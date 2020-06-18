#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;

	vector<int> a;
	for(int i=0;i<n;i++){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}

	vector<int> prefix(n,0);
	prefix[0] = a[0];
	for(int i=1;i<n;i++){
		prefix[i] = prefix[i-1] + a[i];
	}

	int count = 0;
	if(prefix[n-1] % 3 != 0){
		cout<<0<<endl;
		return;
	}

	int sm = prefix[n-1] / 3;
	int sm2 = 2 * sm;

	vector<int> idx1, idx2;
	for(int i=0;i<n-1;i++){
		if(prefix[i] == sm) idx1.push_back(i);
		if(prefix[i] == sm2) idx2.push_back(i);
	}
	// cout<<sm<<" "<<sm2<<endl;
	for(int i=0;i<idx1.size();i++){

		count += (idx2.end() - lower_bound(idx2.begin(), idx2.end(), idx1[i]+1));
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
