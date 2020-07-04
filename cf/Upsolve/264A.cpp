#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	string s;
	cin>>s;
	int l = s.length();
	for(int i=0;i<l;i++){
		if(s[i] == 'r'){
			printf("%lld\n",(i+1));
		}
	}
	for(int i=l-1;i>=0;i--){
		if(s[i] == 'l'){
			printf("%lld\n",(i+1));
		}
	}


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
