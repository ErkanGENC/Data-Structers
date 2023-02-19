#include <stdlib.h>
#include <stdio.h>


struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;

};

typedef struct node AVLTREE;

int maxValue(int x,int y)
{
    return x>=y?x:y; 
}

AVLTREE *newNode(int data)
{
    AVLTREE *p = (AVLTREE*)malloc(sizeof(AVLTREE));
    p->data = data;
    p->height = 0;
    p->left = p->right = NULL;
    return p;
}

int height(AVLTREE *root)
{
    if (root == NULL)
        return 1;
    else
    {
        int rHeight,lHeight = 0;
        lHeight = height(root->left);
        rHeight = height(root->right);
        if (lHeight > rHeight)
            return lHeight+1;
        else
            return rHeight+1;
    }
}

AVLTREE *leftRotate(AVLTREE *z)
{
    AVLTREE *temp = z->right;
    z->right = temp->left;
    temp->left = z;
    z->height = maxValue(height(z->left),height(z->right))+1;
    temp->height = maxValue(height(temp->left),height(temp->right))+1;
    return temp;
}

AVLTREE *rightRotate(AVLTREE *z)
{
    AVLTREE *temp = z->left;
    z->left = temp->right;
    temp->right = z;
    
    z->height = maxValue(height(z->left),height(z->right))+1;
    temp->height = maxValue(height(temp->left),height(temp->right))+1;
    return temp;
}

void inOrder(AVLTREE *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d\t",root->data);
        inOrder(root->right);
    }
}

AVLTREE *leftRightRotate(AVLTREE *root)
{
    root->left = leftRotate(root->left);
    return rightRotate(root);
}

AVLTREE *rightLeftRotate(AVLTREE *root)
{
    root->right = rightRotate(root->right);
    return leftRotate(root);
}

AVLTREE *insertToAvl(AVLTREE *root,int data)
{
    if (root != NULL)
    {
        if (data < root->data)
            root->left = insertToAvl(root->left,data);
        else
            root->right = insertToAvl(root->right,data);
        
        root->height = maxValue(height(root->left),height(root->right));
        
        if ((height(root->left)-height(root->right)) > 1 && data < root->left->data)
            return rightRotate(root);
        else if ((height(root->left)-height(root->right)) > 1 && data > root->left->data)
            return leftRightRotate(root);
        else if ((height(root->left)-height(root->right)) <-1 && data < root->right->data)
            return rightLeftRotate(root);
        else if ((height(root->left)-height(root->right)) <-1 && data > root->right->data)
            return leftRotate(root);
    }
    else
        root = newNode(data);
    return root;
}



void main()
{
    AVLTREE *x = NULL;
    x = insertToAvl(x,55);
    x = insertToAvl(x,15);
    x = insertToAvl(x,90);
    x = insertToAvl(x,67);
    
    inOrder(x);

}
