#include <cstdlib>
#include <iostream>
#include <iterator>

#include "control.h"
#include "ui.h"
int main() {
  admin ad(20, "arctic", "��", "����ʡ������������", 1);
  household h1(1000);
  ad.addHousehold(h1);
  int c, flag = 0, t;
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
        }
      } else {
        cout << "ID�����ڣ�������˳�ϵͳ" << endl;
        system("pause");
        exit(0);
      }
        }
  }

  return 0;
}