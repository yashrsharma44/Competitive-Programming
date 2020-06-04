#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
	
	string s;
	cin>>s;

	ll n = s.length();
	
	vector<string> vv;
	string ss="";
	char prev = s[0];

	for(ll i=0;i<n;i++){

		if(prev == s[i]){
			ss+=s[i];
		} else {
			vv.push_back(ss);
			ss=s[i];
			prev = s[i];
		}
	}
	vv.push_back(ss);

	if(vv.size() <= 2){
		cout<<0<<endl;
		return;
	}

	ll ans = INT_MAX;
	ll l1 = vv[0].length();
	ll l2 = vv[1].length();
	ll l3 = 0;
	for(ll i=2;i<vv.size();i++){
		if(vv[i][0] == vv[1][0]){
			continue;
		}
		l3 += vv[i].length();
	}

	ans = min(ans, l3);
	l3=0;
	for(ll i=vv.size()-3;i>=0;i--){
		if(vv[i][0] == vv[vv.size()-2][0]){
			continue;
		}
		l3 += vv[i].length();
	}

	ans = min(ans, l3);
	cout<<ans<<endl;
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
