/************************************************************** 
* Class: CSC-615-01 Spring 2020
* Name: Jungsun Eoh
* Student ID: 918590990
* Github ID: jungsun-eoh
* Project: Traffic-Light 
* File: assignment1b.c
*
* Description: A program simulating Trafficlights. Used sysfs. 
*	to execute the program:
*		sudo assignment1b -o assignment1b
*		sudo ./assignment1b
* **************************************************************/

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define RED 17
#define YELLOW 27
#define GREEN 22

int gpio_export (char*);
int gpio_unexport (char*);


int main()
{
    int repeat = 2;

    int fdG, fdY, fdR;
    printf("Hello World from RaspberryPI");
    // Export the desired pin by writing to /sys/class/gpio/export
    gpio_export("17");
    gpio_export("27");
    gpio_export("22");

    // Set the pin to be an output by writing "out" to /sys/class/gpio/gpio24/direction
    fdG = open("/sys/class/gpio/gpio22/direction", O_WRONLY);
    if (fdG == -1) {
        perror("Unable to open /sys/class/gpio/gpio22/direction");
        exit(1);
    }
    if (write(fdG, "out", 3) != 3) {
        perror("Error writing to /sys/class/gpio/gpio22/direction");
        exit(1);
    }
    fdG = open("/sys/class/gpio/gpio22/value", O_WRONLY);
    if (fdG == -1) {
        perror("Unable to open /sys/class/gpio/gpio22/value");
        exit(1);
    }

    fdY = open("/sys/class/gpio/gpio27/direction", O_WRONLY);
    if (fdY == -1) {
        perror("Unable to open /sys/class/gpio/gpio27/direction");
        exit(1);
    }
    if (write(fdY, "out", 3) != 3) {
        perror("Error writing to /sys/class/gpio/gpio27/direction");
        exit(1);
    }
    fdY = open("/sys/class/gpio/gpio27/value", O_WRONLY);
    if (fdR == -1) {
        perror("Unable to open /sys/class/gpio/gpio27/value");
        exit(1);
    }

    fdR = open("/sys/class/gpio/gpio17/direction", O_WRONLY);
    if (fdR == -1) {
        perror("Unable to open /sys/class/gpio/gpio17/direction");
        exit(1);
    }
    if (write(fdR, "out", 3) != 3) {
        perror("Error writing to /sys/class/gpio/gpio17/direction");
        exit(1);
    }
    fdR = open("/sys/class/gpio/gpio17/value", O_WRONLY);
    if (fdR == -1) {
        perror("Unable to open /sys/class/gpio/gpio17/value");
        exit(1);
    }


    // Toggle Green LED 6 sec on, Switch to Yellow LED 1.5 sec on, and switch to Red LED 5 sec on
    do{
        if (write(fdG, "1", 1) != 1) {
            perror("Error writing to /sys/class/gpio/gpio22/value");
            exit(1);
        }
        usleep(6000000);
        if (write(fdG, "0", 1) != 1) {
            perror("Error writing to /sys/class/gpio/gpio22/value");
            exit(1);
        }

        if (write(fdY, "1", 1) != 1) {
            perror("Error writing to /sys/class/gpio/gpio27/value");
            exit(1);
        }
        usleep(1500000);
        if (write(fdY, "0", 1) != 1) {
            perror("Error writing to /sys/class/gpio/gpio27/value");
            exit(1);
        }

        if (write(fdR, "1", 1) != 1) {
            perror("Error writing to /sys/class/gpio/gpio17/value");
            exit(1);
        }
        usleep(5000000);
        if (write(fdR, "0", 1) != 1) {
            perror("Error writing to /sys/class/gpio/gpio17/value");
            exit(1);
        }
    }while (repeat--);


    // Unexport the pin by writing to /sys/class/gpio/unexport
    gpio_unexport("17");
    gpio_unexport("27");
    gpio_unexport("22");

    // And exit
    return 0;
}

int gpio_export (char* pin){
    int fd;
    fd = open("/sys/class/gpio/export", O_WRONLY);
    
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/export");
        exit(1);
    }
    if (write(fd, pin, 2) != 2) {
        perror("Error writing to /sys/class/gpio/export");
        exit(1);
    }
    close(fd);
    return 0;
}

int gpio_unexport (char* pin){
    int fd;
    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/unexport");
        exit(1);
    }
    if (write(fd, pin, 2) != 2) {
        perror("Error writing to /sys/class/gpio/unexport");
        exit(1);
    }
    close(fd);
    return 0;
}
