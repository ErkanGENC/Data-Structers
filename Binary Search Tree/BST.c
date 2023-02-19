#include <stdio.h>
#include <stdlib.h>

struct node {

    int data ;
   struct  node *left;
   struct  node *right;

};
typedef struct node node ;

node *insert(node *root,int data){  // agaca eleman ekleme.

    if(root == NULL){       // agac bos olabilir.o zaman bi root dügümü olustur.

        node *temp = (node *)malloc(sizeof(node));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
            return temp;
    }  

    else{
            if(root ->data > data){
                        root->left = insert(root->left,data);
                                    return root;
            }

            else{
                     root->right = insert(root->right,data);
                                 return root;
            }
           
    }

}
 void Traversal(node *root){

        if(root == NULL)
            return ;
        Traversal(root->left);
        printf("%d ",root->data); // inorder (kucukten buyuge sıralar).
        Traversal(root->right);


 }
    node *Search (node *root,int data){

        if(root == NULL || root->data==data)
            return root;

          if(root->data>data)
            return Search(root->left,data);     
        
        else
            return Search(root->right,data);
        
           
    }

    int min(node *root){

        while(root->left!=NULL)
                root = root->left;
        return root->data;
    }

    int recMin(node *root){         // rec olabilir mi acaba ?
            if(root==NULL)
                return 0;

        recMin(root->left);
            return root->data;
    }

    int max(node *root){

            if(root== NULL)
                return 0;
                
                    while(root->right != NULL)
                            root = root->right;

                        return root->data;
    }  


    node *delete(node *root,int data){

        node *q,*p;

        if(root == NULL)
            return NULL;
    
            if(root->data == data){

                if(root->left == root->right){      // yaprak.
                            free(root);
                                return root; // return NULL

                }   

                else{
                        if(root->left ==NULL){
                                p = root->right;
                                free(root);
                                    return p;

                        }

                            else if(root->right == NULL){

                                    p=root->left;
                                        free(root);
                                            return p;

                            }

                                else{
                                        p=q=root->right;
                                            while(p->left!=NULL)
                                                    p=p->left;
                                                
                                                p->left=root->left;
                                                    free(root);
                                                        return q;

                                }

                }
            }

            else if(root->data>data){

                 root->left = delete(root->left,data);
                    return root;

            }

                else{ 
                    
                    root->right = delete(root->right,data);

                        return root;
                }
                     
    }               

        node *copyodd(node *root,node*root2){   // Bir ikili arama ağacındaki verilerden tek olanları diğer bir BST ağacına 
                                                //kopyalayan copyOdd isimli fonksiyonu yazın.

            if(root == NULL)
                return NULL;

             else{

                if(root->data % 2 == 1)
                    root2 = insert(root2,root->data);

                    root2 = copyodd(root->left,root2);
                    root2 = copyodd(root->right,root2);

             }   
             return root2;

        }

        int path(node *root,int sum){   //Girilen bir x değeri, kökten itibaren yaprak dahil olmak üzere o yol üzerindeki verilerin
                                        // toplamına eşitse true, eşit değilse false döndüren path isimli programı kodlayınız.
            if(root==NULL)  
                return (sum=0);

            else{

                int pathSum= sum-root->data;
                    return (path(root->left,pathSum) || path(root->right,pathSum));
            }

        }






int main(){
    node * myRoot = NULL;

    myRoot = insert(myRoot,144);
    myRoot = insert(myRoot,112);
    myRoot = insert(myRoot,133);
    myRoot = insert(myRoot,12);
    myRoot = insert(myRoot,13);

    
    

    Traversal(myRoot);

    myRoot=Search(myRoot,112);
    

    return 0;
}
