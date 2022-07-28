#include "MTnode.h"
#include <iostream>
#include "picosha2.h"
using namespace std;
class MT
{
private:
    string merkleRoot;

    int leafdouble(vector<MTnode*>& nodev);//保证叶子结点为双数
    void printHash(vector<MTnode*> v);//打印节点的哈希值
    vector<vector<MTnode*>> base; //节点列表
public:
    MT();
    void buildMT();
    void buildBase(vector<string> basel);//建立叶子节点列表
    void iterateUp(int element);
    int verify(string hash);
    virtual ~MT();
};

MT::MT() {}
int MT::leafdouble(vector<MTnode*>& nodev) 
{
    int vectSize = nodev.size();
    if ((vectSize % 2) != 0) //元素个数为奇数，把最后一个节点push_back一次
    {
        nodev.push_back(nodev.end()[-1]); //push_back最后一个元素 
        vectSize++;
    }
    return vectSize;
}
void MT::buildMT() 
{
    do
    {
        vector<MTnode*> new_nodes;
        leafdouble(base.end()[-1]); //传入尾元素

        for (int i = 0; i < base.end()[-1].size(); i += 2)
        {
            MTnode* new_parent = new MTnode;
            //设置父亲节点 传入最后一个元素 即一个节点列表的第i和i+1个
            base.end()[-1][i]->setParent(new_parent);
            base.end()[-1][i + 1]->setParent(new_parent);

            //通过两个孩子节点的哈希值设置父节点哈希值
            new_parent->setHash(base.end()[-1][i]->getHash() + base.end()[-1][i + 1]->getHash());
            //将该父节点的左右孩子节点设置为这两个
            new_parent->setChildren(base.end()[-1][i], base.end()[-1][i + 1]);
            //将new_parent压入new_nodes
            new_nodes.push_back(new_parent);

            //cout << "Hash togther: " << base.end()[-1][i]->getHash() << \
            //    " and " << base.end()[-1][i + 1]->getHash() << " attached: " << \
            //    & new_parent << endl;
        }

        base.push_back(new_nodes);
        cout << "上一层结点个数为 " << base.end()[-1].size() << endl;
        cout << "该层结点的哈希值如下：" ;
        printHash(new_nodes);
        cout << "================================================================"<<endl;
    } while (base.end()[-1].size() > 1); 

    merkleRoot = base.end()[-1][0]->getHash(); //根节点的哈希值
    cout << endl;
    cout << "MT根结点哈希值为 : " << merkleRoot << endl << endl;
}
void MT::printHash(vector<MTnode*> v) 
{
    cout << endl;

    for (MTnode* el : v)
    {
        cout << el->getHash() << endl;
    }
}
void MT::buildBase(vector<string> basel) 
{
    vector<MTnode*> new_nodes;

    cout << "MT叶子结点的哈希值如下 : " << endl;

    for (auto leaf : basel)
    {
        MTnode* new_node = new MTnode;
        new_node->setHash(leaf);
        cout << new_node->getHash() << endl;

        new_nodes.push_back(new_node);
    }

    base.push_back(new_nodes);
    cout << endl;
}
int MT::verify(string hash)
{
    MTnode* enode = nullptr;
    string hash1 = hash; //想验证的叶子节点的额哈希值

    //如果base[0] 即叶子节点中有一个节点的hash值和其相等
    for (int i = 0; i < base[0].size(); i++)
    {
        if (base[0][i]->getHash() == hash)
        {
            enode = base[0][i]; //指向该节点
        }
    }
    if (enode == nullptr)
    {
        return 0;
    }

    cout << "叶子结点匹配成功！！！哈希值为：" << hash1 << endl;

    do  //验证merkle tree是否改变过 
    {
        //父节点的哈希是左孩子的哈希string+右孩子的哈希string
        //如果el_node的父节点的左节点是el_node
        if (enode->checkDir() == 0)
        {
            //是左孩子就 做孩子的哈希string+右孩子的哈希string
            hash1 = picosha2::hash256_hex_string(hash1 + enode->getSibling()->getHash());
        }
        else
        {
            hash1 = picosha2::hash256_hex_string(enode->getSibling()->getHash() + hash1);
        }

        cout << "当前层匹配成功！！！！哈希值为：" << hash1 << endl;

        enode = enode->getParent();
    } while ((enode->getParent()) != NULL); //到达根节点

    return hash1 == merkleRoot ? 1 : 0;
}
void MT::iterateUp(int elem) {
    MTnode* el_node = this->base[0][elem];

    do {
        cout << "当前哈希值为: " << el_node->getHash() << '\n';
    } while ((el_node = el_node->getParent()) != NULL);

}
MT::~MT() {}
