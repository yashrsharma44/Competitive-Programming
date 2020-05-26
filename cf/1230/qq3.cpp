#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

    ll n,m;
    cin>>n>>m;

    vector< vector<ll> > adj(n+1);
    ll mm = m;
    while(mm--){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n <= 6 || m==0){
        cout<<m<<endl;
        return 0;
    }

    ll maxDomino = -1;

    for(ll i=1;i<7;i++){

        
        
        for(ll j=i+1;j<=7;j++){

            ll cnt = 0;
            vector<bool> visited(8, false);
            ll t = adj[i].size();
            ll z = adj[j].size();

            for(ll el : adj[i]){
                visited[el]  = true;
            }

            for(ll el : adj[j]){
                if(!visited[el]){
                    visited[el] = true;
                }
            }

            for(ll k=1;k<=7;k++){

                if(visited[k]){
                    cnt++;
                }
            }
            // cout<<"Count"<<cnt<<endl;
            // cout << t << ' ' << z << ' ' << m - (t+z - cnt) << endl;
            maxDomino = max(maxDomino, m - (t+z - cnt));


        }
    }

    cout<<maxDomino<<endl;
}