#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	string a,b,c;
	cin>>a>>b>>c;

	bool isPos = true;
	if(a == b && b== c){
		cout<<"YES"<<endl;
		return;
	}
	for(ll i=0;i<a.length();i++){

		if(a[i] == c[i] && b[i] != c[i]){
			swap(b[i],c[i]);
		} else if(a[i] != c[i] && b[i] == c[i]){
			swap(a[i], c[i]);
		} else if(a[i] == c[i] && b[i] == c[i]){
			continue;
		} else {
			isPos = false;
			break;
		}

	}

	if(isPos){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}