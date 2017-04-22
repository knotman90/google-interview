#include <bits/stdc++.h>
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


#define pb push_back
#define ALL(v) v.begin(), v.end()

//for map, pair
#define mp make_pair
#define fi first
#define se second
//char to int 
inline constexpr int ctoi(const char c)
{ return c - '0'; }
//int to char
inline constexpr char itoc(const int n)
{ return n + '0'; }

template<typename T> inline T clamp(const T& n, const T& lo, const T& hi)
{ return std::max(lo,std::min(n,hi)); }

template<class T> inline void sort(T &a)
{ std::sort(ALL(a)); }

template<class T1, class T2> inline void sort(T1 &a, T2 comp)
{ sort(ALL(a), comp); }

template<class T> inline int read(T& n)
{ return std::cin >> n ? 1 : -1; }
//reads multiple arguments
template<typename T, typename... types> inline int read(T &n, types &...args)
{ return read(n) == -1 ? -1 : read(args...) + 1; }

template<class T> inline void write(const T& n)
{ std::cout << n; }
//reads multiple arguments
template<typename T, typename... types> inline void write(const char sep, T &n, types &...args)
{ write(n); write(sep); write(sep,args...); }



template<typename T> inline constexpr bool odd(const T a)
{ return bool(a & 1); }

template<typename T> inline constexpr bool even(const T a)
{ return !odd(a); }

template<class T>
inline unsigned int mod (const T m, const T n)
{ return m >= 0 ? m % n : ( n - abs( m%n ) ) % n; }

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

//integer power (base^exp)
template<class T>
T ipow(T base, T exp) {
    T result = 1;
    while (exp) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}


//------ PROBLEM CODE --------------

using namespace std;

enum STATE  {E , R , B};

constexpr const int SIZE = 100;

STATE M[SIZE][SIZE];
STATE MR[SIZE][SIZE];

void printM(const int rows, const int cols){
    loop0n(i,rows){
            loop0n(j,cols){
                switch(M[i][j]){
                    case E:   cout<<".";  break;
                    case B: cout<<"B"; break;
                    case R: cout<<"R";  break;
                }
                cout<<" ";
            }
            cout<<endl;
    }
    
}

void rotate(const int rows){
    loop0n(i,rows){
        loop0n(j,rows){
            MR[j][rows-1-i]= M[i][j];
        }
    }
    loop0n(i,rows){
       loop0n(j,rows){
            M[i][j]=MR[i][j];
        }
    }
}

void gravity(const int rows){
    for(int i=rows-2 ; i >=0 ;i--){
        for(int j=0 ; j<rows; j++){
            if(M[i][j]==E)
                continue;
            int p=i;
            while(M[p+1][j]==E && p<rows-1){
                p++;
            }
            if(p!=i){
            M[p][j]=M[i][j];
            M[i][j]=E;
            
            }
        }

    }
}


bool winSide(int r, int c, int rows, int k){
    int count=0;
    for(int i=0;(r+i)<rows && count<k;i++){
        if(M[r][c] == M[r+i][c])
            count++;
        else
            break;
    }
    if(count>=k)
        return true;
   //down
    count=0;
    for(int i=0;(r-i)>=0 && count<k;i++){
        if(M[r][c] == M[r-i][c])
            count++;
        else
            break;
    }
    if(count>=k)
        return true;    
        
        //left
    count=0;
    for(int j=0;(c-j)>=0 && count<k;j++){
        if(M[r][c] == M[r][c-j])
            count++;
        else
            break;
    }
    if(count>=k)
        return true;    
    //right
    count=0;
    for(int j=0;(c+j)<rows && count<k;j++){
        if(M[r][c] == M[r][c+j])
            count++;
        else
            break;
    }
    if(count>=k)
        return true;
   
return false; 
}

bool winDiag(const int r, const int c, const int rows, const int k){
    int count=0;
    for(int i=0;(r+i)<rows && (c+i)<rows && count<k;i++){
        if(M[r][c] == M[r+i][c+i])
            count++;
        else
            break;
    }
    if(count>=k)
        return true;

    count=0;
    for(int i=0;(r-i)>=0 && (c+i)<rows && count<k;i++){
        if(M[r][c] == M[r-i][c+i])
            count++;
        else
            break;
    }
    if(count>=k)
        return true;
   
   
    count=0;
    for(int i=0;(r-i)>=0 && (c-i)>=0 && count<k;i++){
        if(M[r][c] == M[r-i][c-i])
            count++;
        else
            break;
    }
    if(count>=k)
        return true;
        
    
    count=0;
    for(int i=0;(r+i)<rows && (c-i)>=0 && count<k;i++){
        if(M[r][c] == M[r+i][c-i])
            count++;
        else
            break;
    }
    if(count>=k)
        return true;
        
   
   return false;

   
}

void checkWinner(const int rows, const int k){
        bool winR, winB;
        winR=winB=false;
        
        for(int i=0;i<rows;i++){
         for(int j=0;j<rows;j++){
           if(M[i][j]==E || (M[i][j]==R && winR) || (M[i][j]==B && winB))
            continue;
            
            if(winSide(i, j,rows,k) || winDiag(i,j,rows,k) ){
                if(M[i][j] == R)
                    winR=true;
                else
                    winB=true;
            }
         }
        }
        string s="Neither";
        
        if(winR && winB){
            s="Both";
        }
        if(!winR && winB){
            s="Blue";
        }
        
        if(winR && !winB){
            s="Red";
        }
        cout<<s<<endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    
    int T; read(T);
    int c=1;
    while(T--){
        cout<<"Case #"<<c++<<": ";

        int rows, cols,K; 
        read(rows,K);
        cols=rows;
        loop0n(i,rows){
            loop0n(j,cols){
                char c; read(c);
                STATE s;
                if(c=='.')
                    s=E;
                else{
                    s = c == 'B' ? B : R;
                }
                M[i][j]=s;
            }
            
        }
       // cout<<T<<" ---------------------------"<<endl;
       // printM(rows,cols);
       //// cout<<"++++++++++"<<endl;
        rotate(rows);
       // printM(rows,cols);
       // cout<<"++++++++++"<<endl;
//
        gravity(rows);
       // printM(rows,cols);
      //  cout<<"++++++++++"<<endl;
//
      //  cout<<T<<" ---------------------------"<<endl;
       checkWinner(rows, K);
    }
    
    return 0;
}


