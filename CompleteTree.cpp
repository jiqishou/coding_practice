/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, 
and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h. //what does the last sentence mean? 1 and 2h nodes iclusive?
I'm not sure what that sentence means.... but basically it's like
      1
   2        3
  4 5
 like this, last level may not be fully filled. ok.
*/

int CountCompleteTreeNodes(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    
    return CountNodes(root);
}

int CountNodes(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftH = MaxHeight(root->left);
    int rightH = MaxHeight(root->right);
    
    int nodes = 1;  // for the root node
    if (leftH == rightH) {  //left height == right height, at least left side is a full complete subtree
        nodes += pow(2, leftH) - 1;
        nodes += CountNodes(root->right);
        return nodes;
    }
    if (leftH > rightH) {   //leftH > rightH, at least right side is a full complete subtree
        nodes += pow(2, rightH) - 1;
        nodes += CountNodes(root->left);
        return nodes;
    }
}

int MaxHeight(TreeNode *root) {
    int height = 0;
    while (root->left != NULL) {
        root = root->left;
        height++;
    }
    return height;
}

Time Complexity O(lg2n)
Space Complexity(O(n/2)? yes, space i'm not sure, maybe it's n also