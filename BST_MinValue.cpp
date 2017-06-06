//Example program to explain the operation to find the minimum value in a Binary Search Tree.
// In this , we have provided source code for the recursive as well as iterative approach to find the min value in a BST.

//Author - Indeep Singh
//Date - 06/06/2017

#include<iostream>
#include<stdio.h>

using namespace std;

//structure of a Binary Search Tree.
struct BST{
	int data;
	BST* left;
	BST* right;
};

//method to create a new Node of BST using the value provided by user.
BST* GetNewNode(int value){
	BST* newNode = new BST();
	newNode->data = value;
	newNode->right = NULL;
	newNode->left = NULL;
	
	return newNode;
}

//method to insert the newly created node at its relevant position according to the value it has.
BST* InsertValue(int value, BST* root){
	if(root == NULL){
		root = GetNewNode(value);
	} else if(value <= root->data){
		root->left = InsertValue(value, root->left);
	} else {
		root->right = InsertValue(value, root->right);
	}	
	return root;
}

//method to find the minimum value in BST suing iterative approach. 
//This approahc traverse the left side of the BST until unless leaf node is encountered. The left leaf node of a BST will be the minimum value, or the if there is only root node present,
// then it will be minimum value.
int FindMin(BST* root){
	int minValue = -1;
	if(root == NULL){
		cout<<"Tree is empty. ";
	} else{
			while(root->left != NULL){
				root = root->left;
			}
			minValue = root->data;
	}
	return minValue;
}

//method to find the minimum value in BST using recursive approach.
int FindMinRecursive(BST* root){
	int minValue = -1;
	if(root == NULL){
		cout<<"Tree is empty";
	} else if(root->left == NULL){
		minValue = root->data;
	} else{
		minValue=  FindMinRecursive(root->left);
	}
	
	return minValue;
}

int main(){
	BST* root = NULL;
	root = InsertValue(10, root);
	root = InsertValue(15, root);
	root = InsertValue(20,root);
	root = InsertValue(25,root);
	root = InsertValue(8,root);
	
	cout<<"\n Minimum value in tree using iteration is ->" << FindMin(root);
	cout<<"\n Minimum value in tree using recursion is ->" << FindMinRecursive(root);
	
	return 0;
}
