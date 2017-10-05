DESCRIPTION = "An open-source software library for Machine Intelligence."
HOMEPAGE = "https://www.tensorflow.org/"
LICENSE = "Apache-2.0"

DEPENDS ="bazel python python-pip python-numpy python-six"

SRC_URI = "git://github.com/tensorflow/tensorflow;protocol=https"

SUBDIR="tensorflow-${PV}"
S = "${WORKDIR}/${SUBDIR}"

tensorflow_configure() {
}

tensorflow_compile() {
}

tensorflow_install() {
}

