#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string checkPal(ll start, ll end, string s){

	ll lp = start;
	ll rp = end;

	while(lp < rp){

		if(s[lp] != s[rp]){
			return "";
		}
		lp++;
		rp--;
	}

	return s.substr(start, end-start+1);

}


void solve(){

	string s;
	cin>>s;
	ll n = s.length();

	// Take prefix, suffix, and prefix-suffix such that both are palin and
	// then when this fails to hold, start framing the palin starting from prefixend or ending at suffix end
	string prefixString = "";
	for(ll i=0;i<n;i++){

		string ss = checkPal(0,i,s); 
		if(ss!=""){
			prefixString = ss;
		}
	}

	string suffixString = "";
	for(ll i=n-1;i>=0;i--){

		string ss = checkPal(i,n-1,s);
		if(ss!=""){
			suffixString = ss;
		}
	}

	// cout<<prefixString<<" "<<suffixString<<endl;

	ll lp = 0, rp = n-1;
	string startString = "", endString="";
	string finalRes ="";
	while(lp < rp){

		if(s[lp] == s[rp]){
			startString = s.substr(0,lp+1);
			endString = s.substr(rp);
		} else {

			string leftPal = "";
			for(ll i=lp;i<rp;i++){

				string ss = checkPal(lp,i,s);
				if(ss!=""){
					leftPal = ss;
				}
			}

			string rightPal = "";
			for(ll i=rp;i>=lp;i--){

				string ss = checkPal(i,rp,s);
				if(ss!=""){
					rightPal = ss;
				}
			}

			if(startString.length() + leftPal.length() > endString.length()+rightPal.length()){
				finalRes = startString+leftPal+endString;
			} else {
				finalRes = startString+rightPal+endString;
			}
			break;

		}
		lp++;
		rp--;

	}

	ll len1 = prefixString.length();
	ll len2 = suffixString.length();

	ll len3 = finalRes.length();

	if(len1 >= len2 && len1 >= len3){
		cout<<prefixString<<endl;
	} else if(len2 >= len3 && len2 >= len1){
		cout<<suffixString<<endl;
	} else if(len3 >= len2 && len3 >= len1){
		cout<<finalRes<<endl;
	}

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}