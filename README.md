# SoleGuard

**A smart-insole system that warns people with diabetes about foot-ulcer risk before an ulcer forms.**

SoleGuard measures plantar pressure, in-shoe temperature and humidity, blood-oxygen saturation (SpO₂) and foot motion. A **Renesas RA6E2** microcontroller running **bare-metal firmware** reads the sensors and sends the data over **Bluetooth Low Energy (BLE)** to the SoleGuard mobile app, which shows a plantar pressure heat map and an ulcer-risk score with plain-language findings.

> [!WARNING]
> SoleGuard is a student research prototype, not a certified medical device. Its risk score is a screening aid, not a diagnosis.
