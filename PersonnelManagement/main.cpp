#include <cstdlib>
#include <iostream>
#include <iterator>

#include "control.h"
#include "ui.h"
int c, flag = 0, t, id = 1001, age, state = 1;
char *name = (char *)malloc(20);
char *address = (char *)malloc(200);
char *gender = (char *)malloc(8);
void readUserInformation() {  // 读入输入的信息
  cout << "请依次输入id，年龄，姓名，性别，地址(!:"
          "请输入完一项回车换行输入下一项)"
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
  admin ad(20, "arctic", "男", "福建省龙岩市永定区", 1);
  ad.readUser();  // 初始化数据
  ui ui;
  //============================== 初始选择界面
  ui.display();
  cin >> c;
  if (c == 1) {
    ui.userUI();
    //============================== 住户选择界面
    cin >> c;
    //============================== ID登入界面
    if (c == 1) {
      ui.userUI1();
      cin >> c;
      flag = ad.judgeID(c);
      //========================= ID登入成功界面
      ui.successUserUi();
      cin >> t;
      if (t == 1) {
        ad.search(c);
        system("pause");
      }
    } else {
      //=================录入信息界面
      ui.userUI2();
      readUserInformation();
      household h(id, age, name, gender, address, state);
      h.addSelf(ad);
      cout << "添加成功了，重启系统即可使用id登入" << endl;
      system("pause");
      exit(0);
    }
  } else {
    //========================管理员功能选择界面
    ui.adminUI();
    cin >> c;
    if (c == 1) {
      //====================管理员功能1界面
      ui.adminUI_1();
      ad.search();
      system("pause");
      exit(0);
    } else if (c == 2) {
      //====================管理员功能2界面
      ui.adminUI_2();
      cout << "请输入住户id：" << endl;
      cin >> t;
      flag = ad.judgeID(t);
      ad.search(t);
      system("pause");
      exit(0);
    } else if (c == 3) {
      //====================管理员功能3界面
      ui.adminUI_3();
      ad.searchAll();
      system("pause");
      exit(0);
    } else if (c == 4) {
      //====================管理员功能4界面
      ui.adminUI_4();
      ad.searchQuarantine();
      system("pause");
      exit(0);
    } else if (c == 5) {
      //====================管理员功能5界面
      ui.adminUI_5();
      readUserInformation();
      ad.judgeReID(id);
      household h(id, age, name, gender, address, state);
      ad.addHousehold(h);
      cout << "添加成功了，重启系统,用户即可使用id登入" << endl;
      system("pause");
      exit(0);
    } else if (c == 6) {
      //====================管理员功能6界面
      ui.adminUI_6();
      cout << "请输入用户id：" << endl;
      cin >> t;
      flag = ad.judgeID(t);
      ad.searchAllIn(t);
      ad.deleteHousehold(t);
      system("pause");
      exit(0);
    } else if (c == 7) {
      //====================管理员功能7界面
      ui.adminUI_7();
      cout << "请输入用户id：" << endl;
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
      //====================管理员功能8界面
      ui.adminUI_8();
      cout << "请输入用户id：" << endl;
      cin >> t;
      flag = ad.judgeID(t);
      ad.searchAllIn(t);
      cout << "请输入状态：" << endl << "1.健康" << endl << "2.隔离" << endl;
      cin >> state;
      ad.editHousehold(t, state);
      ad.searchAllIn(t);
      system("pause");
      exit(0);
    }
  }

  return 0;
}
