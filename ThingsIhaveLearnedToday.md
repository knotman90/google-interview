Things I have Learned

1\15


#xdd and radare2 
xdd is a hex editor and radare2 is a framework used for reverse engineering

#string command
Given a binary file you can use string command in Linux to extract all valid strings from a binary. It searches for valid ascii chars terminated by a NULL char.\
You can use this tool to inspect a binary. You can get a lot of knowledge from it

#objdump is another tool for inspecting binaries. It basically converse the binary to a slightly more readible assemblish

#patentability
An indea to be patentable has to be **instrustrially applicable + novel + non-obvious**


1\16

- using std::thread if you don't call join or detach from the parent thread then when the child destructor is called then the entire applicatrion is terminated as the thread destructors calls std::terminate. Note that terinate is called only when the destructor of the std::thread is called and not when the actual function that the thread runs is finished. The thread might have no work to do but since the its std::thread handle is still in scope then everything is fine.


- Detaching a thread means the thread itself is separated from the std::thread handle it was spawned from. This means that for instance a very short function can create a temporare thread object and launch it with a very time consuming function. The parent thread will conclude its function quickly destroying the temporary handle. Since the thread was detached, then the spawned thread will continue to run. THere is no wa of communicating with it DIRECTLY, or wait for it to complete (join)

- join a thread will cause the caller to wait untile the std:;thread has completed its task. Note that you either join and wait untile the thread has completed or not join and continue working. If more fine grained behavior are needed then one has to use other solutions as: polling the child thread or use condition variables etc. Note that the associated std:;thread object is no longer available and valid anywhere in the code as join destroyes it. You can call join only once.

- Thread constructor is UNAWARE of the way the supplied thread function parameters are passed. It simply copies all the parameters into internal storage of the thread and then the thread function uses them. So let's say we have:

```c++
void function(string & s){
	modify_s(s);
}
int main{
	string s="sldkfksldfhsdk";
	cout<<s<<endl;
	std::thread(function,s):
	cout<<s<<endl;
}
```

the main thread is not able to see the modification on s because function modifies the copy of s that has been performed by the thread constructor that has been memorized in the internal storage of the thread.
If s in main has to be modified by the thread then, the the parameters in std::thread function calls must be wrapped in a std::ref i.e. std::thread(function,std::ref(s));

- Thread is not copiable  and is movable only
```c++
std::thread t1(f1)
std::thread t2 = std::move(t1); \\t1 is empty now
```
- std::bind is used to bind the first argument to the rest of the argument and call eht first argument with the rest as parameters. One can also partially define the parameters of the first argument and use placeholder instead. 
```c++
void f(int a, double b , float c, const string&s):
auto ff = std::bind(_2, 23.9, 33.99, _1);
```
ff is a sort of new function that takes two arguments. so ff("hello",2) will result in the following function call `f(2, 23.9,33.9,"hello" );`

- std::mem_fn is used to create a wrapper for a member function. this wrapper can later used to call a member function on a pointer or reference to an object. smart pointer can be used to invoke std::mem_fn too
```c++
class Foo{
	void dummy(int a, const string&s){...}
};
int main(){
	auto p = std::mem_fn(&(Foo::dummy)):
	std::unique_ptr ptf(Foo());
	p(ptf,12,"hello"); \\call Foo().dummy(12,"hello");
}
```
- threads can be identified by a thread::id. ids are totally ordered = there is a whole set of comparison operator. Note also that std::hash(std::thread::id) is defined so a thread is can be used a a key in a unordered_map for instance. how the id is implemented is implementation defined. Note that the id cannot be used for other array index. It has no semantic meaning other than idengfiying a thread uniquivocally and being totally ordered.



17/01

- mutex stands for mutually exclusive. you can use std::mutex and call member function as lock and unlock directly from an mutex object but that is farily bad practice because unlock shhould be called on every exit path, exceptions included and this is an error prone practie. use std::lock_guard instead which implements the RAII idiom for mutex. Lock is called on a mutex on construction and unlock on destruction (and we are sure that even in the event of exception the destructor is indeed called).



23/01

- GREP Commands

alias search="grep -n -i -r -color -e "
grep - Hnir --color 'regex' folder

- FIND
basic sintax 
find (name/size/type/access or modified date) ..argument ..argument

alias ff  find -L ./ -type f -iname 
alias ffs find  -L ./  -type f -name

-L is important for symbolic links!

Another example. Search symbolic link too for folders recursing up to two levels down
find -L $FOLDER  -maxdepth 2 -type d -iname "*KPPC*



24/01

dynamic_cast is used to safely convert pointers. If the cast if succesfull it return a pointer to the new_type otherwise it returns a nullptr or raise an exception 
const_cast removes the const or volatile attribute from a pointer type (or reference)


25/01

std::call_once is used to ensure that the callback provided is called exactly by one thread only. It can bbe used to substitute the double chheck locking pattern
Imagine a scenario when multiple thread executes a function that uses a pointer and that pointer has to be lazy inizialited by the first thread that encounters it in a NULL state.
you can use call_once to ensure that the init function is called  only once among all threads.


29/01
Condition variables are used as means of synchronization between threads that can wait for a condition to be satisfied and be notified when the condition is true so theuy con continue processing.
They work in conjunction with a mutex. The thread waiting on the condition variable uses a unique_lock (that can be locked and unlocked freely). It locks it first and then calls the member function `wait(lock, condition_lambda)` of the condition_variable class that works as follows:
1. if the fondition is true, is returns and keep the lock locked for the current thread.
2. if the lambda returns false, then the thread is put into sleep and the lock is unlocked.
3. another thread in the meanwhile can call the member function notify_one() and then one of the threads in the sleep state is awakened (point 1)

Note that the lambda function should be side effect free because threads might be notified spuriously (that would cause spurious side effects)



Thread safe producer/consumer queue.
```c++
using std::mutex;
using std::condition_variable;
using std::queue;
template<class T>
class thread_safe_queue
{
private:
	mutex mut;
	queue<T> q;
	condition_variable cv;
public:

	void push(T new_value){
		lock_guard(mut);
		q.push(new_value);
		cv.notify_one();
	}

	bool try_pop(T& value){
		lock_guard(mut);
		if(q.empty())
			return false;
		value=q.front();
		q.pop();
		return true;
	}

	shared_ptr<T> try_pop(){
		shared_ptr p = make_shared(nullptr);
		lock_guard(mut);
		if(!q.empty()){
			p = make_shared(q.front());
			q.pop();
		}
		return p;
	}

	void wait_and_pop(T&value){
		unique_lock(mut);
		cv.wait(mut, [](){return !q.empty();});
		value = q.pop();
		q.front();
	}
	shared_ptr<T> wait_and_pop(){
		unique_lock(mut);
		cv.wait(mut, [](){return !q.empty();});
		shared_ptr<T> r (make_shared(q.front());
		q.pop();
		return r;
	}
};
```

