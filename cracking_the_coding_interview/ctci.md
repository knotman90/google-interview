# Cracking The Coding Interview


## Preparation habits

1.  Smetti di scrivere codice al computer. **Devi abituarti a scrivere codice CORRETTO alla lavagna** Usa il computer solo dopo per testare la tua soluzione. 
2. Le domende introduttive sono molto importati perchè possono migliorare la percezione iniziale che  l'interviewer ha di noi. Se inizia a pensare che siamo bravi all'inizio, continuera a farlo. **La prima impressione conta più di tutto il resto**.
3. Fai molte interview di prova **vere e proprie**. Bisogna simulare ogni aspetto del processo, per abituarsi allo stress ed alla pressione psicologica alla quale saremo sottoposti.
4. Per ogni problema che risolvi o ogni algoritmo che impari, non impararlo a memoria, piuttosto prova ad analizzarlo e a capire che approccio è stato utilizzato da chi ha risolto il problema.
5. Risolvi i problemi ad alta voce provando a spiegare tutto il tuo processo di ragionamento. Questo aiuta chi ti ascolta a capire come ragioni, e allenandoti, migliora anche le tue capacità analitiche e di concentrazione.
6. I problemi che vengono dati ai candidati sono solitamente **difficili** e bisogna tenere a mente che non bisogna avere paura o essere intimiditi da questo. 


## Resume 
1. Il curriculum dovrebbe essere lungo soltmenta una pagina. Fai in modo che le cose che sai meglio stiano prima. Questo dimostra che hai un forte senso di come le cose vanno messe in ordine di priorità.


#Come studiare e preparare le domande tecniche

1. Leggi in modo accurato il problema, **senza fretta**. Quando hai finito, fai un riassunto ad alta voce del problema. Chiediamo conferma che effettivamente abbiamo capito il problema per bene.
2. **Fai domande**. Fai in modo che tu abbia capito bene il problema.
	- Per esempio ci viene sottoposto il problema di ordinare una lista.
	Se chiediamo per esempio di che tipo di dati la lista è composta, se è un array o una lista, e se per esempio i numeri all'interno sono limitati da un range preciso (supponiamo 1, 100) **allora** possiamo usare bucket sort invece dei classici algoritmi che usano compare-swap e produrre una soluzione **MIGLIORE**.
3. Schematizza un idea di algoritmo risolutivo su carta ed analizza il costo della soluzione in termini di spazio e tempo. 
	- Pensa a tutti i possibili corner cases. **La soluzione prima che veloce deve essere corretta**.
	- Testa il tuo codice su carta direttamente.
	- Puoi migliorare la soluzione se consideri il trade-off tempo e spazio?
4. Scrivi la soluzione interamente su carta, oppure al computer su un editor senza assolutamente alcun aiuto tipo 
	-  compilatore
	- syntax highlighting
5. Una volta che sei abbastanza convinto che il codice funzioni, scrivilo e compilalo al computer per verificare che il codice compili e funzioni.
	- Cerca di scrivere e ricordare dove hai sbagliato (hai fatto errori di sintassi?).
6. Chiedi a chi ti fa l'interview di darti feedback onesti sulla tua performance.

	
#TO-DO
## Per ognuno dei seguenti argomenti fai in modo che tu abbia una conoscenza buona del loro funzionamento, del loro utilizzo, delle loro API e della loro implementazione. 
1. Strutture Dati
	- Linked Lists 
2. Algoritmi
3. Concetti Generali

## Potenze di due
### Memorizza questa tabella, 
### Stampala per le interview online


| 2^n | Value | Approximation in base 10 | Memory |
|-------|---------|-----------------------------------|------------|
| 2^1 |  2 |  |  1b |
| 2^2 |  4 |  |   2b |
| 2^3 |  8 |  |  1B, 8b |
| 2^4 |  16 |  | 
| 2^5 |  32 |  |   |
| 2^6 |  64 |  |   |
| 2^7 |  128 |  |   |
| 2^8 |  256 |  |   |
| 2^9 |  512 |  |   |
| 2^10 |  1024 |  THOUSAND |  1 kB |
| 2^11 |  2048 |  | 2kB  |
| 2^12 |  4096 |  |   |
| 2^13 |  8192 |  |  8kB |
| 2^14 |  16384 |  |  16kB | 
| 2^15 |  32768 |  | 32kB |
| 2^16 |  65536 |  |  64kB |
| 2^20 |  1048576 | MILLION |  1MB |
| 2^30 |  1073741824 | BILLION | 1 GB |
| 2^40 |  1099511627776 | 1000 BILLIONS | 1 TB |




