#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define rep(i,n) for(i=0;i<(n);i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(),c.end()
#define endl "\n"
typedef pair< ll, ll > lpair;

vector< ll > prime(10000000 + 10, -1);

void sieve()
{
    ll i, j;
    // prime[1] = 1;
    for(i = 1; i <= 10000000; i++) prime[i] = i;
    for(i = 2; i*i <= 10000000; i++)
    {
        if(prime[i] == i)
        {
            // prime[i] = i;
            for(j = i * i; j <= 10000000; j += i)
            {
                if(prime[j] == j) prime[j] = i;
            }
        }
    }
}

set< ll > factor(ll x)
{
    set< ll > ans;
    while(x != 1)
    {
        ans.insert(prime[x]);
        x /= prime[x];
    }
    return ans;
}

void solve()
{
    sieve();
    // // ll n;
    // // cin >> n;
    // ll i;
    // // set< ll > pr = factor(4);

    // // for(auto x : pr) cout << x << " " ; cout << endl;

    // // bool flag = true;
    // for(i = 2; i <= 10000000; i++)
    // {
    //     // cout << i << ": ";
    //     set< ll > pr = factor(i);
    //     if(pr.size() == 1 || *pr.begin() == i) continue;
    //     else
    //     {
    //         vector < ll > p;
    //         for(auto x : pr) p.pb(x);
    //         bool f1 = false;

    //         ll p1 = p[p.size() - 1];
    //         ll p2 = 1;
    //         for(ll j = 0; j < p.size() - 1; j++) p2 *= p[j];

    //         if(__gcd(p1 + p2, i) == 1) f1 = true;
    //         if(f1 == false) cout << i << "    FAIL" << endl; 
    //     }
    // }
    // // if(flag) cout << "PAss" << endl;
    // // else cout << "FAIl" << endl;
    // yeh thi chutiyaap zindagi

    // mentos

    ll n, i;
    cin >> n;
    
    vector< ll > a(n);
    rep(i, n) cin >> a[i];

    vector< lpair > ans(n);
    rep(i, n)
    {
        set< ll > prime_fac = factor(a[i]);
        if(prime_fac.size() == 1 )
        {
            ans[i].ff = -1;
            ans[i].ss = -1;
        }
        else
        {
            vector< ll > p;
            for(auto x : prime_fac) p.pb(x);

            ll p1 = p[p.size() - 1];
            ll p2 = 1;
            for(ll j = 0; j < p.size() - 1; j++) p2 *= p[j];

            ans[i].ff = p1;
            ans[i].ss = p2;
        }
    }

    rep(i, n) cout << ans[i].ff << " " ; cout << endl;
    rep(i, n) cout << ans[i].ss << " " ; cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    ll t = 1;
    // cin >> t;

    while(t--) solve();

    return 0;
}