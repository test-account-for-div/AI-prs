#include <iostream>
using namespace std;
struct student {
  string name;
  int rn;
  int m1;
  int m2;
  int m3;
  int total;
};
void accept_data(student s1[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "Enter Student Name : ";
    cin >> s1[i].name;
    cout << "Enter Student Roll No : ";
    cin >> s1[i].rn;
    cout << "Enter Subject 1 Mark : ";
    cin >> s1[i].m1;
    cout << "Enter Subject 2 Mark : ";
    cin >> s1[i].m2;
    cout << "Enter Subject 3 Mark : ";
    cin >> s1[i].m3;
    s1[i].total = s1[i].m1 + s1[i].m2 + s1[i].m3;
    cout << endl;
  }
}
void display(student s1[], int n) {
  cout << "\nStudent Data";
  cout << "\n***********************************\n";
  for (int i = 0; i < n; i++) {
    cout << "Student Name : " << s1[i].name << endl;
    cout << "Student Roll No : " << s1[i].rn << endl;
    cout << "Total Marks : " << s1[i].total << endl;
    cout << "-----------------------------\n";
  }
}
void merge(student s1[], int low, int mid, int high) {
  int i = low;
  int j = mid + 1;
  int k = 0;
  student temp[100];
  while (i <= mid && j <= high) {
    if (s1[i].total > s1[j].total)
      temp[k++] = s1[i++];
    else
      temp[k++] = s1[j++];
  }
  while (i <= mid)
    temp[k++] = s1[i++];
  while (j <= high)
    temp[k++] = s1[j++];
  for (i = low, k = 0; i <= high; i++, k++)
    s1[i] = temp[k];
}
void mergesort(student s1[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    mergesort(s1, low, mid);
    mergesort(s1, mid + 1, high);
    merge(s1, low, mid, high);
  }
}
int main() {
  int n;
  cout << "Enter Number of Students : ";
  cin >> n;
  student s1[100];
  accept_data(s1, n);
  cout << "\nBefore Sorting:";
  display(s1, n);
  mergesort(s1, 0, n - 1);
  cout << "\nAfter Sorting :";
  display(s1, n);
  return 0;
}
