require bazel_${PV}.inc

do_compile() {
  basel_compile
}

do_install() {
  basel_install
}

BBCLASSEXTEND = "native nativesdk"
