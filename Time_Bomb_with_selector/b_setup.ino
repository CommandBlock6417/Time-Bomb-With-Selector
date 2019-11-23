void setup() { 
    pinMode(buzzerPin,OUTPUT);
    Serial.begin(9600);//initiates serial communications
    Serial.println(); //clears the serial monitor
    lcd.begin(16,2);  //columns and rows of the lcd display 
    do {
     timeSet(); //refreshes the values of the button and potentiometer
     lcd.clear();//clears the lcd for stability in display (removes the secondsss effect)
     lcd.setCursor(0, 0); //col, row
     lcd.print("Select time:");
     lcd.setCursor(0, 1); //col, row
     lcd.print(timeSecs);
     lcd.print(" Seconds");
    } while(buttonState == 0); 
    lcd.clear();   
    T.SetTimer(timeSecs); //sets the timer to the value of the potentiometer
    T.StartTimer();  //start the timer
    Serial.println("Countdown initiated"); //marks that the countdown has started
           
}
