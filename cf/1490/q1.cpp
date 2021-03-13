#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int n; cin>>n;
	vector<int> a;
	int nn = n;
	while(nn--){
		int u; cin>>u;
		a.push_back(u);
	}

	int cnt = 0;
	
	int i = 0;
	bool ch = false;
	int left = a[0], right = a[1];
	while(i < n-1){
		int min_ = min(left, right);
		int max_ = max(left, right);	

		while(max_ > 2 * min_){
			min_ *= 2;
			cnt++;
			ch = true;
		}
		if(ch){
			left = min_; right = max_;
			ch = false;
		} else {
			i++;
			left = a[i]; right = a[i+1];
		}
	}
	cout<<cnt<<endl;

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