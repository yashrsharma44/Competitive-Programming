#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	string s;
	cin>>s;

	ll minSum = 0;
	ll maxSum = 0;

	for(ll i=0;i<n/2;i++){

		if(s[i] != '?'){
			minSum += (s[i] - '0');
		}
	}

	for(ll i=n/2;i<n;i++){

		if(s[i] != '?'){
			minSum -= (s[i] - '0');
		} else {
			minSum -= 9;
		}
	}

	for(ll i=0;i<n/2;i++){

		if(s[i] != '?'){
			maxSum += s[i] - '0';
		} else {
			maxSum += 9;
		}
	}	

	for(ll i=n/2;i<n;i++){

		if(s[i] != '?'){
			maxSum -= s[i] - '0';
		}
	}

	if(maxSum + minSum == 0){
		cout<<"Bicarp"<<endl;
	} else {
		cout<<"Monocarp"<<endl;
	}

}

int main(){

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}

}