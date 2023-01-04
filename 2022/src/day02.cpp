#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <string>

using namespace std;

const vector<int> vTruthTable{0, 6, 4, 5, 3, 1, 2};
const vector<int> vScoreTable{0, 1, 2, 3}; // NA, Rock, Paper, Sissors
const vector<int> vOutcomeTable{0, 3, 6}; // Loss, Draw, Win
const vector<string> vGameVerbs{"N/A", "Rock", "Paper", "Sissors"};
const vector<string> vStateVerbs{"N/A", "Lose", "Draw", "Win"};

int Part1();
int Part2();

int Parse();

int main(int argc, char *argv[])
{
    if(Part1())
    {
        return 1;
    }

    cout << "--------------------------" << endl;

    if(Part2())
    {
        return 2;
    }

    return 0;
}

int CalculateScore(int _nWinDrawLossState, pair<int, int> _pairScoringHand)
{
    return vOutcomeTable[_nWinDrawLossState] + vScoreTable[_pairScoringHand.second - 3];
}

int PlayRound(pair<int,int> _pairHands)
{
    if(_pairHands.first == _pairHands.second - 3)
    {
        return 1;
    }

    return (vTruthTable[_pairHands.first] == _pairHands.second?0:2);
}

void Cheat(pair<int, int> *_pairCurrentHand)
{
    switch(_pairCurrentHand->second - 3)
    {
        case 1: // Lose
            *_pairCurrentHand = make_pair(_pairCurrentHand->first, vTruthTable[_pairCurrentHand->first]);
            break;
        case 2: // Draw
            *_pairCurrentHand = make_pair(_pairCurrentHand->first, _pairCurrentHand->first + 3);
            break;
        case 3: // Win
            for(int i = 1; i <= 6; i++)
            {
                if(vTruthTable[i] == _pairCurrentHand->first)
                {
                    *_pairCurrentHand = make_pair(_pairCurrentHand->first, i);
                    break;
                }

            }

            break;
        default:// Error
            break;

    }

}

int Part2()
{
    ifstream inputStream("./data/day02.txt", ifstream::in);
    if(!inputStream.is_open())
    {
        std::cerr << "Unable to open file './data/day02.txt'. Aborting!\n";
        return 1;
    }

    char szEntry[8];
    int nTotalPlayerScore = 0;
    while(!inputStream.eof())
    {
        inputStream.getline(szEntry, 8);
        if(!strlen(szEntry)) { continue; }

        pair<int,int> pairCurrentHand(szEntry[0] - 0x40, szEntry[2] - 0x54);
        Cheat(&pairCurrentHand);
        int nWinDrawLossState = PlayRound(pairCurrentHand);
        switch(nWinDrawLossState)
        {
            case 0: //LOSS
                break;
            case 1: // DRAW
                break;
            case 2: // WIN
                break;
            default:// ERROR
                cout << endl << "ERROR! Unknown error has occurred! Aborting" << endl;
                inputStream.close();
                return 1;
        } 

        int nHandScore = CalculateScore(nWinDrawLossState, pairCurrentHand);
        nTotalPlayerScore += nHandScore;
    }
    
    cout << "[Day02-Part2] -> Total Player Score: " << nTotalPlayerScore << endl;
    inputStream.close();
    return 0;
}

int Part1()
{
    ifstream inputStream("./data/day02.txt", ifstream::in);
    if(!inputStream.is_open())
    {
        std::cerr << "Unable to open file './data/day02.txt'. Aborting!\n";
        return 1;
    }

    char szEntry[8];
    int nTotalPlayerScore = 0;
    while(!inputStream.eof())
    {
        inputStream.getline(szEntry, 8);
        if(!strlen(szEntry)) { continue; }
        pair<int,int> pairCurrentHand(szEntry[0] - 0x40, szEntry[2] - 0x54);
        int nWinDrawLossState = PlayRound(pairCurrentHand);
        switch(nWinDrawLossState)
        {
            case 0: //LOSS
                break;
            case 1: // DRAW
                break;
            case 2: // WIN
                break;
            default:// ERROR
                cout << endl << "ERROR! Unknown error has occurred! Aborting" << endl;
                inputStream.close();
                return 1;
        } 

        int nHandScore = CalculateScore(nWinDrawLossState, pairCurrentHand);
        nTotalPlayerScore += nHandScore;
    }
    
    cout << "[Day02-Part1] -> Total Player Score: " << nTotalPlayerScore << endl;
    inputStream.close();
    return 0;
}
