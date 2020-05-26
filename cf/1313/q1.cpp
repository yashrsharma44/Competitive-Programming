#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll a,b,c;
	cin>>a>>b>>c;
	ll sum = a+b+c;

	if(sum >= 12){
		cout<<7<<endl;
		return;
	}

	if(sum <= 3){
		cout<<sum<<endl;
	} else if(sum == 4){
		cout<<3<<endl;
	} else if(sum == 5){
		cout<<4<<endl;
	} else if(sum == 6){
		cout<<4<<endl;
	} else if(sum == 7){
		cout<<5<<endl;
	} else if(sum == 8){
		cout<<5<<endl;
	} else if(sum > 8 && sum < 12){
		cout<<6<<endl;
	}
	


}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}