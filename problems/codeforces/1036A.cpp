#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	long double n ,k; cin>>n>>k;
	const long long div = floor(k/n);
	const long long mod = (long long)(k)%(long long)(n);
	cout<<div + ( mod> 0)<<endl;
	return 0;
	
}