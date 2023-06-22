SUMMARY = "EApi library and demo tool for Axiomtek device"

LICENSE = "CLOSED"

SRC_URI = "file://include \
           file://eapi_demo \
           file://testeapi \
           file://libEApi \
"

do_install() {
    install -d ${D}${bindir}
    install -d ${D}${libdir}
    install -d ${D}${includedir}
	install -d ${D}${prefix}/src

    cp -a ${WORKDIR}/include/* ${D}${includedir}

    install -m 0755 ${WORKDIR}/libEApi/armv7/libEApi.so.1.1 ${D}${libdir}
    ln -s libEApi.so.1.1 ${D}${libdir}/libEApi.so.1
    ln -s libEApi.so.1.1 ${D}${libdir}/libEApi.so
}

do_install_append_rbox630-6dl() {
    cp -R ${WORKDIR}/eapi_demo/rbox630 ${D}${prefix}/src/eapi_demo
	install -m 0755 ${WORKDIR}/testeapi/rbox630/testeapi ${D}${bindir}/testeapi
}

do_install_append_ifb122() {
    cp -R ${WORKDIR}/eapi_demo/ifb122 ${D}${prefix}/src/eapi_demo
	install -m 0755 ${WORKDIR}/testeapi/ifb122/testeapi ${D}${bindir}/testeapi
}

FILES_${PN} += "${prefix}/src \
"

INSANE_SKIP_${PN} = "ldflags"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
INHIBIT_PACKAGE_STRIP = "1"
