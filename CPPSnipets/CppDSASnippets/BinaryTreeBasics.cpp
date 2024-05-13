/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
void preorder(struct node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(struct node *root)
{
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void preorderIterative(struct node *root)
{
    stack<struct node *> st;
    st.push(root);
    while (!st.empty())
    {
        struct node *tnode = st.top();
        st.pop();
        cout << tnode->data << " ";
        if (tnode->right != nullptr)
            st.push(tnode->right);
        if (tnode->left != nullptr)
            st.push(tnode->left);
    }
}

void inorderIterative(struct node *root)
{
    stack<struct node *> st;
    struct node *tnode = root;

    while (true)
    {
        if (tnode != nullptr)
        {
            st.push(tnode);
            tnode = tnode->left;
        }
        else
        {
            if (st.empty() == true)
                break;
            tnode = st.top();
            st.pop();
            cout << tnode->data << " ";
            tnode = tnode->right;
        }
    }
}

void LevelOrderTraversal(struct node *root)
{
    queue<struct node *> q;
    q.push(root);

    while (!q.empty())
    {
        struct node *tnode = q.front();
        q.pop();

        cout << tnode->data << " ";
        if (tnode->left != nullptr)
        {
            q.push(tnode->left);
        }
        if (tnode->right != nullptr)
        {
            q.push(tnode->right);
        }
    }
}

void LevelOrderTraversalLineByLine(struct node *root)
{
    queue<struct node *> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            struct node *tnode = q.front();
            q.pop();
            cout << tnode->data << " ";
            if (tnode->left != nullptr)
                q.push(tnode->left);
            if (tnode->right != nullptr)
                q.push(tnode->right);
        }
        cout << endl;
    }
}
int findMax(Node *root)
{
        //code here
        if(!root)
         return INT_MIN;
        
        return max(root->data,max(findMax(root->left),findMax(root->right)));
}
int findMin(Node *root)
{
        //code here
        if(!root)
         return INT_MAX;
        
        return min(root->data,min(findMin(root->left),findMin(root->right)));
}

int getNoOfNodes(struct node *root)
{
    if (root == nullptr)
        return 0;
    int lh = getNoOfNodes(root->left);
    int rh = getNoOfNodes(root->right);
    return lh + rh + 1;
}

int maxDepth(struct node *root)//MEASURED FROM ROOT TO PARTICULAR NODE
{
    if (root == nullptr)
        return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return max(lh, rh) + 1;
}

int HeightoftheTree(struct node *root)//MEASURED FROM PARTICULAR NODE TO LONGEST PATHLEAF
{
    if (root == nullptr)
        return 0;

    int lh = HeightoftheTree(root->left);
    int rh = HeightoftheTree(root->right);
    return max(lh, rh) + 1;
}
int isBalanced(struct node *root)
{
    int lh = isBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalanced(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return max(lh, rh) + 1;
}
int DiameterofTree(struct node *root, int &maxi)
{//longest path between any two nodes cab via root or not.
    if (root == nullptr)
        return 0;
    int lh = DiameterofTree(root->left, maxi);
    int rh = DiameterofTree(root->right, maxi);
    maxi = max(maxi, lh + rh);

    return max(lh, rh) + 1;


    // if(root === nullptr)
    //      return;
    // int lh=Height(root->left);
    // int rh=Height(root->right);
    // maxi=max(maxi,lh+rh);

    // DiameterofTree(root->left);
    // DiameterofTree(root->right);
    
}
int MaximumPathSum(struct node *root, int &maxi)
{
    if (root == nullptr)
        return 0;
    int lh = max(0, MaximumPathSum(root->left, maxi));
    int rh = max(0, MaximumPathSum(root->right, maxi));

    maxi = max(maxi, lh + rh + root->data);

    return max(lh, rh) + root->data;
}
bool isSameTree(struct node *p, struct node *q) // two different trees
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
    {
        return false;
    }
    if (p->data != q->data)
    {
        return false;
    }
    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

bool isSymmetric(struct node *p, struct node *q) // one tree checking
{
    if (p == NULL && q == NULL)
        return true;
    else if (p == NULL || q == NULL)
        return false;
    else if (p->data != q->data)
        return false;
    return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
}
vector<int> topView(struct node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    map<int, int> mp;
    queue<pair<struct node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        struct node *node = it.first;
        int line = it.second;
        if (mp.find(line) == mp.end())
            mp[line] = node->data;

        if (node->left != nullptr)
            q.push({node->left, line - 1});
        if (node->right != nullptr)
            q.push({node->right, line + 1});
    }

    for (auto it : mp)
        ans.push_back(it.second);
    return ans;
}

