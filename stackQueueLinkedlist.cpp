#include <iostream>
using namespace std;

struct stack{
	int size;
	int top;
	int *array;

	stack(int n){
		size=n;
		top=0;
		array=new int[n];
	}

	void push(int value){
		if(top>=size){
			size*=2;
			int tempArray[size];
			for(int i=0; i<size/2; i++){
				tempArray[i]=array[i];
			}
			array=tempArray;
			array[top]=value;
			top++;
		}
		else{
			array[top]=value;
			top++;
		}
	}

	void pop(){
		top--;
	}

	void displayContents(){
		for(int i=0; i<top; i++){
			cout<<array[i]<<" ";
		}
	}
};

struct queue{
	int size;
	int top;
	int bottom;
	int totalElement;
	int *array;

	queue(int n){
		size=n;
		bottom=0;
		top=0;
		array=new int[n];
	}

	void enqueue(int value){
		if(totalElement>=size){
			size*=2;
			int tempArray[size];
			for(int i=0; i<size/2; i++){
				tempArray[i]=array[bottom%(size/2)];
				bottom++;
			}
			array=tempArray;
			array[totalElement]=value;
			totalElement++;
			top=totalElement;
			bottom=0;
		}
		else{
			array[top%size]=value;
			top++;
			totalElement++;
		}
	}

	void dequeue(){
		bottom++;
		totalElement--;
	}

	void displayContents(){
		for(int i=bottom; i<=totalElement+bottom; i++){
			cout<<array[i%size]<<" ";
		}
	}
};

struct node{
	int data;
	node *next;

	node(){
		next=NULL;
	}
};

struct linkedList{
	node *root;

	linkedList(){
		root=new node;
		root->next=NULL;
	}

	void insertAtHead(int value){
		node *temp=new node;
		temp->data=value;
		temp->next=root;
		root=temp;
	}

	void insertAtPosition(int value, int position){		//position of root node is 0.
		node *lNode=root;
		node *rNode=new node;
		while(position>0){
			lNode=lNode->next;
			rNode=lNode->next;
			position--;
		}
		node *temp=new node;
		temp->data=value;
		temp->next=rNode;
		lNode->next=temp;
	}

	void removeFromPosition(int position){
		node *lNode=root;
		node *rNode=new node;
		while(position>0){
			lNode=lNode->next;
			rNode=rNode->next;
			position--;
		}
		lNode->next=rNode->next;
	}

	void displayContents(){
		node *temp=root;
		while(temp->next!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
};

int main(){
	
	return 0;
}









