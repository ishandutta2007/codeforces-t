//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!v{
	($(:$t:ty)?=$e:expr)=>{$e$(as$t)?};([$d:expr]$(:$t:ty)?)=>{Vec::$(<$t>::)?with_capacity($d)};
	([]$(:$t:ty)?)=>{Vec::$(<$t>::)?new()};([$d:expr]$($s:tt)+)=>{vec![v!($($s)+);$d]};}
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
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vu(&mut self, n: usize) -> Vec<usize> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

// Field (mod prime) {{{
mod field {
	use std::ops::*;
	#[allow(dead_code)] pub const Z0: Field = Field(0);
	#[allow(dead_code)] pub const Z1: Field = Field(1);
	const P5: i32 = 1_000_000_007;
	const P6: i64 = P5 as i64;
	#[derive(Debug,Clone,Copy,PartialEq,Eq,PartialOrd,Ord,Default)] pub struct Field(i32);
	#[allow(dead_code)] impl Field {
		pub fn new<T: Into<i64>>(a: T) -> Self { Self(Self::cv(a)) }
		pub unsafe fn new_unchecked(a: i32) -> Self { Self(a) }
		fn hi(mut a: i32) -> i32 { if a >= P5 { a -= P5; } a }
		fn lo(mut a: i32) -> i32 { if a < 0 { a += P5; } a }
		fn cv<T: Into<i64>>(a: T) -> i32 { Self::lo((a.into() % P6) as i32) }
		pub fn inv(self) -> Self { self.pow(P5-2) }
		pub fn pow<T: Into<i64>>(self, b: T) -> Self {
			let b = b.into(); if b == 0 { Self(1) } else {
				let mut res = self.pow(b/2); res *= res; if b % 2 == 1 {res *= self;} res
			}
		}
	}
	impl Add for Field { type Output = Self; fn add(self, a: Self) -> Self::Output { Self(Self::hi(self.0 + a.0)) }}
	impl Sub for Field { type Output = Self; fn sub(self, a: Self) -> Self::Output { Self(Self::lo(self.0 - a.0)) }}
	impl Mul for Field { type Output = Self; fn mul(self, a: Self) -> Self::Output { Self(Self::cv(self.0 as i64 * a.0 as i64)) }}
	impl Div for Field { type Output = Self; fn div(self, a: Self) -> Self::Output { self * a.inv() }}
	impl Neg for Field { type Output = Self; fn neg(self) -> Self::Output { Self(Self::lo(-self.0)) }}
	impl AddAssign for Field { fn add_assign(&mut self, a: Self) { *self = *self + a; } }
	impl SubAssign for Field { fn sub_assign(&mut self, a: Self) { *self = *self - a; } }
	impl MulAssign for Field { fn mul_assign(&mut self, a: Self) { *self = *self * a; } }
	impl DivAssign for Field { fn div_assign(&mut self, a: Self) { *self = *self / a; } }
	use std::fmt::{Display, Formatter, Result};
	impl Display for Field { fn fmt(&self, f: &mut Formatter) -> Result { write!(f, "{}", self.0) } }
}
#[allow(unused_imports)] use field::{Field, Field as Z, Z0, Z1};
//}}}

fn main() {
	let (mut rin,mut rout) = rio();
	const A: usize = 1000000;

	let n = rin.u();
	let a = rin.vu(n);
	let mut d = v!([A+1][]);
	for i in 1..=n {
		let mut j = i;
		while j <= A {
			d[j].push(i);
			j += i;
		}
	}
	let mut dp = v!([n+1] = Z0);
	dp[0] = Z1;
	for i in 0..n {
		for &j in d[a[i]].iter().rev() {
			let x = dp[j-1];
			dp[j] += x;
		}
	}
	let mut ans = Z0;
	for i in 1..=n {
		ans += dp[i];
	}
	writeln!(rout, "{}", ans).unwrap();
}