/*
 * test2.c:
 *      Simple test program to test the wiringPi functions
 *      PWM test
 */

#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (void)
{
  int pin ;
  int l ;
  int pwmRtr;



  printf ("Raspberry Pi wiringPi PWM test program\n") ;

  if (wiringPiSetup () == -1)
    exit (1) ;

  // int feedback = softPwmCreate (2, 50 , 100);
  // printf("the feedback is %d\n",feedback);

  // for (pin = 0 ; pin < 2 ; ++pin)
  // {

  //!! Start DC motor control
  // Right rear Wheel
  //pin definition and initialization
  int encPin = 8;
  int in5Pin = 9;
  int in6Pin = 7;
  pinMode (encPin, OUTPUT);
  pinMode (in5Pin, OUTPUT);
  pinMode (in6Pin, OUTPUT);
  digitalWrite (encPin, LOW);
  digitalWrite (in5Pin, LOW);
  digitalWrite (in6Pin, LOW);
  // Left rear Wheel
  //pin definition and initialization
  int endPin = 6;
  int in8Pin = 11;
  int in7Pin = 10;
  pinMode (endPin, OUTPUT);
  pinMode (in8Pin, OUTPUT);
  pinMode (in7Pin, OUTPUT);
  digitalWrite (endPin, LOW);
  digitalWrite (in8Pin, LOW);
  digitalWrite (in7Pin, LOW);
  // 2nd Wheel
  //pin definition and initialization
  int enbPin = 12;
  int in3Pin = 13;
  int in4Pin = 14;
  pinMode (enbPin, OUTPUT);
  pinMode (in3Pin, OUTPUT);
  pinMode (in4Pin, OUTPUT);
  digitalWrite (enbPin, LOW);
  digitalWrite (in3Pin, LOW);
  digitalWrite (in4Pin, LOW);

  // 1st Wheel
  //pin definition and initialization
  int enaPin = 0;
  int in1Pin = 2;
  int in2Pin = 3;
  pinMode (enaPin, OUTPUT);
  pinMode (in1Pin, OUTPUT);
  pinMode (in2Pin, OUTPUT);
  digitalWrite (enaPin, LOW);
  digitalWrite (in1Pin, LOW);
  digitalWrite (in2Pin, LOW);

  printf("Car will start in 2 seconds!\n");
  delay(2000);

  //pwm pin initialization
  int pwmRtrD = softPwmCreate(endPin, 0, 1000);
  if (pwmRtrD != 0)
  {
    printf("pin %d pwm initialization failed, failure code %d \n",endPin ,pwmRtrD );
  }
  int pwmRtrC = softPwmCreate(encPin, 0, 1000);
  if (pwmRtrC != 0)
  {
    printf("pin %d pwm initialization failed, failure code %d \n",encPin ,pwmRtrC );
  }
  int pwmRtrB = softPwmCreate(enbPin, 0, 1000);
  if (pwmRtrB != 0)
  {
    printf("pin %d pwm initialization failed, failure code %d \n",enbPin ,pwmRtrB );
  }
  int pwmRtrA = softPwmCreate(enaPin, 0, 1000);
  if (pwmRtrA != 0)
  {
    printf("pin %d pwm initialization failed, failure code %d \n",enaPin ,pwmRtrA );
  }

  //!! Start part for pwm servo motor
    pin = 1;
    printf("pin number is %d\n",pin );
    pinMode (pin, OUTPUT);
    digitalWrite (pin, LOW);
    pwmRtr = softPwmCreate(pin, 0, 300);
    if (pwmRtr != 0)
    {
      printf("pin %d pwm initialization failed, failure code %d \n",pin ,pwmRtr );
    }





  //drive the wheel
  for (int i = 1; i <6; i++)
  {
      printf("wheel test!\n");
      digitalWrite (in7Pin, HIGH);
      digitalWrite (in6Pin, HIGH);
      digitalWrite (in1Pin, HIGH);
      digitalWrite (in3Pin, HIGH);
      softPwmWrite(endPin, 200*i);
      softPwmWrite(encPin, 200*i);
      softPwmWrite(enaPin, 200*i);
      softPwmWrite(enbPin, 200*i);
      delay(3000);
        //  for (int j = 0; j < 300; j++)
        // {
        //   printf("current pwm value is %d\n",j);
        //   softPwmWrite(pin, j);
        //   delay(10);
        // }

        // for (int j = 300; j > 0; j--)
        // {
        //   printf("current pwm value is %d\n",j);
        //   softPwmWrite(pin, j);
        //   delay(10);
        // } 

  }

  digitalWrite (in8Pin, LOW);
  digitalWrite (in5Pin, LOW);
  digitalWrite (in2Pin, LOW);
  // digitalWrite (in3Pin, LOW);




  // for(;;)
  // {
  //       for (int i = 0; i < 300; i++)
  //     {
  //       printf("current pwm value is %d\n",i);
  //       softPwmWrite(pin, i);
  //       delay(10);
  //     }

  //     for (int i = 300; i > 0; i--)
  //     {
  //       printf("current pwm value is %d\n",i);
  //       softPwmWrite(pin, i);
  //       delay(10);
  //     }
  // }

  // }

  // for (int i=0; i < 1000; i++)
  // {
  //   digitalWrite(4, HIGH);
  //   printf("now the level is HIGH\n");
  //   l = 1;
  //   delay(i);
  //   digitalWrite(4, LOW);
  //   printf("now the level is LOW\n");
  //   delay(1000-i);

  // }
  

  

  // pinMode (1, PWM_OUTPUT) ;

  // for (;;)
  // {
  //   // for (l = 0 ; l < 1024 ; ++l)
  //   // {
  //   //   pwmWrite (1, l) ;
  //   //   delay (1) ;
  //   // }

  //   // for (l = 1023 ; l >= 0 ; --l)
  //   // {
  //   //   pwmWrite (1, l) ;
  //   //   delay (1) ;
  //   // }
  //   pwmWrite(1,110);
  //   printf("current l is 110\n");
  //   delay(5000);

  //   pwmWrite(1,60);
  //   printf("current l is 60\n");
  //   delay(5000);

  // }

  return 0 ;
}