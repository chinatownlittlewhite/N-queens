#include <stdio.h>
#include <stdbool.h>
int board[10086][10086];
// 检查在(x, y)位置放置皇后是否合法
bool isSafe(int x, int y, int N) {
    int i, j;
    
    // 检查列上是否有冲突
    for (i = 0; i < x; i++) {
        if (board[i][y] == 1)
            return false;
    }
    
    // 检查左上对角线是否有冲突
    for (i = x, j = y; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }
    
    // 检查右上对角线是否有冲突
    for (i = x, j = y; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }
    
    return true;
}

// 递归解决N皇后问题
bool solveNQueens(int x,int N) {
    if (x == N) {
        // 打印解决方案
        printf("Solution:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return true;
    }
    
    bool res = false;
    
    for (int y = 0; y < N; y++) {
        if (isSafe(x, y, N)) {
            board[x][y] = 1;
            
            // 递归求解下一行
            res = solveNQueens(x + 1, N) || res;
            
            // 回溯，尝试下一个位置
            board[x][y] = 0;
        }
    }
    
    return res;
}

int main() {
    int N;
    scanf("%d", &N);
    if(N <= 0 || N > 10086) {
        printf("输入有误，请重新输入\n");
        return 1;
    }
    // 初始化棋盘
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
    
    // 解决N皇后问题
    solveNQueens(0, N);
    
    return 0;
}
