#include<common.h>

using namespace std;

typedef signed long long sll;
typedef unsigned long long ull;
int main(){

int T; cin>>T;
LOOPUP(i,T){
    ull L,P,C; cin>>L>>P>>C;
    ull lo = L;
    int count=0;
    while(lo < P){
        lo*=C;
        count++;
    }
    int ans = ceil(log2(count));
    printf("Case #%d: %d\n",i+1,ans);


}

return 0;
}
