#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
	string answer = "";
    
    char category[4][2] = {
        {'R', 'T'},
        {'C', 'F'},
        {'J', 'M'},
        {'A', 'N'}
    };
	//map<char, int> mbti = { {'R', 0}, {'T', 0}, {'C', 0}, {'F', 0}, {'J', 0}, {'M', 0}, {'A', 0}, {'N', 0} };
    map<char, int> mbti;
    
    for(int i = 0; i < 4; i++)
    {
        mbti[category[i][0]] = 0;
        mbti[category[i][1]] = 0;
    }
    
	for (int i = 0; i < survey.size(); i++)
	{
		if (choices[i] > 4)
		{
			mbti[survey[i][1]] += choices[i] - 4;
		}
		else
		{
			mbti[survey[i][0]] += 4 - choices[i];
		}
	}

    // 유형들도 배열로 만들면 하드코딩하지 않아도 됨
	//if (mbti['R'] >= mbti['T'])  answer += "R";
	//else                         answer += "T";
	//if (mbti['C'] >= mbti['F'])  answer += "C";
	//else                         answer += "F";
	//if (mbti['J'] >= mbti['M'])  answer += "J";
	//else                         answer += "M";
	//if (mbti['A'] >= mbti['N'])  answer += "A";
	//else                         answer += "N";
    for(int i = 0; i < 4; i++){
        if(mbti[category[i][0]] >= mbti[category[i][1]]) answer += category[i][0];
        else answer += category[i][1];
    }

	return answer;
}