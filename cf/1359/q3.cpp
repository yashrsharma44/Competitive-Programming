#include <bits/stdc++.h>
#define ll long long int

using namespace std;

double sm(ll h, ll c, ll k){

	return ((k*h) + (k-1.0)*c) / (2*k-1.0);
}

void solve(){
	
	double h,c,t;
	cin>>h>>c>>t;

	if(2*t <= (h+c)){
		cout<<2<<endl;
		return;
	}

	ll k2 = ceil((c - t) / (h + c - (2*t)));
	ll k1 = floor((t - h) / (h + c - (2*t)));
	k1 = max(1LL, k1);
	ll ans = -1;
	double mindiff = INT_MAX;
	for(ll i=k1;i<=k2;i++){

		double diff = sm(h,c,i);
		if(abs(diff-t) < mindiff){
			mindiff = abs(diff-t);
			ans = 2*i-1;
		}
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
