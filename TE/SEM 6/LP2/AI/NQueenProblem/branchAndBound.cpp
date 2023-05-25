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

void branchAndBound(int col, int n, vector<string>& board, vector<bool>& leftRow, vector<bool>& upperLeftDiagonal, vector<bool>& lowerRightDiagonal, vector<vector<string>>& ds) {
    if(col == n) {
        ds.push_back(board);
        return ;
    }

    for (int row = 0; row < n; row++)
    {
        if(leftRow[row] == 0 and upperLeftDiagonal[(n-1)+(col-row)] == 0 and lowerRightDiagonal[row+col] == 0) {
            leftRow[row] = 1, upperLeftDiagonal[(n-1)+(col-row)] = 1, lowerRightDiagonal[row+col] = 1;
            board[row][col] = 'Q';
            branchAndBound(col+1, n, board, leftRow, upperLeftDiagonal, lowerRightDiagonal, ds);
            leftRow[row] = 0, upperLeftDiagonal[(n-1)+(col-row)] = 0, lowerRightDiagonal[row+col] = 0;
            board[row][col] = '.';
        }
    }
}

int main(){
    int n = 4;
    string str(n, '.');
    vector<string> board(n, str);
    vector<vector<string>> ans;

    vector<bool> uld(2*n-1, 0), lrd(2*n-1, 0), lr(n, 0);
    branchAndBound(0, n, board, lr, uld, lrd, ans);

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