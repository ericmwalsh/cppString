//MyString.h
#include <iostream>
#include <fstream> // for doing file I/O
using namespace std;


#ifndef list_node
#define list_node

class ListNode{

public:
    char info;
    ListNode * next;
    ListNode();
    ListNode(char inp);
    ListNode(char inp, ListNode * target);
    ~ListNode();
    void print();
};

#endif // list_node



#ifndef my_string
#define my_string

class MyString{

private:
    ListNode * head;
public:
    MyString(const char *s = "");
    MyString(const MyString &s);
    MyString operator = (const MyString &s);
    char & operator [] (const int index);
    int length() const;
    int indexOf(char c) const;
    bool operator == (const MyString &s) const;
    MyString operator + (const MyString &s) const;
    MyString operator += (const MyString &s);
    MyString reverse();

    void print(ostream & out) const;
    void read(istream & in);
    ~MyString();
    void error(const char *s);
    void testDeepMethods(int i);
};

#endif // my_string
