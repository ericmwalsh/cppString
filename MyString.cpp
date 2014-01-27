#include "MyString.h"

ListNode::ListNode(){
    info = NULL;
    next = NULL;
}
ListNode::ListNode(char inp){
    info = inp;
    next = NULL;
}
ListNode::ListNode(char inp, ListNode * target){
    info = inp;
    next = target;
}
ListNode::~ListNode(){
    delete next;
}
void ListNode::print(){
    cout << info << endl;
    if(next!=NULL) next->print();
}

//Regular MyString Constructor  - for MyString of length N this is O(N)
MyString::MyString(const char* s){
    if(s=="") head=NULL;
    else{
        head = new ListNode(s[0]);
        ListNode * temp = head;
        for(int i=1; s[i]!='\0'; i++){
            temp->next = new ListNode(s[i]);
            temp=temp->next;
        }
    }
}
//Deep-Copy MyString Constructor - for MyString of length N this is O(N)
MyString::MyString(const MyString &s){
    head = new ListNode(s.head->info);
    ListNode * temp1 = head;
    ListNode * temp2 = s.head->next;
    while(temp2){
        temp1->next = new ListNode(temp2->info);
        temp1=temp1->next;
        temp2=temp2->next;
    }
}
//Deep-Assignment MyString Operator  - for MyString of length N this is O(N)
MyString MyString::operator= (const MyString &s){
    MyString *  assignment = new MyString(s);
    delete head;
    head = assignment->head;
    return *this;
}
//+ Operator override for MyString - returns a new string that has this string concatenated with s - for MyString of length N this is O(N)
MyString MyString::operator + (const MyString &s) const{
    ListNode * temp1 = head;
    ListNode * temp2 = s.head;
    char myStr[length() + s.length()];
    int i=0;
    while(temp1){
        myStr[i]=temp1->info;
        i++;
        temp1=temp1->next;
    }
    while(temp2){
        myStr[i]=temp2->info;
        i++;
        temp2=temp2->next;
    }
    return MyString(myStr);
}
//+= Operator override for MyString - concatenates s onto this MyString  - for MyString of length N this is O(N)
MyString MyString::operator += (const MyString &s){
    MyString plusEquals = (*this + s);
    return *this = plusEquals;
}

//Length MyString method returns an int - for a MyString w/ N characters, length has O(N)
int MyString::length() const{
    int ans = 0;
    ListNode * temp = head;
    while(temp){
        ans++;
        temp=temp->next;
    }
    return ans;
}
//[] Operator override for MyString - returns char at the index - for MyString of length N this is O(N)
char & MyString::operator [] (const int index){
    if(index>=length()) error("ERROR - INDEX OUT OF BOUNDS");
    else{
        ListNode * temp = head;
        for(int i=0; i<index; i++) temp=temp->next;
        return temp->info;
    }
}
//== Operator override for MyString - returns true if all chars are in the same positions - for MyString of length N this is O(N)
bool MyString::operator == (const MyString &s) const{
    if(length()!=s.length()) return false;
    ListNode * temp1 = head;
    ListNode * temp2 = s.head;
    while(temp1){
        if(temp1->info!=temp2->info) return false;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
}
//Returns the index of char c if it is in the MyString; else returns -1; - for MyString of length N this is O(N)
int MyString::indexOf(char c) const{
    int ans = 0;
    ListNode * temp = head;
    while(temp){
        if(temp->info==c) return ans;
        else{
            ans++;
            temp=temp->next;
        }
    }
    return -1;
}
//returns a new MyString that is the MyString reversed ("hello" becomes "olleh") - T(N) of about 2N (for MyString with size N input) however O(N)
MyString MyString::reverse(){
    ListNode * temp1 = head;
    int len = length();
    char myStr[len--];
    while(temp1){
        myStr[len--]=temp1->info;
        temp1=temp1->next;
    }
    return MyString(myStr);
}
//MyString Destructor (recursive deletion of nodes implemented via ListNode destructor) - For a MyString with N letters this is an O(N)
MyString::~MyString(){
    delete head;
}
//Error method - O(1)
void MyString::error(const char *s)
{
     cerr << "Error: " << s << endl;
     throw 0;
}

//Testing method for deep constructor and assignment
void MyString::testDeepMethods(int i){
    if(i==0){
        head->info = 'x';
        head->next->info = 'y';
        head->next->next->info = 'z';
    }
    else{
        head->info = 'a';
        head->next->info = 'b';
        head->next->next->info = 'c';
    }
}
//For a word with N letters this is O(N)
void MyString::print(ostream & out) const{
    ListNode * temp = head;
    while(temp){
        out << temp->info;
        temp=temp->next;
    }
}
//Takes the next char * input from the input istream and sets this MyString to that new string. For word input of size N this is O(N)
void MyString::read(istream& in){
    delete head;
    char s[1024];
    in >> s;
    MyString * temp = new MyString(s);
    head = temp->head;
}
//Override << operator to print out MyString str - For MyString of string length N the big O is O(N)
inline ostream & operator << ( ostream & out, const MyString & str )
{
     str.print(out);
     return out;
}
//Override >> operator to set MyString str to the input - For MyString of string length N the big O is O(N)
inline istream & operator >> ( istream & in, MyString & str )
{
     str.read(in);
     return in;
}
