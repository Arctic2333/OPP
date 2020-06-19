#ifndef CONTROL_H
#define CONTROL_H
#include <cstdlib>
#include <fstream>
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
  cout << this->getName() << ",����!" << endl;
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
  void searchAllIn(int a);  // ����idΪa�ĸ�����Ϣ
  void searchQuarantine();  // ��ѯ���ڸ������Ա��Ϣ����ͳ��
  void addHousehold(household a);          // ���ס��
  void deleteHousehold(int a);             // ɾ��idΪi��ס��
  void editHousehold(int a, household b);  // �༭idΪa��ס������Ϣ
  void editHousehold(int a, int s);        // �༭idΪa��ס����״̬
  int judgeID(int a);                      // �ж��Ƿ���idΪa��ס��
  int judgeReID(int a);                    // �ж��Ƿ����ظ���ID
  void printUser();  // ��ס����Ϣ��ӡ��ס����Ϣ.txt��  Ҳ���ڸ����û���Ϣ
  void readUser();  // ��ס����Ϣ.txt�ж���ס����Ϣ��ɳ�ʼ��
};
void admin::search() {
  if (this->getState() == 1) {
    cout << "����Ա,��û�г���ʡ�͸߷��յ�����¼����Ҫ����" << endl;
  } else {
    cout << "ע�⣡��������Ա�����г���ʡ�͸߷��յ�����¼��Ҫ����" << endl;
  }
}
void admin::search(int a) {
  for (i = li.begin(); i != li.end(); ++i) {  // �����������idΪa��ס��
    if (i->getID() == a) {
      i->search();  // �˴����õ� household�ķ���
    }
  }
}
void admin::searchAll() {
  cout << "��ǰ�Ǽǵ�ס���У�" << endl;
  for (i = li.begin(); i != li.end(); ++i) {  // ��������������ס�����
    cout << "id: " << i->getID() << "  ���䣺" << i->getAge() << "  ������"
         << i->getName() << "  �Ա�" << i->getGender() << "  סַ��"
         << i->getAddress();
    if (i->getState() == 1) {
      cout << "  ״̬������" << endl;
    } else {
      cout << "  ״̬������" << endl;
    }
  }
  HouseholdNum = li.size();  // ��ȡ�����е�Ԫ�ظ�������ǰס����
  cout << "��ǰ�Ǽ�ס������" << HouseholdNum << "��" << endl;
}
void admin::searchAllIn(int a) {
  for (i = li.begin(); i != li.end(); ++i) {  // �������� �ҵ�idΪa��ס�������
    if (i->getID() == a) {
      cout << "id: " << i->getID() << "  ���䣺" << i->getAge() << "  ������"
           << i->getName() << "  �Ա�" << i->getGender() << "  סַ��"
           << i->getAddress() << endl;
      break;
    }
  }
}
void admin::searchQuarantine() {  // ����������state��Ϊ������ס����Ϣ���
  QuarantineNum = 0;
  cout << "���ڸ������Ա��" << endl;
  for (i = li.begin(); i != li.end(); ++i) {
    if (i->getState() != 1) {
      cout << "id: " << i->getID() << "  ���䣺" << i->getAge() << "  ������"
           << i->getName() << "  �Ա�" << i->getGender() << "  סַ��"
           << i->getAddress() << endl;
      QuarantineNum++;
    }
  }
  cout << "�����������" << QuarantineNum << endl;
}
void household::addSelf(admin& b) {  // ��Ԫ���������ã��û�����¼����Ϣ
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
      li.erase(i);  // ���������Ƴ�
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    this->printUser();
    cout << "ɾ��idΪ" << a << "��ס���ɹ���" << endl;
  } else {
    cout << "ɾ��ʧ�ܣ�δ��idΪ" << a << "��ס��������" << endl;
  }
}
void admin::editHousehold(
    int a, household b) {  // ���û�a����Ϣ�Ƴ����ҽ���Ϣ�ļ�������
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
    this->printUser();
    cout << "�༭idΪ" << a << "��ס��״̬�ɹ���" << endl;
  } else {
    cout << "�༭ʧ�ܣ�δ�ҵ�ס��" << endl;
  }
}
int admin::judgeID(int a) {  // �ж��Ƿ���idΪa���û���û��ֱ���˳�ϵͳ
  int flag = 0;
  for (i = li.begin(); i != li.end(); ++i) {
    if (i->getID() == a) {
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    cout << "ID�����ڣ�������˳�ϵͳ" << endl;
    system("pause");
    exit(0);
  }
  return flag;
}
int admin::judgeReID(int a) {  // �ж������id a �������û����Ƿ����
  int flag = 0;
  for (i = li.begin(); i != li.end(); ++i) {
    if (i->getID() == a) {
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    cout << "ID�Ѵ��ڣ����˳�ϵͳ��������ID" << endl;
    system("pause");
    exit(0);
  }
  return flag;
}
void admin::printUser() {  // �������е��û���Ϣ������ļ��У���ˢ���û���Ϣ������
  ofstream out;
  out.open("ס����Ϣ.txt");
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
void admin::readUser() {  // �������ʱ�����ļ��е�ס����Ϣ���������
  ifstream in;
  int id = 1001, age, state = 1;
  char* name[10000];
  char* address[10000];
  char* gender[10000];
  household* p = new household[10000];  // ջ��ʽʵ������������
  int j = 0;
  in.open("ס����Ϣ.txt");
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