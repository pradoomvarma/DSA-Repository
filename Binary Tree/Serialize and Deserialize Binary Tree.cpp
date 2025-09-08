// Solution 1
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
public:

    // Encodes a tree to a single string.

    void preorder(TreeNode* root, string &str) {
        if(!root) {
            str += "null ";
            return;
        }

        str += to_string(root->val) + " ";
        preorder(root->left, str);
        preorder(root->right, str);
    }

    string serialize(TreeNode* root) {
        string str = "";
        preorder(root, str);
        str.pop_back();
        cout << str << endl;
        return str;
    }

    // Decodes your encoded data to tree.

    TreeNode* solve(vector<string> &str, int &i) {
        if(i >= str.size()) return 0;
        if(str[i] == "null") return 0;

        int val = stoi(str[i]);
        TreeNode* root = new TreeNode(val);

        ++i;
        root->left = solve(str, i);
        ++i;
        root->right = solve(str, i);

        return root;
    }

    TreeNode* deserialize(string data) {
        vector<string> str;
        string word;
        stringstream ss(data);
        while(ss >> word) {
            str.push_back(word);
        }
        int i = 0;
        return solve(str, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// Solution 2 : BFS
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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        if(!root) return str;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto node = q.front();  q.pop();
            if(node) str += to_string(node->val) + ",";
            else str += "#,";

            if(node) {
                q.push(node->left);
                q.push(node->right);
            }
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return 0;

        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto curr = q.front();  q.pop();

            getline(ss, str, ',');
            if(str != "#") {
                TreeNode* node = new TreeNode(stoi(str));
                curr->left = node;
                q.push(node);
            }

            getline(ss, str, ',');
            if(str != "#") {
                TreeNode* node = new TreeNode(stoi(str));
                curr->right = node;
                q.push(node);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));