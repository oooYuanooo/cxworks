#include <iostream>
#include <sstream>
#include "picosha2.h"
#include <string>
#include <vector>
using namespace std;

class MTnode
{
private:
    string hash;
    MTnode* parent;
    MTnode* children[2];
public:
    MTnode();
    MTnode* getParent();
    void setChildren(MTnode* lchild, MTnode* rchild);
    MTnode* getChildren(int index);
    void setParent(MTnode* parent);
    string getHash();
    int checkDir();
    MTnode* getSibling();
    void setHash(string hash);
    virtual ~MTnode();
};
MTnode::MTnode()
{
    parent = nullptr;
    children[0] = nullptr;
    children[1] = nullptr;
}
void MTnode::setHash(string hash)
{
    this->hash = picosha2::hash256_hex_string(hash);
}
MTnode* MTnode::getParent()
{
    return parent;
}
void MTnode::setParent(MTnode* parent)
{
    this->parent = parent;
}
void MTnode::setChildren(MTnode* lchild, MTnode* rchild)
{
    children[0] = lchild;
    children[1] = rchild;
}
MTnode* MTnode::getSibling() //�����ӵõ��Һ��ӣ����Һ��ӵõ�����
{
    //�õ��ýڵ�ĸ��ڵ�
    MTnode* parent = getParent();

    //�жϸ��ڵ�����Ӻͱ��ڵ��Ƿ���ͬ
    //��ͬ�����Һ��ӣ���ͬ��������
    return parent->getChildren(0) == this ? parent->getChildren(1) : parent->getChildren(0);
}
MTnode* MTnode::getChildren(int index)
{
    return index <= 1 ? children[index] : nullptr;
}
string MTnode::getHash()
{
    return hash;
}
int MTnode::checkDir()
{
    //����丸�ڵ�������Ǹýڵ� ����0 �����򷵻�1
    return parent->getChildren(0) == this ? 0 : 1;
}
MTnode::~MTnode() {}

