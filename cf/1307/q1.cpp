#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,d;
	cin>>n>>d;

	vector<ll> a;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;

		a.push_back(vl);
	}

	ll maxNum = a[0];
	
	for(ll i=1;i<n;i++){

		while(a[i] > 0){

			if(d >= i){
				maxNum+=1;
				d=d-i;
				a[i]-=1;
			} else {
				break;
			}

		}

	}

	cout<<maxNum<<endl;

	

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}