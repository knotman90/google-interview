#include <iostream>
#include <set>
using namespace std;

int main(){
	
	int n = 0;
	cin>>n;
	multiset<string> pr;

	int nn = n;
	while(nn--){
		string s; cin>>s;
		pr.insert(s);
	}
	
	nn=n;
	while(nn--){
		string s; cin>>s;
		auto it = pr.find(s); 
		if(it != end(pr))
			pr.erase(it);
	}
	cout<<pr.size()<<endl;
}