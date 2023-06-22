DESCRIPTION = "FTP server"
LICENSE = "CLOSED"

SRC_URI = "file://ftpd \
"

do_install() {
    install -d  ${D}/etc/xinetd.d/
    install -m 0644 ${WORKDIR}/ftpd ${D}/etc/xinetd.d
}
