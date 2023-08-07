#include <iostream>
#include <string>
#include <random>

using namespace std;

class Pole {
    // двумерный массив обозначается двойным указателем
    string** pole;

public:
    // конструктор поля для игры 3х3
    Pole() {
        // создаём ссылка на массив 3 элементов
        pole = new string * [3];
        for (int i = 0; i < 3; i++) {
            // присваем каждому элементу отдельный массив на 3 элемента
            pole[i] = new string[3];
        }

        // заполняем все ячейки прочерком
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                pole[i][j] = "-";
            }
        }
    }

    // деструктор
    ~Pole() {
        // сначала удаляем каждый вложенный 3-элементный массив
        for (int i = 0; i < 3; i++) {
            delete[] pole[i];
        }
        // удаляем внешний массив
        delete[] pole;
    }

    // метод вывода поля
    void print() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << pole[i][j];
            }
            cout << endl;
        }
        cout << " " << endl;
    }

    // метод установки символа в ячейку для Игрока
    void setPlayerSymbol(int r, int c, string s) {
        // проверка, не выходит ли за границы введённое значение
        if ((r < 3 && r >= 0) && (c < 3 && c >= 0)) {
            // проверка, является ли занимаемое поле символом прочерка
            if (pole[r][c] == "-") {
                pole[r][c] = s;
            }
            else {
                cout << "Такой ход сделать нельзя!" << endl;
            }
        }
    }

    // метод установки символа в ячейку для Компьютера
    void setCompSymbol(int r, int c, string s) {
        // проверка, не выходит ли за границы введённое значение
        if ((r < 3 && r >= 0) && (c < 3 && c >= 0)) {
            // проверка, является ли занимаемое поле символом прочерка
            if (pole[r][c] == "-") {
                pole[r][c] = s;
            }
            else {
                // cout << "Такой ход сделать нельзя!" << endl;
            }
        }
    }

    // функция проверки победы
    bool checkedEnd() {
        // проверка главной диагонали
        if (pole[0][0] == pole[1][1] && pole[1][1] == pole[2][2] && pole[0][0] != "-") {
            return true;
        }

        // проверка побочной диагонали
        if (pole[2][0] == pole[1][1] && pole[1][1] == pole[0][2] && pole[2][0] != "-") {
            return true;
        }

        // проверка горизонталей и вертикалей
        for (int i = 0; i < 3; i++) {
            // вертикали
            if (pole[i][0] == pole[i][1] && pole[i][1] == pole[i][2] && pole[i][0] != "-") {
                return true;
            }
            // горизонтали
            if (pole[0][i] == pole[1][i] && pole[1][i] == pole[2][i] && pole[0][i] != "-") {
                return true;
            }
        }

        // проверка ничьи 
        bool isFull = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (pole[i][j] == "-") {
                    isFull = false;
                    break;
                }
            }
        }

        // проекра, заполнены ли все поля
        if (isFull) {
            return true;
        }

        return false;
    }

    // функция проверки победы
    void checked_Win_or_Draw(string n) {
        // проверка главной диагонали
        if (pole[0][0] == pole[1][1] && pole[1][1] == pole[2][2] && pole[0][0] != "-") {
            cout << "Победа игрока " << n << endl;
        }

        // проверка побочной диагонали
        if (pole[2][0] == pole[1][1] && pole[1][1] == pole[0][2] && pole[2][0] != "-") {
            cout << "Победа игрока " << n << endl;
        }

        // проверка горизонталей и вертикалей
        for (int i = 0; i < 3; i++) {
            // вертикали
            if (pole[i][0] == pole[i][1] && pole[i][1] == pole[i][2] && pole[i][0] != "-") {
                cout << "Победа игрока " << n << endl;
            }
            // горизонтали
            if (pole[0][i] == pole[1][i] && pole[1][i] == pole[2][i] && pole[0][i] != "-") {
                cout << "Победа игрока " << n << endl;
            }
        }

        // проверка ничьи 
        bool isFull = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (pole[i][j] == "-") {
                    isFull = false;
                    break;
                }
            }
        }

        // проверка, заполнены ли все поля
        if (isFull) {
            cout << "У вас ничья!" << endl;
        }
    }

    // метод хода Компьтера
    void CompMove(string val) {
        // случайное значение        
        int s;
        int count = 0;

        // значение игрока
        string oppVal;
        if (val == "X") {
            oppVal = "0";
        }
        if (val == "0") {
            oppVal = "X";
        }

        // Первое правило: если можешь немедленно выиграть - выигрывай
        // Второе правило: если игрок не может выиграть немедленно, но если он мог бы немедленно выиграть,
        // сделав ход в какую-то клетку, компьютер сам делает ход в эту клетку, предотвращая немедленный выигрыш

        //........................ 1 правило
        // ГОРИЗОНТАЛИ

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
                // ВЕРТИКАЛИ
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

        // ДИАГОНАЛИ
        // проверка почти заполненных диагоналей
        if (pole[0][0] == val && pole[1][1] == val && pole[2][2] == "-" && count == 0) {
            pole[2][2] = val;
            count++;
            // cout << "7" << endl;
        }
        else if (pole[0][2] == val && pole[1][1] == val && pole[2][0] == "-" && count == 0) {
            pole[2][0] = val;
            count++;
            // cout << "8" << endl;
        }
        else if (pole[2][0] == val && pole[1][1] == val && pole[0][2] == "-" && count == 0) {
            pole[0][2] = val;
            count++;
            // cout << "9" << endl;
        }
        else if (pole[2][2] == val && pole[1][1] == val && pole[0][0] == "-" && count == 0) {
            pole[0][0] = val;
            count++;
            // cout << "10" << endl;
        }
        
        //........................ 2 правило
        // ГОРИЗОНТАЛИ
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
                // ВЕРТИКАЛИ
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

        // ДИАГОНАЛИ
        // проверка почти заполненных диагоналей
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

        // ОТДЕЛЬНО ОТ ПРАВИЛ
        // ЦЕНТР
        if (pole[1][1] == "-" && count == 0) {
            pole[1][1] = val;
            count++;
            // cout << "21" << endl;
        }
        else if ((count == 0) && (pole[1][1] != "-")) {
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

        // если не подходит ни один случай, нужно вставлять в первую попавшуюся пустую ячейку
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (pole[i][j] == "-" && count == 0) {
                    pole[i][j] = val;
                    count++;
                    // cout << "26" << endl;
                }
            }
        }
    }
};

