/*

LCA of BST

Given a binary search tree and two nodes, find LCA(Lowest Common Ancestor) of the given two nodes in the BST. Read about LCA if you are having doubts about the definition.
If out of 2 nodes only one node is present, return that node.
If both are not present, return -1.
Input format :
Line 1 :  Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Two integers, Node 1 and Node 2 (separated by space)
Output Format :
LCA
Constraints :
1 <= N <= 1000
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 10
Sample Output 1:
8
Sample Input 2:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 6
Sample Output 2:
5
Sample Input 3:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12 78
Sample Output 3:
-1

*/




/*

Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).

The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located farthest from the root. Computation of lowest common ancestors may be useful, for instance, as part of a procedure for determining the distance between pairs of nodes in a tree: the distance from n1 to n2 can be computed as the distance from the root to n1, plus the distance from the root to n2, minus twice the distance from the root to their lowest common ancestor.
*/




// o(h) solution but in binary tree (not BST) required o(n)

int lca(BinaryTreeNode<int>* root , int val1 , int val2){
	if(root==NULL)return -1;
  if(root->data==val1 || root->data==val2)return root->data;
  
  int left=-1;
  int right=-1;
 
  
  if(root->left && val1 < root->data)
  		left=lca(root->left,val1,val2);
 
  if(root->right && val2 > root->data)
    	right=lca(root->right,val1,val2);
  
  
   if(left!=-1 && right!=-1)return root->data;
   else if(left!=-1 && right ==-1)return left;
   else if(left==-1 && right !=-1)return right;
   else return -1;
 
}

int lcaInBST(BinaryTreeNode<int>* root , int val1 , int val2){

 
  return lca(root , val1 < val2 ? val1 : val2 , val1 > val2 ? val1 : val2);
}