Use condition variables when threads repeteadly wait for that condition to be true. If this is a one time only thing then future might be a better choice.
A future is a way for a thread to wait for an event (asynchronous result or event) that might have data associated with it. The thread can periodically poll the future and do other stuff in the meanwhile the future object is not ready.
Note that future do not provide synchronization mechanism and hence if multiple threads need to access the future then some sort of mutex protection is required.
futures are returned by std::async(function_provided_by_user, args...). The future is a non blocking object until ready() member function is called upon him. 
This means that a thread can launch an async computation and then do other stuff. When the value hold by the future is required then it can call ready() and only at that point it will be blocked.
One can also customize the how future are run using the stdL:;launch optional parameter to std::async. A future can be std:;launc::async meaning it runs in a new thread (and it is guaranteed to be ran) or can be std::launch::defeered meaning tthat its execution is defeered at the point where get() or wait() are called on the future (and if those are never called the computation might never start, as a sort of lazy computation)..


```c++
int find_the_answer_to_ltuae();
void do_other_stuff();
int main()
{
	std::future<int> the_answer=std::async(find_the_answer_to_ltuae);
	do_other_stuff();
	std::cout<<"The answer is "<<the_answer.get()<<std::endl;
}
```


31/01

An higher level abstraction for async task is the std::packaged_task templated on a function type which stores a future. The packaged task can be passed around and the future can be retrieved by other threads and another one at some point can execute the task using the operator() and only when this function return the future will be made reade for the other threads. It is an alternative way of starting an async computation  returning a future. In this case, one can choose the exat moment when the task start to be executed.
For more complicated cases, those for instance where the result associated with the async computation does not come from a single function, then a more sophistocated object is required. std::promise 

- future b design allows only one thread to wait the result as it is designed for single-ownership. Once you call get on a future the values are not present anymore into the future. Thus if multiple threads need the value of an asynchronous calls, then promise it not useful USE shared_future instead. shared_futures is copyable (normal future is only movable meaning that you can transfer ownership but you can have only one owner at the time) so multiple object (futures) can refer to the same async computation.
The patter is that each thread thhat need to wait for the async value can have its own copy of shared_future and call get() on it. This is safe to do and does not pose data race problem. Note that if multiple thread uses a single shared_future concurrently then you might have problems since methods of a single instance are not synchronized.

02/02

shared_futures are constructed from futures and since the latter are not copyable thhey must be moved into the shared_future. since this is a common operation future uses share() member function to transfer ownership to a newly created shared_future.
```c++
std::promise<type> p;
p.set_value(somevalue);
auto sf = p.share();
```
Now the future in the promise p is INVALID but sf is a shared_future<type> that can be safely used.

There is a number of variant to the threads waiting function  that allows timed wait (specified by a timeout or an absolute time e.g. wait for 5 minutes or until Nov-30 at 15:34:23.4234).


06/02
An object in c++ is a region of memory. an object can be made of subojects E.G. arrays of subclasses. Each memory location within an object is ether an object of scalar (fundamental type) or a sequence of bit fields. Thiss means that each bitfield has its own memory location shared among all the bits)



09/02
http://codeforces.com/problemset/problem/108/A
```c++
struct Time{
	char h1,h2;
	char m1,m2;

	Time(){
	h1=h1=m1=m2='0';
	}

	void tick(){
		++m2;
		if(m2 > '9'){
			m2 = '0'
			++m1;
		}
		if(m1 > '5'){
			m1='0';
			++h2;
		}
		if(h1 < '2' &&  h2 > '9' || h1=='2' && h2 > '4'){
			h2=0;
			++h1;
		}
		if(h1 >'2')
			h1=0;
	}
	bool is_palindrome(){
		return h1==m2 && m1==h2;
	}

};

int main(){
	Time t;
	cin>>t.h1>>t.h2>>t.m1>>t.m1>>t.m2;
	t.tick();
	while(!is_palindrome()) 
		t.tick();
	cout<<t.h1<<t.h2<<":"<<t.m1<<t.m2;
	return 0:
}
```


http://codeforces.com/problemset/problem/492/C
```
struct Exam{
	int g;
	int b;
	bool operator<(const Exam& e){
		return b<e.b;
	}
};

int main(){
	int  n,r,avg;
	read(n,r,avg);
	vector<Exam> E;
	E.reserve(n);
	int sum = 0;
	for(int i=0 ; i < n ; ++i){
		Exam e; 
		cin>>e.g>>e.b;
		E.push_back(e);
		sum+= e.g;
	}
	sort(begin(E), end(E));
	int delta = avg* n - sum ;
	for(int i = 0 ; i < n ; ++i){
		if(E[i].g >= r)
			continue;
		int v = min(r-E[i].r , delta);
		ans+= v* E[i].b;
		delta-=v;
	}
cout<<ans<<endl;
}
```
12/02/18

http://codeforces.com/problemset/problem/768/B

```c++
//range is [l,r)
bool ith_value(const  int l, const int r, c int pos, const int value){
	const int dist = distance(l,r);
	const int mid = dist/2;
	if(dist <=1 || mid==pos)
		return value%2;
	
	if(pos < mid)
		return solve(l,mid,pos,value/2);
	return solve(mid+1,r,pos,value/2);
}

//complexity is N=(r-l) => theta(N)log(N)
long solve(const int l, const int r){
	long sum=0;
	const int len = (2^(log_2(n)+1))-1
	for(int i=l ; i <= r ; ++i)
		sum+=ith_value(0,len,i,n);
	return sum;
}
```


16/2018
#Rule of three
If one of the three following special member function of a class is defined then all of three should be defined too.
1. destrutor
2. copy construcor
3. copy assignment operator

The rational is that if one of them is defied by the programmer then it means that the compiler generated one is not good but the others having similar sementic should also be changed accordingly.
The rule is extended 

#Guideline for designing of a concurrrent lock based data Structure.

Minimize serialization enforced by mutexes.
1. Restrict the scope off locks as much as possible > performs the little amount of operation necessary to ensure correctness within the protection of locks
2. Porotect multiple part of the data structure with multiple mutexes if necessary
3. Check if a change in the logic of the internal wrking of the data structure might make concurrency more explicit.
4. do all data requires the same level of protection? can you allow multiple concurrent reads?

#ThreadSafe Stack
```c++
struct empty_stack : std::exception{
	const char* what() const throw();
};
template<class T>
class threadsafe_stack{
	private:
		std::stack<T> data;
		std::mutex m;
		using mutex_guard = std::lock_guard<std::mutex>;
	public:
	threadsafe_stack(){}

	//we are assuming that this is called once on creation by a single thread!
	threadsafe_stack(const threadsafe_stack &other){
		//the other stack should not be modified while we operate on it
		mutex_guard(other.m);
		data=other.data;
	}

	void push(T new_value){
		mutex_guard(m);
		data.push(std::move(new_value));
	}


};
```

