#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll func(ll n, ll k){
	return (n*(n+1) / 2) - k;
}

ll bin_search(ll start, ll end, ll k){

	ll lp = start;
	ll rp = end;

	while(lp +1 < rp){

		// if(lp == rp){
		// 	break;
		// }

		ll mid =(lp + rp) / 2;
		if(func(mid, k) >= 0){
			rp = mid-1;
		} else {
			lp = mid;
		}
	}

	return rp;

}

void solve(){

	ll n,k;
	cin>>n>>k;

	ll sum = 0;
	ll j = -1;
	ll i = 1;
	for(;i<=n;i++){

		if(sum + i > k){
			j = k - sum;
			break;
		} else {
			sum += i;
		}
	}

	if(j == 0){
		i -= 1;
		j = i;
	}

	// cout<<i<<" "<<j<<endl;
	string ans(n,'a');
	ans[n - 1 - i] = 'b';
	ans[n - j]  = 'b';
	cout<<ans<<endl;

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}