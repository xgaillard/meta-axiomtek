DESCRIPTION = "SD card image update tool"
LICENSE = "CLOSED"

SRC_URI_rbox630-6dl = "file://update_rbox630.sh \
"

SRC_URI_ifb122 = "file://update_ifb122.sh \
"

do_install_rbox630-6dl() {
    install -d ${D}/home/root
    install -d ${D}/home/root/update
    install -m 0755 ${WORKDIR}/update_rbox630.sh ${D}/home/root/update/update.sh
    install -m 0755 ${DEPLOY_DIR_IMAGE}/u-boot.imx ${D}/home/root/update
    install -m 0755 ${DEPLOY_DIR_IMAGE}/zImage ${D}/home/root/update
    install -m 0755 ${DEPLOY_DIR_IMAGE}/imx6dl-rbox630.dtb ${D}/home/root/update
    install -m 0755 ${DEPLOY_DIR_IMAGE}/imx-image-full-rbox630-6dl.tar.bz2 ${D}/home/root/update
}

do_install_ifb122() {
    install -d ${D}/home/root
    install -d ${D}/home/root/update
    install -m 0755 ${WORKDIR}/update_ifb122.sh ${D}/home/root/update/update.sh
    install -m 0755 ${DEPLOY_DIR_IMAGE}/u-boot.imx ${D}/home/root/update
    install -m 0755 ${DEPLOY_DIR_IMAGE}/zImage ${D}/home/root/update
    install -m 0755 ${DEPLOY_DIR_IMAGE}/imx6ul-ifb122-a2.dtb ${D}/home/root/update
    install -m 0755 ${DEPLOY_DIR_IMAGE}/imx6ul-ifb122-a3.dtb ${D}/home/root/update
    install -m 0755 ${DEPLOY_DIR_IMAGE}/imx-image-core-ifb122.tar.bz2 ${D}/home/root/update
}

FILES_${PN} += "/home/root \
                /home/root/update \
"
