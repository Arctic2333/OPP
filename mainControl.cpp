/*
 * @Author: Susongfeng
 * @Date: 2020-06-18 14:14:22
 * @Last Modified by:   Susongfeng
 * @Last Modified time: 2020-06-18 14:14:22
 */

#include <iostream>
#include <iterator>
#include <list>

#include "model.h"
using namespace std;

class household : public model {
 public:
  household(int i = 1, int a = 18, char* n = "张三", char* g = "男",
            char* add = "中国福建", int sta = 1) {  // 含默认参数的构造函数
    this->setID(i);
    this->setAge(a);
    this->setName(n);
    this->setGender(g);
    this->setAddress(add);
    this->setState(sta);
  }

  void search();  // 查询住户自身需不需要隔离
};
void household::search() {
  if (this->getState() == 1) {
    cout << "您没有出外省和高风险地区记录不需要隔离" << endl;
  } else {
    cout << "注意！！！您有出外省和高风险地区记录需要隔离" << endl;
  }
}

class admin : public model {
 public:
  admin(int a = 18, char* n = "张三", char* g = "男", char* add = "中国福建",
        int sta = 1) {  // 含默认参数的构造函数
    this->setAge(a);
    this->setName(n);
    this->setGender(g);
    this->setAddress(add);
    this->setState(sta);
  }
  int QuarantineNum;       // 正在隔离的人数
  int HouseholdNum;        // 当前住户的人数
  list<household> li;      // 住户链表
  friend class household;  // 友元类
  void search();           // 查询管理者个人是否需要隔离
  void search(int a);  // 通过id查询某个住户是否需要隔离  多态
  void searchAll();    // 查询全部住户消息
  void searchQuarantine();  // 查询正在隔离的人员信息并且统计
};
void admin::search() {
  if (this->getState() == 1) {
    cout << "您没有出外省和高风险地区记录不需要隔离" << endl;
  } else {
    cout << "注意！！！您有出外省和高风险地区记录需要隔离" << endl;
  }
}
void admin::search(int a) {
  list<household>::iterator i;  // 声明迭代器
  for (i = li.begin(); i != li.end(); ++i) {
    if (i->getID() == a) {
      cout << i->getName() << endl;
      i->search();
    }
  }
}
void admin::searchAll() {
  list<household>::iterator i;  // 声明迭代器
  for (i = li.begin(); i != li.end(); ++i) {
    cout << i->getName() << endl;
  }
}

int main() {
  household h1(1, 18, "snow", "男", "福建", 1);
  household h2(2, 18, "wing", "女", "福建", 2);
  household h3(3, 18, "wing", "女", "福建", 2);
  admin h4(18, "wing", "女", "福建", 2);
  h4.li.push_back(h1);
  h4.li.push_back(h2);
  h4.li.push_back(h3);
  h4.search(3);
  h4.searchAll();
  return 0;
}