use std::io;

#[derive(PartialOrd, PartialEq, Ord, Eq)]
struct Edge {
    w: i32,
    u: i32,
    v: i32,
}

fn find(u: i32, &id: Vec<i32>) -> i32 {
   id[u] = u if id[u] == u else find(id[u], id); 
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input);
    let mut iter = input.split_whitespace();
    let N: i32 = iter.next().unwrap().parse().unwrap();
    let M: i32 = iter.next().unwrap().parse().unwrap();
    io::stdin().read_line(&mut input);
    let mut edges: Vec<Edge> = Vec::new();
    let mut sz = vec![1, N+1];
    let mut id: Vec<i32> = (1..=N+1).collect();
    for _ in 0..M {
        io::stdin().read_line(&mut input);
        iter = input.split_whitespace();
        let u: i32 = iter.next().unwrap().parse().unwrap();
        let v: i32 = iter.next().unwrap().parse().unwrap();
        let w: i32 = iter.next().unwrap().parse().unwrap();
        edges.push(Edge { w, u, v });
    }
    edges.sort();
    
}
