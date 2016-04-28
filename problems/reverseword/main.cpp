#include<common.h>

using namespace std;

int main(){
    int N; cin>>N;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    LOOPUP(i,N){
        string s; getline(cin,s);
        vector<string> splitted;
        stringstream ss;
        auto split = [&](stringstream* ss, const char c){
            if(c == ' '){
                splitted.push_back(ss->str());

                ss->clear();ss->str("");
            }else
                (*ss)<<c;

            return ss;
        };

        DS::fold(s.begin(),s.end(),&ss,split);
        splitted.push_back(ss.str());//last word
        cout<<"Case #"<<i+1<<": ";
        LOOPDWN(j,splitted.size()-1){
            cout<<splitted[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
