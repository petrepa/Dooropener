# Door opener

## Why
Wanted to eliminate the need of keys to get into my apartment, and this was the cheapest way to do so. 
Using [Home Assistant](https://github.com/petrepa/Home-AssistantConfig) to controll this, but you can use this with any MQTT service you would like.

## Build
Built this using:
* [NodeMCU](http://www.nodemcu.com/index_en.html) V3
* [Servo](https://docs.google.com/viewer?url=http://akizukidenshi.com/download/ds/towerpro/SG90.pdf)

And made a custom [3D printed case](https://www.thingiverse.com/thing:2872785) to fit over our intercom. This case is really badly designed, but it works. You could probably mount the case with some double sided tape, to avoid making holes in the wall.

### Build process
Proof of concept:
![prototype_1](https://github.com/petrepa/Dooropener/blob/master/Photos/prototype_1.jpg)

First case prototype:
![protoype_2](https://github.com/petrepa/Dooropener/blob/master/Photos/prototype_2.jpg)

Finished product:
![finised](https://github.com/petrepa/Dooropener/blob/master/Photos/finished.jpg)

## Code
The code is also really badly made, but if it works, don't fix it, right?
[Here](https://github.com/petrepa/Dooropener/blob/master/dooropener.ino) it is!
