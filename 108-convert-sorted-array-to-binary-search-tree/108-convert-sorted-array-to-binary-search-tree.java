/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    public TreeNode solver(int nums[],int start,int end){
        if(start>end) return null;
        int mid=(start+end)/2;
        TreeNode root= new TreeNode(nums[mid]);
        root.left=solver(nums,start,mid-1);
        root.right=solver(nums,mid+1,end);
        return root;
    }
    
    public TreeNode sortedArrayToBST(int[] nums) {
        int start=0,end=nums.length-1;
        return solver(nums,start,end);
    }
}