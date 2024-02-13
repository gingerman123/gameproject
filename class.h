#pragma once


#include "monster.h"



class player {
    // 최대 몬스터 포획 가능 수 = 6 , 시작시 itemm, money = 0
    // 
    // 스토리 모드를 대비하여 마지막 위치를 저장하는 location 변수 고려
public:
    player() {}
    ~player() {}

    player(string name) {
        _username = name;
        _money = 0;
    }

    virtual void get() {};

    void _set_username(string in) {
        this->_username = in;
    }
    string _get_username() {
        return _username;
    }

    void _set_mon_list(int i, Monster* who) {   //1열 몬스터 속성 / 2열 몬스터 레벨 / 몬스터 최대 hp
        this->_monster[i] = who;
    }
    Monster* _get_mon_list(int i) const {
        return _monster[i];
    }

    bool is_monster_info_available(int i) const {
        return (_monster[i] != nullptr);
    }


    void item_info() {
        for (int i = 0; i < 4; i++) {
            con_goto_xy(115, 51 + (i * 2));
            cout << "좋은 " << _item[0][i] << " : " << _item_val[0][i] << " 개";
            con_goto_xy(155, 51 + (i * 2));
            cout << "굉장한 " << _item[0][i] << " : " << _item_val[1][i] << " 개";
        }
    }

    void item_get(string name) {
        string grade = name.substr(0, 4); // 앞 두글자 (좋은,굉장)
        int num = name.find(" ");
        string item_type = name.substr(num + 1, 4); //(체력,공격,스피,방어)
        int count = 0;      //회복하면 나가게 하는 함수
        for (int i = 0; i < 4; i++) {
            if (item_type == _item[1][i]) { //Hp,공격,스피드,방어 중 어떤 아이템?
                if (grade == "좋은") {    //grade 따라 다르게
                    _item_val[0][i]++;
                    count++;
                }
                else if (grade == "굉장") {
                    _item_val[1][i]++;
                    count++;
                }
            }
            if (count > 0) {
                break;
            }
        }
        if (item_type == "몬스") {
            if (grade == "좋은") {
                _item_val[0][4]++;
            }
            else if (grade == "굉장") {
                _item_val[1][4]++;
            }
        }
    }

    void item_use(Monster* what, string name) {
        string grade = name.substr(0, 4); // 앞 두글자 (좋은,굉장)
        string item_type = name.substr(name.find(" ") + 1, 4); //(체력,공격,스피,방어,몬스)
        int count = 0;      //회복하면 나가게 하는 함수
        for (int i = 0; i < 4; i++) {
            if (item_type == _item[1][i]) { //체력,공격,스피드,방어 중 어떤 아이템?
                if (_item_val[0][i] > 0 || _item_val[1][i] > 0) {  //소지한 아이템 개수가 0이상이면
                    if (grade == "좋은") {    //grade 따라 다르게 회복
                        *what->stat[i] += _item_val[2][i]; //stat : 체력,공격력,스피드,방어력
                        _item_val[0][i]--;
                    }
                    else if (grade == "굉장") {
                        *what->stat[i] += _item_val[3][i];
                        _item_val[1][i]--;
                    }
                    if (what->_Hp > what->_maxHp) {
                        what->_Hp = what->_maxHp;
                    }
                    count++;
                }
                if (count > 0) {
                    break;
                }
            }
        }
    }

    void item_use_dec(Monster* what, string name) {
        string grade = name.substr(0, 4); // 앞 두글자 (좋은,굉장)
        string item_type = name.substr(name.find(" ") + 1, 4); //(체력,공격,스피,방어,몬스)
        for (int i = 0; i < 4; i++) {
            if (item_type == _item[1][i]) { //체력,공격,스피드,방어 중 어떤 아이템?
                if (_item_val[0][i] > 0 || _item_val[1][i] > 0) {  //소지한 아이템 개수가 0이상이면
                    if (grade == "좋은") {    //grade 따라 다르게 회복
                        *what->stat[i] -= _item_val[2][i]; //stat : 체력,공격력,스피드,방어력
                        break;
                    }
                    else if (grade == "굉장") {
                        *what->stat[i] -= _item_val[3][i];
                        break;
                    }
                }
            }
        }
    }

protected:
    string _username;
    Monster* _monster[6] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
public:
    string _item[3][5] = {
    { "체력 회복 포션", "공격력 업 포션", "스피드 업 포션", "방어력 업 포션", "몬스터볼"},
    {"체력","공격","스피", "방어", "몬스터볼"}, // 어떤 아이템인지
    {"포션","포션","포션","포션","몬스터볼"} //아이템 타입
    };
    int _item_val[5][6] = {
    {1,1,1,2,0},				//좋은 등급 아이템 개수
    {1,1,1,1,0},                //굉장한 등급 아이템 개수
    {10,2,2,2,10},			//좋은 ~~~ : 포션-> 회복량/ 몬스터 볼-> 잡을 확률; 
    {20,4,4,4,20},          //굉장한 ~~~ : 포션-> 회복량/ 몬스터 볼-> 잡을 확률;
    {250,100,100,100,300},		 //가격 (굉장한 쓸때는 *2로 계산하면 될듯합니다.
    };

    int _money = 0;

};






class item : public player {
    void get() {
        cout << "아이템을 얻었습니다.";
    }

};

class money : public player {
    void get() {
        cout << "돈을 얻었습니다.";
    }

};








// 자식 클래스 진입용

void get_what_player(player* what) {
    what->get();
}

/*void get_what_monster(Monster* what) {
    what->get();
}



void what_mon_type(Monster* what) {
    what->set_mon_type();
}*/


string show_mon_val(player& who, int mon_num, string what) {
    string value;
    Monster* mon_value = who._get_mon_list(mon_num);
    value = mon_value->get_mon_val(what);
    return value;
}