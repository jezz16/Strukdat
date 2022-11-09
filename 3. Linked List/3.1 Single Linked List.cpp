//Arfan Yusran (5027211017)
#include <iostream>

using namespace std;

struct Lagu{
  string judul, penyanyi;
  int tahunTerbit;
  Lagu *next;
};

Lagu *head, *tail, *cur, *newNode, *del, *before;

// create linked list
void createSingleLinkedList(string judul, string penyanyi, int tB){
  head = new Lagu();
  head->judul = judul;
  head->penyanyi = penyanyi;
  head->tahunTerbit = tB;
  head->next = NULL;
  tail = head;
  
  cout <<"Judul Lagu : ";
  cin >>head->judul;
  cout << "Penyanyi : ";
  cin >>head->penyanyi;
  cout << "Tahun Terbit Lagu : "; 
  cin >> head->tahunTerbit;
  cout<<endl;
}

// print linked list
int countSingleLinkedList(){
  cur = head;
  int jumlah = 0;
  while( cur != NULL ){
    jumlah++;
    cur = cur->next;
  }
  return jumlah;
}

// tambahAwal Single linked list
void addAwal(string judul, string penyanyi, int tB){
  newNode = new Lagu();
  newNode->judul = judul;
  newNode->penyanyi = penyanyi;
  newNode->tahunTerbit = tB;
  newNode->next = head;
  head = newNode;
  
  cout <<"Judul Lagu : ";
  cin >>head->judul;
  cout << "Penyanyi : ";
  cin >>head->penyanyi;
  cout << "Tahun Terbit Lagu : "; 
  cin >> head->tahunTerbit;
  cout<<endl;
}

// tambahAkhir Single linked list
void addAkhir(string judul, string penyanyi, int tB){
  newNode = new Lagu();
  newNode->judul = judul;
  newNode->penyanyi = penyanyi;
  newNode->tahunTerbit = tB;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
  
  cout <<"Judul Lagu : ";
  cin >>tail->judul;
  cout << "Penyanyi : ";
  cin >>tail->penyanyi;
  cout << "Tahun Terbit Lagu : "; 
  cin >> tail->tahunTerbit;
  cout<<endl;
}

