#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> arr;
	ll nn = 2 * n;

	while(nn--){
		ll vl;
		cin>>vl;
		arr.push_back(vl);
	}

	sort(arr.begin(), arr.end());

	cout<<abs(arr[n-1] - arr[n])<<endl;
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}