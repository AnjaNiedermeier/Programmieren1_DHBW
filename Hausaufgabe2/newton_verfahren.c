#include <stdio.h>
#include <math.h>
#include "funktions_lib.h"

double abl_f_numerisch(double x);

int  main(){
    double x_alt;
    double x_neu;
    int i;
    int variante; //für Auswahl zwischen analytischer Ableitung und numerischer Approximation

    printf("Geben Sie an, ob die analytische Ableitung [1] oder die numerische Approximation [2] verwendet werden soll: ");
    scanf("%d", &variante);
    
    if(variante!=1 && variante!=2){//Nur 1 und 2 darf eingegeben werden
        printf("ERROR: Sie muessen 1 oder 2 eingeben!\nProgramm wird beendet.");
        return 1;
    }
    
    printf("Geben Sie einen Startwert an: ");
    scanf("%lf", &x_alt);
    
    for(i=0 ; i<100; i++){
       
       if(fabs(f(x_alt)) < pow(10, -10)){ //Abbruchkriterium 1 für |f(n_alt)| < 10^(-10)
            printf("Die approximierte NST von f(x) = %.15lf\n", x_alt);
            printf("Es wurden %d Iterationen durchgefuehrt", i);
            return 0;
        }
        
        if(variante==1){
            x_neu = x_alt - (f(x_alt)/abl_f_analytisch(x_alt)); //Iterationsvorschrift
        }
        else{
            x_neu = x_alt - (f(x_alt)/abl_f_numerisch(x_alt)); //Iterationsvorschrift
        }
        

        if(fabs(x_neu - x_alt) < pow(10, -10)){ //Abbruchkriterium 2 für Änderung des x-Werts < 10^(-10)
            printf("Die approximierte NST von f(x) = %.15lf\n", x_neu);
            printf("Es wurden %d Iterationen durchgefuehrt", i);
            return 0;
        }

        x_alt = x_neu; // x_neu wird zum nächstes x_alt Wert für die Berechnung
        
    }
    
    printf("Die approximierte NST von f(x) = %.15lf\n", x_neu);
    printf("Es wurden %d Iterationen durchgefuehrt\n", i);
    return 0;
}

double abl_f_numerisch(double x){
    double h = pow(10, -8);
    return (f(x + h) - f(x))/h;
}