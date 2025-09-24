#include <SPI.h>
#include <NRFLite.h>

const static uint8_t RADIO_ID = 1;             // Our radio's id.
const static uint8_t DESTINATION_RADIO_ID = 0; // Id of the radio we will transmit to.
const static uint8_t PIN_RADIO_CE = 9;
const static uint8_t PIN_RADIO_CSN = 10;

struct RadioPacket // Any packet up to 32 bytes can be sent.
{
    uint8_t FromRadioId;
    uint32_t OnTimeMillis;
    uint32_t FailedTxCount;
};

NRFLite _radio;
RadioPacket _radioData;

int voice1=2;
int voice2=3;
int voice3=4;
int voice4=5;
int leftarm1=6;
int leftarm2=7;
int rightarm1=16;
int rightarm2=17;
int ac1=18;
int ac2=19;
void setup()
{
  Serial.begin(115200);
  pinMode(voice1,INPUT_PULLUP);
  pinMode(voice2,INPUT_PULLUP);
  pinMode(voice3,INPUT_PULLUP);
  pinMode(voice4,INPUT_PULLUP);
  pinMode(leftarm1,INPUT_PULLUP);
  pinMode(leftarm2,INPUT_PULLUP);
  pinMode(rightarm1,INPUT_PULLUP);
  pinMode(rightarm2,INPUT_PULLUP);
  pinMode(ac1,INPUT_PULLUP);
  pinMode(ac2,INPUT_PULLUP);
   if (!_radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN))
    {
        Serial.println("Cannot communicate with radio");
        while (1); // Wait here forever.
    }
    Serial.println("START");
    _radioData.FromRadioId = RADIO_ID;
}
void loop()
{
  if(analogRead(A0)>800)
  {

  _radioData.OnTimeMillis = 11;

    Serial.print("Sending ");
    Serial.print(_radioData.OnTimeMillis);
    Serial.print(" ms");

    // By default, 'send' transmits data and waits for an acknowledgement.  If no acknowledgement is received,
    // it will try again up to 16 times.  This retry logic is built into the radio hardware itself, so it is very fast.
    // You can also perform a NO_ACK send that does not request an acknowledgement.  In this situation, the data packet
    // will only be transmitted a single time and there is no verification of delivery.  So NO_ACK sends are suited for
    // situations where performance is more important than reliability.
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::REQUIRE_ACK) // THE DEFAULT
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::NO_ACK)
    
    if (_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData))) // Note how '&' must be placed in front of the variable name.
    {
        Serial.println("...Success");
    }
    else
    {
        Serial.println("...Failed");
        _radioData.FailedTxCount++;
    }
   delay(250);
  
  }
    else if(analogRead(A0)<300)
  {

  _radioData.OnTimeMillis = 12;

    Serial.print("Sending ");
    Serial.print(_radioData.OnTimeMillis);
    Serial.print(" ms");

    // Byelse default, 'send' transmits data and waits for an acknowledgement.  If no acknowledgement is received,
    // it will try again up to 16 times.  This retry logic is built into the radio hardware itself, so it is very fast.
    // You can also perform a NO_ACK send that does not request an acknowledgement.  In this situation, the data packet
    // will only be transmitted a single time and there is no verification of delivery.  So NO_ACK sends are suited for
    // situations where performance is more important than reliability.
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::REQUIRE_ACK) // THE DEFAULT
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::NO_ACK)
    
    if (_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData))) // Note how '&' must be placed in front of the variable name.
    {
        Serial.println("...Success");
    }
    else
    {
        Serial.println("...Failed");
        _radioData.FailedTxCount++;
    }
   delay(250);
  
  }

   else if(analogRead(A1)>800)
  {

  _radioData.OnTimeMillis = 13;

    Serial.print("Sending ");
    Serial.print(_radioData.OnTimeMillis);
    Serial.print(" ms");

    // By default, 'send' transmits data and waits for an acknowledgement.  If no acknowledgement is received,
    // it will try again up to 16 times.  This retry logic is built into the radio hardware itself, so it is very fast.
    // You can also perform a NO_ACK send that does not request an acknowledgement.  In this situation, the data packet
    // will only be transmitted a single time and there is no verification of delivery.  So NO_ACK sends are suited for
    // situations where performance is more important than reliability.
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::REQUIRE_ACK) // THE DEFAULT
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::NO_ACK)
    
    if (_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData))) // Note how '&' must be placed in front of the variable name.
    {
        Serial.println("...Success");
    }
    else
    {
        Serial.println("...Failed");
        _radioData.FailedTxCount++;
    }
   delay(250);
  
  }
    else if(analogRead(A1)<300)
  {

  _radioData.OnTimeMillis = 14;

    Serial.print("Sending ");
    Serial.print(_radioData.OnTimeMillis);
    Serial.print(" ms");

    // Byelse default, 'send' transmits data and waits for an acknowledgement.  If no acknowledgement is received,
    // it will try again up to 16 times.  This retry logic is built into the radio hardware itself, so it is very fast.
    // You can also perform a NO_ACK send that does not request an acknowledgement.  In this situation, the data packet
    // will only be transmitted a single time and there is no verification of delivery.  So NO_ACK sends are suited for
    // situations where performance is more important than reliability.
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::REQUIRE_ACK) // THE DEFAULT
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::NO_ACK)
    
    if (_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData))) // Note how '&' must be placed in front of the variable name.
    {
        Serial.println("...Success");
    }
    else
    {
        Serial.println("...Failed");
        _radioData.FailedTxCount++;
    }
   delay(250);
  
  }
  else if(digitalRead(voice1)==LOW)
  {
  _radioData.OnTimeMillis = 1;

    Serial.print("Sending ");
    Serial.print(_radioData.OnTimeMillis);
    Serial.print(" ms");

    // By default, 'send' transmits data and waits for an acknowledgement.  If no acknowledgement is received,
    // it will try again up to 16 times.  This retry logic is built into the radio hardware itself, so it is very fast.
    // You can also perform a NO_ACK send that does not request an acknowledgement.  In this situation, the data packet
    // will only be transmitted a single time and there is no verification of delivery.  So NO_ACK sends are suited for
    // situations where performance is more important than reliability.
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::REQUIRE_ACK) // THE DEFAULT
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::NO_ACK)
    
    if (_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData))) // Note how '&' must be placed in front of the variable name.
    {
        Serial.println("...Success");
    }
    else
    {
        Serial.println("...Failed");
        _radioData.FailedTxCount++;
    }
   delay(250);
  } 


  else if(digitalRead(voice2)==LOW)
  {
  _radioData.OnTimeMillis = 2;

    Serial.print("Sending ");
    Serial.print(_radioData.OnTimeMillis);
    Serial.print(" ms");

    // By default, 'send' transmits data and waits for an acknowledgement.  If no acknowledgement is received,
    // it will try again up to 16 times.  This retry logic is built into the radio hardware itself, so it is very fast.
    // You can also perform a NO_ACK send that does not request an acknowledgement.  In this situation, the data packet
    // will only be transmitted a single time and there is no verification of delivery.  So NO_ACK sends are suited for
    // situations where performance is more important than reliability.
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::REQUIRE_ACK) // THE DEFAULT
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::NO_ACK)
    
    if (_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData))) // Note how '&' must be placed in front of the variable name.
    {
        Serial.println("...Success");
    }
    else
    {
        Serial.println("...Failed");
        _radioData.FailedTxCount++;
    }
   delay(250);
  } 


  else if(digitalRead(voice3)==LOW)
  {
  _radioData.OnTimeMillis = 3;

    Serial.print("Sending ");
    Serial.print(_radioData.OnTimeMillis);
    Serial.print(" ms");

    // By default, 'send' transmits data and waits for an acknowledgement.  If no acknowledgement is received,
    // it will try again up to 16 times.  This retry logic is built into the radio hardware itself, so it is very fast.
    // You can also perform a NO_ACK send that does not request an acknowledgement.  In this situation, the data packet
    // will only be transmitted a single time and there is no verification of delivery.  So NO_ACK sends are suited for
    // situations where performance is more important than reliability.
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::REQUIRE_ACK) // THE DEFAULT
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::NO_ACK)
    
    if (_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData))) // Note how '&' must be placed in front of the variable name.
    {
        Serial.println("...Success");
    }
    else
    {
        Serial.println("...Failed");
        _radioData.FailedTxCount++;
    }
   delay(250);
  } 



  else if(digitalRead(voice4)==LOW)
  {
  _radioData.OnTimeMillis = 4;

    Serial.print("Sending ");
    Serial.print(_radioData.OnTimeMillis);
    Serial.print(" ms");

    // By default, 'send' transmits data and waits for an acknowledgement.  If no acknowledgement is received,
    // it will try again up to 16 times.  This retry logic is built into the radio hardware itself, so it is very fast.
    // You can also perform a NO_ACK send that does not request an acknowledgement.  In this situation, the data packet
    // will only be transmitted a single time and there is no verification of delivery.  So NO_ACK sends are suited for
    // situations where performance is more important than reliability.
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::REQUIRE_ACK) // THE DEFAULT
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::NO_ACK)
    
    if (_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData))) // Note how '&' must be placed in front of the variable name.
    {
        Serial.println("...Success");
    }
    else
    {
        Serial.println("...Failed");
        _radioData.FailedTxCount++;
    }
   delay(250);
  } 


  else if(digitalRead(leftarm1)==LOW)
  {
  _radioData.OnTimeMillis = 5;

    Serial.print("Sending ");
    Serial.print(_radioData.OnTimeMillis);
    Serial.print(" ms");

    // By default, 'send' transmits data and waits for an acknowledgement.  If no acknowledgement is received,
    // it will try again up to 16 times.  This retry logic is built into the radio hardware itself, so it is very fast.
    // You can also perform a NO_ACK send that does not request an acknowledgement.  In this situation, the data packet
    // will only be transmitted a single time and there is no verification of delivery.  So NO_ACK sends are suited for
    // situations where performance is more important than reliability.
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::REQUIRE_ACK) // THE DEFAULT
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::NO_ACK)
    
    if (_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData))) // Note how '&' must be placed in front of the variable name.
    {
        Serial.println("...Success");
    }
    else
    {
        Serial.println("...Failed");
        _radioData.FailedTxCount++;
    }
   delay(250);
  } 


  else if(digitalRead(leftarm2)==LOW)
  {
  _radioData.OnTimeMillis = 6;

    Serial.print("Sending ");
    Serial.print(_radioData.OnTimeMillis);
    Serial.print(" ms");

    // By default, 'send' transmits data and waits for an acknowledgement.  If no acknowledgement is received,
    // it will try again up to 16 times.  This retry logic is built into the radio hardware itself, so it is very fast.
    // You can also perform a NO_ACK send that does not request an acknowledgement.  In this situation, the data packet
    // will only be transmitted a single time and there is no verification of delivery.  So NO_ACK sends are suited for
    // situations where performance is more important than reliability.
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::REQUIRE_ACK) // THE DEFAULT
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::NO_ACK)
    
    if (_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData))) // Note how '&' must be placed in front of the variable name.
    {
        Serial.println("...Success");
    }
    else
    {
        Serial.println("...Failed");
        _radioData.FailedTxCount++;
    }
   delay(250);
  } 

  else if(digitalRead(rightarm1)==LOW)
  {
  _radioData.OnTimeMillis = 7;

    Serial.print("Sending ");
    Serial.print(_radioData.OnTimeMillis);
    Serial.print(" ms");

    // By default, 'send' transmits data and waits for an acknowledgement.  If no acknowledgement is received,
    // it will try again up to 16 times.  This retry logic is built into the radio hardware itself, so it is very fast.
    // You can also perform a NO_ACK send that does not request an acknowledgement.  In this situation, the data packet
    // will only be transmitted a single time and there is no verification of delivery.  So NO_ACK sends are suited for
    // situations where performance is more important than reliability.
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::REQUIRE_ACK) // THE DEFAULT
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::NO_ACK)
    
    if (_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData))) // Note how '&' must be placed in front of the variable name.
    {
        Serial.println("...Success");
    }
    else
    {
        Serial.println("...Failed");
        _radioData.FailedTxCount++;
    }
   delay(250);
  } 



  else if(digitalRead(rightarm2)==LOW)
  {
  _radioData.OnTimeMillis = 8;

    Serial.print("Sending ");
    Serial.print(_radioData.OnTimeMillis);
    Serial.print(" ms");

    // By default, 'send' transmits data and waits for an acknowledgement.  If no acknowledgement is received,
    // it will try again up to 16 times.  This retry logic is built into the radio hardware itself, so it is very fast.
    // You can also perform a NO_ACK send that does not request an acknowledgement.  In this situation, the data packet
    // will only be transmitted a single time and there is no verification of delivery.  So NO_ACK sends are suited for
    // situations where performance is more important than reliability.
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::REQUIRE_ACK) // THE DEFAULT
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::NO_ACK)
    
    if (_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData))) // Note how '&' must be placed in front of the variable name.
    {
        Serial.println("...Success");
    }
    else
    {
        Serial.println("...Failed");
        _radioData.FailedTxCount++;
    }
   delay(250);
  } 


  else if(digitalRead(ac1)==LOW)
  {
  _radioData.OnTimeMillis = 9;

    Serial.print("Sending ");
    Serial.print(_radioData.OnTimeMillis);
    Serial.print(" ms");

    // By default, 'send' transmits data and waits for an acknowledgement.  If no acknowledgement is received,
    // it will try again up to 16 times.  This retry logic is built into the radio hardware itself, so it is very fast.
    // You can also perform a NO_ACK send that does not request an acknowledgement.  In this situation, the data packet
    // will only be transmitted a single time and there is no verification of delivery.  So NO_ACK sends are suited for
    // situations where performance is more important than reliability.
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::REQUIRE_ACK) // THE DEFAULT
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::NO_ACK)
    
    if (_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData))) // Note how '&' must be placed in front of the variable name.
    {
        Serial.println("...Success");
    }
    else
    {
        Serial.println("...Failed");
        _radioData.FailedTxCount++;
    }
   delay(250);
  } 




 else if(digitalRead(ac2)==LOW)
  {
  _radioData.OnTimeMillis = 10;

    Serial.print("Sending ");
    Serial.print(_radioData.OnTimeMillis);
    Serial.print(" ms");

    // By default, 'send' transmits data and waits for an acknowledgement.  If no acknowledgement is received,
    // it will try again up to 16 times.  This retry logic is built into the radio hardware itself, so it is very fast.
    // You can also perform a NO_ACK send that does not request an acknowledgement.  In this situation, the data packet
    // will only be transmitted a single time and there is no verification of delivery.  So NO_ACK sends are suited for
    // situations where performance is more important than reliability.
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::REQUIRE_ACK) // THE DEFAULT
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::NO_ACK)
    
    if (_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData))) // Note how '&' must be placed in front of the variable name.
    {
        Serial.println("...Success");
    }
    else
    {
        Serial.println("...Failed");
        _radioData.FailedTxCount++;
    }
   delay(250);
  } 
  else
  {
    {
  _radioData.OnTimeMillis = 0;

    Serial.print("Sending ");
    Serial.print(_radioData.OnTimeMillis);
    Serial.print(" ms");

    // By default, 'send' transmits data and waits for an acknowledgement.  If no acknowledgement is received,
    // it will try again up to 16 times.  This retry logic is built into the radio hardware itself, so it is very fast.
    // You can also perform a NO_ACK send that does not request an acknowledgement.  In this situation, the data packet
    // will only be transmitted a single time and there is no verification of delivery.  So NO_ACK sends are suited for
    // situations where performance is more important than reliability.
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::REQUIRE_ACK) // THE DEFAULT
    //   _radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData), NRFLite::NO_ACK)
    
    if (_radio.send(DESTINATION_RADIO_ID, &_radioData, sizeof(_radioData))) // Note how '&' must be placed in front of the variable name.
    {
        Serial.println("...Success");
    }
    else
    {
        Serial.println("...Failed");
        _radioData.FailedTxCount++;
    }
   delay(250);
  } 
  }
}