class Player {
        int row, column;
        string value, name;

    public:
        // конструктор - позиция на элементе [1],[1] - самый оптимальный первый ход
        Player() {
            row = column = 1;
            value = "";
            name = "Игрок";
        }

        // метод установления значения для игрока
        void setVal() {
            cout << this->name << ", введите координаты (через пробел): ";
            cin >> row >> column;
        }

        // возвращает строку
        int getRow() { return row; }

        // возвращает столбец
        int getColumn() { return column; }

        // возвращает значени
        string getValue() { return value; }

        // возвращает имя
        string getName() { return name; }

        void setRow(int r) { row = r; }

        void setColumn(int c) { column = c; }
        
        void setValue(string v) { value = v; }

        void setName(string n) { this->name = n; }
};


class Computer : public Player {
        int row, column;
        string value, name;

    public:
        Computer() {
            row = column = 1;
            value = "";
            name = "Computer";
        }
};

class Game {
    public:
        void showInfo() {
            cout << "Игроки по очереди ставят на свободные клетки поля 3x3 знаки (один всегда крестики, другой всегда нолики)." << endl;
            cout << "Первый, выстроивший в ряд 3 своих фигуры по вертикали, горизонтали или большой диагонали, выигрывает. " << endl;
            cout << "Если игроки заполнили все 9 ячеек и оказалось, что ни в одной вертикали, горизонтали или большой диагонали" << endl;
            cout << "нет трёх одинаковых знаков, партия считается закончившейся в ничью. Первый ход делает игрок, ставящий крестики." << endl;
        }


        void printPole() {
            cout << "Индексы полей выглядят следующим образом: " << endl;
            cout << "     | 0 | 1 | 2 | " << endl;
            cout << "   0 | - | - | - | " << endl;
            cout << "   1 | - | - | - | " << endl;
            cout << "   2 | - | - | - | " << endl;
            cout << " " << endl;
            cout << "То есть, чтобы обратиться к определённой ячейке, вводите следующие координаты" << endl;
            cout << "     |  0  |  1  |  2  | " << endl;
            cout << "   0 | 0 0 | 0 1 | 0 2 | " << endl;
            cout << "   1 | 1 0 | 1 1 | 1 2 | " << endl;
            cout << "   2 | 2 0 | 2 1 | 2 2 | " << endl;
            cout << " " << endl;
        }


