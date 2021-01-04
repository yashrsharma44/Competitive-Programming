#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

void solve(){

	int n, k; cin>>n>>k;
	vector<int> arr;
	int nn = n;
	while(nn--){
		int u;cin>>u; arr.push_back(u);
	}

	int sum = 0; int pos = 0;
	int localSum = 0;
	for(int i=0;i<k;i++){
		localSum += arr[i];
	}
	sum = localSum;
	for(int i=k;i<n;i++){
		localSum = localSum - arr[i-k] + arr[i];
		if(localSum < sum){
			sum = localSum;
			pos = i;
		}
	}
	// cout<<pos<<endl;
	if(pos == 0) {
		cout<<1<<endl;
		return;
	}
	cout<<(pos + 1 - (k - 1))<<endl;

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
