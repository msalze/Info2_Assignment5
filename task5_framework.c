#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct TreapNode {
    int key;
	int priority;
    struct TreapNode *left;
	struct TreapNode *right;
};

struct TreapNode *root;
 
struct TreapNode* newNode(int key) {
    struct TreapNode* temp = malloc(sizeof(struct TreapNode));
    
	temp->key = key;
    temp->priority = rand()%100;
    temp->left = temp->right = NULL;
    
	return temp;
}

struct TreapNode* search(struct TreapNode* root, int val) {
    // your implementation goes here
}

struct TreapNode* insert(struct TreapNode* root, int val) {
   // your implementation goes here
}

struct TreapNode* deleteNode(struct TreapNode* root, int val) {
   // your implementation goes here
}

void inorder(struct TreapNode* root) {
    if (root) {
        inorder(root->left);
        printf("key: %d | priority: %d ", root->key, root->priority);
        if (root->left)
        printf(" | left child: %d", root->left->key);
        if (root->right)
        	printf(" | right child: %d", root->right->key);
        printf("\n");
        inorder(root->right);
    }
}
 
void main() {
    srand(time(NULL));
    
	root = NULL;
    
	root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    printf("Inorder traversal of the given tree \n");
    inorder(root);
 
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    struct TreapNode *res = search(root, 50);
    
    if(res == NULL){
    	printf("\n50 Not Found");
	} else {
		printf("\n50 Found");
	}
}
