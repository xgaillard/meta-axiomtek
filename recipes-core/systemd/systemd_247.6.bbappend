FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
           file://80-can0.network \
           file://80-can1.network \
"

do_install_append_rbox630-6dl() {
    install -d ${D}${sysconfdir}/systemd/network
	install -m 0644 ${WORKDIR}/80-can0.network ${D}${sysconfdir}/systemd/network
    install -m 0644 ${WORKDIR}/80-can1.network ${D}${sysconfdir}/systemd/network
}
