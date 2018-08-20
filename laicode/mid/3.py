import numpy as np


class ListNode(object):
    def __init__(self, val):
        self.val = val  # used to keep the value
        self.next = None  # used to refer the next list node

def mergeTwo(head_a, head_b):
    dummy_head = ListNode(None)

    ptr_a, ptr_b = head_a, head_b
    ptr_ans = dummy_head

    while ptr_a or ptr_b:  # still have elements
        if ptr_b is None or (ptr_a is not None and ptr_a.val > ptr_b.val):
            # list b is empty, or
            # list a is not empty and has a greater head
            ptr_ans.next = ptr_a
            ptr_a = ptr_a.next
        else:
            ptr_ans.next = ptr_b
            ptr_b = ptr_b.next
        ptr_ans = ptr_ans.next
    return dummy_head.next



def createReverseSortedList():
    arr = sorted(np.random.randint(100, size=(10,)), reverse=True)
    ptr = head = ListNode(None)
    for ele in arr:
        ptr.next = ListNode(ele)
        ptr = ptr.next
    return head.next

def printList(node):
    while node:
        print(node.val, end='->')
        node = node.next
    print()

def test():
    for _ in range(1):
        la, lb = createReverseSortedList(), createReverseSortedList()
        printList(la)
        printList(lb)
        printList(mergeTwo(la, lb))
test()
