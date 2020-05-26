#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n,m,p;
	cin>>n>>m>>p;

	vector < ll > a;
	ll nn =  n;
	ll mm  = m;

	ll ctr = 0;
	bool alleven = true;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	vector < ll > b;
	ctr = 0;

	while(mm--){
		ll vl;
		cin>>vl;
		b.push_back(vl);
	}

	// Choose an element in a and b such that both are not divisible by p
	ll pow1 = -1;
	ll pow2 = -1;

	for(ll i=0;i<n;i++){
		if(a[i] % p != 0){
			pow1 = i;
			break;
		}
	}

	for(ll i=0;i<m;i++){
		if(b[i] % p != 0){
			pow2 = i;
			break;
		}
	}

	cout<<pow1+pow2<<endl;
}