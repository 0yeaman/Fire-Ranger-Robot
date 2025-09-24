/*

  Demonstrates simple RX and TX operation.
  Any of the Basic_TX examples can be used as a transmitter.
  Please read through 'NRFLite.h' for a description of all the methods available in the library.

  Radio    Arduino
  CE    -> 9
  CSN   -> 10 (Hardware SPI SS)
  MOSI  -> 11 (Hardware SPI MOSI)
  MISO  -> 12 (Hardware SPI MISO)
  SCK   -> 13 (Hardware SPI SCK)
  IRQ   -> No connection
  VCC   -> No more than 3.6 volts
  GND   -> GND

*/

#include <SPI.h>
#include <NRFLite.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX = 9; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = -1; // Connects to module's TX 
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

// Create the Player object
DFRobotDFPlayerMini player;
const static uint8_t RADIO_ID = 0;       // Our radio's id.  The transmitter will send to this id.
const static uint8_t PIN_RADIO_CE = 8;
const static uint8_t PIN_RADIO_CSN = 10;

struct RadioPacket // Any packet up to 32 bytes can be sent.
{
  uint8_t FromRadioId;
  uint32_t OnTimeMillis;
  uint32_t FailedTxCount;
};

NRFLite _radio;
RadioPacket _radioData;
int relay1 = 19;
int relay2 = 18;
int relay3 = 17;
int relay4 = 16;
int larmdown = 2;
int larmup = 3;
int rarmdown = 5;
int rarmup = 4;
int cutter = 15;
int pump = 14;
int trigger=7;
int echo=6;
void setup()
{
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(larmdown, OUTPUT);
  pinMode(larmup, OUTPUT);
  pinMode(rarmdown, OUTPUT);
  pinMode(rarmup, OUTPUT);
  pinMode(cutter, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(115200);
  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);

  // Start communication with DFPlayer Mini
  if (player.begin(softwareSerial)) {
   Serial.println("OK");

    // Set volume to maximum (0 to 30).
    player.volume(30);
    // Play the first MP3 file on the SD card
    player.play(1);
  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }
  // By default, 'init' configures the radio to use a 2MBPS bitrate on channel 100 (channels 0-125 are valid).
  // Both the RX and TX radios must have the same bitrate and channel to communicate with each other.
  // You can run the 'ChannelScanner' example to help select the best channel for your environment.
  // You can assign a different bitrate and channel as shown below.
  //   _radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE2MBPS, 100) // THE DEFAULT
  //   _radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE1MBPS, 75)
  //   _radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN, NRFLite::BITRATE250KBPS, 0)

  if (!_radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN))
  {
    Serial.println("Cannot communicate with radio");
    while (1); // Wait here forever.
  }
}

void loop()
{
  digitalWrite(trigger,LOW);
  delay(10);
  digitalWrite(trigger,HIGH);
  delay(10);
  digitalWrite(trigger,LOW);
  int distance=pulseIn(echo,HIGH);
  Serial.println(distance);
  if(distance<1000)
  {
    digitalWrite(relay1,LOW);
    digitalWrite(relay2,LOW);
    digitalWrite(relay3,LOW);
    digitalWrite(relay4,LOW);
    
  }
  while (_radio.hasData())
  {
    _radio.readData(&_radioData); // Note how '&' must be placed in front of the variable name.

    String msg = "Radio ";
    msg += _radioData.FromRadioId;
    msg += ", ";
    msg += _radioData.OnTimeMillis;
    msg += " ms, ";
    msg += _radioData.FailedTxCount;
    msg += " Failed TX";
     if (_radioData.OnTimeMillis == 1)
    {
    player.volume(30);
    // Play the first MP3 file on the SD card
    player.play(1);
    }
        else if (_radioData.OnTimeMillis == 2)
    {
    player.volume(30);
    // Play the first MP3 file on the SD card
    player.play(2);
    }
       else  if (_radioData.OnTimeMillis == 3)
    {
    player.volume(30);
    // Play the first MP3 file on the SD card
    player.play(3);
    }
         if (_radioData.OnTimeMillis == 4)
    {
    player.volume(30);
    // Play the first MP3 file on the SD card
    player.play(4);
    }
    if (_radioData.OnTimeMillis == 11)
    {
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, LOW);
      digitalWrite(relay3, HIGH);
      digitalWrite(relay4, LOW);
    }
    else if (_radioData.OnTimeMillis == 12)
    {
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, HIGH);
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, HIGH);
    }
    else if (_radioData.OnTimeMillis == 14)
    {
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, HIGH);
      digitalWrite(relay3, HIGH);
      digitalWrite(relay4, LOW);
    }
    else if (_radioData.OnTimeMillis == 13)
    {
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, LOW);
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, HIGH);
    }
    else if (_radioData.OnTimeMillis == 8)
    {
      digitalWrite(larmup, HIGH);
      digitalWrite(larmdown, LOW);

    }
    else if (_radioData.OnTimeMillis == 7)
    {
      digitalWrite(larmup, LOW);
      digitalWrite(larmdown, HIGH);

    }
    else if (_radioData.OnTimeMillis == 6)
    {
      digitalWrite(rarmup, HIGH);
      digitalWrite(rarmdown, LOW);

    }
    else if (_radioData.OnTimeMillis == 5)
    {
      digitalWrite(rarmup, LOW);
      digitalWrite(rarmdown, HIGH);

    }
    else if (_radioData.OnTimeMillis == 9)
    {

      digitalWrite(cutter, HIGH);

    }
    else if (_radioData.OnTimeMillis == 10)
    {

      digitalWrite(pump, HIGH);

    }
    else if (_radioData.OnTimeMillis == 0)
    {
       digitalWrite(pump, LOW);
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, LOW);
      digitalWrite(larmup, LOW);
      digitalWrite(larmdown, LOW);
      digitalWrite(rarmup, LOW);
      digitalWrite(rarmdown, LOW);
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, LOW);
      digitalWrite(cutter, LOW);
    }

    Serial.println(msg);
  }
}
