# Light-Activated LED (Photoresistor Voltage Divider)

## Project Overview
This project uses a **photoresistor (LDR)** and a **fixed resistor** to create a **voltage divider** that allows an Arduino to measure light levels.  
Based on the brightness of the environment, an LED automatically turns **ON in the dark** and **OFF in bright light**.

This project introduces **analog input**, **threshold logic**, and **real-world sensing**.

---

## Learning Objectives
By completing this project, students will:
- Understand how a **photoresistor** works
- Learn what a **voltage divider** is
- Read **analog values** using an Arduino
- Use `if` statements to make decisions
- Build an automatic light-controlled system

---

## Materials Required
- Arduino Uno
- Photoresistor (LDR)
- 10kΩ resistor
- LED
- 330Ω resistor
- Breadboard
- Jumper wires
- USB cable

---

##  Circuit Wiring

###  Photoresistor Voltage Divider

**Steps:**
1. One leg of the photoresistor → **5V**
2. Other leg of the photoresistor → **A0**
3. 10kΩ resistor from **A0 → GND**

---

### LED Wiring
1. **Pin 8 → LED long leg (+)**
2. LED short leg (–) → **330Ω resistor**
3. Other end of resistor → **GND**