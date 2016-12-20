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

typedef array<ll,4> piece;
int main() {
    int n;
    cin>>n;
    long long xk,yk;
    cin>>xk>>yk;
    vector<piece> P(n);
    loop0n(i,n) {
        piece p;
        char c;
        cin>>c;
        p[0] = (int)c;
        cin>>p[1];
        cin>>p[2];
        p[3] = sqrt((p[1]-xk)*(p[1]-xk) + (p[2]-yk)* ( p[2]-yk ) );
        P[i]=p;
    }
    auto s = [](piece p1, piece p2) {
        return p1[3]<p2[3];
    };
    sort(ALL(P),s);

    array<bool,8> V= {0};

    bool ok=false;
    loop0n(i,n) {
        piece p = P[i];
        if(xk == p[1]) {
            if(p[2]< yk) {
                if(p[0]==(int)'B')
                    V[4]=true;
                else if (p[0] ==(int)'R' || p[0] == (int)'Q') {
                    if(V[4]==false) {
                        ok=true;
                        break;
                    }
                }
            } else {
                if(p[0]==(int)'B')
                    V[0]=true;
                else if (p[0] ==(int)'R' || p[0] == (int)'Q')
                    if(V[0]==false) {
                        ok=true;
                        break;
                    }
            }


        }

        if(yk == p[2]) {
            if(p[1]< xk) {
                if(p[0]==(int)'B')
                    V[2]=true;
                else if (p[0] ==(int)'R' || p[0] == (int)'Q') {
                    if(V[2]==false) {
                        ok=true;
                        break;
                    }
                }
            } else {
                if(p[0]==(int)'B')
                    V[6]=true;
                else if (p[0] ==(int)'R' || p[0] == (int)'Q')
                    if(V[6]==false) {
                        ok=true;
                        break;
                    }
            }


        }



        ll d1,d2;
        d1 = xk-p[1];
        d2 = yk-p[2];
        if(d1==d2 ) {
            if(d1>=0 && d2>=0)
            {
                if(p[0]==(int)'R')
                    V[7]=true;
                else if (p[0] ==(int)'B' || p[0] == (int)'Q') {
                    if(V[7]==false) {
                        ok=true;
                        break;
                    }
                }
            } else {
                if(p[0]==(int)'R')
                    V[3]=true;
                else if (p[0] ==(int)'B' || p[0] == (int)'Q') {
                    if(V[3]==false) {
                        ok=true;
                        break;
                    }
                }
            }
        }
        else if (d1==-d2) {
            if(d1>0 && d2>0) {
                if(p[0]==(int)'R')
                    V[5]=true;
                else if (p[0] ==(int)'B' || p[0] == (int)'Q') {
                    if(V[5]==false) {
                        ok=true;
                        break;
                    }
                }

            } else {
                if(p[0]==(int)'R')
                    V[1]=true;
                else if (p[0] ==(int)'B' || p[0] == (int)'Q') {
                    if(V[1]==false) {
                        ok=true;
                        break;
                    }
                }

            }
        }


    }
    if(ok){
        cout<<"YES"<<endl;
    }
    else
        cout<<"NO"<<endl;


        return 0;
}







