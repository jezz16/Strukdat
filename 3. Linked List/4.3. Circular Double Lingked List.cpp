#include <iostream>

using namespace std;

// struktur linked list
struct MobileLegend{
  string namahero, gender;
  int umur;
  MobileLegend *prev;
  MobileLegend *next;
};

MobileLegend *head, *tail, *cur, *newNode, *afterNode;

// Create circular double Linked list
void createMobileLegend( string namahero, string Gender, int umur ){
  head = new MobileLegend();
  head->namahero = namahero;
  head->gender = Gender;
  head->umur = umur;
  head->prev = head;
  head->next = head;
  tail = head;
}

// add First
void addFirst( string namahero, string Gender, int umur ){
  if( head == NULL ){
    cout << "Linked List blom dibuat bro!!" << endl;
  }else{
    newNode = new MobileLegend();
    newNode->namahero = namahero;
    newNode->gender = Gender;
    newNode->umur = umur;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
  }
}

// add Last
void addLast( string namahero, string Gender, int umur ){
  if( head == NULL ){
    cout << "Linked List blom dibuat bro!!" << endl;
  }else{
    newNode = new MobileLegend();
    newNode->namahero = namahero;
    newNode->gender = Gender;
    newNode->umur = umur;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    tail = newNode;
  }
}

// add Middle
void addMiddle( string namahero, string Gender, int umur, int posisi ){
  if( head == NULL ){
    cout << "Linked List blom dibuat bro!!" << endl;
  }else{
    if( posisi == 1 ){
      cout << "Posisi 1 bukan posisi tengah" << endl;
    }else if( posisi < 1 ){
      cout << "Posisi diluar jangkauan" << endl;
    }else{
      newNode = new MobileLegend();
      newNode->namahero = namahero;
      newNode->gender = Gender;
      newNode->umur = umur;

      // tranversing
      cur = head;
      int nomor = 1;
      while ( nomor < posisi - 1 ){
        cur = cur->next;
        nomor++;
      }
      
      afterNode = cur->next;
      cur->next = newNode;
      afterNode->prev = newNode;
      newNode->prev = cur;
      newNode->next = afterNode;
    }
  }
}

// fungsi print
void printMobileLegend()
{
  if( head == NULL ){
    cout << "Linked List blom dibuat bro!!" << endl;
  }else{
    cout << "Data Mobile Legend " << endl;
    cout<<"-----------------"<<endl;
    cur = head;
    while( cur->next != head ){
      // print
      // print
      cout << "Nama Hero : " << cur->namahero << endl;
      cout << "Gender Hero : " << cur->gender << endl;
      cout << "Role Hero : " << cur->umur << endl<< endl;
      //step
      cur = cur->next;
    }
    // print last node
	  cout << "Nama Hero : " << cur->namahero << endl;
      cout << "Gender Hero : " << cur->gender << endl;
      cout << "Umur Hero : " << cur->umur << endl<< endl;
  }
}

int main(){
	
  createMobileLegend("Akai", "Cowok", 25);
  printMobileLegend();
  cout<<endl<<endl;

  addFirst("Siti Arofah", "Cewek", 16);
  printMobileLegend();
  cout<<endl<<endl;

  addLast("Miya", "Cewek", 18);
  printMobileLegend();
  cout<<endl<<endl;

  addMiddle("Julianto", "Cowok", 24, 3);
  printMobileLegend();
  cout<<endl<<endl;
}