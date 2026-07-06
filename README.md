# Icicle-Alarm-Clock

## Initial goals:
### Priority Goals:
- This alarm clock should be able to tell the time (obviously).
- This alarm clock should be able to store multiple alarms, as well as be able to toggle each alarm.
### Less important goals
- This alarm clock should have a volume knob.
- This alarm clock should be able to play customized sounds.


## Parts list

| Part | Quantity |
| ---------- | ---------- |
| Lolin C3 Mini ESP32 | 1 |
| 2.25in TFT display | 1 |
| Custom PCB | 1 |
| 3.3V Piezo Buzzer | 1 |
| EC11 Rotary Encoder Switch Button | 1 |
| 1k ohm Resistor | 1 |
| 10k Ohm Resistor | 1 |
| S8050 Transistor | 1 |
| Case | 1 |
| Lid | 1 |
| 1x8 2.54mm pin headers | 2 |
| Keyboard Switches | 3 |
| Keyboard Keycaps | 3 |
| Female to female Dupont wires | 16 |


## Planning:
- I plan to use a rotary encoder with a switch to navigate the UI, as well as extra switches to easily toggle alarms or other features.
- The buzzer will be integrated into a transistor circuit, increasing the volume of the alarm while keeping it adjustable.

## Schemtaic (4 Hours):
- Due to the struggle for GPIO pins on the WEMOS, I was only able to add two switches.
- The rotary encoder and two switches use 5 GPIO pins, while the buzzer uses one.
- The other 6 GPIO pins are used by the THT display.
- The 3.3V pin powers both the buzzer and the THT display.
<img src="/images/Icicle Alarm Clock Schematic.png" width="1000">
  
## Schematic (REVISED: +2 Hours):
- While creating the PCB, I added a pull-down resistor between the base of the transistor circuit and the GND pin.
- I changed the THT display to be connected with a generic 2.54mm 1x8 connector, so the keys and screen can be mounted on separate planes.
- The BL is now powered by the 3.3V pin, freeing the GPIO pin to be used for a third switch.
<img src="/images/Icicle%20Alarm%20Clock%20Schematic%20UPDATED.png" width="1000">

## PCB (4 Hours)
- The PCB was wired in KiCad, using the footprints provided by Hack Club [BLARE](https://github.com/destroyer796/BLARE-Alarm-Clock/tree/main).
- All components were mounted on the top of the PCB.
- The PCB includes 4 mounting holes for M3 screws.
- This PCB uses a 1x8 connector for the display.
<img src="/images/Icicle%20Alarm%20Clock%20pcb.png" width="1000">

## Case (3 Hours)
This case is designed to work in two parts. The main body of the case has M3 screw standoffs in the base, allowing the PCB to be screwed into the case securely. The LCD can be attached to the front of the case using M2 screws in the hole in the front. The lid functions as a quick access to all the componenets inside, as well as contains a hole to reach the knob and switches. The side of the case contains cutouts to better transmit the sound of the buzzer.

## CASE (REVISED: +2 Hours):
Added holes for the usb c wire, as well as a lower lid for easier access to the switches. Also added full electronics 3d model.

### Full Model With Electronics

| <img src="/images/Full Model ISO.png" width="1000"> | <img src="/images/Full Model Front.png" width="1000"> | <img src="/images/Full Model Top.png" width="1000"> |
|-|-|-|
| <img src="/images/Full Model Left.png" width="1000"> | <img src="/images/Full Model Right.png" width="1000"> | <img src="/images/Full Model Back.png" width="1000"> |

### Case

| <img src="/images/Alarm Case ISO.png" width="1000"> | <img src="/images/Alarm Case Front.png" width="1000"> | <img src="/images/Alarm Case Top.png" width="1000"> |
|-|-|-|
| <img src="/images/Alarm Case Left.png" width="1000"> | <img src="/images/Alarm Case Right.png" width="1000"> | <img src="/images/Alarm Case Back.png" width="1000"> |

### Lid

| <img src="/images/Alarm Lid ISO.png" width="1000"> | <img src="/images/Alarm Lid Front.png" width="1000"> | <img src="/images/Alarm Lid Top.png" width="1000"> |
|-|-|-|
| <img src="/images/Alarm Lid Left.png" width="1000"> | <img src="/images/Alarm Lid Right.png" width="1000"> | <img src="/images/Alarm Lid Back.png" width="1000"> |






























