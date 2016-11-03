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
#define S (3)

using namespace std;

char B[3][3];

bool win(const char c) {
    bool r=false;

    for(int j=0; j<3; j++) {
        r = r || ((B[j][0] == B[j][1]) && (B[j][1] == B[j][2]) && B[j][2] == c);
        r = r || ((B[0][j] == B[1][j]) && (B[1][j] == B[2][j]) && B[2][j] == c);
    }

     r = r || ((B[0][0] == B[1][1]) && (B[1][1] == B[2][2]) && B[2][2] == c);
     r = r || ((B[0][2] == B[1][1]) && (B[1][1] == B[2][0]) && B[2][0] == c);
    return r;
}

int main() {
    bool ill=false;
    bool wf,ws;
    wf=ws=false;
    int nf,ns;
    nf=ns=0;
    loop0n(i,S) {
        loop0n(j,S) {
            cin>>B[i][j];
            if(B[i][j]=='X')
                nf++;
            if(B[i][j]=='0')
                ns++;
        }
    }

    wf=win('X');
    ws=win('0');
    if((wf && ws) || ns>nf || (abs(ns-nf)>=2) || (wf && nf <= ns) || (ws && ns < nf) )
        ill=true;

    if(!ill) {
        if(wf)
            cout<<"the first player won"<<endl;
        else if(ws)
            cout<<"the second player won"<<endl;
        else if(ns+nf ==9)
            cout<<"draw"<<endl;
        else if(ns >= nf)
            cout<<"first"<<endl;
        else if(ns < nf)
            cout<<"second"<<endl;

    } else
        cout<<"illegal"<<endl;


    return 0;
}



