
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLfqnOOFKv"
#define BLYNK_DEVICE_NAME "MARC1"
char auth[] = "TNvGZhgybA7iO9qZ1yZiKZQutEQdQDdr";

#include <IRremote.h>

#define irPin 5 // IR sensor pin

IRrecv irrecv(irPin);
decode_results results;

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

#define REMOTE_LIGHT1_DATA 16191727//16724175
#define REMOTE_LIGHT2_DATA 16224367//16718055
#define REMOTE_LIGHT3_DATA 16208047//16743045
#define REMOTE_LIGHT4_DATA 16199887//16716015

// Define Relay Pins
#define r1 22
#define r2 19
#define r3 18
#define r4 17

// Define Switch Pins
#define s1 25
#define s2 26
#define s3 27
#define s4 13

// Switch Flags
bool SWITCH5_FLAG = 1;
bool SWITCH6_FLAG = 1;
bool SWITCH7_FLAG = 1;
bool SWITCH8_FLAG = 1;

// Default Relay State
bool relay1 = LOW;
bool relay2 = LOW;
bool relay3 = LOW;
bool relay4 = LOW;


// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD

#include "BlynkEdgent.h"


BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  relay1 = pinValue;
  digitalWrite(r1 , pinValue);
  // process received value
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  relay2 = pinValue;
  Serial.print("Relay2 - ");Serial.println(pinValue);
  digitalWrite(r2 , pinValue);
  // process received value
}

BLYNK_WRITE(V3)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  relay3 = pinValue;
  Serial.print("Relay3 - ");Serial.println(pinValue);
  digitalWrite(r3 , pinValue);
  // process received value
}

BLYNK_WRITE(V4)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  relay4 = pinValue;
  digitalWrite(r4 , pinValue);
  // process received value
}


void setup()
{
  Serial.begin(115200);
  delay(100);

  irrecv.enableIRIn(); // Enabling IR sensor

  pinMode(s1, INPUT_PULLUP);
  pinMode(s2, INPUT_PULLUP);
  pinMode(s3, INPUT_PULLUP);
  pinMode(s4, INPUT_PULLUP);

  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);

  digitalWrite(r1, 0);
  digitalWrite(r2, 0);
  digitalWrite(r3, 0);
  digitalWrite(r4, 0);

  BlynkEdgent.begin();
}

void loop()
{
  BlynkEdgent.run();
  swfeedback();
  irsense();
}
