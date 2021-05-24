#include <iostream>

#include "BinarySearchTree.h"

using namespace std;

int main() {
    BinarySearchTree BST;
    int opt;
    do {
        cout << " +--------[Binary Search Tree]--------+\n"
                " | 1. Insert                          |\n"
                " | 2. Inorder                         |\n"
                " | 3. Postorder                       |\n"
                " | 4. Delete Node                     |\n"
                " | 5. <FOR CHECKING ROOT DATA>        |\n"
                " | 0. Exit                            |\n"
                " +------------------------------------+\n"
                "   >> ";
        if (!(cin >> opt)) {
            opt = -1;
            cin.clear();
            cin.ignore(256, '\n');
        }
        cin.get();

        switch (opt) {
            case 1: {
                string data;
                cout << " Masukkan string: ";
                cin >> data;
                BST.setRoot(BST.insert(BST.getRoot(), data));
                break;
            }

            case 2: {
                BST.inOrder(BST.getRoot());
                break;
            }

            case 3:
                BST.postOrder(BST.getRoot());
                break;

            case 4: {
                string data;
                cout << "Masukkan string yang ingin dihapus: ";
                cin >> data;
                BST.delNode(BST.getRoot(), data);
                break;
            }

            case 5:
                cout << BST.getRoot()->data << endl;
                break;

            default:
                break;
        }
    } while (opt != 0);
    return 0;
}