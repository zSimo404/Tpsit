#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define LUNG 25
#define N_CANZONI 11
#define SIZE 100

typedef struct canzone{
    int num;
    char nome_canzone[LUNG];
    char artista[LUNG];
}Canzone;

void visualizzaPlaylist(Canzone play[],int num){      //procedura utilizzata per stampare il vettore
    for(int k=0; k<num; k++){    //for che cicla tutta la struttura
        printf("%d - %s - %s\n",play[k].num,play[k].nome_canzone,play[k].artista);   //stampa della struttura
    }
}

bool check(int vet* vet,int cerc,int dim){       //funzione che controlla che nel random non ci siano numeri uguali 
    bool ok=false;     
    for(int k=0;k<dim;k++){       //for che cicla tutta la struttura
        if(cerc==*(vet+k)){      //confronta il vettore randomizzato con il valore generato per controllare che quel numero non ci sia già
            ok=true;           //se entra nell' if imposta la variabile booleana a true
            k=dim;             //imposta k = dim 
        }
    }
    return ok;
}

void printRand(Canzone* playlist,int dim){    //procedura che crea vettore di appoggio e carica in numeri random sopra
    int* vet;     //dichoara vettore di interi di dimensione uguale al numero delle canzoni
    vet= malloc(dim * sizeof(int));
    srand(time(NULL));   //
    for(int i=0;i<dim;i++){   //for ce cicla tutto il vettore
        do{
            *(vet+i)=rand()%(dim-1+1);    //randomizza numero 
        }while(check(vet,*(vet+1),i));    //chiamata della funzione check che serve per controllare se il numero è già stato usato
    }
    for(int j=0;j<dim;j++){    //for che cicla tutto il vettore
        printf("%d - %s - %s\n",(playlist+(*(vet+j)))->num,(playlist+(*(vet+j)))->nome_canzone,(playlist+(*(vet+j)))->artista);  //stampa la struttura utilizzando il vettore randomizzato come indice
    }
}

int main(){
    FILE *fp;   //dichiarazione file
    Canzone playlist[N_CANZONI];   //dichiarazione struttura
    char* buffer; 
    buffer= malloc(SIZE * sizeof(char));
    int k=0;   //inizializza k che servirà per sapere quante canzoni ci sono nel file

    if((fp=fopen("Canzoni.csv","r"))==NULL){   //apertura file in read (sola lettura) & controllo dell'esistenza del file
        printf("File non esistente");   //stampa se non esiste
    }else{
        while(fgets(buffer,SIZE,fp)){        //prende tutta la riga come stringa

            (playlist+k)->num=atoi(strtok(buffer,","));//trasforma i caratteri fino alla prima virgola in intero (atoi trasforma in intero)(strtok prende tutti i caratteri fino alla virgola)
            strcpy((playlist+k)->nome_canzone=strtok(NULL,",")));//prende la stringa dopo la prima virgola fino alla seconda e la carica nel titolo
            strcpy((playlist+k)->artista=strtok(NULL,"\n")));//prende l'ultima stringa fino all'invio
            k++;   //incrementa k
        }
        printRand(playlist,k);   //chiama la procedura che stampa la playlist randomizzata
    }
}