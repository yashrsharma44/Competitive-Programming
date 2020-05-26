#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	
	string s;
	cin>>s;

	ll minDist = -1;
	ll prevR = s.length();
	for(ll i=s.length()-1;i>=0;i--){

		if(s[i] == 'R'){
			minDist = max(minDist, (prevR - i));
			prevR = i;
		}
	}

	minDist = max(minDist, (prevR + 1));

	cout<<minDist<<endl;
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}