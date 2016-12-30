#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int value;
	node *leftChild,*rightChild;
	int leftSize=0;
   	node(int v,node *lc, node *rc){
   		value=v;
   		leftChild=lc;
	   	rightChild=rc;
   	}
};


class binaryTree{
   	public:
        node *root=NULL;

       	void insert(int n){
           	if(root==NULL){
           		root=new node(n,NULL,NULL);
           	}
           	else{
               	node *currentNode=root;
	            int t=1;
	            while(1){
	            	if(n<=currentNode->value && currentNode->leftChild!=NULL){
	            		currentNode->leftSize++;
	            		currentNode=currentNode->leftChild;
	            	}
	            	else if(currentNode->rightChild!=NULL){
	            		currentNode=currentNode->rightChild;
	            	}
	            	else{
	            		break;
	            	}
	            }
	            node *tempNode=new node(n,NULL,NULL);
	            if(n<=currentNode->value){
	            	currentNode->leftChild=tempNode;	//currentNode is pointer that's why currentNode->leftChild otherwise currentNode.leftChild
	            	currentNode->leftSize++;
	            }
	            else{
	            	currentNode->rightChild=tempNode;
	            }
	       	}
	   	}

	   	void levelOrderTraversal(node *root){
	   		deque<node*> bfs;
	   		bfs.push_back(root);	//this will take local root and for global root use this->root
	   		while(!bfs.empty()){
	   			node *tempNode=bfs.front();
	   			if(tempNode->leftChild!=NULL){
	   				bfs.push_back(tempNode->leftChild);
	   			}
	   			if(tempNode->rightChild!=NULL){
	   				bfs.push_back(tempNode->rightChild);
	   			}
	   			bfs.pop_front();
	   			cout<<tempNode->leftSize<<" ";
	   		} 
	   	}

	   	int lowestAvg_K(node *root,int k){

	   	}

	   	int highestAvg_K(node *root,int k){

	   	}

	   	void median(){

	   	}
};

int main(){
   binaryTree tree;
   tree.insert(20);
   tree.insert(17);
   tree.insert(14);
   tree.insert(36);
   tree.insert(22);
   tree.insert(28);
   tree.insert(48);
   tree.levelOrderTraversal(tree.root);
   return 0;
}
