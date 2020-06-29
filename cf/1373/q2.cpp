#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	string s;
	cin>>s;
	int c1 = 0, c0 = 0;
	for(char c : s){
		if(c == '0'){
			c0+=1;
		} else {
			c1+=1;
		}
	}

	int ans = min(c0, c1);
	int aa = ans % 2;
	if(aa == 0){
		cout<<"NET"<<endl;
	} else {
		cout<<"DA"<<endl;
	}

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
