#include<iostream>
using namespace std;

class Nothing{
    public:
    string name, email, password;
    void signup(){
        cout<<"Name: ";
        getline(cin,name);
        cout<<"Email: ";
        getline(cin,email);
        cout<<"Passord: ";
        getline(cin,password);

        
    }
}obj;

int main(){
    cout<<endl;
    cout<<"----------------Welcome to Nothing----------------"<<endl<<endl;
    cout<<"Press 1 to SignUp."<<endl;
    cout<<"Press 2 to Login."<<endl;
    cout<<"Press 5 to Forget Password."<<endl;
    cout<<"Press 4 to Exit."<<endl;

    int choice;
    cin>>choice;

    switch (choice)
    {
    case 1: 
        break;
    case 2:
        break;
    case 3:
        break;
    case 4: return 0;
        break;
    default: cout<<"Invalid choice.";
        break;
    }
}