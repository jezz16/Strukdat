#include <iostream>

using namespace std; 

int main( )
{
	
	string nama = "tridik";
	string *ptr = &nama;
	
	cout <<"nama : " << nama<<endl;	
	cout <<"&nama : " << &nama<<endl;
	cout <<"ptr : " << ptr<<endl;
	cout <<"*ptr : " << *ptr<<endl;
		
    return 0;
    
}
