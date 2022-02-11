#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "HA04_EulerLib.h"

#define NUMOFSTATES 2

void RHS_MSD(double*rhs, double*y){ // mass spring damper

    double m = 1.0; // mass of object
    double c = 5; // feder constant
    double d = 0.25; // damper constant

    double x = y[0]; // position
    double v = y[1]; // speed

    
    //MY NEW CODE
    rhs[0] = v;
    rhs[1] = -(((d/m)*v)+((c/m)*x));
    //MY NEW CODE
}

void eulerSettings_MSD(simHandle* handle){

    /*num of states*/

    /* YOUR CODE HERE */
    /* ---------------*/
    
    /*right hand site*/
    
    /* YOUR CODE HERE */
    /* ---------------*/
    
    /*reserve storage for init state vec*/
    
    /* YOUR CODE HERE */
    /* ---------------*/
    
    /*get user defined Simtime*/
    printf("Simtime (in s): \n");

    /* YOUR CODE HERE */
    /* ---------------*/

    /*get user defined StepSize*/
    printf("StepSize (in s): \n");

    /* YOUR CODE HERE */
    /* ---------------*/

    /*get init state position*/
    printf("position(t = 0): \n");

    /* YOUR CODE HERE */
    /* ---------------*/

    /*get init state speed*/
    printf("speed(t = 0): \n");

    /* YOUR CODE HERE */
    /* ---------------*/

    /*reserve storage for states and derivatives*/
    
    /* YOUR CODE HERE */ //malloc mit länge double*Num of States*(int)ceil(handle->simTime/handle->stepSize)
    /* ---------------*///Um alle Lösungen abspeichern zu können
    
    /*init states and derivatives with zero*/
    
    /* YOUR CODE HERE */
    /* ---------------*/
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
        //in derivStateVec[i*2] und derivStateVec[i*2 +1] ablegen
        /* YOUR CODE HERE */
        /* ---------------*/
        for(int j = 0; j < numOfStates; j++){
        /*euler step*/

        /* YOUR CODE HERE */
        /* ---------------*/// also y = y + (h*f); für beide stellen des statevektors

       }
    }
}

void showResults_MSD(simHandle* handle){

    /*print data to text file*/

    /* YOUR CODE HERE */
    /* ---------------*/

    /*call gnuplot*/
    
    /* YOUR CODE HERE */
    /* ---------------*/

}

