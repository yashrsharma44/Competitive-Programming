#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll dfs(ll root, vector<ll> *adj, map<ll,ll> &count, vector<bool> &visited, ll parent=-1){


	if(adj[root].size() == 1 && adj[root][0] == parent){
		count[root] = 0;
		return 1;
	}

	ll totalCount = 0;

	for(ll neigh : adj[root]){
		
		ll val = 0;
		if(neigh != parent)
		{
			val=dfs(neigh, adj, count, visited, root);
		}
		totalCount += val;
	}
	count[root] = totalCount;
	return totalCount+1;
}


void solve(){

	ll n,k;
	cin>>n>>k;

	vector<ll> adj[n+1];
	ll nn = n-1;
	while(nn--){
		ll u,v;
		cin>>u>>v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// vector<bool> visited(n+1, false);
	// map <ll,ll> count;
	// ll rt = 1;
	// visited[1] = true;
	// ll cc = dfs(rt,adj,count,visited, -1);

	// ll maxSum = 0;
	// vector<ll> val;
	// for(auto el : count){
		
	// 	val.push_back(el.second);
	// }
	// sort(val.begin(), val.end(), greater<ll>());

	// for(ll i=0;i<min(k,n);i++){
	// 	maxSum += val[i];
	// }
	// cout<<maxSum<<endl;

	queue<ll> q;
	map<ll,ll> level;
	q.push(1);
	vector<bool> visited(n+1, false);
	ll lvl = 0;
	// ll parent = 1;
	visited[1] = true;
	while(!q.empty()){
		lvl+=1;

		ll sz = q.size();
		for(ll i=0;i<sz;i++){
			ll node = q.front();
			q.pop();
			visited[node] = true;
			level[node] = lvl;
			for(ll child : adj[node]){
				if(!visited[child]){
					q.push(child);
				}
			}
			
		}

	}

	vector < pair<ll,ll> > numEl;
	for(ll i=1;i<=n;i++){
		numEl.push_back(make_pair(adj[i].size(), i));
	}

	sort(numEl.begin(), numEl.end());

	ll totalCount = 0;
	for(ll i=0;i<min(k,(ll)numEl.size());i++){
		ll val = abs(level[numEl[i].second] - level[1]);
		totalCount += val;
	}

	cout<<totalCount<<endl;

	cout<<"U"<<endl;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}