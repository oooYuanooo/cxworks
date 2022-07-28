#include "MTnode.h"
#include <iostream>
#include "picosha2.h"
using namespace std;
class MT
{
private:
    string merkleRoot;

    int leafdouble(vector<MTnode*>& nodev);//��֤Ҷ�ӽ��Ϊ˫��
    void printHash(vector<MTnode*> v);//��ӡ�ڵ�Ĺ�ϣֵ
    vector<vector<MTnode*>> base; //�ڵ��б�
public:
    MT();
    void buildMT();
    void buildBase(vector<string> basel);//����Ҷ�ӽڵ��б�
    void iterateUp(int element);
    int verify(string hash);
    virtual ~MT();
};

MT::MT() {}
int MT::leafdouble(vector<MTnode*>& nodev) 
{
    int vectSize = nodev.size();
    if ((vectSize % 2) != 0) //Ԫ�ظ���Ϊ�����������һ���ڵ�push_backһ��
    {
        nodev.push_back(nodev.end()[-1]); //push_back���һ��Ԫ�� 
        vectSize++;
    }
    return vectSize;
}
void MT::buildMT() 
{
    do
    {
        vector<MTnode*> new_nodes;
        leafdouble(base.end()[-1]); //����βԪ��

        for (int i = 0; i < base.end()[-1].size(); i += 2)
        {
            MTnode* new_parent = new MTnode;
            //���ø��׽ڵ� �������һ��Ԫ�� ��һ���ڵ��б�ĵ�i��i+1��
            base.end()[-1][i]->setParent(new_parent);
            base.end()[-1][i + 1]->setParent(new_parent);

            //ͨ���������ӽڵ�Ĺ�ϣֵ���ø��ڵ��ϣֵ
            new_parent->setHash(base.end()[-1][i]->getHash() + base.end()[-1][i + 1]->getHash());
            //���ø��ڵ�����Һ��ӽڵ�����Ϊ������
            new_parent->setChildren(base.end()[-1][i], base.end()[-1][i + 1]);
            //��new_parentѹ��new_nodes
            new_nodes.push_back(new_parent);

            //cout << "Hash togther: " << base.end()[-1][i]->getHash() << \
            //    " and " << base.end()[-1][i + 1]->getHash() << " attached: " << \
            //    & new_parent << endl;
        }

        base.push_back(new_nodes);
        cout << "��һ�������Ϊ " << base.end()[-1].size() << endl;
        cout << "�ò���Ĺ�ϣֵ���£�" ;
        printHash(new_nodes);
        cout << "================================================================"<<endl;
    } while (base.end()[-1].size() > 1); 

    merkleRoot = base.end()[-1][0]->getHash(); //���ڵ�Ĺ�ϣֵ
    cout << endl;
    cout << "MT������ϣֵΪ : " << merkleRoot << endl << endl;
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

    cout << "MTҶ�ӽ��Ĺ�ϣֵ���� : " << endl;

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
    string hash1 = hash; //����֤��Ҷ�ӽڵ�Ķ��ϣֵ

    //���base[0] ��Ҷ�ӽڵ�����һ���ڵ��hashֵ�������
    for (int i = 0; i < base[0].size(); i++)
    {
        if (base[0][i]->getHash() == hash)
        {
            enode = base[0][i]; //ָ��ýڵ�
        }
    }
    if (enode == nullptr)
    {
        return 0;
    }

    cout << "Ҷ�ӽ��ƥ��ɹ���������ϣֵΪ��" << hash1 << endl;

    do  //��֤merkle tree�Ƿ�ı�� 
    {
        //���ڵ�Ĺ�ϣ�����ӵĹ�ϣstring+�Һ��ӵĹ�ϣstring
        //���el_node�ĸ��ڵ����ڵ���el_node
        if (enode->checkDir() == 0)
        {
            //�����Ӿ� �����ӵĹ�ϣstring+�Һ��ӵĹ�ϣstring
            hash1 = picosha2::hash256_hex_string(hash1 + enode->getSibling()->getHash());
        }
        else
        {
            hash1 = picosha2::hash256_hex_string(enode->getSibling()->getHash() + hash1);
        }

        cout << "��ǰ��ƥ��ɹ�����������ϣֵΪ��" << hash1 << endl;

        enode = enode->getParent();
    } while ((enode->getParent()) != NULL); //������ڵ�

    return hash1 == merkleRoot ? 1 : 0;
}
void MT::iterateUp(int elem) {
    MTnode* el_node = this->base[0][elem];

    do {
        cout << "��ǰ��ϣֵΪ: " << el_node->getHash() << '\n';
    } while ((el_node = el_node->getParent()) != NULL);

}
MT::~MT() {}
