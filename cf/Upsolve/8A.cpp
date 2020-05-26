#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	string s,a,b;
	cin>>s>>a>>b;

	bool isForward = false;
	bool isBackward = false;

	ll idx1 = -1, idx2 = -1,idx3 = -1, idx4 = -1;

	// Forward
	if(s.find(a) != string::npos){

		idx1 = s.find(a);
	}

	if(s.rfind(b) != string::npos){

		idx2 = s.find(b);
	}

	if((idx1 != -1) && (idx2 != -1) && (idx1 < idx2)){
		isForward = true;
	}

	reverse(s.begin(), s.end());
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	// Backward
	if(s.find(a) != string::npos){

		idx3 = s.find(a);
	}

	if(s.rfind(b) != string::npos){

		idx4 = s.find(b) ;
	}

	if((idx3 != -1) && (idx4 != -1) && (idx3 < idx4)){
		isBackward = true;
	}


	if(isForward && isBackward){
		cout<<"both"<<endl;
	} else if(isForward){
		cout<<"forward"<<endl;
	} else if(isBackward){
		cout<<"backward"<<endl;
	} else {
		cout<<"fantasy"<<endl;
	}
}
