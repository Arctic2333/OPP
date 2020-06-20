#ifndef CONTROL_H
#define CONTROL_H
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

#include "model.h"
using namespace std;
class book;
class CD;
class picture;
class admin;  // 提前声明类 以便后面使用
class book : public goods {
 private:
  string publisher;  // 出版社
  string ISBN;       // ISBN号
  int page;          // 页数
 public:
  book(int id, string t, string a, string g, string p, string isbn, int pa) {
    this->setID(id);
    this->setTitle(t);
    this->setAuthor(a);
    this->setGrade(g);
    this->publisher = p;
    this->ISBN = isbn;
    this->page = pa;
  }
  friend class admin;  // 声明友元类
  list<book> li_book;  // stl
  list<book>::iterator i_book;
  void add(book a);  // 多态
  void Output();     // 重载父类的Output
  void displayAll();
  int judgeID(int a);
};
void book::add(book a) { this->li_book.push_back(a); }
void book::Output() {
  cout << "ID：" << this->getID() << "  Title：" << this->getTitle()
       << "  Author：" << this->getAuthor() << "  Grade：" << this->getGrad()
       << "  Publisher：" << this->publisher << "  ISBN：" << this->ISBN
       << "  Page：" << this->page << endl;
}
int book::judgeID(int a) {
  int flag = 0;
  for (this->i_book = this->li_book.begin();
       this->i_book != this->li_book.end(); this->i_book++) {
    if (this->getID() == a) {
      flag = 1;
      break;
    }
  }
  return flag;
}
void book::displayAll() {
  for (this->i_book = this->li_book.begin();
       this->i_book != this->li_book.end(); this->i_book++) {
    this->i_book->Output();
  }
}

class CD : public goods {
 private:
  string publisher;  // 出品人
  int year;          // 出品年
  int time_len;      // 时长
 public:
  CD(int id, string t, string a, string g, string p, int y, int time) {
    this->setID(id);
    this->setTitle(t);
    this->setAuthor(a);
    this->setGrade(g);
    this->publisher = p;
    this->year = y;
    this->time_len = time;
  }
  friend class admin;
  list<CD> li_CD;
  list<CD>::iterator i_CD;
  void add(CD a);
  void Output();  // 重载父类的Output
  void displayAll();
  int judgeID(int a);
};
void CD::add(CD a) { this->li_CD.push_back(a); }
void CD::Output() {
  cout << "ID：" << this->getID() << "  Title：" << this->getTitle()
       << "  Author：" << this->getAuthor() << "  Grade：" << this->getGrad()
       << "  Publisher：" << this->publisher << "  Year：" << this->year
       << "  Length：" << this->time_len << endl;
}
int CD::judgeID(int a) {
  int flag = 0;
  for (this->i_CD = this->li_CD.begin(); this->i_CD != this->li_CD.end();
       this->i_CD++) {
    if (this->getID() == a) {
      flag = 1;
      break;
    }
  }
  return flag;
}
void CD::displayAll() {
  for (this->i_CD = this->li_CD.begin(); this->i_CD != this->li_CD.end();
       this->i_CD++) {
    this->i_CD->Output();
  }
}

class picture : public goods {
 private:
  string country;  // 出品国家
  int width;       // 宽
  int length;      // 长
 public:
  picture(int id, string t, string a, string g, string c, int w, int l) {
    this->setID(id);
    this->setTitle(t);
    this->setAuthor(a);
    this->setGrade(g);
    this->country = c;
    this->width = w;
    this->length = l;
  }
  friend class admin;
  list<picture> li_picture;
  list<picture>::iterator i_picture;
  void add(picture p);
  void Output();  // 重载父类的Output
  void displayAll();
  int judgeID(int a);
};
void picture::add(picture p) { this->li_picture.push_back(p); }
void picture::Output() {
  cout << "ID：" << this->getID() << "  Title：" << this->getTitle()
       << "  Author：" << this->getAuthor() << "  Grade：" << this->getGrad()
       << "  Published_Country：" << this->country << "  Length："
       << this->length << "  width：" << this->width << endl;
}
int picture::judgeID(int a) {
  int flag = 0;
  for (this->i_picture = this->li_picture.begin();
       this->i_picture != this->li_picture.end(); this->i_picture++) {
    if (this->getID() == a) {
      flag = 1;
      break;
    }
  }
  return flag;
}
void picture::displayAll(){
  for (this->i_picture = this->li_picture.begin();
       this->i_picture != this->li_picture.end(); this->i_picture++) {
    this->i_picture->Output();
  }
}

