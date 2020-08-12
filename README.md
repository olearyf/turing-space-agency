# Turing Space Agency (formerly hobby-rocketry)

Welcome to the Turing Space Agency repository! This is where I detail all my endeavors with 3D printed rockets and the programs that control and/or read data from them. For more on my homemade flight computer, visit the [Project Skippy](https://github.com/olearyf/project-skippy) repo.

![](https://github.com/olearyf/turing-space-agency/blob/master/images/LogoMakr_4B5QO9.png)

## 3D Printed Rockets

Below are some of my 3D printed rocket designs; most are for use with size C Estes rocket motors. Others were made for custom motors made from PVC pipe. In terms of design, I usually follow the rule of thumb that if it looks like a rocket, it will fly like a rocket. Immediate next steps include expanding on the snap fit rocket series, which is a set of modular rocket parts I am designing using annular joints that allow you to rapidly prototype and try new things. The files can be found [here](https://github.com/olearyf/turing-space-agency/tree/master/3d-files/auk-series).

![](https://github.com/olearyf/turing-space-agency/blob/master/3d-files/auk-series/xb%20auk%2012%20v5.png)

![](https://github.com/olearyf/turing-space-agency/blob/master/3d-files/auk-series/auk%201%20v3.png)

![](https://github.com/olearyf/turing-space-agency/blob/master/3d-files/auk-series/auk2%20v5.png)

![](https://github.com/olearyf/turing-space-agency/blob/master/3d-files/auk-series/auk3%20v2.png)

![](https://github.com/olearyf/turing-space-agency/blob/master/3d-files/auk-series/rocket%20snap%20fit%202%20v1.png)

![](https://github.com/olearyf/turing-space-agency/blob/master/3d-files/auk-series/rocket%20snap%20fit%203%20v2.png)

![](https://github.com/olearyf/turing-space-agency/blob/master/3d-files/auk-series/test%20nose%20cone%20v4.png)

## Remote Ignition System

![](https://github.com/olearyf/turing-space-agency/blob/master/images/IMG_5319.jpg)

### Parts
 - [arcade button](https://www.adafruit.com/product/4187)
 - 9 volt battery
 - 220 ohm resistor (or whatever resistance you need for your LED)
 - 10k ohm resistor
 - 10 microfarad capacitor
 - pnp transistor
 - slide switch
 - electric igniters or nichrome wire
 - long wire (recycled or otherwise)
 - optional: breadboard for prototyping
 - optional: 3D printer for parts found [here](https://github.com/olearyf/turing-space-agency/tree/master/remote-ignition-system) (note you’ll need some 6x3 mm magnets)
 
 ### Assembly
 
 Using the following schematic, test your circuit. From there, it is pretty quick and easy to wire up!
 
 ![](https://github.com/olearyf/turing-space-agency/blob/master/images/remote-ignition-system_bb.jpg)
 
 ![](https://github.com/olearyf/turing-space-agency/blob/master/images/IMG_5325.jpg)

## Thrust Vectoring System

Below is the current configuration of my prototype thrust vectoring system. The idea is you have a motor mount that can rotate about the X and Y axes, using servo motors. The degree to which it turns is determined by an accelerometer. Currently, I use Blynk and the accelerometer in my phone to test the set up. This code can be found [here](https://github.com/olearyf/turing-space-agency/tree/master/blynk). 3D files can be found [here](https://github.com/olearyf/turing-space-agency/tree/master/3d-files/thrust-vector-stuff).

![](https://github.com/olearyf/turing-space-agency/blob/master/images/IMG_5170.jpg)

This is a picture of the current iterations; from just a single axis to two and design improvements along the way.

![](https://github.com/olearyf/turing-space-agency/blob/master/images/IMG_5185.jpg)
