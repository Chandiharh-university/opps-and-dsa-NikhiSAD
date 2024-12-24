
#include <iostream>
using namespace std;

// Define a Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to create a binary tree
Node* createBinaryTree() {
    Node* root = new Node(1);   // Root node
    root->left = new Node(2);   // Left child of root
    root->right = new Node(3);  // Right child of root

    root->left->left = new Node(4);  // Left child of node 2
    root->left->right = new Node(5); // Right child of node 2

    root->right->left = new Node(6); // Left child of node 3
    root->right->right = new Node(7); // Right child of node 3

    return root;
}

// Function for Pre-Order Traversal (Root -> Left -> Right)
void preOrderTraversal(Node* node) {
    if (node == nullptr) return;

    cout << node->data << " "; // Visit root
    preOrderTraversal(node->left);  // Visit left subtree
    preOrderTraversal(node->right); // Visit right subtree
}

// Function for In-Order Traversal (Left -> Root -> Right)
void inOrderTraversal(Node* node) {
    if (node == nullptr) return;

    inOrderTraversal(node->left);  // Visit left subtree
    cout << node->data << " ";     // Visit root
    inOrderTraversal(node->right); // Visit right subtree
}

// Function for Post-Order Traversal (Left -> Right -> Root)
void postOrderTraversal(Node* node) {
    if (node == nullptr) return;

    postOrderTraversal(node->left);  // Visit left subtree
    postOrderTraversal(node->right); // Visit right subtree
    cout << node->data << " ";       // Visit root
}

int main() {
    // Create a binary tree
    Node* root = createBinaryTree();

    // Perform different traversals
    cout << "Pre-Order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Post-Order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
