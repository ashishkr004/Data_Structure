//ashishkr004
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node{
	int level;
	int key;
	char value;
	bool valid;
	vector<node*> children;
	node(){}
};

class trie{
	public:
		node *root;
		int count;
		string *array;
		
		trie(int size){
			root=new node();
			root->level=0;
			root->valid=0;
			root->key=0;
			array=new string[size];
			count=0;
		}

		void insert(string word){
			node *parent=root;
			while(parent->level<word.length()){
				vector<node*> temp;
				while(!parent->children.empty()){
					if(parent->children.back()->value==word[parent->children.back()->level-1]){
						node *tNew=parent->children.back();
						while(!temp.empty()){
							parent->children.push_back(temp.back());
							temp.pop_back();
						}
						parent=tNew;
					}
					else{
						temp.push_back(parent->children.back());
						parent->children.pop_back();
					}
				}
				if(parent->level==word.length()){
					if(parent->valid==0){
						parent->valid=1;
						parent->key=count;
						array[count]=word;
						count++;	
					}
					while(!temp.empty()){
						parent->children.push_back(temp.back());
						temp.pop_back();
					}
					break;
				}
				else{
					node *newNode=new node();
					newNode->level=parent->level+1;
					newNode->value=word[newNode->level-1];
					newNode->valid=0;
					if(newNode->level==word.length()){
						newNode->valid=1;
						newNode->key=count;
						array[count]=word;
						count++;
					}
					while(!temp.empty()){
						parent->children.push_back(temp.back());
						temp.pop_back();
					}
					parent->children.push_back(newNode);
					parent=newNode;
				}
			}
		}

		node* search(string str){
			node *parent=root;
			while(parent->level<str.length()){
				vector<node*> temp;
				while(!parent->children.empty()){
					if(parent->children.back()->value==str[parent->children.back()->level-1]){
						node *tNew=parent->children.back();
						while(!temp.empty()){
							parent->children.push_back(temp.back());
							temp.pop_back();
						}
						parent=tNew;
						break;
					}
					else{
						temp.push_back(parent->children.back());
						parent->children.pop_back();
					}
				}	
			}
			return  parent;
		}

		void wordSuggestions(string str){
			node *parent = search(str);
			vector<string> suggestions;

			vector<node*> immediateChilds;
			vector<node*> allChilds;
			while(!parent->children.empty()){
				immediateChilds.push_back(parent->children.back());
				if (parent->children.back()->valid==1){
					suggestions.push_back(array[parent->children.back()->key]);
				}
				parent->children.pop_back();
				if(parent->children.empty()){
					parent->children=immediateChilds;
					while(!immediateChilds.empty()){
						allChilds.push_back(immediateChilds.back());
						immediateChilds.pop_back();
					}
					parent=allChilds.back();
					allChilds.pop_back();
				}
				while(parent->children.empty() && !allChilds.empty()){
					parent=allChilds.back();
					allChilds.pop_back();
				}
			}
			while(!suggestions.empty()){
				cout<<suggestions.back()<<endl;
				suggestions.pop_back();
			}
		}

};

int main(){
	trie dictionary(20);
	dictionary.insert("artist");
	dictionary.insert("art");
	dictionary.insert("artificial");
	dictionary.insert("effort");
	dictionary.insert("effect");
	dictionary.insert("torch");
	dictionary.insert("toss");
	dictionary.insert("test");
	dictionary.insert("torchere");
	dictionary.insert("horse");
	dictionary.insert("hobbit");
	dictionary.insert("has");
	dictionary.insert("bit");
	dictionary.insert("hot");
	dictionary.insert("habbit");
	dictionary.insert("bore");
	dictionary.insert("bare");
	dictionary.insert("bear");
	dictionary.insert("bar");
	dictionary.insert("barret");

	
	cout<<"Print all words of dictionary: "<<endl;
	for (int i = 0; i < 20; ++i){
		cout<<dictionary.array[i]<<endl;
	}

	cout<<endl;
	cout<<"Word suggestions for to: "<<endl;
	dictionary.wordSuggestions("to");
	cout<<"-------------"<<endl;
	cout<<"Word Suggestions for tor: "<<endl;
	dictionary.wordSuggestions("tor");
	cout<<"-------------"<<endl;
	cout<<"Word Suggestions for a: "<<endl;
	dictionary.wordSuggestions("a");
		
	return 0;
}


