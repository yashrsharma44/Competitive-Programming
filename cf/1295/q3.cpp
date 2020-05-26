
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	string s,t;
	cin>>s>>t;

	ll i=1;
	map<char,ll> mp;
	for(char c : s){
		mp[c] = i++;
	}
	vector<ll> v;
	for(char c : t){

		if(mp.count(c) > 0){
			v.push_back(mp[c]);
		} else {
			cout<<-1<<endl;
			return;
		}
	}

	ll count=1;
	for(ll i=1;i<t.length();i++){

		if(v[i] > v[i-1]){
			continue;
		} else {
			count++;
		}
	}

	cout<<count<<endl;

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}