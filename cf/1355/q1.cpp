#include <bits/stdc++.h>
#define ll long long int

using namespace std;


ll getMax(ll n){

	string s="";
	while(n>0){
		s +=to_string(n%10);
		n =n/10;
	}
	ll maxN = 0;
	for(char c : s){

		maxN =  max(maxN, (ll)(c-'0'));
	}

	return maxN;

}

ll getMin(ll n){

	string s="";
	while(n>0){
		s +=to_string(n%10);
		n =n/10;
	}
	ll minN = 9;
	for(char c : s){

		minN =  min(minN, (ll)(c-'0'));
	}

	return minN;

}

void solve(){

	ll a,k;
	cin>>a>>k;
	ll ans=a;

	for(ll i=0;i<k-1;i++){
		ll mn = getMin(ans);
		ll mx = getMax(ans);

		if(mn == 0){
			break;
		}
		ans = ans + mn * mx;
	}

	cout<<ans<<endl;
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
