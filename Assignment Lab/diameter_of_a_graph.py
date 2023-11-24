# adj_list = {
#     0:[1,4],
#     1:[0,2,4,3],
#     2:[1,3],
#     3:[1,2,4],
#     4:[0,1,3]
# }
adj_list = {
    0:[1,2],
    1:[0,3,4],
    2:[0,5,6],
    3:[1],
    4:[1],
    5:[2],
    6:[2]
}
n = 7

visited = [False] * n
max_count,count,x = 0,0,0

def dfs(node,adj_list,visited,count):
    global max_count,x

    visited[node] = True
    count += 1

    for i in adj_list[node]:
        if not visited[i]:
            if count > max_count:
                max_count = count
                x = i
            dfs(i,adj_list,visited,count)
    

dfs(0,adj_list,visited,count + 1)
visited = [False] * n
dfs(x,adj_list,visited,count + 1)
print(max_count,x)