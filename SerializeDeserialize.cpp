class Codec {
public:
    void inorder(TreeNode *root, string &str) {
        if (root == NULL) {
            return;
        }
        
        inorder(root->left, str);
        str += root->val + '0';
        inorder(root->right, str); 
    }

    void preorder(TreeNode *root, string &str) {
        if (root == NULL) {
            return;
        }
        
        str += root->val + '0';
        preorder(root->left, str);
        preorder(root->right, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str_preorder = "";
        string str_inorder = "";
        if (root == NULL) {
            return "";
        }
        
        preorder(root, str_preorder);
        inorder(root, str_inorder);
        
        return str_preorder + " " + str_inorder;
    }

    TreeNode *buildT(string pre_order, string in_order, int pre_start, int in_start, int in_end) {
        if (in_start > in_end) {
            return NULL;
        }
        
        int pivot = pre_order[pre_start] - '0';
        int index;
        for (int i = in_start; i <= in_end; i++) {
            int num = in_order[i] - '0';
            if (pivot == num) {
                index = i;
            }
        }
        
        TreeNode *root = new TreeNode(pivot);
        root->left = buildT(pre_order, in_order, pre_start + 1, in_start, index - 1);
        root->right = buildT(pre_order, in_order, index + 1 + (pre_start - in_start), index + 1, in_end);
        return root;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return NULL;
        }
        string str_preorder = "";
        string str_inorder = "";
        bool pre = true;
        for (int i = 0; i < data.size(); i++) {
            if (pre == true) {
                if (data[i] == ' ') {
                    pre = false;
                    continue;
                }
                str_preorder += data[i];   
            } else {
                str_inorder += data[i];
            }
        }
        
        return buildT(str_preorder, str_inorder, 0, 0, str_inorder.size() - 1);
    }
};