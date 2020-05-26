#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool comp(pair<ll,ll> &p1, pair<ll,ll> &p2){

	if(p1.second != p2.second){
		return p1.second < p2.second;
	}

	return p1.first > p2.first;

}

ll getPow(ll n){

	if(n == 1){
		return 1;
	}
	ll count = 0;

	while(n!=0){
		n >>= 1;
		count +=1;

	}

	return (count);
}

int main(){

	ll n;
	cin>>n;

	vector< pair<ll, ll> > arr;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;

		if(vl == 1){
			arr.push_back(make_pair(1, -1));
		} else if(vl != 0 ){

			ll diff = INT_MAX;
			ll nearExp = getPow(vl);

			ll num1 = (ll)(pow(2, nearExp));
			ll num2 = (ll)(pow(2, nearExp - 1));

			if(abs(num2 - vl) <= diff){
				diff = (vl - num2);
			}

			if(abs(num1 - vl) < diff){
				diff = vl - num1;
			}
			arr.push_back(make_pair(vl, diff));

		} else {
			arr.push_back(make_pair(vl, 0));
		}

	}



	sort(arr.begin(), arr.end(), comp);

	for(ll i=0;i<n;i++){
		cout<<arr[i].first<<" ";
	}
	cout<<endl;

}