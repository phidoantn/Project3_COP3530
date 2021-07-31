#include "BST.h"

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




