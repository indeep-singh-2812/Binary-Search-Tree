//Example programm to explain In order traversal operation for a Binary Search Tree.

//Author - Indeep Singh
//Date - 07/06/2017

#include<iostream>
#include<stdio.h>

using namespace std;

//structure of a Binary Search Tree.
struct BST{
	char data;
	BST* left;
	BST* right;
};

//method to create a new Node of BST using the value provided by user.
BST* GetNewNode(char value){
	BST* newNode = new BST();
	newNode->data = value;
	newNode->right = NULL;
	newNode->left = NULL;
	
	return newNode;
}

//method to insert the newly created node at its relevant position according to the value it has.
BST* InsertValue(char value, BST* root){
	if(root == NULL){
		root = GetNewNode(value);
	} else if(value <= root->data){
		root->left = InsertValue(value, root->left);
	} else {
		root->right = InsertValue(value, root->right);
	}	
	return root;
}

//method to traverse BST in in-order manner. For Pre order traversal, we first travel left child node, then we go to root node and then right child node.
void Inorder(BST* root){
	if(root == NULL)
		return;
		
	Inorder(root->left);
	cout<<root->data<<"\t";
	Inorder(root->right);
}

int main(){
	BST* root = NULL;
	root = InsertValue('F',root);
	root = InsertValue('D',root);
	root = InsertValue('B',root);
	root = InsertValue('E',root);
	root = InsertValue('A',root);
	root = InsertValue('C',root);
	root = InsertValue('J',root);
	root = InsertValue('H',root);
	
	Inorder(root);
	return 0;
}
