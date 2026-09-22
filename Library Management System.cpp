#include <iostream>
#include<string>
#include <algorithm>
#include<vector>
using namespace std;
class Book
{
public:
    int ID;
    string title;
    string author;
     int c;
    Book(int a,string t,string o,int f){
       ID=a;
        title=t;
        author=o;
        c=f;
    }
        
    ~Book(){};
};
class User 
{
public:
    int IDU;
    string Name;
    vector<int>borrowbookID;
    User (int t,string s){
        IDU=t;
        Name =s;
    }
    ~User(){};
};
 class LibrarySystem
  {
 private:
 vector<User>U;
 vector<Book>B;
 public:
    LibrarySystem(){};
    void AddBook(const Book& book){
       B.push_back(book);
       cout<<"Done"<<"\n";
    }
    void AddUser(const User& user){
        U.push_back(user);
        cout<<"Done"<<"\n";
    }
    bool searchkBook(string n){
        bool found=false;
        for(const auto& book:B){
            if(book.title==n){
                 cout<<"The Book ID : "<<book.ID<<"\n";
                 cout<<"Number of Book Avaliable : "<<book.c<<"\n";
                found=true;
                return true;
            }
        }
        if(!found){
            cout<<"Is Not Found"<<"\n";
            return false;
        }
    }
    void borrowbook(int userID,int bookID){
        User* userptr=nullptr;
        Book* bookptr=nullptr;
        for(auto& b:B){
            if(b.ID==bookID){bookptr=&b;break;}
        }
        for(auto& u:U){
            if(u.IDU==userID){userptr=&u;break;}
        }
        if(userptr && bookptr){
            if(bookptr->c>0){
            bookptr->c--;
            userptr->borrowbookID.push_back(bookID);
            cout<<"Done "<<"\n";}
        }
        else{
            cout<<"fail process "<<"\n";
        }
    }
    void ReturnBook(int bookID,int userID){
        User* userptr=nullptr;
        Book* bookptr=nullptr;
        for(auto& b:B){
            if(b.ID==bookID){bookptr=&b;break;}
        }
         for(auto& ub:U){
            if(ub.IDU==userID){userptr=&ub;break;}
        }
        if(userptr && bookptr){
            bool f=false;
            for(auto it=userptr->borrowbookID.begin();it != userptr->borrowbookID.end();++it){
                if(*it==bookID){
                    bookptr->c++;
                    userptr->borrowbookID.erase(it);
                    cout<<"Done"<<"\n";
                    f=true;
                    break;
                }
            }
            if(!f)
            cout<<"The user didn't borrow this book"<<endl;
        }
        else{
               cout<<"Wrong ID"<<"\n"; 
            }
    }
    void printreport(){
        cout<<"All Book in a library : "<<"\n";
        for (const auto& book:B){
            cout<<"ID : "<<book.ID<<"\t"<<"Title :"<<book.title<<"\t"<<"Author's Name : "<<book.author<<"\t"<<"Number of avaliable from this book : "<<book.c<<"\n";
        }
        cout<<"________________"<<"\n";
        cout<<"All Users : "<<"\n";
        for (const auto& user:U)
        {
            cout<<"User's ID : "<<user.IDU<<"\t"<<"User's Name : "<<user.Name<<"\n";
        }
        cout<<endl;
        
    }
    void borrowbookuser(int userid){
        User* userptr=nullptr;
        for (auto& u:U){
           if(u.IDU==userid){userptr=&u;break;}
        
        }
           if(userptr==nullptr){
           cout<<"User Not Found"<<"\n";
           return;
       }
           
        for(const auto& book:userptr->borrowbookID){
            cout<<"Book's ID : "<<book<<"\n";
        }
        
        
        

    }
    ~LibrarySystem(){};
 };

int main (){
    LibrarySystem a;
    
   cout<<"Welcome to Library System"<<"\n";
    cout<<"__________________________"<<"\n";
    cout<<"1_Open The menu"<<"\n";
    cout<<"2-Exit"<<"\n";
    int choice;
    cout<<"Enter your choice : ";
    cin>>choice;
    if(choice==2){
        cout<<"Good Bye"<<"\n";
        return 0;
    }
    if(choice!=1 && choice!=2){
        cout<<"Invalid choice"<<"\n";
        return 0;
    }if(choice==1){
    int y=0;
    while(y!=8){
        cout<<"**__________________________**"<<"\n";
         cout<<"1-Add Book"<<"\n";
    cout<<"2-Add User"<<"\n";
    cout<<"3-Search Book"<<"\n";
    cout<<"4-Borrow Book"<<"\n";
    cout<<"5-Return Book"<<"\n";
    cout<<"6-Print Report"<<"\n";
    cout<<"7-borrowed Book by User ID"<<"\n";
    cout<<"8-Exit"<<"\n";
        cout<<"Enter your choice : ";
        cin>>y;
        switch(y){
            case 1:{
                int id;
                string Title,Author;
                int count;
                cout<<"Enter Book ID : ";
                cin>>id;
                cout<<"Enter Book Title : ";
                cin>>Title;
                cout<<"Enter Book Author : ";
                cin>>Author;
                cout<<"Enter Number of Avaliable Books : ";
                cin>>count;
                a.AddBook(Book(id,Title,Author,count));
                break;}
            case 2:{
                int idu;
                string name;
                cout<<"Enter User ID : ";
                cin>>idu;
                cout<<"Enter User Name : ";
                cin>>name;
                a.AddUser(User(idu,name));
                break;
                }
            case 3:{
                 string searchTitle;
                 cout<<"Enter Book Title to Search : ";
                 cin>>searchTitle;
                 a.searchkBook(searchTitle);
                 break;}
            case 4:{
                 int userID,bookID;
                 cout<<"Enter User ID : ";
                 cin>>userID;
                 cout<<"Enter Book ID to Borrow : ";
                 cin>>bookID;
                 a.borrowbook(userID,bookID);
                 break;}
            case 5:{
                 int returnUserID,returnBookID;
                 cout<<"Enter User ID : ";
                 cin>>returnUserID;
                 cout<<"Enter Book ID to Return : ";
                 cin>>returnBookID;
                 a.ReturnBook(returnBookID,returnUserID);
                 break;}
            case 6:{
                 a.printreport();
                 break;}
            case 7:{
                 int userID;
                 cout<<"Enter User ID : ";
                 cin>>userID;
                 a.borrowbookuser(userID);
                 break;}
            case 8:{
                 cout<<"Good Bye"<<"\n";
                 break;}
            default:
                 cout<<"Invalid choice"<<"\n";
                
        }
    }
    

    

    }
}