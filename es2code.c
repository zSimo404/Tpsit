#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct El{
    int val;
    struct El* next;
};

void push(struct El** pila, struct El* element){
	if (&pila==NULL){
		*pila = element;
		element->next = NULL;
	}else{
		element->next = *pila;
		*pila = element;
	}
}

struct El* pop(struct El** pila){
	struct El *ret = *pila;
	if(&pila==NULL){
		return NULL;
	}else{
		*pila = ret->next;
	}
	return ret;
}

int is_empty(struct El* head){
    if (head == NULL) return 1;
    else return 0;
}

void enqueue(struct El **head, struct El **tail, struct El *element){

    if(is_empty(*head)){
        *head = element;
    }else{
        (*tail)->next=element;
    }
    *tail = element;
    element->next=NULL;    
}

struct El * dequeue(struct El **head, struct El **tail){
    struct El *ret = *head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    if (*head==NULL){
        *tail = NULL;
    }
    return ret;
}

void stampaCoda(struct El** head, struct El** tail){

    struct El* valore = (struct El*) malloc(sizeof(struct El));
    valore = dequeue(head, tail);

    while (valore != NULL) {
        printf("%d\n",valore->val);
        valore = dequeue(head, tail);
    }
    free(valore);
}

int main(){
    struct El* head=NULL;
    struct El* tail=NULL;
    struct El* element=NULL;
    struct El* stack=NULL;
    char risp;
    do{
        element=(struct El*)malloc(sizeof(struct El));
        printf("Inserisci un intero: ");
        fflush(stdin);
        scanf("%d",&element->val);
        enqueue(&head,&tail,element);
        printf("Vuoi inserire ancora? Y=SI N=NO");
        fflush(stdin);
        scanf("%c",&risp);
    }while(risp=='y' || risp=='Y');
    
    while(!is_empty(head)){
        element=dequeue(&head,&tail);
        push(&stack,element);
    }

    while(!is_empty(stack)){
        element=pop(&stack);
        enqueue(&head,&tail,element);
    }

    stampaCoda(&head,&tail);
    return 0;
}