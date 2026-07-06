#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <WiFi.h>
#include "time.h"

// define pins
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

// initialize screen object
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

//set wifi for better time accuracy
const char* ssid = "wifi name";
const char* password = "wifi password";
const char* ntpServer = "pool.ntp.org";

const long gmtOffset_sec = -18000; // offset from gmt to test (-5 hours)
const int daylightOffset_sec = 3600; //off set froim daylight savings

void setup() {
  Serial.begin(115200);a
  tft.init(284, 76);             // screen dimensions
  tft.setColRowStart(82, 18);    // offsets to line up this unusual panel
  tft.setRotation(2);            // orientation, could be different, try 0-3
  Serial.println("TFT Initialized!");

  tft.fillScreen(ST77XX_BLACK);  // clear the screen
  tft.setCursor(0, 0);           // top-left corner
  tft.setTextSize(2);            // a readable size
  tft.print("Intializing");

 //connect to wifi
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

  //setup rotary encoder and switches
  pinMode(BZ1, OUTPUT);
  digitalWrite(BZ1, LOW);

  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
  pinMode(ENC_SW1, INPUT_PULLUP);

  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);  
}



void loop() {
   readEncoder();
  readButtons();
  checkAlarm();
  updateBuzzer();

  // Redraw the screen every 250 milliseconds
  if (millis() - lastDisplayUpdate > 250) {
    printTime();
    lastDisplayUpdate = millis();
}

void printTime (){
  int hour, minute, second;

  bool timeValid = getCurrentTime(hour, minute, second);

  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 0);

  if (alarmRinging) {
    tft.setTextColor(ST77XX_RED);
    tft.setTextSize(3);
    tft.println("ALARM!");

    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(1);
    tft.println("Press any button");
    return;
  }

  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);

  if (timeValid) {
    tft.print("Time ");
    printTwoDigits(hour);
    tft.print(":");
    printTwoDigits(minute);
    tft.print(":");
    printTwoDigits(second);
  } else {
    tft.print("No time sync");
  }

  tft.setCursor(0, 25);
  tft.print("Alarm ");
  printTwoDigits(alarmHour);
  tft.print(":");
  printTwoDigits(alarmMinute);

  tft.print(" ");

  if (alarmEnabled) {
    tft.print("ON");
  } else {
    tft.print("OFF");
  }

  tft.setCursor(0, 50);
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_YELLOW);

  if (mode == SHOW_TIME) {
    tft.print("SW2 set  SW3 on/off");
  } else if (mode == SET_ALARM_HOUR) {
    tft.print("Set alarm HOUR");
  } else if (mode == SET_ALARM_MINUTE) {
    tft.print("Set alarm MINUTE");
  }

}

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

void readEncoder() { // read the encoder
  int encA = digitalRead(ENC_A);

  // Detect one step of rotation.
  if (encA != lastEncA && encA == LOW) {
    int encB = digitalRead(ENC_B);

    if (encB == HIGH) {
      changeValue(1);
    } else {
      changeValue(-1);
    }
  }

  lastEncA = encA;
}

void changeValue(int amount) { // allows user to set the time in case its a little off
  if (alarmRinging) {
    return;
  }

  if (mode == SET_ALARM_HOUR) {
    alarmHour += amount;

    if (alarmHour < 0) {
      alarmHour = 23;
    }

    if (alarmHour > 23) {
      alarmHour = 0;
    }
  }

  if (mode == SET_ALARM_MINUTE) {
    alarmMinute += amount;

    if (alarmMinute < 0) {
      alarmMinute = 59;
    }

    if (alarmMinute > 59) {
      alarmMinute = 0;
    }
  }
}

void readButtons() { // reads the buttons on the pcb
  bool sw2State = digitalRead(SW2);
  bool sw3State = digitalRead(SW3);
  bool sw4State = digitalRead(SW4);
  bool encSWState = digitalRead(ENC_SW1);

  // debounce so one press does not count many times
  if (millis() - lastButtonTime < debounceDelay) {
    lastSW2 = sw2State;
    lastSW3 = sw3State;
    lastSW4 = sw4State;
    lastEncSW = encSWState;
    return;
  }

  // If alarm is ringing, any button stops it
  if (alarmRinging) {
    if (
      buttonPressed(sw2State, lastSW2) ||
      buttonPressed(sw3State, lastSW3) ||
      buttonPressed(sw4State, lastSW4) ||
      buttonPressed(encSWState, lastEncSW)
    ) {
      stopAlarm();
      lastButtonTime = millis();
    }

    lastSW2 = sw2State;
    lastSW3 = sw3State;
    lastSW4 = sw4State;
    lastEncSW = encSWState;
    return;
  }

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

    lastButtonTime = millis();
  }

  lastSW2 = sw2State;
  lastSW3 = sw3State;
  lastSW4 = sw4State;
  lastEncSW = encSWState;
}

bool buttonPressed(bool currentState, bool previousState) {
  return previousState == HIGH && currentState == LOW;
}

void showMessage(const char* message) { // showws a messagfe for wifi and UI
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 20);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.print(message);
}

void printTwoDigits(int number) { // helps print out the time 
  if (number < 10) {
    tft.print("0");
  }

  tft.print(number);
}




























