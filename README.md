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

## Problem statement

### Why diabetic foot ulcers matter

- **Scale in India:** diabetes prevalence is 11.4%, about **101 million people**, and another 15.3%, about **136 million people**, have prediabetes ([ICMR-INDIAB, 2023](#references)).
- **Lifetime risk:** about **one in three people with diabetes develops a foot ulcer**. Roughly half of these ulcers become infected, and about one in five of those infections ends in amputation of part or all of the foot ([JAMA, 2023](#references)).
- **Recurrence:** healing is not the end. Ulcers come back in about **40% of patients within one year and 65% within five years** ([JAMA, 2023](#references)).

### Why they happen

Diabetes damages the nerves in the feet (**peripheral neuropathy**). The person loses protective sensation, so nothing hurts when:

1. **Pressure stays high under bony areas.** The metatarsal heads and the heel take load with every step, and the tissue slowly breaks down.
2. **The inside of the shoe stays warm and damp.** Moist skin softens (macerates), cracks and lets infection in.
3. **Blood supply to the foot is poor.** Damaged tissue heals slowly, or not at all.

By the time an ulcer is visible, the damage has already been done ([Armstrong et al., 2017](#references)).

### The gap

- Feet are checked **only at occasional clinic visits**, but the pressure that causes ulcers builds up **during everyday walking and standing, between those visits**.
- Patients **cannot feel** the warning signs, because neuropathy has switched off their alarm.
- Acting on pressure works, but only when it happens in daily life:
  - Pressure-relieving custom footwear helped only the patients who actually wore it. Among those who wore it for at least 80% of their steps, ulcer recurrence fell from 47.8% to 25.7%, a 46% relative reduction ([Bus et al., 2013](#references)).
  - Patients using a smart insole that alerted them through a smartwatch whenever it detected abnormal pressure had **71% fewer ulcers** than the control group, and 86% fewer among those who wore it at least 4.5 hours a day ([Abbott et al., 2019](#references)).

### Our problem statement

> People with diabetes cannot feel the plantar pressure peaks, unhealthy in-shoe conditions and poor perfusion that lead to foot ulcers, and today these risk factors are checked only during infrequent clinic visits.
>
> **SoleGuard's goal is a low-cost, wearable system that measures these risk factors continuously during daily life and turns them into an early, easy-to-understand warning, so the patient can offload the foot before an ulcer forms.**
