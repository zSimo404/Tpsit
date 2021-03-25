#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define NOME 20
#define MAX 100

typedef struct volo{   //struttura volo
    int tempo;
    float lat;
    float lon;
}Volo;

typedef struct anomalia{   //struttura anomalia
    int tempo;
    char tipo[NOME];
}Anomalia;

void calcolaLatLon(Volo *tVolo, Anomalia *tAnomalia, int dim1, int dim2){

    for(int j=0;j<dim1;j++){    //doppio for che cicla tante volte quante sono le anomalie e per ognuna di esse cicla tutta la struttura volo e cerca che il tempo sia uguale
        for(int i=0;i<dim2;i++){
            if((tAnomalia+j)->tempo==(tVolo+i)->tempo){
                printf("%f %f",(tVolo+i)->lat, (tVolo+i)->lon);

            }
        }
    }
}



int main(){
    FILE *fv;
    FILE *fa;
    Volo *tVolo;
    int k=0;
    int f=0;
    Anomalia *tAnomalia;
    char *buffer;
    buffer=malloc(MAX*sizeof(char));  //stringa di appoggio in allocazione dinamica

    if(fv=fopen("Volo_drone.csv","r")==NULL&&fa=fopen("Anomalie_drone.csv","r")==NULL){  //cpntrollo che entrambi i file esistano, questo passaggio andrebbe fatto con 2 if diverse, ho sbagliato ma non ho tempo per cambiarlo
        printf("uno dei due file, o entrambi, non esiste");
    }else{
        while(fgets(buffer,MAX,fv)){   //ciclo tutto il file per sapere quanto è lungo
            k++;
        }
        fclose(fv);
        tVolo=malloc(k*sizeof(Volo)); //allocazione dinamica memoria
        fv=fopen("Volo_drone.csv","r");
        k=0;

        while(fgets(buffer,MAX,fa)){  //ciclo tutto il file per sapere quanto è lungo 
            k++;
        }
        fclose(fa);
        tAnomalia=malloc(k*sizeof(Anomalia));   //allocazione dinamica memoria
        fa=fopen("Anomalie_drone.csv","r");
        k=0;

        while(fgets(buffer,MAX,fv)){      //carico il file sulla struttura
            (tVolo+f)->tempo=atoi(strtok(buffer,","));    //converto la stringa in intero
            (tVolo+f)->lat=atof(strtok(NULL,","));   //converto la stringa in float
            (tVolo+f)->lon=atof(strtok(NULL,"\n"));   //converto la stringa in float
            f++;
        }

        while(fgets(buffer,MAX,fa)){
            (tAnomalia+k)->tempo=atoi(strtok(buffer,","));  //converto la stringa in intero
            strcpy((tAnomalia+k)->tipo, strtok(NULL,"\n"));  //copio la stringa  
            k++;
        }

        calcolaLatLon(tVolo,tAnomalia,k,f);        
    }

}