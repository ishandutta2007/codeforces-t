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
		Self { q: r.lock(), buf: v!([]), pos: 0 }
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
		let mut s = v!([8]);
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
	fn vvb(&mut self, r: usize, c: Option<usize>) -> Vec<Vec<u8>> {
		let mut res = v!([r]);
		let c = c.unwrap_or(0);
		rep!{[r]
			let t = self.vb();
			assert!(c == 0 || t.len() == c);
			res.push(t);
		}
		res
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
	fn graph(&mut self, n: usize, m: usize) -> Vec<Vec<usize>> {
		let mut e = v!([n][]); rep!{[m] l!(a,b = self.u()-1); e[a].push(b); e[b].push(a); } e
	}
	fn graph_w<T: Copy+FromStr>(&mut self, n: usize, m: usize) -> Vec<Vec<(usize,T)>> where T::Err: Debug {
		let mut e = v!([n][]); rep!{[m] l!(a,b = self.u()-1); let c: T = self.p(); e[a].push((b,c)); e[b].push((a,c)); } e
	}
}
//------------------- End rusT }}}

// SCC
#[allow(dead_code)]
mod scc {
	// Digraph1 {{{
	pub struct Digraph1 {
		n: usize,
		pub edges: Box<[Vec<usize>]>
	}
	impl Digraph1 {
		pub fn new(n: usize) -> Self { Self {n, edges: vec![Vec::new(); n].into_boxed_slice()} }
		pub fn add_edge(&mut self, a: usize, b: usize) { assert!(a.max(b) < self.n); self.edges[a].push(b); }
		pub fn clone_rev(&self) -> Self {
			let mut c = vec![0; self.n]; let mut g = Self::new(self.n);
			for e in self.edges.iter() { for &v in e { c[v] += 1; } }
			for i in 0..self.n { g.edges[i].reserve_exact(c[i]); }
			for u in 0..self.n { for &v in self.edges[u].iter() { g.edges[v].push(u); } }
			g
		}
	}
	//}}}
	// SccDfs {{{
	struct SccDfs<'a> {
		g: &'a Digraph1, ord: Vec<usize>, vis: Vec<bool>, scc_id: Vec<usize>, scc_nodes: Vec<Vec<usize>>
	}
	impl<'a> SccDfs<'a> {
		fn scc_id_and_nodes(g: &'a Digraph1) -> (Box<[usize]>, Box<[Vec<usize>]>) {//'
			let ord = Vec::with_capacity(g.n);
			let vis = vec![false; g.n];
			let scc_id = vec![0; g.n];
			let scc_nodes = Vec::new();
			let mut h = Self {g, ord, vis, scc_id, scc_nodes};
			for u in 0..g.n { if !h.vis[u] { h.dfs(u); } }
			let g_rev = g.clone_rev();
			for u in h.ord.split_off(0).into_iter().rev() {
				if h.vis[u] {
					let mut comp = Vec::new();
					h.fill_comp(&g_rev, u, &mut comp);
					let id = h.scc_nodes.len();
					for &v in &comp { h.scc_id[v] = id; }
					h.scc_nodes.push(comp);
				}
			}
			(h.scc_id.into_boxed_slice(), h.scc_nodes.into_boxed_slice())
		}
		fn dfs(&mut self, u: usize) {
			self.vis[u] = true;
			for &v in self.g.edges[u].iter() { if !self.vis[v] { self.dfs(v); } }
			self.ord.push(u);
		}
		fn fill_comp(&mut self, g_rev: &Digraph1, u: usize, comp: &mut Vec<usize>) {
			self.vis[u] = false; comp.push(u);
			for &v in g_rev.edges[u].iter() { if self.vis[v] { self.fill_comp(g_rev, v, comp); } }
		}
	}
	//}}}
	// Scc (main) {{{
	pub enum SccEdge { No, Unique, All }
	#[derive(Clone,Debug)]
	pub struct Scc {
		pub n: usize,
		pub edges: Option<Box<[Vec<usize>]>>,
		pub id: Box<[usize]>,
		pub nodes: Box<[Vec<usize>]>
	}
	impl Scc {
		pub fn new(g: &Digraph1, mode: SccEdge) -> Self {
			let (id, nodes) = SccDfs::scc_id_and_nodes(g);
			let n = nodes.len();
			let edges = if let SccEdge::No = mode {None} else {
				let mut edges = vec![Vec::new(); n].into_boxed_slice();
				for u in 0..g.n {
					let u_id = id[u];
					for &v in g.edges[u].iter() {
						let v_id = id[v]; if u_id != v_id { edges[u_id].push(v_id); }
					}
				}
				if let SccEdge::Unique = mode {
					for e in edges.iter_mut() { e.sort(); e.dedup(); }
				}
				Some(edges)
			};
			Self {n, edges, id, nodes}
		}
	}//}}}
}

fn dfs(u: usize, e: &[Vec<usize>], par: &mut [Option<usize>], dep: &mut [usize], d: usize) {
	dep[u] = d;
	for &v in e[u].iter() {
		if v != par[u].unwrap() {
			if par[v].is_none() {
				par[v].replace(u);
				dfs(v, e, par, dep, d+1);
			}
		}
	}
}

fn main() {
	let mut rin = reader();
	let mut rout = writer();

	l!(n,m = rin.u());
	let e = rin.graph(n,m);
	let mut par = v!([n] = None);
	let mut dep = v!([n] = n);
	par[0].replace(0);
	dfs(0, &e, &mut par, &mut dep, 0);
	let mut g = scc::Digraph1::new(n);
	for u in 0..n {
		for &v in e[u].iter() {
			if u < v {
				if u == par[v].unwrap() {
					g.add_edge(u, v);
				} else if v == par[u].unwrap() {
					g.add_edge(v, u);
				} else if dep[u] > dep[v] {
					g.add_edge(u, v);
				} else {
					g.add_edge(v, u);
				}
			}
		}
	}
	let s = scc::Scc::new(&g, scc::SccEdge::No);
	if s.nodes.len() == 1 {
		for u in 0..n {
			for &v in g.edges[u].iter() {
				writeln!(rout, "{} {}", u+1, v+1).ok();
			}
		}
	} else {
		writeln!(rout, "0").ok();
	}
}