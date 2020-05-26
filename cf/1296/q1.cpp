#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll s;
	cin>>s;

	ll maxSum = 0;

	while(s > 0){

		string ss = to_string(s);
		ll lastNum = ss[ss.length()-1] - '0';

		maxSum += (s - lastNum);
		if(s < 10){
			maxSum += s;
			break;
		}
		s = (s / 10) + lastNum;
		// cout<<"S"<<s<<endl;
	}

	cout<<maxSum<<endl;

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}