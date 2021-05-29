#include<cstring>

char *my_to_char(string s) {
  char *tmp = new char[100];
  strcpy(tmp, s.c_str());
  return tmp;
}
