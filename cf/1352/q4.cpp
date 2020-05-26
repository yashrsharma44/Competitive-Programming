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

	ll alice=0, bob=0;
	ll p1=0,p2=n-1;
	ll turn=0, steps=0;

	if(n == 1){
		cout<<1<<" "<<arr[0]<<" "<<0<<endl;
		return;
	}

	ll local_alice=0,local_bob=0;
	while(arr.size()>0){

		if(turn % 2 == 0){
			int ct=0;
			local_alice = 0;
			while(arr.size()>0 && local_alice <= local_bob){
				alice+=arr[0];
				local_alice +=arr[0];
				arr.erase(arr.begin());
				ct=1;
			}
			steps+=ct;	
			turn=1;
		} else {
			int ct=0;
			local_bob = 0;
			while(arr.size()>0 && local_alice >= local_bob){
				bob+=arr[arr.size()-1];
				local_bob+=arr[arr.size()-1];
				arr.erase(arr.begin()+arr.size()-1);
				ct=1;
			}
			steps+=ct;
			turn=0;
		}
	}
	cout<<steps<<" ";
	cout<<alice<<" ";
	cout<<bob<<endl;
	
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