#include <iostream>
#include <string>

using namespace std;

class Pole {
    // ��������� ������ ������������ ������� ����������
    string** pole;

public:
    // ����������� ���� ��� ���� 3�3
    Pole() {
        // ������ ������ �� ������ 3 ���������
        pole = new string * [3];
        for (int i = 0; i < 3; i++) {
            // �������� ������� �������� ��������� ������ �� 3 ��������
            pole[i] = new string[3];
        }

        // ��������� ��� ������ ���������
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                pole[i][j] = "-";
            }
        }
    }

    // ����������
    ~Pole() {
        // ������� ������� ������ ��������� 3-���������� ������
        for (int i = 0; i < 3; i++) {
            delete[] pole[i];
        }
        // ������� ������� ������
        delete[] pole;
    }

    // ����� ������ ����
    void print() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << pole[i][j];
            }
            cout << endl;
        }
        cout << " " << endl;
    }

    // ����� ��������� ������� � ������
    void setPlayerSymbol(int r, int c, string s) {
        // ��������, �� ������� �� �� ������� �������� ��������
        if ((r < 3 && r >= 0) && (c < 3 && c >= 0)) {
            // ��������, �������� �� ���������� ���� �������� ��������
            if (pole[r][c] == "-") {
                pole[r][c] = s;
            }
            else {
                cout << "����� ��� ������� ������!" << endl;
            }
        }
    }

    void setCompSymbol(int r, int c, string s) {
        // ��������, �� ������� �� �� ������� �������� ��������
        if ((r < 3 && r >= 0) && (c < 3 && c >= 0)) {
            // ��������, �������� �� ���������� ���� �������� ��������
            if (pole[r][c] == "-") {
                pole[r][c] = s;
            }
            else {
                // cout << "����� ��� ������� ������!" << endl;
            }
        }
    }

    // ������� �������� ������
    bool checkedEnd() {
        // �������� ������� ���������
        if (pole[0][0] == pole[1][1] && pole[1][1] == pole[2][2] && pole[0][0] != "-") {
            return true;
        }

        // �������� �������� ���������
        if (pole[2][0] == pole[1][1] && pole[1][1] == pole[0][2] && pole[2][0] != "-") {
            return true;
        }

        // �������� ������������ � ����������
        for (int i = 0; i < 3; i++) {
            // ���������
            if (pole[i][0] == pole[i][1] && pole[i][1] == pole[i][2] && pole[i][0] != "-") {
                return true;
            }
            // �����������
            if (pole[0][i] == pole[1][i] && pole[1][i] == pole[2][i] && pole[0][i] != "-") {
                return true;
            }
        }

        // �������� ����� 
        bool isFull = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (pole[i][j] == "-") {
                    isFull = false;
                    break;
                }
            }
        }

        // �������, ��������� �� ��� ����
        if (isFull) {
            return true;
        }

        return false;
    }

    // ������� �������� ������
    void checked_Win_or_Draw(string n) {
        // �������� ������� ���������
        if (pole[0][0] == pole[1][1] && pole[1][1] == pole[2][2] && pole[0][0] != "-") {
            cout << "������ ������ " << n << endl;
        }

        // �������� �������� ���������
        if (pole[2][0] == pole[1][1] && pole[1][1] == pole[0][2] && pole[2][0] != "-") {
            cout << "������ ������ " << n << endl;
        }

        // �������� ������������ � ����������
        for (int i = 0; i < 3; i++) {
            // ���������
            if (pole[i][0] == pole[i][1] && pole[i][1] == pole[i][2] && pole[i][0] != "-") {
                cout << "������ ������ " << n << endl;
            }
            // �����������
            if (pole[0][i] == pole[1][i] && pole[1][i] == pole[2][i] && pole[0][i] != "-") {
                cout << "������ ������ " << n << endl;
            }
        }

        // �������� ����� 
        bool isFull = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (pole[i][j] == "-") {
                    isFull = false;
                    break;
                }
            }
        }

        // ��������, ��������� �� ��� ����
        if (isFull) {
            cout << "� ��� �����!" << endl;
        }
    }

    void CompMove(string val) {
        // ��������� ��������        
        int s;
        int count = 0;

        // �������� ������
        string oppVal;
        if (val == "X") {
            oppVal = "O";
        }
        else {
            oppVal = "X";
        }

        // ������ �������: ���� ������ ���������� �������� - ���������
        // ������ �������: ���� ����� �� ����� �������� ����������, �� ���� �� ��� �� ���������� ��������,
        // ������ ��� � �����-�� ������, ��������� ��� ������ ��� � ��� ������ ������������ ����������� �������

        //........................ 1 �������
        // �����������

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // X X -
                if (pole[i][0] == val && pole[i][1] == val && pole[i][2] == "-" && count == 0) {
                    pole[i][2] = val;
                    count++;
                    // cout << "1" << endl;
                    // break;
                }
                // X - X
                else if (pole[i][0] == val && pole[i][2] == val && pole[i][1] == "-" && count == 0) {
                    pole[i][1] = val;
                    count++;
                    // cout << "2" << endl;
                    // break;
                }
                // - X X
                else if (pole[i][1] == val && pole[i][2] == val && pole[i][0] == "-" && count == 0) {
                    pole[i][0] = val;
                    count++;
                    // cout << "3" << endl;
                    // break;
                }
                // ���������
                // X
                // X
                // -
                else if (pole[0][j] == val && pole[1][j] == val && pole[2][j] == "-" && count == 0) {
                    pole[2][j] = val;
                    count++;
                    // cout << "4" << endl;
                    // break;
                }
                // X
                // -
                // X
                else if (pole[0][j] == val && pole[2][j] == val && pole[1][j] == "-" && count == 0) {
                    pole[1][j] = val;
                    count++;
                    // cout << "5" << endl;
                    // break;
                }
                // -
                // X
                // X 
                else if (pole[1][j] == val && pole[2][j] == val && pole[0][j] == "-" && count == 0) {
                    pole[0][j] = val;
                    count++;
                    // cout << "6" << endl;
                    // break;
                }
            }
        }

        // ���������
        // �������� ����� ����������� ����������
        if (pole[0][0] == val && pole[1][1] == val && pole[2][2] == "-" && count == 0) {
            pole[2][2] = val;
            // cout << "7" << endl;
        }
        else if (pole[0][2] == val && pole[1][1] == val && pole[2][0] == "-" && count == 0) {
            pole[2][0] = val;
            // cout << "8" << endl;
        }
        else if (pole[2][0] == val && pole[1][1] == val && pole[0][2] == "-" && count == 0) {
            pole[0][2] = val;
            // cout << "9" << endl;
        }
        else if (pole[2][2] == val && pole[1][1] == val && pole[0][0] == "-" && count == 0) {
            pole[0][0] = val;
            // cout << "10" << endl;
        }
        
        //........................ 2 �������
        // �����������
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // 0 0 -
                if (pole[i][0] == oppVal && pole[i][1] == oppVal && pole[i][2] == "-" && count == 0) {
                    pole[i][2] = val;
                    count++;
                    // cout << "11" << endl;
                    // break;
                }
                // X - X
                else if (pole[i][0] == oppVal && pole[i][2] == oppVal && pole[i][1] == "-" && count == 0) {
                    pole[i][1] = val;
                    count++;
                    // cout << "12" << endl;
                    // break;
                }
                // - X X
                else if (pole[i][1] == oppVal && pole[i][2] == oppVal && pole[i][0] == "-" && count == 0) {
                    pole[i][0] = val;
                    count++;
                    // cout << "13" << endl;
                    // break;
                }
                // ���������
                // X
                // X
                // -
                else if (pole[0][j] == oppVal && pole[1][j] == oppVal && pole[2][j] == "-" && count == 0) {
                    pole[2][j] = val;
                    count++;
                    // cout << "14" << endl;
                    // break;
                }
                // X
                // -
                // X
                else if (pole[0][j] == oppVal && pole[2][j] == oppVal && pole[1][j] == "-" && count == 0) {
                    pole[1][j] = val;
                    count++;
                    // cout << "15" << endl;
                    // break;
                }
                // -
                // X
                // X
                else if (pole[1][j] == oppVal && pole[2][j] == oppVal && pole[0][j] == "-" && count == 0) {
                    pole[0][j] = val;
                    count++;
                    // cout << "16" << endl;
                    // break;
                }
            }
        }

        // ���������
        // �������� ����� ����������� ����������
        if (pole[0][0] == oppVal && pole[1][1] == oppVal && pole[2][2] == "-" && count == 0) {
            pole[2][2] = val;
            count++;
            // cout << "17" << endl;
        }
        else if (pole[0][2] == oppVal && pole[1][1] == oppVal && pole[2][0] == "-" && count == 0) {
            pole[2][0] = val;
            count++;
            // cout << "18" << endl;
        }
        else if (pole[2][0] == oppVal && pole[1][1] == oppVal && pole[0][2] == "-" && count == 0) {
            pole[0][2] = val;
            count++;
            // cout << "19" << endl;
        }
        else if (pole[2][2] == oppVal && pole[1][1] == oppVal && pole[0][0] == "-" && count == 0) {
            pole[0][0] = val;
            count++;
            // cout << "20" << endl;
        }

        // �������� �� ������
        // �����
        if (pole[1][1] == "-" && count == 0) {
            pole[1][1] = val;
            count++;
            // cout << "21" << endl;
        }
        else if (count == 0){
            s = rand() % 4;
            if ((s == 0 && pole[0][0] == "-") || (s == 1 && pole[0][0] == "-") || (s == 2 && pole[0][0] == "-") || (s == 3 && pole[0][0] == "-")) {
                pole[0][0] = val;
                count++;
                // cout << "22" << endl;
            }
            else if ((s == 0 && pole[0][2] == "-") || (s == 1 && pole[0][2] == "-") || (s == 2 && pole[0][2] == "-") || (s == 3 && pole[0][2] == "-")) {
                pole[0][2] = val;
                count++;
                // cout << "23" << endl;
            }
            else if ((s == 0 && pole[2][0] == "-") || (s == 1 && pole[2][0] == "-") || (s == 2 && pole[2][0] == "-") || (s == 3 && pole[2][0] == "-")) {
                pole[2][0] = val;
                count++;
                // cout << "24" << endl;
            }
            else if ((s == 0 && pole[2][2] == "-") || (s == 1 && pole[2][2] == "-") || (s == 2 && pole[2][2] == "-") || (s == 3 && pole[2][2] == "-")) {
                pole[2][2] = val;
                count++;
                // cout << "25" << endl;
            }
        }

        // ���� �� �������� �� ���� ������, ����� ��������� � ����� ������ ������
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (pole[i][j] == "-" && count == 0) {
                    pole[i][j] = val;
                    count++;
                }
            }
        }
    }
};