#
```c++
// returns sum [0..n) 
inline constexpr long triangular(const int n){
	return (n(n-1))/2;
}

void printN(const int n , const char c){
	for(int i=0; i< n ; ++i)
		cout<<c;
}

int main()
{
 int cnt=0;
 while(triangular(cnt++) <= k) ;

 --cnt;
 printN(cnt,'(');
long rest = k-triangular(cnt);
while(rest > 0){
	if(rest >= cnt){
		rest-=cnt;
		cnt++; // superfluous. just keep it 
		cout<<'(';
	}else{
		cout<<')';
		--cnt;
	}
	
	
}

}
```



#http://codeforces.com/contest/918/problem/A

```
int main(){
	int n;
	cin>>n;
	string ans(n,'o');
	int p = 0;
	int c = 1;
	int sum = p+c;
	for( ; sum < n ; p+c, c=sum , sum=p+c)
		toUpper(ans[a]);
		
	cout<<ans<<endl;
	return 0;
}


```

#http://codeforces.com/contest/918/problem/B
```c++
int main(){
	int n,m;
	cin>>n>>m;
	unordered_map<string,string> M;
	loop0n(i,n){
		string name, ip;
		cin>>name>>ip;
		M[ip]=name;
	}
	loop0n(i,m){
		string command, ip;
		cin>>command>>ip;
		ip.erase(ip.end()-1,ip.end()); //remove semi-column from input
		cout<<command<<" "<<ip<<"; #"<<M[ip]<<endl;
	}
	return 0;
}
```


#http://codeforces.com/contest/918/problem/C
```c++
#include <iostream>
using namespace std;

bool T[5000][5000]={0};

bool odd(const int k){
	return k&1;
}

bool isValid(const int left, const int size, const string& s, const int length){
	const int right = left+size-1;
	if(left+size >= length || odd(size) ||  s[left]==')' || s[right]=='('){
		T[left][size]=false;
		return false; 
	}
	if(s[left]=='?' || s[right]=='?' || (s[left]=='(' && s[right]==')') ){
		if(right-size-2 <= 0 || T[left+1][size-1] ){
			T[left][size]=true;
			return true;
		}
	}
	
	// concatenation //O(size) = O(n)
	for(int left_size = 2 ; left_size < size ; left_size+=2){ 
		if(T[left][left_size] && T[left+left_size][size-left_size]){
			T[left][size]=true;
			return 1;
		}
	}
	T[left][size]=false;
	return false;
}

int main(){
	int n,m;
	cin>>n>>m;
	string str; cin>>str;
	const int len = str.size();
	int ans = 0;
	for(int size = 2 ; size < m ; size+=2){
		for( int left = 0 ; left < n ; left++){
			if(left + size > n)
				break;
			ans+=isValid(left, size, str,  len);
		}
	}
	return 0;
}
```





- 

vedi problemi di http://codeforces.com/submissions/DarthPrince


# write a parallel bubble sort
divide the algorithm in two
1. odd phase where only odd pairs (2n+1,2n+2) elements are swapped
2. even phase where only even pairs (2n,2n+1) elements are swapped
if we have k threads and the collection size is n then each phase consists of floor(n\2) pairs
thread i can take care of the pairs from `[ i*floor(n\2)/k` to `(i+1)*floor(n\2)/k  )`

a shared (mutex protected) variable can be used to mark the end of the computation
this variable (is_sorted) is set to false by each thread that if is_sorted && the thread performed a swap
You should make sure that reading the shared variable can be done in parallel by many threads while writing to it should be write protected (maybe a shared_mutex?).

Another solution could be for each thread to have its own is_sorted (thread storage qualifier) and at the end of phase two a parallel AND reduction can take place (among all the is_sorted flags). This way you can asses if the added complexity of performing the reduction (log k) is greater than the cost of managing a shared variable via mutex.



#implement bitonic sort 


#codility array.2 (rotate array inplace)
// you can use includes, for example:
// #include <algorithm>

constexpr inline int get_new_position(const int idx, const int K, const int size){
    return (idx+K)%size;
}


vector<int> solution(vector<int> &A, int K) {
    //easy if you keep a copy of A.
    // simply map elements from A(K...K+N) to A'(0..N)
   
    const int size = A.size();
    if(!size || !K)
        return A;
    K%=size;
    
    
    int idx = 0;
    int curr_el = A[idx];
    if(size%2==0 && K==size/2)
    {
         for(int i = 0 ; i <  size/2 ; ++i, idx++){
             const int new_idx =  get_new_position(idx, K,  size);
             swap(A[idx],A[new_idx]);
         }
    }
    else
    {
        for(int i = 0 ; i <  size ; ++i){
            const int new_idx =  get_new_position(idx, K,  size);
            int next_el = A[new_idx];
            A[new_idx] = curr_el;
            curr_el = next_el;
            idx = new_idx;        
            
        }
    }
    
    return A;
}


30/03
tput can be used to manipulate the curcor or colors. use man terminfo for a list of capabilities (all of them are device independent)

array size in bash can be retrieved with `${#ARRAY[@]}` 
you can used the command read to read some string into specific bash format. For instance you can read a string and save it as an array using the folloring: `read -r -a  ARRAY <<< "STRING"`. Note that -a cause each element to be treated as an array element
 `<<<` is a *here string* i.e. a string that gets passed to `stdin`.
 `<<` is a *here document*, passes everything to the left until the argument of `<<` is encountered.




11/04/18
In bash you can use the instruction pushd popd and dirs to manipulate the directory stak. It can be used to change directory and return back to the starting point for instance.

`pushd <directory>` change directory and also put `<directory>` onto the stak of directories.
`dirs` shows the stack
`popd` remove the directory from the stack.

For instance:

```bash
    user@vb:~$ mkdir navigate
    user@vb:~/navigate$ mkdir dir1
    user@vb:~/navigate$ mkdir dir2
    user@vb:~/navigate$ mkdir dir3
```

Then you can add all your folders to the stack:
```bash
    user@vb:~/navigate$ pushd dir1/
    ~/navigate/dir1 ~/navigate
    user@vb:~/navigate/dir1$ pushd ../dir2/
    ~/navigate/dir2 ~/navigate/dir1 ~/navigate
    user@vb:~/navigate/dir2$ pushd ../dir3/
    ~/navigate/dir3 ~/navigate/dir2 ~/navigate/dir1 ~/navigate
```
You can look it up by:

```bash
    user@vb:~/navigate/dir3$ dirs -v
     0  ~/navigate/dir3
     1  ~/navigate/dir2
     2  ~/navigate/dir1
     3  ~/navigate
```
To navigate safely, you need to add the last (zero) folder twice, since it will be always rewritten:

```bash
    user@vb:~/navigate/dir3$ pushd .
    user@vb:~/navigate/dir3$ dirs -v
     0  ~/navigate/dir3
     1  ~/navigate/dir3
     2  ~/navigate/dir2
     3  ~/navigate/dir1
     4  ~/navigate
```

