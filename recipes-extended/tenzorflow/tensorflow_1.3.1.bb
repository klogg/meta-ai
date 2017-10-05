require tensorflow-${PV}.inc

do_configure () {
	tensorflow_configure
}

do_compile () {
	tensorflow_compile
}

do_install () {
	tensorflow_install
}

