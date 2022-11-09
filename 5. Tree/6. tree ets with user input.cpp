#include <iostream>
#include<math.h>

using namespace std;

// node
struct Node {
	string label;
	Node *left, *right, *parent;
};

// variabel pointer global
Node *root, *newNode;

// create New Tree
void createNewTree( string label ) {
	if( root != NULL )
		cout << "\nTree sudah dibuat" << endl;
	else {
		root = new Node();
		root->label = label;
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
		cout << "\nNode " << label << " berhasil dibuat menjadi root." << endl;
	}
}

// insert Left
Node *insertLeft( string label, Node *node ) {
	if( root == NULL ) {
		cout << "\nBuat tree terlebih dahulu!!" << endl;
		return NULL;
	} else {
		// cek apakah anak kiri ada atau tidak
		if( node->left != NULL ) {
			// kalau ada
			cout << "\nNode "<< node->label << " sudah ada anak kiri!!" << endl;
			return NULL;
		} else {
			// kalau tidak ada
			newNode = new Node();
			newNode->label = label;
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->parent = node;
			node->left = newNode;
			cout << "\nNode " << label << " berhasil ditambahkan ke anak kiri " << newNode->parent->label << endl;
			return newNode;
		}
	}
}

// insert right
Node *insertRight( string label, Node *node ) {
	if( root == NULL ) {
		cout << "\nBuat tree terlebih dahulu!!" << endl;
		return NULL;
	} else {
		// cek apakah anak kiri ada atau tidak
		if( node->right != NULL ) {
			// kalau ada
			cout << "\nNode " << node->label << " sudah ada anak kanan!!" << endl;
			return NULL;
		} else {
			// kalau tidak ada
			newNode = new Node();
			newNode->label = label;
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->parent = node;
			node->right = newNode;
			cout << "\nNode " << label << " berhasil ditambahkan ke anak kanan " << newNode->parent->label << endl;
			return newNode;
		}
	}
}

// Empty
bool empty() {
	if( root == NULL )
		return true;
	else
		return false;
}

// update
void update(string label, Node *node) {
	if( !root ) {
		cout << "\nBuat tree terlebih dahulu!!" << endl;
	} else {
		if( !node )
			cout << "\nNode yang ingin diganti tidak ada!!" << endl;
		else {
			string temp = node->label;
			node->label = label;
			cout << "\nLabel node " << temp << " berhasil diubah menjadi " << label << endl;
		}
	}
}

// Find
void find( Node *node ) {
	if( !root ) {
		cout << "\nBuat tree terlebih dahulu!!" << endl;
	} else {
		if( !node )
			cout << "\nNode yang ditunjuk tidak ada!!" << endl;
		else {
			cout << "\nLabel Node : " << node->label << endl;
			cout << "Root Node : " << root->label << endl;

			if( !node->parent ) {
				cout << "Parent Node : (tidak punya orang tua)" << endl;
			} else {
				cout << "Parent Node : " << node->parent->label << endl;
			}

			if( node->parent != NULL && node->parent->left != node && node->parent->right == node ) {
				cout << "Saudara : " << node->parent->left->label << endl;
			} else if( node->parent != NULL && node->parent->right != node && node->parent->left == node ) {
				cout << "Saudara : " << node->parent->right->label << endl;
			} else {
				cout << "Saudara : (tidak punya saudara)" << endl;
			}

			if( !node->left ) {
				cout << "Anak Kiri Node : (tidak punya anak kiri)" << endl;
			} else {
				cout << "Anak Kiri Node : " << node->left->label << endl;
			}

			if( !node->right ) {
				cout << "Anak Kanan Node : (tidak punya anak kanan)" << endl;
			} else {
				cout << "Anak Kanan Node : " << node->right->label << endl;
			}
		}
	}
}

// Tranversal
// preOrder
void preOrder( Node *node = root ) {
	if( !root ) {
		cout << "\nBuat tree terlebih dahulu!!" << endl;
	} else {
		if( node != NULL ) {
			cout << node->label << ", ";
			preOrder(node->left);
			preOrder(node->right);
		}
	}
}

// inOrder
void inOrder( Node *node = root ) {
	if( !root ) {
		cout << "\nBuat tree terlebih dahulu!!" << endl;
	} else {
		if( node != NULL ) {
			inOrder(node->left);
			cout << node->label << ", ";
			inOrder(node->right);
		}
	}
}

// postOrder
void postOrder( Node *node = root ) {
	if( !root ) {
		cout << "\nBuat tree terlebih dahulu!!" << endl;
	} else {
		if( node != NULL ) {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->label << ", ";
		}
	}
}

