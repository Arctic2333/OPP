#ifndef CONTROL_H
#define CONTROL_H
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <list>

#include "model.h"
using namespace std;
class admin;  // 提前声明 admin类以便household使用
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

  void search();           // 查询住户自身需不需要隔离
  void addSelf(admin& b);  // 用户自己登记信息
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
  int QuarantineNum;                         // 正在隔离的人数
  int HouseholdNum;                          // 当前住户的人数
  list<household> li;                        // 住户链表
  list<household>::iterator i;               // 声明迭代器
  friend void household::addSelf(admin& b);  // 友元函数
  void search();       // 查询管理者个人是否需要隔离
  void search(int a);  // 通过id查询某个住户是否需要隔离  多态
  void searchAll();    // 查询全部住户消息
  void searchQuarantine();  // 查询正在隔离的人员信息并且统计
  void addHousehold(household a);          // 添加住户
  void deleteHousehold(int a);             // 删除id为i的住户
  void editHousehold(int a, household b);  // 编辑id为a的住户的信息
  void editHousehold(int a, int s);        // 编辑id为a的住户的状态
  int judgeID(int a);                      // 判断是否有id为a的住户
};
void admin::search() {
  if (this->getState() == 1) {
    cout << "您没有出外省和高风险地区记录不需要隔离" << endl;
  } else {
    cout << "注意！！！您有出外省和高风险地区记录需要隔离" << endl;
  }
}
void admin::search(int a) {
  for (i = li.begin(); i != li.end(); ++i) {
    if (i->getID() == a) {
      cout << i->getName() << endl;
      i->search();
    }
  }
}
void admin::searchAll() {
  cout << "当前登记的住户有：" << endl;
  for (i = li.begin(); i != li.end(); ++i) {
    cout << i->getName() << endl;
  }
  HouseholdNum = li.size();
  cout << "当前登记住户共有" << HouseholdNum << "人" << endl;
}
void admin::searchQuarantine() {
  QuarantineNum = 0;
  cout << "正在隔离的人员：" << endl;
  for (i = li.begin(); i != li.end(); ++i) {
    if (i->getState() != 1) {
      cout << i->getName() << endl;
      QuarantineNum++;
    }
  }
  cout << "隔离的人数：" << QuarantineNum << endl;
}
void household::addSelf(admin& b) { b.li.push_back(*this); }
void admin::addHousehold(household a) { li.push_back(a); }
void admin::deleteHousehold(int a) {
  int flag = 0;
  for (i = li.begin(); i != li.end(); ++i) {
    if (i->getID() == a) {
      li.erase(i);
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    cout << "删除id为" << a << "的住户成功！" << endl;
  } else {
    cout << "删除失败，未找到住户" << endl;
  }
}
void admin::editHousehold(int a, household b) {
  int flag = 0;
  for (i = li.begin(); i != li.end(); ++i) {
    if (i->getID() == a) {
      li.erase(i);
      li.push_back(b);
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    cout << "编辑id为" << a << "的住户成功！" << endl;
  } else {
    cout << "编辑失败，未找到住户" << endl;
  }
}
void admin::editHousehold(int a, int s) {
  int flag = 0;
  for (i = li.begin(); i != li.end(); ++i) {
    if (i->getID() == a) {
      i->setState(s);
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    cout << "编辑id为" << a << "的住户状态成功！" << endl;
  } else {
    cout << "编辑失败，未找到住户" << endl;
  }
}
int admin::judgeID(int a) {
  int flag = 0;
  for (i = li.begin(); i != li.end(); ++i) {
    if (i->getID() == a) {
      flag = 1;
      break;
    }
  }
  return flag;
}
#endif