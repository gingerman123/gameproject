#pragma once


class monster {
public:
    void get() {
        //cout << _mon_type << " 속성 몬스터를 획득했습니다." << endl << endl;
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
        _mon_type = "물";
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
    // 최대 몬스터 포획 가능 수 = 6 , 시작시 itemm, money = 0
    // 
    // 스토리 모드를 대비하여 마지막 위치를 저장하는 location 변수 고려
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

    void _set_mon_list(int i, monster* who) {   //1열 몬스터 속성 / 2열 몬스터 레벨 / 몬스터 최대 hp
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

// staitc 초기화
int player::_item = 0;
int player::_money = 0;



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