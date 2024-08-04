// time: O(n!)
// space: O(n2)
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        unordered_set<int> col;
        vector<pair<int,int>> diag;
        helper(n, result, col, diag, 0, 0);
        return result;
    }
private:
    void helper(int n, vector<vector<string>>& result, unordered_set<int>& col, vector<pair<int,int>>& diag, int i, int j) {
        //base
        if(i >= n) {
            vector<string> board;
            int idx = 0;
            for(int r = 0; r < n; r++) {
                string str = "";
                for(int c = 0; c < n; c++) {
                    if(idx < n && diag[idx].first == r && diag[idx].second == c) {
                        str += 'Q';
                        idx++;
                    }
                    else {
                        str += '.';
                    }
                }
                board.push_back(str);
            }
            result.push_back(board);
            return;
        }
        if(j >= n) {
            return;
        }
        //logic
        if(col.find(j) == col.end() && diagCheck(diag, i, j)) {
            diag.push_back(make_pair(i,j));
            col.insert(j);
            helper(n, result, col, diag, i+1, 0);
            diag.pop_back();
            col.erase(j);
        }
        helper(n, result, col, diag, i, j+1);
        
    }

    bool diagCheck(vector<pair<int,int>>& diag, int i, int j) {
        if(i == 0 && j == 0) return true;
        for(auto x : diag) {
            if(abs(i - x.first) == abs(j - x.second)) {
                return false;
            }
        }
        return true;
    }
};