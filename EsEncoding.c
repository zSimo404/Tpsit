#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 1000

void encoding(char c[]){

    int count=1;
    int k=0;
    printf("Inserire il codice da decodificare: ");
    scanf("%s",c);

    for(k=0;k<strlen(c);k++){
        if(c[k]==c[k+1]){
            count++;
        }else{ 
            if(count==1){
                printf("%c",c[k]);
                count=1;
            }else{
                printf("%d%c",count,c[k]);
                count=1;
            }
        }
    }
}


void decoding(char c[]){
     printf("Inserire il codice da codificare: ");
     scanf("%s",c);
     int var=0;
     for(int k=0;k<strlen(c);k++){
        var=c[k]-48;
        if(isNumero(c[k])==true){
            for(int j=1;j<var;j++){
                printf("%c",c[k+1]);   
            }
        }else{
            printf("%c",c[k]);
        }
     }
}


bool isNumero(char c){
    bool ris=false;
    if(c>=50 && c<=57){
        ris==true;
    }
    return ris;
}







void main(){

    int num;
    char code[LUNG];




    do{
        printf("Inserire 1 se si vuole eseguire un encoding, 0 altrimenti");
        scanf("%d",&num);
        if(num==1){
            encoding(code);
        }else if(num==0){
            decoding(code);
        }else{
            num=3;
        }
    }while(num==3);
}