vector<int> bottomView(struct node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    map<int, int> mp;
    queue<pair<struct node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        struct node *node = it.first;
        int line = it.second;

        mp[line] = node->data;

        if (node->left != nullptr)
            q.push({node->left, line - 1});
        if (node->right != nullptr)
            q.push({node->right, line + 1});
    }

    for (auto it : mp)
        ans.push_back(it.second);
    return ans;
}

void rightViewRecursive(struct node *root, int level, vector<int> &ans)
{
    if (root == nullptr)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    rightViewRecursive(root->right, level + 1, ans);
    rightViewRecursive(root->left, level + 1, ans);
}

void leftViewRecursive(struct node *root, int level, vector<int> &ans)
{
    if (root == nullptr)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    leftViewRecursive(root->left, level + 1, ans);
    leftViewRecursive(root->right, level + 1, ans);
}

vector<int> rightSideViewIterative(struct node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;

    queue<struct node *> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            struct node *curr = q.front();
            q.pop();
            if (i == count - 1)
            {
                ans.push_back(curr->data);
            }
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
    }
    return ans;
}
vector<int> leftSideViewIterative(struct node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;

    queue<struct node *> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            struct node *curr = q.front();
            q.pop();
            if (i == 0)
            {
                ans.push_back(curr->data);
            }
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
    }
    return ans;
}

vector<vector<int>> verticalTraversal(struct node *root)
{
    map<int, map<int, multiset<int>>> m;
    queue<pair<struct node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    struct node *curr = root;

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        struct node *node = curr.first;
        int x = curr.second.first;
        int y = curr.second.second;

        m[x][y].insert(node->data);

        if (node->left != nullptr)
            q.push({node->left, {x - 1, y + 1}});
        if (node->right != nullptr)
            q.push({node->right, {x + 1, y + 1}});
    }
    vector<vector<int>> ans;
    for (auto p : m)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
int getMaxWidth(struct node* root) 
{
        
        queue<Node*>q;
        q.push(root);
        int maxi=INT_MIN;
        
        while(!q.empty())
        {
           int count=q.size();
           for(int i=0;i<count;i++)
           {
             Node* temp=q.front();
             q.pop();
             
             if(temp->left)
              q.push(temp->left);
             if(temp->right)
              q.push(temp->right);
           }
           maxi=max(maxi,count);
        }
        return maxi;
        // Your code here
}

vector<int> findSpiral(struct node *root)
{
    //Your code here
    //starting from right to left
     vector<int>ans;
    if(root == nullptr)
     return ans;
    
    stack<Node*>s1;
    stack<Node*>s2;
    s1.push(root);
    
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            Node* temp=s1.top();
            s1.pop();
            ans.push_back(temp->data);
            
            
            if(temp->left)
             s2.push(temp->left);
            if(temp->right)
             s2.push(temp->right);
           
        }
        while(!s2.empty())
        {
            Node* temp=s2.top();
            s2.pop();
            ans.push_back(temp->data);
            
            if(temp->right)
             s1.push(temp->right);
           
            if(temp->left)
             s1.push(temp->left);
             
            
        }
    }
    return ans;
    // queue<TreeNode*>q;
    //     q.push(root);
    //     vector<vector<int>>ans;
    //     if(root == nullptr)
    //         return ans;
    //     bool lefttoright=true;
        
    //     while(!q.empty())
    //     {
    //         int count=q.size();
    //         vector<int>temp(count);
    //         for(int i=0;i<count;i++)
    //         {
    //             TreeNode* curr=q.front();
    //             q.pop();
                
    //             int index=(lefttoright)? i : count- 1 -i;
    //             temp[index]=curr->val;
                
    //             if(curr->left != nullptr)
    //                 q.push(curr->left);
    //             if(curr->right != nullptr)
    //                 q.push(curr->right);
    //         }
            
    //         lefttoright=!lefttoright;
    //         ans.push_back(temp);
    //     }
    //     return ans;
    
}
int maxLevelSum(Node* root) 
{
        // Your code here
        queue<Node*>q;
        q.push(root);
        int maxi=INT_MIN,sum=0;
        while(!q.empty())
        {
            int count=q.size();
            vector<int>v;
            for(int i=0;i<count;i++)
            {
              Node* temp=q.front();
              q.pop();
              v.push_back(temp->data);
              if(temp->left)
               q.push(temp->left);
              if(temp->right)
               q.push(temp->right);
            }
            sum=v[0];
            for(int i=1;i<v.size();i++)
            {
               sum+=v[i];
            }
            maxi=max(maxi,sum);
        }
        return maxi;
}
int minDepth(Node *root) 
{
        
        // Your code here
        
    if (root == nullptr) {
        return 0;
    }
    // If both left and right children are null, the depth is 1
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    // If the left subtree is null, recursively find the minimum depth of the right subtree
    if (root->left == nullptr) {
        return 1 + minDepth(root->right);
    }
    // If the right subtree is null, recursively find the minimum depth of the left subtree
    if (root->right == nullptr) {
        return 1 + minDepth(root->left);
    }
    // Otherwise, recursively find the minimum depth of both subtrees and return the minimum depth
    return 1 + min(minDepth(root->left), minDepth(root->right));
}
void findPreSuc(Node* ro, Node*& pre, Node*& suc, int key)
{
        // Your code goes here
        Node* root=ro;
        
        while(root)
        {
            if(key < root->key)
            {
                suc=root;
                root=root->left;
            }
            else
                root=root->right;
        }
        root=ro;
        while(root)
        {
            if(key > root->key)
            {
                pre=root;
                root=root->right;
            }
            else
                root=root->left;
        }
}

