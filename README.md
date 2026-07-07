# Icicle-Alarm-Clock

<p align="center">
  <img src="/images/Full Model.gif" width="250"></p>
</p>


## Initial goals:
### Priority Goals:
- This alarm clock should be able to tell the time (obviously).
- This alarm clock should be able to store multiple alarms, as well as be able to toggle each alarm.
### Less important goals
- This alarm clock should have a volume knob.
- This alarm clock should be able to play customized sounds.


## Parts list (Bill of Materials)

| Part | Quantity | Price | Link |  
| ---------- | ---------- | ---------- | ---------- |
| Lolin C3 Mini ESP32 | 1 | Provided in Kit | N/A |
| 2.25in TFT display | 1 | Provided in Kit | N/A |
| Custom PCB | 1 | $8.67 | JLPCB |
| 3.3V Piezo Buzzer | 1 | Provided in Kit | N/A |
| EC11 Rotary Encoder Switch Button | 1 | $7.55 CAD | [AliExpress](https://www.aliexpress.com/item/1005008610645902.html?spm=a2g0o.productlist.main.4.2c317465sXCwvW&aem_p4p_detail=202607070924475087980507770000005617811&algo_pvid=e8d69d13-1db0-4bfd-9fc3-c2f3c209ff59&algo_exp_id=e8d69d13-1db0-4bfd-9fc3-c2f3c209ff59-3&pdp_ext_f=%7B%22order%22%3A%22342%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21CAD%214.48%214.47%21%21%213.08%213.07%21%402103123917834414872141769e2889%2112000045944331228%21sea%21CA%213742168056%21ABX%211%210%21n_tag%3A-29910%3Bd%3A5e0cbcd8%3Bm03_new_user%3A-29895%3BpisId%3A5000000206226397&curPageLogUid=CCZx2Qf1bu2y&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005008610645902%7C_p_origin_prod%3A&search_p4p_id=202607070924475087980507770000005617811_1) |
| 1k ohm Resistor | 1 | $0.88 CAD | [AliExpress](https://www.aliexpress.com/item/1005007643210127.html?spm=a2g0o.productlist.main.2.6d624f792su7dm&algo_pvid=c0e45152-9ff0-4ec1-bf8a-26d206a77dc9&algo_exp_id=c0e45152-9ff0-4ec1-bf8a-26d206a77dc9-1&pdp_ext_f=%7B%22order%22%3A%22886%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21CAD%210.88%210.85%21%21%214.10%213.94%21%4021033d1217834393402286197efc5e%2112000041624997313%21sea%21CA%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3A5e0cbcd8%3Bm03_new_user%3A-29895&curPageLogUid=x2mLNx3qELF5&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005007643210127%7C_p_origin_prod%3A) |
| 10k Ohm Resistor | 1 | $0.88 CAD | [AliExpress](https://www.aliexpress.com/item/1005007643210127.html?spm=a2g0o.productlist.main.2.6d624f792su7dm&algo_pvid=c0e45152-9ff0-4ec1-bf8a-26d206a77dc9&algo_exp_id=c0e45152-9ff0-4ec1-bf8a-26d206a77dc9-1&pdp_ext_f=%7B%22order%22%3A%22886%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21CAD%210.88%210.85%21%21%214.10%213.94%21%4021033d1217834393402286197efc5e%2112000041624997313%21sea%21CA%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3A5e0cbcd8%3Bm03_new_user%3A-29895&curPageLogUid=x2mLNx3qELF5&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005007643210127%7C_p_origin_prod%3A) |
| S8050 Transistor | 1 | $7.47 CAD | [AliExpress](https://www.aliexpress.com/item/1005006811049225.html?spm=a2g0o.productlist.main.3.23a042ccHx9qk2&algo_pvid=fbd39ea5-1fc0-4b3e-8849-d372df714f92&algo_exp_id=fbd39ea5-1fc0-4b3e-8849-d372df714f92-2&pdp_ext_f=%7B%22order%22%3A%22191%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21CAD%217.47%214.89%21%21%2134.89%2122.85%21%40210319b717834404073473874e8d99%2112000038384320363%21sea%21CA%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3A5e0cbcd8%3Bm03_new_user%3A-29895&curPageLogUid=pNodTbyBBguG&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005006811049225%7C_p_origin_prod%3A) |
| Case | 1 | Provided in Kit | N/A |
| Lid | 1 | Provided in Kit | N/A |
| 1x8 2.54mm pin headers | 2 | $3.72 CAD | [AliExpress](https://www.aliexpress.com/item/32847429443.html?spm=a2g0o.productlist.main.1.166537c1nJpVM4&algo_pvid=ee7e908c-bf01-4b82-bbfa-7b54397e240c&algo_exp_id=ee7e908c-bf01-4b82-bbfa-7b54397e240c-0&pdp_ext_f=%7B%22order%22%3A%22271%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21CAD%213.72%211.44%21%21%212.56%210.99%21%402103110517834417116324369e57b9%2165154055537%21sea%21CA%213742168056%21ABX%211%210%21n_tag%3A-29910%3Bd%3A5e0cbcd8%3Bm03_new_user%3A-29895%3BpisId%3A5000000207288090&curPageLogUid=epGjb5yLUGmR&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A32847429443%7C_p_origin_prod%3A) |
| Keyboard Switches | 3 | Provided in Kit | N/A |
| Keyboard Keycaps | 3 | Provided in Kit | N/A |
| Male to male Dupont wires | 16 | $3.50 CAD | [AliExpress](https://www.aliexpress.com/item/4000109443054.html?spm=a2g0o.productlist.main.2.3b6b6071c6l0Fw&algo_pvid=0befaeab-1c07-467e-9051-386d31b85111&algo_exp_id=0befaeab-1c07-467e-9051-386d31b85111-1&pdp_ext_f=%7B%22order%22%3A%22203%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21CAD%213.50%211.44%21%21%212.41%210.99%21%402103122117834414202824009ecbf1%2110000000283106726%21sea%21CA%213742168056%21ABX%211%210%21n_tag%3A-29910%3Bd%3A5e0cbcd8%3Bm03_new_user%3A-29895%3BpisId%3A5000000210940427&curPageLogUid=BccdmUIZQV69&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A4000109443054%7C_p_origin_prod%3A) | 


| Price | HST (Ontario Sales Tax) | Total Price | Total USD Price |  
| ---------- | ---------- | ---------- | ---------- |
| $32.67 CAD |  $4.25 CAD HST) | $36.92 CAD | 26.01 USD |


## Planning:
- I plan to use a rotary encoder with a switch to navigate the UI, as well as extra switches to toggle alarms or other features easily.
- The buzzer will be integrated into a transistor circuit, increasing the volume of the alarm while keeping it adjustable.

## Schemtaic (4 Hours):
- Due to the struggle for GPIO pins on the WEMOS, I was only able to add two switches.
- The rotary encoder and two switches use 5 GPIO pins, while the buzzer uses one.
- The THT display uses the other 6 GPIO pins.
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
- All 3d files can be found in the 3d model folder.
- The case and lid are stored in [/3d models/STEP files/Alarm Clock Base.step](https://github.com/oSnwy/Icicle-Alarm-Clock/blob/main/3d%20models/STEP%20files/Alarm%20Clock%20Base.step) and [/3d models/STEP files/Alarm Clock Lid.step](https://github.com/oSnwy/Icicle-Alarm-Clock/blob/main/3d%20models/STEP%20files/Alarm%20Clock%20Lid.step)

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

## Code (8 Hours)
Easily the longest part of the project. The code was written in C++ in the Arduino IDE. I used the wifi capabilities of the ESP32 to sync the time accurately without an RTC. This allows me to retrieve the time from pool.ntp.org, but does mean that it must be connected to the wifi. However, we can use the rotary encoder and the switches in order to mantually adjust the time if needed, such as when wifi is not possible.

### Resources Used
If anyone wants to learn how to code an Alarm Clock, these are some excellent resources to get started with.

| Use | Website |
| - | - |
| Install ESP32 in Arduino IDE | https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/ |
| How to connect ESP32 to wifi | https://randomnerdtutorials.com/getting-started-esp32-c3-super-mini/ |
| How to get the time on an ESP32 | https://randomnerdtutorials.com/esp32-date-time-ntp-client-server-arduino/ |
| struct TM reference sheet | https://cplusplus.com/reference/ctime/tm/ |
| WEMOS C3 mini reference sheet | https://www.wemos.cc/en/latest/c3/c3_mini.html |

Keep in mind that the type of microcontroller you are using may affect the firmware.

### Libraries
```C++
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <WiFi.h>
#include "time.h"
```
I used Adafruit and SPI to connect the microcontroller to the THT display, and wifi.h and time.h to get and store the time from pool.ntp.org. You may need to download the libraries before using them.

### Pins
```C++
#define BZ1 0
#define ENC_A 1
#define ENC_SW1 2
#define ENC_B 3
#define SW2 4
#define SW3 5
#define SW4 6
#define TFT_CS 7
#define TFT_DC 8
#define TFT_RST 10
#define TFT_MOSI 20
#define TFT_SCLK 21
```
Defining each pin of the microcontroller makes it easier and more organized. This will change depending on how your microcontroller is wired.

### Setting up Wifi and Time
```C++
const char* ssid = "wifi name";
const char* password = "wifi password";
const char* ntpServer = "pool.ntp.org";

const long gmtOffset_sec = -18000; // offset from gmt to test (-5 hours)
const int daylightOffset_sec = 3600; //off set froim daylight savings
```
We can access the wifi by using the ssid and password, which allows us to connect to the network later. The time can be found by getting the GMT timezone and offsetting it by the difference from GMT to EST, which is -5 hours. We can also use daylight savings offset to fix the hour difference.

### Display
```C++
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
void setup() {
  Serial.begin(115200);a
  tft.init(284, 76);             
  tft.setColRowStart(82, 18);    
  tft.setRotation(2);            
  Serial.println("TFT Initialized!");

  tft.fillScreen(ST77XX_BLACK);  
  tft.setCursor(0, 0);           
  tft.setTextSize(2);          
  tft.print("Intializing");
}
```
This simply sets up the screen.

### Clock
```C++
int tries = 0;
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED && tries < 30) {
    delay(500);
    Serial.print(".");
    tries++;
  }
  
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  if (getLocalTime(&timeinfo)) {
      Serial.println("Time synced!");
      showMessage("Time synced!");
      delay(1000);
    } else {
      Serial.println("Time sync failed!");
      showMessage("Time sync failed");
      delay(1500);
    }
  } else {
    Serial.println("\nWiFi failed!");
    showMessage("WiFi failed");
    delay(1500);
```
This block of code allows us to sync the internal clock of the microcontroller to the timezone, as well as any offsets.

### Alarm
```C++
void checkAlarm() { // check if its time to get up
  int hour, minute, second;

  if (!getCurrentTime(hour, minute, second)) {
    return;
  }

  // Reset the one-minute trigger lock when we leave the alarm minute.
  if (minute != alarmMinute) {
    alarmTriggeredThisMinute = false;
  }

  // If alarm is enabled and time matches, start ringing.
  if (
    alarmEnabled &&
    !alarmRinging &&
    !alarmTriggeredThisMinute &&
    hour == alarmHour &&
    minute == alarmMinute
  ) {
    alarmRinging = true;
    alarmTriggeredThisMinute = true;
  }
}

void updateBuzzer() { // if its time to get up gotta get the buzzer going
  if (!alarmRinging) {
    noTone(BZ1);
    beepOn = false;
    return;
  }

  // Make the alarm beep on/off every 300 ms.
  if (millis() - lastBeepToggle > 300) {
    lastBeepToggle = millis();
    beepOn = !beepOn;

    if (beepOn) {
      tone(BZ1, 2000);   // 2000 Hz beep
    } else {
      noTone(BZ1);
    }
  }
}
```
We can use a function in order to check whether the alarm should be going off. The updateBuzzer function allows us to make the buzzer beep on and off, as well as test when it should be stopped.

### Clock Adjustment
```C++
void changeValue(int amount) { 
  if (mode == SET_ALARM_MINUTE) {
      alarmMinute += amount;
  if (mode == SET_ALARM_HOUR) {
      alarmHour += amount;
}
```
We can use the rotary knob and switches in tandem to adjust the clock's time in case of desync.
```C++
// SW2 can set hour time
  if (buttonPressed(sw2State, lastSW2)) {
    mode = SET_ALARM_HOUR;
    lastButtonTime = millis();
  }

  // SW3 toggles alarm on/off
  if (buttonPressed(sw3State, lastSW3)) {
    alarmEnabled = !alarmEnabled;
    mode = SHOW_TIME;
    lastButtonTime = millis();
  }

  // SW4 goes back to main screen
  if (buttonPressed(sw4State, lastSW4)) {
    mode = SHOW_TIME;
    lastButtonTime = millis();
  }

  // Rotary encoder switch moves between setting hour and minute
  if (buttonPressed(encSWState, lastEncSW)) {
    if (mode == SHOW_TIME) {
      mode = SET_ALARM_HOUR;
    } else if (mode == SET_ALARM_HOUR) {
      mode = SET_ALARM_MINUTE;
    } else if (mode == SET_ALARM_MINUTE) {
      mode = SHOW_TIME;
    }
```
The detection of the switches and rotary encoder allows us to change the UI and set the alarm and clock.













