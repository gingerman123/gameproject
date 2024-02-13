#pragma once

#include <iostream>
#include <random>

using namespace std;

random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(-3, 3);


string mon_type[2][9] = {
    { "파이리","꼬부기","이상해씨","고라파덕","고우스트","리자몽","모래두지","이브이","캐터피"},
    { "불","물","풀","물","악","불","땅","노말","벌레" }
};

int basic_stat[5][9] = {        //기본 스탯 // 파이리,꼬부기,이상해씨,고라파덕,고우스트,리자몽,모래두지,이브이,캐터피 순
    {10,10,12,8,12,25,9,10,3},                                   //attack
    {10,10,6,10,15,20,10,10,5},                                  //speed
    {8,8,8,5,5,20,10,10,5},                                      //armor
    {22,30,25,35,25,35,25,25,15},                                //maxHp
    {10,10,10,10,15,25,7,12,6},                                  //aqExp
};

int increase_stat[5][9] = {     //레벨 당 증가 스탯 // 파이리,꼬부기,이상해씨,고라파덕,고우스트,리자몽,모래두지,이브이,캐터피 순
    {11,8,8,6,10,6,8,5,5},          //attack
    {10,10,11,10,10,8,10,5,3},      //speed
    {5,7,5,5,5,5,8,5,3},            //armor
    {9,8,9,12,6,8,8,10,10},         //maxHp
    {5,5,5,6,6,7,6,10,6}            //aqExp
};


class Monster { //몬스터 (추상)클래스 attack()은 자식 클래스로 내려가서 재정의할 예정
public:
    Monster() {}
    Monster(string name, int level) {
        int count = 0;
        _name = name;
        _level = level;
        _Exp = 0;
        _maxExp = 30;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 5; j++) {
                if (_name == mon_type[0][i]) {
                    _type = mon_type[1][i];
                    *field[j] = basic_stat[j][i];
                    count++;
                }
            }
            if (count == 5) {
                break;
            }
        }
        _Hp = _maxHp;
    }
    ~Monster() {}

public:
    int* field[5] = { &_attack,&_speed,&_armor,&_maxHp,&_aqExp }; //1레벨 스텟 초기화용
    int* stat[4] = { &_Hp,&_attack,&_speed,&_armor };
    string _name;
    string _type;
    string _sec_name;
    int _level;
    int _attack;
    int _speed;
    int _armor;
    int _maxHp;
    int _Hp;
    int _maxExp;
    int _Exp; //내 경험치
    int _aqExp; //전투가 끝나고 줄 경험치
public:
    virtual void attack() {};

    void level_up() { //레벨 업 시 각종 스탯 상승
        int count = 0;
        _level++;
        _maxExp += 15;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 5; j++) {
                if (_name == mon_type[0][i]) {
                    auto randNum = dist(mt);
                    *field[j] += increase_stat[j][i] + randNum;
                    count++;
                }
            }
            if (count == 5) {
                break;
            }
        }
    }

    string get_mon_val(string what) {
        string value;
        if (what == "name") {
            value = this->_name;
        }
        else if (what == "sec_name") {
            value = (this->_sec_name);
        }
        else if (what == "level") {
            value = to_string(this->_level);
        }
        else if (what == "attack") {
            value = to_string(this->_attack);
        }
        else if (what == "speed") {
            value = to_string(this->_speed);
        }
        else if (what == "armor") {
            value = to_string(this->_armor);
        }
        else if (what == "maxHp") {
            value = to_string(this->_maxHp);
        }
        else if (what == "Hp") {
            value = to_string(this->_Hp);
        }
        else if (what == "maxExp") {
            value = to_string(this->_maxExp);
        }
        else if (what == "Exp") {
            value = to_string(this->_Exp);
        }
        else if (what == "aqExp") {
            value = to_string(this->_aqExp);
        }
        return value;
    }
    
    void set_mon_val(string what, int value) {
        if (what == "level") {
            this->_level = value;
        }
        else if (what == "attack") {
            this->_attack = value;
        }
        else if (what == "speed") {
            this->_speed = value;
        }
        else if (what == "armor") {
            this->_armor = value;
        }
        else if (what == "maxHp") {
            this->_maxHp = value;
        }
        else if (what == "Hp") {
            this->_Hp = value;
        }
        else if (what == "maxExp") {
            this->_maxExp = value;
        }
        else if (what == "Exp") {
            this->_Exp = value;
        }
        else if (what == "aqExp") {
            this->_aqExp = value;
        }
    }
};


