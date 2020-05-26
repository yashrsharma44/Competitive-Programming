#include <bits/stdc++.h>
#define ll long long int 

using namespace std;

void solve(){

	ll a1,a2,k1,k2,n;
	cin>>a1>>a2>>k1>>k2>>n;

	if(n < min(k1, k2)){
		cout<<0<<" "<<0<<endl;
		return;
	}

	// Min
	ll minCount = 0;
	ll c1 = (a1 * (k1-1));
	ll c2 = (a2 * (k2-1));

	if(c1 + c2 >= n){
		minCount = 0;
	} else {
		minCount = min((n-c1-c2), a1+a2);
	}

	// Max

	ll maxCount=0;
	ll minTeam = a1;
	ll minCard = k1;

	if(k2 < minCard){
		minCard = k2;
		minTeam = a2;
	}

	maxCount += min(minTeam, n / (minCard));
	n = n - (maxCount  * minCard);

	ll maxTeam = a2;
	ll maxCard = k2;

	if(maxCard < k1){
		maxCard = k1;
		maxTeam = a1;
	}

	maxCount += min(maxTeam, n/ maxCard);

	cout<<minCount<<" "<<maxCount<<endl;

	// // Max
	// pair<ll,ll> minPair = {2000,2000};
	// pair<ll,ll> maxPair= {-1,-1};
	// for(ll i=1;i<=1000;i++){
	// 	for(ll j=1;j<=1000;j++){

	// 		if(n == (i+j)){

	// 			if(minPair.first*k1 + minPair.second*k2 > (i*k1+j*k2)){
	// 				minPair = {i,j};
	// 			}
	// 			if((maxPair.first*k1 + maxPair.second*k2) < (i*k1+j*k2)){
	// 				maxPair = {i,j};
	// 			}
	// 		}

	// 	}
	// }

	// cout<<(minPair.first+minPair.second)<<" "<<(maxPair.first+maxPair.second)<<endl;

	
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