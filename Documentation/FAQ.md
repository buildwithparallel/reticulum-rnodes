# Frequently asked questions
## How do I build this firmware?
Please see [BUILDING.md](BUILDING.md).
## Can I produce and sell my own RNodes using this project? 
Yes! Feel free to use the firmware in this repository for your produced RNodes. You do not have to pay a license to use this software commercially, as it is licensed under the GPLv3. If you fork it, you must understand your obligation to provide all future users of the system with the same rights that you have been provided by the GPLv3. Please also consider contributing additional features you design to this repository, to allow others to also use them.

It is also likely worth you reading [this material from Mark Qvist](https://unsigned.io/sell_rnodes.html). Do consider donating to him if your venture is successful, without him this project would simply be a schizo fever dream.

## Why does my RAK4631 not work after upgrading from v1.71 to v1.72 upstream?
The size of the expected EEPROM file changed between these two releases. In my in(finite) wisdom, I forgot to mention that upgrading between these versions would require a format of the user data flash sector on the RAK4631 so that the file can be recreated. 

### Fix
It can be fixed easily by running [this sketch](https://github.com/RAKWireless/RAK-nRF52-Arduino/blob/master/libraries/InternalFileSytem/examples/Internal_Format/Internal_Format.ino) (you must open the serial monitor and press enter for it to actually format the flash). Then, reprovision your EEPROM. For example, this can be done by using `rnodeconf -a`.

## Write a hecking code of conduct!!
no
