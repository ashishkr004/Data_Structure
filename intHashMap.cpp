#include <iostream>
using namespace std;

struct hashMap{
	int size;
	int *key;		
	int *value;
	hashMap(int n){
		key=new int[n];			//key is an array to check if that key is occupied, if equal to 1 then it is occupied
		value=new int[n];		//value is an array which stores integers
		size=n;
		for(int i=0; i<n;i++){
			key[i]=0;
		}
	}
	void rehash();
	void insert(int x);
	
};

void hashMap::rehash(){
		int* temp=value;				//temp is a new pointer which directed to array value
		size*=2;
		value=new int[size];			//pointer value is now directed to new array
		key=new int[size];				//pointer key is alwo directed to new array of length size
		for(int i=0;i<size/2;i++){
			insert(temp[i]);
		}
	}

void hashMap::insert(int x){
	int t=x%size;
	while(key[t]==1){					//while not find empty cell
		t++;
		t=t%size;						//set t to 0 when t become equal to size
		if(t==x%size){
			rehash();
			insert(x);
			return;
		}
	}
	value[t]=x;
	key[t]=1;				
}

int main(){
	hashMap dictionary(3);
	dictionary.insert(11);
	dictionary.insert(22);
	dictionary.insert(33);
	for(int i=0; i<3; i++){
		cout<<dictionary.value[i]<<endl;
	}
	dictionary.insert(44);
	dictionary.insert(55);
	dictionary.insert(66);
	cout<<"after resizing of hashmap"<<endl;
	for(int i=0; i<6; i++){
		cout<<dictionary.value[i]<<endl;
	}
	return 0;
}