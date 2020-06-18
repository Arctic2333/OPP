#include <cstdlib>
#include <iostream>
#include <iterator>

#include "control.h"
#include "ui.h"
int c, flag = 0, t, id = 1001, age, state = 1;
char *name = (char *)malloc(20);
char *address = (char *)malloc(200);
char *gender = (char *)malloc(8);
void readUserInformation() {
  cout << "����������id�����䣬�������Ա𣬵�ַ(!:"
          "��������һ��س�����������һ��)"
       << endl;
  cin >> id;
  getchar();
  cin >> age;
  getchar();
  gets(name);
  gets(gender);
  gets(address);
}
int main() {
  admin ad(20, "arctic", "��", "����ʡ������������", 1);
  household h1(1000, 18, "anti", "��", "��������", 2);
  ad.addHousehold(h1);
  ui ui;
  //============================== ��ʼѡ�����
  ui.display();
  cin >> c;
  if (c == 1) {
    system("cls");
    ui.userUI();
    //============================== ס��ѡ�����
    cin >> c;
    //============================== ID�������
    if (c == 1) {
      system("cls");
      ui.userUI1();
      cin >> c;
      flag = ad.judgeID(c);

      if (flag == 1) {
        system("cls");
        //========================= ID����ɹ�����
        ui.successUserUi();
        cin >> t;
        if (t == 1) {
          ad.search(c);
          system("pause");
        }
      } else {
        cout << "ID�����ڣ�������˳�ϵͳ" << endl;
        system("pause");
        exit(0);
      }
    } else {
      //=================¼����Ϣ����
      system("cls");
      ui.userUI2();
      readUserInformation();
      household h(id, age, name, gender, address, state);
      h.addSelf(ad);
      cout << "��ӳɹ��ˣ�����ϵͳ����ʹ��id����" << endl;
      system("pause");
      exit(0);
    }
  } else {
    //========================����Ա����ѡ�����
    system("cls");
    ui.adminUI();
    cin >> c;
    if (c == 1) {
      ad.search();
      system("pause");
      exit(0);
    } else if (c == 2) {
      cout << "������ס��id��" << endl;
      cin >> t;
      ad.search(t);
      system("pause");
      exit(0);
    } else if (c == 3) {
      ad.searchAll();
      system("pause");
      exit(0);
    } else if (c == 4) {
      ad.searchQuarantine();
      system("pause");
      exit(0);
    } else if (c == 5) {
      readUserInformation();
      household h(id, age, name, gender, address, state);
      ad.addHousehold(h);
      cout << "��ӳɹ��ˣ�����ϵͳ,�û�����ʹ��id����" << endl;
      system("pause");
      exit(0);
    } else if (c == 6) {
      cout << "�������û�id��" << endl;
      cin >> t;
      ad.deleteHousehold(t);
      system("pause");
      exit(0);
    } else if (c == 7) {
      cout << "�������û�id��" << endl;
      cin >> t;
      readUserInformation();
      household h(id, age, name, gender, address, state);
      ad.editHousehold(t, h);
      ad.searchAll();
      system("pause");
      exit(0);
    }
  }

  return 0;
}