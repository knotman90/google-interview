#include <iostream>

using namespace std;


int solve(const int n){
	if( n == 1)
		return 0;
	if(n == 2)
		return 1;
	if(n == 3)
		return 2;
	if(n % 2 == 0)
		return 1+solve(n/2);
	if( n & (1<<1))
		return solve(n+1) +1;
	return solve(n-1) +1;
}


int main(){
	int n; cin>>n;

	cout<<solve(n)<<endl;

	return 0;
}