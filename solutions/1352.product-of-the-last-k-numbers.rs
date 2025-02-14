// @leet start
struct ProductOfNumbers {
    prefix: Vec<Vec<u32>>,
}

impl ProductOfNumbers {
    fn new() -> Self {
        Self {
            prefix: vec![vec![0; 101]],
        }
    }

    fn add(&mut self, num: i32) {
        let mut last = self.prefix.last().unwrap().to_vec();
        last[num as usize] += 1;
        self.prefix.push(last);
    }

    fn get_product(&self, k: i32) -> i32 {
        let total = &self.prefix.last().unwrap();
        let extra = &self.prefix[self.prefix.len() - 1 - k as usize];

        (0..=100)
            .map(|x| (x as i32).pow(total[x] - extra[x]))
            .product()
    }
}
// @leet end

