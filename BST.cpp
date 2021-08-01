#pragma
#include "BST.h"
#include <iostream>
using namespace std;
BST::BST() {
    this->root = nullptr;
    Node();
}

BST::Node::Node() {
    this->left = nullptr;
    this->right = nullptr;
    this->rsid = 0;
    this->result = "";
}

BST::Node::Node(int rs, string res) {
    this->rsid = rs;
    this->result = res;
}

BST::Node* BST::insertNode(BST::Node *r, int rsid, string letters) {           //root should be passed in always
    cout << "got to insertNode function " << endl;
    if(root == nullptr){                                                 //the tree is empty
        Node* n = new Node(rsid, letters);
        root = n;
        return root;
    }
    if(r == nullptr){                                                   //insert here
        Node* n = new Node(rsid, letters);
    }
    if(rsid < r->rsid){
        r->left = insertNode(r->left, rsid, letters);
    }
    else{
        r->right = insertNode(r->right, rsid, letters);
    }
}

void BST::searchBST(BST::Node *r) {

    /// trait : rsid
    ///gender : 7620511
    ///eyes : 4959788
    ///hair : 6549120
    ///personality : 952399

    vector<int> searchThese;
    searchThese.push_back(7620511);
    searchThese.push_back(4959788);
    searchThese.push_back(6549120);
    searchThese.push_back(952399);
    int i = 0;
    while(traits.size() < 4) {
        if(r->rsid == searchThese.at(i)){
            traits.push_back(r->result);
            continue;
        }
        if(r->rsid < searchThese.at(i)){
            r = r->right;
            continue;
        }
        if(r->rsid > searchThese.at(i)){
            r = r->left;
            continue;
        }
        i++;
    }
}