Now, you can jump around through these folders and work with stack as with aliases for the folders. I guess the following part is self explanatory:
```bash
    user@vb:~/navigate/dir3$ cd ~4
    user@vb:~/navigate$ dirs -v
     0  ~/navigate
     1  ~/navigate/dir3
     2  ~/navigate/dir2
     3  ~/navigate/dir1
     4  ~/navigate
    user@vb:~/navigate$ cd ~3
    user@vb:~/navigate/dir1$ dirs -v
     0  ~/navigate/dir1
     1  ~/navigate/dir3
     2  ~/navigate/dir2
     3  ~/navigate/dir1
     4  ~/navigate
    user@vb:~/navigate/dir1$ touch text.txt
    user@vb:~/navigate/dir1$ cp text.txt ~2
    user@vb:~/navigate/dir1$ ls ~2
    text.txt
    user@vb:~/navigate/dir1$ dirs -v
     0  ~/navigate/dir1
     1  ~/navigate/dir3
     2  ~/navigate/dir2
     3  ~/navigate/dir1
     4  ~/navigate
```




26/04/18 xterm terminal change font and size 
`xterm -fa 'Monospace' -fs 14`



1/05/18
#Code Comments
Comments do not make up for bad codes. We should theoretically avoid comments altogether. If a comment is necessary than the code is not written well enough.
Sometimes comments can add valuable information to the code. Whenever possible it information about the meaning of variables or methods should be encaplulated in the names of those variables of functions.
Comments like the following are useful. They add information that are not easily conveyed in a readable way by the language facilities. In this case it help the reader understanding what the patter match exatly.
```
// format matched kk:mm:ss EEE, MMM dd, yyyy
Pattern timeMatcher = Pattern.compile(
"\\d*:\\d*:\\d* \\w*, \\w* \\d*, \\d*");
```

Other cases in which it is usefule to put comments is when the intent is clear already but  the reasons behind might not. So use comments to justify the code or provide intent or rationale that cannot easily expressed by code itself.

Do not use todo comments because you have other tool to track stuff that need to be done.
Do not write systemwise comments. Let the documentation do it. 
comments should only appear near the code they refer to.
Do not put TOO much information or details into a comment. If necessary link to external resources (like an RFC or a paper).
If a comment is present then the comment should be well written and should be clearly linked to a piece of code it is about.

#Code Formatting
formatting is important. It is about communication, makes the code readable.  Size if part of formatting. Code files should not be too long.
Think about the newspaper mataphor. Code needs to be read as a newspaper i.e. vertivally. At the top of a newspaper you expect an headline which will briefly and concisely explain what the story is about and allows you to deciide if you think it is worth to keep digging into the details.  As you do so, the first paragraph gives you an overview of the whole story and each of the following subparagraph and section dissect all the details of the story with nested level of details.
Code should read as a newspaper.

Use newline to separate concept BUT group related stuff together without using newlines.
Distance between concept is also important. Things shhould be again as in a newspaper. You should be able to read all the code from top to bottom, without the need to jump around to search for anything.
Variables should be declared close to the point they are used (no more as it was 500000 years ago that need to be declared at the top of the function). It reduces the risk of aliasing and bugs. It also makes the code clearer as we do not need to go anywhere to check the type of a variable for instance.
Hhorizontal formatting is also important. New monitor can easily fit 200 characters per line, but that is way too much for human to confortably deal with. Maximum should be around 80/120, preferably less than 60.
Spaces can also serve as separators between non closely related concept. They are also useful for highlighing different part of the statement. (as in an assignment for example).



#Data Structures
Abstraction is really important and detail of impleementation should  be hided as much as posible to makes modules depend less to each other on details and more on interfaces. In this way what's behind the interfaces can be reimplemented easily without breaking any existing code. Exposing the implementation often means that the interface is crafted on those details. Imagine implementing a 2D point. If you choose to expose the details about the implementation then you are forcing your implementation to expose two numerical values (rectangular implementation)  or an angle and a norm (polar implementation); The best is to implement such interface that exposes both the methods and behind the scene you can implement everything that is needed.
Bottom line is when designing a data structure particular care should be taken in how it interfaces the outer world and how the details are hidden. Making variable private and adding getters and setter IS NOT THE WAY TO GO. most of the time getters and setters are not the best design choice. It shows lack of interface design.




#17/05/18
Nice value is a metric used by the linux fair scheduler [-10,20]. The higher the nice value the lesser priority a process has. It is a measure of how nice a process is to the others.
 


#05/06/18

Virtual memorry is the sum of the memory that a process has mappen into itself. It is a measure of the physical memory he thinks it is using. 
Resident memory is a good measure of the actuual physical ram that is used by the process. 
Shared memory indicated how much memory is actually sharable with other processes (e.g. shared libraried for instance). Assume for instance that a process p is using a library l.
It p uses only a portion of l, then l will be mapped entirely into virtual and shared memory but only the actual portion used by p will occupy some page frame (physical memory) and thus appears into the resident memory counter. This is the reason why virtually, for any process virtual is always bigger than resident, as most programs uses the C library.

Buffer and chace memory are used to speed up access to files. Most of the memory would be wasted in modern system if not employed as buffers or cache.
Buffers contains stuff like filesystem metadata while cache memory actually contains part and content of the file themselves. Note that buffers and cache can always be removed and assigned to a process that need it more. Those data can always be accessed (atte price of a slower access) from the disk.


#05/06/18
Convex hull

Given a set of points return a subset of those point such that they forma  convex hull for the whole set. I.e. they form a convex polygon with minimal perimeter that cointains all the other points.
various algorithms but probably the most famous is the graham scan. 
It works by first selecting the point P with lowest y coordinate (if there is a tie then we choose the one with smallest x).
Then the points are sorted by the polar angle that they form with the aforementioned point P (iff there is a tie sort by distance from P).
Then process the sorted list three points at the time and keep the set of candidate points for the hull in a vector. let's call the last three inserted points a,b,c .
Now if the  a turn to the right is necessary reach c from b then b does not belong to the hull and can be removed from the list of candidate points. 
Now recursively check the last three points until no right turn is necessary.
Continue adding points and recursively "backtrack" until there are no points left. 
How to determine iff a right turn is necessary? Compute the determinant of the matrix [a,b,c] if it is positive then is it a right turn.
This algorithm only works for 2D points!


#stock prices
Given a list of integer P find the pair `(i,j)` with that `P[i]-P[j]` is maximal.
Brute force solution is easy. Simply iterate all over the pair and return (i,j) with maximal P[i]-P[j]. Computational complexity is `O(n^2)`
Note that since we need to consider at least once all the elements there is no way we can do it better than O(n).

Note that if `p[j] < p[i]` then there is not way another index k >i >j exists s.t. `p[i]-p[k] > P[j]-p[k]` as `p[j]` is smaller than `p[i]`. This means that whenever we face this condition `p[j] < p[i]` then we can start again our search considering i as the new buying point.

