#include <iostream>
#include <string>
using namespace std;

int fibonacciSearch(string books[], int n, string key) {
  int fib2 = 0, fib1 = 1, fib = fib1 + fib2;
  int offset = -1;

  while (fib < n) {
    fib2 = fib1;
    fib1 = fib;
    fib = fib1 + fib2;
  }

  while (fib > 1) {
    int i = min(offset + fib2, n - 1);

    if (books[i] < key) {
      fib = fib1;
      fib1 = fib2;
      fib2 = fib - fib1;
      offset = i;
    } else if (books[i] > key) {
      fib = fib2;
      fib1 = fib1 - fib2;
      fib2 = fib - fib1;
    } else {
      return i;
    }
  }

  if (fib1 && books[offset + 1] == key)
    return offset + 1;

  return -1;
}

int main() {
  string books[] = {"Computer Networks", "Data Structures",
                    "Design and Analysis of Algorithms", "Operating Systems",
                    "Software Engineering"};

  int n = 5;
  string key = "Design and Analysis of Algorithms";

  int result = fibonacciSearch(books, n, key);

  if (result != -1)
    cout << "Book found at position: " << result + 1;
  else
    cout << "Book not found";

  return 0;
}
