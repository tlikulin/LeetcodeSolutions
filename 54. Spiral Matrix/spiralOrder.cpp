class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        auto row = (int)matrix.size();
        auto column = (int)matrix[0].size();
        int iteration = 0;
        vector<int> res;
        while (column - 2 * iteration > 0 && row - 2 * iteration > 0) {
            int i;
            for (i = iteration; i < column - iteration; i++)
                res.push_back(matrix[iteration][i]);
            if (row - 2 * iteration == 1)
                return res;
            for (i = iteration + 1; i < row - iteration; i++)
                res.push_back(matrix[i][column - iteration - 1]);
            if (column - 2 * iteration == 1)
                return res;
            for (i = column - iteration - 2; i >= iteration; i--)
                res.push_back(matrix[row - iteration - 1][i]);
            for (i = row - iteration - 2; i > iteration; i--)
                res.push_back(matrix[i][iteration]);
            iteration++;
        }
        return res;
    }
};