DESCRIPTION = "An open-source software library for Machine Intelligence."
HOMEPAGE = "https://www.tensorflow.org/"
LICENSE = "Apache-2.0"

DEPENDS = "bazel-native python-native"
RDEPENDS_tensorflow = "python-pip python-numpy python-six"

SRC_URI = "git://github.com/tensorflow/tensorflow;protocol=https"

PV = "${TENSORFLOW_VERSION}-git${SRCPV}"

S = "${WORKDIR}/git"

# Move this to bazel.bbclass
inherit java
JDK_VER = "openjdk-8-native"
export JAVA_HOME="${STAGING_DIR_NATIVE}${libdir_jvm}/${JDK_VER}"
export CC="${TARGET_PREFIX}gcc"
BAZEL_OPTS = "--crosstool_top=//tools/yocto_toolchain:toolchain --cpu=${DEFAULTTUNE}"
# ^^^

tensorflow_configure() {
	# export CC_OPT_FLAGS="-march=armv8-a+simd"
	# actually we need to do fakeroot using host build sysroot here
	# also we need to redirect output ()
	export
	${S}/configure
}

tensorflow_compile() {
	bazel build --config=opt //tensorflow/tools/pip_package:build_pip_package --verbose_failures
}

tensorflow_install() {
}

