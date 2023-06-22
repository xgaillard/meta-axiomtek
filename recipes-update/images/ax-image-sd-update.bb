DESCRIPTION = "Axiomtek SD Update Tool"
LICENSE = "CLOSED"

require recipes-core/images/core-image-base.bb

do_cleanall[depends] += "sd-update:do_cleanall"

IMAGE_INSTALL_remove = " ax-info sys-led gstreamer1.0-plugins-imx \
                         ftpd xinetd netkit-telnet quectel-cm modemmanager \
                         stress-ng libaxeapi libaxeapi-dev axeapi \
"

IMAGE_INSTALL_append = " mmc-utils util-linux e2fsprogs-mke2fs dosfstools sd-update pv \
"

update() {
      sed -i -e s/-8/-a\ root/ ${IMAGE_ROOTFS}${systemd_system_unitdir}/serial-getty@.service
      echo "/home/root/update/update.sh" >> ${IMAGE_ROOTFS}/etc/profile
}

ROOTFS_POSTPROCESS_COMMAND	+=	"update; "
