//replace "pi" with "3.14"

#include<iostream>
using namespace std;

void replacePi(char a[], int i){
    if(a[i] == '\0' or a[i+1]=='\0'){
        return ;
    }
    //look for pi for current location
    if(a[i] =='p' and a[i+1]=='i'){
        int j=i+2;
        //take j to the end of the array
        while(a[j] != '\0'){
            j++;
        }
        //shifting
        while(j>=i+2){
            a[j+2]=a[j];
            j--;
        }
        //replacement + rec call
        a[i] = '3';
        a[i+1] ='.';
        a[i+2] ='1';
        a[i+3] ='4';
        replacePi(a, i+4);
    }
    else{
        replacePi(a, i+1);
    }
    return;
}

int main(){
    char a[1000];
    cin>>a;
    replacePi(a,0);
    cout<<a;
}