#include <sstream>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>
#include <numeric>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;
using namespace std::chrono;
using ull = unsigned long long;
using ul = unsigned long;
using pii = pair<int, int>;

ostringstream solve();
void solve_case(ostringstream&);
void reset();

int main()
{
    unsigned T;
    cin>>T;
    for(unsigned test_id = 1; test_id <= T ; test_id++)
    {
        ostringstream ss = solve();
        const string tc_output(ss.str());
        cout<<"Case #"<<test_id<<": "<<tc_output<<endl;
    }
}

ostringstream solve() {
    ostringstream ssout;
   
    reset();
    solve_case(ssout);
   
    return ssout;
}
//////////////////////////////////////////////////////
//                                                  //
//-------------------PROBLEM CODE-------------------//
//                                                  //
//////////////////////////////////////////////////////

//////////////////////////
//---Global variables---//
//////////////////////////
void reset(){
   
}
//------------------------

void solve_case(ostringstream& cout)
{
    string s;
    cin>>s;

    string A(s);
    string B;
    B.resize(s.size());
    fill(B.begin(), B.end(),'0');
    
    for (unsigned i = 0; i < s.size(); ++i)
    {
        if(s[i]=='4')
        {
            A[i]='2';
            B[i]='2';
        }
    }

    cout<<A<<" ";
   
    {
        auto it = find_if(B.begin(), B.end(), 
            [](const char c){
                return c!='0';
            });
        while(it != B.end()){
            cout<<*it;
            it++;
        }
    }
}