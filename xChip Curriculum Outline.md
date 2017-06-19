## Front matter
Introduction
* What is an xChip? Where do they come from? 

xChip Glossary 
* (possibly break this up, Possibly forgoe this and put the info in the assocaited lab?)
* compilation of each chips capabilities, characteristics, and a link to the associated lab 
* Each lab's materials list should link back here.

Set Up and Install Arduino
* The software platform used to code xCHips. Install the program and drivers.

Install xChip Libraries 
* This could technically be combined with the last tutorial, but they're both a bit time consuming.

Program basics 
* Basically steal from the arduino lesson about structure syntax and troubleshooting

## Labs
> How many labs should there be? brian said ~10 D:

Lab 1: Hello World on OLED 
* Basic code structure, syntaxes
* Have them upload a code, minor modifications
* DU: How LED screen works
> OLED colors are defined by hardware. Library includes fonts, but its a pain in the ass to get to work.

Lab 2: Light Sensor on OLED 
* How does the chip work?
* output values from sensor to OLED, UVA/UVB  and visible
* DU: Logic statements 

Lab 3: Altitude/pressure over OLED
* Cool loops? Cool loops.
* intro to the SW01 and measurement vs. calculation.
* dislaying multiple readings over the LED
* DU: Loops and moving averages. How an Altimeter works

Lab 4: Temperature/Humidity over Serial 
* Serial monitor basics
* Make a video
* DU: Baud rate

Lab 5: UVA/UVB over serial monitor + OLED
* OLED "Wear sunscreen!" logic
* serial monitor, "raw" data
* DU: the spectrum. where UVA/UVB lives

Lab 6: UV and Wifi + OLED 
* This seems tricksy... Not sure about all of our capabilites... Does this need batteries?
* outside lab 
* DU: How wifi works

Lab 7: Use ALL THE CHIPS! on OLED + wifi
* Full weather station
* Dashboard
* DU: weather?

Radio lab 8
* Introduce radio over Serial
Radio lab 9
* Dashboard
Radio lab 10
* Dashboard

Lab x: Programming the LED to show different colors



Other Deeper Understanding:
(Unecessary to make the labs work, but if you're intersted here's how coding works!)
(Won't distract from the main lesson targeted at beginners)
Data Types > binary/bits/size
Bad code will still compile
I2C communication
loops
logic gates
error- sensor error, sources of error
