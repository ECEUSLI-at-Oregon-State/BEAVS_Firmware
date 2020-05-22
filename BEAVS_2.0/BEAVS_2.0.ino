//////////////////////Pressure Sensor//////////////////////////////////////////////
#include <Wire.h>
#include "SparkFunMPL3115A2.h"

//Create an instance of the object
MPL3115A2 myPressure;
///////////////////////////SD Card/////////////////////////////////////////////////
#include <SPI.h>
#include <SD.h>

File myFile;
//////////////////////Accelerometer////////////////////////////////////////////////
int scale = 200;
boolean micro_is_5V = true; 


void setup()
{
  Wire.begin();        // Join i2c bus
  Serial.begin(9600);  // Start serial for output
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
/////////////////////////////////Pressure Sensor///////////////////////////////////
  myPressure.begin(); // Get sensor online

  // Configure the sensor
  //myPressure.setModeAltimeter(); // Measure altitude above sea level in meters
  myPressure.setModeBarometer(); // Measure pressure in Pascals from 20 to 110 kPa
  
  myPressure.setOversampleRate(7); // Set Oversample to the recommended 128
  myPressure.enableEventFlags(); // Enable all three pressure and temp event flags 
///////////////////////////////SD Card//////////////////////////////////////////////
  Serial.print("Initializing SD card...");

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  myFile = SD.open("Full.txt", FILE_WRITE);
}

void loop()
{
  if (myFile) {
    
/////////////////////////////////Pressure Sensor///////////////////////////////////
    float altitude = myPressure.readAltitude();
    Serial.print(" Altitude(m):");
    Serial.print(altitude - 25129, 2);
    myFile.print(" Altitude(m):");
    myFile.print(altitude - 25129, 2);
  
    float pressure = myPressure.readPressure();
    Serial.print(" Pressure(Pa):");
    Serial.print(pressure, 2);
    myFile.print(" Pressure(Pa):");
    myFile.print(pressure, 2);
  
    float temperature = myPressure.readTempF();
    Serial.print(" Temp(f):");
    Serial.print(temperature, 2);
    myFile.print(" Temp(f):");
    myFile.print(temperature, 2);
  
    Serial.println();
    myFile.println();
  
//////////////////////////////Accelerometer////////////////////////////////////////
  
    // Get raw accelerometer data for each axis
    int rawX = analogRead(16);
    int rawY = analogRead(15);
    int rawZ = analogRead(14);
  
    float scaledX, scaledY, scaledZ; // Scaled values for each axis
      if (micro_is_5V) // microcontroller runs off 5V
      {
        scaledX = mapf(rawX, 0, 675, -scale, scale); // 3.3/5 * 1023 =~ 675
        scaledY = mapf(rawY, 0, 675, -scale, scale); // 3.3/5 * 1023 =~ 675
        scaledZ = mapf(rawZ, 0, 675, -scale, scale); // 3.3/5 * 1023 =~ 675
      }
      else // microcontroller runs off 3.3V
      {
        scaledX = mapf(rawX, 0, 1023, -scale, scale);
        scaledY = mapf(rawY, 0, 1023, -scale, scale);
        scaledZ = mapf(rawZ, 0, 1023, -scale, scale);
      }
  
    // Print out scaled X,Y,Z accelerometer readings
    Serial.print("X: "); Serial.print(scaledX - 45.93); Serial.println(" g");
    Serial.print("Y: "); Serial.print(scaledY - 46.52); Serial.println(" g");
    Serial.print("Z: "); Serial.print(scaledZ - 45.52); Serial.println(" g");
    
    myFile.print("X: "); myFile.print(scaledX - 45.93); myFile.println(" g");
    myFile.print("Y: "); myFile.print(scaledY - 46.52); myFile.println(" g");
    myFile.print("Z: "); myFile.print(scaledZ - 45.52); myFile.println(" g");
  
    delay(200);
  }
  /*
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening BEAVS_FullScale1Test.txt");
  }
  */
}

float mapf(double val, double in_min, double in_max, double out_min, double out_max) {
    return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }
