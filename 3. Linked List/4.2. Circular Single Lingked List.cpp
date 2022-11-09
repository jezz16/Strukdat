#include <iostream>
using namespace std;

// Deklarasi struktur untuk Circular Single Linked List
struct MobileLegend{
  string namahero, gender, role;
  MobileLegend *next;
};

MobileLegend *head, *tail, *newNode, *cur;

// create Circular Single Linked List
void createCircularSingleLinkedList(string dataBaru[3]){
  head = new MobileLegend();
  head->namahero = dataBaru[0];
  head->gender = dataBaru[1];
  head->role = dataBaru[2];
  tail = head;
  tail->next = head;
}

// add first
void addFirst( string data[3] ){
  if( head == NULL ){
    cout << "Linked List blom dibuat bro!!" << endl;
  }else{
    newNode = new MobileLegend();
    newNode->namahero = data[0];
    newNode->gender = data[1];
    newNode->role = data[2];
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
  }
}

// add Last
void addLast( string data[3] ){
  if( head == NULL ){
    cout << "Linked List blom dibuat bro!!" << endl;
  }else{
    newNode = new MobileLegend();
    newNode->namahero = data[0];
    newNode->gender = data[1];
    newNode->role = data[2];
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }
}

// add Middle
void addMiddle(string data[3], int posisi)
{
  if( head == NULL ){
    cout << "Linked List blom dibuat bro!!" << endl;
  }else{
    if( posisi == 1 ){
      cout << "Posisi satu bukan posisi tengah bro!!" << endl;
    }else{
      newNode = new MobileLegend();
      newNode->namahero = data[0];
      newNode->gender = data[1];
      newNode->role = data[2];

      // tranversing
      int nomor = 1;
      cur = head;
      while (nomor < posisi - 1)
      {
        cur = cur->next;
        nomor++;
      }
      newNode->next = cur->next;
      cur->next = newNode;
    }
  }
}

void printCircular()
{
  if( head == NULL ){
    cout << "Linked List blom dibuat bro!!" << endl;
  }else{
    cout << "Data Mobile Legend " << endl;
    cout<<"-----------------"<<endl;
    cur = head;
    while(cur->next != head ){
      // print
      cout << "Nama Hero : " << cur->namahero << endl;
      cout << "Gender Hero : " << cur->gender << endl;
      cout << "Role Hero : " << cur->role << endl<< endl;
      //step
      cur = cur->next;
	}
	    cout << "Nama Hero : " << cur->namahero << endl;
      cout << "Gender Hero : " << cur->gender << endl;
      cout << "Role Hero : " << cur->role << endl<< endl;
	}
}


int main(){
  string dataBaru[3] = {"Akai", "Cowok", "Tank"};
  createCircularSingleLinkedList(dataBaru);
  printCircular();
  cout<<endl<<endl;

  string data[3] = {"Miya", "Cewek", "Marksman"};
  addFirst(data);
  printCircular();
  cout<<endl<<endl;
  
  string data2[3] = {"Siti Arofah", "Cewek", "Mage/Support"};
  addLast(data2);
  printCircular();
  cout<<endl<<endl;
  
  string data3[3] = {"Julianto", "Cowok", "Fighter/Mage"};
  addMiddle(data3, 3);
  printCircular();
  cout<<endl<<endl;
}