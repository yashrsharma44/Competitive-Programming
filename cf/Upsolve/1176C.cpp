#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> arr;
	ll nn = n;
	ll c1=0,c2=0,c3=0,c4=0,c5=0,c6=0;

	while(nn--){
		ll vl;
		cin>>vl;

		if(vl == 4){
			c1++;
		}

		if(vl == 8 && c1){
			c2++; 
			c1--;
		}

		if(vl == 15 && c2){
			c3++;
			c2--;
		}

		if(vl == 16 && c3){
			c4++;
			c3--;
		}

		if(vl  ==  23 && c4){
			c5++;
			c4--;
		}

		if(vl == 42 && c5){
			c6++;
			c5--;
		}

	}

	cout<<(n - (6 * c6))<<endl;



}

int main(){

	ll t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
