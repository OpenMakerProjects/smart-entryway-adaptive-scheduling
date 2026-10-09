# Wiring

Follow [the editable circuit](circuit-diagram.svg) and the exact pin table in [README](../README.md). Disconnect supplies before assembly. All grounds are common and GPIO is 3.3 V.

Nano USB positive stays separate from external 5 V. Fuse external supply at 1 A; feed PIR VCC, relay coil VCC and INA219 VIN+. INA219 VIN− → relay COM; NO → 5 V lamp+; lamp− GND. INA219 VCC3V3/SDAA4/SCLA5/GND. PIR OUTD2 ≤3.3 V; relay IND5 with 10 kΩ pulldown GND. NC unused. Never connect mains or critical loads.
