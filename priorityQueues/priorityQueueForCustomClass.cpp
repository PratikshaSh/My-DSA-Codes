#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

class Fun{
    public:
        void operator()(string s){
            cout<<"Having Fun with "<<s;
        }
};

class Person{
    public:
    string name;
    int age;

    Person(string n, int a){
        name = n;
        age = a;
    }

    
};
class PersonCompare{// this class must have the () overloaded operator
    public:
        bool operator()(Person A, Person B){
            return A.age<B.age; 
        }

};


int main(){
    int n;
    cin>>n;

    priority_queue<Person, vector<Person>, PersonCompare> pq;//instead of comparator function pass the comparator class-------THIS IS HOW STL WORKS

    for(int i=0;i<n;i++){
        string name;
        int age;
        cin>>name>>age;
        Person p(name, age);
        pq.push(p);
    }
    int k=3;
    for(int i=0; i<k ; i++){
        Person p= pq.top();
        cout<<p.name<<" "<<p.age<<endl;
        pq.pop();
    }
    return 0;   
}