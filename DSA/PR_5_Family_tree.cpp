#include <iostream>
using namespace std;

struct Node {
  string name;
  Node *left;  // left child
  Node *right; // right child

  Node(string n) {
    name = n;
    left = right = NULL;
  }
};

Node *createNode(string name) { return new Node(name); }

// Inorder Traversal (Left → Root → Right)
void inorder(Node *root) {
  if (root == NULL)
    return;

  inorder(root->left);
  cout << root->name << " ";
  inorder(root->right);
}

// Preorder Traversal (Root → Left → Right)
void preorder(Node *root) {
  if (root == NULL)
    return;

  cout << root->name << " ";
  preorder(root->left);
  preorder(root->right);
}

// Postorder Traversal (Left → Right → Root)
void postorder(Node *root) {
  if (root == NULL)
    return;

  postorder(root->left);
  postorder(root->right);
  cout << root->name << " ";
}

int main() {
  // Build family tree manually
  Node *root = createNode("Grandparent");

  root->left = createNode("Father");
  root->right = createNode("Uncle");

  root->left->left = createNode("Child1");
  root->left->right = createNode("Child2");

  root->right->left = createNode("Cousin1");
  root->right->right = createNode("Cousin2");

  cout << "Inorder Traversal (Generation-wise): ";
  inorder(root);

  cout << "\nPreorder Traversal (Root to Descendants): ";
  preorder(root);

  cout << "\nPostorder Traversal (Descendants to Root): ";
  postorder(root);

  return 0;
}
