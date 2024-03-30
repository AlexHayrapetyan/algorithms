#include <stdio.h>
#include <stdlib.h>

//insertion function
struct node {
	int key;
	struct node *left, *right;
};

struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

struct node* insert(struct node* node, int key)
{
	if (node == NULL){
		return newNode(key);
    }
	if (key < node->key){
		node->left = insert(node->left, key);
    }
	else if (key > node->key){
		node->right = insert(node->right, key);
    }
	return node;
}

int main()
{

	struct node* root = NULL;
	root = insert(root, 50);
	insert(root, 10);
	insert(root, 50);
	insert(root, 60);
	insert(root, 20);
	insert(root, 90);
	insert(root, 40);
	inorder(root);

	return 0;
}

//search function

struct node {
	int key;
	struct node *left, *right;
};

struct node* newNode(int item)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct node* insert(struct node* node, int key)
{
	if (node == NULL){
		return newNode(key);
    }
	if (key < node->key){
		node->left = insert(node->left, key);
    }
	else if (key > node->key){
		node->right = insert(node->right, key);
    }
	return node;
}

struct node* search(struct node* root, int key)
{
	if (root == NULL || root->key == key){
		return root;
    }
	if (root->key < key){
		return search(root->right, key);
    }
	return search(root->left, key);
}

int main()
{
	struct node* root = NULL;
	root = insert(root, 50);
	insert(root, 10);
	insert(root, 40);
	insert(root, 30);
	insert(root, 60);
	insert(root, 70);
	insert(root, 90);

	int key = 6;

	if (search(root, key) == NULL){
		printf("%d not found\n", key);
    }
	else{
		printf("%d found\n", key);
    }
	key = 60;

	if (search(root, key) == NULL){
		printf("%d not found\n", key);
    }
	else{
		printf("%d found\n", key);
    }
	return 0;
}

//deletion function

struct Node {
	int key;
	struct Node *left, *right;
};

struct Node* newNode(int item)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct Node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

struct Node* insert(struct Node* node, int key)
{
	if (node == NULL){
		return newNode(key);
    }
	if (key < node->key){
		node->left = insert(node->left, key);
    }
	else{
		node->right = insert(node->right, key);
    }
	return node;
}

struct Node* deleteNode(struct Node* root, int k)
{
	if (root == NULL){
		return root;
    }
	if (root->key > k) {
		root->left = deleteNode(root->left, k);
		return root;
	}
	else if (root->key < k) {
		root->right = deleteNode(root->right, k);
		return root;
	}

	if (root->left == NULL) {
		struct Node* temp = root->right;
		free(root);
		return temp;
	}
	else if (root->right == NULL) {
		struct Node* temp = root->left;
		free(root);
		return temp;
	}
	else {

		struct Node* succParent = root;

		struct Node* succ = root->right;
		while (succ->left != NULL) {
			succParent = succ;
			succ = succ->left;
		}

		if (succParent != root){
			succParent->left = succ->right;
        }
		else{
			succParent->right = succ->right;
        }
		root->key = succ->key;
		free(succ);
		return root;
	}
}

int main()
{
	struct Node* root = NULL;
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 30);
	root = insert(root, 60);
	root = insert(root, 90);

	printf("Original BST: ");
	inorder(root);

	printf("\n\nDelete a Leaf Node: 20\n");
	root = deleteNode(root, 20);
	printf("Modified BST tree after deleting Leaf Node:\n");
	inorder(root);

	printf("\n\nDelete Node with single child: 70\n");
	root = deleteNode(root, 70);
	printf("Modified BST tree after deleting single child Node:\n");
	inorder(root);

	printf("\n\nDelete Node with both child: 50\n");
	root = deleteNode(root, 50);
	printf("Modified BST tree after deleting both child Node:\n");
	inorder(root);

	return 0;
}
