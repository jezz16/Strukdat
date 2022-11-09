// Arfan Yusran
// NRP 5027211017

#include <iostream>

using namespace std;

struct MobileLegend {
	//Komponen/member
	string namahero, gender;
	int umur;
	float tinggi;
	struct RoleHero{
		string role[2];
	} rolehero;
};

void printDataHero (MobileLegend data){
	cout << " Nama Hero : " << data.namahero << endl;
	cout << " Gender : " << data.gender << endl;
	cout << " Umur : " << data.umur << endl;
	cout << " Tinggi Badan : " << data.tinggi <<" cm"<< endl;
	cout << " Role : " << data.rolehero.role[0] <<", "<<data.rolehero.role[1]<< endl;
}

int main(){
	
	MobileLegend hero[20];
	
//	hero[0].namahero= "Balmond";
//	hero[0].gender = "Laki-laki";
//	hero[0].umur = 18;
//	hero[0].rolehero.role[0] = "Fighter";
//	hero[0].rolehero.role[1] = "Tank";
//	
//	cout << " Nama Hero : " << hero[0].namahero << endl;
//	cout << " Gender : " << hero[0].gender << endl;
//	cout << " Umur : " << hero[0].umur << endl;
//	cout << " Role : " << hero[0].rolehero.role[0] <<", "<<hero[0].rolehero.role[1]<< endl;

	cout<<"=========== Data Hero Mobile Legend =========="<<endl<<endl;

	hero[0] = {"Balmond", "Laki-laki", 18, 180.5, {"Fighter","Tank"}};
	hero[1] = {"Akai", "Cowok", 19, 183.2,{"Tank"}};
	hero[2] = {"Nana", "Cewek", 12, 130.2,{"Mage", "Support"}};	
	hero[3] = {"Gussion", "Cowok", 16, 175.5,{"Assasin", "Mage"}};
	hero[4] = {"Faramis", "Cowok", 18,170.8,{"Support", "Mage"}};
	hero[5] = {"Masha", "Cewek", 16, 165.7,{"Tank", "Fighter"}};
	hero[6] = {"Alice", "Cewek", 19, 170.0,{"Tank", "Mage"}};
	hero[7] = {"Miya", "Cewek", 16, 164.5,{"Marksman"}};
	hero[8] = {"Roger", "Cowok", 20,178.6,{"Marksman", "Fighter"}};
	hero[9] = {"Alucard", "Cowok", 18, 176.5,{"Assasin", "Fighter"}};
	hero[10] = {"Karina", "Cewek", 16,160.3,{"Assasin", "Mage"}};
	hero[11] = {"Kadita", "Cewek", 15,155.9,{"Assasin", "Mage"}};
	hero[12] = {"Linglung", "Cowok", 17,179.5,{"Assasin"}};
	hero[13] = {"Guinivere", "Cewek", 16, 158.5,{"Mage", "Fighter"}};
	hero[14] = {"Phoveus", "Cowok", 21,167.5,{"Mage", "Fighter"}};
	hero[15] = {"Fedrinn", "Cowok", 20, 180.5,{"Tank", "Fighter"}};
	hero[16] = {"Masha", "Cewek", 16,166.3,{"Tank", "Fighter"}};
	hero[17] = {"Atlas", "Cowok", 19,183.2,{"Tank", "Support"}};
	hero[18] = {"Carmila", "Cewek", 18,160.1,{"Support"}};
	hero[19] = {"Benedetta", "Cewek", 17, 167.8,{"Assasin", "Fighter"}};

	for(int i=0; i<20; i++){
		printDataHero(hero[i]);
		cout<< endl;
	}
	
	return 0;
}

