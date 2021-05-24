#include <iostream>

#include "BinarySearchTree.h"

using namespace std;

int main() {
    BinarySearchTree BST;
    int opt;
    do {
        system("cls");
        cout << " +--------[Binary Search Tree]--------+\n"
                " | 1. Insert                          |\n"
                " | 2. Inorder                         |\n"
                " | 3. Postorder                       |\n"
                " | 4. Delete Node                     |\n"
                " | 5. <<FOR CHECKING ROOT DATA>>      |\n"
                " | 0. Exit                            |\n"
                " +------------------------------------+\n"
                " >> ";
        if (!(cin >> opt)) {
            opt = -1;
            cin.clear();
            cin.ignore(256, '\n');
        }
        cin.get();

        switch (opt) {
            case 1: {
                string data;
                cout << "\n Masukkan data: ";
                cin >> data;
                BST.setRoot(BST.insert(BST.getRoot(), data));
                cout << " Data berhasil dimasukkan";
                cin.get();cin.get();
                break;
            }

            case 2:
                cout << endl;
                BST.inOrder(BST.getRoot());
                cin.get();
                break;

            case 3:
                cout << endl;
                BST.postOrder(BST.getRoot());
                cin.get();
                break;

            case 4: {
                string data;
                cout << "\n Masukkan data yang ingin dihapus: ";
                cin >> data;
                BST.delNode(BST.getRoot(), data);
                cout << " Data " << data << " berhasil dihapus!";
                cin.get();cin.get();
                break;
            }

            case 5:
                cout << "\n " << BST.getRoot()->data << endl;
                cin.get();
                break;

            default:
                break;
        }
    } while (opt != 0);
    return 0;
}