#include<iostream>
// #include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    unordered_map <TreeNode*, int> f, g;
    //深度遍历二叉树  
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        dfs(node->left);
        dfs(node->right);
        // f(node) 表示选择 node节点，node 节点的子树上被选择的节点的最大权值和
        // g(node) 表示不选择 node节点，node 节点的子树上被选择的节点的最大权值和
        // 当 node 被选中时，node 的左右孩子都不能被选中，故 node 被选中情况下子树上被选中点的最大权值和为 l 和 r 
        // 不被选中的最大权值和相加，即 f(o)=g(l)+g(r)。
        // 当 node 不被选中时，node 的左右孩子可以被选中，也可以不被选中。对于 node 的某个具体的孩子 x，它对 node 的贡献是 x 被选中和不被选中情况下权值和的较大值。
        // 故 g(o)=max⁡{f(l),g(l)}+max⁡{f(r),g(r)}
        f[node] = node->val + g[node->left] + g[node->right];
        g[node] = max(f[node->left], g[node->left]) + max(f[node->right], g[node->right]);
    }

    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root], g[root]);
    }
};

/* leetcode 337 打家劫舍3
小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。

除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，
聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。

给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。 */
