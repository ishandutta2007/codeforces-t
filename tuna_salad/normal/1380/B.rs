//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
macro_rules!max{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b>*a{*a=b;true}else{false}}};}
macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};}
macro_rules!v{([$d:expr]$($s:tt)+)=>{vec![v!($($s)+);$d]};([])=>{Vec::new()};([$e:expr])=>{Vec::with_capacity($e)};(=$e:expr)=>{$e};}
fn rio()->(Reader,BufWriter<Stdout>){(Reader::new(),BufWriter::new(stdout()))}
struct Reader{buf:Vec<u8>,pos:usize,q:StdinLock<'static>}/*'>}*/#[allow(dead_code)]impl Reader{
	fn new()->Self{let r=unsafe{&*Box::into_raw(Box::new(stdin()))};Self{q:r.lock(),buf:v!([]),pos:0}}
	fn next_line(&mut self)->bool{self.buf.clear();self.pos=0;self.q.read_until(b'\n',&mut self.buf).unwrap_or(0)>0}
	fn byte(&mut self)->Option<u8>{
		if self.pos==self.buf.len(){if!self.next_line(){return None;}}self.pos+=1;Some(self.buf[self.pos-1])}
	fn vb(&mut self)->Vec<u8>{let mut s=v!([10]);let mut f=false;while let Some(c)=self.byte(){
		if!c.is_ascii_whitespace(){s.push(c);f=true;}else if f{break;}}s}
	fn p<T:FromStr>(&mut self)->T where T::Err:Debug{let w=self.vb();str::from_utf8(w.as_ref()).unwrap().parse::<T>().unwrap()}
	fn u(&mut self) ->  usize { self.p() }
}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();
	const S: &str = "RPS";

	rp!{[rin.u()]
		let s = rin.vb();
		let n = s.len();
		let mut rsp = HashMap::new();
		for c in s {
			*rsp.entry(c).or_insert(0_i32) += 1;
		}
		l!(mut cc,nn = 0);
		for (c,n) in rsp {
			if max!(nn, n) {
				cc = c;
			}
		}
		let p = (S.chars().position(|x| x == cc as char).unwrap() + 1) % 3;
		let ans = S[p..=p].repeat(n);
		writeln!(rout, "{}", ans).unwrap();
	}
}