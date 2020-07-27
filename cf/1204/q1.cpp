#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){
	
	string s;
	cin>>s;
	int len = s.length();
	if(len == 1){
		cout<<0<<endl;
		return;
	}
	if(len == 2){
		cout<<1<<endl;
		return;
	}
	int ans = 0;
	if(len % 2 == 1){
		ans = (len+1) / 2;
		bool allZero = true;
		for(int i=1;i<len;i++){
			if(s[i] == '1'){
				allZero = false;
				break;
			}
		}
		if(allZero){
			ans-=1;
		}
	} else {
		ans = (len+1)/2;
	}
	
	cout<<ans<<endl;
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
