#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	ll x,y;
	cin>>x>>y;

	ll findCoord = 0;
	if(x < 0 && y > 0){
		findCoord = 1;
	} else if(x < 0 && y < 0){
		findCoord = 2;
	} else if(x > 0 && y < 0){
		findCoord = 3;
	}

	ll maxEl = max(abs(x), abs(y));

	// white = 0,black = 1
	ll color = 0;


	if(maxEl % 2 == 0){
		color  = 1;
	}

	if(abs(x) == abs(y)){
		color = 1 - color;	
	}

	if(x == 0 || y == 0){
		color = 1 - color;
	}
	if(findCoord % 2  == 0){
		if(color == 1){
			cout<<"black"<<endl;
		} else {
			cout<<"white"<<endl;
		}
	} else {
		if(color == 0){
			cout<<"black"<<endl;
		} else {
			cout<<"white"<<endl;
		}
	}
}