/*
 * @Author: Susongfeng
 * @Date: 2020-06-18 14:14:35
 * @Last Modified by:   Susongfeng
 * @Last Modified time: 2020-06-18 14:14:35
 */

#ifndef MODEL_H
#define MODEL_H
class model {
 private:
  int id;
  int age;        // 年龄
  char* name;     // 姓名
  char* gender;   // 性别
  char* address;  // 地址
  int state;      // 状态

 public:
  void search();
  int getID() { return this->id; }
  int getAge() { return this->age; }
  char* getName() { return this->name; }
  char* getGender() { return this->gender; }
  char* getAddress() { return this->address; }
  int getState() { return this->state; }
  void setID(int i) { this->id = i; }
  void setAge(int a) { this->age = a; }
  void setName(char* p) { this->name = p; }
  void setGender(char* g) { this->gender = g; }
  void setAddress(char* p) { this->address = p; }
  void setState(int a) { this->state = a; }
};
#endif