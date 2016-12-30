#include <iostream>
#include <string>
#include <math.h>
#include <array>
#include <vector>
using namespace std;

int stringValue(string tString){    // get integer value of string 
    int val=0;
    for (int i = 0; i < tString.length(); i++) {    //while i is less than length of string
        char c=tString[i];      //ascii value of char at index i in string
        val+=pow(10,i)*((int)c-97);
    }
    return val;
}

class hashMap{
    public:
        vector<string> v[33];

        void insert(string s){      //insert word in dictionary of size 33.
            int value = stringValue(s);
            int key = value%33;
            v[key].push_back(s);
        }

        void remove(string s){      //remove words from dictionary
            int value = stringValue(s);
            int key = value%33;
            vector<string> tempList;

            while(!v[key].empty()){
                if(v[key].back() != s){     //return the last in
                    tempList.push_back(v[key].back());
                    v[key].pop_back();      //delete the last in
                }
                else{
                    v[key].pop_back();
                }
            }
            v[key]=tempList;
        }

        bool find(string s){
            int value = stringValue(s);
            int key = value%33;
            vector<string> tempList;
            while(!v[key].empty()){
                string tempStr=v[key].back();
                v[key].pop_back();
                if(tempStr==s){
                    tempList.push_back(s);
                    return true;    //return 1
                }
                else{
                    tempList.push_back(tempStr);
                }
            }
            return false;       //return 0
        }

        int size1(){
            int count=0;
            for (int i = 0; i < 33; i++) {      //for each i in array
                if(!v[i].empty()){
                    vector<string> tempStr;
                    while (!v[i].empty()){      //first we pop out all words at index i in array and push words in vector tempStr and once we complete the count of total words in array at index i again we push that tempStr to array at i.
                        tempStr.push_back(v[i].back());
                        v[i].pop_back();
                        count++;
                    }
                    v[i]=tempStr;
                }
            }
            return count;
        }
};

int main() {
  hashMap dictionary;
  dictionary.insert("institute");
  dictionary.insert("aberration");
  dictionary.insert("abhor");
  dictionary.insert("acquiesce");
  dictionary.insert("alacrity");
  dictionary.insert("amiable");
  dictionary.insert("appease");
  dictionary.insert("arcane");
  dictionary.insert("avarice");
  cout<<dictionary.size1()<<endl;
  cout<<"If return 1 then true else false: "<<dictionary.find("institute")<<endl;
  dictionary.remove("institute");
  cout<<dictionary.size1()<<endl;
  cout<<"If return 1 then true else false: "<<dictionary.find("institute")<<endl;
  return 0;
}