```
int getMaxProfit(const vector<int>& stockPrices)
{
    // calculate the max profit
    int buy=0;
	int sell= buy+1;
	int curr_max = stockPrices[sell]-stockPrices[buy];
	while(sell < stockPrices.size() ){
    	if(stockPrices[sell] <= stockPrices[buy])
    		buy = sell;
  		
  		++sell;
  		if(sell >= stockPrices.size())
  		    break;
  		curr_max = std::max(curr_max, stockPrices[sell]-stockPrices[buy]);
	}
	return curr_max;

}
```




# Running median

N unsigned are randomly generated. For each new number output the current median. 
Brute force approach is: sort the current list of numbers and take the middle element.
Cost is log1 + 2log2 + 3log3 + .... + nlogn = Omega(n^2)


#Given a number `n`, find a list of number of minimum size {x0,x1,x2,x3...xk} s.t.
`xo^2 +x1^1 + ... + x^k =n`

Brute force for this problem could be to start from k+sqrt(n) and try to solve the problem for n-k
```c++
void brute_force(const int n, unsigned steps, const unsigned& ans){
	if(n < 0)
		return;
	if(n==0)
		ans = max(ans, steps);

	const unsigned sq = sqrt(n);
	int stop = 0;
	unsigned ans = -1;
	const new_n = n-sq;
	while(sq && new_n >=0 ){
		brute_force(new_n , steps++ , ans);
		sq--;
		new_n = n-sq*sq;
	}

}
```
Complexity  is `T(n) = sqrt(n) + T(n-floor((sqrt(n)-i)*(sqrt(n)-i)))`

We can improve the solution by employying DP. The idea is to use dynamic programming here to resuse solution to subproblems over and over.
We will fist use memoization and recursion to solve this problem
```c++
int solve1(const int n, const int steps, unordered_map<int,int>& M)
{
   
	if(n == 0)
		return 0;	 
    if( n  < 0 )
		return -1;
    
	unsigned  ans = numeric_limits<unsigned >::max();
	for(int i = sqrt(n) ; i >=1 ; --i)
	{
		const int new_n = n - i*i;

		int new_ans = -1;
		if(M.find(new_n) != end(M))
		{
			new_ans = M[new_n]+1;
            hit++;
        }
		else
         {
		 	new_ans = solve1(new_n , steps+1 , M)+1;
         }
		 ans = min(ans,new_ans);
	}
	M[n] = ans; //memoize
	return ans;
}
```


# Given a list of size `n` of unique integer positive (zero included) numbers, write a function that return the smallest number **not** present in the list.

## Questions
- Do the number lie in a particular range (if yes , then simply use an array of flags to check what numbers are present or not)



First of all note that `max(LIST) >= n-1` because of the pigeon principle. It is not possible to have `n` numbers all  strictly smaller than `n-1`, because there is `n` numbers from `n-1` to `0` (both sides included) and all of them need to be unique. So at least one of them must be `n-1`. 
So if you have `n` numbers the missing element must lie in the interval `[0,n]`.


What can be done is create an array of flags of size `n` and loop over the LIST and we mark the elements that we see in the LIST.
Then we can loop over the flags and return the first index `i` s.t. the flag is not set. This will cost `O(n)` time and space.
```c++
using ID = unsigned;
int missing_id1(const vector<ID>& ids)
{
	const unsigned vsize = v.size();
	vector<bool> flags(vsize, false);
		for(const auto id : ids){
			if( id < vsize)
				flags[id] = true;
		}
		for(int i = 0 ; i < vsize ; ++i)
			if(flags[i])
				return i;
		
	return vsize();
}
```
We can do better using divide and conquer and borrowing the partition algorithm from quicksort.
Note that if all numbers in a list of size `n` are `< n` then the missing element is `n`. We can use this to create a more efficient algorithm that splits the array in two halves and partition the elements in two sublist A and B. 
`A` contains all elements `<= n/2` and `B` all the elements `> n/2`
We can look at the size of `A` and if `|A|` is less than `n/2` then it means that some number is missing and we can forget about `B`. Otherwise we keep looking into `B` and we can forget about `A`.
We can recursively do this until we reach the point where we have an empty list. At that point is means that we found our missing number.


```c++
using ID = unsigned;
inline int missing_id_divide_conquer(const vector<ID>& ids)
{
	return missig_id_helper(ids, 0 , ids.size());
}

int missig_id_helper(vector<ID>& ids, int l , int r){
	}

```


# Implement a doubly linked list using only a pointer `both` which is the `xor` of `next` and `prev`
```c++
template < class T >
  struct Node {
    Node * both;
    T value;
    Node(T el): value(el) {};
  };

template < typename T >
  class LinkedList {
    public:
      LinkedList(): head(nullptr), tail(nullptr), length(0) {};
    void insert(T el) {
      Node <T> * n = new Node(el);
      if (!head) {
        head = tail = n;
      } else {
        tail -> both = XORPtr(tail -> both, n);
        n -> both = tail;
        tail = n;
      }
      ++length;
    }

    T find(const unsigned idx) {
      return find_helper(idx, nullptr, head);
    }

    void remove(const T el)
    {
    	return remove_helper(el, nullptr, head);
    }

    void print() {
        if(!head || length == 0)
            cout<<"EMPTY"<<endl;
      for (unsigned i = 0; i < length; i++) {
        cout << find(i) << " ";
      }
      cout << endl;
    }

    private:
      Node <T> * head, * tail;
    unsigned length;

    void remove_helper(const T& el, Node<T>* prev, Node<T>* curr)
    {
    	if(!curr)
    		return;
        
        Node<T>*const next = XORPtr(curr->both, prev);
    	if(curr->value == el){
            if(prev) prev->both = XORPtr( XORPtr(prev->both , curr) , next);                  
            if(next) next->both = XORPtr( XORPtr(next->both , curr) , prev);
            length--;
            
            if(!prev)
                head = next;
            if(!next)
                tail = prev;
            
    		return;
        }

    	
    	return remove_helper(el, curr, next);
    }

    T find_helper(const unsigned idx, Node <T> * prev, Node <T> * curr) {

      if (idx == 0 || !curr)
        return curr -> value;
      Node <T> * const next = XORPtr(curr -> both, prev);
      return find_helper(idx - 1, curr, next);
    }

    Node <T> * XORPtr(Node <T> * a, Node <T> * b) {
      return (Node <T> * )(
        (unsigned long) a ^ (unsigned long) b
      );
    }

  };

int main() {

  LinkedList < int > ll;
    constexpr unsigned S = 10;
    vector<int> el;
    el.resize(S);

    for (int i = 0; i < S; i++)
        el[i] = i;
    
   for (int i = 0; i < 10; i++) {
    ll.insert(el[i]);
    ll.print();
  }
   //remove them randomly
   unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
   shuffle (el.begin(), el.end(), std::default_random_engine(seed));
  //remove head  
   for (int i = 0; i < 10; i++) {
    ll.remove(el[i]);
    ll.print();
  }  
   
  return 0;
}
```



