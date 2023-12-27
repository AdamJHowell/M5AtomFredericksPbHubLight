# M5 Atom quad light sensors
M5Stack Atom with the [M5Stack Pb.HUB](https://docs.m5stack.com/en/unit/pbhub_1.1) and 4 [M5Stack light](https://docs.m5stack.com/en/unit/LIGHT) sensors.  
The light sensors output both a digital value (0 or 1) and an analog value (0 to 4095.  
This uses the [M5 PbHub library](https://github.com/thomasfredericks/M5_PbHub) by Thomas Fredericks.  However, channels 4 and 5 always return the same value, so this should not be used!
