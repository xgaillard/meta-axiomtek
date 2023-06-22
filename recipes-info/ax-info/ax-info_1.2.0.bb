DESCRIPTION = "Axiomtek System Information"
LICENSE = "CLOSED"

SRC_URI = "file://system_info \
"

do_install() {
    install -d ${D}${bindir}
    install -d ${D}${sysconfdir}/ax_version
    install -d ${D}/home/browser
    install -d ${D}${systemd_system_unitdir}
    install -m 0755 ${WORKDIR}/system_info/sysinfo ${D}${bindir}
    install -m 0755 ${WORKDIR}/system_info/axiomtek ${D}${bindir}
    install -m 0644 ${WORKDIR}/system_info/sys_info.service ${D}${systemd_system_unitdir}
}

do_install_append_rbox630-6dl() {
    install -m 0755 ${WORKDIR}/system_info/imx6/eeprom_read ${D}${bindir}
    install -m 0755 ${WORKDIR}/system_info/imx6/rbox630-6dl_info ${D}${sysconfdir}/ax_version
}

do_install_append_ifb122() {
    install -m 0755 ${WORKDIR}/system_info/imx6/eeprom_read ${D}${bindir}
    install -m 0755 ${WORKDIR}/system_info/imx6/ifb122_info ${D}${sysconfdir}/ax_version
}

FILES_${PN} += "/home/browser \
"

inherit systemd
SYSTEMD_SERVICE_${PN} = "sys_info.service"
SYSTEMD_AUTO_ENABLE = "enable"