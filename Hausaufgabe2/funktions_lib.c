#include <stdio.h>
#include <math.h>

double f(double x){
    return pow((x-3) , 2); //f(x)=(x-3)^2 
}

double abl_f_analytisch(double x){
    return (2 * (x-3)); //f'(x)=2*(x-3)
}

