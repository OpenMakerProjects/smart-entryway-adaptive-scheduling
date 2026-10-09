# Architecture

Nano 33 IoT samples PIR D2 and INA219 0x40 over A4/A5 every 100 ms. The Adaptive policy maintains current/previous 24 boot-hour count arrays. A previous count ≥2 chooses a 60-second hold instead of 10 seconds. D5 drives a low-voltage lamp relay. Current faults latch off; safe USB RESET is required. Networking is unused.

See the README, circuit SVG and firmware for the complete behavior. Historical seed files are retained; PlatformIO builds only firmware/main.cpp.
