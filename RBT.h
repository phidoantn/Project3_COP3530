#pragma once
#include <string>
#include <vector>
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
	vector<string> traits;

	RBT() :root(nullptr) {};

	NodeRB* insert(NodeRB* root, int rs, string n);

	// fix tree if needed after insertion
	void fixInsert(NodeRB* node);

	// return uncle node
	NodeRB* getUncle(NodeRB* node);

	// rotate tree if needed
	void rotateLeft(NodeRB* node);
	void rotateRight(NodeRB* node);


	void searchRBT(NodeRB* r, vector<int> searchThese);

	// prints for debugging
	void printIn(NodeRB* root);
	void printPre(NodeRB* root);
};
