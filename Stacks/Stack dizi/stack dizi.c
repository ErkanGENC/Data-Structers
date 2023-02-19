#include <stdio.h>
#define STACK_SIZE 5

typedef struct{
    int data[STACK_SIZE];

    int top;
}stack;


void push(stack *stk,int x){

    if(stk->top == STACK_SIZE-1)
        printf("\nSTACK DOLU.");
    else{

        //stk->top++;

        stk->data[stk->top++]=x;

    }

}

void initialize(stack *stk){
    stk->top = -1;
}

void pop(stack *stk){

    if(stk->top==-1)
        printf("\nStack bos.");
    else{

        stk->top -- ;

    }

}

void yazdir(stack *stk){
    int i=0;

    for(i=0;i<stk->top+1;i++){

        printf("%d ",stk->data[i]);
    }
printf("==>TOP");

}

int peek(stack *stk){       // top 'ýn bulundugu yerin degeri.

    return stk->data[stk->top];
}


void main(){
    int secim;
    stack s;

    initialize(&s);
   while(1){



    printf("\n1-push:");
    printf("\n2-pop:");
    printf("\n3-peek:\n");

    printf("secim yapin: " );
    scanf("%d",&secim);

    switch(secim){

    case 1:
         printf("eklemek istediginiz sayiyi girin: ");
         scanf("%d",&secim);
         push(&s,secim);
            yazdir(&s);
            break;

    case 2:
        pop(&s);
        yazdir(&s);
            break;


    case 3:

        printf("\ntop degeri: %d",peek(&s));


    }

   }
}
