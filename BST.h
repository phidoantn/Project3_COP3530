
#pragma
#include <string>
#include <vector>
using namespace std;


// nodes for tree class
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

// main tree class
class BST {

public:
    Node* root;
    BST() :root(nullptr) {};
    ~BST();
    vector<string> traits;

    // issert function
    Node* insertNode(Node* r, int rsid, string result);
    //search through tree
    void searchBST(Node* r, vector<int> rsid);
    void deleteTree(Node* r);

};
