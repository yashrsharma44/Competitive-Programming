#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	string s;
	cin>>s;

	string x1="", x2="";
	ll i = 0;
	for(;i<n;i++){

		if(s[i] == '2'){
			x1 += '1';
			x2 += '1';
		} else if(s[i] == '0'){
			x1 += '0';
			x2 += '0';
		} else {
			break;
		}
	}

	ll start=i;
	while(start < n){

		if(start == i){
			x1 += '1';
			x2 += '0';
		} else {
			x1 += '0';
			x2 += s[start];
		}
		start++;
	}

	cout<<x1<<endl;
	cout<<x2<<endl;

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}