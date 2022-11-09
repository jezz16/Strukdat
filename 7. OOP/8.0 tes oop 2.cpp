#include <iostream>
using namespace std;

class MHS {
	
	//Acces Specifier
	public:
	//member function()
	void printname() {
		cout << "MHS name is : "<< MHSname; 
	}
	
	string getNama() {
	 return MHSname;
	}
	
	MHS (string nama){
		MHSname = nama;
	}
	
	private:
	string MHSname; // data member
};

int main() {\
	//declare an object of class geeks
	MHS mhs1("ali");
//	MHS mhs2("Ali");
	
	//accesing data member 
//	mhs1.MHSname = "Wika";
	
	//accesing member function
	mhs1.printname();
	
	cout<<mhs1.getNama();
	
	return 0;
}