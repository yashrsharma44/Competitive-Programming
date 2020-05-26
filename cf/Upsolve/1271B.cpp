#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll n;
	cin>>n;
	string s;
	cin>>s;

	// Use a substring to check consecutive 3 / 4 chars
	vector<ll> pos;
	bool isPos = true;

	if(s[0] != 'W'){
		s[0] = 'W';
		s[1] = (s[1] == 'B') ? 'W' : 'B';
		pos.push_back(0);
	}

	for(ll i=1;i<n-1;i++){

		if(s[i] != 'W'){
			pos.push_back(i);
			s[i] = 'W';
			s[i+1] = (s[i+1] == 'B') ? 'W' : 'B';
		}
	}

	if(s[n-1] == 'B'){
	
		if(s[0] != 'B'){
			s[0] = 'B';
			s[1] = (s[1] == 'W') ? 'B' : 'W';
			pos.push_back(0);
		}

		for(ll i=1;i<n-1;i++){

			if(s[i] != 'B'){
				pos.push_back(i);
				s[i] = 'B';
				s[i+1] = (s[i+1] == 'W') ? 'B' : 'W';
			}
		}	

		if(s[n-1] == 'W'){
			cout<<-1<<endl;
		} else {
			cout<<pos.size()<<endl;
			for(ll el : pos){
				cout<<el+1<<" ";
			}
			cout<<endl;
		}
	} else {
		cout<<pos.size()<<endl;
		for(ll el : pos){
			cout<<el+1<<" ";
		}
		cout<<endl;
	}

}

int main(){

	ll t;
	// cin>>t;
	t = 1;
	while(t--){
		solve();
	}
}