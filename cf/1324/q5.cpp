#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,h,l,r;
	cin>>n>>h>>l>>r;

	ll nn = n;
	vector<ll> a;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	ll maxGood = 0;
	dfs(a, &maxGood, l, r, 0);

	cout<<maxGood<<endl;
}

int main(){

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}

}