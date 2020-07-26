/*
* @Author: Davide Spataro
* @Date:   2019-09-22 12:04:10
* @Last Modified by:   Davide Spataro
* @Last Modified time: 2019-09-28 10:00:20
*/
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

constexpr int NG = 25;
constexpr int NM = 205;

void solve(){
	int pg[NG][NG]={{0}};
	int numg[NG]={0};
	int M,C;
	cin>>M>>C;
	for (int i = 0; i < C; ++i)
	{
		cin>>numg[i];
		for (int j = 0; j < numg[i]; ++j)
		{
			cin>>pg[i][j];
		}
	}
	
	bool dp[NG][NM] ={{false}};
	for(int i = 0 ; i <= numg[0] ; i++){
		if(M-pg[0][i] >= 0)
			dp[0][M-pg[0][i]] = true;
	}

	for (int i = 1; i < C; ++i)
	{
		for (int m = 0; m < M; ++m)
		{
			for (int k = 0; k < numg[i]; ++k)
			{
				const int pgk = pg[i][k];
				const int moneyfrom = m+pgk;
				if( moneyfrom <= M && dp[i-1][moneyfrom] )
					dp[i][m] = true;
			}
		}
	}

	int ans = -1;
	for(int i = 0 ; i <= M ; i++){
		if(dp[C-1][i])
		{
			ans = M-i;
			break; 
		}
	}

	if(ans!= -1){
		cout<<ans;
	}else{
		cout<<"no solution";
	}
	cout<<endl;

}

int main()
{

	int T; cin>>T;
	while(T--){
		solve();
	}

	return 0;
}