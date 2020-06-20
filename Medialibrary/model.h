#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <string>
using namespace std;

class goods {
 private:
  int id;         // 编号
  string title;   // 标题
  string author;  // 作者
  string grade;   // 评级
 public:
  int getID() { return this->id; }
  string getTitle() { return this->title; }
  string getAuthor() { return this->author; }
  string getGrad() { return this->grade; }
  void setID(int a) { this->id = a; }
  void setTitle(string t) { this->title = t; }
  void setAuthor(string a) { this->author = a; }
  void setGrade(string g) { this->grade = g; }
  void add();
  void Output();
  int getTotal();
  void displayAll();
  void edit();
  void Delete(int a);
  int judgeID(int a);
};
#endif