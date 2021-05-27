#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStruct
{
    int value;
    struct NodeStruct* left;
    struct NodeStruct* right;
}Node;

Node* root = NULL;

Node* insert(Node* root, int value)
{
    if(root == NULL)
    {
        root = (Node*)malloc(sizeof(Node));
        root->left = root->right = NULL;
        root->value = value;
        return root;
    }
    else
    {
        if(root->value > value)
            root->left = insert(root->left, value);
        else
            root->right = insert(root->right, value);
    }
    return root;
}

Node* search(Node* root, int value)
{
	
	printf("%d ", root->value);
    if(root == NULL)
        return NULL;

    if(root->value == value){
        return root;
		
	}else if(root->value > value){
        return search(root->left, value);
		
	}else
        return search(root->right, value);


	
}


int main()
{
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 5);
	root = insert(root, 6);
	root = insert(root, 7);
	root = insert(root, 8);
	root = insert(root, 11);
	root = insert(root, 12);
	root = insert(root, 14);
	root = insert(root, 15);
	root = insert(root, 24);
	root = insert(root, 26);
	root = insert(root, 42);
	root = insert(root, 43);
	root = insert(root, 48);
	root = insert(root, 49);
	root = insert(root, 51);
	root = insert(root, 55);
	root = insert(root, 56);
	root = insert(root, 59);
	root = insert(root, 66);
	root = insert(root, 67);
	root = insert(root, 69);
	root = insert(root, 70);
	root = insert(root, 71);
	root = insert(root, 73);
	root = insert(root, 75);
	root = insert(root, 80);
	root = insert(root, 96);
	root = insert(root, 99);


	printf("Search Order:");
	search(root, 3);
	printf("\n\n");
	

	printf("Search Order:");
	search(root, 96);
	printf("\n\n");

	printf("Search Order:");
	search(root, 15);
	printf("\n\n");

	printf("Search Order:");
	search(root, 66);
	printf("\n\n");

	printf("Search Order:");
	search(root, 99);
	printf("\n\n");

	return 0;
}