class admin {
 public:
  void search(string t, book &b, CD &c, picture &p);  // 根据标题搜索
  void search(int id, book &b, CD &c, picture &p);    // 多态，函数重载
  void search(string s, int a, book &b, CD &c, picture &p);  // 根据类别搜索
  int RepeatJudgeID(int a, book &b, CD &c, picture &p);  // 判断是否有重复的ID
  void DisplayAll(book &b, CD &c, picture &p);
};
void admin::search(string t, book &b, CD &c, picture &p) {
  int flag = 0;
  for (b.i_book = b.li_book.begin(); b.i_book != b.li_book.end() && flag == 0;
       b.i_book++) {
    if (b.i_book->getTitle() == t) {
      b.i_book->Output();
      flag = 1;
      return;
    }
  }
  for (c.i_CD = c.li_CD.begin(); c.i_CD != c.li_CD.end() && flag == 0;
       c.i_CD++) {
    if (c.i_CD->getTitle() == t) {
      c.i_CD->Output();
      flag = 1;
      return;
    }
  }
  for (p.i_picture = p.li_picture.begin();
       p.i_picture != p.li_picture.end() && flag == 0; p.i_picture++) {
    if (p.i_picture->getTitle() == t) {
      p.i_picture->Output();
      flag = 1;
      return;
    }
  }
  if (flag == 0) {
    cout << "该标题不存在" << endl;
  }
}
void admin::search(int id, book &b, CD &c, picture &p) {
  int flag = 0;
  flag = b.judgeID(id);
  if (flag == 1) {
    b.Output();
    return;
  }
  if (flag == 0) {
    flag = c.judgeID(id);
    if (flag == 1) {
      c.Output();
      return;
    }
  }
  if (flag == 0) {
    flag = p.judgeID(id);
    if (flag == 1) {
      p.Output();
      return;
    }
  }
  if (flag == 0) {
    cout << "该编号不存在" << endl;
  }
}
void admin::search(string s, int a, book &b, CD &c, picture &p) {
  if (s == "图书") {
    if (b.li_book.empty() == true) {
      cout << "该类别没有物品！" << endl;
    } else {
      cout << "该类别商品如下:" << endl;
      for (b.i_book = b.li_book.begin(); b.i_book != b.li_book.end();
           b.i_book++) {
        b.i_book->Output();
      }
    }
  } else if (s == "视频光盘") {
    if (c.li_CD.empty() == true) {
      cout << "该类别没有物品！" << endl;
    } else {
      cout << "该类别商品如下:" << endl;
      for (c.i_CD = c.li_CD.begin(); c.i_CD != c.li_CD.end(); c.i_CD++) {
        c.i_CD->Output();
      }
    }
  } else if (s == "图画") {
    if (p.li_picture.empty() == true) {
      cout << "该类别没有物品！" << endl;
    } else {
      cout << "该类别商品如下:" << endl;
      for (p.i_picture = p.li_picture.begin();
           p.i_picture != p.li_picture.end(); p.i_picture++) {
        p.i_picture->Output();
      }
    }
  } else {
    cout << "请输入正确的类别!" << endl;
  }
}
int admin::RepeatJudgeID(int a, book &b, CD &c, picture &p) {
  int flag1 = 0, flag2 = 0, flag3 = 0;
  flag1 = b.judgeID(a);
  flag2 = c.judgeID(a);
  flag3 = p.judgeID(a);
  if (flag1 == 0 && flag2 == 0 && flag3 == 0) {
    return 1;  // 说明没有重复的id
  } else {
    return 0;
  }
}
void admin::DisplayAll(book &b, CD &c, picture &p){
  cout << "当前库中的物品有：" << endl;
  b.displayAll();
  c.displayAll();
  p.displayAll();
}
#endif