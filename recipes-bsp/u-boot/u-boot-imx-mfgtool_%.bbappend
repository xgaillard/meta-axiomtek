# Copyright 2022 Axiomtek

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
    file://0001-feat-support-rBOX630.patch \
    file://0002-feat-add-read-MAC-address-function-from-EEPROM.patch \
    file://0003-feat-support-RTL8211F-lan-phy.patch \
    file://0004-feat-initial-rBOX630-led-status.patch \
    file://0005-feat-add-command-to-boot-from-sd-card.patch \
    file://0006-feat-support-auto-detect-and-boot-sd-update-or-mfgte.patch \
    file://0007-feat-support-read-multi-mac-address-from-eeprom.patch \
    file://0008-feat-add-asix_ethaddr-variable-for-ax88772b-lan.patch \
    file://0009-feat-support-ifb122.patch \
    file://0010-feat-support-rsb101-a2-and-a3-borads.patch \
    file://0011-feat-support-sd-card-auto-detect-to-boot-for-rsb101.patch \
    file://0012-feat-change-ifb122-boot-partition.patch \
    file://0013-feat-support-mfgtest-boot-from-usb-for-ifb122.patch \
"
