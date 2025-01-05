// @leet start
impl Solution {
    pub fn delete_duplicates(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() {
            return head;
        }

        let mut head = head;
        let mut current = head.as_mut().unwrap();

        while let Some(next) = current.next.as_mut() {
            if current.val == next.val {
                current.next = next.next.take();
            } else {
                current = current.next.as_mut().unwrap();
            }
        }

        head
    }
}
// @leet end

