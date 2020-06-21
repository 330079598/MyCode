#include<iostream>
#include<cstring>
using namespace std;

int main(void)
{
    int n;
    string s;
    cin>>n>>s;
    for(int i = 0;i < s.length();i ++)
    {
        cout<<(char)((s[i] - 'a' + n) % 26+'a');
    }
    return 0;
}
