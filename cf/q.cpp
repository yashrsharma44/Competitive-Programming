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

void solve()
{
    string s;
    cin >> s;

    ll i, j, n = s.length();
    vector< ll > freq(26);

    rep(i,s.length()) freq[s[i] - 'a']++;

    ll cnt1 = 0;
    rep(i,26) cnt1 = max(cnt1, freq[i]);

    vector< vector < ll > > dp(26, vector< ll >(26, 0));

    freq.clear();
    freq.resize(26);
    freq[s[0] - 'a']++;
    for(i = 1; i < n; i++)
    {
        for(j = 0; j < 26; j++)
        {
            dp[s[i] - 'a'][j] += freq[j];
        }
        freq[s[i] - 'a']++;
    }

    ll cnt2 = 0;
    rep(i, 26) rep(j, 26) cnt2 = max(cnt2, dp[i][j]);

    cout << max(cnt1, cnt2) << endl;
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