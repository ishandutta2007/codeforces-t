//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
macro_rules!v{([$d:expr]$($s:tt)+)=>{vec![v!($($s)+);$d]};([])=>{Vec::new()};([$e:expr])=>{Vec::with_capacity($e)};(=$e:expr)=>{$e};}
fn rio()->(Reader,BufWriter<Stdout>){(Reader::new(),BufWriter::new(stdout()))}
struct Reader{buf:Vec<u8>,pos:usize,x:*mut Stdin,q:StdinLock<'static>}//'
#[allow(dead_code)]impl Reader{
	fn new()->Self{let x=Box::into_raw(Box::new(stdin()));let q=unsafe{&*x}.lock();Self{x,q,buf:v!([]),pos:0}}
	fn next_line(&mut self)->bool{self.buf.clear();self.pos=0;self.q.read_until(b'\n',&mut self.buf).unwrap_or(0)>0}
	fn byte(&mut self)->Option<u8>{
		if self.pos==self.buf.len(){if!self.next_line(){return None;}}self.pos+=1;Some(self.buf[self.pos-1])}
	fn vb(&mut self)->Vec<u8>{let mut s=v!([10]);let mut f=false;while let Some(c)=self.byte(){
		if!c.is_ascii_whitespace(){s.push(c);f=true;}else if f{break;}}s}
	fn p<T:FromStr>(&mut self)->T where T::Err:Debug{let w=self.vb();str::from_utf8(w.as_ref()).unwrap().parse::<T>().unwrap()}
	fn u(&mut self) ->  usize { self.p() }
	fn l(&mut self) ->    i64 { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn gcd(mut a: i64, mut b: i64) -> i64 {
	while b != 0 {
		let c = a % b;
		a = b;
		b = c;
	}
	a
}

mod sparse {
	use super::*;
	type S = i64;
	fn combine(a: S, b: S) -> S {
		gcd(a,b)
	}
	pub struct Table {
		pub n: usize,
		pub t: Vec<Vec<S>>,
	}
	impl Table {
		pub fn new(a: Vec<S>) -> Self {
			let n = a.len();
			assert!(n >= 1);
			let m = Self::base(n) + 1;
			let mut t = v!([m]);
			t.push(a);
			for i in 1..m {
				let l = 1 << i;
				let l2 = l >> 1;
				let mut s = v!([n-l+1]);
				for j in 0..=n-l {
					s.push( combine(t[i-1][j], t[i-1][j+l2]) );
				}
				t.push(s);
			}
			Self {n, t}
		}
		fn base(n: usize) -> usize {
			assert!(n >= 1);
			let mut m = 1;
			while (1 << m) <= n {
				m += 1;
			}
			m - 1
		}
		pub fn calc(&self, l: usize, r: usize) -> S {
			assert!(l <= r);
			assert!(r < self.n);
			let n = r - l + 1;
			let m = Self::base(n);
			combine(self.t[m][l], self.t[m][r+1-(1<<m)])
		}
	}
}

fn main() {
	let (mut rin,mut rout) = rio();

	rp!{[rin.u()]
		let n = rin.u();
		let mut last = rin.l();
		if n == 1 {
			writeln!(rout, "{}", n).unwrap();
			continue;
		}
		let mut a = v!([n-1]);
		rp!{[n-1]
			let x = rin.l();
			a.push((last - x).abs());
			last = x;
		}
		let st = sparse::Table::new(a);
		let mut ans = 1;
		let mut j = 0;
		for i in 0..n-1 {
			while j <= i && st.calc(j,i) == 1 {
				j += 1;
			}
			max!(ans, i+2-j);
		}
		writeln!(rout, "{}", ans).unwrap();
	}
}