//
// Created by antdl on 2017/10/24.
//

#include "linklist.h"
#include <iostream>

using namespace std;

int main(){
    Linklist linklist;
    Info info1 = {1,"a"};
    Info info2 = {2,"b"};
    Info info3 = {3,"c"};
    Info info4 = {4,"d"};

    linklist.InsertHead(info1);
    linklist.Insert(info2,1);
    linklist.Insert(info3,2);
    linklist.Print();

    cout << linklist.Search(info2)<<endl;

    linklist.Remove(info2);
    linklist.Print();

    linklist.Reverse();
    linklist.Print();

    cout<<"length is : "<<linklist.Length()<<endl;

    return 0;
}

