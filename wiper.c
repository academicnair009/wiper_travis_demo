/*


                         ________________
                        |                |
RAIN SENSOR------------>|                |
                        |    controller  |
                        |                |
                        |                |
ENGINE STATE----------->|________________|
printf("enter the value of i \n");
 scanf("%d",&i);
    printf("the value of i is %d  ",i);
    getch();

    system("cls");

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

struct state//tells about the state of the system
{
    float rain_int;
    int engine_stat;
    int motor;
};

void motor_speed(struct state s)//CALCULATE THE SPPED AT WHIOH SIGNAL SHOULD CHANGE
{
    float rain_100;
    rain_100=(s.rain_int/3.3)*100;
    rain_100=100-rain_100;
    printf("\r||VIPER==000000||");
    delay(rain_100*500);
    printf("\r||VIPER==111111||");
    delay(rain_100*500);
}



int main()
{
    struct state s1;

    while(1)//INFINTE LOOP
    {

    printf("Enter the value of engine (0 or 1)\n");
    scanf("%d",&s1.engine_stat);
    if(s1.rain_int*s1.engine_stat==0)
      {printf("ENTER VALUES AGAIN");
        delay(500);
        goto WOW;
        }
    printf("Enter the value of rain intensity (0 to 3.3V)\n ");
      scanf("%f",&s1.rain_int);

    printf("\nPRESS KEY ANYTIME TO CHANGE VALUES) ");

  while(1)
   {
       if(kbhit())
        break;
    motor_speed(s1);




    }
    WOW :
    system("cls");

}
}
