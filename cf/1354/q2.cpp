#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool check(map<char,int> mp){

	return mp['1'] > 0 && mp['2'] > 0 && mp['3'] > 0;

}

void solve(){

	string s;
	cin>>s;

	ll minLen = INT_MAX;
	map<char,int> mp;
	ll p1=0,p2=0;

	for(;p2<s.length();p2++){

		char c = s[p2];
		mp[c] += 1;

		while(check(mp)){

			minLen = min(minLen, p2 - p1 + 1);
			char cc = s[p1];
			if(mp.count(cc) > 0){
				mp[cc] -= 1;
			} else {
				break;
			}
			p1++;
		}
	}

	if(check(mp)){
		minLen = min(minLen, p2 - p1 + 1);
	}
	if(minLen == INT_MAX){
		cout<<0<<endl;
	} else {
		cout<<minLen<<endl;
	}


}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}
