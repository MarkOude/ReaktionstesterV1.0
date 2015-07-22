#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);
int Input = 9;
int Output = 10;
int O = OUTPUT;
int I = INPUT_PULLUP;
int start;
int time;

void init(int In, int Out){
  lcd.begin(16,2);
  lcd.print("ReaktionsTester");
  delay(1000);
  lcd.clear();
  lcd.print("Von Mark");
  lcd.setCursor(0,1);lcd.print("Oude Elberink");
  delay(1000);
  lcd.clear();
  lcd.print("V1.0");
  delay(1000);
  lcd.clear();
  pinMode(In,I);
  pinMode(Out,O);
}

void startLedTimer(int OUT){
  digitalWrite(OUT,HIGH);
  start = millis();
}
int endLedTimer(int OUT){
  digitalWrite(OUT,LOW);
  int OU = millis() - start;
   start = 0;
  return OU;
 
}
void startLCD(){
  lcd.print("Reaktionszeit:");
  lcd.setCursor(0,1);
  lcd.print("Achtung!");
}
void endLCD(int Zeit){
  lcd.print("Reaktionszeit:");
  lcd.setCursor(0,1);
  lcd.print(Zeit);
  lcd.setCursor(5,1);
  lcd.print("ms");
}
void setup() {
  init(Input,Output);
}

void loop() {
  startLCD();
  delay(random(1000,5000));
  startLedTimer(Output);
  while(digitalRead(Input) != HIGH){
    ;
  }
  time = endLedTimer(Output);
  lcd.clear();
  endLCD(time);
  delay(2000);
  lcd.clear();
}
  
