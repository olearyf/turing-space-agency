/* 
 *  Frances O'Leary, 7/26/2020
 *  
 *  This file is for an initial thrust vectoring rocket motor mount test.
 *  I have no idea if those are the correct words to describe this endeavor but
 *  that's what I'm going with now. The way it works is this:
 *  
 *    You have an ESP8266.
 *    You have 2 SG90 servos.
 *    You have a 3D printer to prototype the gimbal.
 *    Or you MacGyver the crap out of the thing.
 *    
 *  This is my second test. It uses Blynk to obtain the acceleration
 *  of the x and y component of your phone to mimic the input of an accelerometer
 *  that will *hopefully* eventually be onboard a model rocket. Once I get
 *  this down, the hope is to make a better motor mount and get an accelerometer I 
 *  can put in a model rocket. All it does is rotate the servo
 *  in accordance to how you tilt your phone.
 */

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servoX;
Servo servoY;
char auth[] = "Your Auth Token";
char ssid[] = "Your SSID";
char pass[] = "Your Password";

/* 
 *  Connect to your wifi and instantiate the servo.
 */
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  // attaching servoX to pin D8; connect other servo wires to GND and 3V3
  servoX.attach(15);
  servoX.write(90);
  // attaching servoY to pin D7, connect other servo wires to GND and 3v3
  servoY.attach(13);
  servoY.write(90);
}

/*
 * Run it.
 */
void loop()
{
  Blynk.run();
}

/*
 * Servo Control (XY)
 * 
 * Uses the accelerometer in your phone to write
 * data to the ESP.
 */
BLYNK_WRITE(V0)
{
  
  /*
   * ServoX
   * 
   * Recieve and deal with input from the accelerometer.
   * param[0] denotes we are paying attention to the x component. Values
   * vary from -1.0 to +1.0 so I scale them to values ranging from 0 to 180 degrees
   * for the servo.
   */
   
  if (param[0].asFloat() > 0) {
     servoX.write(90 - ((param[0].asFloat()) * 90));
  } else {
    servoX.write((param[0].asFloat()* -1 * 90) + 90);
  }

  /*
   * ServoY
   * 
   * Recieve and deal with input from the accelerometer.
   * param[1] denotes we are paying attention to the y component. Values
   * vary from -1.0 to +1.0 so I scale them to values ranging from 0 to 180 degrees
   * for the servo.
   */
   
  if (param[1].asFloat() > 0) {
     servoY.write(90 - ((param[1].asFloat()) * 90));
  } else {
    servoY.write(90 + (param[1].asFloat()* -1 * 90));
  }
}
