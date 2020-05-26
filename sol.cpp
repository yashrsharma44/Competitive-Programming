#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;

ll binomialCoeff(ll n, ll k) 
{ 
    ll C[n + 1][k + 1]; 
    ll i, j; 
  
    // Calculate value of Binomial Coefficient in bottom up manner 
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= min(i, k); j++) { 
            // Base Cases 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
  
            // Calculate value using previously stored values 
            else
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD; 
        } 
    } 
  
    return C[n][k] % MOD; 
} 

// void solve(){

	
// }

int main(){

	ll t;
	cin>>t;

	while(t--){
		ll n,l;
		cin>>n>>l;

		if(n%2!=0){
			cout<<0<<endl;
			// return;
		} else {

			ll count = n / 2;
			if(l != 2){
				cout<<(binomialCoeff(count,l/2) % (1000000000+7))<<endl;
			} else {
				cout<<1<<endl;
			}
		}
	}

	return 0;
}