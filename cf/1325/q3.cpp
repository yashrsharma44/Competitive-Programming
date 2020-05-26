#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector < ll > adj[n+1];

	ll nn = n-1;
	vector<ll> deg(n+1,0);

	vector < pair<ll,ll> > ans;
	map< pair<ll,ll>, ll> edge;
	while(nn--){
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		ans.push_back({u,v});
		edge[{u,v}] = -1;
		
		deg[u]+=1;
		deg[v]+=1;
	}
	

	// Find a node with deg = 3, if not possible then mex is n-1
	bool isDegThree = false;
	ll node = -1;
	for(ll i=1;i<=n;i++){

		if(deg[i] >= 3){
			isDegThree=true;
			node = i;
			break;
		}
	}

	if(!isDegThree){
		for(ll i=0;i<n-1;i++){
			cout<<i<<endl;
		}
		return;
	} else {

		ll i=0;
		for(ll neigh : adj[node]){

			if(edge.find({node, neigh}) != edge.end()){
				edge[{node, neigh}] = i++;
			} else {
				edge[{neigh, node}] = i++;
			}
		}

		for(pair< pair<ll,ll> ,ll> edg : edge){

			if(edg.first.first == node || edg.first.second == node){
				continue;
			} else {
				edge[edg.first] = i++; 
			}
		}

		for(pair<ll,ll> edg : ans){
			cout<<edge[edg]<<endl;
		}

	}

}

int main(){

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}

}