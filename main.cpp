#include "mbed.h"
#include "MOTOR_DRIVER.h"

BusOut LED(PA_12,PB_6,PB_7,PF_0,PF_1);
PwmOut servo1(PA_8);
PwmOut buz(PA_4);

int i;

int main() {
  servo1.period_ms(20);

  int l = 0b00001;
  while(1) {
    servo1.pulsewidth_us(1500);
    buz = 0;
    int l = 0b00001;
    for(i = 0; i<=5; i++){
      LED = l;
      wait(0.5);
      l = l << 1;    
    }
    
    //m(0.5,0.5);
    buz = 1;
    servo1.pulsewidth_us(2000);
    wait(1);
    //m(-0.5,-0.5);
    buz = 0;
    servo1.pulsewidth_us(1000);
    wait(1);  
  }
}