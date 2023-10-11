#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// 해시 테이블 : 면접 단골주제 , 강사님은 5번 면접중 4번은 물어봤다고함.
// 기본기이기 때문!


// Q) map vs hash_map(C++11 표준 unordered_map)

// map :  Red Black Tree ---> 균형 이진 트리, 트리 구조로 관리가 됨., 균형을 맞추면서 트리가 유지됨.
// - 추가/탐색/삭제 O(logN)

// C# dictionary = C++ map (X)
// C# dictionary = C++ unordered_map

// hash_map(unordered_map)
// -추가/탐색/삭제 O(1)
// 속도적인 측면에서 보면 해시맵이 훨씬 더 빠르다. 
// 해시맵은 메모리를 내주고 그 대신 속도를 취하는 방법이기 때문에, 충돌이 일어나지 않는다고 가정을 하면 해시맵이 훨씬 더 빠르다.


// 메모리를 내주고 속도를 취한다.!! = 살을 내주고 뼈를 취한다.!

// ex) 아파트 우편함
// 1~999 user(userId = 1~999)

// '해시' '테이블'
// O(1)
void TestTable()
{
    struct User
    {
        int userId = 0;// 1~999
        string username;
    };

    vector<User> users;
    users.resize(1000);

    // 777번 유저 정보 세팅
    users[777] = User{ 777,"Rookiss" };

    // 777번 유저 이름은?
    string name = users[777].username;
    cout << name << endl;

    // 테이블
    // 키를 알면, 데이터를 단번에 찾을 수 있다!

    // 문제의 상황
    // int32_max (3억~)
    // 살을 내줘도 정도껏 내줘야함...
    // 메모리도 무한은 아니다!
}

// 보안
// id: rookiss + pw: qwer1234
// DB [rookiss][qwer1234]
// 요즘은 암호를 해쉬함수를 적용시켜서 db에 저장함. 즉, 해시값을 저장함.
// 해커가 db를 탈취한다고 해도 역으로는 qwer1234 를 유추할 수 없다.

// 비밀번호 찾기 -> 아이디 입력 / 폰 인증 -> 새 비밀번호를 입력하세요. 
// 해당 사이트도 해당 비밀번호의 해시값을 아는것
// 원래 비밀번호는 사이트도 모름. 따라서 새 비밀번호를 입력하라고 하는것.


void TestHash()
{
    struct User
    {
        int userId = 0;// 1~999
        string username;
    };

    vector<User> users;
    users.resize(1000);

    const int userId = 123456789;
    int key = (userId % 1000);// hash < 고유번호


    //// 777번 유저 정보 세팅
    //users[777] = User{ 777,"Rookiss" };

    //// 777번 유저 이름은?
    //string name = users[777].username;
    //cout << name << endl;

    // 123456789번 유저 정보 세팅
    users[key] = User{ userId,"Rookiss" };

    // 123456789번 유저 이름은?
    User& user = users[key];
    if (user.userId == userId)
    {
        string name = user.username;
        cout << name << endl;
    }

    // 충돌 문제!
    // 충돌이 발생한 자리를 대신해서 다른 빈자리를 찾아나서면 된다.
    // - 선형 조사법 (linear probing) : 차리가 차있으면, 옆자리로 이동
    // ex) hash(key) +1 -> hash(key)+2  ----> 근데 이방식은 데이터가 몰리게 되면 인접한 애들끼리 서로 겹칠 확률이 높아짐.
    // - 이차 조사법 (quardratic probing) ===> 선형 조사법을 보완
    // ex) hash(key) + 1^2 -> hash(key) + 2^2


    // 데이터가 엄청 많을때.
    // 체이닝
    //그냥 연결 리스트나 벡터 같은 걸로 만들어 가지고 동일한 키 값이 누군가가 있었다고 하면은
    //그냥 그 위에다가 이렇게 연 이어가지고 양꼬치 마냥 그냥 줄줄 이어가지고 데이터를 계속 밀어 넣는다. 
}

// O(1)
void TestHashTableChaining()
{
    struct User
    {
        int userId = 0;// 1~999
        string username;
    };


    vector<vector<User>> users;
    users.resize(1000);

    const int userId = 123456789;
    int key = (userId % 1000);// hash < 고유번호

    // 123456789번 유저 정보 세팅
    users[key].push_back(User{ userId,"Rookiss" });

    // 123456789번 유저 이름은?
    vector<User>& bucket = users[key];
    for (User& user : bucket)
    {
        if (user.userId == userId)
        {
            string name = user.username;
            cout << name << endl;
        }
    }

}

int main()
{
    TestTable();
    TestHash();

    return 0;
}

