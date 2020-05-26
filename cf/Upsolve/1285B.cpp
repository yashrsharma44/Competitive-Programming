#include<bits/stdc++.h>
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

	// Lets find a subarray which has a sum > yassers val, if not then we can return 
	// yasser is happy

	ll total_sum = 0;
	for(ll el : arr){
		total_sum += el;
	}

	// Max subarray sum in (1,n-1) or (2, n)
	ll local_sum = 0;
	ll global_sum = -1;

	for(ll i=0;i<n-1;i++){

		local_sum += arr[i];
		ll el = arr[i];
		
		global_sum = max(global_sum, local_sum);
		
		if(local_sum < 0){
			local_sum = 0;
		}
	}

	ll local_sum1 = 0;
	ll global_sum1 = -1;

	for(ll i=1;i<n;i++){

		local_sum1 += arr[i];
		ll el = arr[i];
		
		global_sum1 = max(global_sum1, local_sum1);
		if(local_sum1 < 0){
			local_sum1 = 0;
		}
	}	

	if(total_sum > global_sum1 && total_sum > global_sum){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}