void set_stat(Monster* monster) {       // 생성과 동시에 레벨에 맞는 스탯 적용
    if (monster->_name == "파이리") {
        monster->_type = "불";
        monster->_attack = 10 + 11 * (monster->_level - 1);
        monster->_speed = 10 * (monster->_level);
        monster->_armor = 8 + 5 * (monster->_level - 1);
        monster->_maxHp = 22 + 9 * (monster->_level - 1);
        monster->_maxExp = 30 + 15 * (monster->_level - 1);
        monster->_Exp = 0;
        monster->_aqExp = 10 + 5 * (monster->_level - 1);

        int* attribute[5] = { &monster->_attack,&monster->_speed,&monster->_armor,&monster->_aqExp,&monster->_maxHp };
        for (int j = 0; j < monster->_level - 1; j++) {
            for (auto i : attribute) {
                auto randNum = dist(mt);
                *i += randNum;
            }
        }
        monster->_Hp = monster->_maxHp;

    }
    else if (monster->_name == "꼬부기") {
        monster->_type = "물";
        monster->_attack = 20 + 8 * (monster->_level - 1);
        monster->_speed = 10 * (monster->_level);
        monster->_armor = 8 + 7 * (monster->_level - 1);
        monster->_maxHp = 30 + 8 * (monster->_level - 1);
        monster->_maxExp = 30 + 15 * (monster->_level - 1);
        monster->_Exp = 0;
        monster->_aqExp = 10 + 5 * (monster->_level - 1);

        int* attribute[5] = { &monster->_attack,&monster->_speed,&monster->_armor,&monster->_aqExp,&monster->_maxHp };
        for (int j = 0; j < monster->_level - 1; j++) {
            for (auto i : attribute) {
                auto randNum = dist(mt);
                *i += randNum;
            }
        }
        monster->_Hp = monster->_maxHp;
    }
    else if (monster->_name == "이상해씨") {
        monster->_type = "풀";
        monster->_attack = 12 + 8 * (monster->_level - 1);
        monster->_speed = 6 + 11 * (monster->_level - 1);
        monster->_armor = 8 + 5 * (monster->_level - 1);
        monster->_maxHp = 25 + 9 * (monster->_level - 1);
        monster->_maxExp = 30 + 15 * (monster->_level - 1);
        monster->_Exp = 0;
        monster->_aqExp = 10 + 5 * (monster->_level - 1);

        int* attribute[5] = { &monster->_attack,&monster->_speed,&monster->_armor,&monster->_aqExp,&monster->_maxHp };
        for (int j = 0; j < monster->_level - 1; j++) {
            for (auto i : attribute) {
                auto randNum = dist(mt);
                *i += randNum;
            }
        }
        monster->_Hp = monster->_maxHp;
    }
    else if (monster->_name == "고라파덕") {
        monster->_type = "물";
        monster->_attack = 8 + 6 * (monster->_level - 1);
        monster->_speed = 10 * (monster->_level);
        monster->_armor = 5 * (monster->_level);
        monster->_maxHp = 35 + 12 * (monster->_level - 1);
        monster->_maxExp = 30 + 15 * (monster->_level - 1);
        monster->_Exp = 0;
        monster->_aqExp = 10 + 6 * (monster->_level - 1);

        int* attribute[5] = { &monster->_attack,&monster->_speed,&monster->_armor,&monster->_aqExp,&monster->_maxHp };
        for (int j = 0; j < monster->_level - 1; j++) {
            for (auto i : attribute) {
                auto randNum = dist(mt);
                *i += randNum;
            }
        }
        monster->_Hp = monster->_maxHp;

    }
    else if (monster->_name == "고우스트") {
        monster->_type = "악";
        monster->_attack = 12 + 10 * (monster->_level - 1);
        monster->_speed = 15 + 10 * (monster->_level - 1);
        monster->_armor = 5 * (monster->_level);
        monster->_maxHp = 25 + 6 * (monster->_level - 1);
        monster->_maxExp = 30 + 15 * (monster->_level - 1);
        monster->_Exp = 0;
        monster->_aqExp = 15 + 6 * (monster->_level - 1);

        int* attribute[5] = { &monster->_attack,&monster->_speed,&monster->_armor,&monster->_aqExp,&monster->_maxHp };
        for (int j = 0; j < monster->_level - 1; j++) {
            for (auto i : attribute) {
                auto randNum = dist(mt);
                *i += randNum;
            }
        }
        monster->_Hp = monster->_maxHp;
    }
    else if (monster->_name == "리자몽") {
        monster->_type = "불";
        monster->_attack = 25 + 6 * (monster->_level - 1);
        monster->_speed = 20 + 8 * (monster->_level);
        monster->_armor = 20 + 5 * (monster->_level - 1);
        monster->_maxHp = 35 + 8 * (monster->_level - 1);
        monster->_maxExp = 30 + 15 * (monster->_level - 1);
        monster->_Exp = 0;
        monster->_aqExp = 25 + 7 * (monster->_level - 1);

        int* attribute[5] = { &monster->_attack,&monster->_speed,&monster->_armor,&monster->_aqExp,&monster->_maxHp };
        for (int j = 0; j < monster->_level - 1; j++) {
            for (auto i : attribute) {
                auto randNum = dist(mt);
                *i += randNum;
            }
        }
        monster->_Hp = monster->_maxHp;
    }
    else if (monster->_name == "모래두지") {
        monster->_type = "땅";
        monster->_attack = 9 + 8 * (monster->_level - 1);
        monster->_speed = 10 * (monster->_level);
        monster->_armor = 10 + 8 * (monster->_level - 1);
        monster->_maxHp = 25 + 8 * (monster->_level - 1);
        monster->_maxExp = 30 + 15 * (monster->_level - 1);
        monster->_Exp = 0;
        monster->_aqExp = 12 + 6 * (monster->_level - 1);

        int* attribute[5] = { &monster->_attack,&monster->_speed,&monster->_armor,&monster->_aqExp,&monster->_maxHp };
        for (int j = 0; j < monster->_level - 1; j++) {
            for (auto i : attribute) {
                auto randNum = dist(mt);
                *i += randNum;
            }
        }
        monster->_Hp = monster->_maxHp;

    }
    else if (monster->_name == "이브이") {
        monster->_type = "노말";
        monster->_attack = 10 + 5 * (monster->_level - 1);
        monster->_speed = 10 + 5 * (monster->_level - 1);
        monster->_armor = 10 + 5 * (monster->_level - 1);
        monster->_maxHp = 25 + 10 * (monster->_level - 1);
        monster->_maxExp = 30 + 15 * (monster->_level - 1);
        monster->_Exp = 0;
        monster->_aqExp = 10 + 10 * (monster->_level - 1);
        int* attribute[5] = { &monster->_attack,&monster->_speed,&monster->_armor,&monster->_aqExp,&monster->_maxHp };
        for (int j = 0; j < monster->_level - 1; j++) {
            for (auto i : attribute) {
                auto randNum = dist(mt);
                *i += randNum;
            }
        }
        monster->_Hp = monster->_maxHp;
    }
    else if (monster->_name == "캐터피") {
        monster->_type = "벌레";
        monster->_attack = 3 + 5 * (monster->_level - 1);
        monster->_speed = 5 + 3 * (monster->_level - 1);
        monster->_armor = 5 + 3 * (monster->_level - 1);
        monster->_maxHp = 15 + 10 * (monster->_level - 1);
        monster->_maxExp = 30 + 15 * (monster->_level - 1);
        monster->_Exp = 0;
        monster->_aqExp = 6 * (monster->_level - 1);
        int* attribute[5] = { &monster->_attack,&monster->_speed,&monster->_armor,&monster->_aqExp,&monster->_maxHp };
        for (int j = 0; j < monster->_level - 1; j++) {
            for (auto i : attribute) {
                auto randNum = dist(mt);
                *i += randNum;
            }
        }
        monster->_Hp = monster->_maxHp;
    }
}

