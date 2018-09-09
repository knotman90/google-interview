#include <iostream>
#include <vector>
using namespace std;

int main(){
	string l,s;
	cin>>l>>s;
	if(l.size()<s.size())
		swap(l,s);
	int pl,ps;
	ps=0;
	pl = l.size()-s.size();
	int diff = 0;
	for(int i = 0  ; i < s.size() ; i++){
		if(l[pl+i]!=s[i])
			diff=i+1;
	}
	diff=l.size()-s.size() + 2*diff;
	cout<<diff<<endl;
	return 0;

}