#include "Array.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{

  Array<char> c(3);

  c.setValue(0,'c');

  c.setValue(1,'s');

  c.setValue(2,'c');

  cout << c << endl;
 

  Array<int> i(3);

  i.setValue(0,1);

  i.setValue(1,2);

  i.setValue(2,5);

  cout << i << endl;

  Array<int> j(3);

  j.setValue(0,10);

  j.setValue(1,20);

  j.setValue(2,50);

  cout << j << endl;

  Array<int> ij;

  ij = i + j;

  cout << ij << endl;

}