#Cosa da tenere a mente quando si giudica un candidato
1. Chiede domande per risolvere le ambiguità che possono esserci nel problema?
2. Ragiona a voce alta?
3. Inizia con lo scrivere pseudocodice?
4. Scrive codice troppo velocemtne?
5. Test il codice?
6. Effettua un analizi di complessità.
7. Tradeoff memoria/tempo
8. Corner cases.
9. Si chiede come eventualmente questo codice possa essere testato?
10. Prova a fare domande se bloccato.
 


# 5 approcci per risolvere un problema
#1 Deriva una regola generale a partire da qualche esempio
Per esempio immagina di dover risolvere il problema: Qual è l'angolo tra le lancette dell'ora e dei minuti in un orologio?




#Interview Questions

## Check if a string contains only unique chars.

### Questions
- Does the string contain only a-z?

##### Brute force

```c++
bool unique_char(const string& str)
{
	for(unsigned  i = 0 ; i < str.size() ; ++i){
		for(unsigned  j = i+1 ; j < str.size() ; ++j)
		{
			if( str[i] == str[j])
				return false;
		}
		return true;
}
```
This has complexity O(N^2)


##### Sorting
If the string is sorted, then it is only necessary to check for subsequent chars, as equal chars would appear in sequence.


```c++
bool unique_char_sorting( string str) //make a copy so you do not modfy the original str
{
	sort(begin(str), end(str));
	for(auto a = begin(str), b = a+1 ; b != end(str) ; ++a, ++b){
		if(*a == *b)
			return false;
	}
	return true;
}
```

##### Using reference counting
Assuming that the alphabet is not greater than the ascii set (256 elements) then we can always return true if the string is longer or if we have counted at least two times the same char. We keep track of the chars in an array the size of the alphabet.

```c++
bool unique_char_ref_counting( const string& str)
{
	array<bool, 256> counters;
	fill(begin(counter) , end(counter), false);

	for( const auto c : str)
	{	
		const unsigned idx = c-'a';
		if( counter[idx] )
			return false;
		counter[idx] = true;

	}
	return true;
}
```
Complexity is O(n) time and O(1) space;

##### Using reference counting on smaller alphabet
if we know for sure that our alphabet is only composed of letters then we can keep track of the counting in the bit of a single integer.

```c++
bool unique_char_ref_improved(const string& str)
{
	unsigned counters = 0;
	for( const auto c : str)
	{	
		const unsigned idx = c-'a';
		if( counters & (1 << idx) )
			return false;

		counters |= (1 << idx);
	}
	return true;
}
```

##### Using reference counting on smaller alphabet CASE INSENSITIVE
If we add the requirement that the check should be case insensitive then we could fix checking wether the char is lower than 'a' meaning is it an upper case letter (upper case letter come before)

```c++
bool unique_char_ref_improved_case_insensitive(const string& str)
{
	unsigned counters = 0;
	for( const auto c : str)
	{	
		const unsigned idx = c < 'a' ? c -'A' : c -'a';
		if( counters & (1 << idx) )
			return false;

		counters |= (1 << idx);
	}
	return true;
}
```



## Reverse a null terminated string 

### Questions

Easy approach would be to allocate space for a new string and then fill the new string with characters from the end toward the beginning of the input string and then copy the new string into the old one. This would incur in a space cost that is unnecessary.

```c
void reverse1( char * str)
{
	const unsigned size = strlen(str);
	char* rev = (char*)malloc(sizeof(char)*size+1);
	for(int i = size - 1 , idx = 0; i >= 0 ; i--, idx++)
	   rev[idx] = str[i];
    rev[size]='\0';

    for(unsigned i = 0 ; i < size ; i++)
		str[i]=rev[i];
    
	free(rev);
}

```

