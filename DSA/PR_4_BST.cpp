
#include <iostream>
using namespace std;

// Node structure
struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int value) {
    data = value;
    left = right = NULL;
  }
};

// Insert function
Node *insert(Node *root, int value) {
  if (root == NULL)
    return new Node(value);

  if (value < root->data)
    root->left = insert(root->left, value);
  else if (value > root->data)
    root->right = insert(root->right, value);

  return root;
}

// Search function
bool search(Node *root, int value) {
  if (root == NULL)
    return false;

  if (root->data == value)
    return true;
  else if (value < root->data)
    return search(root->left, value);
  else
    return search(root->right, value);
}

// Find minimum node (used in delete)
Node *findMin(Node *root) {
  while (root->left != NULL)
    root = root->left;
  return root;
}

// Delete function
Node *deleteNode(Node *root, int value) {
  if (root == NULL)
    return NULL;

  if (value < root->data)
    root->left = deleteNode(root->left, value);
  else if (value > root->data)
    root->right = deleteNode(root->right, value);
  else {
    // Case 1: No child
    if (root->left == NULL && root->right == NULL) {
      delete root;
      return NULL;
    }
    // Case 2: One child
    else if (root->left == NULL) {
      Node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == NULL) {
      Node *temp = root->left;
      delete root;
      return temp;
    }
    // case 3:Two Children
    else {
      Node *temp = findMin(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }
  return root;
}

// Count total nodes
int countNodes(Node *root) {
  if (root == NULL)
    return 0;

  return 1 + countNodes(root->left) + countNodes(root->right);
}

// Display (Inorder Traversal)
void display(Node *root) {
  if (root != NULL) {
    display(root->left);
    cout << root->data << " ";
    display(root->right);
  }
}

int main() {
  Node *root = NULL;
  int choice, value;

  do {
    cout << "\n--- BST Menu ---\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Search\n";
    cout << "4. Count Total Nodes\n";
    cout << "5. Display (Inorder)\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter value to insert: ";
      cin >> value;
      root = insert(root, value);
      break;

    case 2:
      cout << "Enter value to delete: ";
      cin >> value;
      root = deleteNode(root, value);
      break;

    case 3:
      cout << "Enter value to search: ";
      cin >> value;
      if (search(root, value))
        cout << "Value found in BST\n";
      else
        cout << "Value not found\n";
      break;

    case 4:
      cout << "Total nodes in BST: " << countNodes(root) << endl;
      break;

    case 5:
      cout << "BST elements (Inorder): ";
      display(root);
      cout << endl;
      break;

    case 6:
      cout << "Exiting program...\n";
      break;

    default:
      cout << "Invalid choice!\n";
    }

  } while (choice != 6);

  return 0;
}
