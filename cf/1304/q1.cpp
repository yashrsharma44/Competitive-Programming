#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll x,y,a,b;
	cin>>x>>y>>a>>b;

	ll spd = (a + b);

	if(abs(x-y) % (spd) == 0){
		cout<<abs(x-y)/spd<<endl;
	} else {
		cout<<-1<<endl;
	}

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}