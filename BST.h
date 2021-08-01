#pragma
#include <string>
#include <vector>
using namespace std;

class Node {
    public:
        int rsid;
        string result;
        Node* left;
        Node* right;
        Node():rsid(0),result(""), left(nullptr), right(nullptr) {};
        Node(int rs, string res) :rsid(rs), result(res), left(nullptr), right(nullptr) {};
        ~Node();
};
class BST {
    
public:
    Node* root;
    BST() :root(nullptr) {};
    ~BST();
    vector<string> traits;

    Node* insertNode(Node* r, int rsid, string result);
    //void searchBST(Node* r);

};


