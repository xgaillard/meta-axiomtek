# Copyright 2022 Axiomtek

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
    file://0001-feat-support-rBOX630.patch \
    file://0002-feat-support-RTL8211F-lan-phy.patch \
    file://0003-feat-add-axio_cpld-driver.patch \
    file://0004-feat-support-EC25-LTE-module.patch \
    file://0005-feat-add-ax88772b-mac-address-to-read-from-uboot-var.patch \
    file://0006-feat-support-ifb122.patch \
    file://0007-feat-use-50-MHz-external-osc-for-rsb101-enet-clock-s.patch \
    file://0008-feat-enable-rsb101-uart2-and-uart3-dma-support.patch \
"

SRC_URI_append_ifb122 = " \
    file://ifb122.cfg \
"

do_configure_append_ifb122() {
    cat ../*.cfg >> ${B}/.config
}