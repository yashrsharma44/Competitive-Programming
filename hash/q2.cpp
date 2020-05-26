#include <bits/stdc++.h>

using namespace std;

class Bucket {
public:
    vector< pair<int,int> > bkt;
    Bucket() {
        this->bkt = vector<  pair< int,int> >();
    }
    
    int size(){
        return this->bkt.size();
    }
    
    int get(int key){
        
        for(pair<int,int> el : this->bkt){
            if(el.first == key){
                return el.second;
            }
        }
        
        return -1;
    }
    
    void put(int key, int val){
        this->bkt.push_back(make_pair(key, val));
    }
    
    void remove(int key){
    
        for(int i=0;i<this->bkt.size();i++){
            if(this->bkt[i].first == key){
                this->bkt.erase(this->bkt.begin()+i);
                return;
            }
        }
        
    }
};

class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector <Bucket*> arr;
    MyHashMap() {
        this->arr = vector<Bucket*>();
        for(int i=0;i<2069;i++){
            this->arr.push_back(new Bucket());
        }
        // cout<<"Done"<<endl;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        
        int k = key % 2069;
        // this->arr[k] = new Bucket();
        this->arr[k]->put(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return this->arr[key%2069]->get(key);
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        this->arr[key%2069]->remove(key);
    }
};

int main(){

	MyHashMap *mp = new MyHashMap();
	mp->put(1,1);
	mp->put(2,2);

	cout<<mp->get(1)<<endl;
	cout<<mp->get(3)<<endl;
	mp->put(2,1);
	cout<<mp->get(2)<<endl;
	mp->remove(2);
	cout<<mp->get(2)<<endl;
}