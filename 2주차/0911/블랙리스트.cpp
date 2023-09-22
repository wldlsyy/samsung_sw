#define _CRT_SECURE_NO_WARNINGS
#ifndef _CRT_SECURE_NO_WARNINGS
#endif

#include<string>
#include<cstring> // memset, memcpy
using namespace std;

string names[10000]; // names[5] = "Jack" -> id가 5면 Jack
bool isRegister[10000]; // 특정 id가 사용중인가
bool isIn[10000]; 
/**user.cpp**/
void init()
{
    for (int i = 0;i < 10000;i++) names[i] = "";
    // primitive 타입에 대해서 memset, memcpy
    memset(isRegister, 0, sizeof(isRegister)); // 배열이름은 배열의 주소값(포인터)
    memset(isIn, 0, sizeof(isIn));
}

std::string registerID(int id, std::string name)
{
    if (isRegister[id]) {
        return "ERROR";
    }
    isRegister[id] = true;
    isIn[id] = false;
    names[id] = name;
    return "OK";
}

std::string* inout(int id)
{
    std::string* res = new std::string[2];
    if (!isRegister[id]) {
        res[0] = "ERROR";
        res[1] = "ERROR";
        return res;
    }
    res[0] = names[id];
    if (isIn[id]) {
        isIn[id] = false;
        res[1] = "OUT";
    }
    else {
        isIn[id] = true;
        res[1] = "IN";
    }
    return res;
}

/*** main.cpp ***/
#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>

#define MAX_N 100

extern void init();
extern std::string registerID(int id, std::string name);
extern std::string* inout(int id);

#define CMD_REGISTER 1
#define CMD_INOUT 2

static bool run()
{
    int query_num;
    scanf("%d", &query_num);

    init();

    std::string userAns1;
    std::string* userAns2;
    std::string ans1;
    std::string ans2;
    std::string name;
    int id;
    char tmp[100];
    char tmp2[100];
    bool ok = true;

    for (int q = 0; q < query_num; q++)
    {
        int query;
        scanf("%d", &query);

        if (query == CMD_REGISTER)
        {
            scanf("%d %s", &id, tmp);
            name = tmp;
            userAns1 = registerID(id, name);

            scanf("%s", tmp);
            ans1 = tmp;

            if (ans1 != userAns1)
                ok = false;
        }
        else if (query == CMD_INOUT)
        {
            scanf("%d", &id);

            userAns2 = inout(id);

            scanf("%s %s", tmp, tmp2);

            ans1 = tmp;
            ans2 = tmp2;

            if (ans1 != userAns2[0] || ans2 != userAns2[1])
                ok = false;
        }
    }
    return ok;
}

int main()
{
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
    return 0;
}
