#include <bits/stdc++.h>
using namespace std;
#define N 400001
#define mod 1000000007
#define inf 1000000000
#define pp pair<ll,ll>
typedef long long int ll;
typedef long double ld;
#define MP make_pair

#define endl "\n"
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<n;i++)
#define rrep(i,n) for(ll i=n-1;i>=0;i--)
#define repb(i,n) for(ll i=1;i<n-1;i++)     
void fastIO(void);

void decimal(int);
ll modmulti(ll, ll, ll);
ll modadd(ll, ll, ll);
ll modpower(ll, ll, ll);
ll gcd(ll, ll );
ll modinv(ll, ll);
int sum(int,int);



int main()
{  
   fastIO();
   ll n;
   ll k;
   ll count[N];
   rep(i,N) count[i]=0;
   cin>>n>>k;
   k = k*8/n;
   //cout<<k<<endl;
   ll m = floor(k);
   if(m>25){
      cout<<0<<endl;
      return 0;
   }
       //  cout<<"here"<<endl;

   ll K = pow(2,m);
   //cout<<K<<endl;
    priority_queue <ll, vector<ll>, greater<ll> > p;
   map<ll,ll> mm;
   ll kk;
   rep(i,n){
      cin>>kk;
      mm[kk]++;
      if(mm[kk]==1)
      p.push(kk);
      
   }
   //cout<<p.size()<<endl;
     ll i=0,j;
      // cout<<"here"<<endl;
   while(!p.empty()){
      count[i] = mm[p.top()];
      //cout<<i<<" "<<count[i]<<endl;
      //cout<<p.top()<<endl;
      i++;
      p.pop();
   }
   
   ll ans=0;
   for(i=0;i<K && i<N;i++)
   {  //cout<<i<<endl;
      ans+=count[i];}
   ll curr = ans;
   
            //cout<<"here"<<endl;
   //cout<<ans<<endl;
   for(i=1,j=i+K-1;j<N;i++,j++){
     // cout<<"here"<<endl;
      curr = curr-count[i-1]+count[j];
      ans = max(curr,ans);
   }
   cout<<n-ans<<endl;

}























void fastIO(void)
{  ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
}

void decimal(int n){
   cout<<fixed;
   cout<<setprecision(n);
}
ll modmulti(ll a, ll b, ll m){
   return ((a%m)*(b%m))%m;
}
ll modadd(ll a, ll b, ll m){
   return ((a%m)+(b%m))%m;
}
ll modpower(ll a, ll n, ll m){
   if(n==0)
      return 1;
   ll result = 1;
   while(n>0){
      if(n%2==1)
         result = modmulti(result,a,m);
      a = modmulti(a,a,m);
      n = n/2;
   }
   return result;
}
ll gcd(ll a, ll b){
   if(b==0)
      return a;
   return gcd(b,a%b);
}
ll modinv(ll a, ll m){
   return modpower(a,m-2,m);
}
