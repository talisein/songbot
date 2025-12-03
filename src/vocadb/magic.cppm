module;

#include <magic.h>

export module magic;
import std;

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

  inline std::system_error get_exception(magic_p& p)
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
    return magic_p{ magic_open(flags) };
  }

  std::expected<std::string, std::exception_ptr> get_ext()
  {
    auto p = make_magic(MAGIC_EXTENSION);
    if (!p) {
      return std::unexpected(std::make_exception_ptr(get_exception(p)));
    }
    
    return "meow";
  }	
}
