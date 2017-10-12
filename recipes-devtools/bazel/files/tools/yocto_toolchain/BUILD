package(default_visibility = ["//visibility:public"])

cc_toolchain_suite(
  name = 'toolchain',
  toolchains = {
    'aarch64|compiler':':cc-compiler-armeabi',
    'local|compiler':':cc-compiler-local',
  },
)

filegroup(
  name = 'empty',
  srcs = [],
)

filegroup(
  name = 'linaro_linux_all_files',
  srcs = [
    '@yocto_toolchain//:compiler_pieces',
  ],
)

cc_toolchain(
  name = 'cc-compiler-local',
  all_files = ':empty',
  compiler_files = ':empty',
  cpu = 'local',
  dwp_files = ':empty',
  dynamic_runtime_libs = [':empty'],
  linker_files = ':empty',
  objcopy_files = ':empty',
  static_runtime_libs = [':empty'],
  strip_files = ':empty',
  supports_param_files = 1,
)

cc_toolchain(
  name = 'cc-compiler-armeabi',
  all_files = ':linaro_linux_all_files',
  compiler_files = ':linaro_linux_all_files',
  cpu = 'aarch64',
  dwp_files = ':empty',
  dynamic_runtime_libs = [':empty'],
  linker_files = ':linaro_linux_all_files',
  objcopy_files = 'linaro_linux_all_files',
  static_runtime_libs = [':empty'],
  strip_files = 'linaro_linux_all_files',
  supports_param_files = 1,
)
