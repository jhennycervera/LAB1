/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Jhenny Cervera Vargas(20182841)
 *
 * Created on 4 de mayo de 2020, 10:19
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_LIN 80

#include "FuncAux.h"

/*
 *  int solo llega hasta 10 digitos-- utilizar long int
 */
int main(int argc, char** argv) {
    
    int ddT, mmT, aaT, fechaT;
    int alm1,alm2;
    
    scanf("%d/%d/%d", &ddT, &mmT, &aaT);
    scanf("%d %d", &alm1,&alm2);
    fechaT=ddT + mmT*100 + aaT*10000;
    
    double cantProd, pU, cantIng1=0, cantSal1=0,cantIng2=0, cantSal2=0, ingSol1=0, ingSol2=0,salSol1=0,salSol2=0;
    double adqui, venta, promAdq,promVen, TotNeto1, TotNeto2;
    int dd, mm, aa, codInt, codProd, codAlm, fecha, contProm=0, prodAnt, flag=0;
    int pd,pm,pa,um,ua,ud, fechaMayor=0,fechaMenor=999999999;
    double netoSol1,netocant1,netoSol2,netocant2, adqui1=0,adqui2=0,venta1=0, venta2=0;
   
    
    
    while(1){
        if(flag==0){
            printf("ALMACENES TP2020\n");
            ImprLinea('=', MAX_LIN);
        }        
        scanf("%3d%4d%4d %lf %lf %d/%d/%d", &codInt, &codProd, &codAlm, &cantProd,&pU,&dd, &mm, 
                                            &aa);
/*
        if(feof(stdin)) break;  ACÁ SE DETIENE Y NO PROCESA LOS DATOS
*/
        fecha=aa*10000 + mm*100 + dd;
        if(fecha>fechaT && (codAlm==alm1 || codAlm==alm2)){
            if(flag>0){
                if(prodAnt!=codProd){
               
                pa=fechaMenor/10000;
                fechaMenor%=10000;
                pm=fechaMenor/100;
                pd=fechaMenor%100;
                
                ua=fechaMayor/10000;
                fechaMayor%=10000;
                um=fechaMayor/100;
                ud=fechaMayor%100;
                
                netoSol1=ingSol1-salSol1;
                netocant1=cantIng1-cantIng2;
                netoSol2=ingSol2-salSol2;
                netocant2=cantSal1-cantSal2;
                
                promAdq=(adqui1+adqui2)/contProm;
                promVen=(venta1+venta2)/contProm;
                
                printf("PRODUCTO: %02d  Fecha de tope %d/%d/%d\n",prodAnt, ddT,mmT,aaT);  
                printf("ALMACEN: %02d   Total   Ingresos        Total   Salidas         Total     Neto\n",alm1);
                printf("             %.2lf     S/.%.2lf          %.2lf   S/.%.2lf         %.2lf   S/.%.2lf\n",cantIng1,ingSol1,cantSal1,salSol1, netocant1,netoSol1 );
                printf("ALMACEN: %02d   Total   Ingresos        Total   Salidas         Total     Neto\n", alm2);
                printf("              %.2lf    S/.%.2lf         %.2lf   S/.%.2lf          %.2lf   S/.%.2lf\n",cantIng2,ingSol2,cantSal2,salSol2, netocant2,netoSol2 );
                printf("precio unitario de adquisicion:S/. %lf\n",promAdq);
                printf("precio unitario de venta:S/. %lf\n",promVen);
                printf("Primer registro %d/%d/%d\n", pd,pm,pa);
                printf("ultimo registro %d/%d/%d\n", ud,um,ua);
                ImprLinea('-', MAX_LIN);
                contProm=salSol1=ingSol1=cantIng1=cantSal1=salSol2=ingSol2=cantIng2=cantSal2=adqui2=adqui1=venta1=venta2=0;                
                fechaMayor=0,fechaMenor=999999999;
                }
            }
            
            if(codAlm==alm1){
                AcumularDatos(cantProd,pU,codInt,&salSol1,&ingSol1, &cantIng1,
                        &cantSal1,&adqui1,&venta1);
                contProm++;
            }
            if(codAlm==alm2){
                AcumularDatos(cantProd,pU,codInt,&salSol2,&ingSol2, &cantIng2,
                        &cantSal2,&adqui2,&venta2);
                contProm++;
            }
            if(fecha>fechaMayor)
                fechaMayor=fecha;
            if(fecha<fechaMenor)
                fechaMenor=fecha; 
            
            prodAnt=codProd;
            flag++;
        }
    if(feof(stdin));
    }
    
    return (EXIT_SUCCESS);
}



