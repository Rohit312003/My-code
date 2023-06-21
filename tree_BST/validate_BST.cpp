
class Solution {
public:
    bool solve(TreeNode* root,long long lef,long long righ){
        // concept is  from start in funtion call there should be two integer max and min and in each funtion call check wether it fowlloing the BST rule  
//         base case
     if(root==NULL){
            return true;
        }
        if(root->val>lef&&root->val<righ){
            
        }else{
            return false;
        }

        return solve(root->left,lef,root->val)&solve(root->right,root->val,righ);;
 
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LLONG_MIN,LLONG_MAX);
            
        }
    
};
