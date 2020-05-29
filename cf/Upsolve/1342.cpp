#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll query(ll l, vector<ll> arr){

	ll len = arr.size()-1;

	ll k = l / len;
	ll rem = l % len;

	return (arr[len] * k) + arr[rem];

}

void solve(){

	ll a,b,q;
	cin>>a>>b>>q;

	// build the array
	ll len = (a*b);
	vector<ll> arr(len+1, 0);

	for(ll i=1;i<=len;i++){

		if(((i%a)%b) != ((i%b)%a)){
			arr[i] = arr[i-1] + 1;
		} else {
			arr[i] = arr[i-1];
		}
	}

	while(q--){

		ll l,r;
		cin>>l>>r;
		ll v = (query(r, arr) - query(l-1, arr));
		cout<<v<<" ";
	}
	cout<<endl;

		
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
