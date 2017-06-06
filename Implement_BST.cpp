//Example program to explain the implementation of Binary Search Tree. In this example , we have used recursion technique for traversing our binary search tree.
//Author - Indeep Singh
//Date - 06/06/2017


#include<iostream>
#include<stdio.h>

using namespace std;

//defining the structure of Binary Search Tree. It will contain one data element, and 2 pointer to node elements pointing left and right child nodes of a parent node.
struct BST{
	int data;
	BST* left;
	BST* right;
};

//method to create a new node for BST with the value provided by the user.
BST* GetNewNode(int value){
	BST* newNode = new BST();
	newNode->data = value;
	newNode->right = NULL;
	newNode->left = NULL;
	
	return newNode;
}

//method to insert the node in the tree according to the value associated with it.
//If the value is less than root node, it will be inserted as left node else it will be inserted as right node.
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

//method to perform search operation for a node value. 
bool SearchData(BST* root, int value){
	if(root == NULL){
		return false;
	} else if(root->data == value){
		return true;
	} else if(value <= root->data){
		return SearchData(root->left, value);
	} else {
		return SearchData(root->right, value);
	}
}

int main(){
	BST* root = NULL;
	
	//We will keep a reference to root node of our binary search tree. Thats why we have returned pointer to root node from our insert method.
	root = InsertValue(10, root); 
	root = InsertValue(15, root);
	root = InsertValue(20,root);
	root = InsertValue(25,root);
	
	int number;
	cout<<"Enter number to search -";
	cin>>number;
	
	if(SearchData(root,number)){
		cout<<"Value found \n";
	} else{
		cout<<"Value not found \n";
	}
	
	return 0;
}
