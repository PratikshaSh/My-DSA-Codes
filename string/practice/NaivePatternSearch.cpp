// C++ program for Naive Pattern
// Searching algorithm
#include <bits/stdc++.h>
using namespace std;

void search(char* pat, char* txt)
{
	int p = strlen(pat);
    int t = strlen(txt);

    for(int i=0;i<t-p;i++){
        int j;
        for(j=0; j< p; j++){
            if(txt[i + j] != pat[j])
            break;
        }
        if(j==p){
            cout<<"pat found at: "<<i<<endl;
        }
    }
}

// Driver Code
int main()
{
	char txt[] = "AABAACAADAABAAABAA";
	char pat[] = "AABA";
	search(pat, txt);
	return 0;
}

// This code is contributed
// by Akanksha Rai
