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


void con_init() {      // �ܼ� â ũ�� ����
    system("mode con cols=239 lines=62");
    SetConsoleOutputCP(CP_UTF8);
}



void con_goto_xy(int x, int y) { // Ŀ�� ��ġ �̵�

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ� ��������
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);

}

void con_out(int x, int y, string what) {         //   ��� ��ǥ ����,       �ƽ�Ű��Ʈ �޸��� �ּ� �Է�
    ifstream inputFile(what);

    if (!inputFile.is_open()) {
        cerr << "������ �� �� �����ϴ�." << endl;
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
            if (input == 72) { // ��
                if (y != 33) {
                    y = y - 8;
                }
            }
            else if (input == 80) { // �Ʒ�
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
            if (input == 72) { // ��
                if (y != 33) {
                    y = y - 8;
                }
            }
            else if (input == 80) { // �Ʒ�
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

string con_name_set_view() { //�̸� �����ϴ� â
    system("cls");
    con_init();
    con_out(65, 2, "img/�̸� ȭ��.txt");
    con_out(65, 50, "img/Ʋ.txt");
    SetConsoleOutputCP(949);
    con_goto_xy(70, 52);
    cout << "�ȳ� ! ������ �����ϱ� ���� �� �̸��� �Է�����!";
    con_goto_xy(70, 54);
    cout << "�̸� : ";
    string user_name;
    cin >> user_name; //�̸� �Է¹ޱ�
    
    while (true) {
        
        string y_n;
        SetConsoleOutputCP(CP_UTF8);
        con_out(65, 50, "img/Ʋ.txt");
        SetConsoleOutputCP(949);
        con_goto_xy(70, 52);
        cout << "�Է��� �̸��� " << user_name << "�� �¾�? ";
        con_goto_xy(70, 54);
        cout << "(Y / N) : ";
        cin >> y_n;

        while (true) {
            if (y_n == "Y" || y_n == "N") {
                break;
            }
            SetConsoleOutputCP(CP_UTF8);
            con_out(65, 50, "img/Ʋ.txt");
            SetConsoleOutputCP(949);
            con_goto_xy(70, 52);
            cout << "(Y / N)���� �Է�����! : ";
            cin >> y_n;
        }

        if (y_n == "Y") {
            break;
        }

        SetConsoleOutputCP(CP_UTF8);
        con_out(65, 50, "img/Ʋ.txt");
        SetConsoleOutputCP(949);
        con_goto_xy(70, 52);
        cout << "�� �̸��� �ٽ� �Է�����!";
        con_goto_xy(70, 54);
        cout << "�̸� : ";
        cin >> user_name; //�̸� �Է¹ޱ�
    }

    return user_name;
}

string con_first_monster_view() {
    string m_type_input;
    system("cls");
    con_init();
    con_out(5, 3, "img/mon/L/���α�.txt");
    con_out(80, 3, "img/mon/L/���̸�.txt");
    con_out(160, 3, "img/mon/L/�̻��ؾ�.txt");
    con_out(15, 40, "img/Ʋ_s.txt");
    con_out(92, 40, "img/Ʋ_s.txt");
    con_out(175, 40, "img/Ʋ_s.txt");
    SetConsoleOutputCP(949);
    con_goto_xy(29, 42);
    cout << "�� �Ӽ� <water>";
    con_goto_xy(33, 44);
    cout << "���α�";
    con_goto_xy(106, 42);
    cout << "�� �Ӽ� <fire>";
    con_goto_xy(110, 44);
    cout << "���̸�";
    con_goto_xy(190, 42);
    cout << "Ǯ �Ӽ� <leaf>";
    con_goto_xy(193, 44);
    cout << "�̻��ؾ�";
    
    bool first_time = true;

    while (true) {
        string y_n;
        SetConsoleOutputCP(CP_UTF8);
        con_out(65, 50, "img/Ʋ.txt");
        SetConsoleOutputCP(949);
        con_goto_xy(70, 53);
        cout << "�⺻ ���� �Ӽ��� ��������! (�� / �� / Ǯ). : ";
        cin >> m_type_input;
        while (true) {
            if (m_type_input != "��" && m_type_input != "��" && m_type_input != "Ǯ") {
                SetConsoleOutputCP(CP_UTF8);
                con_out(65, 50, "img/Ʋ.txt");
                SetConsoleOutputCP(949);
                con_goto_xy(70, 53);
                cout << "(�� / �� / Ǯ)���� �Է�����! : ";
                cin >> m_type_input;
                cout << endl;
            }
            else {
                break;
            }
        }
        SetConsoleOutputCP(CP_UTF8);
        con_out(65, 50, "img/Ʋ.txt");
        SetConsoleOutputCP(949);
        con_goto_xy(70, 53);
        cout << "������ �Ӽ��� ���Ͱ� " << m_type_input << "�Ӽ��� �¾�? (Y / N) : ";
        cin >> y_n;
        while (true) {
            if (y_n == "Y" || y_n == "N") {
                break;
            }
            SetConsoleOutputCP(CP_UTF8);
            con_out(65, 50, "img/Ʋ.txt");
            SetConsoleOutputCP(949);
            con_goto_xy(70, 53);
            cout << "(Y / N)���� �Է�����! : ";
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
    con_out(100, 2, "img/�̸� ȭ��.txt");
    con_out(65, 50, "img/Ʋ.txt");

    string mon_name;

    if (m_type_input == "��") {
        con_out(32, 1, "img/mon/L/���α�.txt");
        mon_name = "���α�";
    }
    else if (m_type_input == "��") {
        con_out(32, 1, "img/mon/L/���̸�.txt");
        mon_name = "���̸�";
    }
    else {
        con_out(32, 1, "img/mon/L/�̻��ؾ�.txt");
        mon_name = "�̻��ؾ�";
    }

    SetConsoleOutputCP(949);
    con_goto_xy(70, 52);
    cout << "�١ڡ١ڡ١�  ������~~! �١ڡ١ڡ١�";
    con_goto_xy(70, 54);
    cout << "�١� " << mon_name << "�� �����߾�! �١�";

    Sleep(5000);
    string m_name;
    while (true) {
        SetConsoleOutputCP(CP_UTF8);
        con_out(65, 50, "img/Ʋ.txt");
        SetConsoleOutputCP(949);
        con_goto_xy(70, 52);
        cout << "���� ù ���� �̸��� �������!";
        con_goto_xy(70, 54);
        cout << "���� : ";
        cin >> m_name;
        SetConsoleOutputCP(CP_UTF8);
        con_out(65, 50, "img/Ʋ.txt");
        string y_n;
        SetConsoleOutputCP(949);
        con_goto_xy(70, 53);
        cout << "���� ù ���� �̸��� " << m_name <<"�� �¾�? ���� �̸��� �ٽ� ������ �� ����! (Y / N) : ";
        cin >> y_n;
        while (true) {
            if (y_n == "Y" || y_n == "N") {
                break;
            }
            SetConsoleOutputCP(CP_UTF8);
            con_out(65, 50, "img/Ʋ.txt");
            SetConsoleOutputCP(949);
            con_goto_xy(70, 53);
            cout << "(Y / N)���� �Է�����! : ";
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
    con_out(100, 47, "img/fight_screen/Ʋ.txt");
    //fight menu
    SetConsoleOutputCP(949);
    con_goto_xy(110, 49);
    cout << "����� ������!";
    con_goto_xy(110, 51);
    cout << "�����ϱ�!         (ġ��Ÿ�� ���� ģ�е��� ���)";
    con_goto_xy(110, 53);
    cout << "ġ���ϱ�!         (���� ������ ����Ͽ� ȸ���մϴ�! [�ִ� +10])";
    con_goto_xy(110, 55);
    cout << "������ ����ϱ�!  (���� ������ ���)";
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
            if (input == 72) { // ��
                if (y != 51) {
                    y = y - 2;
                }
            }
            else if (input == 80) { // �Ʒ�
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
    con_out(100, 47, "img/fight_screen/Ʋ.txt");
    SetConsoleOutputCP(949);
    if (what_menu == 51) {
        what = "�����ϱ�";
    }
    else if (what_menu == 53) {
        what = "ȸ���ϱ�";
    }
    else if (what_menu == 55) {
        what = "������ ����ϱ�";
    }
    con_goto_xy(130, 51);
    cout << " \" " << what << " \" " << "�� �Ͻðڽ��ϱ�? ";
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
            if (input == 75) { //��
                if (x != 135) {
                    x = x - 15;
                }
            }
            else if (input == 77) { // ����
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
    // ���� ���� �������� ����
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
                if (input == 75) { //��
                    if (x != 80) {
                        x = x - 34;
                    }
                }
                else if (input == 77) { // ����
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
    con_out(100, 47, "img/fight_screen/Ʋ.txt");
    // ��ǻ�� ���� ��ɾ� ����
    srand(time(NULL));
    int com_act = rand() % 2 + 1;
    
    if (com_act == 1) {
        SetConsoleOutputCP(949);
        con_goto_xy(110, 50);
        cout << "���� ���� �Դϴ�!";
        con_goto_xy(110, 52);
        cout << "������ �����ϱ⸦ �����Ͽ����ϴ�!.";
    }

    //fight menu
    SetConsoleOutputCP(949);
    con_goto_xy(110, 49);
    cout << "����� ������!";
    con_goto_xy(110, 51);
    cout << "�����ϱ�!         (ġ��Ÿ�� ���� ģ�е��� ���)";
    con_goto_xy(110, 53);
    cout << "����ϱ�!         (��� ������ ���� ���� ��ŭ ����)";
    con_goto_xy(110, 55);
    cout << "���ϱ�!           (ȸ�� Ȯ���� �̵��ӵ��� ���)";
    con_goto_xy(110, 57);
    cout << "������ ����ϱ�!  (���� ������ ���)";
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
            if (input == 72) { // ��
                if (y != 51) {
                    y = y - 2;
                }
            }
            else if (input == 80) { // �Ʒ�
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
    con_out(100, 47, "img/fight_screen/Ʋ.txt");
    SetConsoleOutputCP(949);
    if (what_menu == 51) {
        what = "�����ϱ�";
    }
    else if (what_menu == 53) {
        what = "����ϱ�";
    }
    else if (what_menu == 55) {
        what = "���ϱ�";
    }
    else if (what_menu == 57) {
        what = "������ ����ϱ�";
    }
    con_goto_xy(130, 51);
    cout << " \" " << what << " \" " << "�� �Ͻðڽ��ϱ�? ";
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
            if (input == 75) { //��
                if (x != 135) {
                    x = x - 15;
                }
            }
            else if (input == 77) { // ����
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

void CursorView(bool show)//Ŀ�� ������
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
