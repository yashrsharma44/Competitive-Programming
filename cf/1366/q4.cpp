#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int n;
	cin>>n;
	vector<int> a;
	int nn = n;
	while(nn--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}

	set<int> primes;
	primes.insert({2,3,5,7,11,13,17,19,23,29,31,37,41});
	map< int, vector<int> >mp;
	for(int el : a){

		int elem = el;
		for(int i=2;i*i<=(1000000);i++){
			if(elem % i == 0){
				mp[el].push_back(i);
				while(elem%i==0){
					elem = elem / i;
				}
			}
		}

	}
	vector<int> d1, d2;
	for(int el : a){

		vector<int> vv = mp[el];
		int dd1 = -1, dd2 = -1;
		for(int i=0;i<vv.size();i++){
			for(int j=i+1;j<vv.size();j++){
				if(primes.find(vv[i]+vv[j]) != primes.end()){
					dd1 = vv[i];
					dd2 = vv[j];
				}
			}
		}

		if(dd1 == -1 || dd2 == -1){
			d1.push_back(-1);
			d2.push_back(-1);
		} else {
			d1.push_back(dd1);
			d2.push_back(dd2);
		}

	}

	for(int el : d1){
		cout<<el<<" ";
	}
	cout<<endl;
	for(int el : d2){
		cout<<el<<" ";
	}
	cout<<endl;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
