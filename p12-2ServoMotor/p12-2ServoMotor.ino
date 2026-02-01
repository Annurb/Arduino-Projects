// servo code base
#include <Servo.h>
Servo teste;
Servo teste1;
int pos;


void setup()
{
teste.attach(6);
  teste.write(0);

  teste1.attach(5);
  teste1.write(0);
  
}

void loop()
{
  for(pos = 0; pos<180;pos++){
    teste.write(pos);
    teste1.write(pos);
      delay(15);
}
  delay(1000);
  
  for( pos = 180; pos>=0;pos--){
    teste.write(pos);
    teste1.write(pos);
   delay(15);             
  }
  delay(1000);

}