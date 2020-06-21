#ifndef CONTROL_H
#define CONTROL_H
#include <cstdlib>
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
  book() {}
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
  void edit(book b, int a);
  void Delete(int a);
  int getTotal();
  void Read();
  void Write();
};
void book::add(book a) {
  this->li_book.push_back(a);
  this->Write();
}
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
    if (this->i_book->getID() == a) {
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
void book::edit(book b, int a) {
  int flag = this->judgeID(a);
  if (flag == 1) {
    this->li_book.erase(i_book);
    this->li_book.push_back(b);
  } else {
    cout << "未找到ID为" << a << "的图书" << endl;
    system("pause");
    exit(0);
  }
  this->Write();
}
void book::Delete(int a) {
  int flag = this->judgeID(a);
  if (flag == 1) {
    this->li_book.erase(i_book);
    cout << "删除ID为" << a << "的图书成功" << endl;
  } else {
    cout << "编号不存在" << endl;
    system("pause");
    exit(0);
  }
  this->Write();
}
int book::getTotal() { return this->li_book.size(); }
void book::Read() {
  ifstream inFile;
  inFile.open("图书.txt");
  book *b = new book[300];
  int id;            // 编号
  string title;      // 标题
  string author;     // 作者
  string grade;      // 评级
  string publisher;  // 出版社
  string ISBN;       // ISBN号
  int page;          // 页数
  int j = 0;
  while (inFile >> id) {
    inFile >> title;
    inFile >> author;
    inFile >> grade;
    inFile >> publisher;
    inFile >> ISBN;
    inFile >> page;
    b[j].setID(id);
    b[j].setTitle(title);
    b[j].setAuthor(author);
    b[j].setGrade(grade);
    b[j].ISBN = ISBN;
    b[j].publisher = publisher;
    b[j].page = page;
    this->li_book.push_back(b[j]);
    j++;
  }
  inFile.close();
}
void book::Write() {
  ofstream outFile;
  outFile.open("图书.txt");
  for (i_book = li_book.begin(); i_book != li_book.end(); ++i_book) {
    outFile << i_book->getID() << endl;
    outFile << i_book->getTitle() << endl;
    outFile << i_book->getAuthor() << endl;
    outFile << i_book->getGrad() << endl;
    outFile << i_book->publisher << endl;
    outFile << i_book->ISBN << endl;
    outFile << i_book->page << endl;
  }
  outFile.close();
}

class CD : public goods {
 private:
  string publisher;  // 出品人
  int year;          // 出品年
  int time_len;      // 时长
 public:
  CD() {}
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
  void edit(CD c, int a);
  void Delete(int a);
  int getTotal();
  void Read();
  void Write();
};
void CD::add(CD a) {
  this->li_CD.push_back(a);
  this->Write();
}
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
    if (this->i_CD->getID() == a) {
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
void CD::edit(CD c, int a) {
  int flag = this->judgeID(a);
  if (flag == 1) {
    this->li_CD.erase(i_CD);
    this->li_CD.push_back(c);
  } else {
    cout << "未找到ID为" << a << "的视频光盘" << endl;
    system("pause");
    exit(0);
  }
  this->Write();
}
void CD::Delete(int a) {
  int flag = this->judgeID(a);
  if (flag == 1) {
    this->li_CD.erase(i_CD);
    cout << "删除ID为" << a << "的图书成功" << endl;
  } else {
    cout << "编号不存在" << endl;
    system("pause");
    exit(0);
  }
  this->Write();
}
int CD::getTotal() { return this->li_CD.size(); }
void CD::Read() {
  ifstream inFile;
  inFile.open("视频光盘.txt");
  CD *c = new CD[300];
  int id;            // 编号
  string title;      // 标题
  string author;     // 作者
  string grade;      // 评级
  string publisher;  // 出品人
  int year;          // 出品年
  int time_len;      // 时长
  int j = 0;
  while (inFile >> id) {
    inFile >> title;
    inFile >> author;
    inFile >> grade;
    inFile >> publisher;
    inFile >> year;
    inFile >> time_len;
    c[j].setID(id);
    c[j].setTitle(title);
    c[j].setAuthor(author);
    c[j].setGrade(grade);
    c[j].publisher = publisher;
    c[j].year = year;
    c[j].time_len = time_len;
    this->li_CD.push_back(c[j]);
    j++;
  }
  inFile.close();
}
void CD::Write() {
  ofstream outFile;
  outFile.open("视频光盘.txt");
  for (i_CD = li_CD.begin(); i_CD != li_CD.end(); ++i_CD) {
    outFile << i_CD->getID() << endl;
    outFile << i_CD->getTitle() << endl;
    outFile << i_CD->getAuthor() << endl;
    outFile << i_CD->getGrad() << endl;
    outFile << i_CD->publisher << endl;
    outFile << i_CD->year << endl;
    outFile << i_CD->time_len << endl;
  }
  outFile.close();
}

class picture : public goods {
 private:
  string country;  // 出品国家
  int width;       // 宽
  int length;      // 长
 public:
  picture() {}
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
  void edit(picture p, int a);
  void Delete(int a);
  int getTotal();
  void Read();
  void Write();
};
void picture::add(picture p) {
  this->li_picture.push_back(p);
  this->Write();
}
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
    if (this->i_picture->getID() == a) {
      flag = 1;
      break;
    }
  }
  return flag;
}
void picture::displayAll() {
  for (this->i_picture = this->li_picture.begin();
       this->i_picture != this->li_picture.end(); this->i_picture++) {
    this->i_picture->Output();
  }
}
void picture::edit(picture p, int a) {
  int flag = this->judgeID(a);
  if (flag == 1) {
    this->li_picture.erase(i_picture);
    this->li_picture.push_back(p);
  } else {
    cout << "未找到ID为" << a << "的图画！" << endl;
    system("pause");
    exit(0);
  }
  this->Write();
}
void picture::Delete(int a) {
  int flag = this->judgeID(a);
  if (flag == 1) {
    this->li_picture.erase(i_picture);
    cout << "删除ID为" << a << "的图书成功" << endl;
  } else {
    cout << "编号不存在" << endl;
    system("pause");
    exit(0);
  }
  this->Write();
}
int picture::getTotal() { return this->li_picture.size(); }
void picture::Read() {
  ifstream inFile;
  inFile.open("图画.txt");
  picture *p = new picture[300];
  int id;          // 编号
  string title;    // 标题
  string author;   // 作者
  string grade;    // 评级
  string country;  // 出品国家
  int width;       // 宽
  int length;      // 长
  int j = 0;
  while (inFile >> id) {
    inFile >> title;
    inFile >> author;
    inFile >> grade;
    inFile >> country;
    inFile >> width;
    inFile >> length;
    p[j].setID(id);
    p[j].setTitle(title);
    p[j].setAuthor(author);
    p[j].setGrade(grade);
    p[j].country = country;
    p[j].width = width;
    p[j].length = length;
    this->li_picture.push_back(p[j]);
    j++;
  }
  inFile.close();
}
void picture::Write() {
  ofstream outFile;
  outFile.open("图画.txt");
  for (i_picture = li_picture.begin(); i_picture != li_picture.end();
       ++i_picture) {
    outFile << i_picture->getID() << endl;
    outFile << i_picture->getTitle() << endl;
    outFile << i_picture->getAuthor() << endl;
    outFile << i_picture->getGrad() << endl;
    outFile << i_picture->country << endl;
    outFile << i_picture->width << endl;
    outFile << i_picture->length << endl;
  }
  outFile.close();
}

