DESCRIPTION = "Axiomtek System Ready Checker"
LICENSE = "CLOSED"

SRC_URI = "file://system-ready-checker.service \
           file://system-ready-checker_rbox630.sh \
           file://system-ready-checker_ifb122.sh \
"

do_install() {
    install -d ${D}${bindir}
    install -d ${D}${systemd_system_unitdir}
    install -m 0644 ${WORKDIR}/system-ready-checker.service ${D}${systemd_system_unitdir}
}

do_install_append_rbox630-6dl() {
    install -m 0755 ${WORKDIR}/system-ready-checker_rbox630.sh ${D}${bindir}/system-ready-checker.sh
}

do_install_append_ifb122() {
    install -m 0755 ${WORKDIR}/system-ready-checker_ifb122.sh ${D}${bindir}/system-ready-checker.sh
}

inherit systemd
SYSTEMD_SERVICE_${PN} = "system-ready-checker.service"
SYSTEMD_AUTO_ENABLE = "enable"