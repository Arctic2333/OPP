#include <iostream>
#include <string>

#include "control.h"
using namespace std;
int main() {
  book book_root;
  CD cd_root;
  picture picture_root;
  admin ad;
  book b1(100, "安徒生", "anti", "ch", "chiled", "9-189-067", 50);
  book b2(101, "geling", "geli", "ch", "jixie", "9-189-067", 50);
  book b3(102, "xiaowang", "xiao", "ch", "jixie", "9-189-067", 50);
  book_root.add(b1);
  book_root.add(b2);
  book_root.add(b3);
  book_root.displayAll();
  ad.DisplayAll(book_root,cd_root,picture_root);
  ad.search(102,book_root,cd_root,picture_root);
  ad.search("安徒生",book_root,cd_root,picture_root);
  ad.search("图书",1,book_root,cd_root,picture_root);
  book_root.Delete(100);
  ad.DisplayAll(book_root,cd_root,picture_root);
  return 0;
}