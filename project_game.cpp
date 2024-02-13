// project_game.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "console_view.h"
#include "class.h"
#include <cmath>


// 수풀 속에서 랜덤 확률로 포켓몬나옴

using namespace std;



void voi_fir_sel_mon(player& p_who, string what) {
    
    string m_type_input = what;
    
    if (m_type_input == "물") {       
        Monster* m1 = new Monster("꼬부기", 1);
        set_stat(m1);
        p_who._set_mon_list(0, m1);
    }
    if (m_type_input == "불") {
        Monster* m1 = new Monster("파이리", 1);
        set_stat(m1);
        p_who._set_mon_list(0, m1);
    }
    if (m_type_input == "풀") {
        Monster* m1 = new Monster("이상해씨", 1);
        set_stat(m1);
        p_who._set_mon_list(0, m1);
    }
    
}

void com_ran_mon_set(player& who, int start_mon_level) {  // k 는 P1 레벨을 받을 수 있도록
    
    // 랜덤 몬스터 6개 추출
    srand(time(NULL));
    int mon_list[6];
    int i = 0;
    for (int i = 0; i < 6; i++) {
        int my_num = rand() % 9 + 1;
        mon_list[i] = my_num;

        for (int j = 0; j < i; j++) {
            if (my_num == mon_list[j]) {
                i--;
            }
        }
    }
    // 랜덤 몬스터 클래스 대입
    for (int i = 0; i < 6; i++) {
        string what_mon;
        //단계가 올라 갈 수록 몬스터 레벨 랜덤으로 up
        if (i > 0) {
            int ran_lev_up = rand() % 3 + 1;
            start_mon_level = start_mon_level + ran_lev_up;
        }
        if (mon_list[i] == 1) {
            what_mon = "고라파덕";
        }
        if (mon_list[i] == 2) {
            what_mon = "고우스트";
        }
        if (mon_list[i] == 3) {
            what_mon = "꼬부기";
        }
        if (mon_list[i] == 4) {
            what_mon = "리자몽";
        }
        if (mon_list[i] == 5) {
            what_mon = "모래두지";
        }
        if (mon_list[i] == 6) {
            what_mon = "이브이";
        }
        if (mon_list[i] == 7) {
            what_mon = "이상해씨";
        }
        if (mon_list[i] == 8) {
            what_mon = "캐터피";
        }
        if (mon_list[i] == 9) {
            what_mon = "파이리";
        }
        Monster* gora = new Monster(what_mon, start_mon_level); // 레벨 랜덤 함수 구현 필요
        set_stat(gora);
        who._set_mon_list(i, gora);
    }
}

void show_mon_status_window(string player_who ,player& who, int mon_num) {
    int x, y;
    if (player_who == "COM") {
        x = 104;
        y = 5;
    }
    else {
        x = 34;
        y = 54;
    }

    SetConsoleOutputCP(949);
    con_goto_xy(x, y);
    cout << show_mon_val(who, mon_num, "name");
    if (x == 34) {
        cout << "(" << show_mon_val(who, mon_num, "sec_name") << ")";
    }
    con_goto_xy(x+26, y);
    cout << "level : " << show_mon_val(who, mon_num, "level");
    con_goto_xy(x, y + 2);
    cout << "attack : " << show_mon_val(who, mon_num, "attack");
    con_goto_xy(x+14, y + 2);
    cout << "HP : " << show_mon_val(who, mon_num, "Hp");
    con_goto_xy(x + 26, y + 2);
    cout << "armor : " << show_mon_val(who, mon_num, "armor");
    //체력바 구현
    float hp = stoi(show_mon_val(who, mon_num, "Hp"));
    float max_hp = stoi(show_mon_val(who, mon_num, "maxHp"));
    float hp_gage = 16 * (hp / max_hp);
    con_goto_xy(x, y + 4);
    cout << "HP [";
    for (int i = 1; i <= 16; i++) {
        if (i <= hp_gage) {
            cout << "■";
        }
        else {
            cout << "□";
        }
    }
    cout << "]";
}

