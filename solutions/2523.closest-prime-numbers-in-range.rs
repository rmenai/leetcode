// @leet start
impl Solution {
    pub fn closest_primes(left: i32, right: i32) -> Vec<i32> {
        let mut is_prime = vec![true; right as usize + 1];

        is_prime[0] = false;
        is_prime[1] = false;

        for i in 2..=right as usize {
            if is_prime[i] {
                for j in ((2 * i)..=(right as usize)).step_by(i) {
                    is_prime[j] = false;
                }
            }
        }

        is_prime
            .iter()
            .enumerate()
            .skip(left as usize)
            .filter(|(_, p)| **p)
            .map(|(i, _)| i as i32)
            .collect::<Vec<_>>()
            .windows(2)
            .min_by(|w, z| (w[1] - w[0]).cmp(&(z[1] - z[0])))
            .unwrap_or(&[-1, -1])
            .to_vec()
    }
}
// @leet end