We can do better by reversing in-place
```c
void reverse2( char * const str)
{
	const unsigned length = strlen(str);
	for(int i = length - 1 , idx = 0; i > idx ; i--, idx++){
	   char c = str[idx];
	   str[idx] = str[i];
	   str[i] = c;
	}
}
```

we can avoid using the third variable by using xor operation three times
```c
void reverseXOR( char * const str)
{
	const unsigned length = strlen(str);
	for(int i = length - 1 , idx = 0; i > idx ; i--, idx++){
	   str[idx]^= str[i];
	   str[i]  ^= str[idx];
	   str[idx]^= str[i];
	}
}
```
## Given two string write a function that returns true if one string is a permutation of the other, false otherwise

### Questions
First notice that the two string are required to have the same length.

#### Sorting the two string
One approach is to sort the two string and then check if they are equal. This would cost O(n1 log n1) + O(n2 log n2) where n1 and n2 are the length of the two strings.

```c++
bool is_permutation(const string& str1 , const string& str2)
{
	if(str1.size() != str2.size())
		return false;
	
	sort(begin(str1), end(str1));
	sort(begin(str2), end(str2));

	return str1==str2;
}
```
#### We can do better if we use count the occurrences of the chars in the two strings. If all the occurrences are equal then the two strings are permutations of each other

```c++
bool is_permutation(const string& str1 , const string& str2)
{
	const int size = str1.size();
	if(size != str2.size())
		return false;

	constexpr unsigned ALPH_SIZE = 256;
	array<unsigned, ALPH_SIZE> counters;
	fill(begin(counter), end(counters) , 0);

	for( int i = 0 ; i < size ; i++){
		++counters[str1[i]-'a'];
		--counters[str2[i]-'a'];
	}

	const bool fail = any_of(begin(counters) , end(counters) , 
		[](const auto c){ return c != 0;}
		);

		return !fail;
}
```

Complexity is O(n) time and O(1) space;


## Given a string s,t transform it s.t. each char in it is substituted by t 

### Questions

Approach is to, first count the number of occurrences of spaces. 
Then resize the current string in order to accomodate the occurrences of t. 
Then use two pointer strategy . One pointer point to the last valid char of s (before resizing) and the other to the last posizion o s. Non space character are copied from the first pointer to the second, while spaces are substituted by t.

```c++
string solve(string s, const string t){
	const unsigned sizet = t.size();
	const unsigned old_size = s.size();
	const unsigned spaces = count_if(begin(s), end(s), 
		[](const char c){
		return isspace(c);}
		);
	
	const unsigned new_size = old_size - spaces + sizet*spaces; //new_size > s.size()
	s.resize(new_size);

	auto p2 = s.end() -1;
	for(int i = old_size-1 ; i  >= 0  ; --i){
		if(!isspace(s[i]))
		{
			*p2 = s[i];
			p2--;
		}
		else
		{
			copy(begin(t), end(t) , p2-sizet+1);
			p2-=sizet;
		}
	}
return s;
}

```


## Create a method that compress a string s, s.t. each subsequent k occurrences of the char c is replaced by `ck`. 
Fro example `aaabccjjja` would become `a3b1c2j3a1`. If the compressed string is the same size or larger then return the original string.

### Questions


```c++
#include <sstream>
#include <string>

std::string compress(const std::string& s){
	std::stringstream  ss;
	unsigned count = 1;
	for(unsigned i = 0 ; i < s.size()-1 ; ++i, count++)
	{
		if(s[i] != s[i+1])
		{
			ss<<s[i]<<count;
			count = 0;
		}
	}
	ss<<s.back()<<count;
	return ss.str().size() < s.size() ? ss.str() : s;
}
```

