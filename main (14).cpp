#include <iostream>
#include <vector>
using namespace std;

// Node structure for the tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Tree Class
class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    // Insert nodes into the binary tree in level-order
    void insert(Node*& node, int value) {
        if (!node) {
            node = new Node(value);
            return;
        }

        if (value < node->data)
            insert(node->left, value);
        else
            insert(node->right, value);
    }

    void insert(int value) {
        insert(root, value);
    }

    // In-order traversal to print the tree
    void inOrder(Node* node) {
        if (node) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void displayInOrder() {
        inOrder(root);
        cout << "\n";
    }
};

// AVL Tree Class
class AVLTree {
public:
    // Get the height of the tree
    int height(Node* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    // Calculate the balance factor of a node
    int getBalanceFactor(Node* node) {
        if (!node) return 0;
        return height(node->left) - height(node->right);
    }

    // Right rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        return x;
    }

    // Left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        return y;
    }

    // Insert a node into the AVL tree and balance it
    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            return node; // Duplicate values are not allowed

        // Balance the node
        int balanceFactor = getBalanceFactor(node);

        // Left-heavy
        if (balanceFactor > 1) {
            if (value < node->left->data) {
                return rightRotate(node); // Left-Left case
            } else {
                node->left = leftRotate(node->left); // Left-Right case
                return rightRotate(node);
            }
        }

        // Right-heavy
        if (balanceFactor < -1) {
            if (value > node->right->data) {
                return leftRotate(node); // Right-Right case
            } else {
                node->right = rightRotate(node->right); // Right-Left case
                return leftRotate(node);
            }
        }

        return node;
    }

    // Convert Binary Tree to AVL Tree
    Node* convertToAVL(Node* root) {
        if (!root) return nullptr;

        vector<int> values;
        inOrderTraversal(root, values);

        return buildAVL(values, 0, values.size() - 1);
    }

private:
    // Perform in-order traversal and collect values
    void inOrderTraversal(Node* node, vector<int>& values) {
        if (node) {
            inOrderTraversal(node->left, values);
            values.push_back(node->data);
            inOrderTraversal(node->right, values);
        }
    }

    // Build AVL tree from sorted values
    Node* buildAVL(const vector<int>& values, int start, int end) {
        if (start > end) return nullptr;

        int mid = (start + end) / 2;
        Node* node = new Node(values[mid]);

        node->left = buildAVL(values, start, mid - 1);
        node->right = buildAVL(values, mid + 1, end);

        return node;
    }
};

// Main function
int main() {
    BinaryTree bt;
    AVLTree avlTree;

    // Insert values into binary tree
    bt.insert(30);
    bt.insert(20);
    bt.insert(40);
    bt.insert(10);
    bt.insert(25);
    bt.insert(35);
    bt.insert(50);

    cout << "Binary Tree (In-order Traversal):\n";
    bt.displayInOrder();

    // Convert binary tree to AVL tree
    Node* avlRoot = avlTree.convertToAVL(bt.root);

    cout << "AVL Tree (In-order Traversal):\n";
    bt.inOrder(avlRoot);
    cout << "\n";

    return 0;
}

       