class admin {
 public:
  void search(string t, book &b, CD &c, picture &p);  // 根据标题搜索
  void search(int id, book &b, CD &c, picture &p);    // 多态，函数重载
  void search(string s, int a, book &b, CD &c, picture &p);  // 根据类别搜索
  int RepeatJudgeID(int a, book &b, CD &c, picture &p);  // 判断是否有重复的ID
  void DisplayAll(book &b, CD &c, picture &p);
  void getTotal(book &b, CD &c, picture &p);
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
    cout << "该标题不存在,即将退出系统" << endl;
  }
}
void admin::search(int id, book &b, CD &c, picture &p) {
  int flag = 0;
  flag = b.judgeID(id);
  if (flag == 1) {
    b.i_book->Output();
    return;
  }
  if (flag == 0) {
    flag = c.judgeID(id);
    if (flag == 1) {
      c.i_CD->Output();
      return;
    }
  }
  if (flag == 0) {
    flag = p.judgeID(id);
    if (flag == 1) {
      p.i_picture->Output();
      return;
    }
  }
  if (flag == 0) {
    cout << "该编号不存在，即将退出系统" << endl;
  }
}
void admin::search(string s, int a, book &b, CD &c, picture &p) {
  if (s == "图书") {
    if (b.li_book.empty() == true) {
      cout << "该类别没有物品！即将退出系统" << endl;
    } else {
      cout << "该类别商品如下:" << endl;
      for (b.i_book = b.li_book.begin(); b.i_book != b.li_book.end();
           b.i_book++) {
        b.i_book->Output();
      }
    }
  } else if (s == "视频光盘") {
    if (c.li_CD.empty() == true) {
      cout << "该类别没有物品！即将退出系统" << endl;
    } else {
      cout << "该类别商品如下:" << endl;
      for (c.i_CD = c.li_CD.begin(); c.i_CD != c.li_CD.end(); c.i_CD++) {
        c.i_CD->Output();
      }
    }
  } else if (s == "图画") {
    if (p.li_picture.empty() == true) {
      cout << "该类别没有物品！即将退出系统" << endl;
    } else {
      cout << "该类别商品如下:" << endl;
      for (p.i_picture = p.li_picture.begin();
           p.i_picture != p.li_picture.end(); p.i_picture++) {
        p.i_picture->Output();
      }
    }
  } else {
    cout << "请输入正确的类别!即将退出系统" << endl;
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
void admin::DisplayAll(book &b, CD &c, picture &p) {
  cout << "当前库中的图书：" << endl;
  b.displayAll();
  cout << "当前库中的视频光盘：" << endl;
  c.displayAll();
  cout << "当前库中的图画：" << endl;
  p.displayAll();
}
void admin::getTotal(book &b, CD &c, picture &p) {
  cout << "当前物品库中图书总数：" << b.getTotal() << endl;
  cout << "当前物品库中视频光盘总数：" << c.getTotal() << endl;
  cout << "当前物品库中图画总数：" << p.getTotal() << endl;
  cout << "当前物品库中总数：" << b.getTotal() + c.getTotal() + p.getTotal()
       << endl;
}
#endif