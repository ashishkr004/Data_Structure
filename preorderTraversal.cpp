#include <iostream>
using namespace std;

struct node{		// define new structure
	int value;
	node *leftChild=NULL;		// statically initiallize left child of node to NULL
	node *rightChild=NULL;		
};

//Preorder(root,left,right)
void preorder(node *tNode){		// recursion function
	cout<<tNode->value<<" ";			// print value of node
	if(tNode->leftChild!=NULL){		// if left child is not null call preorder recursively
		preorder(tNode->leftChild);
	}
	if(tNode->rightChild!=NULL){	
		preorder(tNode->rightChild);
	}
}

int main(){
	node *a = new node;		// variabe a of pointer type node
	a->value=1;				// set value of node a to 1
	node *b=new node;
	b->value=2;
    	node *c=new node;
	c->value=3;
	node *d=new node;
	d->value=4;
	node *e=new node;
	e->value=5;
    	a->leftChild=b;			// set node b as left child of a
	a->rightChild=c;		// set node c as right cild of a
	b->leftChild=d;
	b->rightChild=e;
	
	preorder(a);

	return 0;
}
