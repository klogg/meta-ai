DESCRIPTION = "An open-source software library for Machine Intelligence."
HOMEPAGE = "https://www.tensorflow.org/"
LICENSE = "Apache-2.0"

DEPENDS = "bazel-native ${PYTHON_PN}-numpy-native ${PYTHON_PN}-native"
RDEPENDS_${PN} = "${PYTHON_PN}-pip ${PYTHON_PN}-numpy ${PYTHON_PN}"

SRC_URI = "git://github.com/tensorflow/tensorflow;protocol=https"

PV = "${TENSORFLOW_VERSION}-git${SRCPV}"
S = "${WORKDIR}/git"

inherit bazel setuptools

tensorflow_configure() {
	export CC_OPT_FLAGS="-march=armv8-a+simd ${TUNE_CCARGS}"
	export PYTHON_BIN_PATH="${STAGING_BINDIR_NATIVE}/python-native/python"
	export PYTHON_LIB_PATH="${STAGING_LIBDIR_NATIVE}/${PYTHON_DIR}"
	${S}/configure
}

tensorflow_compile() {
	bazel build --config=opt //tensorflow/tools/pip_package:build_pip_package --verbose_failures
}

tensorflow_install() {
}

