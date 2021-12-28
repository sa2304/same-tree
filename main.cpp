#include <cassert>
#include <iostream>
#include "binary-tree-playground/binary_tree.h"

using namespace std;

class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    // FIXME
    return false;
  }
};

void TestIsSameTree() {
  Solution s;
  {
    TreeNode* a = stringToTreeNode("[1,2,3]"s);
    TreeNode* b = stringToTreeNode("[1,2,3]"s);
    assert(s.isSameTree(a, b));
  }
  {
    TreeNode* a = stringToTreeNode("[1,2]"s);
    TreeNode* b = stringToTreeNode("[1,null,3]"s);
    assert(not s.isSameTree(a, b));
  }
  {
    TreeNode* a = stringToTreeNode("[1,2,1]"s);
    TreeNode* b = stringToTreeNode("[1,1,2]"s);
    assert(not s.isSameTree(a, b));
  }
}

int main() {
  TestIsSameTree();
  std::cout << "Ok!" << std::endl;
  return 0;
}
