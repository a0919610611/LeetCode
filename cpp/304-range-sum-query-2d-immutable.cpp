class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int size_x = matrix.size();
        int size_y = matrix.size()?matrix[0].size():0;
        sum.resize(size_x+1);
        fill(sum.begin(),sum.end(),vector<int>(size_y+1,0));
        for(int i=1;i<=size_x;i++){
            for(int j=1;j<=size_y;j++){
                sum[i][j] = matrix[i-1][j-1]+sum[i-1][j]+sum[i][j-1]- sum[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return  sum[row2+1][col2+1]-sum[row2+1][col1]-sum[row1][col2+1]+sum[row1][col1];
    }
private:
    vector<vector<int> >sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
