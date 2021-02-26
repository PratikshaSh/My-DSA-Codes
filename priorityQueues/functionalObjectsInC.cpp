#include<iostream>
#include<cstring>
using namespace std;

class Fun{
    public:
        void operator()(string s){
            cout<<"Having Fun with "<<s;
        }
};


int main(){
    Fun f;//Constructor
    f("C++");//Overloaded () operator = looks like function call wherre f is an object

    return 0;
}