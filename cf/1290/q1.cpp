#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	string s;
	cin>>s;

	bool isPos = true;

	if(((s[n-1] - '0') % 2) == 0){

		ll start = -1;
		for(ll i=n-1;i>=0;i--){

			if((s[i] - '0') % 2 == 1){
				start = i;
				break;
			}

		}

		string s1 = "";
		// cout<<"START"<<start<<endl;
		if(start != -1){
			for(ll i=0;i<=start;i++){
				s1+=s[i];
			}
			// cout<<"SI"<<s1<<endl;
			s = s1;
		} else {
			isPos = false;
		}
	}

	if(isPos){

		ll sumDigit = 0;
		for(char c : s){
			sumDigit += (c - '0');
		}

		if((sumDigit % 2) == 0){
			cout<<s<<endl;
		} else {

			bool isDone = false;
			// Remove an element
			for(ll i=0;i<s.length();i++){
				if((s[i] - '0') == 0){
					s[i] = 'l';
				}
			}

			for(ll i=0;i<s.length() - 1;i++){

				if((s[i] - '0') % 2 == 1){
					s[i] = 'l';
					isDone = true;
					break;
				}

				

			}

			if(isDone){
				// cout<<"P"<<s<<endl;
				for(ll i=0;i<s.length();i++){

					char c = s[i];

					if(c == 'l'){
						continue;
					} else {
						
						cout<<c;
					}
				}

				cout<<endl;
				return;

			} else {
				cout<<-1<<endl;
				return;
			}

		}


	} else {
		cout<<-1<<endl;
	}

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}