        // метод хода игры Игрок vs Игрок
        void twoPlayerGame() {
            // создаём 1 поле и 2 игрока
            Pole p;
            Player first;
            Player second;

            random_device rd; // Инициализация генератора случайных чисел
            mt19937 generator(rd()); // Создание генератора с использованием random_device
            uniform_int_distribution<int> distribution(0, 1); // Диапазон случайных чисел

            int randomizer = distribution(generator); // Генерация случайного числа

            cout << "ИГРОК vs ИГРОК" << endl;
            p.print();

            string n1, n2;
            cout << "Игрок #1, введите имя: ";
            cin >> n1;

            cout << "Игрок #2, введите имя: ";
            cin >> n2;
            first.setName(n1);
            second.setName(n2);

            int whoFirst;
            int whoSecond = 0;
            cout << "Назначение первого игрока проходит случайным образом - игроки выбирают 1 и 0: чьё число совпадёт со случайно выбранном, ходит первым." << endl;
            cout << "Игрок " << n1 << ", введите число (сперва договорившись с игроком " << n2 << "):" << endl;
            cin >> whoFirst;
            if (whoFirst == 0) {
                whoSecond = 1;
            }
            if (whoFirst == 1) {
                whoSecond = 0;
            }

            // Первый Игрок ходит первым
            if (whoFirst == randomizer) {
                cout << "Если игрок " << n1 << " выбрал " << whoFirst << ", значит игрок " << n2 << " выбрал " << whoSecond << "." << endl;
                cout << "Игрок " << n1 << " ходит первым." << endl;
                p.print();

                // переменная, определяющая, есть ли победа или ничья
                bool status = false;

                while (!status) {
                    cout << "--------------------- ХОД ИГРОКА " << first.getName() << " ---------------------" << endl;
                    // вводим значение для игрока
                    first.setVal();
                    // вводим значение на поле
                    p.setPlayerSymbol(first.getRow(), first.getColumn(), "X");

                    status = p.checkedEnd();
                    p.checked_Win_or_Draw(n1);
                    p.print();
                    if (status) {
                        break;
                    }

                    cout << "--------------------- ХОД ИГРОКА " << second.getName() << " ---------------------" << endl;
                    second.setVal();
                    p.setPlayerSymbol(second.getRow(), second.getColumn(), "0");

                    status = p.checkedEnd();
                    p.checked_Win_or_Draw(n2);
                    p.print();
                }

                if (status) {
                    cout << "Игра окончена!" << endl;
                }
            }
            
            // Второй Игрок ходит первым
            if (whoSecond == randomizer) {
                cout << "Если игрок " << n1 << " выбрал " << whoFirst << ", значит игрок " << n2 << " выбрал " << whoSecond << "." << endl;
                cout << "Игрок " << n2 << " ходит первым." << endl;
                p.print();

                // переменная, определяющая, есть ли победа или ничья
                bool status = false;

                while (!status) {
                    cout << "--------------------- ХОД ИГРОКА " << second.getName() << " ---------------------" << endl;
                    p.print();
                    
                    second.setVal();
                    p.setPlayerSymbol(second.getRow(), second.getColumn(), "0");

                    status = p.checkedEnd();
                    p.checked_Win_or_Draw(n2);
                    if (status) {
                        break;
                    }

                    cout << "--------------------- ХОД ИГРОКА " << first.getName() << " ---------------------" << endl;
                    p.print();

                    // вводим значение для игрока
                    first.setVal();
                    // вводим значение на поле
                    p.setPlayerSymbol(first.getRow(), first.getColumn(), "X");
                    p.print();

                    status = p.checkedEnd();
                    p.checked_Win_or_Draw(n1);
                }

                if (status) {
                    cout << "Игра окончена!" << endl;
                }
            }
        }

