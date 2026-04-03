# 🧪 Quality Assurance Test Report

### 1. Electrical Stress Test
- **Component:** 32Ah Lead-Acid Battery + 30A Relay Module.
- **Scenario:** Stall torque activation (10A draw per motor).
- **Result:** Booster board successfully maintained 5.0V stable output to Arduino. No logic resets observed.

### 2. Relay Latency Test
- **Requirement:** Reaction time from BT command to Relay click < 100ms.
- **Metric:** Measured ~45ms. **Status: PASS.**

### 3. Mechanical Integrity
- **Torque:** Verified 45 kg-cm stall torque on a 10mm shaft.
- **Heat Sink:** L298N (if used for auxiliary) or Relay contacts remained within thermal operating limits (< 40°C) after 15 mins.
