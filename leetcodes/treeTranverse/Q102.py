# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        if not root:
            return ans
        st = [root]
        while len(st):
            layer = st
            st = []
            temp = []
            for i in layer:
                if i.left:
                    st.append(i.left)
                if i.right:
                    st.append(i.right)
                temp.append(i.val)
            ans.append(temp)
        return ans

