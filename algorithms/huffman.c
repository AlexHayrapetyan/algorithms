#include <stdio.h> 
#include <stdlib.h>  
#define MAX_TREE_HT 100 

//encoding

struct MinHeapNode 
{ 
	char data; 
	unsigned freq; 
	struct MinHeapNode *left, *right; 
}; 

struct MinHeap 
{ 
	unsigned size; 
	unsigned capacity; 
	struct MinHeapNode** array; 
}; 

struct MinHeapNode* newNode(char data, unsigned freq) 
{ 
	struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode)); 

	temp->left = temp->right = NULL; 
	temp->data = data; 
	temp->freq = freq; 

	return temp; 
} 

struct MinHeap* createMinHeap(unsigned capacity) 
{ 
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap)); 
	minHeap->size = 0; 
	minHeap->capacity = capacity; 
	minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*)); 
	return minHeap; 
} 

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) 
{ 
	struct MinHeapNode* t = *a; *a = *b; *b = t; 
} 

void minHeapify(struct MinHeap* minHeap, int idx) 
{ 
	int smallest = idx; 
	int left = 2 * idx + 1; 
	int right = 2 * idx + 2; 

	if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
		smallest = left; 
    }
	if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
		smallest = right; 
    }
	if (smallest != idx) { 
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]); 
		minHeapify(minHeap, smallest); 
	} 
} 

int isSizeOne(struct MinHeap* minHeap) 
{ 
	return (minHeap->size == 1); 
} 

struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
{ 
	struct MinHeapNode* temp = minHeap->array[0]; 
	minHeap->array[0] = minHeap->array[minHeap->size - 1]; 
	--minHeap->size; 
	minHeapify(minHeap, 0); 

	return temp; 
} 

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) 
{ 
	++minHeap->size; 
	int i = minHeap->size - 1; 

	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)
    { 
		minHeap->array[i] = minHeap->array[(i - 1) / 2]; 
		i = (i - 1) / 2; 
	} 

	minHeap->array[i] = minHeapNode; 
} 

void buildMinHeap(struct MinHeap* minHeap) 
{ 
	int n = minHeap->size - 1; 
	int i; 

	for (i = (n - 1) / 2; i >= 0; --i){
		minHeapify(minHeap, i); 
    }
} 

void printArr(int arr[], int n) 
{ 
	int i; 
	for (i = 0; i < n; ++i){
		printf("%d", arr[i]); 
    }
	printf("\n"); 
} 

int isLeaf(struct MinHeapNode* root) 
{
	return !(root->left) && !(root->right); 
} 

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) 
{ 
	struct MinHeap* minHeap = createMinHeap(size); 
	for (int i = 0; i < size; ++i){
		minHeap->array[i] = newNode(data[i], freq[i]); 
    }
	minHeap->size = size; 
	buildMinHeap(minHeap); 

	return minHeap; 
} 

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) 
{ 
	struct MinHeapNode *left, *right, *top; 
	struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size); 

	while (!isSizeOne(minHeap)) { 
		left = extractMin(minHeap); 
		right = extractMin(minHeap); 
		top = newNode('$', left->freq + right->freq); 
		top->left = left; 
		top->right = right; 
		insertMinHeap(minHeap, top); 
	} 

	return extractMin(minHeap); 
} 
 
void printCodes(struct MinHeapNode* root, int arr[], int top) 
{ 
	if (root->left) { 
		arr[top] = 0; 
		printCodes(root->left, arr, top + 1); 
	} 
	if (root->right) { 
		arr[top] = 1; 
		printCodes(root->right, arr, top + 1); 
	} 
	if (isLeaf(root)) { 
		printf("%c: ", root->data); 
		printArr(arr, top); 
	} 
} 

void HuffmanCodes(char data[], int freq[], int size) 
{ 
	struct MinHeapNode* root = buildHuffmanTree(data, freq, size); 
	int arr[MAX_TREE_HT], top = 0; 
	printCodes(root, arr, top); 
} 

int main() 
{ 
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
	int freq[] = { 4, 5, 7, 89, 12, 54 }; 
	int size = sizeof(arr) / sizeof(arr[0]); 
	HuffmanCodes(arr, freq, size); 

	return 0; 
}

//decoding

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TREE_HT 256

struct MinHeapNode {
    char data;
    int freq;
    struct MinHeapNode *left, *right;
};

struct MinHeap {
    int size;
    int capacity;
    struct MinHeapNode** array;
};

struct MinHeapNode* newNode(char data, int freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity* sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq){
        smallest = left;
    }
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq){
        smallest = right;
    }
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i){
        minHeap->array[i] = newNode(data[i], freq[i]);
    }
    minHeap->size = size;
    for (int i = (minHeap->size - 1) / 2; i >= 0; --i){
        minHeapify(minHeap, i);
    }
    return minHeap;
}

int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

void buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    printCodes(minHeap->array[0], "", 0);
}

void printCodes(struct MinHeapNode* root, char arr[], int top) {
    if (root->left) {
        arr[top] = '0';
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = '1';
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i){
            printf("%c", arr[i]);
        }
        printf("\n");
    }
}

void decodeFile(struct MinHeapNode* root, char s[]) {
    struct MinHeapNode* curr = root;
    int i = 0;
    while (s[i]) {
        if (s[i] == '0'){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
        if (isLeaf(curr)){
            printf("%c", curr->data);
            curr = root;
        }
        ++i;
    }
    printf("\n");
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {4, 2, 21, 32, 89, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    buildHuffmanTree(arr, freq, size);
    return 0;
}