int main() {
	cout<<"Input Nama Buyut : ";
	string buyut;
	cin>>buyut;
	createNewTree(buyut);

	int i;
	Node *nodeB[i], *nodeC[i], *nodeD[i], *nodeE[i], *nodeF[i];

	for(int i=0; i<(pow(2,1)); i++) {
		if(i==0) {
		cout << "Input Nama Anggota Keluarga di kolom B[0] : ";
		string b0;
		cin>>b0;
			nodeB[i]= insertLeft(b0, root);
		} else {
		cout << "Input Nama Anggota Keluarga di kolom B[1] : ";
		string b1;
		cin>>b1;
			nodeB[i]= insertRight(b1, root);
		}
	}
	cout << "Input Nama Anggota Keluarga di kolom C[0] : ";
	string c0;
	cin>>c0;
	nodeC[0]= insertLeft(c0, nodeB[0]);
	
	cout << "Input Nama Anggota Keluarga di kolom C[1] : ";
	string c1;
	cin>>c1;
	nodeC[1]= insertRight(c1, nodeB[0]);
	
	cout << "Input Nama Anggota Keluarga di kolom C[2] : ";
	string c2;
	cin>>c2;
	nodeC[2]= insertLeft(c2, nodeB[1]);
	
	cout << "Input Nama Anggota Keluarga di kolom C[3] : ";
	string c3;
	cin>>c3;
	nodeC[3]= insertRight("Ceri", nodeB[1]);


	cout << "Input Nama Anggota Keluarga di kolom D[0] : ";
	string d0;
	cin>>d0;
	nodeD[0]= insertLeft(d0, nodeC[0]);
	
	cout << "Input Nama Anggota Keluarga di kolom D[2] : ";
	string d1;
	cin>>d1;
	nodeD[1]= insertRight(d1, nodeC[0]);
	
	cout << "Input Nama Anggota Keluarga di kolom D[2] : ";
	string d2;
	cin>>d2;
	nodeD[2]= insertLeft(d2, nodeC[1]);
	
	cout << "Input Nama Anggota Keluarga di kolom D[3] : ";
	string d3;
	cin>>d3;
	nodeD[3]= insertRight(d3, nodeC[1]);
	
	cout << "Input Nama Anggota Keluarga di kolom D[4] : ";
	string d4;
	cin>>d4;
	nodeD[4]= insertLeft(d4, nodeC[2]);
	
	cout << "Input Nama Anggota Keluarga di kolom D[5] : ";
	string d5;
	cin>>d5;
	nodeD[5]= insertRight(d5, nodeC[2]);
	
	cout << "Input Nama Anggota Keluarga di kolom D[6] : ";
	string d6;
	cin>>d6;
	nodeD[6]= insertLeft("Danar", nodeC[3]);
	
	cout << "Input Nama Anggota Keluarga di kolom D[7] : ";
	string d7;
	cin>>d7;
	nodeD[7]= insertRight(d7, nodeC[3]);


	cout << "Input Nama Anggota Keluarga di kolom E[0] : ";
	string e0;
	cin>>e0;
	nodeE[0]= insertLeft(e0, nodeD[0]);
	
	cout << "Input Nama Anggota Keluarga di kolom E[1] : ";
	string e1;
	cin>>e1;
	nodeE[1]= insertRight(e1, nodeD[0]);
	
	cout << "Input Nama Anggota Keluarga di kolom E[2] : ";
	string e2;
	cin>>e2;
	nodeE[2]= insertLeft(e2, nodeD[1]);
	
	cout << "Input Nama Anggota Keluarga di kolom E[3] : ";
	string e3;
	cin>>e3;
	nodeE[3]= insertRight(e3, nodeD[1]);
	
	cout << "Input Nama Anggota Keluarga di kolom E[4] : ";
	string e4;
	cin>>e4;
	nodeE[4]= insertLeft(e4, nodeD[2]);
	
	cout << "Input Nama Anggota Keluarga di kolom E[5] : ";
	string e5;
	cin>>e5;
	nodeE[5]= insertRight(e5, nodeD[2]);
	
	cout << "Input Nama Anggota Keluarga di kolom E[6] : ";
	string e6;
	cin>>e6;
	nodeE[6]= insertLeft(e6, nodeD[3]);
	
	cout << "Input Nama Anggota Keluarga di kolom E[7] : ";
	string e7;
	cin>>e7;
	nodeE[7]= insertRight(e7, nodeD[3]);
	
	cout << "Input Nama Anggota Keluarga di kolom E[8] : ";
	string e8;
	cin>>e8;
	nodeE[8]= insertLeft(e8, nodeD[4]);
	
	cout << "Input Nama Anggota Keluarga di kolom E[9] : ";
	string e9;
	cin>>e9;
	nodeE[9]= insertRight(e9, nodeD[4]);
	
	cout << "Input Nama Anggota Keluarga di kolom E[10] : ";
	string e10;
	cin>>e10;
	nodeE[10]= insertLeft(e10, nodeD[5]);
	
	cout << "Input Nama Anggota Keluarga di kolom E[11] : ";
	string e11;
	cin>>e11;
	nodeE[11]= insertRight(e11, nodeD[5]);
	
	cout << "Input Nama Anggota Keluarga di kolom E[12] : ";
	string e12;
	cin>>e12;
	nodeE[12]= insertLeft(e12, nodeD[6]);
	nodeE[13]= insertRight("Engge", nodeD[6]);
	nodeE[14]= insertLeft("Enggo", nodeD[7]);
	nodeE[15]= insertRight("Enji", nodeD[7]);

	nodeF[0]= insertLeft("Fana", nodeE[0]);
	nodeF[1]= insertRight("Fani", nodeE[0]);
	nodeF[2]= insertLeft("Fanu", nodeE[1]);
	nodeF[3]= insertRight("Fane", nodeE[1]);
	nodeF[4]= insertLeft("Fano", nodeE[2]);
	nodeF[5]= insertRight("Fitra", nodeE[2]);
	nodeF[6]= insertLeft("Fitri", nodeE[3]);
	nodeF[7]= insertRight("Fitru", nodeE[3]);
	nodeF[8]= insertLeft("Fitre", nodeE[4]);
	nodeF[9]= insertRight("Fitro", nodeE[4]);
	nodeF[10]= insertLeft("Fiva", nodeE[5]);
	nodeF[11]= insertRight("Fivi", nodeE[5]);
	nodeF[12]= insertLeft("Fivu", nodeE[6]);
	nodeF[13]= insertRight("Five", nodeE[6]);
	nodeF[14]= insertLeft("Fivo", nodeE[7]);
	nodeF[15]= insertRight("Fadila", nodeE[7]);
	nodeF[16]= insertLeft("Fadili", nodeE[8]);
	nodeF[17]= insertRight("Fadilu", nodeE[8]);
	nodeF[18]= insertLeft("Fadile", nodeE[9]);
	nodeF[19]= insertRight("Fadilo", nodeE[9]);
	nodeF[20]= insertLeft("Faiza", nodeE[10]);
	nodeF[21]= insertRight("Faizi", nodeE[10]);
	nodeF[22]= insertLeft("Faizu", nodeE[11]);
	nodeF[23]= insertRight("Faize", nodeE[11]);
	nodeF[24]= insertLeft("Faizo", nodeE[12]);
	nodeF[25]= insertRight("Fatan", nodeE[12]);
	nodeF[26]= insertLeft("Fatin", nodeE[13]);
	nodeF[27]= insertRight("Fatun", nodeE[13]);
	nodeF[28]= insertLeft("Faten", nodeE[14]);
	nodeF[29]= insertRight("Faton", nodeE[14]);
	nodeF[30]= insertLeft("Firza", nodeE[15]);
	nodeF[31]= insertRight("Firzi", nodeE[15]);
	
	cout<<endl;
	cout<<"************************************************************************************************";
	cout << "\nPreOrder :" << endl;
	preOrder();
	cout<<endl<<endl;
	
	cout<<"| Cari Nama anggota keluarga pada kolom E7 |";
	find(nodeE[7]);
	
	cout<<endl<< "Ganti nama anggota keluarga : ";
	string newName;
	cin>>newName;
	update(newName, nodeE[7]);
	
	cout << "\nPreOrder :" << endl;
	preOrder();
	cout<<endl<<endl;

	cout<<"************************************************************************************************";
	cout << "\nInOrder :" << endl;
	inOrder();
	cout<<endl<<endl;
	
	cout<<"| Cari Nama anggota keluarga pada kolom C3 |";
	find(nodeC[3]);
	
	cout<<endl<< "Ganti nama anggota keluarga : ";
	string newName1;
	cin>>newName1;
	update(newName1, nodeC[3]);
	
	cout << "\nInOrder :" << endl;
	inOrder();
	cout<<endl<<endl;
	
	cout<<"************************************************************************************************";
	cout << "\nPostOrder :" << endl;
	postOrder();
	cout<<endl<<endl;
	
	cout<<"| Cari Nama anggota keluarga pada kolom F15 |";
	find(nodeF[15]);
	
	cout<<endl<< "Ganti nama anggota keluarga : ";
	string newName2;
	cin>>newName2;
	update(newName2, nodeF[15]);
	
	cout << "\nPostOrder :" << endl;
	postOrder();
	cout<<endl<<endl;

}