void show_mon(string player_who, player& who, int mon_num) {
    SetConsoleOutputCP(CP_UTF8);
    int x, y;
    if (player_who == "COM") {
        x = 150;
        y = 3;
    }
    else {
        x = 30;
        y = 25;
    }

    string m_name = show_mon_val(who, mon_num, "name");

    if (m_name == "고라파덕") {
        con_out(x, y, "img/mon/고라파덕.txt");
    }
    else if (m_name == "고우스트") {
        con_out(x, y, "img/mon/고우스트.txt");
    }
    else if (m_name == "꼬부기") {
        con_out(x, y, "img/mon/꼬부기.txt");
    }
    else if (m_name == "리자몽") {
        con_out(x, y, "img/mon/리자몽.txt");
    }
    else if (m_name == "모래두지") {
        con_out(x, y, "img/mon/모래두지.txt");
    }
    else if (m_name == "이브이") {
        con_out(x, y, "img/mon/이브이.txt");
    }
    else if (m_name == "이상해씨") {
        con_out(x, y, "img/mon/이상해씨.txt");
    }
    else if (m_name == "캐터피") {
        con_out(x, y, "img/mon/캐터피.txt");
    }
    else if (m_name == "파이리") {
        con_out(x, y, "img/mon/파이리.txt");
    }

}

bool did_player_avoid(player& who, int mon_num) {
    Monster* mon_def_value = who._get_mon_list(mon_num);
    int speed = mon_def_value->_speed;
    double probability = speed * 60 / 10000; // 스피드에 따라 확률 계산

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1); // 0에서 1 사이의 균일 분포를 사용

    // 스피드에 따른 확률로 실행되는 코드
    if (dis(gen) <= probability) {  // 피하다
        return true;
    }
    else {  //그냥 맞기
        return false;
    }
}

void att_deff_from_to(player& who_from, int mon_num_from, player& who_to, int mon_num_to) {
    Monster* ac_value_from = who_from._get_mon_list(mon_num_from);
    int at_val = ac_value_from->_attack;
    Monster* ac_value_to = who_to._get_mon_list(mon_num_to);
    int set_val = ac_value_to->_Hp;
    int def_val = ac_value_to->_armor;
    if (def_val >= at_val) {}    // 상대 방어력이 더 크다면 hp에 지장을 주지 않는다.
    else {
        ac_value_to->set_mon_val("Hp", set_val + def_val - at_val);
    }
}

void self_cure(player&who, int mon_num) {
    Monster* hp_value_from = who._get_mon_list(mon_num);
    int hp_val = hp_value_from->_Hp;
    hp_val = hp_val + 5;    // 자연 회복일 경우 5만큼 체력 회복
    if (hp_value_from->_maxHp <= hp_val) {      // Max hp를 넘어서 회복 못함;
        hp_value_from->set_mon_val("Hp", hp_value_from->_maxHp);
    }
    else {
        hp_value_from->set_mon_val("Hp", hp_val);
    }
}

void player_mon_hp_reset(player&who) {
    for (int i = 0; i <= 6; i++) {
        if (who.is_monster_info_available(i)) {
            Monster* hp_value_from = who._get_mon_list(i);
            hp_value_from->set_mon_val("Hp", hp_value_from->_maxHp);
        }
    }  
}

