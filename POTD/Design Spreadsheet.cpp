class Spreadsheet {
public:

    vector<vector<int>> mat;

    Spreadsheet(int rows) {
        mat.resize(rows + 1, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        mat[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        mat[row][col] = 0;
    }
    
    int getValue(string formula) {
        string first = "";
        int i = 1;
        while(i < formula.size() && formula[i] != '+') first += formula[i++];

        ++i;
        string second = "";
        while(i < formula.size()) second += formula[i++];

        int val1 = 0;
        if(isdigit(first[0])) {
            val1 = stoi(first);
        }
        else {
            int col = first[0] - 'A';
            int row = stoi(first.substr(1));
            val1 = mat[row][col];
        }

        int val2 = 0;
        if(isdigit(second[0])) {
            val2 = stoi(second);
        }
        else {
            int col = second[0] - 'A';
            int row = stoi(second.substr(1));
            val2 = mat[row][col];
        }

        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */