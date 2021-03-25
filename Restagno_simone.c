#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct nodo{
    char seme;
    int num;
    struct nodo* next;
}Nodo;

int isEmpty(Nodo *struttura){    //controlla se la cella di una pila è vuota
    if(struttura == NULL) return 1;
    return 0;
}

void push(Nodo** testa,Nodo* elemento){  //carica una struttura in una pila
    if(isEmpty(*testa)){    //controlla se la pila e vuota 
        *testa = elemento;
        elemento->next = NULL;
    }else{
        elemento->next = *testa;
        *testa = elemento;
    }
}
Nodo* pop(Nodo** testa){   //svuota la lista e returna i valori
    Nodo* ret = *testa;
    if(isEmpty(*testa)) return NULL;
    *testa = ret->next;
    return ret;
}

void main(){
    Nodo* head=(Nodo*)malloc(sizeof(Nodo));
    Nodo* alice=(Nodo*)malloc(sizeof(Nodo));
    Nodo* bob=(Nodo*)malloc(sizeof(Nodo));
    Nodo* element;

    for(int k=0;k<13;k++){  //carica le carte da 1 a 13 di cuori
        element=(Nodo*)malloc(sizeof(Nodo));
        element->num=k+1;
        element->seme="C";
        push(&head,element);
    }
    for(int k=0;k<13;k++){ //carica le carte da 1 a 13 di picche
        element=(Nodo*)malloc(sizeof(Nodo));
        element->num=k+1;
        element->seme="P";
        push(&head,element);
    }
    for(int k=0;k<13;k++){ //carica le carte da 1 a 13 di denari
    element=(Nodo*)malloc(sizeof(Nodo));
    element->num=k+1;
    element->seme="D";
    push(&head,element);
    }
    for(int k=0;k<13;k++){ //carica le carte da 1 a 13 di fiori
    element=(Nodo*)malloc(sizeof(Nodo));
    element->num=k+1;
    element->seme="F";
    push(&head,element);
    }

    int var=0;
    for(int k=0;k<26;k++){  //cicla la metà del mazzo perchè deve dare 2 carte per volta
        srand(time(NULL));
        var=rand()%2;   //randomizza un numero da 0 a 1
        if(var==0){
            push(&alice,pop(&head));
            push(&bob,pop(&head));
        }else{
            push(&bob,pop(&head));
            push(&alice,pop(&head));
        }   
    }

    for(int k=0;k<26;k++){

        printf("%c %d",alice->seme, alice->num);  //stampa le carte in mano ad alice
        pop(&alice);
    }

}