
/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <Wire.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "NTnTb3ypfPHZBSMmohlywoZwpm_Nk9s9";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Cafe497";
char pass[] = "beaver2020";

byte x = 0;

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  Wire.begin(); // don't need slave address bc arduino is master 

  // write the startup code for the PCA9633
  Wire.beginTransmission(0b11000100); // PCA startup address (I think)
  Wire.write(0b10000000); // write to control register
  Wire.write(0b10000001); // MODE1
  Wire.write(0b00000101); // MODE2
  Wire.write(0b11111111); // PWM0
  Wire.write(0b10111111); // PWM1
  Wire.write(0b01111111); // PWM2
  Wire.write(0b00111111); // PWM3
  Wire.write(0b11111111); // GRPPWM
  Wire.write(0b00000000); // GRPFREQ
  Wire.endTransmission(); 
}

void loop()
{
  Blynk.run();
  // get information from the Blynk app and turn into dimmer values
  Wire.beginTransmission(4);
  Wire.write("hello");
  Wire.endTransmission();
}
