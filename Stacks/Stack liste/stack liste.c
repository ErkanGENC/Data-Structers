#include <stdio.h>
#include <stdlib.h>

typedef struct node {

int data ;
    struct node *next;

}node;

    node *top = NULL; // head gibi d�s�n.

void push(int x){

    if(top==NULL){   // liste bosken.

        node *temp = (node *)malloc(sizeof(node));

        temp->data=x;
        temp->next=NULL;
        top=temp;

    }
// doluyken
    else{
        node *temp=(node *)malloc(sizeof(node));

        temp->data = x;

        temp->next=top;

        top=temp;

    }

}

 void pop(){

    if(top==NULL)
        printf("\nListe bos.");

    else{
         struct node *temp=top;

        top=top->next;

        free(temp);

    }

 }

    void display(){         //Yazdirma.

        if(top==NULL)
            printf("\nListe bos.");

        else{

            struct node *index=top;

            while(index!=NULL)
            {
                printf("%d ",index->data);

                index = index ->next;



            }
            printf("\n");

        }

    }




void main(){

    int secim;

    while(1){

        printf("\n1-push");
        printf("\n2-pop");

        printf("secim yapiniz.:");
        scanf("%d",&secim);

        switch(secim){

        case 1:
            printf("eklenecek sayiyi gir:");
            scanf("%d",&secim);
            push(secim);
            display();

            break;

        case 2:

            pop();
            display();
            break;



        }

    }


}
