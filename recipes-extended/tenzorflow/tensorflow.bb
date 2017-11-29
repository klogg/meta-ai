DESCRIPTION = "An open-source software library for Machine Intelligence."
HOMEPAGE = "https://www.tensorflow.org/"
LICENSE = "Apache-2.0"

DEPENDS = "bazel-native ${PYTHON_PN}-numpy-native ${PYTHON_PN}-native"
RDEPENDS_${PN} = "${PYTHON_PN}-pip ${PYTHON_PN}-numpy ${PYTHON_PN}"

TENSORFLOW_VERSION ?= "1.4"

SRC_URI = "git://github.com/tensorflow/tensorflow;protocol=https;branch=r${TENSORFLOW_VERSION}"
SRCREV = "${AUTOREV}"

LIC_FILES_CHKSUM = "file://LICENSE;md5=e74df23890b9521cc481e3348863e45d"

PV = "${TENSORFLOW_VERSION}-git${SRCPV}"
S = "${WORKDIR}/git"

inherit bazel setuptools

JAVA_VERSION = "openjdk-8-native"
export JAVA_HOME="${STAGING_LIBDIR_NATIVE}/jvm/${JAVA_VERSION}"
export CC_OPT_FLAGS="-march=armv8-a+simd ${TUNE_CCARGS}"
export PYTHON_BIN_PATH="${STAGING_BINDIR_NATIVE}/python-native/python"
export PYTHON_LIB_PATH="${STAGING_LIBDIR_NATIVE}/${PYTHON_DIR}"


do_configure() {
	${S}/configure
}

do_compile() {
	bazel test --config=sycl -k --test_timeout 1600 -- //tensorflow/... -//tensorflow/contrib/... -//tensorflow/java/... -//tensorflow/compiler/...
	bazel build --config=opt //tensorflow/tools/pip_package:build_pip_package ${BAZEL_OPTS} --verbose_failures
}

do_install() {
}

