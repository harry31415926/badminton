#include<iostream>
#include<cstdlib>
#include <windows.h>
using namespace std;
int main()
{
    //程式變數
    int option, score1, score2;
    int n = 0, winscore = 0, wintimes[100] = { 0 }, p = 1;
    bool torf = 1;
    string name1, name2, name3[100] = { "" };
re:
    n++;
again:
    score1 = 0;
    score2 = 0;
    //比賽
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
        //判斷輸贏
        if (option == 1)
        {
        re1:
            system("cls");
            if (score1 >= winscore || score2 >= winscore)
            {
                if (max(score1, score2) - min(score1, score2) < 2)
                {
                    cout << "必須打到贏對方2分\n";
                    goto re3;
                }
                system("cls");
                cout << "比賽結束!!!\n";
                cout << name1 << "得了" << score1 << "分 " << name2 << "得了" << score2 << "分 \n";
                if (score1 > score2)
                {
                    cout << name1 << "獲勝!!\n\n";
                    //紀錄結果
                    for (int i = n; i >= 0; i--)
                    {
                        if (name3[i] == name1)
                        {
                            wintimes[i]++;
                            goto p;
                        }
                    }
                    name3[n - 1] = name1;
                    wintimes[n - 1]++;
                p:
                    //印出結果
                    cout << "★☆★風雲排行榜★☆★\n\n";
                    for (int i = n; i >= 1; i--)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            if (wintimes[j] == i)
                            {
                                torf = 0;
                                cout << "第" << p << "名\t" << name3[j] << "\t" << "贏了" << wintimes[j] << "人\n";
                            }
                        }
                        if (torf == 0)
                        {
                            p++;
                        }
                        torf = 1;
                    }
                    p = 1;
                    torf = 1;
                    cout << "\n";
                    system("pause");
                    system("cls");
                    goto re;
                }
                else
                {
                    cout << name2 << "獲勝!!\n\n";
                    //紀錄結果
                    for (int i = n; i >= 0; i--)
                    {
                        if (name3[i] == name2)
                        {
                            wintimes[i]++;
                            goto p1;
                        }
                    }
                    name3[n - 1] = name2;
                    wintimes[n - 1]++;
                p1:
                    //印出結果
                    cout << "★☆★風雲排行榜★☆★\n\n";
                    for (int i = n; i >= 1; i--)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            if (wintimes[j] == i)
                            {
                                torf = 0;
                                cout << "第" << p << "名\t" << name3[j] << "\t" << "贏了" << wintimes[j] << "人\n";
                            }                     
                        }
                        if (torf == 0)
                        {
                            p++;
                        }
                        torf = 1;
                    }
                    p = 1;
                    cout << "\n";
                    system("pause");
                    system("cls");
                    goto re;
                }
            }
        re3:
            cout << name1 << " ------ " << score1 << " V|S " << score2 << " ------ " << name2 << "\n\n";
            cout << "(1) " << name1 << "得分 " << "(2) " << name2 << "得分 ";
            cin >> option;
            if (option == 1)
            {
                score1++;
                goto re1;
            }
            else if (option == 2)
            {
                score2++;
                goto re1;
            }
            else
            {
                cout << "輸入錯誤!";
                Sleep(1500);
                goto re1;
            }
        }
        else if (option == 2)
        {
            system("cls");
            goto again;
        }
        else
        {
            cout << "輸入錯誤!";
            Sleep(1500);
            system("cls");
            goto re;
        }
}