void stage_info(player& who,int stage_num) {
    //대진표 출력 코드
    system("cls");
    con_init();
    con_out(74, 15, "img/fight_screen/stageinfo.txt");
    con_out(30, 25, "img/fight_screen/틀_stageinfo.txt");
    con_out(60, 25, "img/fight_screen/틀_stageinfo.txt");
    con_out(90, 25, "img/fight_screen/틀_stageinfo.txt");
    con_out(120, 25, "img/fight_screen/틀_stageinfo.txt");
    con_out(150, 25, "img/fight_screen/틀_stageinfo.txt");
    con_out(180, 25, "img/fight_screen/틀_stageinfo.txt");

    //화살표
    if (stage_num == 0) {
        con_out(38, 35, "img/fight_screen/upa.txt");
    }
    else if (stage_num == 1) {
        con_out(68, 35, "img/fight_screen/upa.txt");
    }
    else if (stage_num == 2) {
        con_out(98, 35, "img/fight_screen/upa.txt");
    }
    else if (stage_num == 3) {
        con_out(128, 35, "img/fight_screen/upa.txt");
    }
    else if (stage_num == 4) {
        con_out(158, 35, "img/fight_screen/upa.txt");
    }
    else {
        con_out(188, 35, "img/fight_screen/upa.txt");
    }

    

    SetConsoleOutputCP(949);
    con_goto_xy(40, 27);
    cout << "STAGE 1";
    con_goto_xy(70, 27);
    cout << "STAGE 2";
    con_goto_xy(100, 27);
    cout << "STAGE 3";
    con_goto_xy(130, 27);
    cout << "STAGE 4";
    con_goto_xy(160, 27);
    cout << "STAGE 5";
    con_goto_xy(190, 27);
    cout << "STAGE 6";

    int x[] = { 40,70,100,130,160,190 };

    for (int i = 0; i < 6; i++) {
        string com_m_name = show_mon_val(who, i, "name");
        string com_m_level = show_mon_val(who, i, "level");
        con_goto_xy(x[i], 29);
        cout << com_m_name;
        con_goto_xy(x[i] - 1, 31);
        cout << "LEVEL : " << com_m_level;
    }

    // 화살표로 현재 스테이지에 위치 표시 구현 예정




    Sleep(4000);

}

void show_item_list(player& who) {
    SetConsoleOutputCP(CP_UTF8);
    con_out(100, 47, "img/fight_screen/틀.txt");
    SetConsoleOutputCP(949);
    con_goto_xy(140, 49);
    cout << "아이템 보유 현황";
    con_goto_xy(175, 49);
    cout << "돌아가기";
    who.item_info();
    con_goto_xy(110, 51);
    cout << "->";
}

void sel_item_menu(int* out_x, int* out_y) {
    int input;
    int x, y;
    string what_x;
    string what_y;
    x = 110;
    y = 51;
    while (true) {
        input = _getch();

        if (input == 13) {
            *out_x = x;
            *out_y = y;
            break;
        }
        else if (input == 224) {
            input = _getch();
            con_goto_xy(x, y);
            cout << "  ";
            if (input == 72) { // 위
                if (y != 49) {
                    y = y - 2;
                    if (y == 49) {
                        x = 170;
                    }
                }
            }
            else if (input == 80) { // 아래
                if (y != 57) {
                    if (y == 49) {
                        x = 150;
                    }
                    y = y + 2;
                }
            }
            else if (input == 75) { // 왼
                if ( x != 110 ) {
                    if (y != 49) {
                        x = x - 40;
                    }
                }
            }
            else if (input == 77) { // 오
                if (x != 150) {
                    if (y != 49) {
                        x = x + 40;
                    }
                }
            }
            con_goto_xy(x, y);
            cout << "->";
        }
    }
}

