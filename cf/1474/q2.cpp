#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

vector<int> ans;

void solve(){

	int d; cin>>d;
	int n1 = 1;
	int it = 0;
	while(ans[it] - n1 < d){
		it++;
	}
	int n2 = ans[it];
	while(ans[it] - n2 < d){
		it++;
	}
	int n3 = ans[it];
	// int n4 = n3*n2;
	cout<<(n1*n2*n3)<<endl;

}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> primes(100000, true);

	for(int i=2;i*i<=100000;i++){
		if(primes[i]){
			for(int j=i*i;j<=100000;j+=i){
				primes[j] = false;
			}
		}
	}
	ans.clear();
	ans.push_back(1);
	for(int i=2;i<=100000;i++){
		if(primes[i])ans.push_back(i);
	}


	int t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}
