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
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();
	const P: [char; 2] = ['(', ')'];

	rp!{[rin.u()]
		let n = rin.u();
		let s = rin.vb();
		let c1 = s.iter().filter(|x| **x == b'1').count();
		if s[0].min(s[n-1]) == b'0' || c1 % 2 == 1 {
			writeln!(rout, "NO").unwrap();
			continue;
		}
		writeln!(rout, "YES").unwrap();
		for i in 0..2 {
			let mut c = c1 / 2;
			let mut p = 0;
			for &x in &s {
				let j = if x == b'0' {
					p ^= 1;
					(p ^ i) & 1
				} else {
					if c > 0 {
						c -= 1;
						0
					} else {
						1
					}
				};
				write!(rout, "{}", P[j]).unwrap();
			}
			writeln!(rout, "").unwrap();
		}
	}
}