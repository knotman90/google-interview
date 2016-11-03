#include <iostream>
#include<vector>

using namespace std;


int main(){
    
    vector<int> sizes(0);
    int n; cin>>n;

    int gs=0;
    for(int i=0;i<n;i++){
        char c; cin>>c;
        if(c=='B')
            gs++;
        else{
            if(gs>0)
                sizes.push_back(gs);

            gs=0;
       }
    }
    if(gs>0)
        sizes.push_back(gs);

    cout<<sizes.size()<<endl;


    for( int i=0 ; i < (sizes.size())  ; i++ )
        cout<<sizes[i]<<" ";
   // if(sizes.size()>0)
     //   cout<<sizes[sizes.size()-1];

    return 0;
}