        // метод хода игры Игрок vs Компьютер
        void onePlayerGame() {
            // создаём 1 поле, 1 игрока и 1 компьютер
            Pole p;
            Player first;
            Computer comp;

            random_device rd; // Инициализация генератора случайных чисел
            mt19937 generator(rd()); // Создание генератора с использованием random_device
            uniform_int_distribution<int> distribution(0, 1); // Диапазон случайных чисел

            int random = distribution(generator); // Генерация случайного числа

            // row, column
            int r, c;

            cout << "ИГРОК vs КОМПЬЮТЕР" << endl;

            string n;
            cout << "Игрок, введите имя: ";
            cin >> n;
            first.setName(n);

            // выбор игрока, идущего первым
            int whoIsFirst;
            cout << "Каким способом вы хотите выбрать того, кто будет играть за КРЕСТИКОВ: случайно (1) или самостоятельно (2)?" << endl;
            cin >> whoIsFirst;

            // случайный выбор
            if (whoIsFirst == 1) {
                // компьютер - крестик
                if (random == 0) {
                    comp.setValue("X");
                    first.setValue("0");
                }
                // компьютер - нолик
                if (random == 1) {
                    comp.setValue("0");
                    first.setValue("X");
                }
            }

            // самостоятельный выбор
            if (whoIsFirst == 2) {
                int whoToBe;
                cout << "Вы хотите быть крестиком (1) или ноликом (2): " << endl;
                cin >> whoToBe;
                // игрок - крестики
                if (whoToBe == 1) {
                    comp.setValue("0");
                    first.setValue("X");
                }
                // игрок - нолики
                if (whoToBe == 2) {
                    comp.setValue("X");
                    first.setValue("0");
                }

            }

            // переменная, определяющая, есть ли победа или ничья
            bool status = false;

            // Компьютер ходит вторым
            if (comp.getValue() == "0") {
                cout << "Игрок " << n << " ходит первым" << endl;
                // переменная, определяющая, есть ли победа или ничья
                // bool status = false;
                p.print(); 

                while (!status) {
                    cout << "--------------------- ХОД ИГРОКА " << first.getName() << " ---------------------" << endl;
                    // вводим значение для игрока
                    cout << n << ", введите координаты (через пробел): ";
                    cin >> r;
                    cin >> c;

                    first.setRow(r);
                    first.setColumn(c);

                    // вводим значение на поле
                    p.setPlayerSymbol(first.getRow(), first.getColumn(), first.getValue());
                    p.print();

                    status = p.checkedEnd();
                    p.checked_Win_or_Draw(first.getName());
                    if (status) {
                        break;
                    }

                    cout << "--------------------- ХОД КОМПЬЮТЕРА ---------------------" << endl;
                    p.CompMove(comp.getValue());
                    p.setCompSymbol(comp.getRow(), comp.getColumn(), comp.getValue());
                    p.print();

                    status = p.checkedEnd();
                    p.checked_Win_or_Draw(comp.getName());
                }

                if (status) {
                    cout << "Игра окончена!" << endl;
                }
            }

            // Компьютер ходит первым
            if (comp.getValue() == "X") {
                cout << "Computer ходит первым" << endl;
                p.print();

                while (!status) {
                    cout << "--------------------- ХОД КОМПЬЮТЕРА ---------------------" << endl;
                    
                    p.CompMove(comp.getValue());
                    p.setCompSymbol(comp.getRow(), comp.getColumn(), comp.getValue());
                    p.print();

                    status = p.checkedEnd();
                    p.checked_Win_or_Draw(comp.getName());

                    if (status) {
                        break;
                    }

                    cout << "--------------------- ХОД ИГРОКА " << first.getName() << " ---------------------" << endl;
                    // вводим значение для игрока
                    cout << n << ", введите координаты (через пробел): ";
                    cin >> r;
                    cin >> c;

                    first.setRow(r);
                    first.setColumn(c);

                    // вводим значение на поле
                    p.setPlayerSymbol(first.getRow(), first.getColumn(), first.getValue());
                    p.print();

                    status = p.checkedEnd();
                    p.checked_Win_or_Draw(first.getName());
                }

                if (status) {
                    cout << "Игра окончена!" << endl;
                }
            }

        }
    }; 

    int main() {
        setlocale(LC_ALL, "Russian");

        int choice;
        Game g;
        // g.twoPlayerGame();

        // рандом или 0, или 1
        // cout << rand() % 2 << endl;

        g.showInfo();
        g.printPole();
        cout << "Вы хотите играть с человеком (1) или с компьютером (2): ";
        cin >> choice;

        if (choice == 1) {
            g.twoPlayerGame();
        }
        else if (choice == 2) {
            g.onePlayerGame();
        }

        return 0;
    }
