class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.' && !valid(i, j, board[i][j], board))
                    return false;
            }
        }
        return true;
    }
    
    bool valid(int r, int c, char ch, vector<vector<char>> &b){
        //same column check
        for(int i = 0; i < 9; i++){
            if(i == r)
                continue;
            if(b[i][c] == ch)
                return false;
        }
        
        //same row check
        for(int i = 0; i < 9; i++){
            if(i == c)
                continue;
            if(b[r][i] == ch)
                return false;
        }
        
        // same sub-box check
        int sr = (r/3)*3, er = sr + 2, sc = (c/3)*3, ec = sc + 2;
        for(int i = sr; i <= er; i++){
            for(int j = sc; j <= ec; j++){
                if(i == r && j == c)
                    continue;
                if(b[i][j] == ch)
                    return false;
            }
        }
        
        return true;
    }
};