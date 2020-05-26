#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	if((n / 2) % 2 == 1){
		cout<<"NO"<<endl;
		return;
	}

	ll k=2;
	ll sum=0;
	vector<ll> arr(n,0);
	for(ll i=0;i<n/2;i++){
		arr[i] = k;
		sum+=k;
		k+=2;

	}

	k = 1;
	ll oddSum = 0;
	for(ll i=n/2;i<n;i++){	
		
		if(i == n-1){
			arr[i] = sum - oddSum; 
		} else {
			arr[i] = k; 
			oddSum += k;
		}
		k+=2;
	}
	cout<<"YES"<<endl;
	for(ll el : arr){
		cout<<el<<" ";
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
