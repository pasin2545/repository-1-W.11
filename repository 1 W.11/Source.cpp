#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
struct total
{
    string w;
    int score = 0;
    int goaled = 0;
    int goals = 0;
};

bool res1(total& x, total& y)
{
    return x.score > y.score;
}
bool res2(total& x, total& y)
{
    if (x.score == y.score)
        return x.goaled > y.goaled;
    else return 0;
}
bool res3(total& x, total& y)
{
    if (x.score == y.score and x.goaled == y.goaled)
        return x.goals > y.goals;
    else return 0;
}


int main()
{
    total name[4];
    int data[5][5];
    for (int i = 0; i < 4; i++)
        cin >> name[i].w;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> data[i][j];

    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 4; j++)
        {
            if (data[i][j] > data[j][i])
                name[i].score += 3;
            else if (data[i][j] < data[j][i])
                name[j].score += 3;
            else
            {
                name[i].score += 1;
                name[j].score += 1;
            }

            name[i].goals += data[i][j];
            name[j].goals += data[j][i];
            name[i].goaled += data[i][j] - data[j][i];
            name[j].goaled += data[j][i] - data[i][j];
        }
    sort(name, name + 4, res1);
    sort(name, name + 4, res2);
    sort(name, name + 4, res3);

    for (int i = 0; i < 4; i++)
        cout << name[i].w << " " << name[i].score << endl;

}