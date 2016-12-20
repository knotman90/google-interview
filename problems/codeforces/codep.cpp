#include <bits/stdc++.h>
using namespace std;


int v[300000];

int nina(long long z) {
	int aux;
	int pot = 1;
	int ans = 0;
	while (z > 0) {
		aux = z%10;
		if (aux%2 == 1) ans += pot;
		pot *= 2;
		z /= 10;
	}
	return ans;
}

char op[11];
int main()
{
	int n, aux;
	long long x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %lld", op, &x);
		aux = nina(x);
		if (op[0] == '+') {
			v[aux]++;
			//printf("incrementando %d\n", aux);
		}
		else if (op[0] == '-') {
			v[aux]--;
			//printf("tirando %d\n", aux);
		}
		else if (op[0] == '?') printf("%d\n", v[aux]);
		
		
	}
	return 0;
}
