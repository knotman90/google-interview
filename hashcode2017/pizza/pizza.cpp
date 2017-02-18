#include <bits/stdc++.h>

#include <gmpxx.h>
#include <functional>
#include <numeric>

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

#define BIT(n,i) ( ( n>>i )&1 )
#define pb push_back
#define ALL(v) v.begin(), v.end()

//for map, pair
#define mp make_pair
#define fi first
#define se second
//char to int
inline constexpr int ctoi(const char c) {
    return c - '0';
}
//int to char
inline constexpr char itoc(const int n) {
    return n + '0';
}

template<typename T> inline T clamp(const T& n, const T& lo, const T& hi) {
    return std::max(lo,std::min(n,hi));
}

template<class T> inline void sort(T &a) {
    std::sort(ALL(a));
}

template<class T1, class T2> inline void sort(T1 &a, T2 comp) {
    sort(ALL(a), comp);
}

template<class T> inline int read(T& n) {
    return std::cin >> n ? 1 : -1;
}
//reads multiple arguments
template<typename T, typename... types> inline int read(T &n, types &...args) {
    return read(n) == -1 ? -1 : read(args...) + 1;
}

template<class T> inline void write(const T& n) {
    std::cerr << n;
}
//reads multiple arguments
template<typename T, typename... types> inline void write(const char sep, T &n, types &...args) {
    write(n);
    write(sep);
    write(sep,args...);
}



template<typename T> inline constexpr bool odd(const T a) {
    return bool(a & 1);
}

template<typename T> inline constexpr bool even(const T a) {
    return !odd(a);
}

template<class T>
inline unsigned int mod (const T m, const T n) {
    return m >= 0 ? m % n : ( n - abs( m%n ) ) % n;
}

template<class T>
class reader {
public:
    void operator()(T& t) const {
        std::cin>>t;
    }
};

template<class CONTAINER, class READ_Fn>
void read(CONTAINER& v, const unsigned int size, const READ_Fn& rfn = reader<typename CONTAINER::value_type>()) {
    loop0n(i, size) {
        rfn(v[i]);
    }
}

template <class T>
int magnitude(T n) {
    int m=0;
    while(n) {
        m++;
        n/=10;
    }
    return m;
}


