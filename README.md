#rgb-matrix-Xcore
---

This is a quick and dirty piece of code to familiarise myself with the Xmos Xcore architecture on the StartKit development board. I am completely new to this chip architecture, so I've not made use of any of the key features such as parallelising tasks.


### Hardware
* 32x32 pixel RGB matrix panel
	* There is no official documentation for this panel that I could find.
	* 1/16 scan line, meaning 1/16th of the panel can be controlled at a time (i.e. 2 rows at a time).
		* As pixel data is shifted in to each row serially, there are 6 control signals
			* R1,G1,B1
				* Pixel data for row N [0..15]
			* R2,G2,B2
				* Pixel data for row N + 16 [16..31]
			* Requires 32 (panel width) clocks to shift a whole row of data in
			* To select the desired row, signals A,B,C,D form a 4 bit number [0..15]
				* The panel has a sort of safeguard, where it will only allow the display to be enabled if the last bit (D) is changing (this represents a steady count)
				* This is an attempt to prevent burn-in/damage if the controlling system hangs
		* When a row has been shifted in, produce a pulse on the LAT/STB (latch/strobe) line to "lock in" the row of shifted pixels for output to the LED drivers.
		* Asserting OE (Output Enable) turns the LED drivers on
			* OE appears to be an *active low* signal (asserted = 0)
			
			
	* There is no built in PWM (Pulse-Width Modulation)
		* To achieve a mix of colours, a bit-plane technique must be used and the display refreshed constantly to make the effect work.
		* Rather than implementing PWM in software, BCM (Binary Coded Modulation) is employed
			* See [this excellent explanation](http://www.batsocks.co.uk/readme/art_bcm_1.htm) for more info.
			* The current implementation of this appears broken in the code though
			
* Xmos StartKit
	* Architecture seems really cool and very capable
	* I'm definitely not making use of the architectures abilities, namely the multi-thread nature of parallelism the chip supports
		* Suggestions on how I should improve the code **very** welcome.
		
		
### Attributions

Portions of the code that I threw together quickly are sourced from other projects, namely:
* [32x32 pixels RGB leds matrix driver code for Arduino / AVR](https://github.com/skywodd/RGB_Matrix_Arduino_AVR) by @skywodd
* [Adafruit Arduino library for 16x32 panel](https://github.com/adafruit/RGB-matrix-Panel) by @adafruit