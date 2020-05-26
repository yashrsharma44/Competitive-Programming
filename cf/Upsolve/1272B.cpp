#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	string s;
	cin>>s;

	ll l = 0,r = 0,u = 0,d = 0;
	for(ll i=0;i<s.length();i++){

		if(s[i] == 'L'){
			l++;
		} else if(s[i] == 'U'){
			u++;
		} else if(s[i] == 'R'){
			r++;
		} else {
			d++;
		}
	}

	if(min(l,r) > 0 && min(u,d) > 0){

		ll l_r_count = min(l,r);
		ll u_d_count = min(u,d);

		cout<<2 * (l_r_count + u_d_count)<<endl;

		for(ll i=0;i<u_d_count;i++){
			cout<<"U";
		}

		for(ll i=0;i<l_r_count;i++){
			cout<<"R";
		}

		for(ll i=0;i<u_d_count;i++){
			cout<<"D";
		}

		for(ll i=0;i<l_r_count;i++){
			cout<<"L";
		}
		cout<<endl;

	} else if(min(l,r) > 0){
		cout<<2<<endl;
		cout<<"LR"<<endl;
	} else if(min(u,d) > 0){
		cout<<2<<endl;
		cout<<"UD"<<endl;
	} else {
		cout<<0<<endl;
	}
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}
