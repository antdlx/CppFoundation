//
// Created by antdl on 2017/10/24.
//

#ifndef CPPFOUNDATION_LINKLIST_H
#define CPPFOUNDATION_LINKLIST_H

#include <string>

using std::string;

struct Info {
    int id;
    string name;
};

struct Node {
    Info info;
    Node *node;
};

class Linklist{
public:
    //构造函数
    Linklist();
    //将info插入pos
    void Insert(Info info, int pos);
    //插入首部
    void InsertHead(Info info);
    //删除info内容
    void Remove(Info info);
    //返回长度
    int Length();
    //链表反序
    void Reverse();
    //搜索info
    int Search(Info info);
    //打印
    void Print();
    //析构函数
    ~Linklist();

private:
    Node *root;
    int length;
};

#endif //CPPFOUNDATION_LINKLIST_H
