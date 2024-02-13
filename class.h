#pragma once


#include "monster.h"



class player {
    // �ִ� ���� ��ȹ ���� �� = 6 , ���۽� itemm, money = 0
    // 
    // ���丮 ��带 ����Ͽ� ������ ��ġ�� �����ϴ� location ���� ���
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

    void _set_mon_list(int i, Monster* who) {   //1�� ���� �Ӽ� / 2�� ���� ���� / ���� �ִ� hp
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
            cout << "���� " << _item[0][i] << " : " << _item_val[0][i] << " ��";
            con_goto_xy(155, 51 + (i * 2));
            cout << "������ " << _item[0][i] << " : " << _item_val[1][i] << " ��";
        }
    }

    void item_get(string name) {
        string grade = name.substr(0, 4); // �� �α��� (����,����)
        int num = name.find(" ");
        string item_type = name.substr(num + 1, 4); //(ü��,����,����,���)
        int count = 0;      //ȸ���ϸ� ������ �ϴ� �Լ�
        for (int i = 0; i < 4; i++) {
            if (item_type == _item[1][i]) { //Hp,����,���ǵ�,��� �� � ������?
                if (grade == "����") {    //grade ���� �ٸ���
                    _item_val[0][i]++;
                    count++;
                }
                else if (grade == "����") {
                    _item_val[1][i]++;
                    count++;
                }
            }
            if (count > 0) {
                break;
            }
        }
        if (item_type == "��") {
            if (grade == "����") {
                _item_val[0][4]++;
            }
            else if (grade == "����") {
                _item_val[1][4]++;
            }
        }
    }

    void item_use(Monster* what, string name) {
        string grade = name.substr(0, 4); // �� �α��� (����,����)
        string item_type = name.substr(name.find(" ") + 1, 4); //(ü��,����,����,���,��)
        int count = 0;      //ȸ���ϸ� ������ �ϴ� �Լ�
        for (int i = 0; i < 4; i++) {
            if (item_type == _item[1][i]) { //ü��,����,���ǵ�,��� �� � ������?
                if (_item_val[0][i] > 0 || _item_val[1][i] > 0) {  //������ ������ ������ 0�̻��̸�
                    if (grade == "����") {    //grade ���� �ٸ��� ȸ��
                        *what->stat[i] += _item_val[2][i]; //stat : ü��,���ݷ�,���ǵ�,����
                        _item_val[0][i]--;
                    }
                    else if (grade == "����") {
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
        string grade = name.substr(0, 4); // �� �α��� (����,����)
        string item_type = name.substr(name.find(" ") + 1, 4); //(ü��,����,����,���,��)
        for (int i = 0; i < 4; i++) {
            if (item_type == _item[1][i]) { //ü��,����,���ǵ�,��� �� � ������?
                if (_item_val[0][i] > 0 || _item_val[1][i] > 0) {  //������ ������ ������ 0�̻��̸�
                    if (grade == "����") {    //grade ���� �ٸ��� ȸ��
                        *what->stat[i] -= _item_val[2][i]; //stat : ü��,���ݷ�,���ǵ�,����
                        break;
                    }
                    else if (grade == "����") {
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
    { "ü�� ȸ�� ����", "���ݷ� �� ����", "���ǵ� �� ����", "���� �� ����", "���ͺ�"},
    {"ü��","����","����", "���", "���ͺ�"}, // � ����������
    {"����","����","����","����","���ͺ�"} //������ Ÿ��
    };
    int _item_val[5][6] = {
    {1,1,1,2,0},				//���� ��� ������ ����
    {1,1,1,1,0},                //������ ��� ������ ����
    {10,2,2,2,10},			//���� ~~~ : ����-> ȸ����/ ���� ��-> ���� Ȯ��; 
    {20,4,4,4,20},          //������ ~~~ : ����-> ȸ����/ ���� ��-> ���� Ȯ��;
    {250,100,100,100,300},		 //���� (������ ������ *2�� ����ϸ� �ɵ��մϴ�.
    };

    int _money = 0;

};






class item : public player {
    void get() {
        cout << "�������� ������ϴ�.";
    }

};

class money : public player {
    void get() {
        cout << "���� ������ϴ�.";
    }

};








// �ڽ� Ŭ���� ���Կ�

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