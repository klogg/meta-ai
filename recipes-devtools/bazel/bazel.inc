DESCRIPTION = "Correct, reproducible, and fast builds for everyone."
HOMEPAGE = "https://bazel.build/"
LICENSE = "Apache-2.0"

JDK_VER = "openjdk-8-native"

DEPENDS = "${JDK_VER}"

SECTION = "devel"

SRC_URI_PREFIX = "https://github.com/bazelbuild/bazel/releases/download"

SUBDIR = "bazel-${PV}"
S = "${WORKDIR}/${SUBDIR}"

inherit native java

INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_SYSROOT_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT  = "1"

bazel_compile() {
	export JAVA_HOME="${libdir_jvm}/${JDK_VER}"
	${S}/compile.sh
}

bazel_install() {
	install -d ${D}${bindir}/
	cat > ${WORKDIR}/bazel <<EOT
#!/bin/sh
exec "\$0.real" --output_user_root="${TMPDIR}/bazel" "\$BAZEL_OPTS" "\$@"
EOT
	chmod a+x ${WORKDIR}/bazel
	install ${WORKDIR}/bazel ${D}${bindir}
	install -T ${S}/output/bazel ${D}${bindir}/bazel.real
}
