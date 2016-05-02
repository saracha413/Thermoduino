/****************************************************
Sara Vannah and Jenny Gubner
//This code uses analog data from a thermistor to control a servo, which rings a bell, and two LEDs (red and blue) which light up...
//... depending on the thermistor readings. This code was written for a temperature sensing and notification device as a project...
//... in ENGR 160 at Wellesley College in Spring 2016, for a person with a spinal chord injury, who is unable...
... to notice changes in his body temperature in his lower extremities.

  Parts of this code were adapted from an example for the Adafruit VS1053 Codec Breakout

  Designed specifically to work with the 0K Precision Epoxy Thermistor - 3950 NTC 
  ----> https://www.adafruit.com/products/372

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution

  Specific code was found at: https://learn.adafruit.com/thermistor/using-a-thermistor
 ****************************************************/


//servo declarations
#include <Servo.h>
Servo myservo; // create servo object to control a servo
int pos = 0; //variable to store the servo position
int bellpos = 85; //position of bell

//thermosistor declarations
//value of resisitor in series, in Ohms
#define SERIESRESISTOR  10000
//pin that connects to thermistor
#define THERMISTORPIN A0

//resistance values were calculated using ankle temperature readinds from subjects...
//... with and without spinal chord injuries
//demo values are experimentally found, so that temperature notifactions can be demonstrated...
//...at toom temp using only body heat
int maxRes = 9758;  //demo value: 8300; //dangerously hot
int minRes = 7996; //demo value: 7500; //slightly cooler than body temperature
int hiRes = 9458; //demo value: 8200; //resistance is high, getting too cold
int loRes =  8296; //demo value: 8000; //resistance is low, getting too hot


//LED declarations
const int Pin_LED_red  = 13; //positions for blue and red LED
const int Pin_LED_blue = 12;
int led_Value_red = 0; //initializes red and blue LEDs to be off
int led_Value_blue = 0;

void setup() {
  Serial.begin(9600); //set baud rate to 9600

  pinMode(Pin_LED_red, OUTPUT); //treat LED as output
  pinMode(Pin_LED_blue, OUTPUT); 
  
  myservo.attach(9); // ataches the servo on pin 9 to the servo object

}

void loop() {
  
  float reading;

  reading = analogRead(THERMISTORPIN); //interprets analog thermistor reading


  // convert the read in value to resistance
  reading = (1023 / reading) - 1;
  reading = SERIESRESISTOR / reading;
  Serial.print("Thermistor resistance ");
  Serial.println(reading);

  //resistance higher than ideal range
  if(reading > hiRes){
        
        led_Value_blue  = HIGH; //a little cold, blue LED should be on
        digitalWrite(Pin_LED_blue, 1);
        Serial.println("a little cold, blue LED should be on");
  }

  //resistance lower than ideal range
  if(reading < loRes){
    led_Value_red = HIGH; //a little hot, red LED should be on
    digitalWrite(Pin_LED_red, 1);
    Serial.println("a little warm, red LED should be on");
  }


  digitalWrite(Pin_LED_red, led_Value_red); //turn LEDs on or off
  digitalWrite(Pin_LED_blue, led_Value_blue);

  
  //resistance  outside of min or max range
  if(reading > maxRes || reading < minRes){ 
    Serial.println("in danger range, servo should turn");
    bellRing(); //calls function to ring bell
    Serial.println("rung");
    delay(3600000); //wait 1 hour (3600000ms) before evaluating temperature again
  }
  led_Value_red = 0;
  led_Value_blue = 0;
  delay(1000);
}

  
//function to ring bell in distinct pattern with three chimes
void bellRing(){
    myservo.write(bellpos); //move servo to ring bell
    delay(300);
    myservo.write(pos);
    delay(300); // pause before ringing again
    myservo.write(bellpos);
    delay(300); 
    myservo.write(pos);
    delay(300);
    myservo.write(bellpos);
    delay(300);
    myservo.write(pos); 
}