template<class T>
T ipow(T base, uint exp) {
    T result = 1;
    while (exp) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

//remove all elements from col which satisfies the predicate pre
template <typename Collection,typename Predicate>
void filterNot(Collection& col,Predicate pre ) {
    auto returnIterator = std::remove_if(col.begin(),col.end(),pre);
    col.erase(returnIterator,std::end(col));

}

//remove elements that do not satisfy the predicate
template <typename Collection,typename Predicate>
void filter(Collection& col,Predicate predicate) {
    filterNot(col,[predicate](typename Collection::value_type i) {
        return !predicate(i);
    });

}

template <typename Collection,typename unop>
void map(Collection& col,unop op) {
    std::transform(col.begin(),col.end(),col.begin(),op);

}
//TYPEDEFS
typedef unsigned long ul;
typedef unsigned long long ull;
typedef signed long l;
typedef signed long long ll;
typedef unsigned int uint;

typedef std::pair<l,l> pll;
typedef std::pair<int,int> pii;
typedef std::pair<double,double> pdd;
typedef std::pair<long  double,long double> pldd;
typedef std::pair<uint,uint> puu;

//sort pair based on their first component. If equal it uses the second ones.
auto pair_cmp = [](const pll& p1, const pll& p2) {
    return (p1.first < p2.first) || (p1.first==p2.first && p1.second < p2.second);
};


//high order fucntion functions


//------ PROBLEM CODE --------------
using namespace std;

class cut;
#define MAX (1001)
#define MUSHROOM (true)
#define TOMATO (!MUSHROOM)

bool P[MAX][MAX];
int O[MAX][MAX]={0};
vector<cut> SLICES;
int R,C,L,H;

class cut{
public:
    int x,y,r,c;
    cut(const int _x, const int _y, const int _r , const int _c)
        :x(_x), y(_y) , r(_r), c(_c){

    }

    void print()const {
        printf("%d %d %d %d\n", x,y,r,c);
    }
};


int ss=0;
void setOccupied(const cut& s){
    ss++;
    loop0n(i,s.r+1){
        loop0n(j,s.c+1){
            if(O[s.x+i][s.y+j])
            {

                cerr<<"MORTE!"<<endl;
                s.print();
                exit(-1);
            }
            O[s.x+i][s.y+j]=ss;
        }
    }
}


void _solve(const int sx, const int sy){
    int cM=C;
    vector<pii> S(C-sy);
    for (int i = 0; i < R-sx; ++i) {
        int mush=0;
        int tomato=0;
        for (int j = 0; j < cM-sy; ++j) {

            if(O[i+sx][j+sy]){
                cM=j+sy; //new right boundary
                break;
            }
            int ncells=((i+1)*(j+1));
            if(P[i+sx][j+sy]==MUSHROOM){
                S[j].first++;

            }
            else{ //TOMATO
                S[j].second++;

            }
            mush+=S[j].first;
            tomato+=S[j].second;
            //slice buona?
            if(mush>=L && tomato>=L && ncells<=H){
                //good slice
                cut s(sx,sy,i,j);
                SLICES.push_back(s);
                setOccupied(s);
                return;
            }
        }
    }
}



bool _expand(cut& s){

    bool cr, rb;
    int rowend=s.x+s.r+1;
    int colend=s.y+s.c+1;
    rb=rowend<R;
    for (int j = s.y; rb && j <= s.y+s.c; ++j) {
        if(O[rowend][j])
            rb=false;
    }
    cr=colend<C;
    for (int i = s.x; cr && i <= s.x+s.r; ++i) {
        if(O[i][colend])
            cr=false;
    }

    auto incR = [&](){
        cut dummys(rowend,s.y,0,s.c);
        setOccupied(dummys);
        s.r++;
    };

    auto incC = [&](){
        cut dummys(s.x,colend,s.r,0);
        setOccupied(dummys);
        s.c++;
    };

    if(cr && rb){
        if(s.r > s.c){
            incR();
        }else{
            incC();
        }
    }else{

        if(cr){
            incC();
        }
        if(rb){
            incR();
        }

    }
    return cr||rb;
}

void expand(){
    for(auto& c : SLICES){
        while(_expand(c)){}
    }
}

void solve(){
    std::default_random_engine g(time(0));
    std::uniform_int_distribution<int> RR(0,R);
    std::uniform_int_distribution<int> RC(0,C);

    /*loop0n(k,(R*C)){
       const int i=RR(g);
        const int j=RC(g);
        if(!O[i][j])
         _solve(i,j);

    }*/



    loop0n(i,R){
        loop0n(j,C){
            if(!O[i][j])
                _solve(i,j);
        }
    }
}

void readInput(){
    cin>>R>>C>>L>>H;
    loop0n(i,R){
        loop0n(j,C){
            char c; cin>>c;
            if(c=='T')
                P[i][j]=TOMATO;
            else
                P[i][j]=MUSHROOM;
        }
    }

}


void out(){
    cout<<SLICES.size()<<endl;
    for(auto& a : SLICES){
        cout<<a.x<<" ";
        cout<<a.y<<" ";

        cout<<a.x+a.r<<" ";
        cout<<a.y+a.c<<" ";
        cout<<endl;
    }
}

int main(){
    readInput();
    //    loop0n(i,R){
    //        loop0n(j,C){
    //            cerr<<P[i][j]<<" ";
    //        }
    //        cerr<<endl;
    //    }
    //    cerr<<"-"<<endl;

    solve();
    expand();
ss=0;
    loop0n(i,R){
        loop0n(j,C){
            O[i][j]=false;
        }
    }
    for(const auto& a : SLICES){
        setOccupied(a);
    }


    int ans=R*C;
    loop0n(i,R){

        loop0n(j,C){
            if(!O[i][j])
                ans--;
            cerr<<O[i][j]<<" ";
        }
        cerr<<endl;
    }
    cerr<<"Punteggio:"<<ans<<" "<<R*C<<endl;
    cerr<<(double)ans/((double)R*C)<<endl;
    //cerr<<"slices" <<endl;
    //    for(const auto& a : SLICES){
    //        a.print();
    //    }
    out();
    return 0;
}






