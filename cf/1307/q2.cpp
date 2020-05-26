#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
	
	ll n,x;
	cin>>n>>x;

	ll maxNum = -1;
	ll nn = n;

	vector<ll> a;

	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
		maxNum = max(maxNum, vl);
	}

	if(x % maxNum == 0){
		cout<<x/maxNum<<endl;
	} else {

		if(x < maxNum){

			bool check = false;
			ll count = 2;
			for(ll el : a){
				if(x % el == 0){
					// check = true;
					count = min(count, x/el);
					// break;
				}
			}

			cout<<count<<endl;
			return;

		}

		cout<<(x / maxNum) + 1<<endl;
	}

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}