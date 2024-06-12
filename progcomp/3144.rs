use std::io;

#[derive(PartialOrd, PartialEq, Debug, Ord, Eq)]
struct Edge {
    w: i32,
    u: i32,
    v: i32,
}

fn find(u: i32, id: &mut Vec<i32>) -> i32 {
    if id[u as usize] == u {
        id[u as usize] = u;
    } else {
        id[u as usize] = find(id[u as usize], id);
    }
    id[u as usize]
}

fn uni(u: i32, v: i32, id: &mut Vec<i32>, sz: &mut Vec<i32>) -> Option<i32> {
    let mut a = find(u, id);
    let mut b = find(v, id);
    if a == b {
        return None;
    }
    if sz[a as usize] > sz[b as usize] {
        let aux = a;
        a = b;
        b = aux;
    }
    sz[a as usize] += sz[b as usize];
    id[b as usize] = a;
    Some(1)
}

fn main() {
    let mut input = String::new();
    let _ = io::stdin().read_line(&mut input);
    let mut iter = input.split_whitespace();
    let N: i32 = iter.next().unwrap().parse().unwrap();
    let M: i32 = iter.next().unwrap().parse().unwrap();
    let _ = io::stdin().read_line(&mut input);
    let mut edges: Vec<Edge> = Vec::new();
    let mut sz = vec![1; (N + 4) as usize];
    let mut id: Vec<i32> = (0..=(N + 4)).collect();
    for _ in 0..M {
        input = "".to_string();
        let _ = io::stdin().read_line(&mut input);
        iter = input.split_whitespace();
        let u: i32 = iter.next().unwrap().parse().unwrap();
        let v: i32 = iter.next().unwrap().parse().unwrap();
        let w: i32 = iter.next().unwrap().parse().unwrap();
        edges.push(Edge { w, u, v });
    }
    edges.sort();
    let mut ans = 0;
    for edg in edges {
        let u = edg.u;
        let v = edg.v;
        if find(u, &mut id) == find(v, &mut id) {
            continue;
        }
        uni(u, v, &mut id, &mut sz);
        ans += edg.w;
    }
    println!("{:?}", 2 * ans);
}
