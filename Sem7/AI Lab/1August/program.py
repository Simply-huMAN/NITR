original_mat = [[0, 600, 1000, 1900, 1100],
       [600, 0, 1900, 1900, 1500],
       [1000, 1900, 0, 1700, 1200],
       [1900, 1900, 1700, 0, 1900],
       [1100, 1500, 1200, 1900, 0]]
original_size = 5

INF = 9999999


matrix = [[INF, 600, 1000, 1900, 1100],
       [600, INF, 1900, 1900, 1500],
       [1000, 1900, INF, 1700, 1200],
       [1900, 1900, 1700, INF, 1900],
       [1100, 1500, 1200, 1900, INF]]
Size = 5

cost = 0

def findMinInRowAndCol(mat, roww, coll, Size):
    rowMin = INF
    for col in range(Size):
        if roww!=col and col!=coll and mat[roww][col] < rowMin:
            rowMin = mat[roww][col]
    #return rowMin

    colMin = INF
    for row in range(Size):
        if row!=coll and row!=roww and mat[row][coll] < colMin:
            colMin = mat[row][coll]
    return rowMin+colMin


ans = []

def TSPAD(matrix, Size, ans):

    if len(ans) >= original_size:
        return

    # finding row minimum

    rowMins = [None] * Size
    for row in range(Size):
        rowMin = INF
        for col in range(Size):
            if row!=col and matrix[row][col] < rowMin:
                rowMin = matrix[row][col]
        rowMins[row] = rowMin
    

    # Subtracting RowMin from every row'''

    for row in range(Size):
        for col in range(Size):
            if row!=col and matrix[row][col] != INF:
                matrix[row][col] = matrix[row][col] - rowMins[row]

    # Finding Col Minimum'''

    colMins = [None] * Size
    for col in range(Size):
        colMin = INF
        for row in range(Size):
            if row!=col and matrix[row][col] < colMin:
                colMin = matrix[row][col]
        colMins[col] = colMin


    # Subtracting colMin from every row'''

    for col in range(Size):
        for row in range(Size):
            if row!=col and matrix[row][col] != INF:
                matrix[row][col] = matrix[row][col] - colMins[col]

    # Calculating penalty

    penalty = {'row': 0,
            'col': 0,
            'pen': 0}
    for row in range(Size):
        for col in range(Size):
            if row!=col and matrix[row][col] == 0 and findMinInRowAndCol(matrix, row, col, Size) > penalty['pen']:
                penalty['row'] = row
                penalty['col'] = col
                penalty['pen'] = findMinInRowAndCol(matrix, row, col, Size)

    if ans:
        if ans[len(ans)-1] != penalty['row']:
            ans.append(penalty['row'])
    else:
        ans.append(penalty['row'])
    
    ans.append(penalty['col'])
    matrix[penalty['col']][penalty['row']] = INF

    for row in range(Size):
        for col in range(Size):
            if row==penalty['row'] or col==penalty['col']:
                matrix[row][col] = INF
    # Size = Size - 1
    TSPAD(matrix, Size, ans)

TSPAD(matrix, Size, ans)

for i in range(len(ans)-1):
    cost = cost + original_mat[ans[i]][ans[i+1]]
cost = cost + original_mat[ans[len(ans)-1]][ans[0]]

for i in range(len(ans)):
    ans[i] = chr(ans[i]+65)

print(ans)

print("COST - " + str(cost))