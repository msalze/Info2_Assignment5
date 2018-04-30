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
    struct TreapNode * p = root;
    while (p!=NULL){
    	if (val == p->val){
    		return p;
		}
    	else if (val>p->val){
    		p=p->right;
		}
		else{
			p=p->left;
		}
	}
	return p;
}

struct TreapNode* insert(struct TreapNode* root, int val) {
    struct TreapNode * new_node = newNode(val);
    struct TreapNode * p = root;
    struct TreapNode * q = root;
    if (root==NULL){
    	root=new_node;
    	return root;
	}
	/*binary tree insertion*/
    while (p!=NULL){
    	if (val>p->val){
    		q=p;
    		p=p->right;
		}
		else{
			q=p;
			p=p->left;
		}
	}
	if (val>p->val){
		q->right = new_node;
	}
	else{
		q->left = new_node;
	}
	/*fix priority order*/
	if (neq_node->priority>q->priority){
		if (q->left ==new_node){
			rightRotate(root,new_node);
		}
		else{
			leftRotate(root;new_node);
		}
	}
	
	
	
}

void rightRotate(struct TreapNode*root, struct TreapNode*x){
	struct TreapNode *p,*g,*b;
	b=root;
	g=NULL;
    p=NULL;
	while (b->val !=x->val){
		if (x->val >b){
			g=p;
			p=b;
			b=b->right;
		}
		else{
			g=p;
			p=b;
			b=b->left;
		}
	}
	b=x->right;
	x->right =p;
	p->left = b
	if (p->val>g->val){
		g->right = x;
	}
	else{
		g->left = x;
	}
}

void leftRotate(struct TreapNode*root, struct TreapNode*x){
	struct TreapNode *p,*g,*b;
	b=root;
	g=NULL;
    p=NULL;
	while (b->val !=x->val){
		g=p;
		p=b;
		if (x->val >b){
			b=b->right;
		}
		else{
			b=b->left;
		}
	}
	b=x->left;
	x->left = p;
	p->right = b
	if (p->val>g->val){
		g->right = x;
	}
	else{
		g->left = x;
	}
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
