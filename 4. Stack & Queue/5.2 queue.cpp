#include <iostream>
#define MAX 100
using namespace std;

struct queue {
    int depan;
    int belakang;
    string nama[MAX];
    string alamat[MAX];
    string hp[MAX];
}AntrianTeller, AntrianCS;

void init(queue *q) {
    q->depan = NULL;
    q->belakang = NULL;
}

bool isEmpty(queue *q) {
    return (q->depan == -1 && q->belakang == -1);
}

bool isFull(queue *q) {
    return (q->belakang == MAX-1);
}

void enqueue(queue *q, string nama, string alamat, string hp) {
    if (isFull(q)) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty(q)) {
            q->depan = 0;
        }
        q->belakang++;
        q->nama[q->belakang] = nama;
        q->alamat[q->belakang] = alamat;
        q->hp[q->belakang] = hp;
    }
}

void print(queue *q) {
    if (isEmpty(q)) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = q->depan; i < q->belakang; i++) {
            cout << q->nama[i+1]<<" ["<<q->alamat[i+1]<<"]"<<" ["<<q->hp[i+1]<<"] "<< " : " << "Antrian" << " " << i+1 << endl;
        }
        cout << endl;
    }
}

int main(){

    init(&AntrianTeller);
    init(&AntrianCS);

    int n;
    string indikator;
    string nama;
    string alamat;
    string hp;

	cout<<"Jumlah Nasabah : ";
    cin >> n;

    for (int i = 0; i < n; i++) {
    	cout<< "Nasabah "<<i+1<<" Input data dulu ya !"<<endl;
		{
            cout<<"Input nama : ";
            cin >> nama;
            cout<<"Input alamat : ";
            cin >> alamat;
            cout<<"Input no hp : ";
            cin >> hp;
            cout<<endl;
            
            if((&AntrianTeller)->belakang <= (&AntrianCS)->belakang){
                enqueue(&AntrianTeller, nama, alamat, hp);
            }else if((&AntrianCS)->belakang <= (&AntrianTeller)->belakang){
                enqueue(&AntrianCS, nama, alamat, hp);
            }
        } 
    }
 	
 	cout<<"------------------------"<<endl;
 	cout<<"    Antrian Sekarang    "<<endl;
 	cout<<"------------------------"<<endl;
 	cout << "Antrian Teller: "<<endl;
    print(&AntrianTeller);
    cout << "Antrian CS: "<<endl;
    print(&AntrianCS);
    

}