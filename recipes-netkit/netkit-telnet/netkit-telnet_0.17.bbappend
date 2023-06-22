FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI_append = "file://telnet"

do_install_append () {
    install -d  ${D}/etc/xinetd.d/
    install -m 0644 ${WORKDIR}/telnet ${D}/etc/xinetd.d
}
