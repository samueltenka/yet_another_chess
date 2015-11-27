/* size_tests.cpp: how big are different numeric types
 * on this machine?
 */
#include <cstdio>
int main(int argc, char** argv) {
   bool b;
   char c;
   short s;
   int i;
   long l;
   long long ll;
   float f;
   double d;
   long double ld;

   printf("bool: %d\n", sizeof(b));
   printf("char: %d\n", sizeof(c));
   printf("short: %d\n", sizeof(s));
   printf("int: %d\n", sizeof(i));
   printf("long: %d\n", sizeof(l));
   printf("long long: %d\n", sizeof(ll));
   printf("float: %d\n", sizeof(f));
   printf("double: %d\n", sizeof(d));
   printf("long double: %d\n", sizeof(ld));
}
