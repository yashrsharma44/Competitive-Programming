#include <bits/stdc++.h>
#define int long long 

using namespace std;




void solve(){

	int n;
	cin>>n;

	vector< pair<int,int> >ab;
	for(int i=0;i<n;i++){
		int aa,bb;
		cin>>aa>>bb;
		ab.push_back({aa,bb});
	}	

	int ans = 0;
	for(int i=0;i<n;i++){
		ans += ab[i].second * (n - 1);
	}
	vector<int> vv;
	for(int i=0;i<n;i++){
		vv.push_back(ab[i].first - ab[i].second);
	}
	sort(vv.begin(),vv.end(),greater<int>());

	for(int i=0;i<n;i++){
		ans += (i) * (vv[i]);
	}
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
