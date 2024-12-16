

//Call libraries needed to run code
#include<Wire.h>
#include <SparkFun_MicroPressure.h>

// Constants
SparkFun_MicroPressure mpr; // Use default values with reset and EOC pins unused
//SparkFun_MicroPressure mpr(EOC_PIN, RST_PIN, MIN_PSI, MAX_PSI);
const int dirPin = 2; //stepper direction pin
const int stepPin = 3; //stepper step pin
const int UpPin = 4; // Up button pin 
const int DownPin = 5; // Down button pin
const int potPin = A0; //Potentiometer trigger pin
const int stepsPerRevolution = 200; //Steps of Motor per revolution

// Variables

int setPressure = 85; //Target pressure change each time
int currentPressue = 0; //Current pressure read by sensor

void setup() {
  //Initialize components
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(UpPin, INPUT);
  pinMode(DownPin, INPUT);
  //Initalized serial communiction
  Serial.begin(9600);
  // Initalized I2C communication
  Wire.begin(); 
  //lets user know if pressure senosr is working properly
  if(!mpr.begin())
  {
   Serial.write("Cannot connect to MicroPressure sensor.");
   while(1);
  }
}

void loop() {
  //Prints pressure and stores it as a variable
  Serial.println(mpr.readPressure(KPA));
  float pressure = mpr.readPressure(KPA);
  //Serial.println(analogRead(potPin));
  
int  potVal = analogRead(potPin);
  if (potVal == 1023) {
    if ((pressure) > setPressure) 
    {   digitalWrite(dirPin, LOW);
        for(int y =0; y <1; y++)
         {digitalWrite(stepPin, HIGH);
          delayMicroseconds(4000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(4000);}
    }
 
  else if ((pressure) < setPressure)
   {    digitalWrite(dirPin, HIGH);
        for(int y =0; y <1; y++)
         {digitalWrite(stepPin, HIGH);
          delayMicroseconds(4000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(4000);}
   }
else if ((pressure) == setPressure)
 {};  
delay(10);}
else {
 
//Serial.println(digitalRead(UpPin));
if (digitalRead(UpPin) == HIGH)
{  digitalWrite(dirPin, LOW);
   for(int y =0; y <2; y++)
   {digitalWrite(stepPin, HIGH);
    delayMicroseconds(4000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(4000);}
}
else if (digitalRead(DownPin) == HIGH)

  {  digitalWrite(dirPin, HIGH);
   for(int y =0; y <2; y++)
   {digitalWrite(stepPin, HIGH);
    delayMicroseconds(4000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(4000);}}

else
{};


}

delay(10);
}
