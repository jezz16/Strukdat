#include <iostream>
using namespace std;

// deklarasi double linked list
struct MobileLegend{
  string namahero, gender, role;
  MobileLegend *prev;
  MobileLegend *next;
};

MobileLegend *head, *tail, *cur, *newNode, *afterNode;

// Create Double Linked List
void createDoubleLinkedList( string data[3] ){
  head = new MobileLegend();
  head->namahero = data[0];
  head->gender = data[1];
  head->role = data[2];
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

// Add First
void addFirst( string data[3] ){
  if( head == NULL ){
    cout << "Linked List blom dibuat bro!!";
  }else{
    newNode = new MobileLegend();
    newNode->namahero = data[0];
    newNode->gender = data[1];
    newNode->role = data[2];
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

// Add Last
void addLast( string data[3] ){
  if( head == NULL ){
    cout << "Linked List blom dibuat bro!!";
  }else{
    newNode = new MobileLegend();
    newNode->namahero = data[0];
    newNode->gender = data[1];
    newNode->role = data[2];
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
  }
}

// Add Middle
void addMiddle( string data[3], int posisi ){
  if( head == NULL ){
    cout << "Linked List blom dibuat bro!!";
  }else{
    if( posisi == 1 ){
      cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
    }else if( posisi < 1 || posisi > countDoubleLinkedList() ){
      cout << "Posisi diluar jangkauan!!!" << endl;
    }else{
      newNode = new MobileLegend();
      newNode->namahero = data[0];
      newNode->gender = data[1];
      newNode->role = data[2];

      // tranversing
      cur = head;
      int nomor = 1;
      while( nomor <  posisi - 1){
        cur = cur->next;
        nomor++;
      }

      afterNode = cur->next;
      newNode->prev = cur;
      newNode->next = afterNode;
      cur->next = newNode;
      afterNode->prev = newNode;
    }
  }
}

// Print Double Linked List
void printDoubleLinkedList()
{
  if( head == NULL ){
    cout << "Linked List blom dibuat bro!!";
  }else{
    cout << "Jumlah Data : " << countDoubleLinkedList() << endl;
    cout<<"-----------------"<<endl;
    cur = head;
    while( cur != NULL ){
      // print
      cout << "Nama Hero : " << cur->namahero << endl;
      cout << "Gender Hero : " << cur->gender << endl;
      cout << "Role Hero : " << cur->role << endl<< endl;
      //step
      cur = cur->next;
    }
  }
}

int main(){

  string newData[3] = {"Akai", "Cowok", "Tank"};
  createDoubleLinkedList(newData);
  printDoubleLinkedList();
  cout<<endl<<endl;

  string data2[3] = {"Miya", "Cewek", "Marksman"};
  addFirst( data2 );
  printDoubleLinkedList();
  cout<<endl<<endl;

  string data3[3] = {"Siti Arofah", "Cewek", "Mage/Support"};
  addLast( data3 );
  printDoubleLinkedList();
  cout<<endl<<endl;

  string data4[3] = {"Julianto", "Cowok", "Fighter/Mage"};
  addMiddle(data4, 2);
  printDoubleLinkedList();
  cout<<endl<<endl;
}