### Follow-up question: Create a method that decompress the string compressed with the method above. If the input is not valid return the original string
```c++
std::string decompress(const std::string& s)
{
	std::stringstream ss;
	for (unsigned i = 0; i < s.size() ; i++)
	{      
        const int cp = i;
        int num = 0;
        for(int p =1 ; i < s.size() && s[i+1] >= '1' && s[i+1] <= '9' ; ++i , p*=10)
            num+= (s[i+1] - '0')*p;
                   
        if(num==0)
            return s;
        
		for( int j = num; j > 0 ; j--)
			ss<<s[cp];

	}
	return ss.str();
}

```



## Write a function s.t. given a matrix MxN if one of its cell (l,k) is zero, then the whole row and column is set to zero.

### Questions
- How big is the matrix?
- Should we only optimize for space?
- What is the range of numbers stored in the matrix? Only positive?

The naive approach would be to loop over the matrix and whenever we found zero cell, simply iterator over the corrensponding row and column and set them to zero. This would cost more than necessary when more than one cell implies the zeroing of a row or a column. In the worst case, when the matrix is full of zeros, the cost if MxNx(M+N) = M^2N+N^2M, (assuming M = O(N) the complexity is cubic) because for each cell we need to loop over an entire row and an entire column.

Another approach could be to iterator over the matrix and for each zero cell (l,m) store l in a set containing all the columnn to be zeroed and m into another set of all the column to be zeroed. Then we would, in the worst case only iterate through all row and columns once.
The complexity is MxNx(log(M)+log(N)), and assuming M = O(N) it would be N^2log(N);
We could remove the log(N) factor using an unordere map, but during the zeroing of the matrix we could potentially lose cache advantage because we would zero rows and columns potentially far from each other.


Noter that is M and N are relatively small and we could afford to use more space, then we could allocate two arrays of the size of the rows and columns, respectively and use them as flags. Alternatively, is their size is smaller than 32 or 64 we could use the bit of an `int` or a `long` as flags.
```c++
void zeroMatrix(vector<vector<int>>& mat){
	set<int> C,R;
	for(int i = 0 ; i < mat.size() ; i++  )
		for( int j = 0 ; j < mat[i].size() ; j++)
		{
			if(mat[i][j] == 0){
				R.insert(i);
				C.insert(j);
			}
		}

	for(const auto r : R)
		setRow(mat, r, 0);
	
	for(const auto c : C)
		setColumn(mat, c, 0);
}
```

## Follow up question
How about doing without using any extra memory at all?
If the there is at least a number that will never appear in the matrix then  we can use the last row  and the last column to mark the cells that need to be zeroed.
Imagine the matrix can only hold positive numbers.

```c++
void zeroMatrix(vector<vector<int>>& mat){
	const int lastrow = mat.size()-1;
	const int lastcol = mat[0].size()-1;
	for(int i = 0 ; i < mat.size() ; i++  )
		for( int j = 0 ; j < mat[i].size() ; j++)
		{
			if(mat[i][j] == 0){
				mat[i][lastcol] = -1;
				mat[lastrow][j] = -1;
			}
		}

	for(int i = 0 ; i <= lastrow ; i++  )
		if(mat[i][lastcol] < 0)
			setRow(mat, i, 0);
	
	for( int j = 0 ; j <=lastcol ; j++)
		if(mat[lastrow][j] < 0 )
			setColumn(mat, j , 0);
}
```


## Using only one call to substring, determine whether the string s2 is a rotation of the string s1

### Questions

This problem is trivial once you notice that a the string  "modavideciaomichi" concatenated with itself always contains the test string s1 if and only if it is substring of it.

given s1 = ciamichiamodavide , then s2 = modavideciaomichi then s2s2 = modavideciaomichimodavideciaomichi contains ciaomichiamodavide.

```c++
bool isRotation(const string& s1 , const string & s2){
	return isSubstring(s1, s2+s2);
}
```

## Given a string `s`, print the first non-repeated char 

### Questions
- What is such char does not exist? assume returning `0` in this case.

#### Approch 1 - Brute force
One approach consist in, for each character starting from the beginning of `s` to check whether it is repeated in the following part of the string.


