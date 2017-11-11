#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<list>
#include <iomanip>
using namespace std;

enum suit  { SPADES = 0, HEARTS, DIAMONDS,CLUBS};

class card {
public:
    card() {};
    card(suit _s, int _v) : s(_s), value(_v) {}
    suit s;
    int value;

    void print() {
        cout<<s<<" "<< value;
    }


};

suit parseSuit(const char c) {
    switch (c) {
    case  'S' :
        return SPADES;

    case  'H' :
        return HEARTS;

    case  'D' :
        return DIAMONDS;

    case  'C':
        return CLUBS;

    default:
        cerr<<"invalid input \n EXITING"<<endl;
        exit(-1);



    }
}

int parseValue(const char v) {
    if (v >= '2' && v <= '9')
        return (v -'2' + 2);//returns from 2 to 9

    switch (v) {
    case 'A' :
        return 1; //ace
    case 'T' :
        return 10; //ten
    case 'J' :
        return 11; //jack
    case 'Q' :
        return 12;// queen
    case 'K' :
        return 13; //king

    }

}

int main() {
    list<card> deckD;
    list<card> deckND;
    list<card> table;

    char s;
    cin>>s;
    char v;
    int read = 0;
    bool giveD = false;
    list<card>* p = &deckND;
    while(s != '#') {

        for(int i=0; i<4; i++) {
            for(int j=0; j<13; j++) {

                cin>>v;
                card c (parseSuit(s),parseValue(v));
                (*p).push_back(c);
                //(*p).back().print();

                giveD=!giveD;
                if(giveD) p=&deckD;
                else 	 p=&deckND;

                cin>>s;
            }
        }

//play game now
        bool D=false;
        p = &deckND;
        int debit = -1;

        while(deckD.size() > 0 && deckND.size() > 0) {
            /*cout<<endl<<"D: " ;
            for(auto it = deckD.begin() ; it != deckD.end() ; it++)
            	cout<<(*it).value<<" ";

            cout<<endl<<"N: " ;
            for(auto it = deckND.begin() ; it != deckND.end() ; it++)
            	cout<<(*it).value<<" ";

            cout<<endl<<"T: " ;
            for(auto it = table.begin() ; it != table.end() ; it++)
            	cout<<(*it).value<<" ";

            cout<<endl;*/



            card c = (*p).back();
            (*p).pop_back();
            table.push_back(c);

            //cout<<p<<" turno di "<<D<< " estratta ";
            //c.print(); cout<< " - D"<<deckD.size()<<" - ND "<<deckND.size()<<" - T "<<table.size()<<endl;

            if(c.value == 1 || (c.value > 10 && c.value < 14 )) {
                //change player and add debit to the other player
                D=!D;
                if(D) p=&deckD;
                else  p=&deckND;


                debit = c.value > 1 ? c.value - 11 : 4;

            }
            else if(debit <= 0) {
                D=!D;
                if(D) p=&deckD;
                else  p=&deckND;


                if(debit==0) {
			std::copy( table.begin(), table.end(), std::front_inserter((*p)) );
  //                  for(auto it = table.begin(); it != table.end() ; it++)
//                        (*p).push_front(*it);

                    table.clear();
                    debit=-1;


                }

            } else {
                debit--;
            }


        }

        if(deckD.size()> deckND.size())
            cout<<"1 "<<right<< std::setw(3)<<deckD.size()<<endl;
        else
            cout<<"2 "<<right<< std::setw(3)<<deckND.size()<<endl;

//cout<<deckD.size()+deckND.size()+table.size()<<endl;


    }


    return 0;
}
