LIC_FILES_CHKSUM = "file://LICENSE;md5=e74df23890b9521cc481e3348863e45d"

PV = "1.3.1-git${SRCPV}"
SRCREV = "ef8bb6ee29cd3ecc3503ce9ce8108336a922b102"

do_configure () {
	tensorflow_configure
}

do_compile () {
	tensorflow_compile
}

do_install () {
	tensorflow_install
}

