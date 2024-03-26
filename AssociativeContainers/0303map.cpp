//C++ STL map容器详解
#include <iostream>
#include <map>
#include <string>
//#include <bits/stdc++.h>
using namespace std;

int main() {
    //创建空 map 容器，默认根据个键值对中键的值，对键值对做降序排序
    map<string, string, greater<string>> myMap;
    //调用 emplace() 方法，直接向 myMap 容器中指定位置构造新键值对
    myMap.emplace("C语言教程","http://c.biancheng.net/c/");
    myMap.emplace("Python教程", "http://c.biancheng.net/python/");
    myMap.emplace("STL教程", "http://c.biancheng.net/stl/");
    //输出当前 myMap 容器存储键值对的个数
    cout << "myMap size is : " << myMap.size() << endl;
    // 判断当前 myMap 容器是否为空
    if(!myMap.empty()) {
        //借助 myMap 容器迭代器，将该容器的键值对逐个输出
        for(auto i = myMap.begin(); i != myMap.end(); i++) {
            cout << i->first << " " << i->second << endl;
        }
    }
    system("pause");
    return 0;
}