void check_select_item(player& who, bool* no,int x, int y) {
    string what_x, what_y;
    int input;

    if (x == 110) {
        what_x = "좋은";
    }
    else {
        what_x = "굉장한";
    }

    if (y == 51) {
        what_y = "체력 회복 포션";
    }
    else if (y == 53) {
        what_y = "공격력 업 포션";
    }
    else if (y == 55) {
        what_y = "스피드 업 포션";
    }
    else {
        what_y = "방어력 업 포션";
    }

    SetConsoleOutputCP(CP_UTF8);
    con_out(100, 47, "img/fight_screen/틀.txt");
    SetConsoleOutputCP(949);
    con_goto_xy(130, 51);
    cout << what_x << " " << what_y << "을 사용하시겠습니까?";
    con_goto_xy(140, 54);
    cout << "YES";
    con_goto_xy(155, 54);
    cout << "NO";
    con_goto_xy(135, 54);
    cout << "->";


    int x_ys = 135;    // x
    while (true) {
        input = _getch();

        if (input == 13) {
            break;
        }
        else if (input == 224) {
            input = _getch();
            con_goto_xy(x_ys, 54);
            cout << "  ";
            if (input == 75) { //왼
                if (x_ys != 135) {
                    x_ys = x_ys - 15;
                }
            }
            else if (input == 77) { // 오른
                if (x_ys != 150) {
                    x_ys = x_ys + 15;
                }
            }
            con_goto_xy(x_ys, 54);
            cout << "->";
        }
    }
    if (x_ys == 135) {         // yes 선택
        int item_num_x, item_num_y;
        if (x == 110) {
            item_num_x = 0;
        }
        else {
            item_num_x = 1;
        }

        if (y == 51) {
            item_num_y = 0;
        }
        else if (y == 53) {
            item_num_y = 1;
        }
        else if (y == 55) {
            item_num_y = 2;
        }
        else {
            item_num_y = 3;
        }

        if (who._item_val[item_num_x][item_num_y] == 0) {   //아이템 개수가 0이면
            SetConsoleOutputCP(CP_UTF8);
            con_out(100, 47, "img/fight_screen/틀.txt");
            SetConsoleOutputCP(949);
            con_goto_xy(130, 51);
            cout << "아이템을 현재 보유하고 있지 않습니다!.";
            con_goto_xy(130, 54);
            cout << "전투 종료 후 상점에서 구매하세요!";
            Sleep(4000);
        }
        else {
            SetConsoleOutputCP(CP_UTF8);
            con_out(100, 47, "img/fight_screen/틀.txt");
            SetConsoleOutputCP(949);
            con_goto_xy(130, 51);
            cout << what_x << " " << what_y << "을 사용합니다!";
            int item_num = who._item_val[item_num_x][item_num_y] - 1;
            con_goto_xy(130, 54);
            cout << "사용 이후 " << what_x << " " << what_y << " 보유량 = " << item_num;
            Sleep(2000);
            *no = false;
        }
    }
}

void select_what_item(int x, int y, string* what_item) {
    if (x == 110) {
        if (y == 51) {
            *what_item = "좋은 체력";
        }
        else if (y == 53) {
            *what_item = "좋은 공격";
        }
        else if (y == 55) {
            *what_item = "좋은 스피";
        }
        else {
            *what_item = "좋은 방어";
        }
    }
    else {
        if (y == 51) {
            *what_item = "굉장 체력";
        }
        else if (y == 53) {
            *what_item = "굉장 공격";
        }
        else if (y == 55) {
            *what_item = "굉장 스피";
        }
        else {
            *what_item = "굉장 방어";
        }
    }
}

void check_winner(player& who_to, int mon_num_to, player& who_from, int mon_num_from, bool* fight_ing, bool* game_over) {
    //게임 종료 함수
    Monster* com_hp = who_to._get_mon_list(mon_num_to);
    Monster* p1_hp = who_from._get_mon_list(mon_num_from);
    int com_hp_zero = com_hp->_Hp;
    int p1_hp_zero = p1_hp->_Hp;
    if (p1_hp_zero <= 0) {
        system("cls");
        con_init();
        con_out(80, 20, "img/fight_screen/comwin.txt");
        Sleep(4000);
        *fight_ing = false;
        *game_over = true;
    }
    else if (com_hp_zero <= 0) {
        system("cls");
        con_init();
        con_out(80, 20, "img/fight_screen/youwin.txt");
        Sleep(4000);
        *fight_ing = false;
    }
}

