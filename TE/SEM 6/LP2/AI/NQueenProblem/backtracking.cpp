#include<bits/stdc++.h>
using namespace std;

// leftRow 
// . . . . . . Q

// upperLeftDiagonal
//  .
//    .
//      .
//        .
//          .
//            Q

// lowerRightDiagonal
//            Q
//          .
//        .
//      .
//    .
//  .

// Approach 1 --> Simple Backtracking

bool isSafe(int row, int col, int n, vector<string>& board) {
    // upperLeftDiagonal
    int itrRow = row, itrCol = col;
    while(itrRow >= 0 and itrCol >= 0) {
        if(board[itrRow][itrCol] == 'Q') return false;
        --itrRow, --itrCol;
    }

    // leftRow
    itrRow = row, itrCol = col;
    while(itrCol >= 0) {
        if(board[itrRow][itrCol] == 'Q') return false;
        --itrCol;
    }

    // lowerRightDiagonal
    itrRow = row, itrCol = col;
    while(itrRow < n and itrCol >= 0) {
        if(board[itrRow][itrCol] == 'Q') return false;
        ++itrRow, --itrCol;
    }

    return true;
}

void backtracking(int col, int n, vector<string>& board, vector<vector<string>>& ds) {
    if(col == n) {
        ds.push_back(board);
        return ;
    }

    for (int row = 0; row < n; row++)
    {
        if(isSafe(row, col, n, board)) {
            board[row][col] = 'Q';
            backtracking(col+1, n, board, ds);
            board[row][col] = '.';
        }
    }
}

int main(){
    int n = 4;
    string str(n, '.');
    vector<string> board(n, str);
    vector<vector<string>> ans;

    backtracking(0, n, board, ans);

    cout << "Total possible Boards are : " << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Board " << i+1 << endl;
        for (int j = 0; j < ans[i].size(); j++)
        {
            for (int k = 0; k < ans[i][j].size(); k++)
            {
                cout << ans[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}