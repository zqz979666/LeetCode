#include <stdio.h>
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

typedef struct TreeNode{
    TreeNode *lchild;
    TreeNode *rchild;
    int value;
}TreeNode;

//瞎几把一棵完全二叉树，从1、2……开始编号
TreeNode* initTree(int n)
{
    TreeNode *node = new TreeNode();
    node->value = ++n;
    if(n>=3) return node;
    node->lchild=initTree(node->value);
    node->rchild=initTree(node->value+1);
    return node;
}

int main()
{
    /* 思路： 1.通过一个队列queue来层次遍历。2.通过flag标识每层的最右节点
              2.通过flagplus来统计访问每一层节点时它们的子节点个数，在访问最右节点时加到flag上 
    */
    TreeNode* root= initTree(0);
    TreeNode* queue[20];
    int head = -1,tail = -1;
    int flag = 1;//标识该层最右节点,第一个为根节点
    int flagplus = 0;
    int count = 0;
    int layer = 0;
    vector<vector<int> > result(100);
    queue[++head] =root;
    TreeNode* p;
    //层次遍历二叉树
    while(head != tail)
    {
        p = queue[++tail];
        result[layer].push_back(p->value);
        count++;
        
        if(p->lchild != NULL)
        {   queue[++head] = p->lchild;
            ++flagplus;
        }
        if(p->rchild != NULL)
        {
            queue[++head] = p->rchild;
            ++flagplus;
        }
        if(count == flag)
        {
            ++layer;
            flag = flag + flagplus;
            flagplus = 0;
        }
    }

    //打印result
    vector<vector<int>> result_reverse(layer);
    //vector<int>::iterator it;
    for(int i = layer -1 ; i >= 0 ; --i)
    {
        for(int j= 0 ;j < result[i].size() ; ++j)
        {
            result_reverse[layer - i - 1].push_back(result[i][j]);
            cout << result[i][j] << " " ;
        }
        cout << endl;
    }


    system("pause");
    return 0;
}