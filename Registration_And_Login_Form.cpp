#include<iostream>
#include<fstream>
using namespace std;

class Nothing{
    string name, email, password, searchname, searchpassword, searchemail;
    fstream file;
    public:
    void signup();
    void login();
    void forgotpassword();
}obj;

void Nothing :: signup(){
    cout<<"Name: ";
    getline(cin,name);
    cout<<"Email: ";
    getline(cin,email);
    cout<<"Passord: ";
    getline(cin,password);
    file.open("LoginData.txt", ios::out | ios::app);
    file<<name<<'*'<<email<<'*'<<password<<endl;
    file.close();
}
void Nothing :: login(){
    bool tf = false;
    cout<<"Name: ";
    getline(cin, searchname);
    cout<<"Password: ";
    getline(cin, searchpassword);
    file.open("LoginData.txt", ios::in);
    while(!file.eof()){
        getline(file, name, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
        if(searchname==name){
            if(searchpassword==password){
                tf=true;
                cout<<"Welcome "<<name<<endl;
                cout<<email<<endl;
            }
        }
    }
    file.close();
    if(tf==false){
        cout<<"Wrong Username or Password.";
    }
}
void Nothing :: forgotpassword(){
    bool tf = false;
    cout<<"Enter Username: ";
    getline(cin, searchname);
    cout<<"Enter Email: ";
    getline(cin, searchemail);
    file.open("LoginData.txt", ios::in);
    while(!file.eof()){
        getline(file, name, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
        if(searchname==name){
            if(searchemail==email){
                tf=true;
                cout<<"Welcome "<<name<<endl;
                cout<<"Your password is "<<password;
            }
        }
    }
    if(tf==false){
        cout<<"Wrong Username or Email."<<endl;
    }
    file.close();
}
int main(){
    cout<<endl;
    cout<<"----------------Welcome to Nothing----------------"<<endl<<endl;
    cout<<"Press 1 for SignUp."<<endl;
    cout<<"Press 2 for Login."<<endl;
    cout<<"Press 3 for Forget Password."<<endl;
    cout<<"Press 4 to Exit."<<endl<<endl;

    char choice;
    cout<<"Your choice: ";
    cin>>choice;
    cin.ignore();

    switch (choice)
    {
    case '1': obj.signup();
        break;
    case '2': obj.login();
        break;
    case '3': obj.forgotpassword();
        break;
    case '4': return 0;
        break;
    default: cout<<"Invalid choice.";
    }
}
