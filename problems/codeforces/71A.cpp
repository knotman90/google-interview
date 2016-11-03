#include <iostream>
#include<string>
using namespace std;

int main(){
int N; cin>>N;
    while(N--){
        string w; cin>>w;
        if(w.size() >=11)
            cout<<w[0]<<w.size()-2<<w[w.size()-1];
        else
            cout<<w;
        cout<<endl;
    }


    return 0;

}
