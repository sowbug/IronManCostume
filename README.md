A quick-and-dirty Tony Stark costume. Tape inside a black t-shirt and you're all set.

![](https://sowbug.github.io/IronManCostume/img/IMG_20151025_110627.jpg)
![](https://sowbug.github.io/IronManCostume/img/IMG_20151025_110730.jpg)

[Video](https://instagram.com/p/9RliLlqNtk/?taken-by=sowbug)

Ingredients
===

* One [Adafruit NeoPixel Ring](http://www.adafruit.com/products/1463)
* One [Digispark](http://digistump.com/products/1) (pictured is a micro-USB variant)
* One 14500 Li-ion battery
* One AA battery holder
* A few short lengths of hookup wire

The 14500 battery's nominal 3.7-volt voltage means it runs from 3.7 to 4.2 volts, which is enough to power the circuit for a while.

Assembly
===

1. Solder the Digispark to the ring. The three connections are P0 => DIN, GND => GND, 5V => 5V.
2. Solder the battery holder's wires. Red to 5V, black to GND.
3. Upload the included Arduino sketch to the Digispark. If you haven't worked with the Digispark yet, [follow the setup instructions](http://digistump.com/wiki/digispark/tutorials/connecting).
4. Plug in the battery.

At this point it should work. Consider gluing the wires down to reduce the stress on the solder joints.
