#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<thread>
#include<windows.h>

using namespace std;

// 오늘의 주제 : 동적 계획법(DP)
// TIC - TAE - TOE : 서양의 오목 --> 여기서는 3칸 일직선을 차지하면됨.
// 종만북의 하위 난이도 문제에 속함.


// [.][.][.]
// [.][o][x]
// [.][.][o]
// 이걸 1차원 행렬고 나열한다면 9개칸이 된다. 한칸에 올수있는 경우 3가지( '.' , 'o', 'x') ==> [3^9 = 19683]

int HashKey(const vector<vector<char>>& board)
{
    int ret = 0;

    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            ret = ret * 3;
            if (board[y][x] == 'o')
                ret += 1;
            else if (board[y][x] == 'x')
                ret += 2;
        }
    }


    return ret;
}

vector<vector<char>> board;
int cache[19683];

enum
{
    DEFAULT = 2,
    WIN = 1,
    DRAW = 0,
    LOSE = -1
};

bool IsFinished(const vector<vector<char>>& board, char turn)
{
    // 좌우
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == turn && board[i][1] == turn && board[i][2] == turn)
            return true;
    }

    // 상하
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == turn && board[1][i] == turn && board[2][i] == turn)
            return true;
    }

    // 대각선
    if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn)
        return true;

    if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn)
        return true;

    return false;

}

int CanWin(vector<vector<char>>& board, char turn)
{
    // 기저 사례
    if (IsFinished(board, 'o' + 'x' - turn))
        return LOSE;


    // 캐시 확인
    int key = HashKey(board);
    int& ret = cache[key];
    if (ret != DEFAULT)
        return ret;


    // 풀기
    int minValue = DEFAULT;

    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            if (board[y][x] != '.')
                continue;

            // 착수(돌을 놓는다)
            board[y][x] = turn;

            // 확인
            minValue = min(minValue, CanWin(board, 'o' + 'x' - turn));// 내가 이길려면 상대방이 패배하는게 제일 좋은 케이스

            // 취소
            board[y][x] = '.';

        }
    }

    if (minValue == DRAW || minValue == DEFAULT)
        return ret = DRAW;

    return ret = -minValue;

}


int main()
{
    board = vector<vector<char>>
    {
        {'.','.',','},
        {'.','.',','},
        {'.','.',','}
    };

    // memset은 1 byte
    //왜냐면은 이 memset 이라는 것 자체가 1바이트 단위로 여기 있는 숫자로 일단 밀어주는것이다.
    // 4바이트의 -2, 1바이트의 -2가 비트가 틀리기 때문. 따라서 for문으로 세팅을 해야한다.
    //memset(cache, (char) - 2, sizeof(cache));
    //memset(cache, 0, sizeof(cache));// 0 0 0 0 0000
    //memset(cache, -1, sizeof(cache));// 0b11111111

    for (int i = 0; i < 19683; i++)
    {
        cache[i] = DEFAULT;
    }

    int win = CanWin(board, 'o');

    switch (win)
    {
    case WIN:
        cout << "Win" << endl;
        break;
    case DRAW:
        cout << "Draw" << endl;
        break;
    case LOSE:
        cout << "Lose" << endl;
        break;
    }

}

