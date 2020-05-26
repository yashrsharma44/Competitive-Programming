#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,a,b;
	cin>>n>>a>>b;

	// ll times = a / b;
	// ll last = (b - a%b);

	// vector<char> ans;
	string s="";
		
	for(ll i=0;i<a;i++){
		char c = 'a' + (i%b);
		s+=c;
	}
	string ss = "";
	for(ll i=0;i<n;i++){
		ss+= s[i % a];
	}

	cout<<ss<<endl;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}