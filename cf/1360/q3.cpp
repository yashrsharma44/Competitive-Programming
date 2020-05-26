#include <bits/stdc++.h>
#define ll int

using namespace std;


void solve(){

	ll n;
	cin>>n;
	vector<ll>a;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}
	
	sort(a.begin(), a.end());
	ll odd=0, eve=0;
	ll o1=0,e1=0;
	for(ll i=0;i<n-1;i++){
		if(a[i] + 1 == a[i+1]){
			
			if(a[i] % 2 == 0){
				o1+=1;
			} else {
				e1+=1;
			}

			if(a[i+1] % 2 == 0){
				o1+=1;
			} else {
				e1+=1;
			}

			a[i] = -1;
			a[i+1] = -1;

			i+=1;
		} else {
			if(a[i] % 2 == 0){
				eve+=1;
			} else {
				odd+=1;
			}
		}
	}
	if(a[n-1] != -1){
		
		if(a[n-1] % 2 == 0){
			eve+=1;
		} else {
			odd+=1;
		}
	}

	if(odd%2 == 0 && eve%2 == 0 || (odd+(o1>0? 1 : 0))%2 == 0 && (eve+(e1>0 ? 1 : 0)) % 2 == 0){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}		

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin>>t;
	// t=1;

	while(t--){
		solve();
	}

}