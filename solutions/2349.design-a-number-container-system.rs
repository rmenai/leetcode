// @leet start
use std::collections::{BTreeSet, HashMap};

struct NumberContainers {
    index_to_num: HashMap<i32, i32>,
    num_to_index: HashMap<i32, BTreeSet<i32>>,
}

impl NumberContainers {
    fn new() -> Self {
        Self {
            index_to_num: HashMap::new(),
            num_to_index: HashMap::new(),
        }
    }

    fn change(&mut self, index: i32, number: i32) {
        if let Some(old) = self.index_to_num.get(&index) {
            if let Some(indices) = self.num_to_index.get_mut(old) {
                indices.remove(&index);
                if indices.is_empty() {
                    self.num_to_index.remove(old);
                }
            }
        }

        self.index_to_num.insert(index, number);
        self.num_to_index.entry(number).or_default().insert(index);
    }

    fn find(&self, number: i32) -> i32 {
        self.num_to_index
            .get(&number)
            .and_then(|indices| indices.iter().next().copied())
            .unwrap_or(-1)
    }
}
// @leet end

