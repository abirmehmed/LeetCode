# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        # Create dummy head for result linked list
        dummy_head = ListNode(0)
        current = dummy_head
        
        # Initialize carry
        carry = 0
        
        # Process both linked lists until we reach the end of both
        while l1 or l2:
            # Get values from current nodes (or 0 if we've reached the end)
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0
            
            # Calculate sum and new carry
            total = x + y + carry
            carry = total // 10  # Integer division for carry
            digit = total % 10   # Remainder for current digit
            
            # Create new node with current digit
            current.next = ListNode(digit)
            current = current.next
            
            # Move to next nodes if available
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        
        # If there's a final carry, add another node
        if carry > 0:
            current.next = ListNode(carry)
        
        # Return result list (skip the dummy head)
        return dummy_head.next