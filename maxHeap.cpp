#include <iostream>
#include <string>

using namespace std;

struct node{
   	string name;
   	int age;
   	node(){}       //default constructer
   	node(string str, int n){   //define constructer
		name=str;
		age=n;
   	}
};


class maxHeap{
   	public:
       	node *a;       //a is a pointer of type node
       	int count;

       	maxHeap(int size){
           	a=new node[size+1];		//array size is size+1
           	count=1;		//entry in array start from 1
       	}

       	void insert(node newOne, int type){
           	a[count]=newOne;
           	if(type==1){
           		balanceStr();
           	}
           	else{
           		balance();
           	}
           	count++;
       	}

       	void balance(){
           	int i=count;
           	while(i>1){
               	if(a[i].age>a[i/2].age){
                   	node temp=a[i];
                   	a[i]=a[i/2];
                   	a[i/2]=temp;
                   	i=i/2;
               	}  
               	else{
                   	break;
               	}  
           	}
       	}

       	void balanceStr(){
       	    int i=count;
       	    
           	while(i>1){
           		int j=0;
           		while(j<a[i].name.length() && j<a[i/2].name.length()){
           			
           			char f=a[i].name[j];
           			char g=a[i/2].name[j];
           			int x=(int)f;
           			int y=(int)g;
           			
           			if(x==y){
           				j++;
           			}
           			else if(x>y){
           				node temp=a[i];
           				a[i]=a[i/2];
           				a[i/2]=temp;
           				i=i/2;
           			}
           			else{
           				i=0;
           				break;
           			}
           		}
           		if(a[i].name.length()==a[i/2].name.length() || j<a[i].name.length() || j<a[i/2].name.length()){
           			break;
           		}
           	}
       	}

       	void preorderTraversal(int type){
       		if(type==1){
	       		for(int i=1; i<count; i++){
	       			cout<<a[i].name<<" "<<endl;
	       		}	
       		}
       		else{
	       		for(int i=1; i<count; i++){
	       			cout<<a[i].age<<" "<<endl;
	       		}
       		}
       		
       	}
};

int main(){
   	node aradwolf("bella",35);
   	node buffalo("cosmo",33);
   	node cat("sophie",42);
   	node dog("moti",10);
   	node elephant("max",14);
   	node fox("ruby",19);
   	node giraffe("sunny",27);
   	node horse("maggy",44);
   	node ibex("coco",26);
   	node jaguar("lucy",31);

   	maxHeap animalDict(10);
   	animalDict.insert(aradwolf,0);
   	animalDict.insert(buffalo,0);
   	animalDict.insert(cat,0);
   	animalDict.insert(dog,0);
   	animalDict.insert(elephant,0);
   	animalDict.insert(fox,0);
   	animalDict.insert(giraffe,0);
   	animalDict.insert(horse,0);
   	animalDict.insert(ibex,0);
   	animalDict.insert(jaguar,0);
   	animalDict.preorderTraversal(0);
   	
   	maxHeap animalDict_2(10);
   	node currentAnimal("try",1);
   	for (int i = 1; i < animalDict.count; i++){
   		currentAnimal.name=animalDict.a[i].name;
   		currentAnimal.age=animalDict.a[i].age;
   		animalDict_2.insert(currentAnimal,1);
   	}
   	animalDict_2.preorderTraversal(1);
   	return 0;
}
