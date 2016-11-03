#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
typedef pair<int,int> pii;

template <class T>
inline void hash_combine(std::size_t & seed, const T & v)
{
  std::hash<T> hasher;
  seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
 
namespace std
{
  template<typename S, typename T> struct hash<pair<S, T>>
  {
    inline size_t operator()(const pair<S, T> & v) const
    {
      size_t seed = 0;
      ::hash_combine(seed, v.first);
      ::hash_combine(seed, v.second);
      return seed;
    }
  };
}


int isPalindrome(const string& str, pii r){
    int s,e;
    s=r.first;
    e=r.second;
    while(s < e)
        if(str[s++]!=str[e--])
            return 0;
    return 1;
}
int solve(const string& s, pii r, unordered_map<pii,int>& sols, unordered_map<pii,bool>& pali, int d ){
    
//    cout<<d<<endl;
    int res=-1;
    if(r.first > r.second){
        res= 0;
        pali[r]=true;    
    }
    if(r.first == r.second){
        pali[r]=true;
        res= 1;
    }
    if(res==-1){
    auto src = sols.find(r);
    if(src!=sols.end()){
       cout<<"found "<<src->first.first<<" "<<src->first.second<<endl; 
        return src->second;
        
    }
     res=
        solve(s,make_pair(r.first,r.second-1),sols, pali,d+1) + 
        solve(s,make_pair(r.first+1,r.second),sols,pali,d+1) -
        solve(s,make_pair(r.first+1,r.second-1),sols,pali,d+1) ; 
    int inc = (s[r.first]==s[r.second] && pali[make_pair(r.first+1,r.second-1)])? 1 : 0;
    res+=inc; 
    pali[r] = (inc == 1)?  true : false; 
    }
    
   
    sols[r]=res; //memoize
    return res;
}
int main(){
    string s; cin>>s;
    int q; cin>>q;
    unordered_map<pii,int> sols;
    unordered_map<pii,bool> pali;
    while(q--){
        pii range; cin>>range.first>>range.second;
        range.first--;
        range.second--;
//        cout<<range.first<<" "<<range.second<<" == ";
        auto src = sols.find(range);
        if(src!=sols.end()){
            cout<<src->second<<endl;
        }
        else{
            int nsrc=solve(s,range,sols,pali,0);
            cout<<nsrc<<endl;
        }

    }
    return 0;
}
