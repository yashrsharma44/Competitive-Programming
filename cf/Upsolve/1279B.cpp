#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,s;
	cin>>n>>s;

	vector<ll> a;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}


	// Lets find the elements whose sum just exceeds the total time
	// Then removing the biggest number should give us the max number of 
	// verse

	ll curSum = 0;
	ll ind = -1;
	for(ll i=0;i<n;i++){

		curSum += a[i];
		if(curSum > s){

			ind = i;
			break;
		}
	}

	ll maxInd = -1;
	ll maxNum = -1;

	for(ll i=0;i<=ind;i++){

		if(a[i] > maxNum){
			maxNum = a[i];
			maxInd = i;
		}
	}

	cout<<(maxInd + 1)<<endl;

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}