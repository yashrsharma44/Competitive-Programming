#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){


	ll n;
	cin>>n;
	string a,b;
	cin>>a>>b;

	vector<ll> c1(26,0), c2(26,0);
	for(char c : a){
		c1[c-'a']+=1;
	}
	for(char c : b){
		c2[c - 'a']+=1;
	}

	for(ll i=0;i<26;i++){
		if(c1[i] == 0 && c2[i] != 0){
			cout<<-1<<endl;
			return;
		}
	}

	map<char, vector<ll> >mp;
	for(ll i=0;i<a.length();i++){
		mp[a[i]].push_back(i);
	}
	// ll n = a.length();
	vector< vector<ll> >ans;
	for(ll i=0;i<n;i++){
		if(a[i] != b[i]){
			if(b[i] > a[i]){
				cout<<-1<<endl;
				return;
			} 
		}
	}

	for(ll i=0;i<n;i++){
		if(a[i] != b[i]){
			vector<ll>idx;
			idx.push_back(i);
			if(mp[b[i]].size() == 0){
				cout<<-1<<endl;
				return;
			}
			idx.push_back(mp[b[i]][0ll]);
			ans.push_back(idx);
		}
	}
	
	cout<<ans.size()<<endl;
	for(auto el : ans){
		cout<<el.size()<<" ";
		for(auto e : el){
			cout<<e<<" ";
		}
		cout<<endl;
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
