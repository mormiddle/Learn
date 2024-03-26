#include <iostream>
#include <map>
#include <string>
//#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, string> mymap{ {"STL教程","http://c.biancheng.net/java/"} };
    cout << mymap["STL教程"] << endl;

    //向 map 容器添加新键值对
    mymap["Python教程"] = "http://c.biancheng.net/python/";
    system("pause");
    return 0;
}