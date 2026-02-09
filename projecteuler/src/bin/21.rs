// ============ RUST CHEATSHEET ============
//
// TYPES:
//   i32, i64, i128    signed integers
//   u32, u64, u128    unsigned integers
//   usize             array index type
//   f64               floating point
//   bool, char, String
//
// VARIABLES:
//   let x = 5;              immutable
//   let mut x = 5;          mutable
//   let x: i64 = 5;         with type
//
// VECTORS:
//   let v: Vec<i64> = vec![1, 2, 3];
//   let v = vec![0; n];     // n zeros
//   v.push(x);              // append
//   v.len();                // size
//   v[i]                    // access
//   v.iter().sum::<i64>()   // sum all
//   v.iter().max().unwrap() // max element
//   v.sort();               // sort ascending
//   v.sort_by(|a,b| b.cmp(a));  // descending
//
// LOOPS:
//   for i in 0..n { }           // 0 to n-1
//   for i in 1..=n { }          // 1 to n
//   for x in &v { }             // iterate vec
//   for (i, x) in v.iter().enumerate() { }
//   while condition { }
//
// STRINGS:
//   let s = String::from("hello");
//   s.chars()                   // iterator of chars
//   s.as_bytes()                // &[u8]
//   s.len()                     // byte length
//
// MATH:
//   x.abs()                     // absolute value
//   x.pow(3)                    // x^3 (u32 exp)
//   (x as f64).sqrt() as i64   // sqrt
//   std::cmp::min(a, b)
//   std::cmp::max(a, b)
//   a % b                       // modulo
//   a / b                       // integer division
//
// HASHMAP/SET:
//   use std::collections::{HashMap, HashSet};
//   let mut map: HashMap<i64, i64> = HashMap::new();
//   map.insert(key, val);
//   map.get(&key)               // returns Option
//   *map.entry(k).or_insert(0) += 1;  // count
//
// PRINT:
//   println!("{}", x);
//   println!("{} {}", a, b);
//   println!("{:?}", vec);      // debug print
//   eprintln!("{:?}", x);       // stderr (debug)
//
// USEFUL:
//   (0..n).map(|i| i*i).collect::<Vec<_>>()
//   v.iter().filter(|&x| *x > 0).count()
//   "12345".parse::<i64>().unwrap()
//
// ==========================================

fn get_div_sum(val: u64) -> u64 {
    let mut sum: u64 = 0;
    for i in 1..val {
        if val % i == 0 {
            sum += i;
        }
    }
    sum
}

fn solve() {
    let mut sum: u64 = 0;
    
    let mut used = vec![false; 10005];
    for i in 1..=10000 {
        if used[i] { continue; }
        let res = get_div_sum(i as u64);
        if res < 10005 && (i as u64) != res && get_div_sum(res) == (i as u64) {
            sum += i as u64;
            sum += res;
            used[i] = true;
            used[res as usize] = true;
        }
    }

    println!("{}", sum) 
}

fn main() {
    solve();
}
