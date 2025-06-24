class Solution(object):
    def lcaDeepestLeaves(self, root):
        node, _ = self.dfs(root)
        return node
    def dfs(self, node):
        if not node:
            return None, 0
        left_node, left_height = self.dfs(node.left)
        right_node, right_height = self.dfs(node.right)
        if left_height > right_height:
            return left_node, left_height + 1
        elif right_height > left_height:
            return right_node, right_height + 1
        else:
            return node, left_height + 1