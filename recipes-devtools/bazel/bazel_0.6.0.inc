require bazel.inc

SRC_URI = "${SRC_URI_PREFIX}/${PV}/bazel-${PV}-dist.zip;subdir=${SUBDIR}"
SRC_URI[md5sum] = "8f2da0e5bf00bc1e90cd77de0960c037"
SRC_URI[sha256sum] = "a0e53728a9541ef87934831f3d05f2ccfdc3b8aeffe3e037be2b92b12400598e"

LIC_FILES_CHKSUM = "file://LICENSE;md5=3b83ef96387f14655fc854ddc3c6bd57"

