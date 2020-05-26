#include <bits/stdc++.h>
#define ll long long int

using namespace std;


void solve(){

	ll n,s;
	cin>>n>>s;

	if(n == 1 && s == 1){
		cout<<"NO"<<endl;
		return;
	}

	if(n == 1){
		cout<<"YES"<<endl;
		cout<<s<<endl;
		cout<<s-1<<endl;
		return;
	}

	vector<ll> a;
	for(ll i=0;i<n-1;i++){
		a.push_back(1);
	}

	a.push_back(s - (n - 1));
	set<ll> visited;
	
	set<ll> unvis;
	for(ll i=1;i<=s;i++){
		unvis.insert(i);
	}

	int sum=0;
	for(ll i=0;i<n;i++){
		sum+=a[i];
		visited.insert(sum);
		unvis.erase(sum);
	}
	sum=0;
	for(ll i=n-1;i>=0;i--){
		sum+=a[i];
		visited.insert(sum);
		unvis.erase(sum);
	}

	bool isPos=false;
	ll pos_k = -1;
	for(ll el : unvis){

		if(unvis.find(s-el) != unvis.end()){
			pos_k = el;
			isPos = true;
			break;
		}
	}

	if(isPos){
		cout<<"YES"<<endl;
		for(ll el : a){
			cout<<el<<" ";
		}
		cout<<endl;
		cout<<pos_k<<endl;
	} else {
		cout<<"NO"<<endl;
	}

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
