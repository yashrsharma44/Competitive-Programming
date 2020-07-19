#include <bits/stdc++.h>
#define MOD 998244353
#define int long long 

using namespace std;

int dfs(string s, int i){

	// if(s.length() == 0){
	// 	return 0;
	// }

	char cc = (char)('a'+i);
	if(s.length() == 1){
		if(s[0] == cc){
			return 0;
		}
		return 1;
	}
	int n = s.length();
	int l = dfs(s.substr(0,n/2), i+1);
	int r = dfs(s.substr(n/2), i+1);

	int c1 = 0,c2=0;
	for(int j=0;j<n/2;j++){
		if(s[j] != cc){
			c1++;
		}
	}

	for(int j=n/2;j<n;j++){
		if(s[j]!=cc){
			c2++;
		}
	}
	int cost = min({c1+l, c1+r, c2+l, c2+r});
	cout<<s<<" "<<cost<<endl; 
	cout<<c1+l<<" "<<c1+r<<" "<<c2+l<<" "<<c2+r<<endl;
	cout<<"-----------"<<endl;
	return cost;
}


void solve(){

	int n;
	cin>>n;
	string s;
	cin>>s;
	int i = 0;
	int cost = dfs(s, i);
	cout<<cost<<endl;
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
