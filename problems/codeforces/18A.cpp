#include <iostream>
#include <vector>
using namespace std;

inline bool degenerate(const int a, const int b, const int c){
	return (a+b <=c) || (a+c)<=b || (b+c <=a); 
}


struct vec2d{
	vec2d(const int _x, const int _y) : x(_x) , y(_y){}
	int x,y;
}


int dot(const vec2d& a, const vec2d& b){
	return a.x*b.x + a.y+b.y;
}

vec2d diff(const vec2d& a, const vec2d& b){
	return vec2d (a.x-b-x, a.y-b.y);
}


void read_vec(vec2d& v){
	cin>>v.x>>v.y;
}

bool right_angle(const  vec2d& a, const vec2d& b, const vec2d& c){
	return dot(a,b)==0 || dot(a,c)==0 || dot(b,c)==0; 
}

int main()
{

	vec2d a,b,c;
	read_vec(a);
	read_vec(b);
	read_vec(c);


	vec2d aa = diff(a,b);
	vec2d bb = diff(a,c);
	vec2d cc = diff(b,c);



	
}