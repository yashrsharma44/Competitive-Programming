#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool comp(pair<ll,ll>p1, pair<ll,ll>p2){

	if(p1.second!=p2.second){
		return p1.second < p2.second;
	}

	return p1.first < p2.first;

}
// Sort by colors,and print them according to color
// Make sure that same color are not sitting side by side


void solve(){

	ll n,m;
	cin>>n>>m;

	vector<ll> adj[n+1];
	while(m--){
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector< pair<ll,ll> > topic;
	vector<ll> color;
	color.push_back(-1);
	topic.push_back({-1,-1});
	
	for(ll i=1;i<=n;i++){
		ll c;
		cin>>c;
		color.push_back(c);
		if(c > n){
			cout<<-1<<endl;
			return;
		}
		topic.push_back(make_pair(c, i));
	}

	vector<bool> used(n+1, false);
	sort(topic.begin(), topic.end());
	vector<ll> ans(n+1, -1);
	for(ll i=1;i<=n;i++){

		ll el = topic[i].second;
		ll tp = topic[i].first;
		
		// check if all the colors before color[el] is used
		// and color[el] is not used
		
		for(ll i=1;i<=color[el];i++){
			used[i] = false;
		}

		for(auto neigh : adj[el]){
			used[color[neigh]] = true;
		}

		if(used[color[el]]){
			cout<<-1<<endl;
			return;
		}
		for(ll i=1;i<color[el];i++){
			if(!used[i]){
				cout<<-1<<endl;
				return;
			}
		}

		ans[i] = el;
	}

	for(ll i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

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
