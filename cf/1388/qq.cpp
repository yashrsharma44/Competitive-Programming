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
// #define endl "\n"
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
// long long fast_power(long long base, long long power) {
//     long long result = 1;
//     while(power > 0) {
 
//         if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
//             result = (result*base);//%MOD;
//         }
//         base = (base * base);//%MOD;
//         power = power / 2; // Can also use power >>= 1; to make code even faster
//     }
//     return result;
// }
// ll min(ll a,ll b)
// {
//     return a>b?b:a;
// }
// ll max(ll a,ll b)
// {
//     return a>b?a:b;
// }
// ll dfs(ll s,vector<bool> &vis, vector<vector<ll>> &adlist, vector<ll> &pe) 
// {
// 	if(vis[s]) return pe[s];
// 	vis[s]=true;
// 	for(auto x:adlist[s])
// 	{
// 		if(vis[x]==false)
// 		{
//             pe[s] += dfs(x,vis,adlist,pe);
// 		}
// 	}
//     return pe[s];
// }
// void bfs(ll x, vector<bool> &vis, vector<vector<ll>> &adlist, vector<ll> &level, vector<ll> &parent)
// {
// 	queue<ll> q;
// 	vis[x] = true;
// 	q.push(x);
// 	while (!q.empty()) 
// 	{
// 		ll s = q.front(); 
// 		q.pop();
// 		// process node s
// 		for (auto u : adlist[s]) 
// 		{
// 			if (vis[u]) continue;
// 			vis[u] = true;
//             parent[u]=s;
//             level[u]=level[s]+1;
// 			q.push(u);
// 		}
// 	}
// }
// bool bpchk(vector< vector < ll > > &adj, vector<ll> &color)
// {
//     color[1] = 1;
//     queue < ll > q;
//     q.push(1);

//     while(!q.empty())
//     {
//         ll u = q.front();
//         q.pop();

//         for(auto x : adj[u])
//         {
//             if(color[x] == -1)
//             {
//                 color[x] = color[u]^1;
//                 q.push(x);
//             }
//         }
//     }

//     for(ll i = 1; i < adj.size();i++)
//     {
//         for(auto x : adj[i])
//         {
//             if(color[x] == color[i]) return false;
//         }
//     }

//     return true;    
// }
// void swap(ll *a, ll *b)
// {
//     ll tmp=*a;
//     *a = *b;
//     *b = tmp;
// }
// void SieveOfEratosthenes(ll n, set<ll> &s) 
// {  
//     vector<bool> prime(n+1,true);  
//     for (ll p=2; p*p<=n; p++) 
//     { 
//         // If prime[p] is not changed, then it is a prime 
//         if (prime[p] == true) 
//         {   
//             for (ll i=p*p; i<=n; i += p) 
//                 prime[i] = false; 
//         } 
//     }  
//     for (ll p=2; p<=n; p++) 
//        if (prime[p]) s.insert(p); 
// } 

int main()
{
    // IOS
    // ll T;
    // cin>>T; 
    // while(T--)
    
        ll n;
        cin>>n;
        vector<ll> a;
        a.push_back(-1);
        map<ll,ll> m;
        cout<<1<<endl;
        for(ll i=1;i<=n;i++)
        {
            int vl;
            cin>>vl;
            a.push_back(vl);
            m[i]=0;
        }
        vector<ll> nxt;
        nxt.push_back(-1);
        for(ll i=1;i<=n;i++)
        {   
            int vl;
            cin>>vl;
            nxt.push_back(vl);
            if(nxt[i]!=-1)
            {
                m[nxt[i]]+=1;
            }
        }
        cout<<2<<endl;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll> > > pq;
        vector<ll> ans1,ans2;
        for(auto &x:m)
        {
            if(x.second==0)
            {
                pq.push(make_pair(a[x.first],x.first));
            }
        }
        ll val=0;
        pair<ll,ll> p;
        cout<<3<<endl;
        while(!pq.empty())
        {
            p = pq.top();
            pq.pop();
            val+=p.first;
            if(p.first<=0)
            {
                ans2.pb(p.second);
            }
            else if(p.first>0)
            {
                ans1.pb(p.second);
                a[nxt[p.second]]+=p.first;
            }

            if(nxt[p.second]!=-1)
            {
                m[nxt[p.second]]-=1;
                if(m[nxt[p.second]]==0)
                {
                    pq.push(make_pair(a[nxt[p.second]],nxt[p.second]));
                }
            }
        }
        cout<<4<<endl;
        vector<ll> ans;
        if(ans2.size()>0)
        {
            reverse(ans2.begin(),ans2.end());
        }
        if(ans1.size()>0)
        {
            for(ll i=0;i<ans1.size();i++)
            {
                ans.pb(ans1[i]);
            }
        }
        cout<<4<<endl;
        if(ans2.size()>0)
        {
            for(ll i=0;i<ans2.size();i++)
            {
                ans.pb(ans2[i]);
            }
        }
        cout<<5<<endl;
        cout<<val<<endl;
        // cout<<"**********\n";
        // prv(ans);
        for(ll el : ans){
            cout<<el<<" ";
        }
        return 0;
    
}