#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* node = new Node;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* searchElement(Node* root, int target) {
    if (root == nullptr || root->value == target) {
        return root;
    }
    Node* leftResult = searchElement(root->left, target);
    if (leftResult != nullptr) {
        return leftResult;
    }
    Node* rightResult = searchElement(root->right, target);
    return rightResult;
}

int main(int argc, char const *argv[]) {
    Node* root = nullptr;
    int n, value, target;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the values of nodes:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }
    cout << "Enter the value to search: ";
    cin >> target;
    Node* result = searchElement(root, target);
    if (result != nullptr) {
        cout << "Element found in the binary tree." << endl;
    } else {
        cout << "Element not found in the binary tree." << endl;
    }

    // Don't forget to free the memory used by the tree nodes to avoid memory leaks.
    // You can add a function to free the tree nodes if needed.

    return 0;
}
