extern RadioInterface* interface_obj[INTERFACE_COUNT];
void (*onIntRise[INTERFACE_COUNT]) (void);

#if INTERFACE_COUNT == 1
void onInt0Rise() {
    if (interfaces[0] == SX1280) {
        // On the SX1280, there is a bug which can cause the busy line
        // to remain high if a high amount of packets are received when
        // in continuous RX mode. This is documented as Errata 16.1 in
        // the SX1280 datasheet v3.2 (page 149)
        // Therefore, the modem is set into receive mode each time a packet is received.
        interface_obj[0]->receive();
    }
    if (interface_obj[0]->getPacketValidity()) {
        interface_obj[0]->handleDio0Rise();
    }
}

void setup_interfaces() {
    onIntRise[0] = onInt0Rise;
}
#elif BOARD_MODEL == BOARD_RAK4631 || BOARD_MODEL == BOARD_OPENCOM_XL
void onInt0Rise() {
    if (interface_obj[0]->getPacketValidity()) {
        interface_obj[0]->handleDio0Rise();
    }
}

void onInt1Rise() {
    // On the SX1280, there is a bug which can cause the busy line
    // to remain high if a high amount of packets are received when
    // in continuous RX mode. This is documented as Errata 16.1 in
    // the SX1280 datasheet v3.2 (page 149)
    // Therefore, the modem is set into receive mode each time a packet is received.
    interface_obj[1]->receive();
    if (interface_obj[1]->getPacketValidity()) {
        interface_obj[1]->handleDio0Rise();
    }
}

void setup_interfaces() {
    onIntRise[0] = onInt0Rise;
    onIntRise[1] = onInt1Rise;
}
#endif