class Player {
        int row, column;
        string value, name;

    public:
        // ����������� - ������� �� �������� [0],[0]
        Player() {
            row = column = 0;
            value = "";
            name = "�����";
        }

        // ����� ������������ �������� ��� ������
        void setVal() {
            cout << this->name << ", ������� ���������� (����� ������): ";
            cin >> row >> column;
        }

        // ���������� ������
        int getRow() { return row; }

        // ���������� �������
        int getColumn() { return column; }

        // ���������� �������
        string getValue() { return value; }

        // ���������� ���
        string getName() { return name; }

        void setRow(int r) {
            row = r;
        }

        void setColumn(int c) {
            column = c;
        }
        
        void setValue(string v) {
            value = v;
        }

        void setName(string n) {
            name = n;
        }
};


class Computer : public Player {
        int row, column;
        string value, name;

    public:
        Computer() {
            row = column = 0;
            value = "";
            name = "Computer";
        }
};

class Game {
    public:
        void showInfo() {
            cout << "������ �� ������� ������ �� ��������� ������ ���� 3x3 ����� (���� ������ ��������, ������ ������ ������)." << endl;
            cout << "������, ����������� � ��� 3 ����� ������ �� ���������, ����������� ��� ������� ���������, ����������. " << endl;
            cout << "���� ������ ��������� ��� 9 ����� � ���������, ��� �� � ����� ���������, ����������� ��� ������� ���������" << endl;
            cout << "��� ��� ���������� ������, ������ ��������� ������������� � �����. ������ ��� ������ �����, �������� ��������." << endl;
        }


