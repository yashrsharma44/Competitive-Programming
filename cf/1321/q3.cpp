#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
	
	ll n;
	cin>>n;
	string s;
	cin>>s;

	for(ll i=25;i>0;i--){

		for(ll j=0;j<s.length();j++){

			if(s[j] == 'a'+i && (s[j+1] == 'a'+i-1 || s[j-1] == 'a'+i-1)){
				s.erase(s.begin()+i);
			}

		}

	}

	ll count=0;
	for(char c : s){
		if(c == '#'){
			count++;
		}
	}

	cout<<count<<endl;

}

int main(){

	ll t;
	// cin>>t;
	t=1;

	while(t--){
		solve();
	}
}