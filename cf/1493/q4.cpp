#include <bits/stdc++.h>
#define int long long
using namespace std;

#define MAX 1000005
#define MAXN 200005

int spf[MAXN];

void seive() {
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++) {
        // checking if i is prime
        if (spf[i] == i) {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j < MAXN; j += i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<int> getFactorization(int x) {
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

void solve() {
    seive();

    int MOD = 1000000007;
    vector<map<int, int> > mp;
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<vector<int>> quer;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i=0;i<q;i++){
    	int u, v; cin>>u>>v;
    	quer.push_back({u, v});
    }

    map<int, multiset<int>> primes;
    for(int i=0;i<n;i++){
    	int el = a[i];
    	vector<int> fact = getFactorization(el);
    	mp[i] = map<int,int>();
    	for(auto f: fact){
    		int count = 0;
    		while(el % f == 0){
    			el /= f;
    			count+=1;
    		}
    		if(count != 0){
	    		primes[f].insert(count);
    			mp[i][f] = count;
    		}
    	}
    }

    for(auto qq : quer){
    	int i = qq[0]-1;
    	int val = qq[1];

    	vector<int> fact = getFactorization(val);
    	for(auto f: fact){
    		int count = 0;
    		while(val % f == 0){
    			val /= f;
    			count+=1;
    		}
    		int orig = mp[i][f];
    		if(orig != 0){
	    		primes[f].erase(primes[f].find(orig));    			
    		}
    		if(count != 0){
	    		primes[f].insert(count);
	    		mp[i][f] += count;
    		}
    	}

    	// Iterate through all primes found uptil now and multiply the min

    	int ans = 1;
    	for(auto el : primes){
    		
    		if(el.second != NULL)
	    		ans *= *(el.second.begin());
    	}

    	cout<<ans<<endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // generatePrime();

    int t;
    // cin >> t;
    t = 1;

    while (t--) {
        solve();
    }
}
