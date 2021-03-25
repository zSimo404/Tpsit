#include <stdio.h>
#include <stdlib.h>
struct El{
    int valore;
    struct El *next;
};

int main(){
    int n;
    struct El *lista;
    struct El *l;
    lista = NULL; //fa puntare la lista a null

    do{
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0)
        {
            if (lista == NULL) //controlla che la lista non punti a nulla
            {
                //alloca dinamicamente la memoria di lista

                lista = (struct El *)malloc(sizeof(struct El));

                l = lista;
            }
            else //dopo il primo giro, quando lista non vale più null
            {
                //alloca dinamicamente la memoria del successivo

                l->next = (struct El *)malloc(sizeof(struct El));

                l = l->next;
            }
            l->valore = n;  //assegna il valore di n a l
            l->next = NULL;

                }
    } while (n >= 0);

    l = lista; //l ritorna a puntare all'inizio
    printf("numeri inseriti: ");
    while (l != NULL){
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; //assegna ad l il valore successivo di l
    }
    printf("\n");
    return 0;
}

void push(struct El lista,int valore){
    if(lista==NULL){
        lista = (struct El *)malloc(sizeof(struct El));
        lista->valore =valore;
        lista->next=NULL;
    }else{
        while(lista->next!=NULL){
            lista=lista->next;
        }
        l->next = (struct El *)malloc(sizeof(struct El));
        lista->next->valore=valore;
        lista->next->next=NULL;
        
    }
    
}
