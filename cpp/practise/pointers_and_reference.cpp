#include<iostream>

using namespace std;

int* first (int* x)
{ (*x++);
  return x;   // SAFE, x is outside this scope
}

int& second (int& x)
{ x++;
  return x;   // SAFE, x is outside this scope
}

int& third ()
{ int q;
  return q;   // ERROR, scope of q ends here
}

int& fourth ()
{ static int x;
  return x;   // SAFE, x is static, hence lives till the end.
}

int main()
{
 int a=0;
 first(&a);   // UGLY and explicit
 third();
 second(a);   // CLEAN and hidden

 return 0;
}
