//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!min{($x:expr,$y:expr)=>{{let b=$y;let a=&mut$x;if b<*a{*a=b;true}else{false}}};}
macro_rules!rp{{[$c:expr]$($s:tt)+}=>(for _ in 0..$c{$($s)+})}
macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};}
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
	fn framed_board(&mut self, r: usize, c: usize, f: u8) -> Vec<Vec<u8>> {
		let mut res = v!([r+2]);
		res.push( v!([c+2] = f) );
		rp!{[r]
			let mut t = self.vb();
			assert!(t.len() == c);
			t.reserve(2);
			t.insert(0,f);
			t.push(f);
			res.push(t);
		}
		res.push( v!([c+2] = f) );
		res
	}
	fn board(&mut self, r: usize, c: Option<usize>) -> Vec<Vec<u8>> {
		let mut res = v!([r]);
		let c = c.unwrap_or(0);
		rp!{[r]
			let t = self.vb();
			assert!(c == 0 || t.len() == c);
			res.push(t);
		}
		res
	}
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let flood = |b: &mut [Vec<u8>], r: usize, c: usize, x: u8| {
		let mut q = v!([1] = (r,c));
		assert!(b[r][c] == b'0');
		b[r][c] = x;
		while let Some((r,c)) = q.pop() {
			let d = [(r-1,c),(r,c-1),(r+1,c),(r,c+1)];
			for &(rr,cc) in &d {
				if b[rr][cc] == b'0' {
					b[rr][cc] = x;
					q.push((rr,cc));
				}
			}
		}
	};
	l!(r0,c0,r1,c1 = rin.u());
	let mut b = rin.framed_board(n,n,b'1');
	flood(&mut b, r0, c0, b'2');
	if b[r1][c1] == b'2' {
		writeln!(rout, "0").unwrap();
	} else {
		flood(&mut b, r1, c1, b'3');
		l!(mut x,y = v!([]));
		for i in 1..=n {
			for j in 1..=n {
				if b[i][j] == b'2' {
					x.push((i as i32,j as i32));
				} else if b[i][j] == b'3' {
					y.push((i as i32,j as i32));
				}
			}
		}
		let mut ans = (n*n*2) as i32;
		for &(i,j) in &x {
			for &(ii,jj) in &y {
				min!(ans, (i-ii).pow(2) + (j-jj).pow(2));
			}
		}
		writeln!(rout, "{}", ans).unwrap();
	}
}