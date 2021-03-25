#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int val;
    struct nodo* next;
}Nodo;



//liste 

void freeStruttura(Nodo* playlist){  //svuota la struttura
    if(playlist->next != NULL){
        freeStruttura(playlist->next);
        free(playlist);  //dealloca la memoria 
    }
    return;
}

Nodo* accediNodo(Nodo* playlist,int numero){  //cerca l'indirizzo n esimo di una lista
    Nodo* temp = playlist;
    for(int i=0;i<numero;i++){
        temp=temp->next;
    }
    return temp;
}


//pile


int isEmpty(Nodo *struttura){    //controlla se la cella di una pila è vuota
    if(struttura == NULL) return 1;
    return 0;
}
void push(Nodo** testa,Nodo* elemento){  //carica una struttura in una pila
    if(isEmpty(*testa)){   //controlla che la pila sia vuota
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

void pushModificato(Nodo** testa,int numero){
    if(isEmpty(*testa)){
        *testa = (Nodo*) malloc(sizeof(Nodo));
        (*testa)->val= numero;
        (*testa)->next = NULL;
    }else{
        Nodo* temp = (Nodo*) malloc(sizeof(Nodo));
        temp->next = *testa;
        temp->val = numero;
        *testa = temp;
    }
}
void rigiraPila(Nodo **pila){   //inverte una pila servendosi di una pila di appoggio
    Nodo* pilaModificata = (Nodo*) malloc(sizeof(Nodo));
    while (*pila!=NULL){
        push(&pilaModificata,pop(pila));   
    }
    *pila = pilaModificata->next;
    return;    
}

//code


int isEmpty(Nodo *struttura){
    if(struttura == NULL) return 1;
    return 0;
}
void enqueue(Nodo** head,Nodo** tail,Nodo* element){
    if(isEmpty(*head)) *head = element;
    else    (*tail)->next = element;
    *tail = element;
    element->next = NULL;
}

Nodo* dequeue(Nodo** head, Nodo** tail){
    Nodo* ret = *head;

    if(isEmpty(*head)) return NULL;
    else    *head = ret->next;

    if(*head == NULL) *tail = NULL;
    return ret;
}
void giraCoda(Nodo** head,Nodo** tail){
    Nodo* pila = (Nodo*) malloc(sizeof(Nodo));
    Nodo* tempCoda = pila; 
    while (isEmpty(*head) == 0){
        pushModificato(&pila,dequeue(head,tail)->val);
    }
    *tail = tempCoda;    
    *head = pila;
}

