/* 
 *  Frances O'Leary, 7/25/2020
 *  
 *  This file is for an initial thrust vectoring rocket motor mount test.
 *  I have no idea if those are the correct words to describe this endeavor but
 *  that's what I'm going with now. The way it works is this:
 *  
 *    You have an ESP8266.
 *    You have an SG90 servo.
 *    You have a 3D printer to prototype the gimbal.
 *    Or you MacGyver the crap out of the thing.
 *    
 *  This is my first test. It uses Blynk to obtain the acceleration
 *  of the x component of your phone to mimic the input of an accelerometer
 *  that will *hopefully* eventually be onboard a model rocket. Once I get
 *  this down, the hope is to add a y component and then move on from Blynk
 *  to a accelerometer directly linked to the ESP. All it does is rotate the servo
 *  in accordance to how you tilt your phone.
 */

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo;
char auth[] = "Your Blynk Token!";
char ssid[] = "Your WiFi SSID!";
char pass[] = "Your WiFi Password!";

/* 
 *  Connect to your wifi and instantiate the servo.
 */
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  // attaching to pin D8; connect other servo wires to GND and 3V3
  servo.attach(15);
  servo.write(0);
}

/*
 * Run it.
 */
void loop()
{
  Blynk.run();
}

/*
 * Recieve and deal with input from the accelerometer.
 * param[0] denotes we are paying attention to the x component. Values
 * vary from -1.0 to +1.0 so I scale them to values ranging from 0 to 180 degrees
 * for the servo.
 */
BLYNK_WRITE(V0)
{
  Serial.printf("%s%f\n", "Raw X Component: ", param[0].asFloat());
  if (param[0].asFloat() > 0) {
     servo.write(90 - ((param[0].asFloat()) * 90));
     Serial.printf("%s%f\n", "Converted Degrees: ", 90 - ((param[0].asFloat()) * 90));
  } else {
    servo.write((param[0].asFloat()* -1 * 90) + 90);
    Serial.printf("%s%f\n", "Converted Degrees: ", (param[0].asFloat()* -1 * 90) + 90);
  }
}
