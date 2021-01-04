#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int n; cin>>n;
	vector<int> arr;
	int nn = n;

	while(nn--){
		int vl; cin>>vl;
		arr.push_back(vl);
	}

	if(n == 1) {
		cout<<1 - arr[0]<<endl;
		return;
	}

	vector<int> pre, post;
	pre.push_back(0);
	post.push_back(0);

	for(int i=0;i<n;i++){
		pre.push_back(pre.back() + arr[i]);
	}

	for(int i=n-1;i>=0;i--){
		post.push_back(post.back() + arr[i]);
	}

	reverse(post.begin(), post.end());
	int ans = 0;

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int local = 0;
			for(int k=i;k<=j;k++){
				local += 1 - arr[k];
			}
			ans = max(ans, pre[i] + post[j] + local);
		}
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
