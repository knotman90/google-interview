#include<common.h>

using namespace std;

class node{
public:
    string n;
    vector<node*> cs;
    bool done;

    node(){};
    node(string _n,bool _done = false): n(_n), done(_done) { }

    node* findChild(string s){
        auto f = [&](node* node){
            return ((node->n) == s);
        };
        auto ret = DS::find_if(cs.begin(),cs.end(),f);
        if(ret != cs.end())
            return *ret;
        return nullptr;
    }

    bool isLeaf(){
        return cs.size()==0;
    }
    ~node(){
        LOOPUP(i,cs.size()){
            delete cs[i];
        }
    }

};

void addNodes(vector<string> split, node* parent, bool val, int& count){
    if(split.size() > 0){
        string v = split.back();
        split.pop_back();
        node* present = parent->findChild(v);
        if(present)
            addNodes(split,present,val,count);
        else{
            //node not present create a new one
            if(val)
                count++;
            

            node* n = new node(v,val && true);
            parent->cs.push_back(n);
            addNodes(split,n,val,count);
        }
    }

}


#define CLRSS(ss) ss.clear(); ss.str("");

int main(){
    int T; cin>>T;
    LOOPUP(i,1,T+1){
        int N,M; cin>>N>>M;
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        //cout<<N<<" "<<M<<endl;
        node* root = new node();
        stringstream ss;
        auto foldsplit = [&](auto* split, char c){
            if(c=='/'){
                split->push_back(ss.str());
                CLRSS(ss);
            }else{
                ss<<c;
            }
            return split;
        };

        int count = 0;
        //alreadypresent
        LOOPUP(j,N){
            string s; cin>>s;

            s=s.substr(1,s.size());
            vector<string> split;
            DS::fold(ALL(s),&split,foldsplit);
            split.push_back(ss.str());
            DS::reverse(split,split.size());
            //DS::print(ALL(split));
            CLRSS(ss);
            addNodes(split,root,false,count);
        }

        //create
        LOOPUP(j,M){
            string s; cin>>s;

            s=s.substr(1,s.size());
            vector<string> split;
            DS::fold(ALL(s),&split,foldsplit);
            split.push_back(ss.str());
            DS::reverse(split,split.size());
            //DS::print(ALL(split));
            CLRSS(ss);
            addNodes(split,root,true,count);
        }
        printf("Case #%d: %d\n",i,count);

        delete root;
    }

    return 0;
}
