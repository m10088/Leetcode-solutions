class Solution {
public:
  bool isValidSudoku(vector<vector<char> > &board) {
    int rowValid[10] = {0};//ç¨äºå¤æ­æä¸è¡æ¯å¦åæ³ï¼å¯¹äºè¡æ¥è¯´è¿ä¸ªæ°ç»å¯ä»¥éå¤ä½¿ç¨
    int columnValid[9][10] = {0};//ç¨äºå¤æ­æä¸åæ¯å¦åæ³
    int subBoardValid[9][10] = {0};//ç¨äºå¤æ­æä¸ä¸ªä¹å®«æ ¼æ¯å¦åæ³
    for(int i = 0; i < 9; i++)
    {
      memset(rowValid, 0, sizeof(rowValid));
      for(int j = 0; j < 9; j++)
        if(board[i][j] != '.')
        {
          if(!checkValid(rowValid, board[i][j]-'0') ||
             !checkValid(columnValid[j], board[i][j]-'0') ||
             !checkValid(subBoardValid[i/3*3+j/3], board[i][j]-'0'))
             return false;
        }
    }
    return true;
  }
  bool checkValid(int vec[], int val)
  {
    if(vec[val] == 1)return false;
    vec[val] = 1;
    return true;
  }
};