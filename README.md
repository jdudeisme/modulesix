# Module 6 Task 1 - Distributed Networks 

## Members  
Carlos Guanche, Jordan Smith, Cynthia Vu, TanTan Wang  

## Sensors and Setup  
As a four person team, we used four ESP32 devices to create four distinct sensors.  

- Cabinet Sensor  
By using a modified button, we are able to detect when a specific cabinet in the kitchen is open, and when it is closed.  

- Fridge Sensor  
By transforming the handle of the refridgerator into a giant capacitive touch surface by covering it with aluminum foil and wiring it to an ESP32, we can know when the fridge door is being interacted with.  

- Inductor Coil  
By creating an inductor coil wired to an ESP32, we can place it near the microwave's power cord to know when the microwave is being used.  

- Door Sensor  
By creating an sensor mounted above the door next to the kitchen with two ultrasonic sensors and an ESP32, we are able to tell when someone either enters or exits the room through the stairwell. 

## Setup 

Followed this [link](https://gitlab.com/painlessMesh/painlessMesh) to setup a mesh for the ESP32. The dependecies needed are: 

* ArduinoJson
* TaskScheduler
* AsyncTCP

ArduinoJSon and TaskScheduler can be found in the Arduino library manager; however, to get [AsyncTCP](https://github.com/me-no-dev/AsyncTCP), you have to download the source files and manually add it to the Arduino library. 
  
 


