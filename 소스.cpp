#pragma once


class monster {
public:
    void get() {
        //cout << _mon_type << " �Ӽ� ���͸� ȹ���߽��ϴ�." << endl << endl;
    };

    virtual void set_mon_type() { };

    string get_mon_type() const {
        return _mon_type;
    }

protected:
    string _mon_type;
    int _hp;
    int _lv;
    int _def;
    string m_name;


};

class mon_water : public monster {
    void set_mon_type() {
        _mon_type = "��";
        _hp = 100;
        _lv = 0;
        _def = 10;
    };
};

class mon_fire : public monster {
    void set_mon_type() {
        _mon_type = 2;
    };
};

class mon_leaf : public monster {
    void set_mon_type() {
        _mon_type = 3;
    };
};



class player {
    // �ִ� ���� ��ȹ ���� �� = 6 , ���۽� itemm, money = 0
    // 
    // ���丮 ��带 ����Ͽ� ������ ��ġ�� �����ϴ� location ���� ���
public:
    player() {}
    ~player() {}

    player(string name) {
        _username = name;
        _item = 0;
        _money = 0;
    }

    virtual void get() {};

    void _set_username(string in) {
        this->_username = in;
    }
    string _get_username() {
        return _username;
    }

    void _set_mon_list(int i, monster* who) {   //1�� ���� �Ӽ� / 2�� ���� ���� / ���� �ִ� hp
        this->_monster[i] = who;
    }
    monster* _get_mon_list(int i) const {
        return _monster[i];
    }

protected:
    string _username;
    static int _item;
    static int _money;
    monster* _monster[6];

};

// staitc �ʱ�ȭ
int player::_item = 0;
int player::_money = 0;



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

void get_what_monster(monster* what) {
    what->get();
}



void what_mon_type(monster* what) {
    what->set_mon_type();
}


string show_mon_val(player& who, int mon_num, string what) {
    string value;
    monster* mon_value = who._get_mon_list(mon_num);
    if (what == "type") {
        //value = 
    }

    delete mon_value;
}