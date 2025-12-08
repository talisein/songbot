module;

#include <magic.h>
#include <cerrno>

export module magic;
import std;
import util;

namespace magic
{
    struct magic_deleter
    {
        void operator()(magic_t p) const {
            if (p)
                magic_close(p);
        }
    };

    using magic_p = std::unique_ptr<std::remove_pointer_t<magic_t>, magic_deleter>;

    inline std::system_error get_exception(const magic_p& p)
    {
        const char* err_msg = magic_error(p.get());
        auto err_code = magic_errno(p.get());
        std::error_code ec{err_code, std::generic_category()};
        std::system_error sys_ex(ec, std::format("libmagic failed: {}", err_msg ? err_msg : "Unknown magic error"));
        return sys_ex;
    }

}

export namespace magic
{
    magic_p make_magic(int flags = MAGIC_NONE)
    {
        auto res = magic_p{ magic_open(flags) };
        if (!res) {
            std::error_code ec {errno, std::generic_category()};
            if (ec == std::errc::invalid_argument) {
                throw std::invalid_argument { std::format("invalid/unsupported flags {:x} passed to magic_open", flags) };
            } else {
                throw std::system_error {ec, "Couldn't magic_open()"};
            }
        }

        auto rc = magic_load(res.get(), nullptr);
        if (0 != rc) {
            throw get_exception(res);
        }
        return res;
    }

    std::string
    buffer(const magic_p& magic, std::ranges::contiguous_range auto&& rng)
    {
        using ElementType = std::ranges::range_value_t<decltype(rng)>;
        auto res = magic_buffer(magic.get(), std::to_address(std::ranges::begin(rng)), std::ranges::distance(rng) * sizeof(ElementType));
        if (nullptr == res) {
            throw get_exception(magic);
        }
        return res;
    }

    std::string
    file(const magic_p& magic, const std::filesystem::path& path)
    {
        auto res = magic_file(magic.get(), path.c_str());
        if (nullptr == res) {
            throw get_exception(magic);
        }
        return res;
    }

    std::string
    buffer(const magic_p& magic, std::istream& is)
    {
        if (!is.good()) {
            throw std::ios_base::failure("Provided input stream is not ready for read",
                                         util::iostate_to_error_code(is.rdstate()));
        }
        size_t count = 4096UZ;
        std::string buf;
        if (auto is_buf = is.rdbuf(); is_buf && is_buf->in_avail() > count) {
            count = is_buf->in_avail();
        }
        buf.resize_and_overwrite(count, [&](char* ptr, size_t count) {
            is.read(ptr, count);
            if (!is.good() && !is.eof()) {
            throw std::ios_base::failure("Error while reading istream",
                                         util::iostate_to_error_code(is.rdstate()));

            }
            return static_cast<size_t>(is.gcount());
        });

        return buffer(magic, buf);
    }

    std::expected<std::string, std::exception_ptr> get_ext(std::ranges::contiguous_range auto&& rng)
    {
        try {
            auto p = make_magic(MAGIC_EXTENSION | MAGIC_ERROR);
            auto exts = buffer(p, std::forward<decltype(rng)>(rng));
            return std::string(*std::ranges::begin(std::views::split(exts, std::string_view{"/"})));
        } catch (...) {
            return std::unexpected(std::current_exception());
        }
    }

    std::expected<std::string, std::exception_ptr> get_ext(const std::filesystem::path& path)
    {
        try {
            static auto p = make_magic(MAGIC_EXTENSION | MAGIC_ERROR);
            auto exts = file(p, path);
            auto split = std::views::split(exts, std::string_view{"/"});
            auto it = std::ranges::begin(split);
            return std::string(std::ranges::begin(*it), std::ranges::end(*it));
        } catch (...) {
            return std::unexpected(std::current_exception());
        }
    }

    std::expected<std::string, std::exception_ptr> get_mime(const std::filesystem::path& path)
    {
        try {
            static auto p = make_magic(MAGIC_MIME_TYPE | MAGIC_ERROR);
            auto mime = file(p, path);
            return std::string(mime);
        } catch (...) {
            return std::unexpected(std::current_exception());
        }
    }

}
