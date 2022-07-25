class Solution {
public:
    vector<vector<char>> ans;
    
    void solveSudoku(vector<vector<char>>& board) {
        bt(0, 0, board);
        board = ans;
    }
    
    void bt(int r, int c, vector<vector<char>>& board){
        if(r == 9) {
            ans = board;
            return;
        }
        
        auto[nr, nc] = next(r, c);
        if(board[r][c] == '.'){
            for(int i = '1'; i <= '9'; i++){
                if(valid(r, c, i, board)){
                    board[r][c] = i;
                    bt(nr, nc, board);
                    board[r][c] = '.';
                }
            }
        }
        else{
            bt(nr, nc, board);
        }
    }
    
    bool valid(int r, int c, char ch, vector<vector<char>>& board){
        for(int i = 0; i < 9; i++)
            if(board[i][c] == ch)
                return false;
        
        for(int i = 0; i < 9; i++)
            if(board[r][i] == ch)
                return false;
        
        int sr = (r/3)*3, er = sr + 2, sc = (c/3)*3, ec = sc + 2;
        for(int i = sr; i <= er; i++){
            for(int j = sc; j <= ec; j++)
                if(board[i][j] == ch)
                    return false;
        }
        return true;
    }
    
    pair<int, int> next(int i, int j){
        j++;
        if(j == 9)
            i++, j = 0;
        return {i, j};
    }
};