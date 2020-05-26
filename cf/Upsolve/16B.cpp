#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool comp(pair<ll,ll> &p1, pair<ll,ll> &p2){

	if(p1.second != p2.second){
		return p1.second > p2.second;
	}

	return p1.first < p2.first;
}

int main(){

	ll n,m;
	cin>>n>>m;

	vector< pair<ll,ll> > ab;
	ll mm = m;
	while(mm--){
		ll v1,v2;
		cin>>v1>>v2;

		ab.push_back(make_pair(v1,v2));
	}

	sort(ab.begin(), ab.end(),comp);

	ll totalCount=0;
	for(pair<ll,ll> el : ab){
		if(el.first <= n){
			totalCount += (el.first * el.second);
		} else {
			totalCount +=(n * el.second);
			break;
		}
		n-=el.first;
	}

	cout<<totalCount<<endl;
}