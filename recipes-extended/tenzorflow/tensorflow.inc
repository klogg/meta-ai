DESCRIPTION = "An open-source software library for Machine Intelligence."
HOMEPAGE = "https://www.tensorflow.org/"
LICENSE = "Apache-2.0"

DEPENDS = "bazel-native python-native"
RDEPENDS_tensorflow = "python-pip python-numpy python-six"

SRC_URI = "git://github.com/tensorflow/tensorflow;protocol=https"

PV = "${TENSORFLOW_VERSION}-git${SRCPV}"
S = "${WORKDIR}/git"

inherit bazel python-dir

tensorflow_configure() {
	# export CC_OPT_FLAGS="-march=armv8-a+simd"
	# actually we need to do fakeroot using host build sysroot here
	# also we need to redirect output ()
	export PYTHON_BIN_PATH="${STAGING_BINDIR_NATIVE}/python-native/python"
	export PYTHON_LIB_PATH="${STAGING_LIBDIR_NATIVE}/${PYTHON-DIR}"
	${S}/configure
}

tensorflow_compile() {
	bazel build ${BAZEL_OPTS} --config=opt //tensorflow/tools/pip_package:build_pip_package --verbose_failures
}

tensorflow_install() {
}

