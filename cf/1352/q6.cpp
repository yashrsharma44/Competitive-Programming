#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> a;
	ll nn = n;

	vector<ll> cnt(n+1,0);
	while(nn--){

		ll vl;
		cin>>vl;
		a.push_back(vl);
		cnt[vl]++;
	}
	ll count=0;

	ll sum=0;
	for(ll l=0;l<n;l++){
		sum=0;
		for(ll r=l;r<n;r++){
			sum+=a[r];
			if(r == l){
				continue;
			} 
			if(sum <= n){
				count += cnt[sum];
				cnt[sum] = 0;
				// sum = 0;
			}
		}
	}
	

	cout<<count<<endl;

}

int main(){

	ll t;
	cin>>t;
	// t = 1;
	while(t--){
		solve();
	}

}