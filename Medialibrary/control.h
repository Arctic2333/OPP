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
class admin;  // ��ǰ������ �Ա����ʹ��
class book : public goods {
 private:
  string publisher;  // ������
  string ISBN;       // ISBN��
  int page;          // ҳ��
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
  friend class admin;  // ������Ԫ��
  list<book> li_book;  // stl
  list<book>::iterator i_book;
  void add(book a);  // ��̬
  void Output();     // ���ظ����Output
  void displayAll();
  int judgeID(int a);
  void edit(book b, int a);
  void Delete(int a);
  int getTotal();
};
void book::add(book a) { this->li_book.push_back(a); }
void book::Output() {
  cout << "ID��" << this->getID() << "  Title��" << this->getTitle()
       << "  Author��" << this->getAuthor() << "  Grade��" << this->getGrad()
       << "  Publisher��" << this->publisher << "  ISBN��" << this->ISBN
       << "  Page��" << this->page << endl;
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
    cout << "δ�ҵ�IDΪ" << a << "��ͼ��" << endl;
  }
}
void book::Delete(int a) {
  int flag = this->judgeID(a);
  if (flag == 1) {
    this->li_book.erase(i_book);
    cout << "ɾ��IDΪ" << a << "��ͼ��ɹ�" << endl;
  } else {
    cout << "��Ų�����" << endl;
  }
}
int book::getTotal() { return this->li_book.size(); }

class CD : public goods {
 private:
  string publisher;  // ��Ʒ��
  int year;          // ��Ʒ��
  int time_len;      // ʱ��
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
  void Output();  // ���ظ����Output
  void displayAll();
  int judgeID(int a);
  void edit(CD c, int a);
  void Delete(int a);
  int getTotal();
};
void CD::add(CD a) { this->li_CD.push_back(a); }
void CD::Output() {
  cout << "ID��" << this->getID() << "  Title��" << this->getTitle()
       << "  Author��" << this->getAuthor() << "  Grade��" << this->getGrad()
       << "  Publisher��" << this->publisher << "  Year��" << this->year
       << "  Length��" << this->time_len << endl;
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
    cout << "δ�ҵ�IDΪ" << a << "����Ƶ����" << endl;
  }
}
void CD::Delete(int a) {
  int flag = this->judgeID(a);
  if (flag == 1) {
    this->li_CD.erase(i_CD);
    cout << "ɾ��IDΪ" << a << "��ͼ��ɹ�" << endl;
  } else {
    cout << "��Ų�����" << endl;
  }
}
int CD::getTotal(){
  return this->li_CD.size();
}

class picture : public goods {
 private:
  string country;  // ��Ʒ����
  int width;       // ��
  int length;      // ��
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
  void Output();  // ���ظ����Output
  void displayAll();
  int judgeID(int a);
  void edit(picture p, int a);
  void Delete(int a);
    int getTotal();
};
void picture::add(picture p) { this->li_picture.push_back(p); }
void picture::Output() {
  cout << "ID��" << this->getID() << "  Title��" << this->getTitle()
       << "  Author��" << this->getAuthor() << "  Grade��" << this->getGrad()
       << "  Published_Country��" << this->country << "  Length��"
       << this->length << "  width��" << this->width << endl;
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
    cout << "δ�ҵ�IDΪ" << a << "��ͼ����" << endl;
  }
}
void picture::Delete(int a) {
  int flag = this->judgeID(a);
  if (flag == 1) {
    this->li_picture.erase(i_picture);
    cout << "ɾ��IDΪ" << a << "��ͼ��ɹ�" << endl;
  } else {
    cout << "��Ų�����" << endl;
  }
}
int picture::getTotal(){
  return this->li_picture.size();
}

class admin {
 public:
  void search(string t, book &b, CD &c, picture &p);  // ���ݱ�������
  void search(int id, book &b, CD &c, picture &p);    // ��̬����������
  void search(string s, int a, book &b, CD &c, picture &p);  // �����������
  int RepeatJudgeID(int a, book &b, CD &c, picture &p);  // �ж��Ƿ����ظ���ID
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
    cout << "�ñ��ⲻ����" << endl;
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
    cout << "�ñ�Ų�����" << endl;
  }
}
void admin::search(string s, int a, book &b, CD &c, picture &p) {
  if (s == "ͼ��") {
    if (b.li_book.empty() == true) {
      cout << "�����û����Ʒ��" << endl;
    } else {
      cout << "�������Ʒ����:" << endl;
      for (b.i_book = b.li_book.begin(); b.i_book != b.li_book.end();
           b.i_book++) {
        b.i_book->Output();
      }
    }
  } else if (s == "��Ƶ����") {
    if (c.li_CD.empty() == true) {
      cout << "�����û����Ʒ��" << endl;
    } else {
      cout << "�������Ʒ����:" << endl;
      for (c.i_CD = c.li_CD.begin(); c.i_CD != c.li_CD.end(); c.i_CD++) {
        c.i_CD->Output();
      }
    }
  } else if (s == "ͼ��") {
    if (p.li_picture.empty() == true) {
      cout << "�����û����Ʒ��" << endl;
    } else {
      cout << "�������Ʒ����:" << endl;
      for (p.i_picture = p.li_picture.begin();
           p.i_picture != p.li_picture.end(); p.i_picture++) {
        p.i_picture->Output();
      }
    }
  } else {
    cout << "��������ȷ�����!" << endl;
  }
}
int admin::RepeatJudgeID(int a, book &b, CD &c, picture &p) {
  int flag1 = 0, flag2 = 0, flag3 = 0;
  flag1 = b.judgeID(a);
  flag2 = c.judgeID(a);
  flag3 = p.judgeID(a);
  if (flag1 == 0 && flag2 == 0 && flag3 == 0) {
    return 1;  // ˵��û���ظ���id
  } else {
    return 0;
  }
}
void admin::DisplayAll(book &b, CD &c, picture &p) {
  cout << "��ǰ���е���Ʒ�У�" << endl;
  b.displayAll();
  c.displayAll();
  p.displayAll();
}
#endif