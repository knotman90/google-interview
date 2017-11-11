#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>


using namespace std;

typedef pair<string,string> book;
int main(){

vector<book> shelve;
vector<book> borrowed;
vector<book> returned;

string title;
string author;
string buffer;
getline(cin,buffer);
while(buffer !="END"){
	int split=buffer.find("\"",1);//find the second "
	title = buffer.substr(1,split-1);

	author = buffer.substr(split+4,buffer.size());

	book b = make_pair(author,title);

	shelve.push_back(b);

//	cout<<title<<" "<<author<<endl;

	getline(cin,buffer);

}

cin>>buffer;
while(buffer!="END"){
	if(buffer== "BORROW"){
		getline(cin,buffer);
		 buffer=buffer.substr(2,buffer.size()-3);
		//remove from shelve add to borrowed
		auto it = find_if(shelve.begin(),shelve.end(),
			[&](const book b1){return b1.second==buffer;}
		);
		if(it != shelve.end()){	
			borrowed.push_back(*it);
			shelve.erase(it);
		}


	}
	else if (buffer=="RETURN"){
		getline(cin,buffer); 
		buffer=buffer.substr(2,buffer.size()-3);
		//remove from  borrowed add to returned and to shelve
		auto it = find_if(borrowed.begin(),borrowed.end(),
			[&](const book b1){return b1.second==buffer;}
		);
	if(it == borrowed.end()){
		cout<<buffer<<"\n";
}		
shelve.push_back(*it);
		returned.push_back(*it);
		borrowed.erase(it);

		
	}
	else{
	//shelve it
	sort(shelve.begin(),shelve.end());
	sort(returned.begin(),returned.end());
	for(auto b: returned){
		auto it = find(shelve.begin(),shelve.end(),b);
		if(it==shelve.begin())
			cout<<"Put \""<<(*it).second<<"\" first"<<endl;
		else{
			auto prec = it-1;
			cout<<"Put \""<<b.second<<"\" after \""<<(*prec).second<<"\""<<endl;
		}
	}
	returned.clear();
	cout<<"END"<<endl;	
	}

cin>>buffer;
}

return 0;

}
