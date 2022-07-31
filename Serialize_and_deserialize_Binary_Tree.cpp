class Codec {
    string ser;
    string dser;
    int i;
    void Serializehelper(TreeNode* root)
    {
        if(root == NULL)
        {
            ser += "N ";
            return;
        }
        ser += to_string(root->val) + " ";
        Serializehelper(root->left);
        Serializehelper(root->right);
    }
    TreeNode* Dserializehelper()
    {
        if(i > dser.size() || dser[i] == 'N')
        {
            i = i+2;
            return NULL;
        }
        string temp;
        while(dser[i] != ' ')
            temp += dser[i++];
        TreeNode* root = new TreeNode(stoi(temp));
        i++;
        root->left = Dserializehelper();
        root->right = Dserializehelper();
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        ser = "";
        Serializehelper(root);
        return ser;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        dser = data;
        i = 0;
        return Dserializehelper();
    }
};