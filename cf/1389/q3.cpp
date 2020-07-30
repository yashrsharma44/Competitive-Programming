#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){
	
	string s;
	cin>>s;
	int n = s.length();
	string s1 = s.substr(1)+s[0];
	string s2 = s[n-1] + s.substr(0,n-1);
	if(s1 == s2){
		cout<<0<<endl;
		return;
	}
	vector<int> cc(10, 0);
	for(char c : s){
		cc[c-'0']+=1;
	}
	int mx = 0;
	for(int i=0;i<9;i++){
		mx = max(mx, cc[i]);
	}
	if(mx == 1){
		cout<<n-2<<endl;
		return;
	}
	cout<<(n-mx)<<endl;
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
