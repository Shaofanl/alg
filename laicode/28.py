from __future__ import print_function

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    @staticmethod
    def selectionSort(head):
        """
        input: ListNode head
        return: ListNode
        """
        # write your solution here


        cur_head = ListNode(None)
        fake_head = cur_head
        cur_head.next = head;
        while cur_head.next:
            min_ptr = iter_ptr = cur_head
            while iter_ptr.next:
                if iter_ptr.next.val < min_ptr.next.val:
                    min_ptr = iter_ptr
                iter_ptr = iter_ptr.next
            # print(min_ptr.next.val)

            vals = [min_ptr.next, min_ptr.next.next, cur_head.next, cur_head.next.next]
            print(map(id, vals))

            cur_head.next = vals[0]
            printLink(fake_head)
            print(map(id, vals))
            cur_head.next.next = vals[1]
            printLink(fake_head)
            print(map(id, vals))
            min_ptr.next = vals[2]
            printLink(fake_head)
            print(map(id, vals))
            min_ptr.next.next = vals[3]
            printLink(fake_head)
            print(map(id, vals))

            cur_head = cur_head.next

            import ipdb
            ipdb.set_trace()
        return fake_head.next

def printLink(ptr):
    while ptr:
        print(id(ptr), id(ptr.next), ptr.val)
        ptr = ptr.next
    print('='*50)


if __name__ == '__main__':
    arr = [5, 4, 1, 2, 6, 3]
    head = ptr = ListNode(arr[0])
    for ind in range(1, len(arr)):
        ptr.next = ListNode(arr[ind])
        ptr = ptr.next
    
    printLink(head)
    printLink(Solution.selectionSort(head))
