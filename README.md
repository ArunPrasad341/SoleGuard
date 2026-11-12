# SoleGuard

**A smart-insole system that warns people with diabetes about foot-ulcer risk before an ulcer forms.**

SoleGuard measures plantar pressure, in-shoe temperature and humidity, blood-oxygen saturation (SpO₂) and foot motion. A **Renesas RA6E2** microcontroller running **bare-metal firmware** reads the sensors and sends the data over **Bluetooth Low Energy (BLE)** to the SoleGuard mobile app, which shows a plantar pressure heat map and an ulcer-risk score with plain-language findings.

> [!WARNING]
> SoleGuard is a student research prototype, not a certified medical device. Its risk score is a screening aid, not a diagnosis.

## App output

| Plantar heat map | Ulcer risk |
|:---:|:---:|
| <img src="docs/images/app-plantar-heat-map.png" width="280" alt="Plantar heat map screen: four pressure zones per foot, with the right metatarsal at 195.5 kPa flagged as high load"> | <img src="docs/images/app-ulcer-risk.png" width="280" alt="Ulcer risk screen: score 63 of 100 (high risk) with peak pressure, asymmetry, SpO2 and humidity tiles and a list of findings"> |

**Plantar heat map.** Pressure in four zones per foot, from toes to heel, colour-coded from low to high kPa. The most loaded zone is called out with a recommendation: in this reading the **right metatarsal at 195.5 kPa** is above the app's safe tissue-load threshold, so the app suggests offloading it with a cushioned insole. Below it are the left and right average pressures (106.6 and 122.3 kPa) and the left/right asymmetry (13%).

**Ulcer risk.** A rule-based score from 0 to 100, here **63 (High risk)**, shown with the readings behind it: peak pressure 195.5 kPa, asymmetry 13%, SpO₂ 95.1% and in-shoe humidity 84.7%. Each finding is explained in plain language. In this reading the right-metatarsal pressure peak is the main driver, loading between the two feet is balanced, and SpO₂ sits at the lower edge of normal.
