# Smart Energy Smart Meter – Presentation Slide Deck

## Slide 1: Title Slide

- **Title:** Smart Energy Smart Meter
- **Subtitle:** Pulse Counter, Energy Monitoring & Analytics using Linux
- **Presenter:** Ankit Kumar
- **GitHub:** https://github.com/1806-ak/smart-energy-smart-meter
- **Platform:** Linux
- **Technologies:** C++, C, Linux Kernel Module, CMake

## Slide 2: Problem Statement & Motivation

- Traditional energy meters do not provide a simple software-level interface for real-time pulse monitoring.
- Energy consumption needs to be converted from meter pulses into useful power and energy values.
- Sudden increases in pulse frequency should be detected and reported.
- The project demonstrates an edge-based smart-meter monitoring solution using Linux and C++.

## Slide 3: Project Objectives

- Count energy-meter pulses.
- Convert pulse information into power and energy measurements.
- Simulate different load conditions.
- Generate alerts for high-power conditions.
- Store meter readings for later analysis.
- Demonstrate Linux kernel-to-userspace communication using a character device driver.


## Slide 4: System Architecture

Input
  ↓
Pulse Simulator / Kernel Character Device
  ↓
PulseCounter
  ↓
EnergyCalculator
  ↓
AlertManager + Analytics
  ↓
DataLogger
  ↓
Terminal Dashboard / CSV Report

## Slide 5: Core Modules

- `PulseCounter` – manages pulse counting.
- `PulseSimulator` – generates simulated meter pulses.
- `EnergyCalculator` – calculates power and cumulative energy.
- `AlertManager` – detects high-power conditions.
- `Analytics` – generates usage summaries and statistics.
- `DataLogger` – stores readings in CSV format.

## Slide 6: Linux System Programming

- Linux Kernel Module written in C.
- Character device interface: `smart_meter_pulse`.
- Uses `open()`, `read()`, and `write()` operations.
- `copy_to_user()` provides kernel-to-userspace data transfer.
- `cdev` provides character-device registration.
- Kernel messages can be inspected using `dmesg`.

## Slide 7: Driver Verification

The kernel driver was successfully compiled and loaded.

Driver test:

    sudo ./driver_test

Observed output:

    Driver pulse count: 3

Kernel log confirmed:

    SmartMeter: Device opened
    SmartMeter: Pulse received by driver! Total: 3
    SmartMeter: Device closed

This verifies communication between the userspace test program and the kernel character device.

## Slide 8: Results

- Pulse counting successfully demonstrated.
- Kernel character-device communication verified.
- Smart-meter application successfully built and executed.
- Energy and power calculations are handled by the application modules.
- Meter data can be logged for analysis.

## Slide 9: Future Scope

- Connect the driver to a real pulse-output energy meter.
- Deploy on Raspberry Pi or another embedded Linux platform.
- Add MQTT/cloud connectivity.
- Add a web-based monitoring dashboard.
- Add long-term energy-consumption analytics.
- Add configurable overload and surge thresholds.

## Slide 10: Conclusion

- Developed a Linux-based Smart Energy Smart Meter system.
- Implemented a userspace C++ monitoring application.
- Implemented a Linux character-device kernel module.
- Successfully verified pulse communication using the driver test.
- Project source code and documentation are available on GitHub.

**GitHub:** https://github.com/1806-ak/smart-energy-smart-meter

**Thank You**
