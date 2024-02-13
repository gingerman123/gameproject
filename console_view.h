#pragma once


#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include "Windows.h"
#include <conio.h>
#include <cstdlib>
#include <ctime>





using namespace std;


void con_init() {      // 콘솔 창 크기 설정
    system("mode con cols=239 lines=62");
    SetConsoleOutputCP(CP_UTF8);
}



void con_goto_xy(int x, int y) { // 커서 위치 이동

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);

}

void con_out(int x, int y, string what) {         //   출력 좌표 설정,       아스키아트 메모장 주소 입력
    ifstream inputFile(what);

    if (!inputFile.is_open()) {
        cerr << "파일을 열 수 없습니다." << endl;
    }
    else {
        string line;
        while (getline(inputFile, line)) {
            con_goto_xy(x, y);
            cout << line << endl;
            y++;
        }
        inputFile.close();
    }
}

string con_first_view() {
    system("cls");
    con_init();
    con_out(65, 2, "img/main.txt");
    con_out(95, 33, "img/start.txt");
    con_out(95, 41, "img/credit.txt");
    con_out(95, 49, "img/exit.txt");
    con_out(85, 33, "img/select.txt");

    int input;
    int y = 33;

    while (true) {
        input = _getch();



        if (input == 13) {
            break;
        }
        else if (input == 224) {
            input = _getch();
            con_out(85, 33, "img/m-erase.txt");
            if (input == 72) { // 위
                if (y != 33) {
                    y = y - 8;
                }
            }
            else if (input == 80) { // 아래
                if (y != 49) {
                    y = y + 8;
                }
            }
            con_out(85, y, "img/select.txt");
        }
    }

    if (y == 33) {
        return "start";
    }
    else if (y == 41) {
        return "credit";
    }
    else if (y == 49) {
        return "exit";
    }
}

string con_start_view() {
    system("cls");
    con_out(65, 2, "img/main.txt");
    con_out(75, 33, "img/storymode.txt");
    con_out(75, 41, "img/fightmode.txt");
    con_out(75, 49, "img/return.txt");
    con_out(65, 33, "img/select.txt");

    int input;
    int y = 33;

    while (true) {
        input = _getch();

        if (input == 13) {
            break;
        }
        else if (input == 224) {
            input = _getch();
            con_out(65, 33, "img/m-erase.txt");
            if (input == 72) { // 위
                if (y != 33) {
                    y = y - 8;
                }
            }
            else if (input == 80) { // 아래
                if (y != 49) {
                    y = y + 8;
                }
            }
            con_out(65, y, "img/select.txt");
        }
    }

    if (y == 33) {
        return "story mode";
    }
    else if (y == 41) {
        return "fight mode";
    }
    else if (y == 49) {
        return "return";
    }
}

string con_storymode_view() {
    system("cls");
    con_out(65, 2, "img/main.txt");
    con_out(75, 33, "img/notready.txt");
    con_out(75, 48, "img/return.txt");
    con_out(65, 48, "img/select.txt");

    int input;
    int y = 33;

    while (true) {
        input = _getch();

        if (input == 13) {
            break;
        }
    }

    return "return";
}

string con_name_set_view() { //이름 설정하는 창
    system("cls");
    con_init();
    con_out(65, 2, "img/이름 화면.txt");
    con_out(65, 50, "img/틀.txt");
    SetConsoleOutputCP(949);
    con_goto_xy(70, 52);
    cout << "안녕 ! 모험을 시작하기 전에 내 이름을 입력해줘!";
    con_goto_xy(70, 54);
    cout << "이름 : ";
    string user_name;
    cin >> user_name; //이름 입력받기
    
    while (true) {
        
        string y_n;
        SetConsoleOutputCP(CP_UTF8);
        con_out(65, 50, "img/틀.txt");
        SetConsoleOutputCP(949);
        con_goto_xy(70, 52);
        cout << "입력한 이름이 " << user_name << "이 맞아? ";
        con_goto_xy(70, 54);
        cout << "(Y / N) : ";
        cin >> y_n;

        while (true) {
            if (y_n == "Y" || y_n == "N") {
                break;
            }
            SetConsoleOutputCP(CP_UTF8);
            con_out(65, 50, "img/틀.txt");
            SetConsoleOutputCP(949);
            con_goto_xy(70, 52);
            cout << "(Y / N)으로 입력해줘! : ";
            cin >> y_n;
        }

        if (y_n == "Y") {
            break;
        }

        SetConsoleOutputCP(CP_UTF8);
        con_out(65, 50, "img/틀.txt");
        SetConsoleOutputCP(949);
        con_goto_xy(70, 52);
        cout << "내 이름을 다시 입력해줘!";
        con_goto_xy(70, 54);
        cout << "이름 : ";
        cin >> user_name; //이름 입력받기
    }

    return user_name;
}

