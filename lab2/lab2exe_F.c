/*
 *
 * lab2exe_F.c
 * ENSF 337 - Lab 2 - Execise F
 * 
 * Completed by:    Jay Chuang
 * Lab Section:     B01
 *
 * 
 */

#include<stdio.h>

void get_user_input(double* distance, double* speed);
/*
 *  REQUIRES
 *      Reads user input, distance in km, and vehicles speed in km/h
 *  PROMISES
 *      Returns nothing
 */

void travel_time_hours_and_minutes(double distance, double speed, double *hours, double *minutes);
/*
 *  REQUIRES
 *      Receives the user inputs (distance and speed), and calculates the 
 *      travel time in hours and minutes. 
 *  PROMISES
 *      Returns nothing
 */

void display_info( double distance, double speed, double hours, double minutes);
/*
 *  REQUIRES
 *      To display the distance that was traveled, followed by the 
 *      speed of vehicle, and then the travel time in( hours and minutes)
 *  PROMISES
 *      Returns nothing
 */

int main(void)
{
    double distance, speed, hours, minutes;

    get_user_input(&distance, &speed);

    travel_time_hours_and_minutes(distance, speed, &hours, &minutes);

    display_info(distance, speed, hours, minutes);
}

void get_user_input(double *distance, double *speed)
{
    printf("Please enter the travel distance in km:");
    scanf("%lf",&*distance);

    printf("Now enter the vehicle's average speed (km/hr):"); 
    scanf("%lf",&*speed);
}

void travel_time_hours_and_minutes(double distance, double speed, double *hours, double *minutes)
{
    double time;
    double h = 0;

    time = distance/speed;

    while(time>=1)
    {
        time -= 1;
        h += 1;
    }
    
    time *= 60;

    *minutes = time;
    *hours = h;
}

void display_info( double distance, double speed, double hours, double minutes)
{
    printf("\nYou have travelled %lf km with a speed of %lf km/h in %lf hour(s) and %lf minutes(s)",distance, speed, hours, minutes);
}

