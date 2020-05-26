#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;
	string s;
	cin>>s;

	vector<ll> visited(n, 0);
	ll count = 0;
	for(ll i=25;i>0;i--){

		for(ll j=0;j<s.length();j++){

			if((s[j] - 'a' == i)){
				if((j>0 && (s[j-1] - 'a' == i-1)) || (j<n && (s[j+1] - 'a' == i-1))){
					visited[j] = 1;
				}
			}
		}

		string ss="";
		for(ll i=0;i<s.length();i++){
			if(!visited[i]){
				ss += s[i];
			}
		}

		s = ss;
		vector<ll> vs(s.length(),0);
		visited = vs;
		// cout<<ss<<endl;
		// if(s[0] == 1 + s[1]){
		// 	visited[0] = 1;
		// }

		// if(s[n-1] == s[n-2] + 1){
		// 	visited[n-1] = 1;
		// }

	}
	cout<<s<<endl;
	cout<<n - s.length()<<endl;

}

int main(){

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}