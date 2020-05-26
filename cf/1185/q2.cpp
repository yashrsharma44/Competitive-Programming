#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	string s1,s2;
	cin>>s1>>s2;

	ll p1 = 0, p2 = 0;
	bool isPos = true;
	
	vector<int> charCount1(26, 0), charCount2(26, 0);
	char prevChar = s1[0];
	ll count = 0;
	while(p1 < s1.length()){

		if(s1[p1] == prevChar){
			count++;
		} else {

			ll count2 = 0;
			while(p2 < s2.length()){

				if(prevChar == s2[p2]){
					count2++;
				} else {
					break;
				}
				p2++;
			}

			if((count == 0 && count2 != 0) || (count2 < count)){
				isPos = false;
				break;
			} 
			count = 1;
			prevChar = s1[p1];
		}

		p1++;
	}

	ll count2 = 0;
	while(p2 < s2.length()){

		if(prevChar == s2[p2]){
			count2++;
		} else {
			break;
		}
		p2++;
	}

	if((p2 < s2.length()) || (count2 < count)){
		isPos = false;
	} 

	
	if(s2.length() < s1.length()){
		isPos = false;
	}
	

	if(isPos){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}

}

int main(){
	
	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}