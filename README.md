# FSM-Based Traffic Light Controller 🚦

A Finite State Machine (FSM) implementation of a pedestrian crossing traffic light system, written in C++ for the Arduino Uno.

## Overview
Instead of using blocking `delay()` functions, this project utilizes **hardware interrupts** and a **Finite State Machine** to manage the traffic light states. This ensures the microcontroller remains responsive to pedestrian inputs at all times, demonstrating core embedded systems principles.

## Hardware Used
* Arduino Uno
* 3x LEDs (Red, Yellow, Green)
* 1x Pushbutton

## How it Works
* **Normal State:** Cars have a green light (`CARS_GO`).
* **Interrupt:** When a pedestrian presses the button, a hardware interrupt is triggered on Pin 2.
* **State Transition:** The FSM safely transitions through the `CARS_SLOWING` (Yellow) -> `PEDESTRIANS_GO` (Red) -> `CARS_PREPARING` (Red+Yellow) -> `CARS_GO` (Green) sequence using non-blocking `millis()` timing.

## Simulation
You can test the circuit and review the code directly in your browser:
[▶️ Run Simulation on Wokwi](https://wokwi.com/projects/456934098554235905)
