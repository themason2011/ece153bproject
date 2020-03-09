#include <Wire.h>
int x = 0;
void setup()
{
  Wire.begin(4);                // join i2c bus with address 0
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop()
{
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int bytes)
{
  x = Wire.read();
  Serial.println(x);
  Serial.println("Yay something was received");
//  while(1 < Wire.available()) // loop through all but the last
//  {
//    char c = Wire.read(); // receive byte as a character
//    Serial.print(c);         // print the character
//  }
//  int x = Wire.read();    // receive byte as an integer
//  Serial.println(x);         // print the integer
}

//
//void setup() {
//  // put your setup code here, to run once:
//pinMode(9,OUTPUT);
//pinMode(7,INPUT);
//Serial.begin(9600);
//}
//
//bool pin7 = 0;
//
//void loop() {
//  // put your main code here, to run repeatedly:
//pin7 = digitalRead(7);
//if(!pin7) {
//  analogWrite(9, 100);
//}
//else  {
//  analogWrite(9, 255);
//}
//delay(100);
//}
