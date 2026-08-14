# 🌱 Smart Irrigation and Animal Detection System

An Arduino-based smart agriculture project that combines **automatic
plant irrigation** with **night-time animal detection and alerting**.

## 📌 Project Overview

Agriculture commonly faces two problems:

-   💧 Water wastage caused by unnecessary irrigation
-   🐾 Crop damage caused by animals entering fields at night

This project combines both solutions in one Arduino-based system.

### Main Features

-   🌱 Soil moisture monitoring
-   💧 Automatic water pump control
-   🌙 Day/night mode
-   🐾 PIR-based animal/motion detection at night
-   🔴 LED warning
-   🔊 Buzzer alert
-   📟 16×2 LCD display
-   🖥️ Serial Monitor status

------------------------------------------------------------------------

## 🎯 Objectives

-   Automate irrigation according to soil moisture.
-   Reduce unnecessary water usage.
-   Detect animal movement around agricultural fields at night.
-   Provide immediate visual and audio warnings.
-   Display important system information on an LCD.
-   Demonstrate practical sensor and actuator integration using Arduino.

------------------------------------------------------------------------

## 🌾 Why Do We Need This Project?

Traditional irrigation may water crops even when the soil already
contains enough moisture. This wastes water and can negatively affect
plants.

Animals entering farms at night can also damage crops.

This system addresses both problems:

``` text
Dry Soil → Pump ON
Moist Soil → Pump OFF

Night + Motion → LED ON + Buzzer ON + Animal Detection Alert
```

The project therefore provides a simple foundation for **smart
agriculture and crop monitoring**.

------------------------------------------------------------------------

## ⚙️ How It Works

### 1. Smart Irrigation

The soil moisture sensor sends an analog value to the Arduino.

The program uses:

``` cpp
const int threshold = 500;
```

If:

``` text
moisture < 500
```

the pump is turned ON.

Otherwise, the pump is turned OFF.

> The threshold should be calibrated for the actual sensor and soil
> conditions.

### 2. Animal Detection

The PIR sensor detects movement.

The project is designed to check the PIR sensor primarily during
nighttime.

When nighttime motion is detected:

-   LED turns ON
-   Buzzer sounds
-   LCD displays an animal detection warning
-   Serial Monitor reports the event

**Important:** PIR detects motion; it does not identify the exact animal
species.

------------------------------------------------------------------------

## 🔌 Pin Configuration

  Function               Arduino Pin
  ---------------------- -------------
  Soil Moisture Sensor   A0
  Day/Night Input        A1
  Motor/Pump Control     D8
  PIR Sensor             D10
  Warning LED            D11
  Buzzer                 D2
  LCD RS                 D7
  LCD Enable             D6
  LCD D4                 D5
  LCD D5                 D4
  LCD D6                 D3
  LCD D7                 D9

------------------------------------------------------------------------

## 🔧 Components Used

  Component                    Quantity Purpose
  ----------------------- ------------- ----------------------------------
  Arduino Uno R3                      1 Main controller
  Soil Moisture Sensor                1 Measures soil moisture
  DC Motor / Water Pump               1 Irrigation
  NPN Transistor (BJT)                1 Controls motor
  Diode                               1 Protects motor switching circuit
  9V Battery                          1 External power
  1 kΩ Resistor                       2 Circuit current limiting
  16×2 LCD                            1 Displays information
  250 kΩ Potentiometer                2 Input adjustment
  PIR Sensor                          1 Detects motion
  Piezo Buzzer                        1 Audio alert
  Red LED                             1 Visual alert
  Jumper Wires              As required Connections

------------------------------------------------------------------------

## 💻 Software

-   Arduino IDE / Arduino-compatible environment
-   Arduino C/C++
-   `LiquidCrystal` library
-   Optional simulation using Wokwi

------------------------------------------------------------------------

## ▶️ How to Run

1.  Open the Arduino sketch.
2.  Connect the components according to the circuit.
3.  Make sure the `LiquidCrystal` library is available.
4.  Select **Arduino Uno** as the board.
5.  Upload the program.
6.  Test the soil moisture sensor.
7.  Set the system to night mode and trigger the PIR sensor.
8.  Open Serial Monitor at **9600 baud** to view system status.

------------------------------------------------------------------------

## 📟 Example LCD Output

### Normal Irrigation

``` text
Moisture: 420
Pump: ON
```

or

``` text
Moisture: 650
Pump: OFF
```

### Night Detection

``` text
NIGHT ALERT!
ANIMAL DETECTED
```

------------------------------------------------------------------------

