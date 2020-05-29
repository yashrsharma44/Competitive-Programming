#include <bits/stdc++.h>
const double PI  =3.141592653589793238463; 
using namespace std;
typedef long long ll;
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define MOD 1000000007
#define endl "\n"
#define sz(a) (int)((a).size())
#define all(x) (x).begin(), (x).end()
#define trace(x) cerr << #x << ": " << x << " " << endl;
#define prv(a) for(auto x : a) cout << x << ' ';cout << '\n';
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define OTP(s) cout<<s<<endl;
#define FOR(i,j,k,l) for(ll i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
inline ll add(ll a, ll b){a += b; if(a >= MOD)a -= MOD; return a;}
inline ll sub(ll a, ll b){a -= b; if(a < 0)a += MOD; return a;}
inline ll mul(ll a, ll b){return (ll)((ll) a * b %MOD);}
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {
 
        if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base);//%MOD;
        }
        base = (base * base);//%MOD;
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}
ll min(ll a,ll b)
{
    return a>b?b:a;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}
void SieveOfEratosthenes(ll n, unordered_set<ll> &s) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // store all prime squares 
    for (ll p=2; p<=n; p++) 
       if (prime[p]) s.insert(p); 
} 
void dfs(ll s,vector<bool> &vis, vector<vector<ll>> &adlist)
{
	if(vis[s])return;
	vis[s]=true;
	for(auto x:adlist[s])
	{
		if(vis[x]==false)
		{
			cout<<s<<" "<<x<<endl;
		}
		dfs(x,vis,adlist);
	}
}
void bfs(ll x, vector<bool> &vis, vector<vector<ll>> &adlist)
{
	queue<ll> q;
	vis[x] = true;
	q.push(x);
	while (!q.empty()) 
	{
		ll s = q.front(); 
		q.pop();
		// process node s
		for (auto u : adlist[s]) 
		{
			if (vis[u]) continue;
			vis[u] = true;
			q.push(u);
		}
	}
}
bool bpchk(vector< vector < ll > > &adj, vector<ll> &color)
{
    color[1] = 1;
    queue < ll > q;
    q.push(1);

    while(!q.empty())
    {
        ll u = q.front();
        q.pop();

        for(auto x : adj[u])
        {
            if(color[x] == -1)
            {
                color[x] = color[u]^1;
                q.push(x);
            }
        }
    }

    for(ll i = 1; i < adj.size();i++)
    {
        for(auto x : adj[i])
        {
            if(color[x] == color[i]) return false;
        }
    }

    return true;    
}
void swap(ll *a, ll *b)
{
	ll tmp=*a;
	*a=*b;
	*b=tmp;
}
void add(ll x, ll k, vl &a)
{
    while(k<=a.size()-1)
    {
        a[k]+=x;
        k+=k&(-k);
    }
}
ll sm(ll k, vl &a)
{
    ll s=0;
    while(k>=1) 
    {
        s+=a[k];
        k-=k&(-k);
    }
    return s;
}
ll bin(ll st, ll en, ll val, vl &a)
{
    while(st<en){

        ll mid = st + (en - st) / 2;
        if(sm(mid, a) >= val){
            en = mid;
        } else {
            st = mid + 1;
        }
    }    
    if(en == 1e6){
        return 0;
    }

}
int main() 
{ 
    IOS
    ll n,k;
    cin>>n>>k;
    vl a(n,0);
    vl b(k,0);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(ll i=0;i<k;i++)
    {
        cin>>b[i];
    }
    vl arr(1e6+1,0);
    for(ll i=0;i<n;i++)
    {
        add(1,a[i],arr);
    }
    //prv(arr)
    for(ll i=0;i<k;i++)
    {
        if(b[i]>0)add(1,b[i],arr);
        else 
        {
            ll v=bin(1,arr.size()-1,-b[i],arr);
            add(-1,v,arr);
        }
    }
    //prv(arr);
    ll v=bin(1,arr.size()-1,1,arr);
    cout<<v<<endl;
}     