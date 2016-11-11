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

// Lambda has type: D -> T -> D
template <typename D, typename Iterator, typename Lambda>
D fold(Iterator s, Iterator e, const D& a, Lambda l) {
    D acc = a;
    while (s != e) {
        acc = l(acc, *s);
        s++;
    }
    return acc;
}

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


//------ PROBLEM CODE --------------

using namespace std;


template <class Iterator, typename T = typename std::iterator_traits<Iterator>::value_type >
pair<int,T> maxIdx (const Iterator start, const Iterator end) {
    pair<int,T> m {0,*start};
    auto ff = [&](pair<int,T> acc, const T& e, int idx) {
        if(e > acc.second) {
            acc.second=e;
            acc.first = idx;
        }
        return acc;
    };
    fold_idx(start,end,m,ff);
}

template<class T>
class reader {
public:
    void operator()(T& t) const {
        cin>>t;
    }
};

template<class CONTAINER, class READ_Fn>
void read(CONTAINER& v, const unsigned int size, const READ_Fn& rfn) {
    using T=typename std::remove_reference<decltype(v[0])>::type;
    loop0n(i, size) {
        rfn(v[i]);
    }
}




void ps(const int s, const int e,  int m ,bool b,const int N, ostringstream& ss) {
    int d =e-s;
    if(b) { //up
        for(int i=m; i<e && d > 0; i++,d--) {
            ss<<m-N<<" R"<<endl;
        }
        for(int i=m; i>s && d>0 ; i--,d--) {
            ss<<i-N<<" L"<<endl;
        }
    } else {
        for(int i=m; i>s && d>0 ; i--,m--,d--) {
            ss<<i-N<<" L"<<endl;
        }
        for(int i=m; i<e && d > 0; i++,d--) {
            ss<<m-N<<" R"<<endl;
        }
    }

}

int specialMax(vector<ll>& N, const int s, const int e, bool& up) {
    up=true;
    ll MAX = -1;
    int idx=-1;
    if(s==e) {
        return s;
    }
    for(int j=s; j<=e; j++) {
        if(N[j]> MAX) {
            if(j>s && N[j-1]<N[j]) {
                MAX=N[j];
                up=false;
                idx=j;

            }
            if(j<e && N[j+1]< N[j])
            {
                MAX=N[j];
                up=true;
                idx=j;
            }

        }
    }
    return idx;
}

int main() {
    int n;
    cin>>n;
    vector<ll> N(n);
    read(N,n, reader<ll>());
    int m;
    cin>>m;
    vector<ll> M(m);
    read(M,m,reader<ll>());
    string sss; sss.reserve(500*5);
    ostringstream ss(sss);
    int k=0;
    int s;
    int e;
    for( s=0; s<n;) {
        bool up;
        int l=0;
        ll sum=0;
        for( e=s; e<n; e++, l++) {

            sum+=N[e];
            if(sum==M[k]) {
                int idx=specialMax(N,s,e,up);
                if(idx==-1) {
                    cout<<"NO"<<endl;
                    return 0;
                }
                ps(s,e,idx,up,s-k-1,ss);
                k++;
                s=e+1;
                break;

            } else if (sum > M[k]) {
                cout<<"NO\n";
                return 0;
            }

        }
        if(e>=s){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(k<m) {
        cout<<"NO"<<endl;

    } else
    {
        cout<<"YES"<<endl;
        cout<<ss.str();
    }
    return 0;
}




