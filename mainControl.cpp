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
  household(int i = 1, int a = 18, char* n = "����", char* g = "��",
            char* add = "�й�����", int sta = 1) {  // ��Ĭ�ϲ����Ĺ��캯��
    this->setID(i);
    this->setAge(a);
    this->setName(n);
    this->setGender(g);
    this->setAddress(add);
    this->setState(sta);
  }

  void search();  // ��ѯס�������費��Ҫ����
};
void household::search() {
  if (this->getState() == 1) {
    cout << "��û�г���ʡ�͸߷��յ�����¼����Ҫ����" << endl;
  } else {
    cout << "ע�⣡�������г���ʡ�͸߷��յ�����¼��Ҫ����" << endl;
  }
}

class admin : public model {
 public:
  admin(int a = 18, char* n = "����", char* g = "��", char* add = "�й�����",
        int sta = 1) {  // ��Ĭ�ϲ����Ĺ��캯��
    this->setAge(a);
    this->setName(n);
    this->setGender(g);
    this->setAddress(add);
    this->setState(sta);
  }
  int QuarantineNum;       // ���ڸ��������
  int HouseholdNum;        // ��ǰס��������
  list<household> li;      // ס������
  friend class household;  // ��Ԫ��
  void search();           // ��ѯ�����߸����Ƿ���Ҫ����
  void search(int a);  // ͨ��id��ѯĳ��ס���Ƿ���Ҫ����  ��̬
  void searchAll();    // ��ѯȫ��ס����Ϣ
  void searchQuarantine();  // ��ѯ���ڸ������Ա��Ϣ����ͳ��
};
void admin::search() {
  if (this->getState() == 1) {
    cout << "��û�г���ʡ�͸߷��յ�����¼����Ҫ����" << endl;
  } else {
    cout << "ע�⣡�������г���ʡ�͸߷��յ�����¼��Ҫ����" << endl;
  }
}
void admin::search(int a) {
  list<household>::iterator i;  // ����������
  for (i = li.begin(); i != li.end(); ++i) {
    if (i->getID() == a) {
      cout << i->getName() << endl;
      i->search();
    }
  }
}
void admin::searchAll() {
  list<household>::iterator i;  // ����������
  for (i = li.begin(); i != li.end(); ++i) {
    cout << i->getName() << endl;
  }
}

int main() {
  household h1(1, 18, "snow", "��", "����", 1);
  household h2(2, 18, "wing", "Ů", "����", 2);
  household h3(3, 18, "wing", "Ů", "����", 2);
  admin h4(18, "wing", "Ů", "����", 2);
  h4.li.push_back(h1);
  h4.li.push_back(h2);
  h4.li.push_back(h3);
  h4.search(3);
  h4.searchAll();
  return 0;
}