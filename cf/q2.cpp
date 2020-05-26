#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll dfs(vector<ll> *adj, ll root, vector<bool> &visited){

	if(visited[root]){
		return 0;
	}

	visited[root] = true;

	ll maxLen = 0;

	for(ll neigh : adj[root]){
		// visited[neigh] = true;
		maxLen = max(maxLen, dfs(adj, neigh, visited));
	}

	return maxLen + 1;

}

void solve(){

	ll n;
	cin>>n;
	string s;
	cin>>s;

	ll maxDist = -1;

	for(ll i=0;i<n;i++){

		if(s[i] == '1'){
			// cout<<"CMAX"<<maxDist<<endl;
			maxDist = max(maxDist, max(abs(i - 0 + 1), abs(i - n)));

			
			// cout<<abs(i - 0 + 1)<<" "<<abs(i - n)<<endl;
		}
	}

	if(maxDist == -1){
		cout<<n<<endl;
		return;
	}

	cout<<(2*maxDist)<<endl;
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}