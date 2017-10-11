DESCRIPTION = "An open-source software library for Machine Intelligence."
HOMEPAGE = "https://www.tensorflow.org/"
LICENSE = "Apache-2.0"

DEPENDS ="bazel python python-pip python-numpy python-six"

SRC_URI = "git://github.com/tensorflow/tensorflow;protocol=https"

S = "${WORKDIR}/git"

tensorflow_configure() {
	${S}/configure
}

tensorflow_compile() {
	bazel build
}

tensorflow_install() {
}

