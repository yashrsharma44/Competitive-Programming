#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ll int
#define ld double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
const ll M = 2e5 + 5;
bool f[M];
ll U[M], V[M], wt[M], pt[M], ch[M], lvl[M], a[M];
pair<ll, ll> anc[M][30];
std::vector<pair<ll, ll> > vtr[M];
bool comp(ll x, ll y) {
    return wt[x] < wt[y];
}
ll getpt(ll x) {
    if (pt[x] == x)
        return x;
    return pt[x] = getpt(pt[x]);
}
void dfs(ll x, ll p = 0, ll l = 0) {
    lvl[x] = l;
    for (ll i = 0; i < sz(vtr[x]); i++) {
        if (vtr[x][i].ff != p) {
            anc[vtr[x][i].ff][0].ff = x;
            anc[vtr[x][i].ff][0].ss = vtr[x][i].ss;
            dfs(vtr[x][i].ff, x, l + 1);
        }
    }
}
void pre(ll n) {
    for (ll j = 1; j < 22; j++) {
        for (ll i = 1; i <= n; i++) {
            anc[i][j].ff = anc[anc[i][j - 1].ff][j - 1].ff;
            anc[i][j].ss = max(anc[i][j - 1].ss, anc[anc[i][j - 1].ff][j - 1].ss);
        }
    }
}
ll getlca(ll p, ll q) {
    if (lvl[p] < lvl[q])
        swap(p, q);
    ll ans = 0;
    for (ll i = 21; i >= 0; i--) {
        if (lvl[p] - (1 << i) >= lvl[q]) {
            ans = max(ans, anc[p][i].ss);
            p = anc[p][i].ff;
        }
    }
    if (p == q)
        return ans;
    for (ll i = 21; i >= 0; i--) {
        ll a = anc[p][i].ff;
        ll b = anc[q][i].ff;
        if (a != b) {
            ans = max(ans, anc[p][i].ss);
            ans = max(ans, anc[q][i].ss);
            p = anc[p][i].ff;
            q = anc[q][i].ff;
        }
    }
    ans = max(ans, anc[p][0].ss);
    ans = max(ans, anc[q][0].ss);
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, u, v;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++) {
        cin >> U[i] >> V[i] >> wt[i];
        a[i] = i;
    }
    sort(a + 1, a + m + 1, comp);
    for (ll i = 1; i <= n; i++) {
        pt[i] = i;
        ch[i] = 1;
    }
    for (ll j = 1; j <= m; j++) {
        ll i = a[j];
        ll u = U[i], v = V[i];
        ll a = getpt(u);
        ll b = getpt(v);
        if (a != b) {
            if (ch[a] > ch[b]) {
                pt[b] = a;
                ch[a] += ch[b];
            } else {
                ch[b] += ch[a];
                pt[a] = b;
            }
            vtr[u].pb(mp(v, wt[i]));
            vtr[v].pb(mp(u, wt[i]));
            f[i] = 1;
        }
    }
    dfs(1);
    pre(n);
    ll ans = 0;
    for (ll i = 1; i <= m; i++) {
        if (f[i])
            continue;
        if (wt[i] == getlca(U[i], V[i])) {
            cout << "CHNG: " << i << " " << U[i] << " " << V[i] << endl;
            ans++;
        }
    }
    cout << "MAX WEIGHT: 1->3: " << getlca(1, 3) << endl;
    cout << "MAX WEIGHT: 3->5: " << getlca(3, 5) << endl;
    cout << ans << "\n";
    return 0;
}