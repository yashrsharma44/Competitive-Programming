#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;
	int nn = n;
	vector<int> a;
	while(nn--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}
	// if(n%2==1){
	for(int i=0;i<n/2;i+=2){
		swap(a[i], a[n-i-1]);
	}
	for(int el : a){
		cout<<el<<" ";
	}
	cout<<endl;
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
