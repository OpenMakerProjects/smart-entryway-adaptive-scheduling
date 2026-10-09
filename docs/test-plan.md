# Test plan

The CI host assertions, image integrity tests and actual target build are automated. Run commands and boundary cases are in README. Physical hardware has not been tested.

On a safe fused 5 V bench, verify PIR output levels and warmup, INA219 polarity/current accuracy and relay active-high logic. Confirm startup latch, safe RESET, 10-second first-day hold, previous-day two-event/60-second rule, current fault latch and OFF. Use a current-limited supply; do not intentionally short the load. Do not accelerate hardware results by pretending host tests measured physical behavior.
