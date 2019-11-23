#include <LiquidCrystal.h> // LiquidCrystal can be found on Tools > manage libraries
#include <CountUpDownTimer.h> //CountUpDownTimer by AndrewMascolo can be found on his github page: https://github.com/AndrewMascolo/CountUpDownTimer
const int buzzerPin = 9; //assigns the pin the buzzer is in
const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7; //assigns the appropriate pins to names for the lcd pins
const int knobPin = A0; //assigns the analog pin the potentiometer is in
const int buttonPin = 2; //assigns the pin the start button is in
int buzzFreq = 100; //initial buzzer frequency for the siren sequence
int buttonState = 0; //creates a new variable where the state of the button will be stored
int timeSecs; //creates a new variable where the value of the potentiometer is converted to seconds
float knobReading; //creates a decimal point variable for the potentiometers value to be stored
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //lcd register select, enable and data pins 4-7 are used by the lcd
CountUpDownTimer T(DOWN); //makes a new timer named "T" and sets it to countdown
void timeSet(){
  buttonState = digitalRead(buttonPin);
  knobReading = analogRead(knobPin);
  timeSecs = ((knobReading * 600) / 1010); //converts the input of the potentiometer (~0-1023) to ~0-600 seconds
  Serial.print("time is set to: ");
  Serial.print(timeSecs);
  Serial.println(" seconds");


}
void beepity(){ //does the beeping sound every second
      tone(buzzerPin, 3000);
      delay(100);
      noTone(buzzerPin);
      delay(900);
    }
void siren(){ //does the siren sound after the time is up
  do{ //increments the frequency
   buzzFreq = buzzFreq + 20;
   tone(buzzerPin,buzzFreq);
   Serial.println(buzzFreq);
   Serial.print("frequency:");
   delay(1);
  } while (buzzFreq < 3500);

  do{ //decrements the frequency
   buzzFreq = buzzFreq - 20;
   tone(buzzerPin,buzzFreq);
   Serial.println(buzzFreq);
   Serial.print("frequency:");
   delay(1);
  } while (buzzFreq > 100);
}
