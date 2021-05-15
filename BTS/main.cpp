#include "Header Files/BST.h"

using namespace std;

int main()
{

    BST<int> root;
    node<float> tst1;



    root.addNode(30);
    root.addNode(40);
    root.addNode(10);
    root.addNode(20);
    root.addNode(14);
    root.addNode(15);
    root.addNode(-1);
    root.addNode(33);
    root.addNode(63);

    root.inorderPrint();
    cout << "---------------------------------" << endl;
    root.postorderPrint();
    cout << "---------------------------------" << endl;
    root.preorderPrint();

    cout << "---------------------------------" << endl;
    cout << root.search(63)->getData() << endl;
    cout << "---------------------------------" << endl;
    cout << root.search(100) << endl;

    return 0;
}
