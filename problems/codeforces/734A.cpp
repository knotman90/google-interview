#include <bits/stdc++.h>


// Lambda has type: D -> T -> D
template <typename D, typename Iterator, typename Lambda>
D fold_idx(Iterator s, Iterator e,  D& acc, Lambda l) {
    int idx=0;
    while (s != e) {
        acc = l(acc, *s,idx);
        s++;
        idx++;
    }
    return acc;
}
template <typename D, typename Iterator, typename Lambda>
D fold(Iterator s, Iterator e, const D& a, Lambda l) {
    D acc = a;
    while (s != e) {
        acc = l(acc, *s);
        s++;
    }
    return acc;
}


// Useful constants
#define INF (int)1e9
#define EPS 1e-9
// Useful hardware instructions
#define bitcount __builtin_popcount
#define gcd __gcd
// Useful container manipulation / traversal macros
#define forall(i, a, b) for (int i = a; i < b; i++)
#define foreach(v, c) \
  for (typeof((c).begin()) v = (c).begin(); v != (c).end(); ++v)
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define pb push_back
#define fill(a, v) memset(a, v, sizeof a)
#define sz(a) ((int)(a.size()))
#define mp make_pair
// Some common useful functions
#define maX(a, b) ((a) > (b) ? (a) : (b))
#define miN(a, b) ((a) < (b) ? (a) : (b))
#define checkbit(n, b) ((n >> b) & 1)
#define DREP(a) \
  sort(all(a)); \
  a.erase(unique(all(a)), a.end())
#define INDEX(arr, ind) (lower_bound(all(arr), ind) - arr.begin())

// incremental loops
#define loop0n(i, n) for (int i = 0; i < n; ++i)
#define loopse(i, s, e) for (int i = s; i < e; ++i)
#define loopsei(i, s, e, inc) for (int i = s; i < e; i += inc)
// decremental loops
#define dloop0n(i, n) for (int i = n; i >= 0; --i)
#define dloopse(i, s, e) for (int i = s; i >= e; --i)
#define dloopsei(i, s, e, inc) for (int i = s; i >= e; i -= inc)
#define GET_LOOP(_1, _2, _3, _4, NAME, ...) NAME
#define LOOPUP(...) \
  GET_LOOP(__VA_ARGS__, loopsei, loopse, loop0n) \
(__VA_ARGS__)
#define LOOPDWN(...) \
  GET_LOOP(__VA_ARGS__, dloopsei, dloopse, dloop0n) \
(__VA_ARGS__)


#define pb push_back
#define ALL(v) v.begin(), v.end()

//for map, pair
#define mp make_pair
#define fi first
#define se second
//char to int 
inline int chrint(const char c){ return c - '0'; }

template<typename T>
inline T clamp(const T& n, const T& lo, const T& hi){
    return std::max(lo,std::min(n,hi));
}

template<class T>
class reader {
public:
    void operator()(T& t) const {
        std::cin>>t;
    }
};

template<class CONTAINER, class READ_Fn>
void read(CONTAINER& v, const unsigned int size, const READ_Fn& rfn) {
    using T=typename std::remove_reference<decltype(v[0])>::type;
    loop0n(i, size) {
        rfn(v[i]);
    }
}


typedef unsigned long ul;
typedef unsigned long long ull;
typedef signed long l;
typedef signed long long ll;
typedef unsigned int uint;

typedef std::pair<l,l> pll;
typedef std::pair<int,int> pii;
typedef std::pair<uint,uint> puu;

//sort pair based on their first component. If equal it uses the second ones.
auto pair_cmp = [](const pll& p1, const pll& p2)
    {
        return (p1.first < p2.first) || (p1.first==p2.first && p1.second < p2.second);
    };


//------ PROBLEM CODE --------------

using namespace std;

int main() {

    int n; cin>>n;
    int a=0,d=0;
    while(n--){
        char c; cin>>c;
        c == 'A' ? a++  : d++;  
    }
    if(a > d){
        cout<<"Anton";
    }
    else if(d > a)
        cout<<"Danik";

    else
        cout<<"Friendship";

    cout<<endl;
    return 0;
}

