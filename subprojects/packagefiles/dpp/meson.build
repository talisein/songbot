project('dpp', ['cpp'],
        license: 'Apache-2.0',
        version: '10.1.5',
        meson_version: '>=1.4.0',
        default_options: ['cpp_std=c++17'])

cc = meson.get_compiler('cpp')

openssl_dep      = dependency('openssl')
zlib_dep         = dependency('zlib')
threads_dep      = dependency('threads')
nlohmann_json_dep = dependency('nlohmann_json', fallback: ['json', 'nlohmann_json_multiple_headers'])

have_prctl = cc.has_function('prctl', prefix: '#include <sys/prctl.h>')

have_two_param_setname_np = cc.compiles('''
  #include <pthread.h>
  int main() { pthread_setname_np(pthread_self(), "ThreadName"); return 0; }
''', name: 'two-parameter pthread_setname_np', args: ['-pthread'])

have_one_param_setname_np = cc.compiles('''
  #include <pthread.h>
  int main() { pthread_setname_np("ThreadName"); return 0; }
''', name: 'one-parameter pthread_setname_np', args: ['-pthread'])

private_defs = ['-DDPP_BUILD', '-DDPP_OS=Linux', '-DAVX_TYPE=0', '-DDPP_USE_EXTERNAL_JSON']

if have_prctl
  private_defs += ['-DHAVE_PRCTL']
endif
if have_two_param_setname_np
  private_defs += ['-DHAVE_TWO_PARAMETER_SETNAME_NP']
elif have_one_param_setname_np
  private_defs += ['-DHAVE_SINGLE_PARAMETER_SETNAME_NP']
endif

