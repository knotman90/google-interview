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
inline constexpr int ctoi(const char c)
{
    return c - '0';
}
//int to char
inline constexpr char itoc(const int n)
{
    return n + '0';
}

template<typename T> inline T clamp(const T& n, const T& lo, const T& hi)
{
    return std::max(lo,std::min(n,hi));
}

template<class T> inline void sort(T &a)
{
    std::sort(ALL(a));
}

template<class T1, class T2> inline void sort(T1 &a, T2 comp)
{
    sort(ALL(a), comp);
}

template<class T> inline int read(T& n)
{
    return std::cin >> n ? 1 : -1;
}
//reads multiple arguments
template<typename T, typename... types> inline int read(T &n, types &...args)
{
    return read(n) == -1 ? -1 : read(args...) + 1;
}

template<class T> inline void write(const T& n)
{
    std::cout << n;
}
//reads multiple arguments
template<typename T, typename... types> inline void write(const char sep, T &n, types &...args)
{
    write(n);
    write(sep);
    write(sep,args...);
}



template<typename T> inline constexpr bool odd(const T a)
{
    return bool(a & 1);
}

template<typename T> inline constexpr bool even(const T a)
{
    return !odd(a);
}

template<class T>
inline unsigned int mod (const T m, const T n)
{
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

//TYPEDEFS
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

typedef array<short,10> digits;

void intToDigits( ll n, digits& ds) {
    while(n>0) {
        ds[n%10]++;
        n/=10;
    }

}

bool sameDigits(const digits& ds, const digits& dk) {
    for(int i=0; i<10; i++)
        if(ds[i]!=dk[i])
            return false;
    return true;
}

void getPrimes(vector<long long>& primes, const int n) {
    primes.push_back(2);
    for(int i=3; i<=n; i+=2) {
        bool p = true;
        for(int j=2; p && j<=sqrt(i); j++) {
            if(i%j==0)
                p=false;
        }
        if(p)
            primes.push_back(i);
    }
}
void solve70(const int size) {
    vector<long long> primes;
    getPrimes(primes,1000000);
    double m = LONG_MAX;
    for(ll n=0; n < primes.size() ; n++) {
        for(ll k=n+1; k<primes.size(); k++) {
            ll b=primes[n]*primes[k];
            ll phi = b-primes[n]-primes[k]+1;
            if(b<=size)
            {
                digits dn= {0};
                intToDigits(b,dn);
                digits dk= {0};
                intToDigits(phi,dk);
                double ratio = (double)b/(double)phi;
                if(sameDigits(dn,dk) && ratio < m) {
                    m = ratio;
                    cout<<primes[n]<< " "<<primes[k]<<" "<<b<<" "<<phi<<" "<<m<<endl;


                }
            }
            else
                break;
        }
    }
}

#include "InfInt.h"
template<class T>
T MCD(const T& n, const T& d) {
    T r=n-d*(n/d);
    if(r==0)
        return d;
    return MCD<T>(d,r);
}

template<class T>
class Rational {
public:
    T  num;
    T den;
    Rational(const T& _num, const T& _den) : num(_num), den(_den) {}

    void simplify() {
        T mcd = MCD(min(num,den),max(num,den));
        while(mcd > 1) {
            num/=mcd;
            den/=mcd;
            mcd=MCD(num,den);
        }
    }
    Rational operator*(const Rational& p) {
        Rational r(*this);
        r.num*=p.num;
        r.den*=p.den;
        r.simplify();
        return r;
    }
    Rational operator/(const Rational& p) {
        Rational pp(p.den,p.num);
        Rational r(*this);
        return r*pp;
    }
    Rational operator+(const Rational& p) {
        Rational r(*this);
        T nden=p.den*r.den;
        T nnum = (nden/r.den)*r.num + (nden/p.den)*p.num;
        r.num=nnum;
        r.den=nden;
        r.simplify();
        return r;
    }
    void show() {
        cout<<num<<"/"<<den;
    }
};

typedef Rational<InfInt> Rati;

Rati compute(int it, int k, const int limit) {
    Rati t(1,1);
    Rati one(1,1);

    if(it%3==1) {
        k++;
        t.num=2*k;
    }

    if(it==limit)
        return t;

    Rati res = one/compute(it+1,k,limit);
    Rati ans = (t+res);
    ans.simplify();
    return ans;


    return ans;
}
void solve() {
    int limit=300;
    int start=1;

    Rati two (2,1);
    Rati one(1,1);
    (two+(one/compute(0,0,limit))).show();
//the use the followings on ghci to get the sum of the digits in the numerator
//let n = intToList (numeratorfromTheOutput)
//foldr (\x acc-> (digitToInt x) +acc) 0 n

}

void solve72() {
    typedef long double ld;
    ld minimum = -1000;
    int n=1;
    const int LIM = 1000000;
    while(n<LIM) {
        int limit=(n*7)/3;
        int c=0;
        while(limit <= LIM) {
            if(MCD(n,limit)==1 ) { /*&& ratio > minimum*/
                c++   ;
                printf("new minimum = %d/%d=%d\n", n,limit,c);
                break;
            }


            limit++;
        }
        n++;
    }

    printf("\n");

}
void solve71() {
    typedef long double ld;
    ld minimum = -1000;
    int n=1;
    const int LIM = 1000000;
    while(n<LIM) {
        int limit=(n*7)/3;
        int c=0;
        while(limit <= LIM) {
            ld ratio = (long double)n/(long double)limit;
            if(ratio < minimum)
                break;
            if(MCD(n,limit)==1 && ratio < (3.0/7.0) /*&& ratio > minimum*/) {
                ld diff = 3.0/7.0 - ratio;
                minimum = ratio;
                printf("new minimum = %d/%d=%.20Lf %.20Lf\n", n,limit,ratio,diff);
                break;
            }


            limit++;
        }
        n++;
    }

    printf("\n");

}

void solve73() {
    ll ans=0;
    int n=1;
    const int LIM = 12000;
    while(n<LIM) {
        int lowerBound=2*n;
        int upperBound=3*n;
        int c=0;
        int limit=lowerBound+1;
        while(limit < upperBound && limit<=LIM) {
            if(MCD(n,limit)==1 ) {
                ans++;
                //printf("%d/%d\n", n,limit);
            }


            limit++;
        }
        n++;
    }

    printf("%d\n",ans);

}


template< class T>
T phi( T n) {
    T result = n;
    for(T i=2; i*i <= n; i++) {
        if (n % i == 0) result -= result / i;
        while (n % i == 0) n /= i;
    }
    if (n > 1) result -= result / n;
    return result;
}
void solve72_real() {
    ll limit=1000000;
    ll ans=0;
    for(ll i=2; i <= limit ; i++) {
        ans+=phi<ll>(i);
    }
    cout<<ans<<endl;
}


void solve74() {
    array<ll,10> factorials= {1,1,2,6,24,120,720,5040,40320,362880};
    ll LIM=1000000;
    ll ans=0;
    for(ll n=3; n<LIM; n++ ) {
        ll nn=n;
        vector<ll> chain;
        auto it =chain.begin();
        it = find(chain.begin(),chain.end(), nn);
        while( it== chain.end()) {
            chain.push_back(nn);
            ll sum=0;
            ll d=nn;
            while(d) {
                sum+=factorials[d%10];
                d/=10;
            }
            nn=sum;
            it = find(chain.begin(),chain.end(), nn);
        }
        auto it2 = chain.end();

        if(chain.size()==60)
        {
            ans++;
//            cout<<n<<endl;
        }

    }
    cout<<ans<<endl;
}



void solve77() {
    //how many way you can write 100 as a sum of at leat two numbers?
    vector<ll> primes;
    getPrimes(primes,10000);
    vector<int> w(10000,0);
    w[0]=1;
    int sum=0;

    int j=0;
    for(int i=0; i<primes.size(); i++) { //using only the first i primes (i included)
        for(j=primes[i]; j<=primes[primes.size()-1]; j++) {
            w[j] += w[j-primes[i]];
            if(w[j]>5000)
                break;
        }

    }
    for(int i=0; i<=100; i++)
        if(w[i]>5000) {
            cout<<i<<" "<<w[i]<<endl;
            break;

        }
}

void solve76() {
    //how many way you can write 100 as a sum of at leat two numbers?
    int w[101] = {0};
    w[0]=1;
    for(int i=1; i<100; i++) { //using only number <= 99
        for(int j=i; j<=100; j++) {
            w[j] += w[j-i];
        }

    }
    for(int i=0; i<=100; i++)
        cout<<i<<" "<<w[i]<<endl;

}


constexpr const int S=80;
ll E[S][S];
ll M[S][S];

ll dagMinimum(const int r, const int c) {
    if(E[r][c] != -1)
        return E[r][c];

    ll right = r+1 < S ? dagMinimum(r+1,c) : LLONG_MAX;
    ll left  = c+1 < S ? dagMinimum(r,c+1) : LLONG_MAX;
    ll ans =   M[r][c] + min(left,right);
    E[r][c] = ans;
    return ans;
}


void solve81() {
    loop0n(i,S) {
        loop0n(j,S) {
            ll a;
            scanf("%lld,",&a);
            M[i][j]=a;
            E[i][j] =-1;
        }
    }
    E[S-1][S-1]=M[S-1][S-1];
    ll ans=dagMinimum(0,0);
    cout<<ans<<endl;

}


//required dijkstra. min is implemented naively. use a priority queue instead.
//yet works.
void solve82() {
    loop0n(i,S) {
        loop0n(j,S) {
            ll a;
            scanf("%lld,",&a);
            M[i][j]=a;
            E[i][j] =-1;
        }
    }

    ll min=LLONG_MAX;
    ll W[S][S];
    bool V[S][S];
    typedef pair<ll,pii> pllii;
    priority_queue<pllii> Q;
    for(int i=0; i<S; i++) {
        //init dijkstra
        loop0n(k,S) {
            loop0n(l,S) {
                W[k][l]=LLONG_MAX;
                V[l][k]=false;
            }
        }
        W[i][0]=0;

        auto getMin = [&](auto& x, auto&y) {
            x=-1;
            y=-1;
            ll m = LLONG_MAX;
            loop0n(i,S) {
                loop0n(j,S) {
                    if(!V[i][j] && W[i][j] < m)
                    {
                        m = W[i][j];
                        x=i;
                        y=j;
                    }
                }
            }
        };

        int x,y;
        getMin( x,y );
        while(x!=-1 && y!=-1) {
            V[x][y] = true;
            if(x>0 && !V[x-1][y] && W[x][y] + M[x-1][y] < W[x-1][y]) {
                W[x-1][y] = W[x][y]+M[x-1][y];
            }
            if(x<S-1 && !V[x+1][y] && W[x][y] + M[x+1][y] < W[x+1][y]) {
                W[x+1][y] = W[x][y]+M[x+1][y];
            }
            if(y<S-1 && !V[x][y+1] && W[x][y] + M[x][y+1] < W[x][y+1]) {
                W[x][y+1] = W[x][y]+M[x][y+1];
            }
            getMin(x,y);

        }


        loop0n(j,S) {
            if(W[j][S-1]< min) {
                min = W[j][S-1];
                cout<<"min is "<<W[j][S-1]+ M[i][0]<<" "<<i<<"->"<<j<<endl;

            }

        }

    }
}

//required dijkstra. min is implemented naively. use a priority queue instead.
//yet works.
void solve83() {
    loop0n(i,S) {
        loop0n(j,S) {
            ll a;
            scanf("%lld,",&a);
            M[i][j]=a;
            E[i][j] =-1;
        }
    }

    int i=0;
    ll min=LLONG_MAX;
    ll W[S][S];
    pii P[S][S];
    bool V[S][S];
    typedef pair<ll,pii> pllii;
    priority_queue<pllii> Q;
    //init dijkstra
    loop0n(k,S) {
        loop0n(l,S) {
            W[k][l]=LLONG_MAX;
            V[l][k]=false;
            P[k][l]=mp(-1,-1);
        }
    }
    W[i][0]=M[i][0];

    auto getMin = [&](auto& x, auto&y) {
        x=-1;
        y=-1;
        ll m = LLONG_MAX;
        loop0n(i,S) {
            loop0n(j,S) {
                if(!V[i][j] && W[i][j] <= m)
                {
                    m = W[i][j];
                    x=i;
                    y=j;
                }
            }
        }
    };

    int x,y;
    getMin( x,y );
    while(x!=-1 && y!=-1) {
        V[x][y] = true;
        if(x>0 && !V[x-1][y] && W[x][y] + M[x-1][y] < W[x-1][y]) {
            W[x-1][y] = W[x][y]+M[x-1][y];
            P[x-1][y] = mp(x,y);
        }
        if(x<S-1 && !V[x+1][y] && W[x][y] + M[x+1][y] < W[x+1][y]) {
            W[x+1][y] = W[x][y]+M[x+1][y];
            P[x+1][y] = mp(x,y);
        }
        if(y<S-1 && !V[x][y+1] && W[x][y] + M[x][y+1] < W[x][y+1]) {
            W[x][y+1] = W[x][y]+M[x][y+1];
            P[x][y+1] = mp(x,y);
        }
        if(y>0 && !V[x][y-1] && W[x][y] + M[x][y-1] < W[x][y-1]) {
            W[x][y-1] = W[x][y]+M[x][y-1];
            P[x][y-1] = mp(x,y);
        }

        getMin(x,y);

    }


    if(W[S-1][S-1]< min) {
        min = W[S-1][S-1];
        cout<<"min is "<<min<<" "<<i<<"->"<<endl;
        /*   pii s = mp(S-1,S-1);
           while(s.first != -1 && s.second!=-1){
               cout<<"("<<s.first<<" "<<s.second<<") -> ";
               s=P[s.first][s.second];
           }
           cout<<endl;*/

    }
}


//problem 61
bool found=false;
array<bool,6> type= {false};

class node {
public:
    node(const int nn, const int tt) {
        n=nn;
        t=tt;
    }
    int n;
    int t;
    vector<node*> neigh;
};

vector<node> G;
vector<node> c;

auto last = [](const int n) {
    return n%100;
};
auto first = [](const int n) {
    return n/100;
};
inline bool canVisit(node n) {
    return !type[n.t];
}
void visit(node n, int l) {
    for( auto nn : n.neigh ) {
        if(l>=5 && canVisit(*nn) && last((*nn).n)==first(c[0].n )) {
            found=true;
            c.push_back(*(nn));
            return;
        }
        if(canVisit(*nn)) {
            c.push_back(*nn);
            type[(*nn).t]=true;
            visit(*nn,l+1);
            if( found )
            {
                return;
            } else {
                c.pop_back();
                type[(*nn).t]=false;
            }

        }
    }
}

void solve61() {

    auto addNode= [&](const int n, const int t) {
        if(n>=1000 && n<=10000) {
            node nn(n,t);
            G.push_back(nn);
        }
    };
    auto tri = [](const int i) {
        return (i*(i+1))/2;
    };
    auto oct = [](const int i) {
        return (i*(3*i-2));
    };
    auto pent = [](const int i) {
        return (i*(3*i-1))/2;
    };
    auto hex = [](const int i) {
        return (i*(2*i-1));
    };
    auto hep = [](const int i) {
        return (i*(5*i-3))/2;
    };
    auto square = [](const int i) {
        return (i*(i));
    };

    int n = 0;
    int i = 0;
    while(n<=10000) {
        n=square(i);
        addNode(n,0);
        n=oct(i);
        addNode(n,1);
        n=pent(i);
        addNode(n,2);
        n=hex(i);
        addNode(n,3);
        n=hep(i);
        addNode(n,4);
        n=tri(i);
        addNode(n,5);
        i++;
    }

    for(auto& v : G) {
        for(auto& q : G) {
            if(v.t != q.t && last(v.n)>9 && last(v.n)==first(q.n))
                v.neigh.push_back(&q);
        }
    }

    for(auto &v : G) {
        c.push_back(v);
        type[v.t]=true;
        visit(v,1);
        if(found)
            break;
        c.pop_back();
        type[v.t]=false;
    }
    int sum=0;
    if(found) {
        for(int i=0; i<c.size(); i++)
            sum+=c[i].n;
        cout<<"found sol "<< sum<<endl;


    }
}

int periodic2(vector<int>& v) {
    if( v.size() < 2 || v.size()%2 != 0)
        return -1;
    int h = v.size()/2;
    for(int i=0; i < h ; i++) {
        //if( (i <(h-1 ) && v[i] != v[i+h]) || ( i==(h-1) && abs(v[i]-v[i+h]) > 1))
        if(v[i] != v[i+h])
            return -1;
    }
    return h;
}

void solve64() {
    typedef float  FLOAT;
    constexpr const int LIM = 10000;
    constexpr const FLOAT EPS2 = 0.00001;
    int ans=0;
    for(int i=2 ; i<=LIM; i++) {
        int a0, a1,den,denold;
        a0=0;
        den=1;
        denold=1;
        FLOAT intpart;
        FLOAT tgt = -1;
        FLOAT fracpart=modf(sqrt(i),&intpart);
        a0=intpart;
        int sign=1;
        int it=0;
        if(fracpart >= EPS2)
            do {
                den=(i-a0*a0);
                FLOAT R1 = (denold*(sqrt((FLOAT)i)+sign*(FLOAT)a0)) / den;
                modf(R1,&intpart);
                den/=denold;
                denold=1;
                a1=intpart;
                int na = (-a1*den)+abs(a0);
                a0=na;
                fracpart=den/(sqrt(i)+a0);
                denold=den;
                sign=-1;
                if(it==0)
                    tgt=fracpart;
                it++;
            } while(fabs(fracpart-tgt)>=EPS2  || it <=1 ) ;
            if(it > 1 && ((it-1)%2)!=0){
                ans++;    
            }
    }
    cout<<"sol: "<<ans<<endl;
}

template<class T>
bool isPerfectSquare(const T d){
    long double intpart, fractpart;
    fractpart = modf(sqrtl(d), &intpart);
    return fractpart <= 0.000001;
}

template <class T>
int magnitude(T n){
    int m=0;
    while(n){
        m++;
        n/=10;
    }
    return m;
}

void solve66(){
    typedef ll T;
    InfInt max=-1;
    for(T d=62; d<=1000; d++){
        if(!isPerfectSquare<T>(d)){
            bool go=true;
            for(T x=1; go ; x++){
                 long double y2 = ((long double)x)/sqrtl((long double)d);
                 long double intp,floatp;
                 floatp=modf(y2,&intp);
                 long double p = 0.0001;//1.0/(long double)pow10(magnitude<T>(x)); 
                // cout<<setprecision(10)<<d<<" "<<x<<" "<<y2<<" "<<p<<endl;;
                 long double diff = fabs(1.0-floatp);
                 if(intp>0 && (floatp <=p || diff <= p )){
                    long double candintp;
                    if(diff <=p){
                        intp=intp+1;
                    }
                    InfInt xi = x;
                    InfInt di=d;
                    InfInt intpi =(ll)intp;
                    InfInt res = xi*xi -di*intpi*intpi;
                         //printf("CANDIDATE-> %lld^2 - %lld*%lld^2 = 1\n",x,d,(T)intp);
                    //cout<<res<<endl;
                  
                    InfInt one =1;
                    if( one== res ){
                        printf("GOOD-> %lld^2 - %lld*%lld^2 = 1\n",x,d,(T)intp);
                    cout<<res<<endl;
                    if(xi>max)
                        max=xi;
                        go = false;

                }
            }
        }
    }
}
cout<<max<<endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    solve66();


    return 0;
}







