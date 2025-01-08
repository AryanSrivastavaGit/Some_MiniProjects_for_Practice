#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Library{
    string showbook, addbook, takebook, adminid, adminpassword;
    int take_book=0;
    fstream file;
    public:
    void list();
    void take();
    void add();
}obj;

void Library :: list(){
    cout<<"-----------Below is List of available books-----------"<<endl;
    file.open("LibraryData.txt", ios::in);
    int i=1;
    while(getline(file, showbook)){
        cout<<i<<". "<<showbook<<endl;
        i++;
    }
    file.close();
}
void Library :: take(){
    list();
    cout<<endl;
    cout<<"Enter book number by list: ";
    cin>>take_book;
    cin.ignore();
    file.open("LibraryData.txt", ios::in | ios::out);
    int i=1;
    while(getline(file, takebook)){
        if(i==take_book){
            cout<<"Thanks for taking '"<<takebook<<"'. Please return it to Library Staff after reading.";
            break;
        }
        i++;
    }
    file.close();
}
void Library :: add(){
    cout<<"Enter your given id: ";
    getline(cin, adminid);
    cout<<"Enter password: ";
    getline(cin, adminpassword);
    if(adminid=="Aryan" && adminpassword=="789"){
        cout<<"Add Book: ";
        getline(cin, addbook);
        file.open("LibraryData.txt", ios::out | ios::app);
        file<<addbook<<endl;
    }else{
        cout<<"Wrong credentials."<<endl;
    }
}

int main(){
    cout<<endl;
    cout<<"----------------------Welcome to Library----------------------"<<endl<<endl;
    cout<<"Press 1 - Show All Available Books"<<endl;
    cout<<"Press 2 - To Take Books"<<endl;
    cout<<"Press 3 - To Add Books (Admin Only)"<<endl;
    cout<<"Press 4 - Exit"<<endl<<endl;

    cout<<"Enter your choice: ";
    char n;
    cin>>n;
    cin.ignore();

    switch (n)
    {
    case '1': obj.list();
        break;
    case '2': obj.take();
        break;
    case '3': obj.add();
        break;
    case '4': return 0;
        break;
    default: "Invalid Input";
        break;
    }
}