/************************************************************** 
* Class: CSC-615-01 Spring 2020
* Name: Jungsun Eoh
* Student ID: 918590990
* Github ID: jungsun-eoh
* Project: Traffic-Light 
* File: assignment1wpi.c
*
* Description: a program simulating traffic light. used wiringPi.
*   to execute the program:
*       gcc -Wall -o assignment1wpi assignment1wpi.c -l wiringPi
*       ./assignment1wpi
* **************************************************************/


#include <stdio.h>
#include <wiringPi.h>

#define RED 0
#define YELLOW 2
#define GREEN 3

int main(void)
{
    int repeat = 3;
    printf("Hello World from RaspberryPI\n");
    wiringPiSetup();

    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(YELLOW,OUTPUT);

    do
    {
        digitalWrite (GREEN, 1);
        delay(6000);
        digitalWrite(GREEN, 0);

        digitalWrite(YELLOW, 1);
        delay(1500);
        digitalWrite(YELLOW, 0);

        digitalWrite(RED, 1);
        delay(5000);
        digitalWrite(RED, 0);
    }while(repeat--);

    return 0;
}