impl Solution {
    pub fn merge_two_lists(mut list1: Option<Box<ListNode>>, mut list2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode::new(0));
        let mut tail = &mut dummy;

        while list1.is_some() && list2.is_some() {
            if list1.as_ref().unwrap().val < list2.as_ref().unwrap().val {
                let next = list1.as_mut().unwrap().next.take();
                tail.next = list1.take();
                list1 = next;
            } else {
                let next = list2.as_mut().unwrap().next.take();
                tail.next = list2.take();
                list2 = next;
            }
            tail = tail.next.as_mut().unwrap();
        }

        if list1.is_some() {
            tail.next = list1;
        } else {
            tail.next = list2;
        }

        dummy.next
    }
}
