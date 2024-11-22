from typing import Optional


class TreeNode:
    def __init__(self, val: int) -> None:
        self.value = val
        self.left: Optional[TreeNode] = None
        self.right: Optional[TreeNode] = None

def pre_order_traversal_non_recursive(head: TreeNode) -> None:
    """
    1. 对于每一个节点，打印该节点的值，先压入该节点的右节点，再压入该节点的左节点。
    2. 弹出下一个节点，重复步骤1。
    3. 在栈为空时跳出循环。

    实际上，对于任何一个节点，总是先处理该节点，然后是该节点的左子树，最后是该节点的右子树
    """
    node_stack: list[TreeNode] = [head]
    while node_stack:
        cur = node_stack.pop()
        print(cur.value, end=" ")
        if cur.right:
            node_stack.append(cur.right)
        if cur.left:
            node_stack.append(cur.left)

def in_order_traversal_non_recursive(head: TreeNode) -> None:
    """
    1. 对于任何一棵子树，将该子树的左边界压入栈。
    2. 弹出一个栈顶节点，打印，对以该节点为头节点的子树重复步骤1。
    3. 在没有子树且节点为空时跳出循环。

    实际上，对于任何一个节点，总是先处理该节点的左子树，然后是该节点自身，最后是该节点的右子树。
    """
    node_stack: list[TreeNode] = [ ]
    cur: Optional[TreeNode] = head
    while node_stack or cur:
        if cur is not None:
            node_stack.append(cur)
            cur = cur.left
        else:
            cur = node_stack.pop()
            print(cur.value, end=" ")
            cur = cur.right

def pos_order_traversal_non_recursive_two_stack(head: TreeNode) -> None:
    """
    1. 先序遍历是中左右，由先序遍历容易得到中右左
    2. 后序遍历的本质是左右中，只需要把由先序遍历变种得到的中右左重新压入另一个栈中，顺序自然得到调换
    """
    pre_order_stack: list[TreeNode] = [head]
    pos_order_stack: list[TreeNode] = []
    while pre_order_stack:
        cur = pre_order_stack.pop()
        pos_order_stack.append(cur)
        if cur.left is not None:
            pre_order_stack.append(cur.left)
        if cur.right is not None:
            pre_order_stack.append(cur.right)
    while pos_order_stack:
        print(pos_order_stack.pop().value, end=" ")


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

    pre_order_traversal_non_recursive(head=node1)
    print()
    in_order_traversal_non_recursive(head=node1)
    print()
    pos_order_traversal_non_recursive_two_stack(head=node1)
    print()
