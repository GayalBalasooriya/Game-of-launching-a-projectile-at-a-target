 /*
Author:B.A.I.Gayal(SE/2016/010)
Purpose:Game of launching a projectile at a target
Date created:29/07/2018
Date modified:29/07/2018
*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

//prototype of functions used in the program
float angle,velocity,dist,radians;
int random_number,flag=0;
float getRadians(float angle);
float distance(float velocity,float radians);
int distanceToTarget();
void checkLimit(int random_number,float dist);

void main()
{
    if(flag==0)
        welcome();
    int rand=distanceToTarget();
    printf("Distance to target = %d\n",rand);
    velocityAngle();
    float rad=getRadians(angle);
    float dis=distance(velocity,rad);
    printf("Distance according to your data = %f\n",dis);
    checkLimit(rand,dis);
    replay();
 }

 /*
PRE-CONDITION:None
POST-CONDITION:None
PURPOSE:Display the welcome message and rules of the game
*/
void welcome()
{
    printf("WELCOME THE GAME\n");
    printf("Rules\n");
    printf("\t* Player has to enter the angle and velocity for launching the projectile.\n");
    printf("\t* If, according to the player's inputs (velocity and angle), the shot comes within 10%% of the distance to the target, the player wins the game.\n");
}

/*
PRE-CONDITION:None
POST-CONDITION:None
PURPOSE:Display a random distance to the target
*/
int distanceToTarget()
{
    int random_number;
    srand(time(NULL));
    random_number=(rand()%500)+1500;
    return random_number;
}

/*
PRE-CONDITION:None
POST-CONDITION:None
PURPOSE:Reads user Input(angle,velocity)
*/
void velocityAngle()
{
    printf("Enter the angle for the launching the projectile\n");
    scanf("%f",&angle);
    if(angle<0 || angle>90)
    {
        printf("Input is invalid\n");
        replay();
    }
    printf("Enter the velocity for the launching the projectile\n");
    scanf("%f",&velocity);
    if(velocity<0)
    {
        printf("Input is invalid\n");
        replay();
    }
}

/*
PRE-CONDITION:Value of angle(degree) entered by user
POST-CONDITION:Radian value of the angle
PURPOSE:calculates radian value from angle
*/
float getRadians(float angle)
{
    float radians;
    radians=angle*3.1415926/180.0;
    return radians;
}

/*
PRE-CONDITION:Radian value of angle & value of velocity entered by user
POST-CONDITION:float value
PURPOSE:Returns user projected distance
*/
float distance(float velocity,float radians)
{
    float dist;
    dist=velocity*velocity*sin(2*radians)/32.2;
    return dist;
}

/*
PRE-CONDITION:None
POST-CONDITION:None
PURPOSE:Checks the result of the game
*/
void checkLimit(int random_number,float dist)
{
    float limit;
    limit=random_number * 0.1;
    if(dist>random_number-limit && dist<random_number+limit )
        printf("You won the game\n");

    else
    {
        if(dist<1000)
            printf("You are too short, Try again\n");
        else if(dist>2500)
            printf("You are too far, Try again\n");
        else
            printf("You are %d from the projectile, Try again\n",abs(random_number-dist));
    }
}

/*
PRE-CONDITION:None
POST-CONDITION:None
PURPOSE:Allow user to play multiple times
*/
void replay()
{
    int choice;
    printf("If you want to play again, press 1\nIf you want to exit, press 0\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            flag=1;
            main();
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("Invalid number");
    }
}




