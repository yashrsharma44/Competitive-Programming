#include <bits/stdc++.h>
#define MOD 998244353
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;
	if(n <= 30){
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	if(n == 36){
		cout<<"5 6 10 15"<<endl;
		return;
	}
	if(n == 40){
		cout<<"6 10 22 2"<<endl;
		return;
	}
	if(n == 44){
		cout<<"6 7 10 21"<<endl;
		return;
	}
	cout<<"6 10 14 "<<(n-30)<<endl;
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
