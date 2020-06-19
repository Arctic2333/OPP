#include <cstdlib>
#include <iostream>
#include <iterator>

#include "control.h"
#include "ui.h"
int c, flag = 0, t, id = 1001, age, state = 1;
char *name = (char *)malloc(20);
char *address = (char *)malloc(200);
char *gender = (char *)malloc(8);
void readUserInformation() {  // �����������Ϣ
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
  ad.readUser();  // ��ʼ������
  ui ui;
  //============================== ��ʼѡ�����
  ui.display();
  cin >> c;
  if (c == 1) {
    ui.userUI();
    //============================== ס��ѡ�����
    cin >> c;
    //============================== ID�������
    if (c == 1) {
      ui.userUI1();
      cin >> c;
      flag = ad.judgeID(c);
      //========================= ID����ɹ�����
      ui.successUserUi();
      cin >> t;
      if (t == 1) {
        ad.search(c);
        system("pause");
      }
    } else {
      //=================¼����Ϣ����
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
    ui.adminUI();
    cin >> c;
    if (c == 1) {
      //====================����Ա����1����
      ui.adminUI_1();
      ad.search();
      system("pause");
      exit(0);
    } else if (c == 2) {
      //====================����Ա����2����
      ui.adminUI_2();
      cout << "������ס��id��" << endl;
      cin >> t;
      flag = ad.judgeID(t);
      ad.search(t);
      system("pause");
      exit(0);
    } else if (c == 3) {
      //====================����Ա����3����
      ui.adminUI_3();
      ad.searchAll();
      system("pause");
      exit(0);
    } else if (c == 4) {
      //====================����Ա����4����
      ui.adminUI_4();
      ad.searchQuarantine();
      system("pause");
      exit(0);
    } else if (c == 5) {
      //====================����Ա����5����
      ui.adminUI_5();
      readUserInformation();
      ad.judgeReID(id);
      household h(id, age, name, gender, address, state);
      ad.addHousehold(h);
      cout << "��ӳɹ��ˣ�����ϵͳ,�û�����ʹ��id����" << endl;
      system("pause");
      exit(0);
    } else if (c == 6) {
      //====================����Ա����6����
      ui.adminUI_6();
      cout << "�������û�id��" << endl;
      cin >> t;
      flag = ad.judgeID(t);
      ad.searchAllIn(t);
      ad.deleteHousehold(t);
      system("pause");
      exit(0);
    } else if (c == 7) {
      //====================����Ա����7����
      ui.adminUI_7();
      cout << "�������û�id��" << endl;
      cin >> t;
      flag = ad.judgeID(t);
      ad.searchAllIn(t);
      readUserInformation();
      household h(id, age, name, gender, address, state);
      ad.editHousehold(t, h);
      ad.searchAllIn(t);
      system("pause");
      exit(0);
    } else {
      //====================����Ա����8����
      ui.adminUI_8();
      cout << "�������û�id��" << endl;
      cin >> t;
      flag = ad.judgeID(t);
      ad.searchAllIn(t);
      cout << "������״̬��" << endl << "1.����" << endl << "2.����" << endl;
      cin >> state;
      ad.editHousehold(t, state);
      ad.searchAllIn(t);
      system("pause");
      exit(0);
    }
  }

  return 0;
}
