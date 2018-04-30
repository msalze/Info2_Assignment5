#include <math.h>
#include<stdio.h>

struct element {
	int val;
	struct element * next;
};

struct element * H[8];

void init(){
	int i=0;
	for (i; i<8; i++){
		(H[i])=NULL;
	}
}

float h(int val){
	float val_f = (float) val;
	float a = (sqrt(7)-1)/2;
	float x = (val*a);
	x= x-floor(x);
	return floor(8*x);
}

struct element * search(int val){
	int x = h(val);
	struct element * ret,b;
	if ((H[x])->val==val){
		ret = H[x];
		return ret;
	}
	ret = H[x];
	while(ret->next != NULL && ret->val != val){
		ret = ret->next;
	}
	if (ret->val == val){
		return ret;
	}
	else{/*
		b=NULL;
		return b;*/
		return ret;
	}

}

void insert(int val){
	int i = h(val);
	printf("Value %d has hash %d\n", val, i);
	if (H[i]==NULL){
		H[i] = malloc(sizeof(struct element));
		(H[i])->next = NULL;
		(H[i])->val = val;
	}
	else{
		struct element *r;
		r = malloc(sizeof(struct element));
		r->val = val;
		r->next = (H[i])->next;
		(H[i])->next = r;
	}
}

void printHash(){
	int i = 0;
	int length = 8;
	for (i;i<length; i++){
		if (H[i]== NULL){
			printf("H[%d] is empty.\n",i);
		}
		else{
			struct element *p =H[i];
			printf("H[%d] contains: \n",i);
			while (p!=NULL){
				printf("%d ", p->val);
				p=p->next;
			}
			printf("\n");
		}
	}
}

void main(){
	insert(111);
	insert(10112);
	insert(1113);
	insert(5568);
	insert(63);
	insert(1342);
	insert(21231);
	printHash();
	printf("\n");
	struct element *x = search(5568);
	printf("%d", x->val);
}











