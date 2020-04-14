/*
*  lab1exe_D.c
*  ENSF - Fall 2019 Lab 1, exercise D
*  Completed by: Jay Chuang
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.8   /* gravitation acceleration 9.8 m/s^2 */
#define PI 3.141592654

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

void create_table(double v)
{
    double time, distance, angle;

    printf("Angle                 t                  d \n(deg)               (sec)               (m)"); 
    
    for (angle=0; angle<=90; angle+=5) 
    {
        time = Projectile_travel_time(angle,v);
        distance = Projectile_travel_distance(angle,v);

        printf ("\n%lf           %lf           %lf", angle, time, distance);
    }
}
double Projectile_travel_time(double a, double v)
{
    double time, angle;

    angle = degree_to_radian(a);
    time = (2*v*sin(angle))/G;

    return time;
}
double Projectile_travel_distance(double a, double v)
{
    double distance, angle;

    angle = degree_to_radian(a);
    distance = (pow(v,2)/G)*sin(2*angle);

    return distance;
}
double degree_to_radian(double d)
{
    double angle;

    angle = (d*PI)/180;

    return angle;
}

int main(void)
{
    int n;
    double velocity;
    
    printf ("please enter the velocity at which the projectile is launched (m/sec): \n");
    n = scanf("%lf" ,&velocity);
    
    if(n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }
    
    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }
        create_table(velocity); 
    
    return 0;
}


/* UNCOMMENT THE CALL TO THE create_table IN THE main FUNCTION, AND COMPLETE THE PROGRAM */

