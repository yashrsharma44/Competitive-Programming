#include <bits/stdc++.h>
#define MOD 998244353
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;
	vector<int> a;
	while(n--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}
	// remove monotnous 
	n = a.size();
	int i = n-1;
	if(a[i] <= a[i-1]){
		while(i > 0 && a[i] <= a[i-1]){
			i--;
		}
	} 

	if(i > 0 && a[i] >= a[i-1]) {
		while(i > 0 && a[i] >= a[i-1]){
			i--;
		}
	}
	cout<<i<<endl;



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
