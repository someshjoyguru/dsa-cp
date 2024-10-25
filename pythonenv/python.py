from collections import defaultdict


def hyderatedtheNode(parent, waterLevel, overHyderatd, underHyderated):
    g = defaultdict(list)

    h_penalty = [0] * len(waterLevel)
    u_penalty = [0] * len(waterLevel)

    createGraph(parent, g)
    dfs(0, waterLevel, overHyderatd, underHyderated, 1, h_penalty, g)
    dfs(0, waterLevel, underHyderated, overHyderatd, - 1, u_penalty, g)
    # print(h_penalty)
    # print(u_penalty)
    # print(g)
    # print(list(enumerate(waterLevel)))
    ans = float('inf')
    p = u_penalty[0]
    for i, h in enumerate(h_penalty):
        ans = min(ans, h + (p - u_penalty[i]))
    print(ans)


def createGraph(parent, g):
    for i in range(1, len(parent)):
        g[parent[i]].append(i)


def dfs(src, waterLeve, oH, uH, apple, val, g):
    if not g.get(src, None):
        if waterLeve[src] == apple:
            val[src] = oH
            return oH
        return 0

    if g.get(src, None):
        penalty = 0
        if waterLeve[src] == apple:
            penalty = oH
        for t in g[src]:
            penalty += dfs(t, waterLeve, oH, uH, apple, val, g)
            # print(src, t, penalty)
    val[src] = penalty
    return penalty


hyderatedtheNode([-1, 0, 1], [1, 1, 1], 3, 5)  # 0
hyderatedtheNode([-1, 0, 0], [1, -1, -1], 10, 15)   # 10
hyderatedtheNode([-1, 0, 0, 1], [0, 0, 0, 0], 10, 15)  # 0 
hyderatedtheNode([-1, 0, 1, 0, 1, 2, 2, 2, 5, 5], [-1, -1, 0, -1, 0, 0, 1, 0, 0, 1], 2, 3)  # 4