dpp_src = files(
  # Top-level dpp/ (51 files)
  'src/dpp/application.cpp',
  'src/dpp/auditlog.cpp',
  'src/dpp/automod.cpp',
  'src/dpp/ban.cpp',
  'src/dpp/bignum.cpp',
  'src/dpp/cache.cpp',
  'src/dpp/channel.cpp',
  'src/dpp/cluster_coro_calls.cpp',
  'src/dpp/cluster.cpp',
  'src/dpp/commandhandler.cpp',
  'src/dpp/discordclient.cpp',
  'src/dpp/discordevents.cpp',
  'src/dpp/discordvoiceclient.cpp',
  'src/dpp/discord_webhook_server.cpp',
  'src/dpp/dispatcher.cpp',
  'src/dpp/dns.cpp',
  'src/dpp/dtemplate.cpp',
  'src/dpp/emoji.cpp',
  'src/dpp/entitlement.cpp',
  'src/dpp/etf.cpp',
  'src/dpp/guild.cpp',
  'src/dpp/httpsclient.cpp',
  'src/dpp/http_server.cpp',
  'src/dpp/http_server_request.cpp',
  'src/dpp/integration.cpp',
  'src/dpp/invite.cpp',
  'src/dpp/message.cpp',
  'src/dpp/permissions.cpp',
  'src/dpp/presence.cpp',
  'src/dpp/prune.cpp',
  'src/dpp/queues.cpp',
  'src/dpp/role.cpp',
  'src/dpp/scheduled_event.cpp',
  'src/dpp/signature_verifier.cpp',
  'src/dpp/sku.cpp',
  'src/dpp/slashcommand.cpp',
  'src/dpp/snowflake.cpp',
  'src/dpp/socket.cpp',
  'src/dpp/socketengine.cpp',
  'src/dpp/ssl_context.cpp',
  'src/dpp/sslconnection.cpp',
  'src/dpp/stage_instance.cpp',
  'src/dpp/thread.cpp',
  'src/dpp/thread_pool.cpp',
  'src/dpp/user.cpp',
  'src/dpp/utility.cpp',
  'src/dpp/voiceregion.cpp',
  'src/dpp/voicestate.cpp',
  'src/dpp/webhook.cpp',
  'src/dpp/wsclient.cpp',
  'src/dpp/zlibcontext.cpp',
  # cluster/ (24 files)
  'src/dpp/cluster/appcommand.cpp',
  'src/dpp/cluster/automod.cpp',
  'src/dpp/cluster/channel.cpp',
  'src/dpp/cluster/confirmation.cpp',
  'src/dpp/cluster/dm.cpp',
  'src/dpp/cluster/emoji.cpp',
  'src/dpp/cluster/entitlement.cpp',
  'src/dpp/cluster/gateway.cpp',
  'src/dpp/cluster/guild.cpp',
  'src/dpp/cluster/guild_member.cpp',
  'src/dpp/cluster/invite.cpp',
  'src/dpp/cluster/json_interface.cpp',
  'src/dpp/cluster/message.cpp',
  'src/dpp/cluster/role.cpp',
  'src/dpp/cluster/scheduled_event.cpp',
  'src/dpp/cluster/sku.cpp',
  'src/dpp/cluster/stage_instance.cpp',
  'src/dpp/cluster/sticker.cpp',
  'src/dpp/cluster/template.cpp',
  'src/dpp/cluster/thread.cpp',
  'src/dpp/cluster/timer.cpp',
  'src/dpp/cluster/user.cpp',
  'src/dpp/cluster/voice.cpp',
  'src/dpp/cluster/webhook.cpp',
  # events/ (69 files)
  'src/dpp/events/automod_rule_create.cpp',
  'src/dpp/events/automod_rule_delete.cpp',
  'src/dpp/events/automod_rule_execute.cpp',
  'src/dpp/events/automod_rule_update.cpp',
  'src/dpp/events/channel_create.cpp',
  'src/dpp/events/channel_delete.cpp',
  'src/dpp/events/channel_pins_update.cpp',
  'src/dpp/events/channel_update.cpp',
  'src/dpp/events/entitlement_create.cpp',
  'src/dpp/events/entitlement_delete.cpp',
  'src/dpp/events/entitlement_update.cpp',
  'src/dpp/events/guild_audit_log_entry_create.cpp',
  'src/dpp/events/guild_ban_add.cpp',
  'src/dpp/events/guild_ban_remove.cpp',
  'src/dpp/events/guild_create.cpp',
  'src/dpp/events/guild_delete.cpp',
  'src/dpp/events/guild_emojis_update.cpp',
  'src/dpp/events/guild_integrations_update.cpp',
  'src/dpp/events/guild_join_request_delete.cpp',
  'src/dpp/events/guild_member_add.cpp',
  'src/dpp/events/guild_member_remove.cpp',
  'src/dpp/events/guild_members_chunk.cpp',
  'src/dpp/events/guild_member_update.cpp',
  'src/dpp/events/guild_role_create.cpp',
  'src/dpp/events/guild_role_delete.cpp',
  'src/dpp/events/guild_role_update.cpp',
  'src/dpp/events/guild_scheduled_event_create.cpp',
  'src/dpp/events/guild_scheduled_event_delete.cpp',
  'src/dpp/events/guild_scheduled_event_update.cpp',
  'src/dpp/events/guild_scheduled_event_user_add.cpp',
  'src/dpp/events/guild_scheduled_event_user_remove.cpp',
  'src/dpp/events/guild_stickers_update.cpp',
  'src/dpp/events/guild_update.cpp',
  'src/dpp/events/integration_create.cpp',
  'src/dpp/events/integration_delete.cpp',
  'src/dpp/events/integration_update.cpp',
  'src/dpp/events/interaction_create.cpp',
  'src/dpp/events/invite_create.cpp',
  'src/dpp/events/invite_delete.cpp',
  'src/dpp/events/logger.cpp',
  'src/dpp/events/message_create.cpp',
  'src/dpp/events/message_delete_bulk.cpp',
  'src/dpp/events/message_delete.cpp',
  'src/dpp/events/message_poll_vote_add.cpp',
  'src/dpp/events/message_poll_vote_remove.cpp',
  'src/dpp/events/message_reaction_add.cpp',
  'src/dpp/events/message_reaction_remove_all.cpp',
  'src/dpp/events/message_reaction_remove.cpp',
  'src/dpp/events/message_reaction_remove_emoji.cpp',
  'src/dpp/events/message_update.cpp',
  'src/dpp/events/presence_update.cpp',
  'src/dpp/events/ready.cpp',
  'src/dpp/events/resumed.cpp',
  'src/dpp/events/stage_instance_create.cpp',
  'src/dpp/events/stage_instance_delete.cpp',
  'src/dpp/events/stage_instance_update.cpp',
  'src/dpp/events/thread_create.cpp',
  'src/dpp/events/thread_delete.cpp',
  'src/dpp/events/thread_list_sync.cpp',
  'src/dpp/events/thread_members_update.cpp',
  'src/dpp/events/thread_member_update.cpp',
  'src/dpp/events/thread_update.cpp',
  'src/dpp/events/typing_start.cpp',
  'src/dpp/events/user_update.cpp',
  'src/dpp/events/voice_channel_effect.cpp',
  'src/dpp/events/voice_channel_effect_send.cpp',
  'src/dpp/events/voice_server_update.cpp',
  'src/dpp/events/voice_state_update.cpp',
  'src/dpp/events/webhooks_update.cpp',
  # voice stub (no voice support) + Linux epoll socket engine
  'src/dpp/voice/stub/stubs.cpp',
  'src/dpp/socketengines/epoll.cpp',
)

dpp_inc = include_directories('include')

dpp_lib = static_library('dpp',
  dpp_src,
  include_directories: dpp_inc,
  cpp_args: private_defs,
  dependencies: [openssl_dep, zlib_dep, threads_dep, nlohmann_json_dep],
  pic: true,
  install: false,
)

dpp_dep = declare_dependency(
  link_with: dpp_lib,
  include_directories: dpp_inc,
  dependencies: [openssl_dep, zlib_dep, threads_dep, nlohmann_json_dep],
  variables: ['includedir=@0@'.format(meson.current_source_dir() / 'include')],
)

meson.override_dependency('dpp', dpp_dep)
