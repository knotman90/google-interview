#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

vector<string> split_string(string);

bool check_submatrix(vector<string>& G, vector<string>& P,int ii,int jj){
   const unsigned L = P.size();
   const unsigned M = P[0].size();
    for (int i = 0; i < L; i++) 
         for (int j = 0; j < M; j++) 
             if(G[ii+i][jj+j]!=P[i][j])
                 return false;
    return true;
}


string solve_brute_force(vector<string>& G, vector<string>& P){
  const unsigned L = G.size();
  const unsigned M = G[0].size();
  const unsigned l = P.size();
  const unsigned m = P[0].size();
  const string yes("YES");
  const string no("NO");
  
    for (int i = 0; i <= L-l; i++) 
         for (int j = 0; j <= M-m; j++) 
             if(check_submatrix(G,P,i,j))
              return yes;
    return no;
}



// Complete the gridSearch function below.
string gridSearch(vector<string>& G, vector<string>& P) {
  using Mat = vector<vector<int>>;
  const unsigned L = G.size();
  const unsigned M = G[0].size();
  const unsigned l = P.size();
  const unsigned m = P[0].size();
  const string yes("YES");
  const string no("NO");

  Mat prefix(L, vector<int>(M, 0));
  for (int i = 0; i < L; i++) {
    for (int j = 0; j < M; j++) {
      prefix[i][j] = G[i][j] - '0';
      if (j > 0) prefix[i][j] += prefix[i][j - 1];
    }
  }

  vector<int> prefix_P(l, 0);
  for (int i = 0; i < l; i++)
    for (int j = 0; j < m; j++) prefix_P[i] += P[i][j] - '0';
    
    for(int i = 0 ; i <= L-l ; i++){
       for(int j = m-1 ; j < M ; j++){
            bool good = true;
           for( int k = 0 ; good && k < l ; k++)
           {
               int sumrow = prefix[i+k][j];
               if( j != m-1)
                   sumrow-=prefix[i+k][j-m];
               
               if(sumrow!=prefix_P[k]){
                   good = false;
                   break;
               }
           }//k
           if(good && check_submatrix(G,P,i,j-m+1)){
               return yes;
           }
        } 
    }
    return no;
}

int main() {
  

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string RC_temp;
    getline(cin, RC_temp);

    vector<string> RC = split_string(RC_temp);

    int R = stoi(RC[0]);

    int C = stoi(RC[1]);

    vector<string> G(R);

    for (int i = 0; i < R; i++) {
      string G_item;
      getline(cin, G_item);

      G[i] = G_item;
    }

    string rc_temp;
    getline(cin, rc_temp);

    vector<string> rc = split_string(rc_temp);

    int r = stoi(rc[0]);

    int c = stoi(rc[1]);

    vector<string> P(r);

    for (int i = 0; i < r; i++) {
      string P_item;
      getline(cin, P_item);

      P[i] = P_item;
    }


    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    string result = gridSearch(G, P);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration_smart = duration_cast<microseconds>( t2 - t1 ).count();


    t1 = high_resolution_clock::now();
    string result_bf = solve_brute_force(G, P);
    t2 =  high_resolution_clock::now();

    auto duration_bf = duration_cast<microseconds>( t2 - t1 ).count();

    cout << "Brute Force: "<<duration_bf<<" ms"<<endl;
    cout << "Maybe Smart: "<<duration_smart<<" ms"<<endl;
    cout << "Correctness:"<<(result==result_bf)<<"="<<result<<endl;    
    
  }

  

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char &x, const char &y) { return x == y and x == ' '; });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
