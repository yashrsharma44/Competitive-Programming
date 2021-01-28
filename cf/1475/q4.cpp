#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

bool comp(vector<int> &p1, vector<int> &p2){
	if(p1[1] == p2[1]){
		return p1[0] > p2[0];
	}
	return p1[1] < p2[1];
}

void solve(){

	int n,m; cin>>n>>m;
	vector<int> a,b;
	int nn = n;
	int sum = 0;
	while(nn--){
		int u; cin>>u; sum+=u;
		a.push_back(u);
	}
	nn = n;
	while(nn--){
		int u; cin>>u;
		b.push_back(u);
	}

	if(sum < m){
		cout<<-1<<endl;
		return;
	}

	vector<vector<int>> cont;
	for(int i=0;i<n;i++){
		cont.push_back({a[i], b[i]});
	}

	sort(cont.begin(), cont.end(), comp);
	int local = 0;
	int ans = 0;
	for(int i=0;i<n;i++){
		if(local >= m) break;
		local += cont[i][0];
		ans += cont[i][1];
	}

	cout<<ans<<endl;
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

