#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	string s;
	cin>>s;

	vector<ll> chr(26,0);
	for(char c : s){
		chr[c-'a'] +=1;
	}

	vector<ll> res;
	while(1){

		if(chr['o'-'a'] >= 1 && chr['n'-'a'] >= 1 && chr['e'-'a'] >= 1){
			res.push_back(1);
			chr['o'-'a']-=1;
			chr['n'-'a']-=1;
			chr['e'-'a']-=1;
		} else if(chr['z'-'a'] >= 1 && chr['e'-'a'] >= 1 && chr['r'-'a'] >= 1 && chr['e'-'a'] >= 1){
			res.push_back(0);
			chr['z'-'a']-=1;
			chr['e'-'a']-=1;
			chr['r'-'a']-=1;
			chr['o'-'a']-=1;
		} else {
			break;
		}
	}

	for(ll el : res){
		cout<<el<<" ";
	}
	cout<<endl;

}

int main(){
	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}