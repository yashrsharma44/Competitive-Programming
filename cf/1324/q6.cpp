#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector<ll> adj[200001];
vector<ll> dp(200001);
vector<ll> dp2(200001);

vector<ll> a;

void dfs(ll node=1, ll parent=0){

	dp[node] = a[node] == 1 ? 1 : -1;
	for(ll child : adj[node]){

		if(child == parent){
			continue;
		}
		dfs(child, node);
		dp[node]+=max(0ll, dp[child]);
	}
}

void dfs2(ll node=1, ll parent=0){

	dp2[node] = dp[node];

	if(parent){

		ll val = dp2[parent] - max(0ll ,dp[node]);
		dp2[node] += max(0ll, val);
	}

	for(ll child : adj[node]){

		if(parent == child){
			continue;
		}

		dfs2(child, node);
	}
}

int main(){

	ll n;
	cin>>n;

	
	ll nn = n;
	a.push_back(0);
	while(nn--){
		ll vl;
		cin>>vl;

		a.push_back(vl);
	}

	nn = n-1;
	while(nn--){
		ll u,v;
		cin>>u>>v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs();
	dfs2();
	for(ll i=1;i<=n;i++){
		cout<<dp2[i]<<" ";
	}
	cout<<endl;

}