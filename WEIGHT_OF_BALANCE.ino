/*
  Project: WEIGHT OF BALANCE
  Author: Lam Nguyen
  Course: Creation & Computation (C&C)
  Date: September 2026

  Description:
  Reads analog values from three Velostat pressure sensors and maps them 
  to drive three corresponding LED channels.

  Attribution:
  Adapted from OCAD University C&C course code example (twoSensorMap.ino).
*/

// Sensor variables
int sensor1Pin = A1; // Left Wall Sensor
int sensor1Value;
int sensor1Constrained;

int sensor2Pin = A2; // Right Wall Sensor
int sensor2Value;
int sensor2Constrained;

int sensor3Pin = A3; // Floor Sensor
int sensor3Value;
int sensor3Constrained;

// Calibrated sensor ranges (3200 = minimal pressure, 0 = maximum pressure)
// Because my sensor's value decreases under physical pressure so I map 3200 to 0
int sensor1Min = 3200;
int sensor1Max = 0;

int sensor2Min = 3200;
int sensor2Max = 0;

int sensor3Min = 3200;
int sensor3Max = 0;

// LED variables
int led1Pin = 12; // Left LED Array
int led1Value;

int led2Pin = 27; // Right LED Array
int led2Value;

int led3Pin = 33; // Bottom LED Array
int led3Value;

// Brightness output range (0 = Off, 255 = Full Brightness)
int led1Min = 0;
int led1Max = 255;

int led2Min = 0;
int led2Max = 255;

int led3Min = 0;
int led3Max = 255;

void setup()
{
  Serial.begin(9600);

  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
}

void loop()
{
  // Read all three analog sensors
  sensor1Value = analogRead(sensor1Pin);
  sensor2Value = analogRead(sensor2Pin);
  sensor3Value = analogRead(sensor3Pin);

  // Keep sensor readings within limits
  sensor1Constrained = constrain(sensor1Value, sensor1Max, sensor1Min);
  sensor2Constrained = constrain(sensor2Value, sensor2Max, sensor2Min);
  sensor3Constrained = constrain(sensor3Value, sensor3Max, sensor3Min);

  // Map sensor readings to LED brightness values
  led1Value = map(sensor1Constrained, sensor1Min, sensor1Max, led1Min, led1Max);
  led2Value = map(sensor2Constrained, sensor2Min, sensor2Max, led2Min, led2Max);
  led3Value = map(sensor3Constrained, sensor3Min, sensor3Max, led3Min, led3Max);

  // Output PWM signal to drive LEDs
  analogWrite(led1Pin, led1Value);
  analogWrite(led2Pin, led2Value);
  analogWrite(led3Pin, led3Value);

  // Print values to Serial Monitor for testing and debugging
  Serial.print("Sensor 1: ");
  Serial.print(sensor1Value);
  Serial.print("   LED 1: ");
  Serial.print(led1Value);
  Serial.print("   Sensor 2: ");
  Serial.print(sensor2Value);
  Serial.print("   LED 2: ");
  Serial.print(led2Value);
  Serial.print("   Sensor 3: ");
  Serial.print(sensor3Value);
  Serial.print("   LED 3: ");
  Serial.println(led3Value);

  delay(20);
}