## 🌱 Applications

This project can be used or adapted for:

-   Agricultural fields
-   Small farms
-   Vegetable gardens
-   Greenhouses
-   Nurseries
-   Home gardens
-   Crop monitoring
-   Smart farming demonstrations
-   Embedded-systems education

------------------------------------------------------------------------

## ✅ Advantages

-   💧 Reduces unnecessary irrigation.
-   🌱 Automatically waters plants based on soil condition.
-   🐾 Detects movement at night.
-   🔊 Provides audio and visual alerts.
-   📟 Gives real-time LCD information.
-   💰 Uses relatively low-cost components.
-   ⚡ Simple Arduino-based design.
-   🔧 Easy to modify and expand.
-   📚 Useful for learning embedded systems.

------------------------------------------------------------------------

## ❌ Disadvantages / Limitations

-   PIR detects motion but cannot identify the animal species.
-   No camera or AI-based animal classification is included.
-   Soil moisture sensors require calibration.
-   Pump operation requires a suitable external power source.
-   Outdoor deployment requires weatherproofing.
-   The prototype uses a potentiometer for the day/night input rather
    than a dedicated light sensor.
-   A single PIR sensor has limited coverage.

------------------------------------------------------------------------

## 🚀 Future Improvements

Possible upgrades include:

-   📷 Camera-based animal detection
-   🤖 AI/ML animal classification
-   📱 Mobile notifications
-   ☁️ IoT cloud monitoring
-   🌦️ Weather/rain sensors
-   💡 LDR-based automatic day/night detection
-   📍 GPS field monitoring
-   📊 Web dashboard
-   🔋 Solar power
-   💧 Water-level monitoring
-   📡 Wireless communication
-   🔔 SMS/internet alerts

------------------------------------------------------------------------

## 🔮 Future Scope

A more advanced version could replace the Arduino Uno with an
ESP32/ESP32-CAM and combine:

``` text
Soil Monitoring
      +
Automatic Irrigation
      +
PIR Motion Detection
      +
Camera
      +
AI Animal Classification
      +
IoT Cloud
      ↓
Advanced Smart Agriculture System
```

This could allow farmers to monitor fields remotely and receive
real-time alerts.

------------------------------------------------------------------------

## 🧠 Learning Outcomes

This project demonstrates:

-   Arduino programming
-   Analog sensor reading
-   Digital sensor reading
-   Automatic control
-   Motor switching
-   Transistor-based control
-   LCD interfacing
-   PIR motion detection
-   LED and buzzer control
-   Embedded-system design
-   Smart agriculture concepts

------------------------------------------------------------------------

## ⚠️ Safety Note

Do not power a DC motor/pump directly from an Arduino GPIO pin. Use an
appropriate transistor/MOSFET or motor driver and a suitable external
power supply. A flyback diode should be used across an inductive DC
motor where appropriate.

------------------------------------------------------------------------

## 📂 Recommended GitHub Structure

``` text
Smart-Irrigation-and-Animal-Detection/
│
├── README.md
├── Smart_Irrigation_and_Animal_Detection.ino
├── Smart_Irrigation_and_Animal_Detection_Project_Report.pdf
└── circuit/
    └── circuit-diagram.png
```

------------------------------------------------------------------------

## 📊 Project Status

  Feature                    Status
  -------------------------- -----------
  Soil moisture monitoring   ✅
  Automatic irrigation       ✅
  LCD monitoring             ✅
  Day/night mode             ✅
  PIR motion detection       ✅
  Animal detection alert     ✅
  LED warning                ✅
  Buzzer warning             ✅
  Serial monitoring          ✅
  AI animal identification   🔜 Future
  Camera detection           🔜 Future
  IoT monitoring             🔜 Future

------------------------------------------------------------------------

## 📄 Project Report

A detailed project report can be included in this repository:

`Smart_Irrigation_and_Animal_Detection_Project_Report.pdf`

It contains the objective, need for the project, applications,
advantages, disadvantages, components, working principle, future scope
and other project details.

------------------------------------------------------------------------

## ⭐ Conclusion

The **Smart Irrigation and Animal Detection System** demonstrates how
simple embedded hardware can solve practical agricultural problems.

By automatically watering plants when the soil is dry and detecting
movement at night, the project provides a foundation for a more advanced
**smart farming and crop-monitoring system**.

> **Smart Watering + Night-Time Animal Detection = Better Crop
> Management 🌱🐾**

------------------------------------------------------------------------

## 📜 License

This project is intended for educational and learning purposes. You are
free to study, modify and improve the project.
