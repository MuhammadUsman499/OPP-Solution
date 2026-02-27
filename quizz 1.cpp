#include<iostream>
using namespace std;

class library{
protected:
    string title;
    string author;
    int Id;
    
public:
    library(string t,string a,int i){
        title = t;
        author = a;
        Id = i;
    }
    
    virtual void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ID: " << Id << endl;
    }
};

class Book : public library {
private:
    int pages;
    string genre;

public:
    Book(string t, string a, int i, int p, string g )
        : library(t,a,i) {
        pages = p;
        genre = g;
    }
    
    void display() override { 
        library::display();   // call base class function
        cout << "Pages: " << pages << endl;
        cout << "Genre: " << genre << endl;
    }
};

class magazine: public library {
    int issuenumber;
    string month;

public:
    magazine(string t, string a, int i, int issue, string m)
        : library(t, a, i) {
        issuenumber = issue;
        month = m;
    }

    void display() override {
        library::display();
        cout << "Issue Number: " << issuenumber << endl;
        cout << "Month: " << month << endl;
    }
};

class audioboook: public library {
private:
    int duration;
    string narratorNAme;
    
public:
    audioboook(string t, string a, int i, int d, string n)
        : library(t, a, i) {
        duration = d;
        narratorNAme = n;
    }

    void display() override {
        library::display();
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Narrator: " << narratorNAme << endl;
    }
};

int main(){
    Book b1("pakstudy", "english", 101, 102, "Education");
    Book b2("Isl", "urdu", 103, 104, "Education");
    magazine m1("DAWN", "AJJ", 202, 12, "January");
    magazine m2("KOCH", "Maghraib", 204, 14, "Fbrury");
    audioboook a1("Atomic Habits", "James Clear", 303, 320, "Jhon");
    audioboook a2("Mchiel", "Jckson", 303, 320, "Jhon");

cout<<"\nBOOK details :"<<endl;
    b1.display();
    cout << endl;
    b2.display();
    cout << endl;
    
    cout<<"\nMaxine details :"<<endl;
    m1.display();
    cout << endl;
    m2.display();
    cout << endl;
    
    cout<<"\nAudiobook details :"<<endl;
    a1.display();
    cout << endl;
    a2.display();

    return 0;
}
