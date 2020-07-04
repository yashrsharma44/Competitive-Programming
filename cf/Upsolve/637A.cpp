#include <bits/stdc++.h>
#define int long long 

using namespace std;

int getMax(map<int,int> mp, int mx,  int cnt){

	// int mx = -1
	// int cnt = 0;
	for(auto el : mp){
		if(el.second > cnt){
			cnt = el.second;
			mx = el.first;
		}
	}
	return mx;

}

void solve(){

	int n;
	cin>>n;
	map<int,int> mp;
	int max_ = -1;
	for(int i=0;i<n;i++){
		int v;
		cin>>v;
		mp[v]+=1;
		max_ = getMax(mp, max_, mp[max_]);
	}
	cout<<max_<<endl;

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
