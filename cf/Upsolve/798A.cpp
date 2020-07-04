#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	string s;
	cin>>s;

	int count = 0;
	int p1 = 0, p2 = s.length()-1;
	while(p1 < p2){

		if(s[p1] != s[p2]){
			count++;
		}
		p1++;
		p2--;
	}
	if(count == 1 || count == 0 && s.length()%2==1){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
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
