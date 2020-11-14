#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

void solve(){

	int n,k; cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];

	sort(arr.begin(), arr.end());

	int count = 0;
	for(int i=0;i<n;i+=3){
		if(i+2 < n && 5 - arr[i+2] >= k && 5 - arr[i] >= k) count++;
	}

	cout<<count<<endl;
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
