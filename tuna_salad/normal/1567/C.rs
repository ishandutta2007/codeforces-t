//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
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
	fn u(&mut self) ->  usize { self.p() }
	fn i(&mut self) ->    i32 { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let mut p = [0;20];
	for i in 0..10 {
		for j in 0..10 {
			p[i+j] += 1;
		}
	}
	rp!{[rin.u()]
		let n = rin.i();
		let mut x = n;
		let mut a = [0; 10];
		for i in 0..10 {
			a[i] = x % 10;
			x /= 10;
		}
		let mut ans: i64 = -2;
		for x in 0..1 << 8 {
			let mut b = a;
			for i in 0..8 {
				if (x >> i) & 1 == 1 {
					b[i] += 10;
					b[i+2] -= 1;
				}
			}
			let mut res = 1;
			for i in 0..10 {
				if 0 <= b[i] && b[i] <= 18 {
					res *= p[b[i] as usize];
				} else {
					res = 0;
					break;
				}
			}
			ans += res;
		}
		writeln!(rout, "{}", ans).unwrap();
	}
}