string con_first_monster_view() {
    string m_type_input;
    system("cls");
    con_init();
    con_out(5, 3, "img/mon/L/꼬부기.txt");
    con_out(80, 3, "img/mon/L/파이리.txt");
    con_out(160, 3, "img/mon/L/이상해씨.txt");
    con_out(15, 40, "img/틀_s.txt");
    con_out(92, 40, "img/틀_s.txt");
    con_out(175, 40, "img/틀_s.txt");
    SetConsoleOutputCP(949);
    con_goto_xy(29, 42);
    cout << "물 속성 <water>";
    con_goto_xy(33, 44);
    cout << "꼬부기";
    con_goto_xy(106, 42);
    cout << "불 속성 <fire>";
    con_goto_xy(110, 44);
    cout << "파이리";
    con_goto_xy(190, 42);
    cout << "풀 속성 <leaf>";
    con_goto_xy(193, 44);
    cout << "이상해씨";
    
    bool first_time = true;

    while (true) {
        string y_n;
        SetConsoleOutputCP(CP_UTF8);
        con_out(65, 50, "img/틀.txt");
        SetConsoleOutputCP(949);
        con_goto_xy(70, 53);
        cout << "기본 몬스터 속성을 선택해줘! (물 / 불 / 풀). : ";
        cin >> m_type_input;
        while (true) {
            if (m_type_input != "물" && m_type_input != "불" && m_type_input != "풀") {
                SetConsoleOutputCP(CP_UTF8);
                con_out(65, 50, "img/틀.txt");
                SetConsoleOutputCP(949);
                con_goto_xy(70, 53);
                cout << "(물 / 불 / 풀)으로 입력해줘! : ";
                cin >> m_type_input;
                cout << endl;
            }
            else {
                break;
            }
        }
        SetConsoleOutputCP(CP_UTF8);
        con_out(65, 50, "img/틀.txt");
        SetConsoleOutputCP(949);
        con_goto_xy(70, 53);
        cout << "선택한 속성의 몬스터가 " << m_type_input << "속성이 맞아? (Y / N) : ";
        cin >> y_n;
        while (true) {
            if (y_n == "Y" || y_n == "N") {
                break;
            }
            SetConsoleOutputCP(CP_UTF8);
            con_out(65, 50, "img/틀.txt");
            SetConsoleOutputCP(949);
            con_goto_xy(70, 53);
            cout << "(Y / N)으로 입력해줘! : ";
            cin >> y_n;
        }
        if (y_n == "Y") {
            break;
        }
    }
    return m_type_input;
}

string con_sel_mon_view(string what) {
    string m_type_input = what;
    system("cls");
    con_init();
    con_out(100, 2, "img/이름 화면.txt");
    con_out(65, 50, "img/틀.txt");

    string mon_name;

    if (m_type_input == "물") {
        con_out(32, 1, "img/mon/L/꼬부기.txt");
        mon_name = "꼬부기";
    }
    else if (m_type_input == "불") {
        con_out(32, 1, "img/mon/L/파이리.txt");
        mon_name = "파이리";
    }
    else {
        con_out(32, 1, "img/mon/L/이상해씨.txt");
        mon_name = "이상해씨";
    }

    SetConsoleOutputCP(949);
    con_goto_xy(70, 52);
    cout << "☆★☆★☆★  축하해~~! ☆★☆★☆★";
    con_goto_xy(70, 54);
    cout << "☆★ " << mon_name << "를 선택했어! ☆★";

    Sleep(5000);
    string m_name;
    while (true) {
        SetConsoleOutputCP(CP_UTF8);
        con_out(65, 50, "img/틀.txt");
        SetConsoleOutputCP(949);
        con_goto_xy(70, 52);
        cout << "너의 첫 몬스터 이름을 만들어줘!";
        con_goto_xy(70, 54);
        cout << "별명 : ";
        cin >> m_name;
        SetConsoleOutputCP(CP_UTF8);
        con_out(65, 50, "img/틀.txt");
        string y_n;
        SetConsoleOutputCP(949);
        con_goto_xy(70, 53);
        cout << "너의 첫 몬스터 이름이 " << m_name <<"이 맞아? 몬스터 이름은 다시 수정할 수 없어! (Y / N) : ";
        cin >> y_n;
        while (true) {
            if (y_n == "Y" || y_n == "N") {
                break;
            }
            SetConsoleOutputCP(CP_UTF8);
            con_out(65, 50, "img/틀.txt");
            SetConsoleOutputCP(949);
            con_goto_xy(70, 53);
            cout << "(Y / N)으로 입력해줘! : ";
            cin >> y_n;
        }
        if (y_n == "Y") {
            break;
        }
        return m_name;
    }
    



}

