#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "HA04_EulerLib.h"

#define NUMOFSTATES 2

void RHS_MSD(double*rhs, double*y){ // mass spring damper

    double m = 1.0; // mass of object
    double c = 2; // feder constant
    double d = 3; // damper constant

    double x = y[0]; // position
    double v = y[1]; // speed

    
    //MY NEW CODE
    rhs[0] = v;
    rhs[1] = -(((d/m)*v)+((c/m)*x));
    //MY NEW CODE
}

void eulerSettings_MSD(simHandle* handle){

    /*num of states*/
    handle->numOfStates = NUMOFSTATES;
    
    /*right hand site*/
    handle->f = &RHS_MSD;
   
    /*reserve storage for init state vec*/
    handle->stateVecInit = malloc(sizeof(double) * handle->numOfStates);

    /*get user defined Simtime*/
    handle->simTime = -1.0;
    printf("Simtime (in s): \n");
    scanf("%lf", &(handle->simTime));
    while(handle->simTime<=0 || handle->simTime>__DBL_MAX__){
        printf("invalid input. Try again.\n");
        fflush(stdin);
        printf("Simtime (in s): \n");
        scanf("%lf", &(handle->simTime));
    }
    
    
    /*get user defined StepSize*/

    handle->stepSize = -1.0;
    printf("StepSize (in s): \n");
    scanf("%lf", &(handle->stepSize));
    while(handle->stepSize<=0 || handle->stepSize>__DBL_MAX__){
        printf("invalid input. Try again.\n");
        fflush(stdin);
        printf("StepSize (in s): \n");
        scanf("%lf", &(handle->stepSize));
    }

    if (handle->stepSize>0.1)
    {
        printf("WARNING: Stepsize is very high. Probably inaccurate results\n\n");
    }
    
    /*get init state position*/
    printf("position(t = 0): \n");
    scanf("%lf", handle->stateVecInit);

    /*get init state speed*/
    printf("speed(t = 0): \n");
    scanf("%lf", (handle->stateVecInit)+1);

    /*reserve storage for states and derivatives*/
    int storageLength = handle->numOfStates * ((int)ceil(handle->simTime/handle->stepSize));
    handle->stateVec = malloc(sizeof(double) * storageLength);
    handle->derivStateVec = malloc(sizeof(double) * storageLength);
    
    /*init states and derivatives with zero*/
    for(int i=0; i<storageLength; i++){
        handle->stateVec[i]=0;
        handle->derivStateVec[i]=0;
    }

}

void eulerForward(simHandle* handle){ // this is called only once
    int numOfStates = handle->numOfStates;
    int integratorSteps = (int)ceil(handle->simTime/handle->stepSize);

    /*write init states*/
    for(int i = 0; i < numOfStates; i++){
        handle->stateVec[i] = handle->stateVecInit[i];
    }

    for(int i = 0; i < integratorSteps; i++){
        /*get derivatives*/
        (*(handle->f))((handle->derivStateVec)+i*2, (handle->stateVec)+i*2);

        for(int j = 0; j < numOfStates; j++){
        /*euler step*/
            handle->stateVec[((i+1)*2)+j] = handle->stateVec[(i*2)+j] + (handle->stepSize * handle->derivStateVec[(i*2)+j]);
     
       }
    }
}

void showResults_MSD(simHandle* handle){
    int integratorSteps = (int)ceil(handle->simTime/handle->stepSize);

    /*print data to text file*/
    FILE *fp = fopen("simData.txt", "w");
    if(fp == NULL){
        printf("ERROR: Could not create 'simData.txt'\n");
        return;
    }

    for(int i=0; i < integratorSteps; i++){
        fprintf(fp, "%lf ", i*handle->stepSize);
        fprintf(fp, "%lf ", handle->stateVec[i*2]);
        fprintf(fp, "%lf\n", handle->stateVec[(i*2)+1]);
    }

    fclose(fp);
    
    /*call gnuplot*/
    
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

    fprintf(gnuplotPipe, "set title 'Spring-Damper-System' font ',20'\n");
    fprintf(gnuplotPipe, "set key right box\n");
    fprintf(gnuplotPipe, "set xlabel 'time in s'\n");
    
    fprintf(gnuplotPipe, "plot 'simData.txt' using 1:2 title 'position' with lines lw 3, 'simData.txt' using 1:3 title 'speed' with lines lw 3\n");
    
    fprintf(gnuplotPipe, "exit");

    fclose(gnuplotPipe);

    
}

