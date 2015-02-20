#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int flag = 0;
        string X, Y;
        for (int i = 0; i < n; i++)
        {
            cin >> X >> Y;
            if (
                (X == "paper" && Y == "rock") ||
                (X == "rock" && Y == "scissors") ||
                (X == "scissors" && Y == "paper")
            )
                flag++;
            if (
                (X == "rock" && Y == "paper") ||
                (X == "scissors" && Y == "rock") ||
                (X == "paper" && Y == "scissors")
            )
                flag--;
        }
        if (flag == 0)
            cout << "Jiong!" << endl;
        if (flag > 0)
            cout << "xinge008" << endl;
        if (flag < 0)
            cout << "OceanLight" << endl;
    }
    return 0;
}