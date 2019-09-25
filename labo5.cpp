#include<stdio.h>
#include<stdlib.h>
#include <iostream> 


using namespace std;

struct node
{
    int data;
    int key;
    struct node *left, *right;
    
};
struct node *newNode(int item)
{
struct node *temp = (struct node *)malloc(sizeof(struct node));
temp->key = item;
temp->left = temp->right = NULL;
return temp;
}

void inorder(struct node *root)
{
if (root != NULL)
{
inorder(root->left);
printf("%d ", root->key);
inorder(root->right);
}
}

struct node* insert(struct node* node, int key)
{
if (node == NULL) return newNode(key);
if (key < node->key)
node->left = insert(node->left, key);
else if (key > node->key)
node->right = insert(node->right, key);
return node;
}

//delete node in bst

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  
struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL) return root; 

    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 

    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 

        struct node* temp = minValueNode(root->right); 
  
        root->key = temp->key; 
  
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 

//FUNCION DE PRE ORDER

void preOrder(struct node *root) 
{ 
    if(root) 
    { 
        printf("%d ", root->key); 
          
        preOrder(root->left); 
          
        preOrder(root->right); 
    } 
} 

//FUNCION DE POSTORDEN

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);

        postOrder(root->right);
        printf("%d ", root->key);
    }
}

// MAIN
int main()
{

struct node *root = NULL;
root = insert(root, 8);
insert(root, 3);
insert(root, 10);
insert(root, 1);
insert(root, 6);
insert(root, 14);
insert(root, 4);
insert(root, 7);
insert(root, 13);

// print inoder traversal of the BST
printf("\nimprimiendo arbol original:\n");
inorder(root);
printf("\n \n");

printf("\nse acaba de eliminar un nodo del arbol.\n"); 
root = deleteNode(root, 6); 

// print inoder traversal of the BST
printf("\narbol ya con nodo borrado:\n");
inorder(root);
printf("\n \n");

//PRINT PREORDER

printf("\nimprimiendo arbol preOrder:\n");
preOrder(root);
printf("\n \n");


printf("\nimprimiendo arbol postOrder:\n");
postOrder(root);

return 0;
}