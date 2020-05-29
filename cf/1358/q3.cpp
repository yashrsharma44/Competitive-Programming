#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll NCR(ll n, ll r){

	if(r > n - r){
		r = n - r;
	}

	vector<ll> C(r+1, 0);

	C[0] = 1;

	for(ll i=1;i<=n;i++){
		for(ll j=min(i,r);j>0;j--){
			C[j] = C[j] + C[j-1];
		}
	}

	return C[r];

}

void solve(){

	ll x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;

	cout<<(x2-x1) * (y2-y1)+1<<endl;

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
