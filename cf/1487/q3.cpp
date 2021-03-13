#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int n; cin>>n;
	vector<vector<int>> adj(n, vector<int>(n, -1));

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			adj[i][j] = 1;
			adj[j][i] = 1;
		}
	}
	int hlf = (n-1) / 2;
	vector<int> in(n, n-1), out(n, n-1);
	for(int i=0;i<n;i++){
		int cnt = in[i] / 2;
		
		for(int j=0;j<n;j++){
			if(cnt == 0) break;
			int nei = (i + 1 + j) % n;
			// cout<<i<<" "<<nei<<endl;
			if(adj[i][nei] == 1 && adj[nei][i] == 1){
				adj[nei][i] = -1;
				out[nei]--;
				in[i]--;
				cnt--;
			}
		}

		// for(auto nei : adj[i]){
		// 	if(cnt == 0) break;
		// 	if(out[nei] >= hlf){
		// 		adj[nei].erase(find(adj[nei].begin(), adj[nei].end(), i));
		// 		out[nei]--;
		// 		in[i]--;
		// 		cnt--;
		// 	}
		// }
	
	}

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(adj[i][j] > 0 && adj[j][i] > 0){
				cout<<0<<" ";
			} else if(adj[i][j] > 0 && adj[j][i] < 0) {
				cout<<1<<" ";
			} else {
				cout<<-1<<" ";
			}
		}
	}
	cout<<endl;

}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}