void show_fight_menu_you() {
    SetConsoleOutputCP(CP_UTF8);
    con_out(100, 47, "img/fight_screen/틀.txt");
    //fight menu
    SetConsoleOutputCP(949);
    con_goto_xy(110, 49);
    cout << "명령을 내려줘!";
    con_goto_xy(110, 51);
    cout << "공격하기!         (치명타는 몬스터 친밀도에 비례)";
    con_goto_xy(110, 53);
    cout << "치유하기!         (몬스터 레벨에 비례하여 회복합니다! [최대 +10])";
    con_goto_xy(110, 55);
    cout << "아이템 사용하기!  (보유 아이템 사용)";
    con_goto_xy(105, 51);
    cout << "->";
}

int sel_fight_menu_you() {
    int input;
    int y = 51;

    while (true) {
        input = _getch();

        if (input == 13) {
            break;
        }
        else if (input == 224) {
            input = _getch();
            con_goto_xy(105, y);
            cout << "  ";
            if (input == 72) { // 위
                if (y != 51) {
                    y = y - 2;
                }
            }
            else if (input == 80) { // 아래
                if (y != 55) {
                    y = y + 2;
                }
            }
            con_goto_xy(105, y);
            cout << "->";
        }
    }
    return y;
}



bool check_sel_fight_menu_you(int what_menu) {
    // after fight menu select check
    string what;
    SetConsoleOutputCP(CP_UTF8);
    con_out(100, 47, "img/fight_screen/틀.txt");
    SetConsoleOutputCP(949);
    if (what_menu == 51) {
        what = "공격하기";
    }
    else if (what_menu == 53) {
        what = "회복하기";
    }
    else if (what_menu == 55) {
        what = "아이템 사용하기";
    }
    con_goto_xy(130, 51);
    cout << " \" " << what << " \" " << "를 하시겠습니까? ";
    con_goto_xy(140, 54);
    cout << "YES";
    con_goto_xy(155, 54);
    cout << "NO";
    con_goto_xy(135, 54);
    cout << "->";
    int input;
    int x = 135;
    while (true) {
        input = _getch();

        if (input == 13) {
            break;
        }
        else if (input == 224) {
            input = _getch();
            con_goto_xy(x, 54);
            cout << "  ";
            if (input == 75) { //왼
                if (x != 135) {
                    x = x - 15;
                }
            }
            else if (input == 77) { // 오른
                if (x != 150) {
                    x = x + 15;
                }
            }
            con_goto_xy(x, 54);
            cout << "->";
        }
    }
    if (x == 135) {
        return true;
    }
    else {
        return false;
    }
}

