#pragma once
#include <string>

using namespace std;

// enum to store color for red black tree
enum Color { red, black };

// struct for node in RBT
struct NodeRB {

	int rsid;

	// string of nucleobase
	string nu;

	// color of node
	bool color;

	// parent and childs nodes
	NodeRB* parent;
	NodeRB* left;
	NodeRB* right;
	
	//constructor for red node
	NodeRB(int rs, string n) : rsid(rs), nu(n), color(red), parent(nullptr), left(nullptr), right(nullptr) {};
};


// RBT class
class RBT {

public:
	NodeRB* root;
	vector<string> RBTtraits;
	RBT() :root(nullptr) {};
	NodeRB* insert(NodeRB* root, int rs, string n);
	void fixInsert(NodeRB* node);

	NodeRB* getUncle(NodeRB* node);

	void rotateLeft(NodeRB* node);
	void rotateRight(NodeRB* node);
	
	vector<string> searchRBT(NodeRB* r, vector<int> rsid);

};