# Metaprogramming
```c++
template<unsigned N>
struct is_even{
  constexpr static bool value = !(N&1);
};

//base template
template<unsigned base, unsigned exp, typename T = void>
struct ipower_improved;

//specialization for even exponents
template<unsigned base, unsigned exp>
struct ipower_improved<base,exp, typename enable_if<is_even<exp>::value>::type> {
	private:
		constexpr static unsigned __value =  ipower_improved<base , exp/2>::value;
	public:
    	constexpr static unsigned value = __value * __value;
};

//specialization for odd exponents
template<unsigned base, unsigned exp>
struct ipower_improved<base,exp ,  typename enable_if<!is_even<exp>::value>::type> {
    constexpr static unsigned value = base * ipower_improved<base , exp-1>::value;
};

//base case
template<unsigned base>
struct ipower_improved<base,0> {
    constexpr static unsigned value = 1;
};
```

#Given the interval [a,b] and a digit d, count the number of occurrences of d in all numbers in [a,b]
Example [1,123] d=4 will result in: 






#Bit operations
- `p | 1` adds one only if `p` is even
- `p^1` results in `p+1` is `p` is even or `p-1` if `p` is odd




#Policy based Data structure
Data structure that allows to:
- query for the kth ordered element in a collection. `KEY find_by_order(const order ord)`
- Retrieve the order of a given key `order order_of_key(const KEY k)`


```c++
template<class Key>
struct Node{
	Key payload;
	Node* left,right;
	unsigned num_nodes;	
};
```
This is easily implementable by using a BST and augmenting the node with a count of the number of children in the subtree rooted at that node.
If you use a self balancing tree, both operations are guaranteed to be `logN`.
The invariant in this case is that `root.num_nodes = 1+left.num_nodes + right.num_nodes`. This can be easily maintaned during the update of the tree by simply bubbling up the invariant up to the root of the tree.

`KEY find_by_order(const order ord)` can be implemented as follows (ord is an index and starts from `0`).
Given the current node root and its children i.e. left and right if 
- `left.num_nodes == ord` it means that the we have ord element in the current left subtree. Since we are searching for the element with index `ord` which is the `ord+1` element (if we start counting from `1`) then out element is the one located at the root. So we return the current node `root`.
- if `left.num_nodes > ord` then our element is located in the left subtree and we have to recursively search in it.
- Otherwise we have to look in the right subtree. But we have to look for a different order in this case. We have to `"remove"` all the elements from the left subtree first, so we will search for `ord - left.num_nodes -1` (`-1` is for the root).

```c++
Key find_by_order(const order ord, const Node* root){
	if(root!= nullptr){
		const int order_left = root.left ? root.left.num_nodes : 0;
		const int order_right = root.right ? root.right.num_nodes : 0;
		if(order_left == ord)
			return root.payload.
		if(order_left > ord)
			return find_by_order(ord, root->left);
		return find_by_order(ord - order_left -1 , root->right);
	}else
		return nullptr;
}
```



```
  template<typename T,
           typename cmp_fn = less<T>> // less_equal if you want duplicates
  using order_statistic_tree =
    __gnu_pbds::tree<T, 
                     __gnu_pbds::null_type,
                     cmp_fn,
                     __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;

```
You can use this DS as a normal set of multiset or map orr multimap, but also use the following methods:
- find_by_order and order_of_key.
```c++

// Program showing a policy-based data structure. 
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <iostream> 
using namespace __gnu_pbds; 
using namespace std; 
  
// a new data structure defined. Please refer below 
// GNU link : https://goo.gl/WVDL6g 
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    new_data_set; 
  
// Driver code 
int main() 
{ 
    new_data_set p; 
    p.insert(5); 
    p.insert(2); 
    p.insert(6); 
    p.insert(4); 
  
    // value at 3rd index in sorted array. 
    cout << "The value at 3rd index ::" 
         << *p.find_by_order(3) << endl; 
  
    // index of number 6 
    cout << "The index of number 6::" 
         << p.order_of_key(6) << endl; 
  
    // number 7 not in the set but it will show the  
    // index number if it was there in sorted array. 
    cout << "The index of number seven ::"
         << p.order_of_key(7) << endl; 
  
    return 0; 
} 


```

#Given three lines of length a,b,c, they forma triangle is the followings are all true:
- `a+b > c`
- `a+c > b`
- `b+c > a`
Sum of two of them is greater than the third one.




#Adding `x` to all the elements but one (i.e. element `e`) it's equivalent to decreasing the value of `e` by `x`.

## Problem 
Given `n` integers, you can only perform one operation them i.e. add `1` or `2` or `5` to all of them but one. 
What is the minimal number of operation required to make all the element equal?

As mentioned earlier adding `x` to all numbers but one is equivalent to decreasing the value of that sole number b `x`. 
The question can be translated to: what is the minimum number of decrease operation on a single element that one has to make in order to make them equal? 
Note that the cost of making a single element `a_i` equals to `T` i.e. the target number is `a_i - T` and also note that `T` cannot be greater than the min of all the numbers. Because in order to make min(a0,a1,a2..an) equal to T we would need to add something and addition is not allowed.
So a brute force approach could be the following
```c++
ans = MAX_INT;
for all T in {0...min(a0,a1,a2..an)}
	ans = min(ans , cost(T));
```
where `cost(T)` is the cost of making all the element equal to `T`. 
`cost(T)` is defined as follows.
```c++
int cost(const int T){
	int cost = 0;
	for(const int ai : A){
		const int tgt = ai-T;
		cost+=tgt/5 + (tgt%5)/2 + (tgt%5)%2;
	}
	return cost;
}
```
cost(min) = for all i: ( (ai - min)/5 + ((ai - min)%5)/2 + ((ai - min)%5)%2  )
cost(min) = for all i: ( (ai - (min-1))/5 + ((ai - (min-1))%5)/2 + ((ai - (min-1))%5)%2  ) = 
						( (ai - min +1)/5 + ((ai - min +1)%5)/2 + ((ai - min +1 )%5)%2  )
						....

cost(min - 5) = for all i: ( (ai - (min-5))/5 + ((ai - (min-5))%5)/2 + ((ai - (min-5))%5)%2  ) = 
						( (ai - min +5)/5 + ((ai - min +5)%5)/2 + ((ai - min +5 )%5)%2  )

for cost(min-5) we notice that `( (ai - min +5)/5  > ( (ai - min)/5` hence there is not need to compute anything greater than min-5 as target because that would for sure lead to a suboptimal answer.

So to wrap up:
the anwswer is: the minimum of: `cost(min), cost(min-1), cost(min-2), cost(min-3), cost(min-4)`