        void printPole() {
            cout << "������� ����� �������� ��������� �������: " << endl;
            cout << "     | 0 | 1 | 2 | " << endl;
            cout << "   0 | - | - | - | " << endl;
            cout << "   1 | - | - | - | " << endl;
            cout << "   2 | - | - | - | " << endl;
            cout << " " << endl;
            cout << "�� ����, ����� ���������� � ����������� ������, ������� ��������� ����������" << endl;
            cout << "     |  0   |  1  |  2  | " << endl;
            cout << "   0 | 0 0  | 0 1 | 0 2 | " << endl;
            cout << "   1 | 1 0  | 1 1 | 1 2 | " << endl;
            cout << "   2 | 2 0  | 2 1 | 2 2 | " << endl;
            cout << " " << endl;
        }


        // ����� ���� ���� ����� vs �����
        void twoPlayerGame() {
            // ������ 1 ���� � 2 ������
            Pole p;
            Player first;
            Player second;

            string n1, n2;
            cout << "����� �1, ������� ���: ";
            cin >> n1;

            cout << "����� �2, ������� ���: ";
            cin >> n2;
            first.setName(n1);
            second.setName(n2);

            int whoFirst, randomizer;
            int whoSecond = 0;
            cout << "���������� ������� ������ �������� ��������� ������� - ������ �������� 1 � 0: ��� ����� ������� �� �������� ���������, ����� ������." << endl;
            cout << "����� " << n1 << ", ������� ����� (������ ������������� � ������� " << n2 << "):" << endl;
            cin >> whoFirst;
            if (whoFirst == 0) {
                whoSecond = 1;
            }
            else if (whoFirst == 1) {
                whoSecond = 0;
            }
            else {
                cout << "�� ����� ���-�� �� ��... ��������� �Ѩ �������!!!";
            }

            randomizer = rand() % 2;

            // ���� ��������� �� �������� ���������
            if (whoFirst == randomizer) {
                cout << "���� ����� " << n1 << " ������ " << whoFirst << ", ������ ����� " << n2 << " ������ " << whoSecond << "." << endl;
                cout << "����� " << n1 << " ����� ������." << endl;
                p.print();
                // ����������, ������������, ���� �� ������ ��� �����
                bool status = false;

                while (!status) {
                    cout << "--------------------- ��� ������ " << first.getName() << " ---------------------" << endl;
                    // ������ �������� ��� ������
                    first.setVal();
                    // ������ �������� �� ����
                    p.setPlayerSymbol(first.getRow(), first.getColumn(), "X");
                    p.print();

                    status = p.checkedEnd();
                    p.checked_Win_or_Draw(n1);
                    if (status) {
                        break;
                    }

                    cout << "--------------------- ��� ������ " << second.getName() << " ---------------------" << endl;
                    second.setVal();
                    p.setPlayerSymbol(second.getRow(), second.getColumn(), "0");
                    p.print();

                    status = p.checkedEnd();
                    p.checked_Win_or_Draw(n2);
                }

                if (status) {
                    cout << "���� ��������!" << endl;
                }
            }
            else if (whoSecond == randomizer) {
                cout << "���� ����� " << n1 << " ������ " << whoFirst << ", ������ ����� " << n2 << " ������ " << whoSecond << "." << endl;
                cout << "����� " << n2 << " ����� ������." << endl;
                // ����������, ������������, ���� �� ������ ��� �����
                bool status = false;

                while (!status) {
                    cout << "--------------------- ��� ������ " << second.getName() << " ---------------------" << endl;
                    second.setVal();
                    p.setPlayerSymbol(second.getRow(), second.getColumn(), "0");
                    p.print();

                    status = p.checkedEnd();
                    p.checked_Win_or_Draw(n2);
                    if (status) {
                        break;
                    }

                    cout << "--------------------- ��� ������ " << first.getName() << " ---------------------" << endl;
                    // ������ �������� ��� ������
                    first.setVal();
                    // ������ �������� �� ����
                    p.setPlayerSymbol(first.getRow(), first.getColumn(), "X");
                    p.print();

                    status = p.checkedEnd();
                    p.checked_Win_or_Draw(n1);
                }

                if (status) {
                    cout << "���� ��������!" << endl;
                }
            }
        }

