/**
 * Dont raise your voice, improve your argument.
 * --Desmond Tutu
 */

#include <bits/stdc++.h>
using namespace std;

const bool ready = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);
    return true;
}();

const double PI = acos(-1);
using ll = long long;
#define int ll
#define all(v) (v).begin(), (v).end()
#define fori(n) for (int i = 0; i < int(n); i++)

#define cini(i) \
    int i;      \
    cin >> i;
#define cins(s) \
    string s;   \
    cin >> s;
#define cind(d) \
    double d;   \
    cin >> d;
#define cinai(a, n) \
    vi a(n);        \
    fori(n) { cin >> a[i]; }
#define cinas(s, n) \
    vs s(n);        \
    fori(n) { cin >> s[i]; }
#define cinad(a, n) \
    vd a(n);        \
    fori(n) { cin >> a[i]; }

using pii = pair<int, int>;
using pdd = pair<double, double>;
using vd = vector<double>;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;

/* Hows the greedy?
 * Once we get the smallest element to left 
 * or the biggest to right it is trivial.
 *
 * If there is something left of the smallest
 * we cannot get rid of it, so we must remove
 * the smallest. And so on.
 * We cannot remove the smallest if it is last.
 * We cannot remove the biggest if it is first.
 *
 * Can we simply remove the biggest/smallest 
 * until the biggest/smallest remaining is left right?
 * How to check this?
 * How to prove? idk
 * Remove smallest until possible.
 *
 * Maintain a set<pii> of <val,next>
 */
const int INF = 1e9;
void solve() {
    cini(n);
    cinai(a, n);

    vb smL(n); /* smL[i]==true if a smaller element is left of ith element */
    vb bgR(n); /* bgR[i]==true if a bigger  element is right of iht element */

    int mi = INF;
    for (int i = 0; i < n; i++) {
        if (mi < a[i])
            smL[i] = true;
        mi = min(mi, a[i]);
    }

    int ma = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (ma > a[i])
            bgR[i] = true;
        ma = max(ma, a[i]);
    }

    cout << "DBG: ";
    for (auto el : a) {
        cout << el << "  ";
    }
    cout << endl
         << "SML: ";
    for (int i = 0; i < n; i++) cout << smL[i] << "  ";
    cout << endl
         << "BIG: ";
    for (int i = 0; i < n; i++) cout << bgR[i] << "  ";

    vi pos(n + 1);
    for (int i = 0; i < n; i++)
        pos[a[i]] = i;

    /* find if first element can be made smallest. This is if all smaller elements
 * have a bigger one right of them.
 */
    int ok = true;
    for (int i = 1; i < a[0]; i++) {
        int p = pos[i];
        if (!bgR[p])
            ok = false;C
    }
    if (ok) {
        cout << "YES" << endl;
        return;
    }

    /* find if last element can be made biggest. This is if all bigger elements
 * have a smaller one left of them.
 */
    ok = true;
    for (int i = n; i > a[n - 1]; i--) {
        int p = pos[i];
        if (!smL[p])
            ok = false;
    }
    if (ok) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
}

signed main() {
    cini(t);
    while (t--)
        solve();
}

// FIRST THINK, THEN CODE
// DO NOT JUMP BETWEEN PROBLEMS
