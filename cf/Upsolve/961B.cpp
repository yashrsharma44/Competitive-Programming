#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	ll n,k;
	cin>>n>>k;

	vector<ll> arr;
	ll nn = n;
	while(nn--){

		ll vl;
		cin>>vl;
		arr.push_back(vl);
	}

	vector<ll> t;
	nn = n;

	while(nn--){

		ll vl;
		cin>>vl;
		t.push_back(vl);
	}

	ll active_time = 0;

	vector<ll> pre_time(n,0);

	for(ll i=0;i<n;i++){

		if(t[i]!=0){
			active_time += arr[i];
			// arr[i] = 0;
		} else {
			pre_time[i] = arr[i];
			
		}
		if(i!=0)pre_time[i] += pre_time[i-1];
	}

	ll max_active = pre_time[k-1];

	for(ll i=k;i<n;i++){
		max_active = max(max_active, pre_time[i] - pre_time[i-k]);
	}

	cout<<max_active+active_time<<endl;

}
