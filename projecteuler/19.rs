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

fn solve() {
    let MOD: i64 = 7;
    let mut count: i64 = 2;
    let mut ans: i64 = 0;
    let months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    for i in 1901..2001 {
        let is_leap = i % 400 == 0 || (i % 4 == 0 && i % 100 != 0);
        for j in 0..12 {
            if count % MOD == 0 {
                ans += 1;
            }
            let month_mod = months[j] % MOD;
            count += if j != 1 { month_mod } else { month_mod + is_leap as i64 }; 
        }
    }

    println!("{}", ans);
}

fn main() {
    solve();
}
