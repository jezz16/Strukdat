#include <iostream>

using namespace std; 

int main( )
{
	
	string nama = "tridik";
	string *ptr = &nama;
	
	cout <<"Nama : " << nama<<endl;
	
	*ptr= "ganteng";
	cout <<"Nama : " << nama<<endl;
	cout <<"*ptr : " << *ptr<<endl;
	
	
    return 0;
    
}
