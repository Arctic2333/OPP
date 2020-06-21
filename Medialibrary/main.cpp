#include <iostream>
#include <string>

#include "control.h"
#include "ui.h"
using namespace std;
int id;         // 编号
string title;   // 标题
string author;  // 作者
string grade;   // 评级
void readBaseInformation() {
  cin >> id;
  getchar();
  cin >> title;
  cin >> author;
  cin >> grade;
}
void EXIT() {
  system("pause");
  exit(0);
}
int main() {
  int c, t;  // 选择功能
  book book_root;
  CD cd_root;
  picture picture_root;
  admin ad;
  ui ui;
  ui.display();
  book_root.Read();
  cd_root.Read();
  picture_root.Read();

  //=========================================================================================
  cin >> c;
  //=========================================功能选择
  if (c == 1) {
    ui.addUI();
    cin >> c;
    //============================添加图书
    if (c == 1) {
      string publisher;  // 出版社
      string ISBN;       // ISBN号
      int page;          // 页数
      ui.addBook();
      readBaseInformation();
      cin >> publisher;
      cin >> ISBN;
      cin >> page;
      int flag = ad.RepeatJudgeID(id, book_root, cd_root, picture_root);
      if (flag == 1) {
        book b(id, title, author, grade, publisher, ISBN, page);
        book_root.add(b);
        cout << "添加物品成功，即将退出系统" << endl;

      } else {
        cout << "错误！ID重复，即将退出系统" << endl;
      }
      EXIT();
    } else if (c == 2) {  //=====================添加视频光盘
      string publisher;   // 出品人
      int year;           // 出品年
      int time_len;       // 时长
      ui.addCD();
      readBaseInformation();
      cin >> publisher;
      cin >> year;
      cin >> time_len;
      int flag = ad.RepeatJudgeID(id, book_root, cd_root, picture_root);
      if (flag == 1) {
        CD c(id, title, author, grade, publisher, year, time_len);
        cd_root.add(c);
        cout << "添加物品成功，即将退出系统" << endl;

      } else {
        cout << "错误！ID重复，即将退出系统" << endl;
      }
      EXIT();
    } else {
      //========================== 添加图画
      string country;  // 出品国家
      int width;       // 宽
      int length;      // 长
      ui.addPicture();
      readBaseInformation();
      cin >> country;
      cin >> length;
      cin >> width;
      int flag = ad.RepeatJudgeID(id, book_root, cd_root, picture_root);
      if (flag == 1) {
        picture p(id, title, author, grade, country, width, length);
        picture_root.add(p);
        cout << "添加物品成功，即将退出系统" << endl;

      } else {
        cout << "错误！ID重复，即将退出系统" << endl;
      }
      EXIT();
    }
  } else if (c == 2) {  // ============================查询物品
    ui.searchUI();
    cin >> c;
    //================按标题查询
    if (c == 1) {
      ui.searchTitle();
      cin >> title;
      ad.search(title, book_root, cd_root, picture_root);
      EXIT();
    } else if (c == 2) {  //===============按id查询
      ui.searchID();
      cin >> id;
      ad.search(id, book_root, cd_root, picture_root);
      EXIT();
    } else {  //=======================按类别查询
      ui.searchClass();
      cin >> title;
      ad.search(title, 1, book_root, cd_root, picture_root);
      EXIT();
    }
  } else if (c == 3) {  //==============显示当前库中所有物品
    ui.allUI();
    ad.DisplayAll(book_root, cd_root, picture_root);
    EXIT();
  } else if (c == 4) {  //===============编辑物品
    ui.editUI();
    cin >> c;
    if (c == 1) {        //======================编辑图书
      string publisher;  // 出版社
      string ISBN;       // ISBN号
      int page;          // 页数
      ui.editBook();
      cin >> t;
      ad.search(t, book_root, cd_root, picture_root);
      cout << "请依次输入：编号，标题，作者，评级，出版社，ISBN码，页数（每输入"
              "完"
              "一项请敲回车换行）:"
           << endl;
      readBaseInformation();
      cin >> publisher;
      cin >> ISBN;
      cin >> page;
      int flag = ad.RepeatJudgeID(id, book_root, cd_root, picture_root);
      if (id == t) flag = 1;  // 使用原来的id
      if (flag == 1) {
        book b(id, title, author, grade, publisher, ISBN, page);
        book_root.edit(b, t);
        cout << "编辑物品成功，即将退出系统" << endl;

      } else {
        cout << "错误！ID重复，即将退出系统" << endl;
      }
      EXIT();
    } else if (c == 2) {  //=========编辑光盘
      string publisher;   // 出品人
      int year;           // 出品年
      int time_len;       // 时长
      ui.editCD();
      cin >> t;
      ad.search(t, book_root, cd_root, picture_root);
      cout << "请依次输入：编号，标题，作者，评级，出版人，出版年，视频时长（每"
              "输入完一项请敲回车换行）:"
           << endl;
      readBaseInformation();
      cin >> publisher;
      cin >> year;
      cin >> time_len;
      int flag = ad.RepeatJudgeID(id, book_root, cd_root, picture_root);
      if (id == t) flag = 1;
      if (flag == 1) {
        CD c(id, title, author, grade, publisher, year, time_len);
        cd_root.edit(c, t);
        cout << "编辑物品成功，即将退出系统" << endl;

      } else {
        cout << "错误！ID重复，即将退出系统" << endl;
      }
      EXIT();
    } else {
      //================编辑图画
      string country;  // 出品国家
      int width;       // 宽
      int length;      // 长
      ui.editPicture();
      cin >> t;
      ad.search(t, book_root, cd_root, picture_root);
      cout << "请依次输入：编号，标题，作者，评级，出版国家，长，宽（每输入完"
              "一项请敲回车换行）:"
           << endl;
      readBaseInformation();
      cin >> country;
      cin >> length;
      cin >> width;
      int flag = ad.RepeatJudgeID(id, book_root, cd_root, picture_root);
      if (t == id) flag = 1;
      if (flag == 1) {
        picture p(id, title, author, grade, country, width, length);
        picture_root.edit(p, t);
        cout << "编辑物品成功，即将退出系统" << endl;
      } else {
        cout << "错误！ID重复，即将退出系统" << endl;
      }
      EXIT();
    }
  } else if (c == 5) {
    ui.deleteUI();
    cin >> c;
    if (c == 1) {
      ui.deleteBook();
      cin >> t;
      ad.search(t, book_root, cd_root, picture_root);
      book_root.Delete(t);
      EXIT();
    } else if (c == 2) {
      ui.deleteCD();
      cin >> t;
      ad.search(t, book_root, cd_root, picture_root);
      cd_root.Delete(t);
      EXIT();
    } else {
      ui.deletePicture();
      cin >> t;
      ad.search(t, book_root, cd_root, picture_root);
      picture_root.Delete(t);
      EXIT();
    }
  } else {
    ui.getTotalUI();
    ad.getTotal(book_root, cd_root, picture_root);
    EXIT();
  }
  return 0;
}