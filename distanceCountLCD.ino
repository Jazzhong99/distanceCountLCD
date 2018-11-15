#include<LiquidCrystal.h>  //Import tle library file into this program to use the lcd function
#define PI 3.142
int count1;
volatile int count = 0;  //Integer num of count
volatile float distance = 0;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  //RS,ENABLE,D4,D5,D6,D7

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);  //LCD screen display of 16  column  and 2  row (Full screen used)
  Serial.begin(9600);
  lcd.clear();  //Clears the LCD screen and positions the cursor in the upper-left corner
  attachInterrupt(3, pin_ISR, CHANGE);   // response to any changes in the interrupt pin's value
  Serial.println("READY");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("INPUT COMES IN");
  if (Serial.available() > 0) {
    count1 = Serial.read();
    pin_ISR();

  }
  Serial.println("State 1");
  lcd.setCursor(0, 0);  //Starts or begin at 0 column ,0 row
  lcd.print("Count:");
  lcd.setCursor(7, 0);
  count = Serial.parseInt(); //Reads only integer number, other than int will = 0, wont counted
  lcd.print(count);  //Print out the count , counted by the count++
  Serial.println("State 2");
  lcd.setCursor(0, 1);  //At column 0, row 2, become lcd counts from 0,1,2,3...
  lcd.print("Distance:");
  lcd.setCursor(10, 1);  //The position of distance you want it to display at
  distance = Serial.parseInt();
  lcd.print(distance);
  Serial.println("DONE");
}

void pin_ISR() {
  count++;  //If there is INPUT, count++ (Encoder)
  distance = ((count / 35) * (2 * PI * 0.035)); //Explaination inside ipad note
}
