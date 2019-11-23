/*
 * Project by Panos Koutsoumanis (aka CommandBlock6417)
 * last edited on 23/11/2019
 * for a simpler version with no selector visit 
 * 
 * Parts required:
 *   24x cables
 *   1x 100Ω resistor
 *   1x 220Ω resistor
 *   1x 1kΩ resistor
 *   1x 10kΩ resistor
 *   1x 10kΩ potentiometer
 *   1x momentary button
 *   1x piezo buzzer
 *   1x Arduino UNO (or any arduino with pwm)
 * 
 * Wiring:
 *   it is strongly advised to draw the 5V and ground lines from the UNO to the breadboard, since the pins on board are not enough for every device.
 *   lcd pin VSS to 5V
 *   lcd pin VDD to ground
 *   lcd pin Contrast (V0) through 1kΩ resistor to ground
 *   lcd pin RS to digital pin 12
 *   lcd pin Enable (E) to digital pin 11
 *   lcd pin Dataline 4 (D4) to digital pin 4
 *   lcd pin Dataline 5 (D5) to digital pin 5
 *   lcd pin Dataline 6 (D6) to digital pin 6
 *   lcd pin Dataline 7 (D7) to digital pin 7
 *   lcd pin Backlight Vin (A) through 220Ω resistor to 5V
 *   lcd pin Backlight Gnd (K) to ground
 *   Buzzer:
 *     Vin pin (+) to digital pin 9
 *     Gnd pin (-) through 100Ω resistor to ground
 *   Button: 
 *     one pin goes to 5V 
 *     the other goes to both ground through a 10kΩ resistor and digital pin 2
 *   Potentiometer:
 *     side pins to 5V and Gnd
 *     middle pin to analog pin A0
 *   
 * Code separation: 
 *       Time_bomb (this tab) contains the description of the project
 *       a_presetup tab contains variables and library setups
 *       b_setup tab contains the void setup(); code
 *       c_loop tab contains the void loop(); code
 * 
 * Description: this is a bomb ( that detonates only acoustically and is very nervewracking) 
 *              that I made on the 19-23/11/2019, when I was twelve years old.
 *              I made it by using Bodging, a technique I learned from youtuber Tom Scott. I first made the code for the buzzer, then the countdown and finally,
 *              the most tedious of them all, the "select time" part.
 *              It is not that useful but I think it's pretty cool.
 *              Here is how it works:
 *               It starts by asking you to select the time that you want to countdown from using the potentiometer, value is in seconds.
 *               Then, you press the red button and the countdown starts.
 *               Once the countdown finishes, the "bomb" emits a very annoying sound that will wrack anyone's nerves.
 * NOTE: This NOT a weapon of mass destruction. 
 *       It is only used for mental destruction, if one wants to mess with another's nerves.
 *       
 *       
 *     
*/
