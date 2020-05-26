#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
	
	ll n;
	cin>>n;

	vector<ll> m;

	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		m.push_back(vl);
	}

	ll maxInd = 0;
	ll ctr=0;
	// Find max index
	// for(ll el : m){

	// 	if(el > m[maxInd]){
	// 		maxInd = ctr;
	// 	}
	// 	ctr++;
	// }

	unordered_map<ll,vector<ll> > mp;
	ll maxSum = 0;
	for(maxInd = 0;maxInd<n;maxInd++){
		vector<ll> minArray(n, INT_MAX);
	// leftMin[maxInd-1] = m[maxInd-1];
		for(ll i=maxInd-1;i>=0;i--){
			minArray[i] = min(minArray[i+1], m[i]);
		}
		minArray[maxInd] = m[maxInd];
		for(ll i=maxInd+1;i<n;i++){
			minArray[i] = min(minArray[i-1],m[i]);
		}

		ll sum = 0;
		for(ll el : minArray){
			sum+=el;
		}		
		maxSum = max(maxSum, sum);
		mp[sum] = minArray;		
	}

	// vector<ll> minArray(n, INT_MAX);
	// // leftMin[maxInd-1] = m[maxInd-1];
	// for(ll i=maxInd-1;i>=0;i--){
	// 	minArray[i] = min(minArray[i+1], m[i]);
	// }
	// minArray[maxInd] = m[maxInd];
	// for(ll i=maxInd+1;i<n;i++){
	// 	minArray[i] = min(minArray[i-1],m[i]);
	// }

	ll floor = 0;
	for(ll el : mp[maxSum]){
		cout<<el<<" ";
	}
	cout<<endl;

}

int main(){

	ll t;
	// cin>>t;
	t = 1;
	while(t--){
		solve();
	}

}