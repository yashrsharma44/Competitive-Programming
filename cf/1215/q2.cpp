#include <bits/stdc++.h>
#define ll long long int 

using namespace std;

void solve(){
	ll n;
	cin>>n;

	vector<ll> arr;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		arr.push_back(vl);
	}

	vector<ll> prefixProduct(n, 1);
	prefixProduct[0] = (arr[0] > 0) ? 1 : -1;

	for(ll i=1;i<n;i++){
		prefixProduct[i] = (arr[i] > 0 ? 1 : -1)* prefixProduct[i-1];
	}

	ll countPositive=1, countNegative=0;

	for(ll el : prefixProduct){
		if(el > 0){
			countPositive+=1;
		} else {
			countNegative+=1;
		}
	}

	cout<<(countPositive*countNegative)<<" ";
	cout<<((n*(n+1) / 2) - countPositive*countNegative)<<endl;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}

}