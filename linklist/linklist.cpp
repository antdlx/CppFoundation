//
// Created by antdl on 2017/10/24.
//
#include <iostream>
#include "linklist.h"

using namespace std;

Linklist::Linklist() {
    root = NULL;
    length = 0;
}

Linklist::~Linklist() {
    Node *tmp;
    for(int i = 0 ; i < length ; i++){
        tmp = root;
        root = root->node;
        delete tmp;
    }
}

int Linklist::Length() {
    return length;
}

//pos从0开始计算
void Linklist::Insert(Info info, int pos) {
    //判断pos不合法的情况
    if (pos > length or pos < 0){
        cout << "Pos is out of range";
    } else{
        //创建新节点
        Node *added = new Node();
        added->node = NULL;
        added->info = info;
        //在链表为空的情况下，pos的合法选择只有pos=0
        if (length == 0){
            root = added;
        } else{
            //当pos==0的情况下
            if (pos == 0){
                Node * tmp = root;
                root = added;
                added->node = tmp;
            } else{
                //pos不为零的情况下
                Node *former = root;
                for (int i = 1 ; i < pos ; i++){
                    former = former->node;
                }
                //如果直接插入末尾，则只需要前一个节点
                if (pos == length){
                    former->node = added;
                }
                //如果插入队列中，则需要前后两个节点的信息
                if (pos < length){
                    Node * latter = former->node;
                    former->node = added;
                    added->node = latter;
                }
            }
        }
        length++;
    }
}

void Linklist::InsertHead(Info info) {
    Insert(info,0);
}

//返回的数字也是从0开始计算的
int Linklist::Search(Info info) {
    int pos = -1;
    Node * tmp = root;
    if (tmp->info.id==info.id && tmp->info.name ==info.name){
        return 0;
    }
    for (int i = 1 ; i < length ; ++i){
        tmp = tmp->node;
        if (tmp->info.id==info.id && tmp->info.name ==info.name){
            pos = i;
            return pos;
        }
    }
    return pos;
}

//pos是从0开始的
void Linklist::Remove(Info info) {
    int pos = Search(info);
    if (pos < 0){
        cout << "Do not have this info"<<endl;
    } else{
        if (pos==0){
            root = root->node;
        } else{
            Node *former  = root;
            for (int i = 1 ; i < pos ;++i){
                former = former->node;
            }
            Node * target = former->node;
            former->node = target->node;
        }
        --length;
    }
}

void Linklist::Print(){
    Node * tmp = root;
    for (int i = 0; i < length; ++i) {
        cout << "id is : "<< tmp->info.id <<" name is : "<<tmp->info.name<<endl;
        tmp = tmp->node;
    }
}

void Linklist::Reverse() {
    if (length == 0){
        cout<<"length is 0"<<endl;
    }
    Node *current = root,*nextNode = current->node,*tmp;
    while (nextNode != NULL){
        tmp = nextNode->node;
        nextNode->node = current;
        current = nextNode;
        nextNode = tmp;
    }
    root->node = NULL;
    root = current;
}