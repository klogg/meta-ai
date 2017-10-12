DESCRIPTION = "Correct, reproducible, and fast builds for everyone."
HOMEPAGE = "https://bazel.build/"
LICENSE = "Apache-2.0"

SECTION="devel"

SRC_URI_PREFIX = "https://github.com/bazelbuild/bazel/releases/download"

SUBDIR="bazel-${PV}"
S = "${WORKDIR}/${SUBDIR}"

inherit native

INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_SYSROOT_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT  = "1"

bazel_compile() {
	export CC=${BUILD_CC}
	${S}/compile.sh
}

bazel_install() {
	install -d ${D}${bindir}/
	install ${S}/output/bazel ${D}${bindir}
}
