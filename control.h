#ifndef CONTROL_H
#define CONTROL_H
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <list>

#include "model.h"
using namespace std;
class admin;  // ��ǰ���� admin���Ա�householdʹ��
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

  void search();           // ��ѯס�������費��Ҫ����
  void addSelf(admin& b);  // �û��Լ��Ǽ���Ϣ
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
  int QuarantineNum;                         // ���ڸ��������
  int HouseholdNum;                          // ��ǰס��������
  list<household> li;                        // ס������
  list<household>::iterator i;               // ����������
  friend void household::addSelf(admin& b);  // ��Ԫ����
  void search();       // ��ѯ�����߸����Ƿ���Ҫ����
  void search(int a);  // ͨ��id��ѯĳ��ס���Ƿ���Ҫ����  ��̬
  void searchAll();    // ��ѯȫ��ס����Ϣ
  void searchQuarantine();  // ��ѯ���ڸ������Ա��Ϣ����ͳ��
  void addHousehold(household a);          // ���ס��
  void deleteHousehold(int a);             // ɾ��idΪi��ס��
  void editHousehold(int a, household b);  // �༭idΪa��ס������Ϣ
  void editHousehold(int a, int s);        // �༭idΪa��ס����״̬
  int judgeID(int a);                      // �ж��Ƿ���idΪa��ס��
};
void admin::search() {
  if (this->getState() == 1) {
    cout << "��û�г���ʡ�͸߷��յ�����¼����Ҫ����" << endl;
  } else {
    cout << "ע�⣡�������г���ʡ�͸߷��յ�����¼��Ҫ����" << endl;
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
  cout << "��ǰ�Ǽǵ�ס���У�" << endl;
  for (i = li.begin(); i != li.end(); ++i) {
    cout << i->getName() << endl;
  }
  HouseholdNum = li.size();
  cout << "��ǰ�Ǽ�ס������" << HouseholdNum << "��" << endl;
}
void admin::searchQuarantine() {
  QuarantineNum = 0;
  cout << "���ڸ������Ա��" << endl;
  for (i = li.begin(); i != li.end(); ++i) {
    if (i->getState() != 1) {
      cout << i->getName() << endl;
      QuarantineNum++;
    }
  }
  cout << "�����������" << QuarantineNum << endl;
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
    cout << "ɾ��idΪ" << a << "��ס���ɹ���" << endl;
  } else {
    cout << "ɾ��ʧ�ܣ�δ�ҵ�ס��" << endl;
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
    cout << "�༭idΪ" << a << "��ס���ɹ���" << endl;
  } else {
    cout << "�༭ʧ�ܣ�δ�ҵ�ס��" << endl;
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
    cout << "�༭idΪ" << a << "��ס��״̬�ɹ���" << endl;
  } else {
    cout << "�༭ʧ�ܣ�δ�ҵ�ס��" << endl;
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