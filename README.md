# Smart Energy Smart-Meter Pulse Counter & Analytics Agent

![Build](https://img.shields.io/badge/Build-CMake%20%2B%20g%2B%2B-blue)
![Language](https://img.shields.io/badge/C%2B%2B-C%2B%2B17-blue)
![Platform](https://img.shields.io/badge/Platform-Linux-green)
![License](https://img.shields.io/badge/License-Educational-lightgrey)

A Linux-based smart energy meter prototype developed using C++17 and C.

The project demonstrates pulse counting, pulse simulation, energy and power calculation, alert management, analytics, data logging, and Linux character-device communication.

## 📋 Table of Contents

- [Project Overview](#-project-overview)
- [Objectives](#-objectives)
- [Key Features](#️-key-features)
- [System Architecture](#️-system-architecture)
- [Core Modules](#-core-modules)
- [Linux System Programming](#-linux-system-programming)
- [Directory Structure](#-directory-structure)
- [Build and Execution](#-build-and-execution)
- [Testing and Verification](#-testing-and-verification)
- [Future Scope](#-future-scope)
- [Repository](#-repository)

---

# ⚡ Project Overview

## Problem Statement

Traditional energy meters provide limited software-level visibility into real-time energy consumption.

It can be difficult to continuously monitor meter pulses, calculate instantaneous power, track energy consumption, and identify high-power conditions.

## Solution

The **Smart Energy Smart-Meter Pulse Counter & Analytics Agent** provides a Linux-based prototype that:

- Generates or receives meter pulses.
- Counts pulses using a dedicated pulse counter.
- Calculates energy consumption.
- Calculates power from pulse timing.
- Monitors power conditions.
- Generates alerts.
- Performs usage analytics.
- Logs meter information.
- Demonstrates Linux character-device communication.

---

# 🎯 Objectives

The main objectives of the project are:

- Real-time pulse acquisition.
- Accurate pulse-based energy calculation.
- Instantaneous power calculation.
- Simulation of different load conditions.
- High-power condition monitoring.
- Data logging.
- Energy usage analytics.
- Linux kernel and userspace communication.
- Modular and maintainable software architecture.

---

# 🛠️ Key Features

## 1. Pulse Counter

The `PulseCounter` module maintains and processes the meter pulse count.

## 2. Pulse Simulator

The `PulseSimulator` module generates simulated meter pulses for software-based testing and demonstration.

## 3. Energy Calculator

The `EnergyCalculator` module calculates:

- Energy consumption.
- Instantaneous power.
- Power-related measurements.

The project uses a calibration constant of:

```text
3200 impulses/kWh

Energy calculation:
Energy (kWh) = Number of Pulses / 3200

For example:
320 pulses / 3200 = 0.1000 kWh

4. Alert Manager
The AlertManager monitors power conditions and generates alerts when configured conditions are detected.
5. Analytics
The Analytics module processes meter readings and calculates useful usage statistics.
Examples include:
- Minimum power.
- Maximum/peak power.
- Average power.
- Energy consumption.
- Session statistics.
6. Data Logger
The DataLogger module stores meter readings for later analysis.
🏗️ System Architecture
                    Pulse Input
                        │
             ┌──────────┴──────────┐
             │                     │
     Pulse Simulator       Linux Character
                             Device Driver
             │                     │
             └──────────┬──────────┘
                        │
                        ▼
                 ┌──────────────┐
                 │ PulseCounter │
                 └──────┬───────┘
                        │
                        ▼
               ┌─────────────────┐
               │ EnergyCalculator│
               └────────┬────────┘
                        │
              ┌─────────┴─────────┐
              │                   │
              ▼                   ▼
       ┌─────────────┐     ┌────────────┐
       │ AlertManager│     │  Analytics │
       └──────┬──────┘     └─────┬──────┘
              │                  │
              └────────┬─────────┘
                       ▼
                ┌────────────┐
                │ DataLogger │
                └────────────┘

📦 Core Modules
Module	Purpose
PulseCounter	Maintains and processes pulse counts
PulseSimulator	Generates simulated meter pulses
EnergyCalculator	Calculates power and energy
AlertManager	Monitors power conditions
Analytics	Generates usage statistics
DataLogger	Stores meter readings
pulse_driver.c	Linux character-device driver
driver_test.cpp	Userspace driver test


🐧 Linux System Programming
The project demonstrates several Linux system-programming concepts.
Multithreading
The C++ application uses threading concepts for asynchronous pulse generation and monitoring.
Atomic Operations
Atomic operations are used for safe pulse-count processing in concurrent execution.
POSIX Signals
Linux signal handling is used for controlled application termination, including:
SIGINT

which can be generated using:
Ctrl+C

Linux Character Device
The project includes:
driver/pulse_driver.c

which demonstrates Linux character-device programming.
The userspace test application is:
driver/driver_test.cpp

The driver build files are:
driver/Makefile
driver/Kbuild

📁 Directory Structure
SmartMeterProject-main/
│
├── driver/
│   ├── Kbuild
│   ├── Makefile
│   ├── driver_test.cpp
│   └── pulse_driver.c
│
├── include/
│   ├── AlertManager.h
│   ├── Analytics.h
│   ├── DataLogger.h
│   ├── EnergyCalculator.h
│   ├── PulseCounter.h
│   └── PulseSimulator.h
│
├── src/
│   ├── AlertManager.cpp
│   ├── Analytics.cpp
│   ├── DataLogger.cpp
│   ├── EnergyCalculator.cpp
│   ├── PulseCounter.cpp
│   ├── PulseSimulator.cpp
│   └── main.cpp
│
├── tests/
│   └── test_meter.cpp
│
├── docs/
│   ├── PRESENTATION_SLIDES.md
│   └── PROJECT_REPORT.md
│
├── CMakeLists.txt
├── README.md
└── .gitignore

🚀 Build and Execution
Prerequisites
The project requires:
- Linux / Ubuntu
- GCC / G++
- C++17 support
- CMake
- Make
1. Configure the Project
From the project directory:
cmake -B build

2. Build the Project
cmake --build build

3. Run the Application
After successful compilation, run the generated application according to the executable produced by the CMake configuration.
For example:
./bin/SmartMeter

If the executable is generated in another location, use the path shown by the CMake build output.
4. Stop the Application
Use:
Ctrl+C

to send SIGINT and safely terminate the application.
🧪 Testing and Verification
The project contains application tests in:
tests/test_meter.cpp

The Linux driver also includes a userspace test application:
driver/driver_test.cpp

Driver Test
The driver test can be executed using:
sudo ./driver_test

An observed test result was:
Driver pulse count: 3

Kernel Log Verification
Kernel messages can be inspected using:
sudo dmesg | tail -10

Observed driver messages included:
SmartMeter: Device opened
SmartMeter: Pulse received by driver! Total: 3
SmartMeter: Device closed

This demonstrates the communication sequence:
Userspace Application
        ↓
Device Open
        ↓
Pulse Processing
        ↓
Pulse Count
        ↓
Device Close

✅ Verification Summary
Component	Status
C++ application	Implemented
PulseCounter	Implemented
PulseSimulator	Implemented
EnergyCalculator	Implemented
AlertManager	Implemented
Analytics	Implemented
DataLogger	Implemented
Linux character driver	Implemented
Driver test	Verified
Pulse communication	Verified
Project documentation	Available
GitHub repository	Published


🔮 Future Scope
The project can be extended in several ways.
Real Energy Meter Integration
Connect the software to a physical energy meter that provides pulse output.
Embedded Linux
Deploy the system on platforms such as:
- Raspberry Pi
- BeagleBone
- Other embedded Linux systems
Cloud Integration
Add MQTT or another communication protocol to send meter readings to a cloud service.
Web Dashboard
Develop a web interface displaying:
- Current power.
- Energy consumption.
- Historical usage.
- Peak load.
- Alerts.
Advanced Analytics
Future analytics can include:
- Daily consumption.
- Weekly consumption.
- Monthly consumption.
- Peak-hour analysis.
- Consumption forecasting.
Notifications
The alert system can be extended to support:
- Email notifications.
- Mobile notifications.
- Web dashboard alerts.
- MQTT-based notifications.
📄 Project Documentation
Detailed documentation is available in the docs/ directory.
Project Report
docs/PROJECT_REPORT.md

Presentation Slides
docs/PRESENTATION_SLIDES.md

👨‍💻 Project Information
Project Name:
Smart Energy Smart-Meter Pulse Counter & Analytics Agent
Presenter:
Ankit Kumar
Platform:
Linux
Technologies:
C++17, C, Linux System Programming, CMake
🔗 Repository
GitHub:
https://github.com/1806-ak/smart-energy-smart-meter
📌 Final Summary
The Smart Energy Smart-Meter Pulse Counter & Analytics Agent demonstrates how C++, Linux system programming, pulse processing, energy calculation, analytics, data logging, and Linux character-device communication can be combined to create a smart-meter monitoring prototype.
The project follows a modular architecture and separates pulse acquisition, calculation, monitoring, analytics, and persistence into independent components.
The project also includes a Linux character-device driver and a userspace driver test application, providing a practical demonstration of kernel-to-userspace communication.
The modular structure makes the project suitable for further development, testing, hardware integration, and embedded Linux deployment.
Thank You
