#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;

typedef map<int, deque<char> > dictionary;
typedef pair<int, int> item;

int Part1();
int Part2();

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

vector<string> split(const string &_sString, char _cDelimiter)
{
    stringstream ss(_sString);
    vector<string> vResult;
    string sLeft;
    while(getline(ss, sLeft, _cDelimiter))
    {
        vResult.push_back(sLeft);
    }

    return vResult;
}

pair<int, int> getHeaderSize(ifstream &_inputStream, pair<int, int> &_pair)
{
    int nPos = _inputStream.tellg();
    _inputStream.seekg(0, ios::beg);
    char szReadline[48];
    int nLeft = 0, nRight = 0, nLength = 0;
    _pair.first = 0;
    do
    {
        _inputStream.getline(szReadline, 48);
        nLength = strlen(szReadline);
        if(!_pair.first) 
        {
            _pair.first = nLength + 1; 
        }

        nRight++;

    } while(nLength > 1);

    _inputStream.seekg(nPos);
    _pair.second = nRight - 2;
    return _pair;
}

dictionary readStackingData(ifstream &_inputStream, dictionary &_dicDictionary)
{
    _inputStream.seekg(0, ios::beg);
    pair<int, int> pStackingSize = getHeaderSize(_inputStream, pStackingSize);

    char szReadline[48];
    for(int j{0}; j < pStackingSize.second; j++) // height
    {
        _inputStream.getline(szReadline, 48);
        for(int i{0},j{0}; i < pStackingSize.first; i+=4,j++) // width
        {
            if(szReadline[i + 1] != 0x20)
            {
                _dicDictionary[j].push_back(szReadline[i + 1]);
            }

        }

    }

    return _dicDictionary;
}

int readCommandLineData(ifstream &_inputStream, vector<string> &_vCommandStrings)
{
    _inputStream.seekg(0, ios::beg);
    pair<int, int> pStackingSize = getHeaderSize(_inputStream, pStackingSize);
    char szReadLine[48];
    int nCommandCount = 0;
    for(int i{0}; i < pStackingSize.second + 2; i++)
    {
        _inputStream.getline(szReadLine, 48);
    }

    while(!_inputStream.eof())
    {
        try
        {
            _inputStream.getline(szReadLine, 48);
            _vCommandStrings.push_back(string(szReadLine));
            nCommandCount++;
        }
        catch(const ifstream::failure& e)
        {
            if((_inputStream.rdstate() & ios::eofbit) != 0)
                break;
                
            std::cerr << "ERR: " << e.what() << '\n';
        }
        
    }

    return nCommandCount;
}

dictionary moveStackElement(int _nHowMany, int _nFromStack, int _nToStack, dictionary &_dicDictionary, bool _bUsesCrateMover9001 = false)
{
    deque<char> deqTempQue;
    for(int i{0}; i < _nHowMany; i++)
    {
        char cItem = _dicDictionary[_nFromStack].front();
        if(_bUsesCrateMover9001)
        {
            deqTempQue.push_back(cItem);
            _dicDictionary[_nFromStack].pop_front();
        }
        else
        {
            _dicDictionary[_nFromStack].pop_front();
            _dicDictionary[_nToStack].push_front(cItem);
        }

    }

    if(_bUsesCrateMover9001)
    {
        
        while(deqTempQue.size())
        {
            char cItem = deqTempQue.back();
            deqTempQue.pop_back();
            _dicDictionary[_nToStack].push_front(cItem);
        }

    }

    return _dicDictionary;
}

vector<int> parseStackCommandLine(string &_sCommandLine, vector<int> &_vCommandTokens)
{
    int nToPos = _sCommandLine.find("to");
    string sToValue = _sCommandLine.substr(nToPos + 3);

    int nFromPos = _sCommandLine.find("from");
    string sFromValue = _sCommandLine.substr(nFromPos + 5, nToPos - (nFromPos + 5));

    int nMovePos = _sCommandLine.find("move");
    string sMoveValue = _sCommandLine.substr(nMovePos + 5, nFromPos - (nMovePos + 5));

    _vCommandTokens.push_back(atoi(sMoveValue.c_str()));
    _vCommandTokens.push_back(atoi(sFromValue.c_str()) - 1);
    _vCommandTokens.push_back(atoi(sToValue.c_str()) - 1);

    return _vCommandTokens;
}

dictionary ExecuteCommandQue(vector<string> &_vCommandQue, dictionary &_dicDictionary, bool _bUsesCrateMover9001 = false)
{
    vector<int> vCommands;
    for(string sCommand: _vCommandQue)
    {
        vCommands = parseStackCommandLine(sCommand, vCommands);
        moveStackElement(vCommands[0], vCommands[1], vCommands[2], _dicDictionary, _bUsesCrateMover9001);
        vCommands.clear();
    }

    return _dicDictionary;
}

void displayStackTops(dictionary _dicDictionary)
{
    for(int i = 0; i < _dicDictionary.size();i++)
    {
        cout << _dicDictionary[i].front();
    }

    cout << endl;
}

int Part2()
{
    ifstream inputStream("./data/day05.txt", ifstream::in);
    inputStream.exceptions( ifstream::failbit | ifstream::badbit );
    if(!inputStream.is_open())
    {
        std::cerr << "Unable to open file './data/day05.txt'. Aborting!\n";
        return 1;
    }

    dictionary dicDictionary;
    pair<int, int> pItem;

    for(int j{0}; j < getHeaderSize(inputStream, pItem).first / 4; j++)
        dicDictionary[j] = deque<char>();

    readStackingData(inputStream, dicDictionary);
    vector<string> vCommandQue;
    int nNumberOfCommands = readCommandLineData(inputStream,vCommandQue);
    ExecuteCommandQue(vCommandQue, dicDictionary, true);

    cout << "Result: ";
    displayStackTops(dicDictionary);
    return 0;
}

int Part1()
{
    ifstream inputStream("./data/day05.txt", ifstream::in);
    inputStream.exceptions( ifstream::failbit | ifstream::badbit );
    if(!inputStream.is_open())
    {
        std::cerr << "Unable to open file './data/day05.txt'. Aborting!\n";
        return 1;
    }

    dictionary dicDictionary;
    pair<int, int> pItem;

    for(int j{0}; j < getHeaderSize(inputStream, pItem).first / 4; j++)
        dicDictionary[j] = deque<char>();

    readStackingData(inputStream, dicDictionary);

    vector<string> vCommandQue;
    int nNumberOfCommands = readCommandLineData(inputStream,vCommandQue);
    ExecuteCommandQue(vCommandQue, dicDictionary);

    cout << "Result: ";
    displayStackTops(dicDictionary);
    return 0;
}
