# PN005_merus_audio_ctl

A basic command line controller for the Merus Audio MA1270P amplifier. At present, it mainly reads and interprets the various control registers available, but planning to add pretty much full functionality over time.

All functionality can be seen in the usage statement, see this with _./ma1270p_ctl_. The default bus number is 1 and amp device address is 0x20. Only one other option can be selected as any one time.

Example: _ma1270p_ctl -b 1 -d 0x20 -e acc_

_NOTE: Some of the channel monitor registers need checking given the datasheet is unclear to exactly what bit values relate to what setting_
