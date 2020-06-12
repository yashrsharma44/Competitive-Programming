#include <bits/stdc++.h>
#define int long long 

using namespace std;

void fillPrime(vector<int> &prime){

	// Using sieve, in O(n) time and returning the smallest prime factor
	for(int i=1;i<=10000000;i++){
		prime[i] = i;
	}

	for(int i=2;i*i<=10000000;i++){

		if(prime[i] == i){
			for(int j=i*i;j<=10000000;j+=i){

				if(prime[j] == j){
					prime[j] = i;
				}
			}
		}

	}

}

set<int> primefactor(vector<int> prime, int num){

	set<int> pfactor;

	while(num!=1){
		pfactor.insert(prime[num]);
		num /= prime[num];
	}
	return pfactor;

}


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

	vector<int> prime(10000000 + 10, -1);
	fillPrime(prime);

	// map< int, set<int> >mp;
	// for(int el : a){

	// 	// The current implementation takes O(sqrt(n)) for each number
	// 	// We need a O(logN) implementation
		
	// }

	vector<int> d1, d2;
	for(int el : a){

		set<int> vv = primefactor(prime,el);
		vector<int> fc;
		for(int elw : vv){
			fc.push_back(elw);
		}

		if(fc.size() <= 1){
			d1.push_back(-1);
			d2.push_back(-1);
			continue;
		}

		int p1 = fc[fc.size()-1];
		int p2 = 1;

		for(int i=0;i<fc.size()-1;i++){
			p2 *= fc[i];
		}

		d1.push_back(p1);
		d2.push_back(p2);


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
