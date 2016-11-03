/* Copyright (c) 2015 Prateek Singhal */

#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007

#define s(n) scanf("%d",&n) 
#define sc(n) scanf("%c",&n)
#define sl(n) scanf("%lld",&n)
#define s64(n) scanf("%I64d",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s", n)
#define gc getchar()
#define gl(n) getline (cin,n)
#define ci(n) cin >> n


#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define rt return
#define nxtp next_permutation
#define bg begin()
#define end end()

#define strc(a, b) strcpy(a, b.c_str())
#define fill(a, v) memset(a, v, sizeof(a))
#define rev(n) reverse(n.bg, n.end)

#define rep(i, n) for(i = 0; i < n; i++)
#define _rep(i, a, b, c) for(i = a; i <= b; i = i + c)
#define repr(i, a, b, c) for(i = a; i >= b; i = i - c)

#define foreach(v, c) for( typeof( (c).begin()) v = (c).begin(); v != (c).end(); ++v)

using namespace std;

string numtostr(ll n)
{
	string str = "";
	ll x;
	while(n > 0)
	{
		x = n % 10;
		n = n / 10;
		str = ((char)('0' + x)) + str;
	}
	rt str;
}

ll strtonum(string str)
{
	ll num = 0, i;
	rep(i, str.size())
	{
		num = num * 10 + (str[i] - '0');
	}
	return num;
}

int palin[5005][5005];
int dp[5005][5005];

int main()
{
	int i, j, n, x, y, q;
	string str;
	ci(str);
	n = str.length();
	rep(i, n)
	{
		palin[i][i] = 1;
		dp[i][i] = 1;
		palin[i + 1][i] = 1;
	}

	_rep(i, 2, n, 1)
	{
		_rep(j, 0, n - i, 1)
		{
			palin[j][j + i - 1] = palin[j + 1][j + i - 2] && str[j] == str[j + i - 1];
			dp[j][j + i - 1] = dp[j][j + i - 2] + dp[j + 1][j + i - 1] - dp[j + 1][j + i - 2] + palin[j][j + i -1];
		}
	}
	s(q);
	rep(i, q)
	{
		s(x);s(y);
		p(dp[x - 1][y - 1]);nl;
	}
	rt 0;
}
