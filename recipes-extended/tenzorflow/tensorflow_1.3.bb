TENSORFLOW_VERSION ?= "1.3"

require tensorflow_${TENSORFLOW_VERSION}.inc

do_configure () {
	tensorflow_configure
}

do_compile () {
	tensorflow_compile
}

do_install () {
	tensorflow_install
}

