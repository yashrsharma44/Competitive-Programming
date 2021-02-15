#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

bool comp(vector<int> &p1, vector<int> &p2){
	return p1[1] > p2[1];
}

void solve(){

	int n; cin>>n;
	vector<vector<int>> q;
	for(int i=0;i<n;i++){
		int u,v; cin>>u>>v;
		q.push_back({u,v, i+1});
	}
			
	int k; cin>>k;
	vector<vector<int>> r;
	for(int i=0;i<k;i++){
		int u; cin>>u;
		r.push_back({u, i+1});
	}

	sort(q.begin(), q.end(), comp);
	sort(r.begin(), r.end());
	vector<vector<int>> ans;
	int total = 0, sum = 0;
	for(int i=0;i<n;i++){

		for(int j=0;j<k;j++){
			if(r[j][0] >= q[i][0]){
				ans.push_back({q[i][2], r[j][1]});
				r[j][0] = -1;
				total++; sum += q[i][1];
				break;
			}
		}
	}
	cout<<total<<" "<<sum<<endl;

	for(auto el : ans) cout<<el[0]<<" "<<el[1]<<endl;

}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
