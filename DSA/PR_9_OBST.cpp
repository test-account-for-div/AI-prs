#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Product {
  int id;
  int freq;
};

struct Node {
  Product data;
  Node *left;
  Node *right;
};

Node *createNode(Product p) {
  Node *temp = new Node();
  temp->data = p;
  temp->left = temp->right = NULL;
  return temp;
}

bool compareProduct(Product a, Product b) { return a.id < b.id; }

Node *buildOBST(vector<Product> &products, int start, int end) {
  if (start > end)
    return NULL;

  int maxIndex = start;
  for (int i = start + 1; i <= end; i++) {
    if (products[i].freq > products[maxIndex].freq)
      maxIndex = i;
  }

  Node *root = createNode(products[maxIndex]);

  root->left = buildOBST(products, start, maxIndex - 1);
  root->right = buildOBST(products, maxIndex + 1, end);

  return root;
}

void inorder(Node *root) {
  if (root == NULL)
    return;

  inorder(root->left);
  cout << "Product ID: " << root->data.id << " | Frequency: " << root->data.freq
       << endl;
  inorder(root->right);
}
void insertProduct(vector<Product> &products) {
  Product p;
  cout << "Enter Product ID: ";
  cin >> p.id;
  cout << "Enter Purchase Frequency: ";
  cin >> p.freq;

  products.push_back(p);

  sort(products.begin(), products.end(), compareProduct);

  cout << "Product inserted successfully.\n";
}

void deleteProduct(vector<Product> &products) {
  int id;
  cout << "Enter Product ID to delete: ";
  cin >> id;

  for (int i = 0; i < products.size(); i++) {
    if (products[i].id == id) {
      products.erase(products.begin() + i);
      cout << "Product deleted successfully.\n";
      return;
    }
  }

  cout << "Product not found.\n";
}

int main() {
  vector<Product> products;
  Node *root = NULL;
  int choice;

  do {
    cout << "\n--- Inventory Menu ---\n";
    cout << "1. Insert Product\n";
    cout << "2. Delete Product\n";
    cout << "3. Display (OBST)\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {

    case 1:
      insertProduct(products);
      break;

    case 2:
      deleteProduct(products);
      break;

    case 3:
      if (products.empty()) {
        cout << "No products available.\n";
        break;
      }
      root = buildOBST(products, 0, products.size() - 1);
      cout << "\nProducts in sorted order:\n";
      inorder(root);
      break;

    case 4:
      cout << "Exiting...\n";
      break;

    default:
      cout << "Invalid choice\n";
    }

  } while (choice != 4);

  return 0;
}
