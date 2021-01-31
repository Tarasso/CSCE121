#include <iostream>
#include <vector>
#include <iomanip>
#include <tuple>

using namespace std;

void win_losses(vector < tuple<string, int, string, int, string> > games, string targetTeam)
{
  int dubs = 0;
  int ls = 0;
  for(int i = 0; i < games.size(); i++)
  {
    string team1;
    string team2;
    int score1;
    int score2;
    string date;

    tie(team1,score1,team2,score2,date) = games[i];

    if(team1==targetTeam)
    {
      if(score1>score2)
        dubs++;
      else
        ls++;
    }
    if(team2==targetTeam)
    {
      if(score2>score1)
        dubs++;
      else
        ls++;
    }
  }
  cout << targetTeam << ": W=" << dubs << ", L=" << ls << endl;
}

int main()
{

  vector < tuple<string, int, string, int, string> > games;
  tuple<string, int, string, int, string> one = make_tuple("Auburn",28,"Texas A&M",20,"9/21/19");
  tuple<string, int, string, int, string> two = make_tuple("Texas A&M",31,"Arkansas",27,"9/28/19");
  tuple<string, int, string, int, string> three = make_tuple("Alabama",47,"Texas A&M",28,"10/12/19");
  tuple<string, int, string, int, string> four = make_tuple("Texas A&M",24,"Mississippi",17,"10/19/19");
  tuple<string, int, string, int, string> five = make_tuple("UTSA",14,"Texas A&M",45,"11/2/19");

  games.push_back(one);
  games.push_back(two);
  games.push_back(three);
  games.push_back(four);
  games.push_back(five);

  for(int i = 0; i < games.size(); i++)
  {
    string team1;
    string team2;
    int score1;
    int score2;
    string date;

    tie(team1,score1,team2,score2,date) = games[i];

    cout << fixed << left << setw(15) << team1 << setw(5) << score1;
    cout << fixed << left << setw(15) << team2 << setw(5) << score2;
    cout << fixed << left << setw(15) << date << endl;
  }

  win_losses(games, "Texas A&M");
  win_losses(games, "Alabama");



}
