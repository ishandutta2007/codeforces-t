//spnauti-rust
#[allow(unused_macros)]
macro_rules! a {
    ($c: tt, $x: expr, $y: expr) => {{
        let b = $y; let a = &mut $x;
        if b $c *a { *a = b; true } else { false }
    }};
}
use std::io::*;
use std::str::*;
use std::fmt::Debug;
struct WordReader<'a> { it : SplitAsciiWhitespace<'a>, }
#[allow(dead_code)]
impl<'a> WordReader<'a> {
    fn new<T: Read>(b: &mut String, mut r: T) -> WordReader {
        b.clear();
        r.read_to_string(b).unwrap();
        WordReader { it: b.split_ascii_whitespace() }
    }
    fn from_stdin(b: &mut String) -> WordReader {
        WordReader::new(b, stdin())
    }
    fn sl(&mut self) ->  &str { self.it.next().unwrap() }
    fn bs(&mut self) -> &[u8] { self.sl().as_bytes()    }
    fn s(&mut self) -> String { String::from(self.sl()) }
    fn i(&mut self) ->    i32 { self.p()                }
    fn u(&mut self) ->  usize { self.p()                }
    fn vi(&mut self, n: usize) -> Vec<i32> {
        self.vp::<i32>(n)
    }
    fn p<T: FromStr>(&mut self) -> T where T::Err: Debug {
        self.sl().parse::<T>().unwrap()
    }
    fn vp<T: FromStr>(&mut self, n: usize) -> Vec<T> where T::Err: Debug {
        (0..n).map(|_| self.p()).collect()
    }
}

fn main() {
    let mut bin = String::new();
    let mut input = WordReader::from_stdin(&mut bin);

    let n = input.u();
    let a = input.vi(n);
    let mut i = 0;
    let mut j = n - 1;
    let mut sol = vec![0; 2];
    let mut p = 0;
    while i <= j {
        if a[i] >= a[j] {
            sol[p] += a[i];
            i += 1;
        } else {
            sol[p] += a[j];
            j -= 1;
        }
        p = 1 - p;
    }
    println!("{} {}", sol[0], sol[1]);
}