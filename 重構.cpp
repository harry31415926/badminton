#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    int n = 0;
    string name1, name2;
    int winscore = 0;
    int score1, score2;

    int wintimes[100] = { 0 };
    string name3[100] = { "" };

    while (true /*要不要繼續*/)
    {
        n++;

        // name1, name2, score1, score2
        #pragma region 比賽 

        #pragma region 參數設定

        int option = 2;

        while (option != 1)
        {
            cout << "★☆★ 羽毛球大賽第" << n << "場★☆★\n\n";
            cout << "請輸入1號選手的名字: ";
            cin >> name1;
            cout << "請輸入2號選手的名字: ";
            cin >> name2;
            cout << "請輸入幾分制: ";
            cin >> winscore;
            cout << "\n";
            cout << "1 - 正確無誤 2 - 重新輸入 ";
            cin >> option;
        }

        #pragma endregion
          
        #pragma region 計分
        score1 = 0;
        score2 = 0;

        bool isRoundContinue = true;

        while (isRoundContinue)
        {
            int who_win;

            //使用者輸入某次誰贏得比賽
        user_input_who_win:
            system("cls");
            cout << name1 << " ------ " << score1 << " V|S " << score2 << " ------ " << name2 << "\n\n";
            cout << "(1) " << name1 << "得分 " << "(2) " << name2 << "得分 ";
            cin >> who_win;
            if (who_win != 1 && who_win != 2)
            {
                cout << "輸入錯誤!";
                Sleep(1500);
                goto user_input_who_win;
            }

            //紀錄得分
            if (who_win == 1)
                score1++;
            else
                score2++;

            // 判斷是否繼續
            if (score1 >= winscore || score2 >= winscore)
            {
                if (max(score1, score2) - min(score1, score2) < 2)
                {
                    cout << "必須打到贏對方2分\n";
                    isRoundContinue = true;
                }
                else
                {
                    isRoundContinue = false;
                }
            }
        }

        #pragma endregion

        system("cls");
        cout << "比賽結束!!!\n";
        cout << name1 << "得了" << score1 << "分 " << name2 << "得了" << score2 << "分 \n";

        #pragma endregion

        // name3, wintimes
        #pragma region 紀錄結果

        bool Used = 0;
        string winner;
        if (score1 > score2)
            winner = name1;
        else
            winner = name2;

        cout << winner << "獲勝!!\n\n";
        for (int i = n; i >= 0; i--)
        {
            if (name3[i] == winner)
            {
                wintimes[i]++;
                Used = 1;
            }
        }
        if (Used == 0)
        {
            name3[n - 1] = winner;
            wintimes[n - 1]++;
        }
        
        #pragma endregion

        #pragma region 顯示結果
        int rank = 1;
        bool isRankUsed = false; // 名次(rank)是否已經被使用過

        cout << "★☆★風雲排行榜★☆★\n\n";
        for (int i = n; i >= 1; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (wintimes[j] == i)
                {
                    cout << "第" << rank << "名\t" << name3[j] << "\t" << "贏了" << wintimes[j] << "人\n";
                    isRankUsed = true;
                }
            }

            if (isRankUsed)
                rank++;
        }
        cout << "\n";
        system("pause");
        system("cls");

        #pragma endregion
    }
}
