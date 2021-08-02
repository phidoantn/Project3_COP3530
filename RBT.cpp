#include "RBT.h"
#include <iostream>

using namespace std;

NodeRB* RBT::insert(NodeRB* root, int rs, string n)
{
	// insert empty tree
	if (root == nullptr)
	{
		NodeRB* node = new NodeRB(rs, n);
		node->color = black;
		root = node;
		return root;
	}

	// traverse and insert left
	if (rs < root->rsid)
	{
		root->left = insert(root->left, rs, n);
		root->left->parent = root;
	}


	// traverse and insert right
	else
	{
		root->right = insert(root->right, rs, n);
		root->right->parent = root;
	}

	// fix insert if needed 
	fixInsert(root);
	return root;

}

void RBT::fixInsert(NodeRB* node)
{
	// if node is tree root then it's black
	if (node->parent == nullptr) {
		node->color = black;
		
		return;
	}

	// if parent is black then return node
	else if (node->parent->color == black) {
		return;
	}
	else {
		// -----------fix tree if parent is red

		// geting node's family
		NodeRB* parent = node->parent;
		NodeRB* grand = node->parent->parent;
		NodeRB* uncle = getUncle(node);

	

		// red parent has red sibling
		if (uncle != nullptr && uncle->color == red) {
			parent->color = uncle->color = black;
			grand->color = red;
			fixInsert(grand);
			return;
		}

		// no red uncle: left right
		if (node == parent->right && parent == grand->left) {
			rotateLeft(parent);
			node = parent;
			parent = node->parent;


		}

		// right left imbalance
		else if (node == parent->left && parent == grand->right) {
			rotateRight(parent);
			node = parent;
			parent = node->parent;

		}

		parent->color = black;
		grand->color = red;
		if (node == parent->left)
			rotateRight(grand);
		else
			rotateLeft(grand);
	}
}

NodeRB* RBT::getUncle(NodeRB* node)
{
	// if parent is left then return the right child of grand, otherwise return left child.
	if (node->parent == node->parent->parent->left)
		return node->parent->parent->right;
	else
		return node->parent->parent->left;



}


void RBT::rotateLeft(NodeRB* node)
{
	NodeRB* grandChild = node->right->left;
	NodeRB* newParent = node->right;
	newParent->left = node;
	node->right = grandChild;
	
}

void RBT::rotateRight(NodeRB* node)
{
	NodeRB* grandChild = node->left->right;
	NodeRB* newParent = node->left;
	newParent->right = node;
	node->left = grandChild;
	


}

void RBT::searchRBT(NodeRB* r, vector<int> searchThese)
{
	int i = 0;
	while (traits.size() < 4) {
		if (r->rsid == searchThese.at(i)) {
			traits.push_back(r->nu);
			i++;
			r = root;
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
	}
}

void RBT::printIn(NodeRB* root)
{
	if (root == nullptr)
		return;
	else
	{
		printIn(root->left);
		cout << root->rsid << " ";
		printIn(root->right);

	}
}

void RBT::printPre(NodeRB* root)
{
	if (root == nullptr)
		return;
	else
	{
		cout << root->rsid << " ";
		printIn(root->left);
		printIn(root->right);

	}
}
