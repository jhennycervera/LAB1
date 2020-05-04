/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_LIN 80

    void ImprLinea(char c, int cant){
        for(int i=0; i<cant; i++){
            printf("%c", c);
        }
        printf("\n");
    }
    
    void AcumularDatos(double cantProd,double pU,int codInt,double *salSol1, double*ingSol1, double*cantIng1,
                        double *cantSal1,double *adqui,double*venta){
        
        if(codInt%2==0){
            (*salSol1)+=(pU*cantProd);
            (*cantSal1)+=cantProd;
            (*venta)+=pU;
        }
        else{
            (*ingSol1)+=(pU*cantProd);
            (*cantIng1)+=cantProd;
            (*adqui)+=pU;
        }
        
    }