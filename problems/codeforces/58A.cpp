#include <bits/stdc++.h>

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

// Input macros
#define s(n) scanf("%d", &n)
#define sc(n) scanf("%c", &n)
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define ss(n) scanf("%s", n)

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

inline void printIf(const bool p,const char* a, const char* b ) {
    if(p)
        std::cout<<a;
    else
        std::cout<<b;
    std::cout<<std::endl;
}
using namespace std;


int main() {
    string S;
    cin>>S;
    int h,l,o,e;
    h=l=o=e=0;
    bool ok=false;
    loop0n(i,S.size())
    {
        
        switch (S[i]) {
        case 'h':
            h++;
            break;
        case 'l':
            l= (h && e) ? l+1 : l;;
            break;
        case 'o':
            o = (h && e && l ) ? o+1 : o;
            break;
        case 'e':
            e= h ? e+1 : e;
            break;
        }
        if(h && l>=2 && o && e) {

            ok=true;
            break;
        }
    }

    printIf(ok,"YES","NO");
    return 0;
}




