require bazel_${PV}.inc

do_compile() {
  bazel_compile
}

do_install() {
  bazel_install
}

BBCLASSEXTEND = "native nativesdk"
