#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;
	ll count=0;
	vector<ll> nums;
	while(n>0){

		string dg = to_string(n%10);
		for(int i=0;i<count;i++){
			dg +="0";
		}
		ll nm = stoll(dg);
		if(nm!=0){
			nums.push_back(nm);
		}
		count++;
		n/=10;
	}
	cout<<nums.size()<<endl;
	for(ll el : nums){
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

	

	while(t--){
		solve();
	}
}