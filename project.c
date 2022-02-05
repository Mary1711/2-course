#include <LCD5110_Basic.h>
 
LCD5110 LCD(8,9,10,11,12);
extern uint8_t SmallFont[];

class Coins
{
private:
  float money;
public:
  void set_0();
  void add_25();
  void add_50();                      
  void disp();
};

void Coins::set_0()
{
  money = 0;  
  }

void Coins::add_25()
{
  money = money+0.25;
  delay(300);
  }

void Coins::add_50()
{
  money = money+0.5;
  delay(300);
  }

void Coins::disp()
{
  LCD.printNumF(money, 2, CENTER, 16);
}

void setup() {
  // put your setup code here, to run once:
  LCD.InitLCD();
  LCD.setFont(SmallFont);
Serial.begin(9600);
pinMode(A1, INPUT);
LCD.print("Money:", CENTER, 8);
}

void loop() {
  // put your main code here, to run repeatedly:
  Coins coins1;
  coins1.set_0();
if (analogRead(A1) >= 0 && analogRead(A1) < 3)
{
coins1.add_25();
}
if (analogRead(A1) < 9 && analogRead(A1) > 3)
{
coins1.add_50();
}
Serial.println(analogRead(A1));

coins1.disp();
delay(10);

}