bool con_rsp_did_i_win() {
    // 누가 먼저 시작할지 선택
    while (true) {
        system("cls");
        con_init();
        con_out(50, 5, "img/fight_screen/wsf.txt");
        con_out(70, 15, "img/fight_screen/rsp.txt");
        con_out(80, 35, "img/fight_screen/upa_e.txt");
        con_out(80, 35, "img/fight_screen/upa.txt");    // +34
        int input;
        int x = 80;
        while (true) {
            input = _getch();

            if (input == 13) {
                break;
            }
            else if (input == 224) {
                input = _getch();
                con_out(80, 35, "img/fight_screen/upa_e.txt");
                if (input == 75) { //왼
                    if (x != 80) {
                        x = x - 34;
                    }
                }
                else if (input == 77) { // 오른
                    if (x != 148) {
                        x = x + 34;
                    }
                }
                con_out(x, 35, "img/fight_screen/upa.txt");
            }
        }
        srand(time(NULL));
        int com_rsp = rand() % 3 + 1;
        int rsp_list[] = { 70,104,138 };
        string result;
        if (x == 80) {           //rock
            x = 1;
            if (com_rsp == 1) {
                result = "draw";
            }
            else if (com_rsp == 2) {
                result = "win";
            }
            else {
                result = "lose";
            }
        }
        else if (x == 114) {    //scissor
            x = 2;
            if (com_rsp == 1) {
                result = "lose";
            }
            else if (com_rsp == 2) {
                result = "draw";
            }
            else {
                result = "win";
            }

        }
        else {                  //paper
            x = 3;
            if (com_rsp == 1) {
                result = "win";
            }
            else if (com_rsp == 2) {
                result = "lose";
            }
            else {
                result = "draw";
            }
        }

        if (result != "draw") {
            con_out(rsp_list[x - 1], 42, "img/fight_screen/you.txt");
            con_out(rsp_list[com_rsp - 1], 42, "img/fight_screen/com.txt");
            if (result == "win") {
                con_out(87, 50, "img/fight_screen/youwin.txt");
                Sleep(3000);
                return true;
            }
            else {
                con_out(87, 50, "img/fight_screen/comwin.txt");
                Sleep(3000);
                return false;
            }
            break;
        }
        else {
            con_out(102, 42, "img/fight_screen/draw.txt");
            Sleep(3000);
        }
    }
}

void show_fight_menu_com() {
    SetConsoleOutputCP(CP_UTF8);
    con_out(100, 47, "img/fight_screen/틀.txt");
    // 컴퓨터 랜덤 명령어 생성
    srand(time(NULL));
    int com_act = rand() % 2 + 1;
    
    if (com_act == 1) {
        SetConsoleOutputCP(949);
        con_goto_xy(110, 50);
        cout << "상대방 차례 입니다!";
        con_goto_xy(110, 52);
        cout << "상대방이 공격하기를 선택하였습니다!.";
    }

    //fight menu
    SetConsoleOutputCP(949);
    con_goto_xy(110, 49);
    cout << "명령을 내려줘!";
    con_goto_xy(110, 51);
    cout << "공격하기!         (치명타는 몬스터 친밀도에 비례)";
    con_goto_xy(110, 53);
    cout << "방어하기!         (상대 공격의 나의 방어력 만큼 차감)";
    con_goto_xy(110, 55);
    cout << "피하기!           (회피 확률은 이동속도에 비례)";
    con_goto_xy(110, 57);
    cout << "아이템 사용하기!  (보유 아이템 사용)";
    con_goto_xy(105, 51);
    cout << "->";
}

int sel_fight_menu_com() {
    int input;
    int y = 51;

    while (true) {
        input = _getch();

        if (input == 13) {
            break;
        }
        else if (input == 224) {
            input = _getch();
            con_goto_xy(105, y);
            cout << "  ";
            if (input == 72) { // 위
                if (y != 51) {
                    y = y - 2;
                }
            }
            else if (input == 80) { // 아래
                if (y != 57) {
                    y = y + 2;
                }
            }
            con_goto_xy(105, y);
            cout << "->";
        }
    }
    return y;
}

bool check_sel_fight_menu_com(int what_menu) {
    // after fight menu select check
    string what;
    SetConsoleOutputCP(CP_UTF8);
    con_out(100, 47, "img/fight_screen/틀.txt");
    SetConsoleOutputCP(949);
    if (what_menu == 51) {
        what = "공격하기";
    }
    else if (what_menu == 53) {
        what = "방어하기";
    }
    else if (what_menu == 55) {
        what = "피하기";
    }
    else if (what_menu == 57) {
        what = "아이템 사용하기";
    }
    con_goto_xy(130, 51);
    cout << " \" " << what << " \" " << "를 하시겠습니까? ";
    con_goto_xy(140, 54);
    cout << "YES";
    con_goto_xy(155, 54);
    cout << "NO";
    con_goto_xy(135, 54);
    cout << "->";
    int input;
    int x = 135;
    while (true) {
        input = _getch();

        if (input == 13) {
            break;
        }
        else if (input == 224) {
            input = _getch();
            con_goto_xy(x, 54);
            cout << "  ";
            if (input == 75) { //왼
                if (x != 135) {
                    x = x - 15;
                }
            }
            else if (input == 77) { // 오른
                if (x != 150) {
                    x = x + 15;
                }
            }
            con_goto_xy(x, 54);
            cout << "->";
        }
    }
    if (x == 135) {
        return true;
    }
    else {
        return false;
    }
}

void CursorView(bool show)//커서 깜빡임
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
