#include <iostream>
#include <string>

#include "control.h"
#include "ui.h"
using namespace std;
int id;         // ���
string title;   // ����
string author;  // ����
string grade;   // ����
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
  int c, t;  // ѡ����
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
  //=========================================����ѡ��
  if (c == 1) {
    ui.addUI();
    cin >> c;
    //============================���ͼ��
    if (c == 1) {
      string publisher;  // ������
      string ISBN;       // ISBN��
      int page;          // ҳ��
      ui.addBook();
      readBaseInformation();
      cin >> publisher;
      cin >> ISBN;
      cin >> page;
      int flag = ad.RepeatJudgeID(id, book_root, cd_root, picture_root);
      if (flag == 1) {
        book b(id, title, author, grade, publisher, ISBN, page);
        book_root.add(b);
        cout << "�����Ʒ�ɹ��������˳�ϵͳ" << endl;

      } else {
        cout << "����ID�ظ��������˳�ϵͳ" << endl;
      }
      EXIT();
    } else if (c == 2) {  //=====================�����Ƶ����
      string publisher;   // ��Ʒ��
      int year;           // ��Ʒ��
      int time_len;       // ʱ��
      ui.addCD();
      readBaseInformation();
      cin >> publisher;
      cin >> year;
      cin >> time_len;
      int flag = ad.RepeatJudgeID(id, book_root, cd_root, picture_root);
      if (flag == 1) {
        CD c(id, title, author, grade, publisher, year, time_len);
        cd_root.add(c);
        cout << "�����Ʒ�ɹ��������˳�ϵͳ" << endl;

      } else {
        cout << "����ID�ظ��������˳�ϵͳ" << endl;
      }
      EXIT();
    } else {
      //========================== ���ͼ��
      string country;  // ��Ʒ����
      int width;       // ��
      int length;      // ��
      ui.addPicture();
      readBaseInformation();
      cin >> country;
      cin >> length;
      cin >> width;
      int flag = ad.RepeatJudgeID(id, book_root, cd_root, picture_root);
      if (flag == 1) {
        picture p(id, title, author, grade, country, width, length);
        picture_root.add(p);
        cout << "�����Ʒ�ɹ��������˳�ϵͳ" << endl;

      } else {
        cout << "����ID�ظ��������˳�ϵͳ" << endl;
      }
      EXIT();
    }
  } else if (c == 2) {  // ============================��ѯ��Ʒ
    ui.searchUI();
    cin >> c;
    //================�������ѯ
    if (c == 1) {
      ui.searchTitle();
      cin >> title;
      ad.search(title, book_root, cd_root, picture_root);
      EXIT();
    } else if (c == 2) {  //===============��id��ѯ
      ui.searchID();
      cin >> id;
      ad.search(id, book_root, cd_root, picture_root);
      EXIT();
    } else {  //=======================������ѯ
      ui.searchClass();
      cin >> title;
      ad.search(title, 1, book_root, cd_root, picture_root);
      EXIT();
    }
  } else if (c == 3) {  //==============��ʾ��ǰ����������Ʒ
    ui.allUI();
    ad.DisplayAll(book_root, cd_root, picture_root);
    EXIT();
  } else if (c == 4) {  //===============�༭��Ʒ
    ui.editUI();
    cin >> c;
    if (c == 1) {        //======================�༭ͼ��
      string publisher;  // ������
      string ISBN;       // ISBN��
      int page;          // ҳ��
      ui.editBook();
      cin >> t;
      ad.search(t, book_root, cd_root, picture_root);
      cout << "���������룺��ţ����⣬���ߣ������������磬ISBN�룬ҳ����ÿ����"
              "��"
              "һ�����ûس����У�:"
           << endl;
      readBaseInformation();
      cin >> publisher;
      cin >> ISBN;
      cin >> page;
      int flag = ad.RepeatJudgeID(id, book_root, cd_root, picture_root);
      if (id == t) flag = 1;  // ʹ��ԭ����id
      if (flag == 1) {
        book b(id, title, author, grade, publisher, ISBN, page);
        book_root.edit(b, t);
        cout << "�༭��Ʒ�ɹ��������˳�ϵͳ" << endl;

      } else {
        cout << "����ID�ظ��������˳�ϵͳ" << endl;
      }
      EXIT();
    } else if (c == 2) {  //=========�༭����
      string publisher;   // ��Ʒ��
      int year;           // ��Ʒ��
      int time_len;       // ʱ��
      ui.editCD();
      cin >> t;
      ad.search(t, book_root, cd_root, picture_root);
      cout << "���������룺��ţ����⣬���ߣ������������ˣ������꣬��Ƶʱ����ÿ"
              "������һ�����ûس����У�:"
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
        cout << "�༭��Ʒ�ɹ��������˳�ϵͳ" << endl;

      } else {
        cout << "����ID�ظ��������˳�ϵͳ" << endl;
      }
      EXIT();
    } else {
      //================�༭ͼ��
      string country;  // ��Ʒ����
      int width;       // ��
      int length;      // ��
      ui.editPicture();
      cin >> t;
      ad.search(t, book_root, cd_root, picture_root);
      cout << "���������룺��ţ����⣬���ߣ�������������ң�������ÿ������"
              "һ�����ûس����У�:"
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
        cout << "�༭��Ʒ�ɹ��������˳�ϵͳ" << endl;
      } else {
        cout << "����ID�ظ��������˳�ϵͳ" << endl;
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