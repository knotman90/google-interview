#include <iostream>
#include <vector>
using namespace std;

int main(){
	
	int n,nn,nnn;
	n=0;
	cin>>n;

	cin>>nn;
	n--;
	int size = 1;
	vector<int> s;
	
	while(n--){
		int nnn; cin>>nnn;
		if(nnn==1){
			s.push_back(size);
			size=0;
		}
		size++;
		nn=nnn;
	}
	s.push_back(size);
	cout<<s.size()<<endl;
	for(auto a: s){
		cout<<a<<" ";
	}
	cout<<endl;
	return 0;

}