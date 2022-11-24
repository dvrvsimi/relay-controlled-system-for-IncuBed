#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
#define RELAY_HEATER_PIN 7
#define RELAY_FAN_PIN 8
// #define RELAY_LED_PIN 7
#define TEMPERATURE_THRESHOLD_HEATER 35 // define the threshold for turning on the fan
#define TEMPERATURE_THRESHOLD_FAN 35 //define the threshold for turning on the heater

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

float Temp = 0;

void setup() {
  sensors.begin();
  Serial.begin(9600);
  pinMode(RELAY_FAN_PIN, OUTPUT); // initialize digital pin as an output
  pinMode(RELAY_HEATER_PIN, OUTPUT); // initialize digital pin as an output
  // pinMode(RELAY_LED_PIN, OUTPUT); // initialize digital pin as an output
  

}

void loop() {
  
  sensors.requestTemperatures();

  Temp = sensors.getTempCByIndex(0);

  Serial.println(Temp);  


  // Relay for putting on the FAN
  if (Temp > TEMPERATURE_THRESHOLD_FAN ) {
    Serial.println("Fan on");
    digitalWrite(RELAY_FAN_PIN, HIGH);
  }
  else {
    digitalWrite(RELAY_FAN_PIN, LOW); 
  }

  
// Relay for LED
// if (Temp > TEMPERATURE_THRESHOLD_FAN ){
//     Serial.println("ON");
//     digitalWrite(RELAY_LED_PIN, HIGH);
//   }else{
    
//     digitalWrite(RELAY_LED_PIN, LOW); 
//   }
  
  // Relay for putting on the HEATER
  if (Temp > TEMPERATURE_THRESHOLD_HEATER ) {
    digitalWrite(RELAY_HEATER_PIN, LOW); 
  }
  else {
    Serial.println("Heater on");
    digitalWrite(RELAY_HEATER_PIN, HIGH); 
  }

  delay(100);
}