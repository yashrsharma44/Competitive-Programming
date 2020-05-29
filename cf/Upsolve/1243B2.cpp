#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	string s,t;
	cin>>s>>t;

	vector<ll> chr(26,0);
	for(char c : s){
		chr[c-'a']+=1;
	}
	for(char c : t){
		chr[c - 'a']+=1;
	}
	for(ll i=0;i<26;i++){
		if(chr[i] % 2 != 0){
			cout<<"No"<<endl;
			return;
		}
	}

	vector < pair<char,ll> > v1, v2;
	vector < pair<ll,ll> > ans;


	for(ll i=0;i<s.length();i++){

		if(s[i] != t[i]){

			for(ll j=i+1;j<t.length();j++){

				if(s[i] == s[j]){
					ans.push_back(make_pair(j+1, i+1));
					swap(s[j], t[i]);
					break;	
				} 
				
				if(t[i] == t[j]){
					ans.push_back(make_pair(i+1, j+1));
					swap(t[i], t[j]);
					break;
				}

				if(s[i] == t[j]){
					ans.push_back(make_pair(j+1, j+1));
					ans.push_back(make_pair(j+1, i+1));
					swap(s[j], t[j]);
					swap(s[j], t[i]);
					break;
				}

				
				if(t[i] == s[j]){
					ans.push_back(make_pair(j+1, j+1));
					ans.push_back(make_pair(i+1, j+1));
					swap(t[j], s[j]);
					swap(t[i], s[j]);
					break;
				}
			}
		}
	}
	
	// cout<<s<<" "<<t<<endl;
	cout<<"Yes"<<endl;
	cout<<ans.size()<<endl;
	for(auto el : ans){
		cout<<el.first<<" "<<el.second<<endl;
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
