#include <stdio.h>
#include <stdlib.h>

                            // kuyrugu linked listler vasýtasýyla olusturma.
typedef struct node {

        int data;
    struct node *next;

}node;
    // front ve rear (listenin basýný ve sonun gösteren pointerlar) baþta null olarak belirtilir.

node *front = NULL;

node *rear = NULL ;



void enqueue(int x){
                        // LÝSTE BOSKEN.
   if(front == NULL){

    node *temp= (node *)malloc(sizeof(node ));

    temp->data=x;
    temp->next = NULL;

    rear = front = temp;
   }

    else{           // Liste doluyken.
        node *temp = (node * )malloc(sizeof(node ));

        temp->data = x;
        rear -> next = temp;

        rear = temp;


    }

    void dequeue(){

    if(front == NULL)
        printf("\nListe bos.");

    else{

        node *temp = front;

        front = front->next ;

        free(temp);


        }

    }

    void display(){

        if(front == NULL )
            printf("\nListeniz bos.");

        else{


        node * index = front ;

        while (index != NULL ){

            printf("%d ",index->data);

            index = index->next;
        }

            printf("\n");
        }
    }




void  main(){

    int secim;


    while(1){
            printf("\n1-enqueue");
    printf("\n2-dequeue");

    printf("\nseciminizi yapiniz.");

    scanf ("%d",&secim);


    switch(secim){

        case 1:

            printf("eklenecek sayiyi girin: ");
            scanf("%d",&secim);

            enqueue(secim);
            display();
                break ;


        case 2:

            dequeue();

            display();
            break;
    }




    }


}
