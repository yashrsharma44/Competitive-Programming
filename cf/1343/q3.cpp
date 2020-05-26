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

	ll currMax = LLONG_MIN;

	ll prevSign = arr[0] > 0 ? 1 : -1;
	ll sum = 0;
	for(ll i=0;i<n;i++){

		if((arr[i] >= 0 && prevSign >= 0) || (arr[i] < 0 && prevSign < 0)){
			currMax = max(currMax, arr[i]);
			prevSign = arr[i] > 0 ? 1 : -1;
		} else {
			sum += currMax;
			currMax = arr[i];
			prevSign = arr[i] > 0 ? 1 : -1;
		}
	}

	sum+=currMax;

	cout<<sum<<endl;

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
