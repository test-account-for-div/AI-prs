#include <iostream>
using namespace std;

struct Node {
  int score;
  string name;
  Node *left;
  Node *right;
  int height;
};

int getHeight(Node *node) {
  if (node == NULL)
    return 0;
  return node->height;
}

int getBalance(Node *node) {
  if (node == NULL)
    return 0;
  return getHeight(node->left) - getHeight(node->right);
}

Node *createNode(string name, int score) {
  Node *node = new Node();
  node->name = name;
  node->score = score;
  node->left = node->right = NULL;
  node->height = 1;
  return node;
}

Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

  return x;
}

Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

  return y;
}

Node *insert(Node *node, string name, int score) {
  if (node == NULL)
    return createNode(name, score);

  if (score < node->score)
    node->left = insert(node->left, name, score);
  else if (score > node->score)
    node->right = insert(node->right, name, score);
  else
    return node; // duplicate scores ignored

  node->height = 1 + max(getHeight(node->left), getHeight(node->right));

  int balance = getBalance(node);

  if (balance > 1 && score < node->left->score)
    return rightRotate(node);

  if (balance < -1 && score > node->right->score)
    return leftRotate(node);

  if (balance > 1 && score > node->left->score) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && score < node->right->score) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

Node *minValueNode(Node *node) {
  Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

Node *deleteNode(Node *root, int score) {
  if (root == NULL)
    return root;

  if (score < root->score)
    root->left = deleteNode(root->left, score);
  else if (score > root->score)
    root->right = deleteNode(root->right, score);
  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      Node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;

      delete temp;
    } else {
      Node *temp = minValueNode(root->right);
      root->score = temp->score;
      root->name = temp->name;
      root->right = deleteNode(root->right, temp->score);
    }
  }

  if (root == NULL)
    return root;

  root->height = 1 + max(getHeight(root->left), getHeight(root->right));

  int balance = getBalance(root);

  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

void display(Node *root) {
  if (root == NULL)
    return;

  display(root->right); // reverse inorder
  cout << root->name << " - Score: " << root->score << endl;
  display(root->left);
}

int main() {
  Node *root = NULL;
  int choice;
  string name;
  int score;

  do {
    cout << "\n1.Insert Player\n2.Delete Player\n3.Display "
            "Leaderboard\n4.Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter player name: ";
      cin >> name;
      cout << "Enter score: ";
      cin >> score;
      root = insert(root, name, score);
      break;

    case 2:
      cout << "Enter score to delete: ";
      cin >> score;
      root = deleteNode(root, score);
      break;

    case 3:
      cout << "\nLeaderboard (Top Players):\n";
      display(root);
      break;

    case 4:
      cout << "Exiting...\n";
      break;

    default:
      cout << "Invalid choice!\n";
    }

  } while (choice != 4);

  return 0;
}