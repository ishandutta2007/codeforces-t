//spnauti-rusT {{{
use std::io::*; use std::str::{self,*}; use std::fmt::Debug;
#[allow(unused_imports)] use std::cmp::Ordering::{self,*};
#[allow(unused_imports)] use std::ops::{self,*};
#[allow(unused_imports)] use std::iter::{self,*};
#[allow(unused_imports)] use std::collections::*;
#[allow(unused_imports)] use std::cell::*;
#[allow(unused_macros)] macro_rules! min {
	($x:expr,$y:expr) => {{ let b=$y; let a=&mut$x; if b < *a {*a=b; true} else {false} }};
}
#[allow(unused_macros)] macro_rules! max {
	($x:expr,$y:expr) => {{ let b=$y; let a=&mut$x; if b > *a {*a=b; true} else {false} }};
}
#[allow(unused_macros)] macro_rules! l {
	($($v:ident),+ =$e:expr) => {$(let$v=$e;)+};
	($($v:ident),+:$t:ty=$e:expr) => {$(let$v:$t=$e;)+};
	(mut $($v:ident),+ =$e:expr) => {$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr) => {$(let mut$v:$t=$e;)+};
}
#[allow(unused_macros)] macro_rules! v {
	([$d:expr]$($s:tt)+) => {vec![v!($($s)+);$d]};
	([]) => {Vec::new()}; ([$e:expr]) => {Vec::with_capacity($e)}; (=$e:expr) => {$e};
}
#[allow(unused_macros)] macro_rules! rep { {[$c:expr]$($s:tt)+} => {for _ in 0..$c {$($s)+}} }
#[allow(dead_code)] fn reader() -> WordReaderC { WordReaderC::new() }
#[allow(dead_code)] fn writer() -> BufWriter<Stdout> { BufWriter::new(stdout()) }
struct WordReaderC {buf: Vec<u8>, pos: usize, q: std::io::StdinLock<'static>}//'
#[allow(dead_code)] impl WordReaderC {
	fn new() -> Self {
		let r = unsafe {&*Box::into_raw(Box::new(stdin()))};
		Self { q: r.lock(), buf: Vec::new(), pos: 0 }
	}
	fn next_line(&mut self) -> bool {
		self.buf.clear(); self.pos = 0;
		self.q.read_until(b'\n', &mut self.buf).unwrap_or(0) > 0
	}
	fn is_ws(c: u8) -> bool {
		c == b' ' || c == b'\r' || c == b'\n' || c == b'\t'
	}
	fn byte(&mut self) -> Option<u8> {
		if self.pos == self.buf.len() { if !self.next_line() { return None; } }
		self.pos += 1; Some(self.buf[self.pos - 1])
	}
	fn vb(&mut self) -> Vec<u8> {
		let mut s = Vec::with_capacity(8);
		let mut f = false;
		loop {
			if let Some(c) = self.byte() {
				if !Self::is_ws(c) {
					s.push(c);
					f = true;
				} else if f { break; }
			} else { break; }
		}
		s
	}
	fn s(&mut self) -> String { String::from_utf8(self.vb()).expect("invalid utf8") }
	fn i(&mut self) ->    i32 { self.p() }
	fn l(&mut self) ->    i64 { self.p() }
	fn u(&mut self) ->  usize { self.p() }
	fn f(&mut self) ->    f64 { self.p() }
	fn vi(&mut self, n: usize) -> Vec<i32> { self.vp(n) }
	fn vl(&mut self, n: usize) -> Vec<i64> { self.vp(n) }
	fn vu(&mut self, n: usize) -> Vec<usize> { self.vp(n) }
	fn ii(&mut self, n: usize) -> impl Iterator<Item=i32> { self.ip(n).into_iter() }
	fn iu(&mut self, n: usize) -> impl Iterator<Item=usize> { self.ip(n).into_iter() }
	fn p<T: FromStr>(&mut self) -> T where T::Err: Debug {
		let w = self.vb(); str::from_utf8(w.as_ref()).unwrap().parse::<T>().unwrap()
	}
	fn vp<T: FromStr>(&mut self, n: usize) -> Vec<T> where T::Err: Debug {
		(0..n).map(|_|self.p()).collect()
	}
	fn ip<T: FromStr>(&mut self, n: usize) -> impl Iterator<Item=T> where T::Err: Debug {
		self.vp(n).into_iter()
	}
}
//------------------- End rusT }}}

fn main() {
	let mut rin = reader();
	let mut rout = writer();
	const INF: i64 = 100000000000000000;

	let n = rin.u();
	let a = rin.vl(n);
	if n == 1 {
		writeln!(rout, "{}", a[0]).ok();
		return;
	}
	let mut dp = v!([n+1][3][2] = -INF);
	dp[0][0][0] = 0;
	for i in 1..=n {
		let x = a[i-1];
		for j in 0..3 {
			for k in 0..2 {
				if i >= 2 {
					let xx = a[i-2] + a[i-1];
					max!(dp[i][(j+2)%3][1], dp[i-2][j][k] + xx);
					max!(dp[i][j][1], dp[i-2][j][k] - xx);
				}
				max!(dp[i][(j+1)%3][k], dp[i-1][j][k] + x);
				max!(dp[i][j][k], dp[i-1][j][k] - x);
			}
		}
	}
	let mut sol = -INF;
	for i in 0..3 {
		if (n + i) % 3 == 2 {
			max!(sol, dp[n][i][1]);
		}
	}
	writeln!(rout, "{}", sol).ok();
}