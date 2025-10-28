// 与えられた文字列Sを辞書順に並べてK番目に来るものは何かを出力する問題
// [ 問題 ]文字が重複した場合に階乗の計算を行なってもうまく行かない(a,a,b,bの場合でaを先頭におく場合、a,b,bと文字は三つだが、文字の組み合わせはa,bの二つのみになる。)
// [ 解決 ]文字列をそのままソートしたあと、next_permutation関数で辞書順に並べ直すと、うまくいく。next_permutation関数は、指定したイテレータの範囲において、その文字列を辞書順で次の配置にしてくれる

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    int k;
    cin >> S >> k;
    // S.begin()じゃなくてもいい
    sort(begin(S), end(S));

    for (int i = 1; i < k; i++)
    {
        // 文字列を並び替えて辞書順でk番目の並びにする(iの初期値が1なのは、最初が辞書順に置いて1番目であるため)
        next_permutation(S.begin(), S.end());
    }

    cout << S << endl;
}