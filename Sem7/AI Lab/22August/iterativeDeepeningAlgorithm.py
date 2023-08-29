# Iterative Deepening Depth First Search Algorithm
global node
def dfs(src,target,maxDepth):
    print(f"{node[src]} ")
    if src == target : return True
    if maxDepth <= 0 : return False

    for i in graph[src]:
        if(dfs(i,target,maxDepth-1)):
            return True
    return False

# Create a graph
graph,node = [[] for i in range(8)],{}
#S A B C D E G  -> GOAL IS G
#0 1 2 3 4 5 6
graph[0].append(1)
graph[0].append(2)
graph[1].append(3)
graph[1].append(4)
graph[2].append(5)
graph[2].append(6)

node[0]='S'
node[1]='A'
node[2]='B'
node[3]='C'
node[4]='D'
node[5]='E'
node[6]='G'

target = 6; maxDepth = 4; src = 0

for i in range(maxDepth):
	if (dfs(src,target,i)):
		print(f"GOAL reached in level {i}")
		break
	else:
		print(f"GOAL not reachable in level {i}")

