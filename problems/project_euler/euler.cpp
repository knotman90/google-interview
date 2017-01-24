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

#define BIT(n,i) ( ( n>>i )&1 )
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

template <class T>
int magnitude(T n) {
    int m=0;
    while(n) {
        m++;
        n/=10;
    }
    return m;
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

bool sameDigits(const digits& ds, const digits& dk, const int s=0, const int e=10) {
    for(int i=s; i<e; i++)
        if(ds[i]!=dk[i])
            return false;
    return true;
}


void getPrimesSieve(vector<long long>&primes, const ll n) {
    vector<bool> nums(n+1,true);
    primes.push_back(2);
    for(ll i=3; i*i<n+1; i+=2) {
        if(nums[i]) {
            for(ll j=i*i; j<n+1; j+=2*i) {
                nums[j]=false;
            }
        }
    }

    for(ll i =3 ; i <=n ; i+=2)
        if(nums[i])
            primes.push_back(i);
}

void parallelSieve( vector<ll>& primes , const ll n, const int slice ) {

    for(int l = 2 ; l <= n ; l+=slice) {
        int r = clamp<long long>(l+slice,-1,n);

    }

}


void getPrimes(vector<long long>& primes, const ll n, const ll s=2) {
    if(s<=2)
        primes.push_back(2);
    for(int i=s; i<=n; i+=2) {
        bool p = true;
        for(int j=2; p && j<=sqrt(i); j++) {
            if(i%j==0)
                p=false;
        }
        if(p)
            primes.push_back(i);
    }
}

inline bool goodDigits(const digits& d, const int s , const int e) {
    for(int i=s; i<e; i++)
        if(d[i]>1)
            return false;
    return true;
}


void solve38() {
    ll LIM = 987654321;
    digits target= {0};
    intToDigits(LIM,target);
    for(ll i=1; i<10000 ; i++) {
        ll n=0;
        ll k=0;
        digits dn = {0};
        intToDigits(n,dn);
        while(!sameDigits(target,dn,1,10) && dn[0]==0) {
            k++;
            n=i*k;
            intToDigits(n,dn);
            if(!goodDigits(dn,1,10))
                break;
        }
        if(k>1 && sameDigits(target,dn,1,10) && dn[0]==0) {
            cout<<i <<"->";
            for(int j=1; j<=k; j++)
                cout<<i*j<<"";
            cout<<endl;
        }
    }

}

void solve17() {
    unordered_map<int,int> map;
    ll ans=4;//zero
    map[1] = 3;
    map[2]=3;
    map[3]=5;
    map[4] = 4;
    map[5]=5;
    map[6]=3;
    map[7]=5;
    map[8]=5;
    map[9]=4;
    map[10]=3;
    map[11]=6;
    map[12]=6;
    map[13]=8;
    map[20]=6;
    map[30]=7;
    map[40]=6;
    map[50]=5;
    map[60]=5;
    map[70]=7;
    map[80]=6;
    map[90]=6;
    map[100]=7;
    for(int i=1; i<13; i++) {
        ans+=map[i];
    }
    for(int i=14; i<20; i++) {
        int d = i%10;
        ans+=map[d] + 4;
    }

    for(int i=21; i<=99; i++) {

        int d=i%10;
        if(d!=0)
            ans+=map[d]+3+map[i-d];
    }

    for(int i=100; i<1000; i++) {
        int n=i;
        int d0=n%10;
        n/=10;
        int d1=n%10;
        n/=10;
        int d2=n%10;
        ans+= map[d2] + map[100];
        if(d1) {
            ans+=map[d1*10];
            if(d2)
                ans+=1+map[d1];
        }

    }

}

bool isPandigital(const digits& dn, const int s, const int e) {
    int i=s;
    for(; i<e; i++) {
        if(dn[i]>1)
            return false;
        if(!dn[i])
            break;
    }
    for(; i<e; i++)
        if(dn[i])
            return false;

    return true;
}

void solve43() {
    bool go=true;
    digits dn= {0};
    ll ans=0;
    for(int i1=1; i1<=9; dn[i1]--, go=true,i1++) {
        dn[i1]++;
        go=goodDigits(dn,0,10);

        for(int i2=0; go && i2<=9; dn[i2]--, go=true, i2++) {
            dn[i2]++;
            go=goodDigits(dn,0,10);

            for(int i3=0; go &&  i3<=9; dn[i3]--, go=true, i3++) {
                dn[i3]++;
                go=goodDigits(dn,0,10);

                for(int i4=0; go &&  i4<=9;  dn[i4]--, go=true,i4++) {
                    dn[i4]++;
                    go=goodDigits(dn,0,10);
                    int d24=100*i2 + 10*i3 +i4;
                    go= go&& (d24%2==0);

                    for(int i5=0; go && i5<=9;  dn[i5]--, go=true,i5++) {
                        dn[i5]++;
                        go=goodDigits(dn,0,10);
                        int d35 = 100*i3 +10*i4+i5;
                        go = go && (d35%3==0);

                        for(int i6=0; go && i6<=9;  dn[i6]--, go=true,i6++) {
                            dn[i6]++;
                            go=goodDigits(dn,0,10);
                            int d46 = 100*i4 +10*i5+i6;
                            go = go && (d46%5==0);

                            for(int i7=0; go && i7<=9;  dn[i7]--, go=true,i7++) {
                                dn[i7]++;
                                go=goodDigits(dn,0,10);
                                int d57 = 100*i5 +10*i6+i7;
                                go = go && (d57%7==0);

                                for(int i8=0; go && i8<=9;  dn[i8]--, go=true,i8++) {
                                    dn[i8]++;
                                    go=goodDigits(dn,0,10);
                                    int d68 = 100*i6 +10*i7+i8;
                                    go = go && (d68%11==0);

                                    for(int i9=0; go && i9<=9;  dn[i9]--, go=true,i9++) {
                                        dn[i9]++;
                                        go=goodDigits(dn,0,10);
                                        int d79 = 100*i7 +10*i8+i9;
                                        go = go && (d79%13==0);

                                        for(int i10=0; go && i10<=9;  dn[i10]--, go=true,i10++) {

                                            dn[i10]++;
                                            go=goodDigits(dn,0,10);
                                            int d810 = 100*i8 +10*i9+i10;
                                            go = go && (d810%17==0);

                                            if(go && isPandigital(dn,0,10)) {
                                                int nn=0;
                                                //printf("-------%d%d%d%d%d%d%d%d%d%d --- %d,%d,%d,%d\n",i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,d24,d35,d46,d57);
                                                auto multsum = [](const ll& a,  ll& n) {
                                                    n=n*10+a;
                                                };
                                                ll n =0;
                                                multsum(i1,n);
                                                multsum(i2,n);
                                                multsum(i3,n);
                                                multsum(i4,n);
                                                multsum(i5,n);
                                                multsum(i6,n);
                                                multsum(i7,n);
                                                multsum(i8,n);
                                                multsum(i9,n);
                                                multsum(i10,n);
                                                ans+=n;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}



//problem 60 ----------------------------------

inline long long concat(const long long i, const long long j) {
    return  i*pow10(magnitude(j))+j;
}

bool primalityTest(const long long n) {

    for(long i=2 ; i <= sqrt(n)+1 ; i++)
        if(n%i==0)
            return false;
    return true;
}

void solve60() {
    constexpr const long LIMP =30000;
    constexpr const int LIM = 2000;
    vector<ll> primes;
    getPrimesSieve(primes,LIMP);

    unordered_map<long long, bool> concatPrime;

    auto isPrime = [&](const long long& n) {
        if( concatPrime.find(n) == concatPrime.end())
            concatPrime[n]=primalityTest(n);

        return concatPrime[n];

    };
    auto goodSet = [&](const array<long long ,5>& vec, const int p) {
        for(int i=0; i < p ; i++) {
            if(
                !(isPrime( concat(vec[i],vec[p]) )  && isPrime(concat(vec[p],vec[i]) ) )
            )
                return false;
        }
        return true;
    };
    bool go=true;
    array<long long ,5> pset = {0,0,0,0,0};
    for(int i=1 ; i < LIM ; i++ ) {
        pset[0]=primes[i];
        for(int j=i+1 ; j<LIM ; j++) {
            pset[1]=primes[j];
            if( goodSet(pset,1) ) {

                for(int l=j+1; l<LIM; l++) {
                    pset[2] = primes[l];
                    if(goodSet(pset,2) ) {

                        for(int k=l+1; k<LIM; k++) {
                            pset[3] = primes[k];
                            if(goodSet(pset,3)) {

                                // printf("%d %d %d %d \n" , primes[i],primes[j],primes[l] , primes[k]);
                                for(int m=k+1; m<LIM ; m++) {
                                    pset[4]=primes[m];
                                    if(goodSet(pset,4)) {
                                        printf("%d +%d +%d +%d +%d= %d\n" , primes[i],primes[j],primes[l] , primes[k], primes[m], primes[i]+primes[j]+primes[l] + primes[k]+ primes[m]);
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

//end of problem 60



void solve41() {
    vector<long long> primes;
    //getPrimesSieve(primes,987654321);
    //no prime can be made by using once all 9 digits because 1+2+3+4+5+6+7+8+9=45
    //which is divisible by 3. Any number which digits are divisible by 3 is divisible by 3!
    //same reasoning for 8. we can limit our search to 7654321
    getPrimesSieve(primes,7654321);
    for(int i=primes.size()-1; i>=0 ; i--) {
        digits dn = {0};
        intToDigits(primes[i],dn);
        if(isPandigital(dn,1,10) && dn[0]==0) { //0 digit has not to be present in 1-n pandigital
            cout<<primes[i]<<endl;
            break;
        }
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

void solve92() {
    array<ll,10> squares = {0,1,4,9,16,25,36,49,64,81};
    ll LIM= 10000000;
    ll ans = 0;
    for(ll i = 1 ; i<LIM ; i++) {
        ll n = i;
        while(n!=89 && n!=1) {
            ll n1=n;
            ll newn=0;
            while(n1) {
                newn+=squares[n1%10];
                n1/=10;
            }
            n=newn;
        }
        if(n==89)
            ans++;
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

ll numRec(const ll r, const ll m) {
    return (r*m*(r+1)*(m+1))/4;
}
void solve85() {
    ll m;
    ll n ;
    m=n=4;
    constexpr const ll LIM =2000000;
    bool go =true;
    int i=1;
    ll k=-1;;
    ll min = LLONG_MAX;
    ll mm=10000,nn=10000;
    ll ans=0;

    int L =2000;
    for(m=1; m<L; m++) {
        for(n=m; n<L; n++) {
            ans = numRec(n,m);
            if(abs(ans-LIM) < abs(min-LIM) ) {
                min=ans;
                mm=m;
                nn=n;

            }
            if(ans > LIM)
                break;
        }
    }
    cout<<min<<" at "<<mm<<"* "<<nn<<"= "<<nn*mm<<endl;

}

//problem 96 -----------------------------------------
constexpr int size = 9;
constexpr int bsize = 3;
//sudoku
bool checkBlock(int S[size][size], const int x, const int y) {
    array<int,size> f= {0};
    for(int i=bsize*x ; i < (bsize)*x+bsize ; i++)
        for(int j=bsize*y ; j < (bsize)*y+bsize ; j++) {
            int d = S[i][j];
            if(d>0) {
                f[d-1]++;
                if(f[d-1] > 1)
                    return false;

            }
        }
    return true;
}

bool checkCol(int S[size][size] ,  const int col) {
    array<int,size> f= {0};
    loop0n(i,size) {
        if(S[i][col] > 0) {
            int d = S[i][col];
            f[d-1]++;
            if(f[d-1] > 1)
                return false;
        }
    }
    return true;
}

bool checkRow(int S[size][size],  const int row) {
    array<int,size> f= {0};
    loop0n(i,size) {
        if(S[row][i] > 0) {
            int d = S[row][i];
            f[d-1]++;
            if(f[d-1] > 1)
                return false;
        }
    }
    return true;
}

void printGrid(int S[size][size]) {
    loop0n(i,size) {
        cout<<"---";
    }
    cout<<endl;
    loop0n(i,size) {
        loop0n(j,size) {
            if(S[i][j])
                cout<<S[i][j]<<" ";
            else
                cout<<"  ";
            if(j%bsize==2)
                cout<<" ";
        }
        cout<<endl;
        if(i%bsize==2)
            cout<<endl;

    }
}



bool solveSudoku(int S[size][size], int L[size][size], vector<pii> guessable ) {
    int i=0;
    while(i<guessable.size()) {
        pii p = guessable[i];
        if(i==0 && L[p.first][p.second]>9)
            return false;
        //  cout<<i<<" "<<p.first<<" "<<p.second << "-> "<<L[p.first][p.second]<<endl;
        S[p.first][p.second]=L[p.first][p.second];
        if(L[p.first][p.second]>9) {
            L[p.first][p.second]=1;
            S[p.first][p.second]=0;
            i--;
            continue;
        }
        if(!(checkRow(S,p.first) && checkCol(S,p.second) &&
                checkBlock(S,p.first/bsize, p.second/bsize))) {
            //choice not good. backtrack
            S[p.first][p.second]=0;
            L[p.first][p.second]++;
        } else {
            //good choice
            i++;
            L[p.first][p.second]++;
        }
        // printGrid(S);
    }

    return true;
}
void solve96() {
    int S[size][size];
    int L[size][size];
    vector<pii> Q;
    ll ans=0;
    for(int i=0; i<50; i++) {
        string s;
        cin>>s;
        cin>>s;//first row useless
        for(int r=0; r<size; r++) {
            //parse row
            cin>>s;
            for(int c=0; c<size; c++) {
                int d = s[c]-'0';
                S[r][c] = d;
                d ? L[r][c]=-1 : L[r][c] = 1;
                if(!d)
                    Q.push_back(mp(r,c));
            }
        }
        //  printGrid(S);
        bool solved = solveSudoku(S,L,Q);
        if(solved) {
            //printGrid(S);

            ans+=S[0][0]*100 + 10*S[0][1] + S[0][2];
        }
        else
            cout<<"NO SOLUTION!"<<endl;
        Q.clear();

    }
    cout<<ans<<endl;
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
        if(it > 1 && ((it-1)%2)!=0) {
            ans++;
        }
    }
    cout<<"sol: "<<ans<<endl;
}

template<class T>
bool isPerfectSquare(const T d) {
    long double intpart, fractpart;
    fractpart = modf(sqrtl(d), &intpart);
    return fractpart <= 0.000001;
}

void solve66() {
    typedef ll T;
    InfInt max=-1;
    for(T d=62; d<=1000; d++) {
        if(!isPerfectSquare<T>(d)) {
            bool go=true;
            for(T x=1; go ; x++) {
                long double y2 = ((long double)x)/sqrtl((long double)d);
                long double intp,floatp;
                floatp=modf(y2,&intp);
                long double p = 0.0001;//1.0/(long double)pow10(magnitude<T>(x));
                // cout<<setprecision(10)<<d<<" "<<x<<" "<<y2<<" "<<p<<endl;;
                long double diff = fabs(1.0-floatp);
                if(intp>0 && (floatp <=p || diff <= p )) {
                    long double candintp;
                    if(diff <=p) {
                        intp=intp+1;
                    }
                    InfInt xi = x;
                    InfInt di=d;
                    InfInt intpi =(ll)intp;
                    InfInt res = xi*xi -di*intpi*intpi;
                    //printf("CANDIDATE-> %lld^2 - %lld*%lld^2 = 1\n",x,d,(T)intp);
                    //cout<<res<<endl;

                    InfInt one =1;
                    if( one== res ) {
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


template<class T>
void print(const vector<T>& V) {
    for(const auto& a : V) {
        cout<<a<< " ";
    }
    cout<<endl<<endl;
}



//problem 93---------------------------------
typedef vector<double> vi;
vi two[10][10]= {{}};
vi three[10][10][10]= {{}};
vi four[10][10][10][10]= {{}};
int s=1;
void filltwo() {
    for(int i=s; i<=9; i++) {
        for(int j=s; j<=9; j++) {
            if(i!=j) {
                int l=i;
                int m=j;
                if(l>m) swap(l,m);
                two[l][m].push_back(i+j);
                two[l][m].push_back(i-j);
                two[l][m].push_back(j-i);
                two[l][m].push_back(i*j);
                two[l][m].push_back(j*i);
                if(j!=0)
                    two[l][m].push_back((double)i/(double)j);
                if(i!=0)
                    two[l][m].push_back((double)j/(double)i);
            }
        }
    }
    cout<<endl;
}


void fillthree() {
    for(int i=s; i<10; i++) {
        for(int j=s; j<10; j++) {
            if(i!=j)
                for(int k=s; k<10; k++) {
                    if(i!=k && j!=k) {
                        array<int,3> coord= {i,j,k};
                        sort(coord.begin(),coord.end());
                        int jj=j;
                        int kk=k;
                        if(jj>kk)
                            swap(jj,kk);
                        vi ns = two[jj][kk];
                        for(auto n: ns) {
                            double op = (double)i;
                            three[coord[0]][coord[1]][coord[2]].push_back(op+n);
                            three[coord[0]][coord[1]][coord[2]].push_back(op-n);
                            three[coord[0]][coord[1]][coord[2]].push_back(n-op);
                            three[coord[0]][coord[1]][coord[2]].push_back(op*n);
                            three[coord[0]][coord[1]][coord[2]].push_back(n*op);
                            if(n!=0)
                                three[coord[0]][coord[1]][coord[2]].push_back(op/n);
                            if(op!=0)
                                three[coord[0]][coord[1]][coord[2]].push_back(n/op);


                        }
                    }
                }
        }
    }
}

bool isGood(const double n) {
    double intp, fracp;
    if(n>=1) {
        fracp=modf(n,&intp);
        if(fracp<=0.0001)
            return true;
    }
    return false;
}


void fillfour() {
    for(int i=s; i<10; i++) {
        if(i==4)
            cout<<endl;
        for(int j=s; j<10; j++) {
            if(i!=j)
                for(int k=s; k<10; k++) {
                    if(j!=k && k!=i)
                        for(int l=s; l<10; l++) {
                            if(l!=k && l!=j && l!=i) {
                                array<int,3> cc= {j,k,l};
                                sort(cc.begin(),cc.end());
                                auto ns= three[cc[0]][cc[1]][cc[2]];
                                array<int,4> coord= {i,j,k,l};
                                sort(coord.begin(),coord.end());
                                for(auto n: ns) {
                                    //metti anche l DIVISIONE AL CONTRATIO. tutte le operazioni non commutative vanno doppi
                                    ////metti anche l DIVISIONE AL CONTRATIO. tutte le operazioni non commutative vanno doppiee
                                    double op=(double)i;
                                    if(isGood(op+n))
                                        four[coord[0]][coord[1]][coord[2]][coord[3]].push_back(op+n);
                                    if(isGood(op-n))
                                        four[coord[0]][coord[1]][coord[2]][coord[3]].push_back(op-n);
                                    if(isGood(n-op))
                                        four[coord[0]][coord[1]][coord[2]][coord[3]].push_back(n-op);

                                    if(isGood(n*op))
                                        four[coord[0]][coord[1]][coord[2]][coord[3]].push_back(n*op);

                                    if(op!=0)
                                        if(isGood((double)n/(double)op))
                                            four[coord[0]][coord[1]][coord[2]][coord[3]].push_back(n/op);


                                    if(isGood(op*n))
                                        four[coord[0]][coord[1]][coord[2]][coord[3]].push_back(op*n);

                                    if(n!=0)
                                        if(isGood((double)op/(double)n))
                                            four[coord[0]][coord[1]][coord[2]][coord[3]].push_back(op/n);

                                }
                            }
                        }
                }
        }
    }

}
void solve93() {

    filltwo();
    fillthree();
    fillfour();
    int max=0;
    int c=0;
    for(int i=0; i<10; i++) {
        for(int j=i+1; j<10; j++) {
            for(int k=j+1; k<10; k++) {
                for(int l=k+1; l<10; l++) {
                    auto ns=four[i][j][k][l];
                    vector<int> nss;
                    for(int m=0; m<ns.size(); m++) {
                        if(isGood(ns[m]))
                            nss.push_back(ns[m]);
                    }
                    set<int> s(nss.begin(),nss.end());
                    nss.assign(s.begin(),s.end());
                    if(ns.size()>0) {
                        int start=1;
                        int c=0;
                        for(int m=0; m<nss.size(); m++,c++,start++) {
                            if( nss[m]!=start)
                                break;
                        }
                        if(c>max) {
                            max=c;
                            printf("\n%d %d %d %d: %d",i,j,k,l,c);
                        }
                    }
                }
            }
        }
    }
}

//end of problem 93


//problem94
inline pair<long double,long double> solveEq2(const long double a, const long double b, const long double c) {
    pair<long double,long double> res = {-1,-1};
    long double delta=b*b-4*a*c;
    if(delta>0.0) {
        res.first=(-b+sqrtl(delta))/(2*a);
        res.second=(-b-sqrtl(delta))/(2*a);
    }
    return res;
}

bool isIntegral(const long double l) {
    long double intp,fracp;
    if(modfl(l,&intp)<= 0.000000000001)
        return true;
    return false;
}


//this works but consider using solution of the Pell's equation for getting speedup
//
void solve94_c() {
    ll ans=0;
    long double a=2;

    #pragma omp parallel for reduction(+:ans)
    for(ll c =2; c<333333333; c++) {
        long double a=(long double)c;
        long double a23=3.0*a*a;
        long double a12=0.5*a;

        long double res=(3.0*(a*a) -2.0*a -1.0)/4.0;
        if(  isIntegral(sqrt(res)) ) {
            // ll aa=a;
            // printf("%ld %ld %ld\n", aa , aa , aa+1);
            ans+=3*a+1;
        }
        long double res2=(3.0*(a*a) +2.0*a -1.0)/4.0;
        if(  isIntegral(sqrt(res2)) ) {
            //  ll aa=a;
            // printf("%ld %ld %ld\n", aa , aa , aa+1);

            ans+=3*a-1;
        }
        a++;
    }
    cout<<ans<<endl;
}

//end of problem 94

//problem 95
constexpr const int LIM = 15000000;
array<ll,LIM +1> SD; //SD[i] contains the sum of proper divisor of i

void initSD() {
    #pragma omp parallel for shared(SD)
    for(int i=0; i<=LIM ; i++) {
        SD[i]=1;
        //cout<<i<<" "<<SD[i]<<endl;
    }
    #pragma omp parallel for
    for(int i=2; i<=LIM/2 ; i++) {
        int k=2;
        int p=k*i;
#pragma parallel for schedule(guided) private(k,p)
        for(; p<=LIM; k++, p=k*i ) {
            #pragma omp atomic
            SD[p]+=i;
        }

    }
}
void solve95() {
    initSD();
    int L, M;
    L=INT_MIN;
    M=INT_MAX;
    #pragma omp parallel for shared(L,M)
    for(int i=4 ; i<= LIM ; i++) {
        unordered_map<int,bool> map;
        int l=1;
        int m=i;
        map[i]=true;
        int c=SD[i];
        bool go= c!=1 ;
        while(!map[c] && c > 1&& c<=LIM) {
            map[c]=true;
            ++l;
            c=SD[c];
            if(c<m)
                m=c;
            go=(c>1) && (c<=LIM);
        }
        #pragma omp critical
        {
            if(go && c==i && l > L) {
                L=l;
                M=m;
            }
        }
    }
    cout<<M<<endl;
}

//end of problem 95

void solve86NEEDTOBESOLVED() {
    constexpr const int LIM=101;
    double EPS2=0.00000000001;
    int ans=0;
    int l=0;
    vector<int> Q (LIM,0);
    for(int i= 1 ; i < LIM ; i++) {
        for(int j= i ; j < LIM ; j++) {
            for(int k= j ; k< LIM ; k++) {
                int m= max(max(i,j),k);
                double intp;
                double a,b,c;

                a = modf( sqrt(i*i+(j+k)*(j+k) ) , &intp );
                b = modf( sqrt(j*j+(i+k)*(i+k) ) ,&intp);
                c = modf( sqrt(k*k+(i+j)*(i+j) ) ,&intp);
                if((a<EPS) || (b<EPS) || (c<EPS)) {
                    Q[m]++;
                    ans++;
                    printf("%d %d %d -> %d\n", i,j,k,Q[m] );


                }



            }
        }
    }
    cout<<ans<<endl;
}


void solve91() {
#define PI 3.14159265
    typedef array<int,2> vec2i;
    auto dot = [](const vec2i& a, const vec2i& b) {
        return a[0]*b[0]+a[1]*b[1];
    };

    auto magn = [] (const vec2i& a)-> double {
        return sqrt(a[0]*a[0] + a[1]*a[1]);
    };

    auto angle = [&](const vec2i& a, const vec2i& b) {
        auto magna = magn(a);
        auto magnb = magn(b);
        auto dotab = dot(a,b);
        return acos(( dotab )/magna*magnb);
    };

    vec2i a = {1,0};
    vec2i b = {0,2};

    auto minus = [](const vec2i a, const vec2i& b) {
        vec2i ret = {a[0]-b[0], a[1]-b[1]};
        return ret;
    };
    auto negate = [](const  vec2i a) {
        vec2i b = {-a[0],-a[1]};
        return b;
    };

    auto equal = [](double a, double b, double _EPS) {
        return fabs(a - b) < _EPS;
    };
    auto isGood = [&] (const vec2i a, const vec2i b, double _EPS) {
        if(a[0]==b[0] && a[1]==b[1])
            return false;
        if(a[0]==0 && a[1]==0)
            return false;
        if(b[0]==0 && b[1]==0)
            return false;
        auto ang1 = angle(a,b);
        auto ang2 = angle(negate(b),minus(a,b));
        auto ang3 = angle(negate(a),minus(b,a));
        const double PI2 =M_PI/2.0;
        return       (equal( ang1,PI2 , _EPS ) || equal(ang1,-PI2,_EPS)) ||
                     (equal( ang2,PI2 , _EPS ) || equal(ang2,-PI2,_EPS)) ||
                     (equal( ang3,PI2 , _EPS ) || equal(ang3,-PI2,_EPS)) ;


    };
    int ans=0;
    int LIM=50;
    vec2i zero= {0,0};
    #pragma omp parallel for collapse(2) reduction(+:ans)
    for(int i=0; i<=LIM; i++) {
        for(int j=0; j<=LIM; j++) {
            vec2i one = {j,i};
            if(i!=0 || j!=0)
                for(int k=i; k<=LIM; k++) {
                    for(int l=0; l<=LIM; l++) {
                        vec2i two = {l,k};
                        if(l<=j && k<=i)
                            continue;
                        if(isGood(one,two, 0.000001)) {
                            //printf("(0,0) (%d,%d), (%d,%d)\n",j,i,l,k);
                            ans++;

                        }
                    }
                }
        }

    }
    cout<<ans<<endl;
}


void solve87() {
    vector<ll> primes;
    getPrimesSieve(primes,7100);
    constexpr const int LIM = 50000000;
    vector<int> squares;
    vector<int> cubes ;
    vector<int> fourths;
    loop0n(i,primes.size()) {
        if(primes[i]*primes[i] < LIM)
            squares.push_back(primes[i]*primes[i]);
        else
            break;
    }
    loop0n(i,primes.size()) {
        if(primes[i]*primes[i]*primes[i] < LIM)
            cubes.push_back(primes[i]*primes[i]*primes[i]);
        else
            break;
    }
    loop0n(i,primes.size()) {
        if(primes[i]*primes[i]*primes[i]*primes[i] < LIM)
            fourths.push_back(primes[i]*primes[i]*primes[i]*primes[i] );
        else
            break;
    }


    unordered_map<int,bool> map;
    int ans=0;
    loop0n(i,squares.size()) {
        loop0n(j,cubes.size()) {
            loop0n(k,fourths.size()) {
                int n = squares[i]+cubes[j]+fourths[k];
                if(n < LIM && (map.find(n)==map.end())) {
                    map[n]=true;
                    ++ans;

                }
            }
        }
    }
    cout<<ans<<endl;
}

// PROBLEM 88 -----------------------------------
void combine(vector<vector<int>>& w, const int n) {
    for(auto& s : w) {
        s.push_back(n);
    }
}

vector<vector<int>> asMultiplication(const int n, vector<ll>&primes) {
    vector<vector<int>> W;
    int nn=n;
    vector<int> r = {{nn}};
    W.push_back(r);
    int nnn=1;
    loopse(i,2, n/2+1) {
        if(nn==primes[i]) {
            break; ;
        }
        if(nn%i==0) {
            vector<int> A = {nn/i,i};
            W.push_back(A);
            vector<vector<int>> wnn = asMultiplication(nn/i,primes);
            for(auto& ww : wnn) {
                sort(ww.begin(),ww.end());
            }
            sort(wnn.begin(),wnn.end());
            auto it =unique(wnn.begin(), wnn.end());
            wnn.resize(distance(wnn.begin(),it));

            combine(wnn, i);
            W.insert(W.end(), wnn.begin(), wnn.end());
        }
        if(nn<primes[i])
            break;
    }

    for(auto& ww : W) {
        sort(ww.begin(),ww.end());
    }
    sort(W.begin(),W.end());
    auto it =unique(W.begin(), W.end());
    W.resize(distance(W.begin(),it));
    return W;

}

void solve88() {
    set<int> S;
    const int LIM = 12000;
    vector<ll> primes;
    getPrimesSieve(primes,LIM);
    vector<vector<vector<int>>> WM(2*LIM);

    #pragma omp parallel for shared(WM)
    for(int i=1; i<= 2*LIM; i++) {
        WM[i-1] = asMultiplication(i,primes);

    }

    #pragma omp parallel for  shared(S)
    for(int k=2 ; k<=LIM ; k++) {
        bool go =true;
        int i=k-1;
        for(; go && i< WM.size() ; i++) {
            for(int n=0 ; go&& n < WM[i].size() ; n++) {
                vector<int> w = WM[i][n];
                if(w.size()<=k) {
                    int sum =0;
                    for(const auto c : w)
                        sum+=c;

                    int d = k-w.size();
                    if(d+sum == i+1)
                    {
                        go=false;
                        //cout<<k<<" "<<i+1<<endl;
                        #pragma omp critical
                        S.insert(i+1);
                    }


                }
            }

        }
        if(go) {
            cout<<"WRONGGGGGGGG"<< k<<endl;
            exit(-1);
        }
    }
    ll ans=0;
    for(auto & w :S) {
        ans+=w;
        // cout<<w<<endl;
    }
    cout<<ans<<endl;
}
//END OF PROBLEM88 -----------------------------------------


//problem 90

void combination( const unsigned short n, const unsigned short k, vector<vector<int>> &C) {
    int LIM = pow( 2 , n )-1; //bits max number using n bits
    int LOW = pow(2,k) -1;
    for(int i=LOW ; i < LIM ; i++) {
        //counts bit set
        int bs =0;
        for(int b=0; bs<=k && b<n ; b++) {
            if( BIT(i,b) )
                bs++;
        }

        if(bs==k) { //good permutation
            vector<int> p(k);
            for(int bit=0; bit<n ; bit++)
                if(BIT(i,bit))
                    p[--bs]=(bit);

            C.push_back(p);

        }

    }
}

bool isGood(const vector<int>& C0, const vector<int>& C1) {

    bool sn1 = C1.end() != find(ALL(C1),6);
    sn1 = sn1 || (C1.end() != find(ALL(C1),9));

    bool sn0 = C0.end() != find(ALL(C0),6);
    sn0 = sn0 || (C0.end() != find(ALL(C0),9));
    for(int i=1; i<=9 ; i++) {
        int ii=i*i;
        int a=ii%10;
        int b=(ii/10)%10;


        bool a0,b0, a1,b1;
        a0 = C0.end() != find(C0.begin(), C0.end(), a);
        b0 = C0.end() != find(C0.begin(), C0.end(), b);
        a0 = a0 || ( (a==6 || a==9) && sn0);
        b0 = b0 || ( (b==6 || b==9) && sn0);

        a1 = C1.end() != find(C1.begin(), C1.end(), a);
        b1 = C1.end() != find(C1.begin(), C1.end(), b);

        a1 = a1 || ( (a==6 || a==9) && sn1);
        b1 = b1 || ( (b==6 || b==9) && sn1);

        if( ! ((a0 && b1) || (b0 && a1)  ))
            return false;

    }
    return true;
}

void solve90() {
    vector<vector<int>> C;
    combination(10,6,C);
    int ans=0;
    for(int i=0; i< C.size() ; i++) {
        for(int j=i ; j< C.size(); j++) {
            if(isGood(C[i], C[j]))
                ans++;
        }
    }
    cout<<ans<<endl;
}


//problem 102-----
void solve102() {
    FILE* file;


    file=fopen("p102_triangles.txt","r");
    if(!file)
    {
        cout<<"something bad happened opening the file\n";
        exit(-1);
    }


    auto linetwopoints=[](const pdd& p0, const pdd& p1, const int x, const int y) {
        return (y-p0.second)/(p1.second-p0.second )-(x-p0.first)/(p1.first-p0.first) ;
    };

    array<pii,3> Pi;
    int ans=0;
    while(fscanf(file,"%d,%d,%d,%d,%d,%d\n",&Pi[0].first,&Pi[0].second,&Pi[1].first,&Pi[1].second,&Pi[2].first,&Pi[2].second))
    {

        array<pdd,3> P;
        P[0]=Pi[0];
        P[1]=Pi[1];
        P[2]=Pi[2];
        sort(ALL(P),pair_cmp);

        if(P[2].second < P[1].second)
            swap(P[2],P[1]);

        if(linetwopoints(P[0],P[1],0,0) <=0)  {
            if(linetwopoints(P[0],P[2],0,0) >=0) {
                if(linetwopoints(P[1],P[2],0,0) >=0) {
                    ans++;
                }
            }
        }
    }
    fclose(file);
    cout<<ans<<endl;
}

//problem 101------------

/*
 * In order to find the (UNIQUE!) minimal degree polynomial which interpolate n numbers
 * we here use the lagrangian polynomial.
 * */

double LagrangePolynomial(const int i, const vector<pldd>& points, const pldd& p) {
    long double res=1.0;
    loop0n(m,points.size()) {
        if(m!=i) {
            res*=(p.first-points[m].first)/(points[i].first-points[m].first);
        }
    }
    return res;
}


long double interpolateLagrange(const vector<pldd>& points,const  pldd& p) {
    long double res=0;
    #pragma omp parallel for reduction(+:res)
    loop0n(i,points.size()) {
        res+=points[i].second * LagrangePolynomial(i,points, p);
    }
    return res;
}


void solve101() {
    vector<pldd> points ;
    int maxd=11;
    auto evalcube = [&](const long double n) -> long double {
        return n*n*n;
    };
    auto eval = [&](const long double n) -> long double {
        return 1 -
        pow(n,1) +
        pow(n,2) -
        pow(n,3) +
        pow(n,4) -
        pow(n,5) +
        pow(n,6) -
        pow(n,7) +
        pow(n,8) -
        pow(n,9) +
        pow(n,10);

    };

    loopse(i,0,maxd)    {
        const pldd p = mp(i+1,eval(i+1));
        points.push_back(p);

    }

    long double ans=0;
    loopse(i,1,maxd)    {
        vector<pldd> _points(points.begin(), points.begin()+i);
        ans+=interpolateLagrange(_points,mp(i+1,-1));

    }
    cout<<(long long int)ans<<endl;
}

bool checkDuplicateSum(vector<vector<int>>& S,const int v) {

    vector<int> n;
    n.push_back(v);
    loop0n(i,S.size()) {
        loop0n(j,S[i].size()) {
            n.push_back(S[i][j]+v);
        }
    }

    bool ok = true;
    loop0n(k,n.size()) {
        if(ok)
            loop0n(i,S.size()) {
            if(ok)
                loop0n(j,S[i].size()) {
                if(n[k]==S[i][j]) {
                    ok=false;
                    break;
                }
            }
        }
    }
    if(ok)
        S.push_back(n);

    return ok;


}


constexpr int D=7;
bool noDuplicateSum(const array<int,D>&M) {
    array<int,D> L;
    array<int,D> R;
    L[0]=M[0];
    for(int i=1 ; i< M.size() ; i++) {
        L[i]=M[i]+L[i-1];
    }
    R[M.size()-1]=M.back();
    for(int i=M.size()-2 ; i>=0 ; i--) {
        R[i]=M[i]+R[i+1];
    }

    bool ok = true;
    for(int i=M.size()-1 ; ok && i>=0 ; i--) {
        for(int j=1+M.size()-1-i ; ok && j<M.size() ; j++) {
            if(R[i] > L[j])
                ok=false;
        }

    }
    return ok;

}

void solve103() {

    int minsum=INT_MAX;
    constexpr int LIM=50;
    array<int,D> M= {0,0,0,0,0,0,0}; //,0,0,0};
    array<int,D> minA;
    vector<vector<int>> S;
    int i=0;
    int sum=0;
    do {

        M[i]++;
        sum =0;
        loop0n(k,i+1) {
            sum+=M[k];
        }
        bool ok = true;
        bool odd = sum % 2 != 0;
        bool inc = i==0;
        inc = inc || (i > 0 && M[i] > M[i-1]);
        if(i>=2)
            for(int j=i ; inc && ok && j>1 ; j--)
                if(M[0]+M[1] <= M[j])
                    ok=false;



        if(ok && inc && M[i]<=LIM )
            if(checkDuplicateSum(S,M[i]))
                i++;



        if(i>=D ) {
            if(  noDuplicateSum(M) && sum<minsum) {
                minsum=sum;
                loop0n(k,D) {
                    minA[k]=M[k];
                }

            }
            ok=false;
        }




        if((!odd && i==D) || !ok || M[i]>=LIM )
        {
            do {
                sum-=M[i];
                M[i]=0;
                S.pop_back();
                i--;
            } while(M[i]>=LIM);
        }



    } while(M[0]<LIM);
    cout<<minsum<<endl;
    loop0n(k,D) {
        cout<<minA[k];
    }
    cout<<endl;


}

//end of  problem 101  ------------
int main() {
    ios_base::sync_with_stdio(false);
    solve43();
    return 0;
}











