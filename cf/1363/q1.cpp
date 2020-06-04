#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
	
	ll n,x;
	cin>>n>>x;

	vector<ll>v;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		v.push_back(vl);
	}

	ll a = 0, b = 0;
	for(ll el : v){
		if(el%2==0){
			a+=1;
		} else {
			b+=1;
		}
	}

	// 1st 2 case 
	if(x <= a){

		if(b!=0){
			cout<<"Yes"<<endl;	
		} else {
			cout<<"No"<<endl;
		}
		
		return;
	}

	if(x > a && x >= b){
		ll odcount = (b % 2 == 1) ? b : b-1;
		if(x - odcount <= a){
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
		return;
	}


	if(x > a && x < b){
		if(x%2==1){
			cout<<"Yes"<<endl;
		} else {
			if(a != 0){
				cout<<"Yes"<<endl;
			} else {
				cout<<"No"<<endl;
			}
		}
	}
}


int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}
