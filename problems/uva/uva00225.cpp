
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

bool isLegalState(const int Q, const int K) {
    return Q!=K;
}

void to2D(int Q, int rowsize, int&x,int&y) {
    x=Q/rowsize;
    y=Q-x*rowsize;
}

bool isLegalMove(const int Q,const int K,const int QN) {
    int QX,QY;
    to2D(Q,8,QX,QY);
    int KX,KY;
    to2D(K,8,KX,KY);
    int QNX,QNY;
    to2D(QN,8,QNX,QNY);
//check if queen new pos is on same row or column of old Q'pos
    if(QNX!=QX && QNY!=QY)
        return false;

//+1 and -1 is needed  becuase the queen has to move at least of one position!
//horizonthal move
    if(QNX==QX) {
        if(QY>QNY)
		for(int i=QY-1; i >=0 ; i--) {
		    if(i == KY && KX==QNX)
		        return false;
		    if(i == QNY)
		        return true;
		}
	else
		for(int i=QY+1; i < 8 ; i++) {
		    if(i == KY && KX==QNX)
		        return false;
		    if(i == QNY)
		        return true;
		}


    }
    else { //vertical move
	if(QX > QNX)        
		for(int i=QX-1; i >=0 ; i--) {
		    if(i == KX && KY==QNY)
		        return false;
		    if(i == QNX)
		        return true;
		}
	else
		for(int i=QX+1; i < 8 ; i++) {
		    if(i == KX && KY==QNY)
		        return false;
		    if(i == QNX)
		        return true;

		}

    }

return false;


}

bool SamePosKing(int K, int QN) {
    int KX,KY;
    to2D(K,8,KX,KY);
    int QNX,QNY;
    to2D(QN,8,QNX,QNY);
    //move king down
    if((KX+1 )<=7 && (KX+1)==QNX && KY==QNY)
        return false;
    if((KX-1) >=0 && (KX-1)==QNX && KY==QNY)
        return false;

    if((KY+1) <=7 && (KY+1)==QNY && KX==QNX)
        return false;
    if((KY-1) >=0 && (KY-1)==QNY && KX==QNX)
        return false;

return true;


}


bool isLocked(const int K, const int QN){
if((K==56 && QN ==49) || (K==0 && QN ==9) || (K==7 && QN ==14) || (K==63 && QN ==54))
	return true;

return false;

}

string solve(const int Q, const int K, const int QN) {
//check for legal state
    if(!isLegalState(Q,K))
        return "Illegal state";

    if(!isLegalMove(Q,K,QN))
        return "Illegal move";

    if(!SamePosKing(K,QN))
        return "Move not allowed";

    if(!isLocked(K,QN))
	return "Continue";

return "Stop";

	
//move the queen nd check if the king can move or nor in this state
return "OK";

}


int main() {

    int Q,K,QN;
    while(scanf("%d %d %d \n", &K,&Q,&QN)==3) {

        cout<<solve(Q,K,QN)<<endl;
    }

    return 0;

}