void store_view(player* p1) { //돈이랑 아이템 접근해야돼서 pointer로 매개변수 받습니다.
    while (1) {
        system("cls");
        SetConsoleOutputCP(949);
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 표준 출력 핸들 가져오기
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(consoleHandle, &cursorInfo); // 현재 커서 정보 가져오기
        cursorInfo.bVisible = FALSE; // 커서를 보이지 않게 설정
        SetConsoleCursorInfo(consoleHandle, &cursorInfo);

        con_out(80, 15, "img/상점_틀.txt");
        con_goto_xy(83, 31);
        cout << "현재 보유금 : " << p1->_money;
        con_goto_xy(97, 16);
        cout << "< 상 점 >";
        int j = 18;
        con_goto_xy(120, 17);
        cout << "가 격";

        for (int i = 0; i < 5; i++) {
            string x = p1->_item[0][i];
            int y = p1->_item_val[4][i];
            con_goto_xy(83, j);
            cout << "좋은 " << x << endl;
            con_goto_xy(120, j);
            cout << y << "원";
            j++;
            con_goto_xy(83, j);
            cout << "굉장한 " << x << endl;
            con_goto_xy(120, j);
            cout << y * 2 << "원";
            j++;
        }

        int selected = 18;
        con_goto_xy(81, 18);
        cout << "->";
        con_goto_xy(81, 18);
        bool select = true;
        while (select) {
            char key = _getch();
            switch (key) {
            case 72: // 위쪽 화살표
                if (selected > 18)
                    selected--;
                con_goto_xy(81, selected);
                cout << "->";
                if (selected < 28)
                    con_goto_xy(81, selected + 1);
                cout << "  ";
                break;
            case 80: // 아래쪽 화살표
                if (selected < 27)
                    selected++;
                con_goto_xy(81, selected);
                cout << "->";
                if (selected > 18)
                    con_goto_xy(81, selected - 1);
                cout << "  ";
                break;
            case 13: // Enter 키
                con_goto_xy(120, 29);
                int num;
                cout << "수량을 입력하세요 : ";
                cin >> num;
                int price_arr[10] = { 250,500,100,200,100,200,100,200,300,600 };
                int index = selected - 3;
                int price = num * price_arr[index];
                if (p1->_money > price - 1) {
                    p1->_money -= price;
                    con_goto_xy(120, 30);
                    cout << "남은 돈 : " << p1->_money << "원";
                    int index = selected - 3;
                    p1->_item_val[index % 2][index / 2] += num;
                    con_goto_xy(120, 31);
                    if (index % 2 == 0) {
                        cout << "좋은 " << p1->_item[0][index / 2] << "의 개수 : " << p1->_item_val[index % 2][index / 2];
                    }
                    else {
                        cout << "굉장한 " << p1->_item[0][index / 2] << "의 개수 : " << p1->_item_val[index % 2][index / 2];
                    }
                }
                else {
                    con_goto_xy(120, 30);
                    cout << "돈이 부족합니다!!";
                }
                select = false;
                break;
            }


        }
        con_goto_xy(120, 32);
        string exit;
        cout << "계속 : Y/종료 : 아무거나";
        con_goto_xy(120, 33);
        cin >> exit;
        if (exit == "Y" || exit == "y") {
            continue;
        }
        else {
            break;
        }
    }




}

void win_stage(player* player, Monster* monster1, Monster* monster2) { //1이 아군 2가 적 몬스터
    system("cls");
    con_init();
    con_out(80, 20, "img/fight_screen/youwin.txt");
    con_out(95, 35, "img/fight_screen/틀_s.txt");
    int i = 0;
    while (i < 2) {
        monster1->level_up();
        i++;
    }
    int win_money = monster2->_level;
    player->_money += 200 * win_money;
    
    SetConsoleOutputCP(949);
    con_goto_xy(105, 37);
    cout << "PLAYER MONSTER LEVEL + 2";
    con_goto_xy(105, 39);
    cout << "CURRENT MONSTER LEVEL : " << monster1->_level;
    con_goto_xy(105, 41);
    cout << "GOLD +  " << 200 * win_money;

    Sleep(1500);
}

