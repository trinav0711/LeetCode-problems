/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void serializeHelper(TreeNode* node, ostringstream& out) {
        if (!node) {
            out << "N "; // 'N' marks a NULL pointer
            return;
        }
        // Write the value followed by a space delimiter
        out << node->val << " "; 
        serializeHelper(node->left, out);
        serializeHelper(node->right, out);
    }

    TreeNode* deserializeHelper(istringstream& in) {
        string val;
        in >> val; // Automatically extracts characters until the next space
        
        if (val == "N" || val.empty()) {
            return nullptr;
        }
        
        // Create the current node
        TreeNode* node = new TreeNode(stoi(val));
        
        // Recursively build the left and right subtrees
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        
        return node;
    }
public:

    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));