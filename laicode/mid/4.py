import numpy as np

class ListNode(object):
    def __init__(self, val):
        self.val = val  # used to keep the value
        self.next = None  # used to refer the next list node

def printList(node):
    while node:
        print(node.val, end='->')
        node = node.next
    print()

def createList(arr = None):
    if arr is None:
        arr = np.random.randint(10, size=(10,))
    tar = np.random.randint(10)
    ptr = head = ListNode(None)
    for ele in arr:
        ptr.next = ListNode(ele)
        ptr = ptr.next
    return head.next

def removeTarFromLList(head, tar):
    dummy_head = ListNode(None)
    dummy_head.next = head
    ptr = dummy_head

    while ptr and ptr.next:
        if ptr.next.val == tar:
            ptr.next = ptr.next.next
        ptr = ptr.next
    return dummy_head.next

a = createList(arr=[5])
printList(a)
printList(removeTarFromLList(a, 5))