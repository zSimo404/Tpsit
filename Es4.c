#include <stdio.h>
#include <stdlib.h>
struct El{
    int valore;
    struct El *next;
};

void deAlloca(struct El* l){
    struct El* t;
    t = l;
    while (t != NULL){
        free(t);
        t = t->next;
    }   
}

int main()
{
    int n;
    struct El *lista;
    struct El *l;
    lista = NULL;

    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0)
        {
            if (lista == NULL)
            {

                lista = (struct El *)malloc(sizeof(struct El));
            }else{  
              
                l->next = (struct El *)malloc(sizeof(struct El));

                l = l->next;
            }
            l->valore = n;
            l->next = NULL; 
        }
    } while (n >= 0);

    l = lista; 
    printf("numeri inseriti: ");
    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; 
    }
    printf("\n");
    return 0;
}