// tambah tengah single linked list
void addTengah(string judul, string penyanyi, int tB, int posisi){
  cout << "Posisi : "; 
  cin >> posisi;
  if( posisi < 1 || posisi > countSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    newNode = new Lagu();
    newNode->judul = judul;
    newNode->penyanyi = penyanyi;
    newNode->tahunTerbit = tB;

    // tranversing
    cur = head;
    int nomor = 1;
    while( nomor < posisi - 1 ){
      cur = cur->next;
      nomor++;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    
  cout <<"Judul Lagu : ";
  cin >>newNode->judul;
  cout << "Penyanyi : ";
  cin >>newNode->penyanyi;
  cout << "Tahun Terbit Lagu : "; 
  cin >> newNode->tahunTerbit;
  cout<<endl;
  }
}

// Remove Awal
void removeAwal(){
  del = head;
  head = head->next;
  delete del;
}

// Remove Akhir
void removeAkhir(){
  del = tail;
  cur = head;
  while( cur->next != tail ){
    cur = cur->next;
  }
  tail = cur;
  tail->next = NULL;
  delete del;
}

// remove Tengah
void removeTengah(int posisi){
  cout << "Posisi data yang ingin dihapus : "; 
  cin >> posisi;
  if( posisi < 1 || posisi > countSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    int nomor = 1;
    cur = head;
    while( nomor <= posisi ){
      if( nomor == posisi-1 ){
        before = cur;
      }
      if( nomor == posisi ){
        del = cur;
      }
      cur = cur->next;
      nomor++;
    }
    before->next = cur;
    delete del;    
  }
}

// ubahAwal Single linked list
void changeAwal(string judul, string penyanyi, int tB){
  head->judul = judul;
  head->penyanyi = penyanyi;
  head->tahunTerbit = tB;
  
  cout <<"Judul Lagu : ";
  cin >>head->judul;
  cout << "Penyanyi : ";
  cin >>head->penyanyi;
  cout << "Tahun Terbit Lagu : "; 
  cin >> head->tahunTerbit;
  cout<<endl;
}

// ubahAkhir Single linked list
void changeAkhir(string judul, string penyanyi, int tB){
  tail->judul = judul;
  tail->penyanyi = penyanyi;
  tail->tahunTerbit = tB;
  
  cout <<"Judul Lagu : ";
  cin >>tail->judul;
  cout << "Penyanyi : ";
  cin >>tail->penyanyi;
  cout << "Tahun Terbit Lagu : "; 
  cin >> tail->tahunTerbit;
  cout<<endl;
}

// ubah Tengah Single linked list
void changeTengah(string judul, string penyanyi, int tB, int posisi){
  cout << "Posisi data yang ingin di ubah : "; 
  cin >> posisi;
  if( posisi < 1 || posisi > countSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1 || posisi == countSingleLinkedList() ){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    cur = head;
    int nomor = 1;
    while( nomor < posisi ){
      cur = cur->next;
      nomor++;
      
    cur->judul = judul;
    cur->penyanyi = penyanyi;
    cur->tahunTerbit = tB;
    }
    
  cout <<"Judul Lagu : ";
  cin >>cur->judul;
  cout << "Penyanyi : ";
  cin >>cur->penyanyi;
  cout << "Tahun Terbit Lagu : "; 
  cin >> cur->tahunTerbit;
  cout<<endl;
  }
}

// print linked list
void printSingleLinkedList(){
  cout <<endl<<"Jumlah data : " << countSingleLinkedList() << endl;
  cur = head;
  while( cur != NULL ){
    cout << "Judul Lagu : " << cur->judul << endl;
    cout << "Penyanyi : " << cur->penyanyi << endl;
    cout << "Tahun Terbit Lagu : " << cur->tahunTerbit << endl<<endl;

    cur = cur->next;
  }
}

int main(){
  cout << "Input data" << endl;
  createSingleLinkedList(" ", " ", 0); 
  printSingleLinkedList();
  cout << "\n" << endl;
 	
  cout << "Tambah data di awal"<<endl;
  addAwal("", "", 0);
  printSingleLinkedList();
  cout << "\n" << endl;
  
  cout << "Tambah data di akhir"<<endl;
  addAkhir("", "", 0);
  printSingleLinkedList();
  cout << "\n" << endl;
  
  cout << "Tambah data di tengah"<<endl;
  addTengah("", "", 0,0);
  printSingleLinkedList();
  cout << "\n" << endl;
  
  cout<< "apakah ingin mengahapus data awal ? "<<endl<<"Ketik 1 jika iya, ketik yang lain jika tidak :";
  int x;
  cin >> x;
  if (x==1){
  removeAwal();
  printSingleLinkedList(); 
  }
  cout << "\n" << endl;
  
  cout<< "apakah ingin mengahapus data akhir ? "<<endl<<"Ketik 1 jika iya, ketik yang lain jika tidak :";
  int y;
  cin >> y;
  if (y==1){
  removeAkhir();
  printSingleLinkedList(); 
  }
  cout << "\n" << endl;
  
  cout<< "apakah ingin mengahapus data tengah ? "<<endl<<"Ketik 1 jika iya, ketik yang lain jika tidak :";
  int z;
  cin >> z;
  if (z==1){
  removeTengah(0);
  printSingleLinkedList(); 
  }
  cout << "\n" << endl;
  
  cout<< "apakah ingin mengganti data awal ? "<<endl<<"Ketik 1 jika iya, ketik yang lain jika tidak :";
  int a;
  cin >> a;
  if (a==1){
  changeAwal(" ", " ", 0);
  printSingleLinkedList(); 
  }
  cout << "\n" << endl;
  
  cout<< "apakah ingin mengganti data tengah ? "<<endl<<"Ketik 1 jika iya, ketik yang lain jika tidak :";
  int b;
  cin >> b;
  if (b==1){
  changeTengah(" ", " ", 0, 0);
  printSingleLinkedList(); 
  }
  cout << "\n" << endl;

  cout<< "apakah ingin mengganti data akhir ? "<<endl<<"Ketik 1 jika iya, ketik yang lain jika tidak :";
  int c;
  cin >> c;
  if (c==1){
  changeAkhir(" ", " ", 0);
  printSingleLinkedList(); 
  }
  cout << "\n" << endl;
}