int sumOfLeafNodes(Node *root )
{
            
             if(root == nullptr)
              return 0;
             if(root->left == nullptr && root->right == nullptr)
              return root->data;
             
             return sumOfLeafNodes(root->left)+sumOfLeafNodes(root->right);
}

Node* LCA(Node *root, int p, int q)
{
            if(root == nullptr)
             return nullptr;
            
            int curr=root->data;
            
            if(p < curr && q < curr)
             return LCA(root->left,p,q);
            else if(p > curr && q > curr)
             return LCA(root->right,p,q);
            else
             return root;
            // code here
}
int isSumProperty(Node *root)
{
     // Add your code here
     if(root == nullptr)
      return 1;
    
     if(root->left && root->right)
     {
       if(root->data != root->left->data+root->right->data)
        return 0;
     }
      if(!root->left && root->right)
     {
         if(root->data != root->right->data)
          return 0;
     }
     if(!root->right && root->left)
     {
         if(root->data != root->left->data)
          return 0;
     }
     
     return isSumProperty(root->left) && isSumProperty(root->right);
}

int isPairPresent(struct Node *root, int target)
{
    //add code here.
      vector<int>v;
      inorder(root,v);
      int i=0,j=v.size()-1;
      
      while(i<j)
      {
          if(v[i] + v[j] == target)
           return 1;
          else if(v[i]+v[j] > target)
           j--;
          else
           i++;
      }
      return 0;
}
void inorder(Node* root,int K,int &ans,int &count)
{
     // Return the Kth smallest element in the given BST
       if(root == nullptr)
        return;
       inorder(root->left,K,ans,count);
       count++;
       if(count == K)
       {
           ans=root->data;
       }
       inorder(root->right,K,ans,count);

    //    int KthSmallestElement(Node *root, int K) {
    //     // add code here.
    //     int ans=-1,count=0;
    //     inorder(root,K,ans,count);
    //     return ans;
    // }
}
   
    

int main()
{
    struct node *root = new node(5);
    root->left = new node(3);
    root->right = new node(8);
    root->left->left = new node(4);
    root->left->right = new node(9);
    root->right->left = new node(10);
    cout << "Preorder:" << endl;
    preorder(root);
    cout << endl;
    cout << "Inorder:" << endl;
    inorder(root);
    cout << endl;
    cout << "Postorder:" << endl;
    postorder(root);
    cout << endl;
    cout << "PreorderIterative:" << endl;
    preorderIterative(root);
    cout << endl;
    cout << "InorderIterative:" << endl;
    inorderIterative(root);
    cout << endl;
    cout << "LevelOrderTraversal :";
    LevelOrderTraversal(root);
    cout << endl;
    cout << "LevelOrderTraversalLineByLine :" << endl;
    LevelOrderTraversalLineByLine(root);
    cout << "Total Number of Nodes in a tree:" << getNoOfNodes(root) << endl;
    cout << "maxDepth :" << maxDepth(root) << endl;
    cout << "Heighth :" << HeightoftheTree(root) << endl;
    // cout<<"IsBalanced:"<<" ";
    // if(isBalanced(root) == -1)
    //  cout<<"NotBalanced";
    // else
    //  cout<<"Balanced";
    int maxi = 0;
    cout << "Diameter of a Binary Tree:" << DiameterofTree(root, maxi) << endl;
}