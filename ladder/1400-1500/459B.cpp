#include <bits/stdc++.h>
#define int long long 

using namespace std;
#define MAX 1000005

void solve(){

	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	int max_ = INT_MIN, min_ = INT_MAX;
	
	for(int el : a){
		max_ = max(max_, el);
		min_ = min(min_, el);
	}

	int c1 = 0, c2 = 0;
	for(int el : a){
		if(el == max_) c1++;
		if(el == min_) c2++;
	}
	int ans = c1 * c2;
	if(max_ == min_){
		ans = (c1 * (c1 - 1)) / 2;
	}
	cout<<(max_ - min_)<<" "<<(ans)<<endl;
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
