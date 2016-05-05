#include<common.h>

using namespace std;
typedef vector<int> vb;


inline int getkthbit(const int k,const int N, int numdigits=4){
    int i = 1<<(4*numdigits-1)-k;
    return (N & i) ? 1 : 0;
}

void printNBitRepesentation(const int k,const int N){
    LOOPDWN(i,k-1){
        cout<<getkthbit(i,N)<<" ";
    }
    cout<<endl;
}


void printMatrix(const vector<vb>& matrix){
    LOOPUP(i,matrix.size()){
        LOOPUP(j,matrix[i].size()){
            cout<<matrix[i][j]<< " ";
        }
        cout<<endl;
    }
}
void readInput(const int M, const int N,vector<vb>& matrix){
    LOOPUP(i,M){
        string l; cin>>l;

        //cout<<row<<endl;
        const int SLICE = 4;
        int k=0;
        int count=0;
        while(k*SLICE < l.size()){
        int row;
            string ll = l.substr(0+k*SLICE,SLICE);
            //cout<<ll<< " ";
            row=stoi(ll,nullptr,16);
            //    cout<<"size ="<<ll.size()<<"\n";

            for(int j=0; j < ll.size()*4 ; j++){
                matrix[i][count++] = getkthbit(j,row,ll.size());
                //printf("%d bit of %d is %d - \n",j,row,getkthbit(j,row,ll.size()));
            }
            k++;
        }



    }
    //printMatrix(matrix);
}

//returns true if the portion of matrix starting at x,y and of size S
//is a board
bool isaboard(const int x, const int y, const int S,const vector<vb> & m){
    bool go = true;
    for(int i=x ; i < (x+S) && go; i++){
        for(int j=y ; j < (y+S) && go; j++){
            if(m[i][j] > 1)
               go=false;
             else if(i < (x+S-1) && ( (m[i][j] == m[i+1][j])  || m[i+1][j] > 1))
                go=false;
            else if(j < (y+S-1) && ( (m[i][j] == m[i][j+1])  || m[i][j+1] > 1))
                go=false;
        }
    }
    //printf("(%d,%d)-(%d,%d)",x,y,x+S,y+S);
    return go;
}

//returns true if the portion of matrix starting at x,y and of size S
//is a board
void invalidateBoard(const int x, const int y, const int S, vector<vb> & m, const int val){
    for(int i=x ; i <(x+S) ; i++)
        for(int j=y ; j < (y+S) ; j++)
            m[i][j]=val;
}


int main(){
    int T; cin>>T;

    LOOPUP(i,T){
        int M,N; cin>>M>>N;
        vector<vb> matrix(M,vector<int>(N));
        readInput(M,N,matrix);
        int size = min(M,N);
        int LM = M-1;
        int LN = N-1;
        int s = size+1;
        int dec = true;
        int f=2;
        int diff=0;
        stringstream ss;


        while(s >= 1){
            //printf("%d\n",s);
            dec = true;
            //check for board of size s*s
            //printf("size = %d\n",s);
            //printMatrix(matrix);
            for(int r=0 ; r <= (M-s) ; r++){
                for(int c=0 ; c <= (N-s); c++){
                    //cout<<"here"<<i<<" "<<r<<" "<<c<<endl;
                    if(isaboard(r,c,s,matrix)){
                        //printf("bOARD OF SIZE %d starts at %d,%d\n",s,r,c);
                        invalidateBoard(r,c,s,matrix,f++);
                        dec=false;

                    }else{
                        //printf("\t\tNO BOARD %d starts at %d,%d\n",s,r,c);
                    }

                }
                //printf("\n");
            }
            if(dec){
                if(f > 2){
                    ss<<s<<" "<<f-2<<endl;
                    //printf("%d %d\n",s,f-2);
                    diff++;
                    //printMatrix(matrix);
                }
                s--;
                f=2;
            }
            //if(dec) s--;

            }
            string out = ss.str();
            printf("Case #%d: %d\n",i+1,diff);
            cout<<out;

        }


    return 0;
}
