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
inline int chrint(const char c) {
    return c - '0';
}

template<typename T>
inline T clamp(const T& n, const T& lo, const T& hi) {
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
typedef pair<pll,pll> triple;

map<pll,pll> hm;

int main() {
    int n;
    cin>>n;
    ll x=-1,y=-1,M=-1;

    loop0n(i,n) {
        array<ll,3> t;
        cin>>t[0]>>t[1]>>t[2];
        sort(ALL(t));
        ll a,b,c;
        a=t[0];
        b=t[1];
        c=t[2];
        ll m = a;

        pll p1,p2,p3;
        p1=mp(a,b);
        p2=mp(a,c);
        p3=mp(b,c);


        if(hm.find(p1) != hm.end()) {
            ll m = min(a,b); m = min(m,hm[p1].first+c);
            if( m > M ) { //new max
                M = m;
                x=hm[p1].second;
                y=i;
            }
            if(c > hm[p1].first) {
                hm[p1].first=c;
                hm[p1].second=i;
            }

        } else {
            hm[p1] = mp(c,i);
        }

        //p2
        if(hm.find(p2) != hm.end() && i != hm[p2].second) {
             ll m = min(a,c); m = min(m,hm[p2].first + b);
            if( m > M ) { //new max
                M = m;
                x=hm[p2].second;
                y=i;
            }
            if(b > hm[p2].first) {
                hm[p2].first=b;
                hm[p2].second=i;
            }

        } else {
            hm[p2] = mp(b,i);
        }


//p3
        if(hm.find(p3) != hm.end() && i!= hm[p3].second) {
            ll m = min(b,c); m = min(m,hm[p3].first+a);
            if(m > M) { //new max
                M = m;
                x=hm[p3].second;
                y=i;
            }
            if(a > hm[p3].first) {
                hm[p3].first=a;
                hm[p3].second=i;
            }

        } else {
            hm[p3] = mp(a,i);
        }

        if(a > M){
            M=a;
            x=i;
            y=-1;
        }

    }


    if(y!=-1){
        cout<<2<<endl<<x+1<<" "<<y+1<<endl;
        
    }else
        cout<<1<<endl<<x+1<<endl;
    return 0;
}


