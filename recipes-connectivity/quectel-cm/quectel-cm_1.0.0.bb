DESCRIPTION = "Quectel Connect Manager"
LICENSE = "CLOSED"

SRC_URI = "file://quectel-CM \
"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/quectel-CM ${D}${bindir}
}
