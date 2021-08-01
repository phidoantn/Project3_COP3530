#include "BST.h"
#include <iostream>


using namespace std;

BST::~BST()
{
	delete root;
}

Node* BST::insertNode(Node* r, int rsid, string letters) {

	// base case
	if (r == nullptr) {
		return new Node(rsid, letters);
	};

	// if id already there
	if (r->rsid == rsid)
		return r;

	else if (rsid < r->rsid) {
		r->left = insertNode(r->left, rsid, letters);
	}
	else {
		r->right = insertNode(r->right, rsid, letters);
	}
	cout << "got to insertNode function " << endl;
	return r;
}
/*
void BST::searchBST(BST::Node* r) {

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
	while (traits.size() < 4) {
		if (r->rsid == searchThese.at(i)) {
			traits.push_back(r->result);
			continue;
		}
		if (r->rsid < searchThese.at(i)) {
			r = r->right;
			continue;
		}
		if (r->rsid > searchThese.at(i)) {
			r = r->left;
			continue;
		}
		i++;
	}
}
*/

Node::~Node()
{
	delete left;
	delete right;
}
