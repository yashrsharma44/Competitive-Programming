#include <bits/stdc++.h>
#define ll long long int

using namespace std;

struct Comparer {
    bool operator() (const pair<bitset<60>,ll> &b1, const pair<bitset<60>,ll> &b2){
        return b1.first.to_ulong() < b2.first.to_ulong();
    }
};

string decToBin(ll num){

	string ans = "";
	while(num > 0){
		if(num % 2 == 0){
			ans+="0";
		} else {
			ans+="1";
			
		}
		num /= 2;
	}

	return ans;
}

int main(){

	ll n;
	cin>>n;

	vector < bitset<60> > a;
	ll nn = n;
	while(nn--){
		ll s;
		cin>>s;

		a.push_back(bitset<60>(decToBin(s)));
	}

	vector<ll> b;

	nn = n;
	while(nn--){
		ll vl;
		cin>>vl;

		b.push_back(vl);
	}

	vector < pair< bitset<60>, ll > > res;
	for(ll i=0;i<n;i++){
		res.push_back(make_pair(a[i], i));
	}

	set < pair<bitset<60> , ll>, Comparer >mp;

	for(pair< bitset<60>, ll > el : res){
		mp.insert(el);
	}

	ll sum = 0;
	for(pair< bitset<60>, ll > el : mp){
		sum += b[el.second];
	}

	cout<<sum<<endl;


}