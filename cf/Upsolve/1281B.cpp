#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	string s1,s2;
	cin>>s1>>s2;

	// Lets find the lexicographically biggest character
	ll ind1 = -1;
	// ll ind2 = -1;
	bool isSmall = false;
	ll i = 0;
	for(;i<min(s1.length(), s2.length());i++){

		if(s1[i] > s2[i]){
			ind1 = i;
			// ind2 = i;
			break;
		}

		if(s1[i] < s2[i]){
			isSmall = true;
			break;
		}

	}

	if(isSmall || ind1 == -1 && i == s1.length()){
		cout<<s1<<endl;
	} else if(ind1 == -1 && i == s2.length()){
		
		cout<<"---"<<endl;

	}else {

		ll chngInd = -1;
		for(ll i=ind1;i<s1.length();i++){

			if((s1[i] - s2[ind1]) < 0){
				chngInd = i;
				break;
			}
		}

		if(chngInd != -1){

			char tmp = s1[ind1];
			s1[ind1] = s1[chngInd];
			s1[chngInd] = tmp;

			cout<<s1<<endl;
		} else {
			cout<<"---"<<endl;
		}

	}

}

int main(){

	ll t;
	cin>>t;
	while(t--){
		solve();
	}

}