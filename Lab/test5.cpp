


int main(){
    int board [8][8] = {};
    int r = 0;
    int c = 0;
    int solution = 0;

    board[0][0] = 1;

nextColumn:
    c++;
    if(c > 7){
        goto printSolution;
    }

nextRow:
    r++;
    if(r > 7)
    {
        goto backTrack;
    }
backTrack:
    c--;
    if(c == -1)
    {
        return 0;
    }
    r = 0;
    while(board[r][c] == 0)
    {
        r++;
    }
    board[r][c] = 0;
    goto nextRow;

printSolution:
    // this is gonna be the code to print out a 2d array
    goto backTrack;

}