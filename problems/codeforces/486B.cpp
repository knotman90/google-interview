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

using namespace std;
#define SIZE (100)

bool A[SIZE][SIZE];
bool RES[SIZE][SIZE];
bool C[SIZE][SIZE];
bool isok(const int r,const int cs, bool rORc) {

    loop0n(i,cs) {
        bool el;
        if(rORc)
            el=A[i][r];
        else
            el=A[r][i];
        if(!el)
            return false;
    }
    return true;
}

int main() {
    int rs,cs;
    cin>>rs>>cs;
    loop0n(i,rs) {
        loop0n(j,cs) {
            cin>>A[i][j];
        }
    }

    loop0n(i,rs) {
        if(isok(i,cs,false)){
        loop0n(j,cs) {
            if(isok(j,rs,true))
                RES[i][j] = true;
            else
                RES[i][j]= false;
            }

        }
    }

    loop0n(i,rs) {
        loop0n(j,cs) {
            bool v=false;
            loop0n(k,rs) {
                v = v || RES[i][k];

            }

            loop0n(k,cs) {
                v = v || RES[k][j];
            }
            
            C[i][j] =v;
        }
    }
    bool f=true;
    loop0n(i,rs){
        loop0n(j,cs){
            if(A[i][j] != C[i][j])
                f=false;
                
        }
    }
    if(!f){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        loop0n(i,rs){
            loop0n(j,cs){
                cout<<RES[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



