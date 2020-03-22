# python 3.7 ile çalıştırım0

from collections import defaultdict

class Graph:
    def __init__(self, matrix, select):
        self.visited = []
        self.select = select;
        self.graph = defaultdict(list);
        self.edge_count = 0
        for ix, line in enumerate(matrix):
            for iy, edge in enumerate(line):
                if int(edge):
                    self.edge_count += 1
                    self.add_edge(ix + 1, iy + 1)

    def add_edge(self, u, v):
        self.graph[u].append(v)
    
    def dfs(self):
        self.dfs_partition(self.select)
        print()

    def dfs_partition(self, node):        
        if node not in self.visited:
            print(node, end=" ")
            self.visited.append(node)
            for neighbour in self.graph[node]:
                self.dfs_partition(neighbour)

    def edge_count(self):
        pass

    def print_io(self):
        out = len(self.graph[self.select])
        _in = 0
        for i in self.graph:
            if self.select in self.graph[i]:
                _in += 1
        print(f"Giris: {_in} Cıkıs: {out}")


def main():
    matrix = []
    with open("./matrix.txt") as f:
        for line in f.readlines():
            line = line.replace("\n", "")
            line = line.replace(" ", "")
            matrix.append(line)
    
    g = Graph(matrix, int(input("Dügüm >> ")))
    print("DFS", end=" ")
    g.dfs()
    g.print_io()
    print("Kenar sayısı", g.edge_count)
    print(g.graph)


def print_matrix(m):
    for line in m:
        print(line)

if __name__ == "__main__":
    main();