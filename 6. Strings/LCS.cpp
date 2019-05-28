#include <bits/stdc++.h>

using namespace std;
int lcs(string X, string Y, int m, int n) 
{ 
    int L[m + 1][n + 1]; 
    int i, j; 
    for (i = 0; i <= m; i++) { 
        for (j = 0; j <= n; j++) { 
            if (i == 0 || j == 0) 
                L[i][j] = 0; 
  
            else if (X[i - 1] == Y[j - 1]) 
                L[i][j] = L[i - 1][j - 1] + 1; 
  
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
        } 
    } 
    return L[m][n]; 
} 
// Complete the commonChild function below.
int commonChild(string &s1, string &s2) {
    int m = s1.size();
    int n = s2.size();

    return lcs(s1,s2,m,n);
}

int main()
{
    ifstream inf;
    inf.open("sample.txt");
    string s1;
    getline(inf, s1);

    string s2;
    getline(inf, s2);

    int result = commonChild(s1, s2);

    cout << result << "\n";

    inf.close();
    getline(cin,s1);
    return 0;
}
