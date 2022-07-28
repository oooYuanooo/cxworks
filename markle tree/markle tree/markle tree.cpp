#include <iostream>
#include "MT.h"
#include "picosha2.h"
using namespace std;


//自定义函数用于生成固定长度的随机小写英文字符串
string rand_str(const int len)  
{
    string str;              
    char c;                     
    int i;                    
    for (i = 0; i < len; i++)
    {
        c = 'a' + rand() % 26;
        str.push_back(c);       
    }
    return str;                 
}

//打印容器中的值
void print(vector<string> vector1) {
    for (int i = 0; i < vector1.size(); i++)
        cout << vector1[i] << " ";

    cout << endl;
}

int main()
{
    cout << "==========Creating 10w MT leaves=========== " << endl;
    vector<string> v;
    int i = 0;
    while (i<100000)
    {
        string str;
        str = rand_str(3);
        v.push_back(str);
        i++;
    }
    cout << "MT的叶子结点如下：" << endl;
    print(v);

    cout << "请输入要验证的叶子结点： " << endl;
    string cstr = "";
    string cstrh = "";
    cin >> cstr;
    cstrh = picosha2::hash256_hex_string(cstr);
    MT mtree;
    cout << endl;
    cout << "==========Creating  MT =========== " << endl;
    cout << endl;
    mtree.buildBase(v);
    mtree.buildMT();
    cout << "===================检验" << cstr << "是否包含在MT中====================" << endl;
    cout << "即检验哈希值 " << cstrh << " 是否包含在MT中 " << endl;
    cout << endl;
    if (mtree.verify(cstrh))
    {
        cout <<endl<< "成功匹配到根结点！因此该结点包含在MT中"<<endl;
    }
    else
    {
        cout <<endl<< "当前层匹配错误！！故该结点不包含在MT中"<<endl;
    }
    return 0;
}