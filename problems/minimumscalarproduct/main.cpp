#include<common.h>

using namespace std;

int main(){
    int N; cin>>N;
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    LOOPUP(i,1,N+1){
        int size; cin>>size;
        vector<long long> v1;
        vector<long long> v2;
        LOOPUP(i,size){
            int el; cin>>el;
            v1.pb(el);
        }
        LOOPUP(i,size){
            int el; cin>>el;
            v2.pb(el);
        }
        DS::quicksort(v1,0,size,DS::gt<long long>);
        DS::quicksort(v2,0,size,DS::lt<long long>);
        long long  sp =0;
        LOOPUP(j,size){
            sp += v1[j]*v2[j];

        }


        printf("Case #%d: %lld\n",i,sp);
        //DS::print(ALL(v1));
        //DS::print(ALL(v2));
    }
    return 0;
}
