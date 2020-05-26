#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll  n,m;
	cin>>n>>m;

	vector<ll> a;
	ll nn =  n;
	ll sum = 0;
	while(nn--){
		ll vl;
		cin>>vl;
		sum += vl;
		a.push_back(vl);
	}

	cout<<min(sum, m)<<endl;
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}