#include <bits/stdc++.h>
#define int long long 
using namespace std;
int get(map<char,vector<int>> &mp, char c){
	if(mp[c].size() == 0){
		return 3;
	}
	if(mp[c].size() == 1){
		return 2;
	}
	if(mp[c].size() == 2){
		auto vv = mp[c];
		if(abs(vv[0] - vv[1]) == 1 || abs(vv[0] - vv[1]) == 2){
			return 1;
		} else if(vv[0] == vv[1]){
			return 1;
		} else {
			return 2;
		}
	}
	if(mp[c].size() == 3){
		auto vv = mp[c];
		sort(vv.begin(), vv.end());
		if(abs(vv[0] - vv[1]) == 1 && abs(vv[1] - vv[2]) == 1){
			return 0;
		} else if(abs(vv[0] - vv[1]) == 1 || abs(vv[1] - vv[2]) == 1){
			return 1;
		} else if(vv[0] == vv[1] && vv[1] == vv[2]){
			return 0;
		} else if(vv[0] == vv[1] || vv[1] == vv[2]){
			return 1;
		} else if(abs(vv[0] - vv[1]) == 2 || abs(vv[1] - vv[2]) == 2){
			return 1;
		}
		return 2;
	}
}
void solve(){

	string s1,s2,s3;
	cin>>s1>>s2>>s3;

	map<char,vector<int> > mp;
	mp[s1[1]].push_back((s1[0]-'0'));
	mp[s2[1]].push_back((s2[0]-'0'));
	mp[s3[1]].push_back((s3[0]-'0')); 

	int ans = INT_MAX;
	ans = min(ans, get(mp, 's'));
	ans = min(ans, get(mp, 'p'));
	ans = min(ans, get(mp, 'm'));

	cout<<ans<<endl;

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
