#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){
	
	int n; cin>>n;
	vector<int> p;
	int nn = n;
	while(nn--){
		int u; cin>>u;
		p.push_back(u);
	}

	multiset<int> ms;
	vector<vector<int>> ans;
	vector<int> local;
	for(int i=0;i<n;i++){
		if(i != 0){
			if(*(ms.rbegin()) < p[i]){
				ms.clear();
				ans.push_back(local);
				local.clear();
			}
		}
		ms.insert(p[i]);
		local.push_back(p[i]);
	}
	if(!local.empty()){
		ans.push_back(local);
	}
	reverse(ans.begin(), ans.end());
	for(auto el : ans){
		for(auto e : el){
			cout<<e<<" ";
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
