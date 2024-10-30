//spnauti-rusT {{{
#[allow(unused_imports)]use std::{io::*,collections::*,fmt::Debug,str::{self,*},cmp::*,ops::{self,*},iter::{self,*}};
macro_rules!l{
	($($v:ident),+:$t:ty=$e:expr)=>{$(let$v:$t=$e;)+};(mut $($v:ident),+ =$e:expr)=>{$(let mut$v=$e;)+};
	(mut $($v:ident),+:$t:ty=$e:expr)=>{$(let mut$v:$t=$e;)+};($($v:ident),+ =$e:expr)=>{$(let$v=$e;)+};}
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
	fn vp<T:FromStr>(&mut self,n:usize)->Vec<T>where T::Err:Debug{(0..n).map(|_|self.p()).collect()}
	fn vi(&mut self, n: usize) -> Vec<i32> { self.vp(n) }
	fn u(&mut self) ->  usize { self.p() }
}impl Drop for Reader{fn drop(&mut self){unsafe{Box::from_raw(self.x)};}}
//----------}}}

fn main() {
	let (mut rin,mut rout) = rio();

	let n = rin.u();
	let mut a = rin.vi(n);
	let mut ans = String::with_capacity(n);
	let mut i = 0;
	let mut j = n;
	let mut x = 0;
	while i+1 < j {
		if x < a[i] {
			if x < a[j-1] {
				if a[i] < a[j-1] {
					x = a[i];
					i += 1;
					ans.push('L');
				} else if a[i] > a[j-1] {
					j -= 1;
					x = a[j];
					ans.push('R');
				} else {
					l!(mut ci,cj = 1);
					for k in i..j {
						if a[k] >= a[k+1] {
							break;
						}
						ci += 1;
					}
					for k in (i..j).rev() {
						if a[k] >= a[k-1] {
							break;
						}
						cj += 1;
					}
					if ci >= cj {
						a[j-1] = 0;
					} else {
						a[i] = 0;
					}
					continue;
				}
			} else {
				x = a[i];
				i += 1;
				ans.push('L');
			}
		} else {
			if x < a[j-1] {
				j -= 1;
				x = a[j];
				ans.push('R');
			} else {
				break;
			}
		}
	}
	if i+1 == j && x < a[i] {
		ans.push('L');
	}
	writeln!(rout, "{}", ans.len()).unwrap();
	writeln!(rout, "{}", ans).unwrap();
}