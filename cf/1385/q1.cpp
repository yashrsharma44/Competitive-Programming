#include <bits/stdc++.h>
#define MOD 998244353
#define int long long 

using namespace std;

void solve(){

	vector<int> a(3,0);
	cin>>a[0]>>a[1]>>a[2];
	vector<int> aa(a);
	sort(aa.begin(), aa.end());

	if(aa[0] == aa[1] && aa[1] == aa[2]){
		cout<<"YES"<<endl;
		cout<<aa[0]<<" "<<aa[0]<<" "<<aa[0]<<endl;
		return;
	}

	if(aa[1] == aa[2]){
		cout<<"YES"<<endl;
		cout<<aa[2]<<" "<<aa[0]<<" 1"<<endl;
		return;
	}
	cout<<"NO"<<endl;

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