```c++
int cost(const vector<int>& arr, const int T){
    int cost = 0;
    for(const int ai: arr){
        const int tgt = ai-T;   
        cost+= tgt/5 + (tgt%5)/2 + (tgt%5)%2;
    }
    return cost;
}

int equal(vector<int> arr) {
    const int m = *min_element(begin(arr), end(arr));
    int ans = numeric_limits<int>::max();
    #pragma omp parallel for
    for(int i = 0 ; i <= 5 && (m-i)>=0 ; i++)
        ans = min(ans, cost(arr,m-i));
    
    return ans;
}
```

#Problem 116 of projecteurler.org
It is solvable using the following reasoning:
Given N cells and a stick off length len, one can decide to:
1. leave one cell empty 
2. fill the next len cells with a stick

Note that both decisions leads to a smaller problems. Leaving one cell empty means solving the problem for `N-1` and filling the next len cells means solving a subproblem for `N-len`
The recursive formula is at follows: `ways(N,len) = ways(N-1, len) + ways(N-len, len)`
Note that 
- when `N < 0` we should return `0` as we cannot fill a negative number of cells.
- when `N>=0 && N<len` we should return `1` as there is only one way we can fill such number of cells i.e. leave them empty
- when `N==len` we have only two ways: leave them empty or fill it with a single stick of length `len`

The simple recursion will lead to exponential execution time  because the same coomputation is repeated many times.
For instance
                   ways(5,2)
       ways(4,2)               *ways(3,2)*
*ways(3,2)*  *ways(2,2)*    *ways(2,2)*  ways(1,2)

Since there is not more than N indipendent calls, this is easily solvable by caching the result of ways(N,len) and returning it instead when we are asked for it from the second time onwards.


```c++
long long ways(const int N, const int len){
    constexpr int MAXL = 51;
    static long long DP[MAXL] = {{0}};
    
    if(N<0)
        return 0;
    if(N==len)
        return 2;
    if(N<len)
        return 1;
    if(DP[N]>0)
        return DP[N];    
    
    const long long ans = ways(N-1, len) + ways(N-len,len);
    DP[N] = ans;
    return ans;
   
}
long long solve_116(){
    return ways(50,2)+ways(50,3)+ways(50,4);   
}
```

#Problem 117 of projecteurler.org
This is very similar to 116 but in this case we can use multiple sticks of different length.
Again, for each square, we can leave it blank (or think about filling it with a stick of length 1) or fill with one of the sticks available.

```c++
constexpr int MAXL = 51;
static long long DP[MAXL]{0};

long long ways(const int N, const vector<int>& lengths){
     if(N==0)
         return 1;
    if(DP[N]>0)
        return DP[N];    
    
    long long ans = 0;
    for(const auto l : lengths){
        if(l<=N)
          ans += ways(N-l,lengths);
    }
    DP[N] = ans;
    return ans;
}
```

# Given an array a of N integers a1, a2, a3, ... aN you have to find the longest alternating sub-sequence of this array.
An alternating sequence `b1, b2 ... bk, k>=1` is a sequence that has the 2 following properties:
1. `|b1|<|b2|<|b3|<.....<|bk|`
2. The signs alternate between adjacent elements, i.e, if `b1 > 0` then `b2<0`, `b3 >0` and so on. Alternatively, if `b1<0`, then `b2>0`, `b3<0` and so on.
A sub sequence of array a is a sequence obtained by dropping some elements of the array a. Here is the formal definition.
It is guaranteed that the array a contains no element equal to 0.
Constraints

`1<=N<=5000 |ai|<=10^9`, `a_i` not equal to `0`.
## Solution

The idea is that if we start from the end of the sequence, i.e. the very last element, then the longest alternating subsequence (LAS) is `1` (the number itself).
Given LAS(i) we can compute LAS(i-1) as follows;

`LAS(i) = max(1  , LAS(k) )`  where `k > i` and `A[i] < A[k]` and `signum(A[i]) != signum(A[k])`

Why does it work? because a trivial sequence is always made by a single element. And if can be extended then it must be the case that it should be extended by a sequence starting with a number of higher absolute value and different signum. if there are multiple starting points, then the optimal way to do it, is by extending it with the longest of those subsequence.
The following is a bottom up solution:
Complexity is `O(n^2)`
```c++
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

int solve(){
    
    int ansans = 1;
    for(int k = n-1 ; k >=0 ; k--)
    {
        int ans = 1 ;
        for(int k1 = k+1 ; k1 < n ; k1++)
            if( sgn(A[k]) != sgn(A[k1]) && abs(A[k]) < abs(A[k1]))
                ans=max(ans, 1+DP[k1]);
            
        ansans = max(ans, ansans);
        DP[k] = ans;
    }
     return ansans;
}
```

#Binary search
Repeatedly split the search space in a half, effectively avoiding searching in the other half. Search can be carried out in O(logn) steps.
It can also be applied on every increasing sequences, both discrete and continue.


```c++
template<class T, class RndAccessIterator>
bool binary_search(RndAccessIterator begin, RndAccessIterator end, const T target){
	if(begin <= end){
		auto mid = begin + distance(begin, end)/2;
		if(target == *mid)
			return true;
		if(target > *mid)
			return binary_search(mid+1, end, target );
		return binary_search(begin, mid-1, target );

	}
	return false;
}
```

```c++
template<class T, class RndAccessIterator>
bool binary_search_iterative(RndAccessIterator begin, RndAccessIterator end, const T target){
	while(begin <= end){
		auto mid = begin + distance(begin, end)/2;
		if(target == *mid)
			return true;
		if(target > *mid)
			begin = mid+1;
		else
			end = mid-1;
	}
	return false;
```

## Binary search is implemented in c++ STL in at least the following methods;
- `lower_bound(target)`: returns the smallest element that not evaluates strictly smaller than target. I.e. it return the smallest element equal of greater of target.
`lower_bound(20)` on the following vector: `{1,2,3,10,20,20,21,22,23,24}` returns a iterator to the element at index `4` (first occurrence of `20`)
`lower_bound(20)` on the following vector: `{1,2,3,10,15,17,22,22,23,24}` returns a iterator to the element at index `6` (first occurrence of `22` which is the first element equal or larger than `20`)
- `upper_bound(target)` return the largest element that evaluate strictly greater to `target`. If such element does not exists it returns end();
`upper_bound(20)` on the following vector: `{1,2,3,10,20,20,21,22,23,24}` returns a iterator to the element at index `6` (first occurrence of `21`)
`upper_bound(20)` on the following vector: `{1,2,3,10,15,17,20,22,22,23,24}` returns a iterator to the element at index `7` (first occurrence of the smallest element  greater than `20` i.e. `22` )
- `equal_range(target)` returns a pair of iterators that identify a subrange containing element all equal to target
`equal_range(20)` on the following vector: `{1,2,3,10,20,20,20,21,22,23,24}` returns a iterator to the element at index `[4,7)`


