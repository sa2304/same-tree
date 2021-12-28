#include <cassert>
#include <iostream>
#include "binary-tree-playground/binary_tree.h"

using namespace std;

class Solution {
  enum class Tag {
    Root, LeftChild, RightChild
  };

  bool isSameNodes(const pair<TreeNode *, Tag> &l, const pair<TreeNode *, Tag> &r) {
    return l.first->val == r.first->val
        && l.second == r.second;
  }

 public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    // Both empty trees are same
    if (!p && !q) {
      return true;
    }

    if (p && q) {
      queue<pair<TreeNode *, Tag>> queue_left, queue_right;
      queue_left.emplace(p, Tag::Root);
      queue_right.emplace(q, Tag::Root);
      while (not queue_left.empty()) {
        const size_t count = queue_left.size();
        if (count != queue_right.size()) {
          return false;
        }
        for (size_t i = 0; i < count; ++i) {
          auto l = queue_left.front();
          auto r = queue_right.front();
          if (not isSameNodes(l, r)) {
            return false;
          }
          // Enqueue left tree next level nodes
          TreeNode *node_left = l.first;
          if (node_left->left) {
            queue_left.emplace(node_left->left, Tag::LeftChild);
          }
          if (node_left->right) {
            queue_left.emplace(node_left->right, Tag::RightChild);
          }
          queue_left.pop();

          // Enqueue right tree next level nodes
          TreeNode *node_right = r.first;
          if (node_right->left) {
            queue_right.emplace(node_right->left, Tag::LeftChild);
          }
          if (node_right->right) {
            queue_right.emplace(node_right->right, Tag::RightChild);
          }
          queue_right.pop();
        }
      }

      return queue_right.empty();
    }

    return false;
  }
};

void TestIsSameTree() {
  Solution s;
  {
    TreeNode *a = stringToTreeNode("[1,2,3]"s);
    TreeNode *b = stringToTreeNode("[1,2,3]"s);
    assert(s.isSameTree(a, b));
  }
  {
    TreeNode *a = stringToTreeNode("[1,2]"s);
    TreeNode *b = stringToTreeNode("[1,null,3]"s);
    assert(not s.isSameTree(a, b));
  }
  {
    TreeNode *a = stringToTreeNode("[1,2,1]"s);
    TreeNode *b = stringToTreeNode("[1,1,2]"s);
    assert(not s.isSameTree(a, b));
  }
  {
    TreeNode *a = stringToTreeNode("[]"s);
    TreeNode *b = stringToTreeNode("[]"s);
    assert(s.isSameTree(a, b));
  }
  {
    TreeNode *a = stringToTreeNode("[1]"s);
    TreeNode *b = stringToTreeNode("[1,null,2]"s);
    assert(not s.isSameTree(a, b));
  }
}

int main() {
  TestIsSameTree();
  std::cout << "Ok!" << std::endl;
  return 0;
}
