#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

void solve(){

	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> pre(n+1, 0);
	for(int i=0;i<n;i++){
		pre[i+1] = pre[i] + (s[i] - '0');
	}
	map<int,int> mp;
	mp[0] = 1;
	int count = 0;
	for(int i=1;i<=n;i++){
		int val = i - (pre[i]);
		if(mp.count(val) > 0){
			count += mp[val];
		}
		mp[val]++;
	}
	cout<<count<<endl;

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
