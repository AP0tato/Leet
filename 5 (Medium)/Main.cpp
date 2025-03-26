#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

class Solution 
{
    public:
    string longestPalindrome(string s) 
    {
        if(s.length() == 1)
            return s;
        string sub = s.substr(0, 1);
        for(int i = 0; i < s.length(); i++)
        {
            bool a = false;
            bool b = false;
            for(int j = 1, k = 1; max(j, k) < s.length()-i; j++, k++)
            {
                if(i-k<0)
                {
                    k = i;
                    b = true;
                }
                if(s[i-k] == s[i+j])
                {
                    if(b && s[i] != s[i-k])
                        break;
                    a = true;
                    string t = s.substr(i-k, j+k+1);
                    sub = t.length() > sub.length() ? t : sub;
                }
                else if(s[i] == s[i+j] && !a)
                {
                    k--;
                    string t = s.substr(i, j+1);
                    sub = t.length() > sub.length() ? t : sub;
                }
                else
                {
                    break;
                }
            }
        }

        return sub;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> s {
        "babad"
        ,
        "cbbd"
        ,
        "a"
        ,
        "ac"
        ,
        "bb"
        ,
        "ccc"
        ,
        "abb"
        ,
        "aacabdkacaa"
        ,
        "ujtofmboiyyrjzbonysurqfxylvhuzzrzqwcjxibhawifptuammlxstcjmcmfvjuphyyfflkcbwimmpehqrqcdqxglqciduhhuhbjnwaaywofljhwzuqsnhyhahtkilwggineoosnqhdluahhkkbcwbupjcuvzlbzocgmkkyhhglqsvrxsgcglfisbzbawitbjwycareuhyxnbvounqdqdaixgqtljpxpyrccagrkdxsdtvgdjlifknczaacdwxropuxelvmcffiollbuekcfkxzdzuobkrgjedueyospuiuwyppgiwhemyhdjhadcabhgtkotqyneioqzbxviebbvqavtvwgyyrjhnlceyedhfechrbhugotqxkndwxukwtnfiqmstaadlsebfopixrkbvetaoycicsdndmztyqnaehnozchrakt"
        ,
        "mwwfjysbkebpdjyabcfkgprtxpwvhglddhmvaprcvrnuxifcrjpdgnktvmggmguiiquibmtviwjsqwtchkqgxqwljouunurcdtoeygdqmijdympcamawnlzsxucbpqtuwkjfqnzvvvigifyvymfhtppqamlgjozvebygkxawcbwtouaankxsjrteeijpuzbsfsjwxejtfrancoekxgfyangvzjkdskhssdjvkvdskjtiybqgsmpxmghvvicmjxqtxdowkjhmlnfcpbtwvtmjhnzntxyfxyinmqzivxkwigkondghzmbioelmepgfttczskvqfejfiibxjcuyevvpawybcvvxtxycrfbcnpvkzryrqujqaqhoagdmofgdcbhvlwgwmsmhomknbanvntspvvhvccedzzngdywuccxrnzbtchisdwsrfdqpcwknwqvalczznilujdrlevncdsyuhnpmheukottewtkuzhookcsvctsqwwdvfjxifpfsqxpmpwospndozcdbfhselfdltmpujlnhfzjcgnbgprvopxklmlgrlbldzpnkhvhkybpgtzipzotrgzkdrqntnuaqyaplcybqyvidwcfcuxinchretgvfaepmgilbrtxgqoddzyjmmupkjqcypdpfhpkhitfegickfszermqhkwmffdizeoprmnlzbjcwfnqyvmhtdekmfhqwaftlyydirjnojbrieutjhymfpflsfemkqsoewbojwluqdckmzixwxufrdpqnwvwpbavosnvjqxqbosctttxvsbmqpnolfmapywtpfaotzmyjwnd"
        ,
        "aaaa"
        ,
        "abbcccbbbcaaccbababcbcabca"
        ,
        "aaabaaaa"
    };
    /*
    bab
    bb
    a
    a
    bb
    ccc
    bb
    aca
    uhhu
    khvhk
    aaaa
    bbcccbb
    */
    Solution sol;

    clock_t tStart = clock();
    for(string i : s)
    {
        string j = sol.longestPalindrome(i);
        cout << i << ": " << j << endl;
    }
    cout << "Time taken: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;

    return 0;
}
