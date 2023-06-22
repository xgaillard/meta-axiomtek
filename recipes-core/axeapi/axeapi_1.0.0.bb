DESCRIPTION = "Axiomtek EApi Tool"
LICENSE = "CLOSED"

SRC_URI = "file://axeapi \
"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/axeapi ${D}${bindir}
}

RDEPENDS_${PN} += "libaxeapi"
