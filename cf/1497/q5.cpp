#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

#define MAXN 10000005

int spf[MAXN];

void sieve(){
	spf[1] = 1;
	for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 

int canonical(int el){
	vector<int> fact = getFactorization(el);
	int ans = 1;
	for(auto f : fact){
		int cnt = 0;
		while(el % f == 0){
			cnt += 1;
			el /= f;
		}
		ans *= (cnt % 2 == 0 ? 1 : f);
	}
	return ans;
}

void solve(){

	int n,k; cin>>n>>k;
	vector<int> aa;
	for(int i=0;i<n;i++){
		int a; cin>>a;
		a = canonical(a);
		aa.push_back(a);
	}

	set<int> elems;
	int  count = 0;
	for(auto el : aa){
		if(elems.count(el) > 0){
			elems.clear();
			count+=1;
		}
		elems.insert(el);
	}

	cout<<count+1<<endl;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sieve();
	int t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}