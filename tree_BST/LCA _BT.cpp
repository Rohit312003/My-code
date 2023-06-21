// it can be optimise more
class Solution {
public:
    
     void solve(TreeNode* root,int k,vector<TreeNode*> &path,vector<TreeNode*> &patho){
        
        if(root==nullptr){
            return;
        }
        path.push_back(root);
         if(root->val==k){
             patho=path;
             return;
         }
         
         solve(root->left,k,path,patho);
         solve(root->right,k,path,patho);
         
        path.pop_back();
        
        
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      vector<TreeNode*> path1(100005); 
      vector<TreeNode*> path2(100005); 
    vector<TreeNode*> o;
    vector<TreeNode*> m;
        solve(root,p->val,o,path1);
        solve(root,q->val,m,path2);
       TreeNode* l=0;
        cout<<path1.size()<<endl;
        cout<<endl;
        for(int i=0;i<min(path1.size(),path2.size());i++){
        if(path1[i]->val==path2[i]->val){
              l=path1[i];
          }else{
              break;
          }
              
        }
        
        
        return l;
        
    }
};
