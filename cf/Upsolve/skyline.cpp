#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <complex>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
const ll MOD1 = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define fo(i, a, b) for (int i = (a); i <= (b); i++)
#define fod(i, a, b) for (int i = (a); i >= (b); i--)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

const string NAME = "";
const int MOD = 1e9 + 7;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    fast_cin();

    int n;
    cin >> n;
    ll h[n + 1], b[n + 1], dp[n + 1], mxm[n + 1];
    memset(mxm, 0, sizeof mxm);
    fo(i, 1, n) cin >> h[i];
    fo(i, 1, n) cin >> b[i];

    h[0] = -INF;
    stack<int> st;
    st.push(0);
    fo(i, 1, n) {
        ll mx = -INF;
        while (h[st.top()] > h[i]) {
            mx = max(mx, mxm[st.top()]);
            st.pop();
        }

        mxm[st.top()] = max(mxm[st.top()], mx);
        dp[i] = mxm[st.top()] + b[i];

        if (st.top()) {
            dp[i] = max(dp[i], dp[st.top()]);
        }
        st.push(i);
        mxm[i] = dp[i];
    }
    cout << dp[n] << ln;

    return 0;
}