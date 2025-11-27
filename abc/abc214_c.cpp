// 反時計回りの人がN人並んでいる。i番目の人が宝石をもらうと、S時間後、よってSi+t時間後に宝石をN+1番目の人に渡す。ただし、N人目の人の場合、渡すのは1人目になる。また、高橋くんはTiにi番目の人に宝石を渡す。この条件の時に、全てのiについてi番目の人が宝石をもらう時刻を出力する。
// [ 問題 ] SiとTiが10^9であるため、カウンタを愚直に増やしていくのでは間に合わない。また、i番目の高橋くんが宝石を渡してくれる時刻がバラバラであるため、人が一番早く渡される時刻を出力するのが難しい。
// [ 解決 ] i番目の人が受け取った宝石の時刻getTimeをTiで初期化する。そうすることで。i番目の人が宝石を受け取る最大値が保存される。i + 1番目の人が宝石を受け取るときのより小さな時間は、i + 1番目の人のgetTimeに保存されている時間 or i番目の人がi+1番目に渡すまでの時間の何れかである。したがって、判別方法はmin(getTime.at(i), getTime.at(i - 1) + S.at(i - 1))でgetTimeの最小値を求めていく。
// [ 解決2 ] 1 ~ N人まで求め終わったあと、もう一周同じ動作をする必要性がある。理由としてはN人目の処理が終わったあとにそこで止まってしまうと、i == 0の時に見てた最小値が変わる可能性があるからである。そのため一度の処理では終わらせずに、もう一周動かすことで上手くいく。

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;


    // intでもACできたが、後のgetTimeが2*10^9の値を取る可能性があるため、long longを採用している。
    vector<long long> T;
    vector<long long> S;

    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        S.push_back(t);
    }
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        T.push_back(t);
    }
    // ここでgetTimeをTで初期化してgetTimeの最大値を決める。
    vector<long long> getTime = T;

    // 2回繰り返さないとN人目のgetTimeを使って1人目のgetTimeを調べられない
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j == 0)
            {
                getTime.at(j) = min(getTime.at(j), S.at(N - 1) + getTime.at((N - 1)));
            }
            else
            {
                getTime.at(j) = min(getTime.at(j), S.at((j - 1)) + getTime.at((j - 1)));
            }
            if (i == 1)
            {
                // 2回目繰り返したら出力してしまってok
                cout << getTime.at(j) << endl;
            }
        }
    }
}