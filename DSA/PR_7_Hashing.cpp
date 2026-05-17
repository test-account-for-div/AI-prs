#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

struct Employee {
  int id;
  string name;
  float salary;
};

struct Node {
  Employee data;
  Node *next;
};

class HashTable {
private:
  Node *table[TABLE_SIZE];

public:
  HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
      table[i] = NULL;
  }

  int hashFunction(int id) { return id % TABLE_SIZE; }

  void insert() {
    Employee emp;
    cout << "Enter ID: ";
    cin >> emp.id;
    cout << "Enter Name: ";
    cin >> emp.name;
    cout << "Enter Salary: ";
    cin >> emp.salary;

    int index = hashFunction(emp.id);

    Node *newNode = new Node();
    newNode->data = emp;
    newNode->next = table[index];

    table[index] = newNode;

    cout << "Employee inserted successfully!\n";
  }

  void search(int id) {
    int index = hashFunction(id);
    Node *temp = table[index];

    while (temp != NULL) {
      if (temp->data.id == id) {
        cout << "Found -> ID: " << temp->data.id
             << ", Name: " << temp->data.name
             << ", Salary: " << temp->data.salary << endl;
        return;
      }
      temp = temp->next;
    }

    cout << "Employee not found!\n";
  }

  void deleteEmp(int id) {
    int index = hashFunction(id);
    Node *temp = table[index];
    Node *prev = NULL;

    while (temp != NULL) {
      if (temp->data.id == id) {
        if (prev == NULL)
          table[index] = temp->next;
        else
          prev->next = temp->next;

        delete temp;
        cout << "Employee deleted successfully!\n";
        return;
      }
      prev = temp;
      temp = temp->next;
    }

    cout << "Employee not found!\n";
  }

  void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
      cout << "\nIndex " << i << ": ";
      Node *temp = table[i];

      while (temp != NULL) {
        cout << "[ID:" << temp->data.id << ", " << temp->data.name << "] -> ";
        temp = temp->next;
      }
      cout << "NULL";
    }
    cout << endl;
  }
};

int main() {
  HashTable ht;
  int choice, id;

  do {
    cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      ht.insert();
      break;

    case 2:
      cout << "Enter ID to search: ";
      cin >> id;
      ht.search(id);
      break;

    case 3:
      cout << "Enter ID to delete: ";
      cin >> id;
      ht.deleteEmp(id);
      break;

    case 4:
      ht.display();
      break;

    case 5:
      cout << "Exiting...\n";
      break;

    default:
      cout << "Invalid choice!\n";
    }

  } while (choice != 5);

  return 0;
}
