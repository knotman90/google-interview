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
Complexity is O(n) time and O(n) space;

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


bool isRotation(const string& s1 , const string & s2){
	return isSubstring(s1, s2+s2);
}