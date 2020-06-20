#include <iostream>
#include <string>

#include "control.h"
using namespace std;
int main() {
  book book_root;
  CD cd_root;
  picture picture_root;
  admin ad;
  book b(102, "JAVA", "Tim", "成人", "高校出版社", "9-189-067", 600);
  book_root.Read();
  book_root.add(b);
  ad.DisplayAll(book_root, cd_root, picture_root);
  book_root.Write();
  return 0;
}