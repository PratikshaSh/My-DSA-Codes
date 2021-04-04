#include <bits/stdc++.h>
using namespace std;


#define prime 101

long createHash(char *str, int end){
   long hash =0;
   for(int i=0; i<=end; i++){
       hash += str[i]*pow(prime,i);
   }
   return hash;
}
bool checkEqual(char str1[], int start1, int end1, char str2[], int start2, int end2){
   if(end1-start1 != end2-start2) return false;

   while(start1 <= end1 and start2 <= end2){
       if(str1[start1++] != str2[start2++])
       return false;
   }
   return true;
}

long recalHash(char* str, int oldIdx, int newIdx, long oldHash, int patLen){
  long newHash = oldHash - str[oldIdx];
  newHash = newHash/prime;
  newHash += str[newIdx]*(pow(prime,patLen-1));

  return newHash;
}
int search(char pat[], char txt[])
{
    
    int m = strlen(pat);
    int n  = strlen(txt);

    long patHash = createHash(pat,m-1);
    long txtHash = createHash(txt,m-1);

    for(int i=1; i<= n-m+1;i++){
        if(patHash == txtHash and checkEqual(txt,i-1,m+i-2,pat, 0, m-1)){
            // cout<< i-1<<endl;
            return i-1;
        }
        if(i<n-m+1){
            txtHash = recalHash(txt, i-1,i+m-1,txtHash,m);
        }
    }
    return -1;
}

/* Driver code */
int main()
{
	char txt[] = "DEEKS FOR GEEKS";
	char pat[] = "GEEK";
		
	int ans = search(pat, txt);
    cout<<ans;
	return 0;
}

