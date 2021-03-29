#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

	string s; cin>>s;
	int n = s.length();
	
	vector<bool> one(n, false), zero(n, false);
	zero[0] = (s[0] == '0') ? true : false;
	zero[1] = (s[1] == '0') ? true : false;

	for(int i=2;i<n;i++){
		if(s[i] == '0'){
			zero[i] = zero[i-1] || zero[i-2];	
		}
		
	}

	one[n-1] = (s[n-1] == '1') ? true : false;
	one[n-2] = (s[n-2] == '1') ? true : false;

	for(int i=n-3;i>=0;i--){
		if(s[i] == '1'){
			one[i] = one[i+1] || one[i+2];			
		}
	}

	if(zero[n-1] == true || zero[n-2] == true || one[0] == true || one[1] == true){
		cout<<"YES"<<endl;
		return;
	}
	
	for(int i=0;i<n-1;i++){
		if(s[i] == '0' && s[i+1] == '1' && zero[i] && one[i+1]){
			cout<<"YES"<<endl;
			return;
		}
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