```c++
char first_non_repeated_brute_force(const string&s)
{
	for(char c = 'a' ; c <='z' ; ++c)
	{
		const auto it = find_if(begin(s) , end(s), [&c](const auto cc){return cc==c || toupper(c)==cc;});
		if(it == end(s) )
			return c;
	}
	return 0;
}

```
This solution has complexity of `O(26n)=O(n)`.


#### Approch 2 - Brute force
We can make it O(n+26) by storing a bit for each of the 26 char, and setting it to true if we have encountered it in the string.


```c++
char first_non_repeated_improved(const string&s)
{
	array<bool, 26> C;
	fill(begin(C), end(C), false);
	for(const char c : s)
	{
		const unsigned idx = tolower(c)-'a';
		C[idx] = true;
	}
	for (int i = 0; i < C.size(); ++i)
	{
		if(!C[i])
			return 'a'+i;
	}
	return 0;
}

```

## Reverse a string using recursion
### Questions


This is easy once you realise that you can swap each char from the first half with every char of the last half. Start swapping `0` and `s.size()-1` till the two values overlap (we have reached the half of the string).

```c++
void reverse_helper(string&, unsigned  , unsigned );

void reserve(string& s)
{
	return reverse_helper(s, 0 , s.size()-1);
}
void reverse_helper(string &s, const unsigned l , const unsigned r)
{
	if(l>=r)
		return;
	swap(s[l],s[r]);
	reverse_helper(s, l+1 , r-1 );
}
```

Another approach is to use ostringstream to build a new string.
The recursive call at index `i` will first reverse the rest of the string and then will append char at position `i`.

```c++
void reserve_ss(string& s)
{
	ostringstream oss;
	reverse_helper_ss(s, 0 , oss);
	s = oss.str();
}

void reverse_helper_ss(string &, const unsigned  , ostringstream& );


void reverse_helper_ss(string &s, const unsigned l , ostringstream& os)
{
	if(l>=s.size())
		return;

	reverse_helper_ss(s, l+1 , os);
	os<<s[l];
}
```



# Questions on Linked List

First we provide a simple implementation of Linked List that we will use thoughout the rest of the chapter.

```c++
template<class T>

```



# Implement a doubly linked list using only a pointer `both` which is the `xor` of `next` and `prev`
Make sure that the Linked List provides at least two methods
- `add` , which add a node at the end of the list
- `get` which return the n-th element of the list.


Note that:
-  `A XOR B XOR A = B`. 
- The `both` pointer is the XOR or prev and next. 
- Since head does not have any prev, `head.both=next` 
- and since tail does not have any next `tail.both=prev`.

The Node of a linked list is pretty standard and will contain a value element the payload of the node and a `both` pointer defined as `XOR(prev, next)`
```c++
template < class T >
  struct Node {
    Node * both;
    T value;
    Node(T el): value(el) {};
  };
```

The linked list contains two pointers: the head and the tail and an unsigned containing the length of the list.

The insert work as follows:
If the list is empty then by definition when we add a node N head and tail will both point to the same node. N.both will point to `nullptr` because it has no next and no prev.
If the list is not empty then we need to fix the current tail both pointer because after the addition the old tail will have a next element. So since tail.`both=prev`, and n is the new tail.next, all we have to do is to `XOR(tail.both, &T)`. 
T.both need also to be fixed. Since `n` is the new tail, we know that `n.both=prev`, and since n will be the new tail, `n.prev` is the current tail. So `T.both=tail`
Now all the both pointers are fix, and we need to update the tail `tail=n`.



`Find` work under the following idea: given `n.both=prev^next`, what we need in order to extract `next` fro `both` is `prev`. So while searching we will carry with use `prev`, and we can visit the `curr.both ^ prev = next` node if needed.

```c++
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

    T get(const unsigned idx) {
      return get_helper(idx, nullptr, head);
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

    T get_helper(const unsigned idx, Node <T> * prev, Node <T> * curr) {

      if (idx == 0)
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


So in order to do the traversal what we need to do is to retrieve the `next` point
```c++
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




# Write a function that taken a list, removes duplicates from it.

```c++
template<class T>
T remove_duplicates_brute_force(Node<T>* head , const unsigned k)
{
	while(head){
		head = head.next;
	}
}
```


