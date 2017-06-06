//Example program to illustrate the operation to calculate the Height of binary tree.
// This programm uses recursion technique to calculat the height.
//Author - Indeep Singh
//Date = 06/06/2017

#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

//structure of a BST
struct BST{
	int data;
	BST* left;
	BST* right;
};

//method to create a new node.
BST* GetNewNode(int value){
	BST* newNode = new BST();
	newNode->data = value;
	newNode->left = newNode->right = NULL;
	
	return newNode;
}

//method to insert the newly created node.
BST* InsertNode(int value, BST* root){
	if(root == NULL){
		root = GetNewNode(value);
	} else if(value <= root->data){
		root->left = InsertNode(value,root->left);
	} else {
		root->right = InsertNode(value,root->right);
	}
	
	return root;
}

//method to calculate the heigh of tree using recursion technique.
int BSTHeight(BST* root){
	if(root == NULL){
		return -1;
	} 
	
	return max(BSTHeight(root->left), BSTHeight(root->right)) +1;
}

int main(){
	BST* root = NULL;
	cout<<"Heigh of tree when no node is inserted is ->" << BSTHeight(root);
	
	root = InsertNode(10, root);
	cout<<"\n Height of tree when there is only root node present -> " << BSTHeight(root); //since there is onlyt root node present, no edge is there i.e. height is 0.
	
	root = InsertNode(15, root);
	root = InsertNode(20,root);
	root = InsertNode(25,root);
	root = InsertNode(35,root);
	root = InsertNode(8,root);
	
	cout<<"\n Height of tree is -> " << BSTHeight(root); 
	return 0;
}	
