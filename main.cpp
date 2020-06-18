#include <cstdlib>
#include <iostream>
#include <iterator>

#include "control.h"
#include "ui.h"
int main() {
  admin ad(20, "arctic", "男", "福建省龙岩市永定区", 1);
  household h1(1000);
  ad.addHousehold(h1);
  int c, flag = 0, t;
  ui ui;
  //============================== 初始选择界面
  ui.display();
  cin >> c;
  if (c == 1) {
    system("cls");
    ui.userUI();
    //============================== 住户选择界面
    cin >> c;
    //============================== ID登入界面
    if (c == 1) {
      system("cls");
      ui.userUI1();
      cin >> c;
      flag = ad.judgeID(c);

      if (flag == 1) {
        system("cls");
        //========================= ID登入成功界面
        ui.successUserUi();
        cin >> t;
        if (t == 1) {
          ad.search(c);
        }
      } else {
        cout << "ID不存在，任意键退出系统" << endl;
        system("pause");
        exit(0);
      }
        }
  }

  return 0;
}