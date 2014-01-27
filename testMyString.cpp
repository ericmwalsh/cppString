#include "MyString.cpp"

void testListNodes(){
    ListNode a = ListNode('a');
    ListNode b = ListNode('b', &a);
    ListNode c = ListNode('c', &b);
    b.print();
    cout << "AND C PRINT" << endl;
    c.print();
}

void testPrint(char *inp="test"){
    MyString a(inp);
    cout << a << endl;
}

void testDeepConstructorAndAssignment(){
    MyString a("ORIGINAL A");
    cout << "PRINTS A - " << a << endl;
    MyString c("ORIGINAL C");
    cout << "PRINTS C - " << c << endl;
    MyString b(a);
    cout << "B HAS BEEN DEEP CONSTRUCTED FROM A" << endl;
    c=b;
    cout << "C HAS BEEN DEEP ASSIGNED TO B" << endl;
    cout << "PRINTING A,B,and C - THEY SHOULD ALL BE THE SAME" << endl;
    cout << "PRINTS A - " << a << endl;
    cout << "PRINTS B - " << b << endl;
    cout << "PRINTS C - " << c << endl;
    b.testDeepMethods(0);
    c.testDeepMethods(1);
    cout << "ALTERED B AND C - ALL STRINGS SHOULD BE UNIQUE" << endl;
    cout << "PRINTS A - " << a << endl;
    cout << "PRINTS B - " << b << endl;
    cout << "PRINTS C - " << c << endl;
}
//method to test length() and indexOf() MyString methods
void testLengthAndIndex(){
    MyString a("abcdefg");
    cout << "MyString A is : " << a << endl;
    cout << "Length of A is : " << a.length() << endl;
    cout << "Index of the letter c in A is : " << a.indexOf('c') << endl;
    cout << "Index of the letter z in A is : " << a.indexOf('z') << " <<< this should be -1." << endl;
    MyString b("1234qwer");
    cout << "MyString B is : " << b << endl;
    cout << "Length of B is : " << b.length() << endl;
    cout << "Index of the letter w in B is : " << b.indexOf('w') << endl;
    cout << "Index of the letter z in B is : " << b.indexOf('z') << " <<< this should be -1." << endl;
    MyString c("12345");
    cout << "MyString C is : " << c << endl;
    cout << "Length of C is : " << c.length() << endl;
    cout << "Index of the number 1 in C is : " << c.indexOf('1') << endl;
    cout << "Index of the number 6 in C is : " << c.indexOf('6') << " <<< this should be -1." << endl;
    cout << "Character at index 0 of C is : " << c[0] << endl;
    cout << "Character at index 4 of C is : " << c[4] << endl;
}
void testPlusOperator(){
    MyString a("abcdefg");
    MyString b("1234qwer");
    MyString c= a+b;
    a.testDeepMethods(0);
    b.testDeepMethods(1);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}
void testPlusEqualsOperator(){
    MyString a("abcdefg");
    MyString b("1234qwer");
    a+=b;
    cout << a << endl;
    b.testDeepMethods(0);
    cout << b << endl;
    cout << a << endl;
}
void testRead(){
    MyString a("abcdefg");
    cout << a.reverse() << endl;
    MyString b("haha");
    cout << b << endl;
    cin >> b;
    cout << b;
}
int main(){

}
