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
	fn vl(&mut self, n: usize) -> Vec<i64> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
	fn l(&mut self) ->    i64 { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let s = rin.l();
	let a = rin.vl(n);
	let mut lo = 1;
	let mut hi = n;
	let mut ans = (0,0);
	while lo <= hi {
		let mid = (lo + hi) / 2;
		let mut b = v!([n]);
		for i in 0..n {
			b.push(a[i] + ((i+1) as i64 * mid as i64));
		}
		b.sort();
		b.truncate(mid);
		let res = b.into_iter().sum();
		if s >= res {
			ans = (mid, res);
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	writeln!(rout, "{} {}", ans.0, ans.1).unwrap();
}