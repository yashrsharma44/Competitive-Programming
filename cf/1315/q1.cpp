#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll a,b,x,y;
	cin>>a>>b>>x>>y;

	ll area1 = (a * (b - (y+1)));
	ll area2 = (a * (y));

	ll area3 = (b * (x));
	ll area4 = (b * (a - (x+1)));

	ll mx = -1;
	mx = max(mx, area1);
	mx = max(mx, area2);
	mx = max(mx, area3);
	mx = max(mx, area4);

	cout<<mx<<endl;
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}