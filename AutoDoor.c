#include <reg51.h>

sbit p10 = P1 ^ 0;
sbit p11 = P1 ^ 1;
sbit p12 = P1 ^ 2;
sbit p13 = P1 ^ 3;
int gateStatus = 0;
void delay1();
void delay2();
void main(void) {
  while (1) {
    delay1();
    if (p10 == 1 && gateStatus == 0) {
      p11 = 1;
      p12 = 0;
      p13 = 1;
      delay2();
      gateStatus = 1;
    } else if (p10 == 0 && gateStatus == 1) {
      p11 = 1;
      p12 = 1;
      p13 = 0;
      delay2();
      gateStatus = 0;
      p11 = 0;
    } else if (p10 == 1 && gateStatus == 1) {
      p11 = 0;
      p12 = 0;
      p13 = 0;
    }

  }
}

void delay1() {
  int i, j;
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10000; j++) {}
  }
}
void delay2() {
  int i, j, f = 0;
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 30000; j++) {}
  }
}