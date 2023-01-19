// # Assignment-13 -> Frequency Count
// # using STL map
// # O(n)
#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
  int n, i;
  cout << "\n# Enter number of elements in an array: ";
  cin >> n;
  int *a = new int[n];
  map<int, int> m;
  cout << "\n# Enter array:\n  ";
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    m[a[i]]++;
  }
  cout << "\nkey" << setw(10) << "count" << endl;
  map<int, int>::iterator it;
  for (it = m.begin(); it != m.end(); ++it)
  {
    cout << it->first << setw(10) << it->second << endl;
  }
  return 0;
}