# Implement an algorithm to find the kth to last element of a singly linked list.

Using two pointers. First move the first pointer k position ahead. Then start moving both pointers until the last pointer reached the end of the list. The element pointerd by the first pointer is the k to last element of the list.

```c++
template<class T>
T k_to_last(List<T>& list , const unsigned k)
{
	assert(k <= list.size());
	it1 = begin(list);
	it2 = begin(list);
	while(k--)
		++it1;
	while(it1 != end(list))
	{
		++it1;
		++it2;
	}
	return *it2;
}
```


# You are given a binary number `B`.  Your task is to output the value of the `k`th bit of the resulting number `B'` obtained after performing the following operation `n` times:

Each bit in `B` gets transformed as follows:
- `0`  becomes `01` 
- `1`  becomes `10`

Example
`B=1011` , `n=3`, `k=10 `
```bash
0. B=1011
1. B=10011010
2. B=1 0 0 1 1 0 1 0 0 1 1  0  0  1  0  1
idx= 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 
```
The correct answer is answer: `1`; If `k` is 5 then the correct answer is `0`.

#Question

First notice that after each iteration the string doubles its size.
After `n` iteration it will have size `|B|*2^n`.
There are two key idea that one need to consider in order to solve this problem:
1. Which is the digit in B that eventually determines the value of `k`th digit in `B'`?
2. Notice that after each iteration the string doubles and in particular that the second half is exactly the negation of the first half. 

- We can use fact `1` to determine the digit in `B` that generates our solution. Each digit generates a segment of length `2^n`, so our anser lies in the block generated by the `k/2^n` digit. We also know that within that block, the kth digit lies at location `k%(2^n)` (starting from the beginning of the block). This is important because in this way we know if the digit lies in the first or in the second half.
Now we use fact 2, which tells us that our answer can be searched in the subproblem of half of the size, and depending whether the digit lies in the first or the second half of the block return digit as it is or negate it.
The following code solve the problem. `S` is the original binary number `B` , `d=k / (1 << n)` and `k` is the location we are searching for at the current call. In the main `k` is initialised as `k % (1 << n)` i.e. the location within the generating block `d`.
```c++
bool solve(const vector<bool>& B, long k, int n, const int d) {
  if (n == 0) {
    return B[d];
  }
  if (k >= (1 << (n - 1))) {  // second
    return !solve(B, k - (1 << (n - 1)), n - 1, d);
  } else {  // first
    return solve(B, k, n - 1, d);
  }
}
```
If `k` lies in the first half we will simply return the answer for sub-problem of half the size. If it lies in the second half, then we translate `k` into the first half (by subtracting (2^n)/2 = 2^(n-1)) and negating the answer (fact 2 tells us to do so).
Once the string is of size 0, we know that we can return the digit `d` in `B`.



# Given an interval `[l,r]` and a integer `v` how many `l<=p<=r` are divisible by `v`?

First note that:
- If `l|v` then the problem is easy as there are  `1 + (l-r)/v` number of multiples of v in the interval. `l` is the first one and then you can have at most one every `v` spots.
- When `l` is not multiple of `v` then we need to find the first multiple of `v` larger than `l` i.e. `l' = ceil(l/v)*v`.
- Now if `l'` is bigger than `r` the answer is `0` otherwise is: `1 + (l'-r)/v`, the same for the easy case we discussed before.

Example:
`[24, 78], 7`. 24 is not multiple of `7` so we shall find the first multiple of 7 greater than `24`. `ceil(24/7) = 4` so `7*4 = 28`. Between 28 and 78 there are `1+(28-78)/7=8` multiple of seven i.e. `[28,35,42,49,56,63,70,77]`.





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



#Aggressive COWS SPOJ problem 
This is a problem  that can be solved by applying binary search in a non trivial way.
The problem stateing is the following:
There are `2<=C<=10e5` stalls located in a line at location `x_1, x_2, x_3,...,x_n`. We have to place `2<=C<=N` objects in the stall such that no stall contains more than `1` object. What is the maximum minimum distance at which two object can be placed?

## Solution


#Implement a binary tree and a heap.






