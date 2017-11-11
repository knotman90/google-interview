#include<iostream>
#include<vector>
#include<string>
using namespace std;




enum ACTION {MOVEONTO = 0, MOVEOVER,PILEONTO,PILEOVER};
typedef vector<int> vi;

int printStacks(vector<vi> stacks) {
    for(int i=0 ; i < stacks.size(); i++) {
        cout<<i<<":";
        for(const auto a: stacks[i])
            cout<<" "<<a;
        cout<<endl;
    }
}

//moves all elements from stack from top until the element a is found
//the to be moved elements are moved to position listed in the vector P
void moveUpTo(vector<vi>& S, vector<int>&C, const vector<int>& P, vector<int>&PRE, int s,int a) {

    int p= S[s].back();
    while(p != a && S[s].size() > 0 ) {

        S[s].pop_back();
        S[P[p]].push_back(p);
        C[p] = P[p];
        PRE[p] = s;

        p = S[s].back();

    }

}

int main() {
    int N;
    cin>>N;

    vector<vi> stacks(N);
    vector<int> contain(N);
    vector<int> previous(N);
    for(int i=0; i<N; i++) {
        stacks[i].push_back(i);
        contain[i] = i;
        previous[i] = i;
    }

    const vector<int> initial(contain);


    string command;
    cin>>command;
    while(command != "quit") {
        int a,b;
        ACTION action = PILEOVER;
        string command1;
        cin>>a>>command1>>b;

        //parsing action
        if(command =="move")
            if(command1=="onto")
                action = MOVEONTO;
            else
                action = MOVEOVER;
        else if(command1 == "onto")
            action = PILEONTO;

            vector<int> tmp;
        if(a!=b && contain[a] != contain[b]) {
            int p;
            switch(action) {
            case MOVEONTO:
                moveUpTo(stacks,contain,initial,previous,contain[a],a);
                moveUpTo(stacks,contain,initial ,previous, contain[b],b);
                //move a onto b now: pop a from stack containing a and pushback into b'sone
                stacks[contain[a]].pop_back();
                stacks[contain[b]].push_back(a);
                previous[a] = contain[a];
                contain[a] = contain[b];
                break;
            case MOVEOVER:
                moveUpTo(stacks,contain,initial,previous,contain[a],a);
                stacks[contain[a]].pop_back();
                stacks[contain[b]].push_back(a);
                previous[a] = contain[a];
                contain[a] = contain[b];

                break;

            case PILEONTO:
               moveUpTo(stacks,contain,initial,previous,contain[b],b);
                do {
                    p = stacks[contain[a]].back();
                    stacks[contain[a]].pop_back();
                  //  stacks[contain[b]].push_back(p);
                    previous[p] = contain[a];
                    contain[p] = contain[b];
                    tmp.push_back(p);
//cout<<"pileinto"<<a<<" "<<b<< "contained into "<<contain[a]<<endl;
                } while(p != a && stacks[contain[a]].size()>0);

                for(int i=tmp.size()-1 ; i>=0 ; i--)
                   stacks[contain[b]].push_back(tmp[i]);

                break;

            case PILEOVER:
                do {
                    p = stacks[contain[a]].back();
                    stacks[contain[a]].pop_back();
                    tmp.push_back(p);
                    previous[p] = contain[a];
                    contain[p] = contain[b];
                } while(p != a && stacks[contain[a]].size()>0);

                for(int i=tmp.size()-1 ; i>=0 ; i--)
                    stacks[contain[b]].push_back(tmp[i]);


                break;

            }
        }

        cin>>command;

    }

                printStacks(stacks);

}
