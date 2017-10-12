inherit java

# TODO: auto determine Java version
JDK_VER = "openjdk-8-native"

export JAVA_HOME="${STAGING_LIBDIR_JVM_NATIVE}/${JDK_VER}"

# TODO: if non-native call then install CROSSTOOL, BUILD, ..., also set BAZEL_OPTS
BAZEL_OPTS = "--crosstool_top=//tools/yocto_toolchain:toolchain --cpu=${DEFAULTTUNE}"
