# relay-controlled-system
*this program was written and is maintained for an Arduino controlled system that automates a health innovation project built by Team Stark of the University of Lagos*

`IncuBed` is a cost-effective steam incubator designed for low income regions. For the automation part, the input devices (a `DHT11` temperature and humidity sensor and the `DS18B20` waterproof temperature sensor) decide the conditions of the output devices (2 12V brushless fans and a DC powered Nichrome heating element), whether `ON` or `OFF`.

The program uses basic conditional statements to supply power to corresponding pins based on the predefined threshold temperatures. Preterms need an ambient tempereature within `34-37` degrees celsius so the steam in the baby's chamber should not exceed `38` degrees. The `DHT11` senses the change in the baby's chamber while the `DS18B20` monitors the temperature in the steam chamber, the Arduino sends a `HIGH` signal to the fan pins, the heater pin receives a `LOW` signal simultaneously.

