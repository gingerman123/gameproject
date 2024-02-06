// project_game.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>


// 수풀 속에서 랜덤 확률로 포켓몬나옴

using namespace std;

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

    void _set_mon_list(int i,string mon_type) {
        this->_monster[i] = mon_type;
    }
    string _get_mon_list(int i) {
        return _monster[i];
    }

protected:
    string _username;
    static int _item;
    static int _money;
    static string _monster[6];

};

// staitc 초기화
int player::_item = 0;
int player::_money = 0;
string player::_monster[6];


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



class monster :public player {
public:
    void get() {
        cout << _mon_type << " 속성 몬스터를 획득했습니다." << endl << endl;
    };
    
    virtual void set_mon_type() {
        _mon_type = "미지정";
    };

protected :
    string _mon_type;
};

class mon_water : public monster {
    void set_mon_type() {
        _mon_type = "물";
    };
};

class mon_fire : public monster {
    void set_mon_type() {
        _mon_type = "불";
    };
};

class mon_leaf : public monster {
    void set_mon_type() {
        _mon_type = "풀";
    };
};












// 자식 클래스 진입용

void get_what(player* what) {
    what->get();
}

void what_mon_type(monster* what) {
    what->set_mon_type();
}





int main()
{
    
    cout << "포켓몬 게임" << endl;

    // 사용자 설정
    player P1;

    string my_name;

    while (true) {

        string y_n;

        cout << "사용자 이름을 입력하세요. : ";
        cin >> my_name;

        cout << endl << "입력하신 이름이 " << my_name << "이 맞나요? (Y / N) : ";
        cin >> y_n;
        cout << endl;

        while (true) {
            if (y_n == "Y" || y_n == "N") {
                break;
            }
            cout << "(Y / N)으로 입력해주세요. : ";
            cin >> y_n;
            cout << endl;
        }

        if (y_n == "Y") {
            break;
        }
        cout << "다시 ";
    }

    P1._set_username(my_name);
    
    cout << "플레이어 이름은 " << P1._get_username() << "입니다." << endl;






    //기본 몬스터 선택
    string m_type_input;


    cout << "기본 몬스터 속성을 선택해주세요. (물 / 불 / 풀). : ";
    cin >> m_type_input;
    cout << endl;

    while (true) {
        if (m_type_input== "물" || m_type_input == "불" || m_type_input == "풀") {
            break;
        }
        cout << "(물 / 불 / 풀)으로 입력해주세요. : ";
        cin >> m_type_input;
        cout << endl;
    }

    // 몬스터 속성 입력 (자식 클래스 불러오기 확인 작업)
    if (m_type_input == "물") {
        monster* m1 = new mon_water();
        what_mon_type(m1);
        get_what(m1);
        P1._set_mon_list(1,"물");
        delete m1;            
    }
    else if (m_type_input == "불") {
        monster* m1 = new mon_fire();
        what_mon_type(m1);
        get_what(m1);
        P1._set_mon_list(1, "불");
        delete m1;
    }
    else if (m_type_input == "풀") {
        monster* m1 = new mon_leaf();
        what_mon_type(m1);
        get_what(m1);
        P1._set_mon_list(1, "풀");
        delete m1;
    }
    

    cout << "처음으로 선택하신 몬스터 속성은 " << P1._get_mon_list(1) << "입니다." << endl;




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
