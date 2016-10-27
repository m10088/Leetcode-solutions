[原题](https://leetcode.com/problems/valid-sudoku/)


题意：

判断一个数独是不是有效的：

这里的有效不是有解，而是规定的范围内，有没有重复的数字。


```
    def evaluation(list):
        return len(set(list)) == len(list)

    def column(i):
        return [row[i] for row in board]
    
    def block(i,j):
        temp = []
        for s in xrange(3):
            for t in xrange(3):
                temp.append(board[i+s][j+t])
        return temp
        
    #row evaluation
    for row in board:
        tmp = [strRow for strRow in row if strRow != '.']
        if not evaluation(tmp):
            return False
    
    #column evaluation
    for i in xrange(9):
        tmp = [strColumn for strColumn in column(i) if strColumn != '.']
        if not evaluation(tmp):
            return False   
            
    #block evaluation
    for i in xrange(3):
        for j in xrange(3):
            tmp = [strBlock for strBlock in block(3*i,3*j) if strBlock != '.']
            if not evaluation(tmp):
                return False
    
    return True
```


