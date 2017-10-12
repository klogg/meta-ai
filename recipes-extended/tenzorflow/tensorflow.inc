DESCRIPTION = "An open-source software library for Machine Intelligence."
HOMEPAGE = "https://www.tensorflow.org/"
LICENSE = "Apache-2.0"

DEPENDS ="bazel-native python python-pip python-numpy python-six"

SRC_URI = "git://github.com/tensorflow/tensorflow;protocol=https"

PV = "${TENSORFLOW_VERSION}-git${SRCPV}"

S = "${WORKDIR}/git"

tensorflow_configure() {
	${S}/configure
}

tensorflow_compile() {
	CC=${TARGET_PREFIX}gcc bazel build --config=opt //tensorflow/tools/pip_package:build_pip_package
}

tensorflow_install() {
}