Binary search can be applied in all the scenario where we have a predicate `p` on a seach space s.t. `p(x)` is true for `x > x_k` i.e. the search space is divided in two by the predicate `p`. 
`p(x_i) => false`  for all `i < k` and `p(x_j) => true `for all `i >= k`.
We can always find `k` by applying binary search, i.e. the smallest element s.t. `p` is `true`.

## How to craft a binary search solution to a problem
First we need to find a suitable predicate `p` that satisfy the condition stated above. Then we need to apply one of the following two algorithm:
1. Find the first occurrence of p true
2. find the last occurrence of `p` false

For example. Given a sorted array `A`, find the index of the first occurrence of a number greater than our target in `A`. Our predicate can be: is `A[x]` greater of equal than `target`?
It is easy to see that `p(A[x])=false` for all `A[x] < target` and true for the rest of them.
The predicate applied to the following array `A={1,2,3,4,5,6,7,8,9}` would look as follows (target = 3): `P(A) = {0,0,1,1,1,1,1,1,1}`
Now we can apply the algorithm `1` to return the first element where the predicate is true.

## Algorithm 1
The idea is that `[begin, end)`, always contains our answer.  We should always maintain this invariant
```c++
Iterator binary_search_1(const Iterator begin, const Iterator end, const Predicate p){
	while(begin < end){
		auto mid = begin + ceil(distance(begin, end)/2); //round up
		if( P(mid) )
			end = mid;
		else 
			begin = mid+1;
	}
	//if(!p(begin)) cout<<"the whole range is false";
	return begin;
}
```
binary_search_1 return the first element s.t. Predicate p is true;

## Algorithm 2
The idea is that `[begin, end]`, always contains our answer.  We should always maintain this invariant
```c++
Iterator binary_search_2(const Iterator begin, const Iterator end, const Predicate p){
	while(begin < end){
		auto mid = begin + ceil(distance(begin, end)/2); //round up
		if( !P(mid) )
			end = mid-1;
		else 
			begin = mid;
	}
	//if(!p(begin)) cout<<"the whole range is false";
	return begin;
}
```
binary_search_2 return the last element s.t. Predicate p is false;

```c++
int main(){
	int target = 16;
	auto p = [](const T v){ return v >= target;}
	vector<int> V = {1,2,7,9,15,19,22,26,29,33};
	auto first_true = binary_search_1(begin(V), end(V) , p); //return Iterator pointing at 19
	auto last_false = binary_search_2(begin(V), end(V) , p); //return Iterator pointing at 15
}
```

# FairWorkload, which was the division 1 level 2 problem in SRM 169
Given an array A and a number N, partition the array A in N sequential chunks s.t. the maximum sum among all chunks is minimized.
We are asked to find an assignment s.t. minimizes the maximum sum among all chunks.

# Solution
It is solvable by binary search reasoning in the following way:

For a given `MAX` we can calculate the minimum number of chunks needed s.t. each chunck will not have more than `MAX` elements.
Note that as MAX increases, the number of chunks required decreases  because with each chunk we can accomodate more and more elements.
What the problem is asking us is: **what is the minimum MAX that a chunk can have and not using more than N chunks?**
Or put in another word is: can we create N chunks s.t. each of them will have sum less or equal to MAX

- What is the  seach space? The search space is an interval [s,e] of possible MAX values (i.e. max size of a chunk)
- What is the predicate? Can we create N chunks s.t. each of them have sum less or equal to MAX?

Note that the predicate if the predicate is `false` for `x` then it is `false` for all the `y < x`  and if the predicate is true for `z` then it is `true` for all the `y > z`. Setting our `MAX` higher is translates to relaxing the problem

What we can do, we can binary search the first value MAX s.t. the predicate is true!


```c++
//compute the smallest number of chunks needed s.t. each chunk is less than val
int evaluate(const int val , const vector<int>& N){
	int ans = 1;
	int sum = 0;
	for(int i = 0 ; i < N.size() ; i++)
	{
		if(sum + N[i] <= val){
			sum+= N[i];
		}
		else{
			sum=N[i];
			ans++;
		}
	}
}


void solve(){
	int lo = *max_element(begin(N), end(N));
	int hi = accumulate(begin(N), end(N));
	while(lo < hi){
		auto mid = lo + ceil((hi-lo)/2);
		if(evaulate(mid,N) <= workers)
			hi = mid;
		else
			low = mid+1;
	}
	cout<<lo<<endl;
}

```





#Implement a binary tree and a heap.





















































 I have recently learned about the new open vacancy related to the positions of C++ Research Engineer
and I am writing to state my interest on it. 
I am a software engineer at ASML in the Netherlands working on the next generation of extreme ultraviolet photolithography systems.
My Ph.D. programme has been mainly focused on scientific computation for massively parallel architectures for macroscopic natural phenomena
simulation. I also have an MSc in Computer Science (cum laude) from the University of Calabria,
focused on parallel computing, theoretical computer science, AI and answer set programming.
As s Ph.D. graduate I wish to work for a international company, developing advanced and
innovative products. After having challenged myself in different multicultural and professional
backgrounds, by working on my MSc Thesis (for 8 months) at University of Plymouth, and
by being accepted as Research Visiting student at University of Edinburgh (10 months) and
at University of Warwick (3 months), I am keen to work for a global, international-minded,
company and be part of a proactive, dynamic and research-driven environment working on
developing cutting-edge technology. I feel naturally driven to this type of work. In addition
to scientific computing, during my studies, I have also been interested in how the exascale
simulation data could be interactively visualized and analyzed. This has been deepened with
an enriching experience at the University of Edinburgh on the VELaSSCO EU project. My
willingness and curiosity to learn, with my determination to pursue an objective with resilience,
have always driven me through my studies and especially my Ph.D., where I have also learned
to take ownership of my tasks while working and communicating effectively in a project-team
with international partners. This mindset and the different topics I have focused on so far, have
given me the right adaptability and multidisciplinary background to fit in a company with an
international outlook.
What attracts my of to CloudNC is the possibility to work with top-class scientists and engineers to
develop, design and build smarter CNC machines that are fundamental in many production industries.
Working on such complex and computational heavy problem is what excites me about this opening,
and feels like it is a a natural consequence of pursuing a Ph.D. in the field of
High-Performance modeling and simulation. The direct impact of the role on the features and overall quality of the software running the machine would push my enthusiasm more every day. 
During the last 5 years, I have worked in interdisciplinary and international teams of
mathematicians, physicists, experts in modeling and computer scientists. I have already achieved
good academic results by producing HPC software from mathematical and/or prototypical
specifications of solutions and consequently, I am also familiar with modeling methodologies
and tools such as Matlab. As an HPC programmer and a Ph.D. I combine strong theory with
extensive experience in, among others, C/C++, Unix, build tools (Make, Cmake), versioning
systems (git) and GPGPU (CUDA, OpenCL, OpenMP4).
I believe that I can be a great fit for the position and for the team and I would be very grateful
for the opportunity of an interview, where we can discuss about the job requirements and my
ability to meet them.
Yours faithfully,
Davide Spataro