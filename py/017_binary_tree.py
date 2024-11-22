"""
对于任何一棵子树
先序：中左右
中序：左中右
后序：左右中

每一个非空节点都会经过3次，三种顺序分别是在第一、二、三次经过某个非空节点的时候打印对应节点的值
"""

from typing import Optional


class TreeNode:
    def __init__(self, val: int) -> None:
        self.value = val
        self.left: Optional[TreeNode] = None
        self.right: Optional[TreeNode] = None

def pre_order(node: Optional[TreeNode]) -> None:
    if node is None: return
    print(node.value, end="")
    pre_order(node.left)
    pre_order(node.right)

def in_order(node: Optional[TreeNode]) -> None:
    if node is None: return
    in_order(node.left)
    print(node.value, end="")
    in_order(node.right)

def pos_order(node: Optional[TreeNode]) -> None:
    if node is None: return
    pos_order(node.left)
    pos_order(node.right)
    print(node.value, end="")

if __name__ == "__main__":
    node1 = TreeNode(1)
    node2 = TreeNode(2)
    node3 = TreeNode(3)
    node4 = TreeNode(4)
    node5 = TreeNode(5)
    node6 = TreeNode(6)
    node7 = TreeNode(7)

    node1.left = node2
    node1.right = node3

    node2.left = node4
    node2.right = node5

    node3.left = node6
    node3.right = node7

    pre_order(node1)
    print()
    in_order(node1)
    print()
    pos_order(node1)


