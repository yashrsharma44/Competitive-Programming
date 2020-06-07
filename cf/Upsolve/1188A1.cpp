#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){

	ll n;
	cin>>n;
	vector<ll> adj[n+1];
	ll m = n-1;
	vector<ll> indeg(n+1,0);
	while(m--){
		ll u,v;
		cin>>u>>v;
		indeg[u]++;
		indeg[v]++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ll leaf = 0, nleaf = 0;
	for(ll i=1;i<=n;i++){
		if(indeg[i] == 1){
			leaf+=1;
		} else if(indeg[i]>2){
			nleaf+=1;
		}
	}

	if(leaf + nleaf != n){
		cout<<"NO"<<endl;
	} else {
		cout<<"YES"<<endl;
	}

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
