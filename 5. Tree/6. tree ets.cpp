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

// insert anak kiri
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

// insert anak kanan
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

// update data
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

// Find data
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
	createNewTree("Arfan");

	int i;
	Node *nodeB[i], *nodeC[i], *nodeD[i], *nodeE[i], *nodeF[i];

	for(int i=0; i<(pow(2,1)); i++) {
		if(i==0) {
			nodeB[i]= insertLeft("Beni", root);
		} else {
			nodeB[i]= insertRight("Budi", root);
		}
	}

	nodeC[0]= insertLeft("Caca", nodeB[0]);
	nodeC[1]= insertRight("Cici", nodeB[0]);
	nodeC[2]= insertLeft("Cindi", nodeB[1]);
	nodeC[3]= insertRight("Ceri", nodeB[1]);

	nodeD[0]= insertLeft("Dana", nodeC[0]);
	nodeD[1]= insertRight("Dini", nodeC[0]);
	nodeD[2]= insertLeft("Dadang", nodeC[1]);
	nodeD[3]= insertRight("Dudung", nodeC[1]);
	nodeD[4]= insertLeft("Dinda", nodeC[2]);
	nodeD[5]= insertRight("Didin", nodeC[2]);
	nodeD[6]= insertLeft("Danar", nodeC[3]);
	nodeD[7]= insertRight("Danur", nodeC[3]);

	nodeE[0]= insertLeft("Ela", nodeD[0]);
	nodeE[1]= insertRight("Eli", nodeD[0]);
	nodeE[2]= insertLeft("Elu", nodeD[1]);
	nodeE[3]= insertRight("Ele", nodeD[1]);
	nodeE[4]= insertLeft("Elo", nodeD[2]);
	nodeE[5]= insertRight("Era", nodeD[2]);
	nodeE[6]= insertLeft("Eri", nodeD[3]);
	nodeE[7]= insertRight("Eru", nodeD[3]);
	nodeE[8]= insertLeft("Ere", nodeD[4]);
	nodeE[9]= insertRight("Ero", nodeD[4]);
	nodeE[10]= insertLeft("Engga", nodeD[5]);
	nodeE[11]= insertRight("Enggi", nodeD[5]);
	nodeE[12]= insertLeft("Enggu", nodeD[6]);
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
	
	cout<<endl<< "Ganti nama anggota keluarga pada kolom E7 : ";
	string newName;
	cin>>newName;update(newName, nodeE[7]);
	
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
	cout<<"************************************************************************************************";

}