# Smart Entryway Adaptive Scheduling

Build a smart home prototype that uses PIR sensor, current sensor, relay module to adjust schedules from occupancy patterns. Include setup instructions, a circuit diagram, tested firmware, and sample output.

## Project details

| Field | Value |
| --- | --- |
| Roadmap ID | 20 |
| Category | Smart Home |
| Platform | Arduino Nano 33 IoT |
| Difficulty | Beginner |
| Estimated build time | 16 hours |
| Connectivity | Local only |
| Core components | PIR sensor, current sensor, relay module |
| Control mode | closed loop control |

## Repository layout

- `firmware/smart-entryway-adaptive-scheduling/smart-entryway-adaptive-scheduling.ino`: runnable firmware or application
- `docs/wiring.md`: suggested low-voltage wiring plan
- `docs/architecture.md`: system data flow
- `docs/test-plan.md`: repeatable verification steps
- `sample-data/example.json`: example telemetry record
- `tools/validate.py`: dependency-free repository validation

## Quick start

1. Open `firmware/smart-entryway-adaptive-scheduling/smart-entryway-adaptive-scheduling.ino` in Arduino IDE or Arduino CLI.
2. Select the board matching **Arduino Nano 33 IoT**.
3. Compile and upload, then open the serial monitor at 115200 baud.

## Expected behavior

Adaptive Scheduling demonstration with repeatable test steps. The default implementation supports simulated or generic analog inputs so the control path can be exercised before hardware-specific drivers are added.

## Hardware adaptation

The included code is a safe reference implementation. Update pin assignments and sensor conversions from the exact component datasheets, then repeat the test plan before connecting actuators.

## License

MIT
