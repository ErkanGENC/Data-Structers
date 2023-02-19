#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 20
struct priority_queue{

    int A[QUEUE_SIZE+1];
    int cnt;


};  

typedef struct priority_queue pqueue;

void initialize(pqueue *p){

    p->cnt= 0;

}

void insert(pqueue *p,int key){

    if(p->cnt == QUEUE_SIZE)
        printf("QUEUE IS FULL ");

    else{

        p->cnt ++ ;
        p->A[p->cnt]=key;
        int iter= p->cnt;

        while(iter !=1 && p->A[iter]<p->A[iter/2]){

            int temp=p->A[iter];
            p->A[iter]=p->A[iter/2];
            p->A[iter/2]=temp;
            iter = iter/2;

        }
    }  
}  

    void print_temp(pqueue *p){

        if(p->cnt == 0)
            printf("QUEUE İS EMPTY");

        else{

            int i=1;
            for(i;i<=p->cnt;i++)
                printf("%5d",p->A[i]);
        }    


    }

    int delete(pqueue *p){
        if(p->cnt == 0){

            printf("queue is empty");
                 return -100; 
        }
            

          else{

            int x = p->A[1];
            P->A[1]=p->A[p->cnt];
            p->cnt -- ;
            int iter = 1;

                while(2*iter< = p->cnt && p->A[iter]>p->A[2*iter] || p->A[iter] > p->A[2*iter+1]){

                    if(p->A[2*iter]<p->A[2*iter+1]){

                        swap(&p->A[iter],&p->A[2*iter]);

                        iter = 2*iter;
                    }
                        else{
                                swap(&p->A[iter],&p->A[2*iter+1]);
                                iter = 2*iter +1; 

                        }
                    


                }
          }        



    }


int main(){

pqueue p;

initialize(&p);

insert(&p,10);
insert(&p,12);
insert(&p,3);
insert(&p,18);
insert(&p,22);

print_temp(&p);

    return 0;
}