        // ����� ���� ���� ����� vs ���������
        void onePlayerGame() {
            // ������ 1 ����, 1 ������ � 1 ���������
            Pole p;
            Player first;
            Computer comp;

            // row, column
            int r, c;
            int random;

            p.print();

            string n;
            cout << "�����, ������� ���: ";
            cin >> n;

            // ����� ������, �������� ������
            int whoIsFirst;
            cout << "����� �������� �� ������ ������� ����, ��� ����� ������ �� ���������: �������� (1) ��� �������������� (2) ?" << endl;
            cin >> whoIsFirst;

            if (whoIsFirst == 1) {
                random = rand() % 2;
                // ��������� ������ - �������
                if (random == 0) {
                    comp.setValue("X");
                    first.setValue("0");
                }
                // ��������� ������ - �����
                else {
                    comp.setValue("0");
                    first.setValue("X");
                }
            }
            else if (whoIsFirst == 2) {
                int whoToBe;
                cout << "�� ������ ���� ��������� (1) ��� ������� (2): " << endl;
                cin >> whoToBe;
                if (whoToBe == 1) {
                    comp.setValue("0");
                    first.setValue("X");
                }
                else if (whoToBe == 2) {
                    comp.setValue("X");
                    first.setValue("0");
                }
                else {
                    cout << "�����, �� ����� ���-�� �� ��... ��������� ������� �� :/" << endl;
                }
            }
            else {
                cout << "�����, �� ����� ���-�� �� ��... ��������� ������� �� :/" << endl;
            }


            // ����������, ������������, ���� �� ������ ��� �����
            bool status = false;

            // ���� ������� - ������ ���  rand() % 2 == whoIsFirst
            if (comp.getValue() == "X") {
                cout << "����� " << n << " ����� ������" << endl;
                // ����������, ������������, ���� �� ������ ��� �����
                // bool status = false;

                while (!status) {
                    cout << "--------------------- ��� ������ " << n << " ---------------------" << endl;
                    // ������ �������� ��� ������
                    cout << n << ", ������� ���������� (����� ������): ";
                    cin >> r;
                    cin >> c;

                    first.setRow(r);
                    first.setColumn(c);

                    // ������ �������� �� ����
                    p.setPlayerSymbol(first.getRow(), first.getColumn(), first.getValue());
                    p.print();

                    status = p.checkedEnd();
                    p.checked_Win_or_Draw(n);
                    if (status) {
                        break;
                    }

                    cout << "--------------------- ��� ���������� ---------------------" << endl;
                    p.CompMove(comp.getValue());
                    p.setCompSymbol(comp.getRow(), comp.getColumn(), comp.getValue());
                    p.print();

                    status = p.checkedEnd();
                    p.checked_Win_or_Draw(comp.getName());
                }

                if (status) {
                    cout << "���� ��������!" << endl;
                }
            }
            // ���� �� ������� - ������ ��� ����������
            else {
                cout << "Computer ����� ������" << endl;

                while (!status) {
                    cout << "--------------------- ��� ���������� ---------------------" << endl;
                    p.CompMove(comp.getValue());
                    p.setCompSymbol(comp.getRow(), comp.getColumn(), comp.getValue());
                    p.print();

                    status = p.checkedEnd();
                    p.checked_Win_or_Draw(comp.getName());

                    if (status) {
                        break;
                    }

                    cout << "--------------------- ��� ������ ---------------------" << endl;
                    // ������ �������� ��� ������
                    cout << n << ", ������� ���������� (����� ������): ";
                    cin >> r;
                    cin >> c;

                    first.setRow(r);
                    first.setColumn(c);

                    // ������ �������� �� ����
                    p.setPlayerSymbol(first.getRow(), first.getColumn(), first.getValue());
                    p.print();

                    status = p.checkedEnd();
                    p.checked_Win_or_Draw(n);
                }

                if (status) {
                    cout << "���� ��������!" << endl;
                }
            }

        }
    };

    int main() {
        setlocale(LC_ALL, "Russian");

        int choice;
        Game g;
        // g.twoPlayerGame();

        // ������ ��� 0, ��� 1
        // cout << rand() % 2 << endl;

        g.showInfo();
        g.printPole();
        cout << "�� ������ ������ � ��������� (1) ��� � ����������� (2): ";
        cin >> choice;

        if (choice == 1) {
            cout << "����� vs �����" << endl;
            g.twoPlayerGame();
        }
        else if (choice == 2) {
            cout << "����� vs ���������" << endl;
            g.onePlayerGame();
        }

        return 0;
    }