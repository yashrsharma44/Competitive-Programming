#include <bits/stdc++.h>
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
	sort(a.begin(), a.end());
	for(int i=1;i<a.size();i++){
		if(abs(a[i] - a[i-1]) > 1){
			cout<<"NO"<<endl;
			return;
		}
	}

	cout<<"YES"<<endl;

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
