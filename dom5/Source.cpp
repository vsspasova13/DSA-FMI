#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void _inorderTraversal(TreeNode* root, vector<int>& result) {
    if (!root) {
        return;
    }
    int sum = 0;
    _inorderTraversal(root->left, result);
    sum += root->val;
    result.push_back(sum);
    _inorderTraversal(root->right, result);
}

int main() {

    int n;
    cin >> n;

    vector<TreeNode*> nums(n);
    vector<pair<int, int>> neigb(n);
    //vector<tuple<TreeNode*, int, int>> coord(n);

    for (int i = 0; i < n; i++)
    {
        int p, x, y;
        cin >> p >> x >> y;
        TreeNode* t = new TreeNode(p);
        nums[i]=t;
        neigb[i]={x,y };
    }

    TreeNode* root = nums[0];
    //coord[0]={root,0,0};


    for (int i = 0; i < n; i++)
    {
        if (neigb[i].first != -1) {
            nums[i]->left = nums[neigb[i].first];
            //coord[neigb[i].first]={nums[neigb[i].first], <get1>(coord[i])-1, <get2>(coord[i])1};
        }
        if (neigb[i].second != -1) {
            nums[i]->right = nums[neigb[i].second];
            // coord[neigb[i].second]={nums[neigb[i].second], <get1>(coord[i])+1, <get2>(coord[i])1};
        }
    }

    vector<int> res;
    _inorderTraversal(nums[0], res);

    cout << nums[0]->left->val;

    /*
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    */
}