int main()
{
    string what_next;
    string user_name;
    string mon_name;
    bool tot_game_over = true;
    bool game_over = false;
    player P1, COM;
    
    while (tot_game_over) {
        what_next = con_first_view();

        if (what_next == "start") {
            while (true) {
                what_next = con_start_view();

                if (what_next == "story mode") {
                    what_next = con_storymode_view();
                    if (what_next == "return") {
                        what_next = "take a break";
                    }
                }
                if (what_next == "fight mode") {                //fight mode 진입
                    user_name = con_name_set_view();            //이름 설정화면 출력
                    P1._set_username(user_name);                //P1 에 사용자 이름 저장
                    what_next = con_first_monster_view();       //  첫몬스터 선택화면 출력
                    mon_name = con_sel_mon_view(what_next);     // 처음 선택한 몬스터 con 출력       + 별명 입력[미구현]
                    voi_fir_sel_mon(P1, what_next);             // P1 처음 선택한 몬스터 저장
                    //************************** fight mode void

    //fight screen
                    voi_fir_sel_mon(P1, "물");
                    com_ran_mon_set(COM, 1);

                    for (int i = 0; i < 6; i++) {   // i적용
                        if (game_over) {
                            break;
                        }
                        //대진표
                        stage_info(COM, i);

                        //가위바위보
                        bool who_first_you = con_rsp_did_i_win();

                        system("cls");
                        con_init();
                        show_mon("player", P1, 0);
                        show_mon("COM", COM, i);
                        con_out(30, 52, "img/fight_screen/틀_s.txt");     //내 몬스터 status 창
                        con_out(100, 3, "img/fight_screen/틀_s.txt");     //상대 몬스터 status 창
                        show_mon_status_window("player", P1, 0);
                        show_mon_status_window("COM", COM, i);      //여기까지

                        // 전투 while 문 시작
                        bool fight_ing = true;
                        bool did_used_item = false;
                        string last_item;
                        while (fight_ing) {
                            if (who_first_you == true) {    //공격하기 / 회복하기 / 아이템 사용
                                SetConsoleOutputCP(CP_UTF8);
                                con_out(5, 2, "img/fight_screen/turnyou.txt");
                                bool go_back = true;
                                bool item_use_turn_over = true;
                                while (go_back) {
                                    go_back = false;
                                    // fight menu 출력 + 선택 확인
                                    int y;
                                    while (true) {
                                        show_fight_menu_you();
                                        y = sel_fight_menu_you();
                                        bool t_f = check_sel_fight_menu_you(y);
                                        if (t_f == true) {
                                            break;
                                        }
                                    }

                                    SetConsoleOutputCP(CP_UTF8);
                                    con_out(100, 47, "img/fight_screen/틀.txt");

                                    // 나의 턴이 아닐 때 회피를 못하면 방어
                                    // 상대 몬스터의 피하기 = true / 방어 = false


                                    SetConsoleOutputCP(949);
                                    if (y == 51) {
                                        con_goto_xy(110, 50);
                                        cout << "공격하기를 선택하였습니다!";
                                        bool p_avoid = did_player_avoid(COM, i);
                                        if (p_avoid == true) {
                                            Sleep(1000);
                                            con_goto_xy(110, 52);
                                            cout << "상대 몬스터가 피하였습니다!        (몬스터 speed에 비례하여 발동)";
                                        }
                                        else {
                                            Sleep(1000);
                                            con_goto_xy(110, 52);
                                            cout << "상대 몬스터가 피하지 못하였습니다!        (몬스터 speed에 비례하여 발동)";
                                            att_deff_from_to(P1, 0, COM, i);
                                        }
                                    }
                                    else if (y == 53) {
                                        con_goto_xy(110, 50);
                                        cout << "치유하기를 선택하였습니다!";
                                        Sleep(1000);
                                        con_goto_xy(110, 52);
                                        cout << "자연 회복을 합니다!        [ HP + 5 ]";
                                        self_cure(P1, 0);
                                    }
                                    else {      // 아이템 사용하기
                                        if (did_used_item) {    // 이전 턴에 사용했던 아이템 무효
                                            SetConsoleOutputCP(CP_UTF8);
                                            con_out(100, 47, "img/fight_screen/틀.txt");
                                            SetConsoleOutputCP(949);
                                            con_goto_xy(110, 50);
                                            cout << "이전 턴 아이템 사용을 무효 합니다!";
                                            P1.item_use_dec(P1._get_mon_list(0), last_item);
                                            did_used_item = false;
                                            Sleep(3000);
                                        }
                                        SetConsoleOutputCP(CP_UTF8);
                                        con_out(30, 52, "img/fight_screen/틀_s.txt");     //내 몬스터 status 창
                                        con_out(100, 3, "img/fight_screen/틀_s.txt");     //상대 몬스터 status 창
                                        show_mon_status_window("player", P1, 0);
                                        show_mon_status_window("COM", COM, i);
                                        bool item_sel_no = true;
                                        int x, y;
                                        string what_item;
                                        while (item_sel_no) {
                                            show_item_list(P1);
                                            sel_item_menu(&x, &y);
                                            if (y == 49) {      //돌아가기 선택
                                                go_back = true;
                                                break;
                                            }
                                            else {
                                                check_select_item(P1, &item_sel_no, x, y);
                                                select_what_item(x, y, &what_item);
                                            }
                                        }
                                        if (item_sel_no == false) {
                                            P1.item_use(P1._get_mon_list(0), what_item);
                                            if (y != 51) {  //  체력회복 옵션은 계속 값 적용
                                                did_used_item = true;
                                                last_item = what_item;
                                                item_use_turn_over = false;
                                            }
                                        }
                                    }
                                    if (item_use_turn_over) {
                                        if (did_used_item) {    // 이전 턴에 사용했던 아이템 무효
                                            Sleep(1500);
                                            SetConsoleOutputCP(CP_UTF8);
                                            con_out(100, 47, "img/fight_screen/틀.txt");
                                            SetConsoleOutputCP(949);
                                            con_goto_xy(110, 50);
                                            cout << "이전 턴 아이템 사용을 무효 합니다!";
                                            P1.item_use_dec(P1._get_mon_list(0), last_item);
                                            did_used_item = false;
                                            Sleep(3000);
                                        }
                                    }
                                }
                                who_first_you = false;
                                Sleep(1500);
                            }
                            else {
                                SetConsoleOutputCP(CP_UTF8);
                                con_out(5, 2, "img/fight_screen/turncom.txt");

                                SetConsoleOutputCP(CP_UTF8);
                                con_out(100, 47, "img/fight_screen/틀.txt");
                                SetConsoleOutputCP(949);
                                con_goto_xy(110, 50);
                                cout << "상대방 차례 입니다!";
                                Sleep(3000);
                                // 컴퓨터 랜덤 명령어 생성
                                srand(time(NULL));
                                int com_act = rand() % 2 + 1;

                                // 체력이 full인 경우 무조건 공격하기 선택
                                Monster* hp_value_from = COM._get_mon_list(i);
                                if (hp_value_from->_Hp == hp_value_from->_maxHp) {
                                    com_act = 1;
                                }

                                // 선택 명령어 실행
                                if (com_act == 1) {
                                    con_goto_xy(110, 52);
                                    cout << "상대방이 공격하기를 선택하였습니다!.";
                                    bool p_avoid = did_player_avoid(P1, 0);
                                    if (p_avoid == true) {
                                        Sleep(1000);
                                        con_goto_xy(110, 54);
                                        cout << "상대 몬스터의 공격을 피하였습니다!        (몬스터 speed에 비례하여 발동)";
                                    }
                                    else {
                                        Sleep(1000);
                                        con_goto_xy(110, 54);
                                        cout << "상대 몬스터의 공격을 피하지 못하였습니다!        (몬스터 speed에 비례하여 발동)";
                                        att_deff_from_to(COM, 0, P1, 0);
                                    }
                                }
                                else {
                                    con_goto_xy(110, 52);
                                    cout << "치유하기를 선택하였습니다!";
                                    Sleep(1000);
                                    con_goto_xy(110, 54);
                                    cout << "자연 회복을 합니다!        [ HP + 5 ]";
                                    self_cure(COM, i);
                                }
                                who_first_you = true;
                                Sleep(1500);
                            }
                            SetConsoleOutputCP(CP_UTF8);
                            con_out(30, 52, "img/fight_screen/틀_s.txt");     //내 몬스터 status 창
                            con_out(100, 3, "img/fight_screen/틀_s.txt");     //상대 몬스터 status 창
                            show_mon_status_window("player", P1, 0);
                            show_mon_status_window("COM", COM, i);
                            Sleep(1500);
                            check_winner(COM, i, P1, 0, &fight_ing, &game_over);    // 승자 화면 출력 및 라운드 종료
                        }
                        if (!game_over) {

                            win_stage(&P1, P1._get_mon_list(0), COM._get_mon_list(i));
                            player_mon_hp_reset(P1); // 전투 종료 후 player monster hp 초기화
                            store_view(&P1);
                        }
                    }

                    
                    cin >> what_next;
                                       
                    
                }
                if (what_next == "return") {
                    break;
                }
            }
        }
        else if (what_next == "credit") {
            //what_next = con_start_view();
        }
        else if (what_next == "exit") {
            game_over = false;
        }
   }


    
    

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
