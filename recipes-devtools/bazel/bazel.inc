DESCRIPTION = "Correct, reproducible, and fast builds for everyone."
HOMEPAGE = "https://bazel.build/"
LICENSE = "Apache-2.0"

SECTION="devel"

SRC_URI_PREFIX = "https://github.com/bazelbuild/bazel/releases/download"

SUBDIR="bazel-${PV}"
S = "${WORKDIR}/${SUBDIR}"

inherit native

bazel_compile() {
	export CC=${BUILD_CC}
	${S}/compile.sh
}

bazel_install() {
	install -d "${D}${bindir}"
}

FILES_${PN} = "${bindir}"
