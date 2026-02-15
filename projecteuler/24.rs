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

fn next_permutation(vi: &mut Vec<usize>) {
    let mut pivot_idx = 0;
    for i in (1..vi.len()).rev() {
        if vi[i - 1] < vi[i] {
            pivot_idx = i - 1;
            break;
        }
    }
    for i in (pivot_idx+1..vi.len()).rev() {
        if vi[i] > vi[pivot_idx] {
            vi.swap(i, pivot_idx);
            break;
        } 
    }
    vi[pivot_idx+1..].reverse();
}

fn solve() {

    let mut vv = vec![0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
    for _ in 0..999999 {
        next_permutation(&mut vv);
    }
    let s: String = vv.iter().map(|&d| d.to_string()).collect();
    println!("{}", s);
}

fn main() {
    solve();
}
