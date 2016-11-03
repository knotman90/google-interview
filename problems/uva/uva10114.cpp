#include<iostream>
#include<stdio.h>


using namespace std;


int main(){

     int months;
     double payment, amount;

    int nd;
    cin>>months>>payment>>amount>>nd;
    double carvalue=amount+payment;
    int lm =0;
    double ld=0.0;
    while(months > 0){
            int res=0;
            int m; double d;
            cin>>m>>d;
            carvalue-=carvalue*d;
            if(amount < carvalue)
                break;
            nd--;
            ld=d;
            lm=m;
             while(nd-- && amount>= carvalue){
             cin>>m>>d;
            if(m-lm >=2){
                int M = m-lm-1;
                while(M-- && amount >= carvalue){
                      amount-= payment;
                      carvalue-=carvalue*ld;
                      res++;
                }
              
            }
        
            if(amount < carvalue)
                break;

            res++;
            amount-=payment;
            carvalue -= carvalue*d;
            if(amount < carvalue)
                break;

            lm=m;
            ld=d;

        }
        
         while(amount >= carvalue){
                  amount-= payment;
                  carvalue-=carvalue*ld;
                   res++;
          }
              cout<<res<<" months\n";
        //consume input
        while(nd>0)
            cin>>m>>d;
       cin>>months>>payment>>amount>>nd;
       carvalue= amount+payment;
       lm=ld=0;
    }
        
    return 0;
}
