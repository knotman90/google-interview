#include<common.h>

using namespace std;
int mod(int a, int b){
    int mod = a%b;
    if(mod<0)
        return mod +b;
    return mod;
}
void charToKey(const char c,int& key,int& npress){
    if(c == ' '){
        key=8;
        npress=0;
        return;
    }

    char a =c;
    key=6;
    npress=(a-'t')%3;
    if(a >='a' && a<= 'o'){
        key    = (a-'a')/3;
        npress = (a-'a')%3;
    }
    else if(a >=('p') && a<=('s')){
        key    = 5;
        npress = (a-'p')%5;
    }
    else if(a >=('w') && a<=('z')){
            key = 7;
            npress=mod((a-'w'),5);

    }


}



int main(){
    vector<int> chersKey= {3,3,3,3,3,4,3,4,1};
    int N; cin>>N;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for(int i=0 ;i<N ; ++i){
        string s; getline(cin,s);
        //cout<<s<<endl;


int key=-1,keyprec=-1,npress=-1;
    /*    for(char a='a' ; a<='z';a++){
            charToKey(a,key,npress);
            printf("char %c k=%d npress=%d\n",a,key,npress);
        }
exit(0);*/
    printf("Case #%d: ",i+1);
        for(char a:s){

            charToKey(a,key,npress);
            if(key==keyprec)
                cout<<' ';
            for(int j=0 ;j<=npress;j++){
                int print = (key == 8 ? 0 : key+2);
                cout<<print;

            }
            keyprec=key;

        }
        cout<<endl;
    }


    return 0;
}
