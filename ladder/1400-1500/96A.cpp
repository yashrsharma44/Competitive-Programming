#include <bits/stdc++.h>
#define int long long 

using namespace std;
#define MAX 1000005

void solve(){

	string s; cin>>s;
	int count = 1;
	for(int i=1;i<s.length();i++){
		if(s[i] == s[i-1]) count++;
		else {
			if(count >= 7) {
				cout<<"YES"<<endl;
				return;
			} 
			count = 1;
		}
	}
	if(count >= 7) {
		cout<<"YES"<<endl;
		return;
	}
	cout<<"NO"<<endl;
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
