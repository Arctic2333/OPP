#ifndef CONTROL_H
#define CONTROL_H
#include <cstdlib>
#include <fstream>
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
  cout << this->getName() << ",您好!" << endl;
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
  void searchAllIn(int a);  // 返回id为a的个人信息
  void searchQuarantine();  // 查询正在隔离的人员信息并且统计
  void addHousehold(household a);          // 添加住户
  void deleteHousehold(int a);             // 删除id为i的住户
  void editHousehold(int a, household b);  // 编辑id为a的住户的信息
  void editHousehold(int a, int s);        // 编辑id为a的住户的状态
  int judgeID(int a);                      // 判断是否有id为a的住户
  int judgeReID(int a);                    // 判断是否有重复的ID
  void printUser();  // 将住户信息打印到住户信息.txt中  也用于更新用户信息
  void readUser();  // 从住户信息.txt中读入住户信息完成初始化
};
void admin::search() {
  if (this->getState() == 1) {
    cout << "管理员,您没有出外省和高风险地区记录不需要隔离" << endl;
  } else {
    cout << "注意！！！管理员，您有出外省和高风险地区记录需要隔离" << endl;
  }
}
void admin::search(int a) {
  for (i = li.begin(); i != li.end(); ++i) {  // 遍历链表查找id为a的住户
    if (i->getID() == a) {
      i->search();  // 此处调用的 household的方法
    }
  }
}
void admin::searchAll() {
  cout << "当前登记的住户有：" << endl;
  for (i = li.begin(); i != li.end(); ++i) {  // 遍历链表，将所有住户输出
    cout << "id: " << i->getID() << "  年龄：" << i->getAge() << "  姓名："
         << i->getName() << "  性别：" << i->getGender() << "  住址："
         << i->getAddress();
    if (i->getState() == 1) {
      cout << "  状态：健康" << endl;
    } else {
      cout << "  状态：隔离" << endl;
    }
  }
  HouseholdNum = li.size();  // 获取链表中的元素个数即当前住户数
  cout << "当前登记住户共有" << HouseholdNum << "人" << endl;
}
void admin::searchAllIn(int a) {
  for (i = li.begin(); i != li.end(); ++i) {  // 遍历链表 找到id为a的住户并输出
    if (i->getID() == a) {
      cout << "id: " << i->getID() << "  年龄：" << i->getAge() << "  姓名："
           << i->getName() << "  性别：" << i->getGender() << "  住址："
           << i->getAddress() << endl;
      break;
    }
  }
}
void admin::searchQuarantine() {  // 遍历链表，将state不为健康的住户信息输出
  QuarantineNum = 0;
  cout << "正在隔离的人员：" << endl;
  for (i = li.begin(); i != li.end(); ++i) {
    if (i->getState() != 1) {
      cout << "id: " << i->getID() << "  年龄：" << i->getAge() << "  姓名："
           << i->getName() << "  性别：" << i->getGender() << "  住址："
           << i->getAddress() << endl;
      QuarantineNum++;
    }
  }
  cout << "隔离的人数：" << QuarantineNum << endl;
}
void household::addSelf(admin& b) {  // 友元函数，引用，用户自身录入信息
  b.li.push_back(*this);
  b.printUser();
}
void admin::addHousehold(household a) {
  li.push_back(a);
  this->printUser();
}
void admin::deleteHousehold(int a) {
  int flag = 0;
  for (i = li.begin(); i != li.end(); ++i) {
    if (i->getID() == a) {
      li.erase(i);  // 从链表中移除
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    this->printUser();
    cout << "删除id为" << a << "的住户成功！" << endl;
  } else {
    cout << "删除失败，未找id为" << a << "的住户！！！" << endl;
  }
}
void admin::editHousehold(
    int a, household b) {  // 将用户a的信息移除并且将信息的加入链表
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
    this->printUser();
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
    this->printUser();
    cout << "编辑id为" << a << "的住户状态成功！" << endl;
  } else {
    cout << "编辑失败，未找到住户" << endl;
  }
}
int admin::judgeID(int a) {  // 判断是否有id为a的用户，没有直接退出系统
  int flag = 0;
  for (i = li.begin(); i != li.end(); ++i) {
    if (i->getID() == a) {
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    cout << "ID不存在，任意键退出系统" << endl;
    system("pause");
    exit(0);
  }
  return flag;
}
int admin::judgeReID(int a) {  // 判断输入的id a 在已有用户中是否存在
  int flag = 0;
  for (i = li.begin(); i != li.end(); ++i) {
    if (i->getID() == a) {
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    cout << "ID已存在，请退出系统重新输入ID" << endl;
    system("pause");
    exit(0);
  }
  return flag;
}
void admin::printUser() {  // 将链表中的用户信息输出到文件中，起到刷新用户信息的作用
  ofstream out;
  out.open("住户信息.txt");
  for (i = li.begin(); i != li.end(); ++i) {
    out << i->getID() << endl;
    out << i->getAge() << endl;
    out << i->getName() << endl;
    out << i->getGender() << endl;
    out << i->getAddress() << endl;
    out << i->getState() << endl;
  }
  out.close();
}
void admin::readUser() {  // 软件启动时，将文件中的住户信息加载入程序
  ifstream in;
  int id = 1001, age, state = 1;
  char* name[10000];
  char* address[10000];
  char* gender[10000];
  household* p = new household[10000];  // 栈方式实例化对象数组
  int j = 0;
  in.open("住户信息.txt");
  while (in >> id) {
    name[j] = (char*)malloc(20);
    gender[j] = (char*)malloc(8);
    address[j] = (char*)malloc(200);
    in >> age;
    in >> name[j];
    in >> gender[j];
    in >> address[j];
    in >> state;
    p[j].setID(id);
    p[j].setAge(age);
    p[j].setName(name[j]);
    p[j].setGender(gender[j]);
    p[j].setAddress(address[j]);
    p[j].setState(state);
    li.push_front(p[j]);
    j++;
  }
}
#endif