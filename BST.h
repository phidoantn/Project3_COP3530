#include <string>
using namespace std;

class BST {
    class Node {
    public:
        int rsid;
        string result;
        Node* left;
        Node* right;
        Node();
        Node(int rs, string res);
    };
public:
    Node* root;
    BST();
    Node* insertNode(Node* r, int rsid, string result);

};



