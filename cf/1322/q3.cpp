#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
	
	ll n;
	cin>>n;

	string s;
	cin>>s;

	// Lets count open and close brackets
	// If not same, then balancing not possible
	// Otherwise, we will consider subsegments which are
	// un-balanced and need to be balanced and contains 
	// equal number of open and close brackets

	ll openBracket = 0, closeBracket = 0;
	for(char c : s){

		if(c == '('){
			openBracket += 1;
		} else {
			closeBracket += 1;
		}
	}

	if(openBracket != closeBracket){
		cout<<-1<<endl;
		return;
	}

	ll countTime = 0;
	ll currBal = 0;

	for(char c : s){

		if(c == '('){
			currBal+=1;
		} else {
			currBal -= 1;
		}

		if(currBal < 0 || (currBal == 0 && c == '(')){
			countTime+=1;
		}
	}

	cout<<countTime<<endl;

}

int main(){

	ll t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}