#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll a,b,c,d,k;
	cin>>a>>b>>c>>d>>k;

	double r1 = (double)(a) / c;
	double r2 = (double)(b) / d;

	ll count1 = ceil(r1);
	ll count2 = ceil(r2);

	if(count1 + count2 > k){
		cout<<-1<<endl;
	} else {
		cout<<count1<<" "<<count2<<endl;
	}

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}