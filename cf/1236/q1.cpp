#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll a,b,c; 
	cin>>a>>b>>c;

	ll c_rem = c / 2;

	c_rem = min(c_rem, b);

	ll count = (c_rem * 2)+(c_rem);

	c = c - (c_rem * 2);
	b = b - c_rem;

	ll b_rem = b / 2;
	b_rem = min(b_rem, a);
	count += (b_rem * 2)  + b_rem;
	cout<<count<<endl;

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}