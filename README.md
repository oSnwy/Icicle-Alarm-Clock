# Icicle-Alarm-Clock

## Initial goals:
- This alarm clock should be able to tell the time (obviously).
- This alarm clock should be able to store multiple alarms, as well as be able to toggle each alarm.
- This alarm clock should have a volume knob.
- This alarm clock should be able to play customized sounds.


## Parts list
- Lolin C3 Mini ESP32
- 2.25in TFT display
- 12 Keyboard Switches
- A 3.3V Piezo Buzzer
- Some Jumper Cables for wiring

## Planning:
- I plan to use a rotary encoder with a switch to navigate the UI, as well as extra switches to easily toggle alarms or other features.
- The buzzer will be integrated into a transistor circuit, increasing the volume of the alarm while keeping it adjustable.

## Schemtaic (4 Hours):
- Due to the struggle for GPIO pins on the WEMOS, I was only able to add two switches
- The rotary encoder and two switches use 5 GPIO pins, while the buzzer uses one.
- The other 6 GPIO pins are used by the THT display.
- Both the buzzer and the THT display are powered by the 3.3V pin.
  ![Icicle Alarm Clock Schematic](https://github.com/oSnwy/Icicle-Alarm-Clock/blob/main/Images/Icicle%20Alarm%20Clock%20Schematic.png)
