#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){
	
	int n,m; cin>>n>>m;
	string s,t; cin>>s>>t;

	// vector<vector<int>> rle;
	// vector<int> local({0});
	// map<char, vector<int> > mp;
	// for(int i=1;i<n;i++){
	// 	if(s[i] != s[i-1]){
	// 		rle.push_back(local);
	// 		mp[s[i-1]] = local;
	// 		local.clear();
	// 	}
	// 	local.push_back(i);
	// }
	// if(!local.empty()){
	// 	mp[s.back()] = local;
	// }

	// int ans = mp[t[0]].back() - mp[t[0]][0];
	// for(int i=1;i<t.length();i++){
	// 	ans = max(ans, mp[t[i]].back() - mp[t[i-1]][0]);
	// }

	// cout<<ans<<endl;

	vector<vector<int>> rlet;
	string tm = t.substr(0, 1), sm = s.substr(0, 1);
	vector<int> local;
	for(int i=1;i<m;i++){
		if(t[i] != t[i-1]){
			tm+=t[i];
			rlet.push_back(local);
			local.clear();
		}
		local.push_back(i);
	}
	if(local.size() > 0){
		rlet.push_back(local);
	}

	vector<vector<int>> rles;
	local.clear();

	for(int i=1;i<n;i++){
		if(s[i] != s[i-1]){
			sm += s[i];
			rles.push_back(local);
			local.clear();
		}
		local.push_back(i);
	}
	
	if(local.size() > 0){
		rles.push_back(local);
	}

	

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
