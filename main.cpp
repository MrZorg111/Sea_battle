#include <iostream>

/*

 * Вначале игроки по очереди расставляют корабли, начиная с самых маленьких и заканчивая большими.
 * Маленькие корабли в одну клетку расставляются с помощью указания лишь одной клетки-точки на поле, к примеру 2,1.
 * Корабли размерностью от двух клеток и выше, расставляются с помощью координат их начала и конца, к примеру: 0,1 - 0,3.
 * Корабли могут быть установлены только строго вертикально, или горизонтально. Установка корабля по диагонали — недопустимо,
 * в случае которого об этом тоже надо сообщить пользователю. Если корабль не может быть размещён на заданных клетках из-за того,
 * что он столкнётся с другим кораблём (окажется на его клетках) или выйдет за пределы поля вообще,
 * то игроку должно быть сделано предупреждение, после которого он должен переставить корабль на новые валидные координаты.
 * Замечу, в нашем упрощённом варианте игры, мы не будем обсчитывать соприкосновения кораблей друг с другом,
 * а потому корабли вполне можно будет размещать друг к другу вплотную — борт к борту.
 * После того как все корабли были расставлены начинается игра. Игроки по очереди атакуют друг друга, называя координаты выстрела.
 * После выстрела, в консоль выводится информация о его результате: попал или мимо.
 * Если выстрел успешен, клетка, на которой был корабль (или его фрагмент) затирается и становится пустой.
 * Игра заканчивается тогда, когда все корабли одной из сторон будут полностью уничтожены.
 * Как только это произойдёт в консоль выводится информация с номером игрока, который победил.
 * */

char field(int b, int c) {
    char a [13][13] {{' ', ' ', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' '},
                     {' ', '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+'},
                     {'0', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
                     {'1', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ','|'},
                     {'2', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ','|'},
                     {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  ' ','|'},
                     {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  ' ','|'},
                     {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  ' ','|'},
                     {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  ' ','|'},
                     {'7', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  ' ','|'},
                    {'8', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  ' ','|'},
                    {'9', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  ' ','|'},
                    {' ', '+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+'}};
    return a [b][c];
}
char ship(char a[][13], int b, int c, int d, int e) {
    for (int i = c; i <= e; i++) {
        for (int l = b; l <= d; l++) {
            a[l][i] = 'O';
        }
    }

}


int main() {
    char filed_player_1[13][13];
    char filed_player_2[13][13];
    for (int i = 0; i < 13; i++) {
        for (int l = 0; l < 13; l++) {
            filed_player_1[i][l] = field(i, l);
            filed_player_2[i][l] = field(i, l);
        }
    }
    int x, x_2, y, y_2, ships = 0;
    for (int i = 0; i < 15; i++) {


        do {
            std::cout << "Player number one, arrange your ships: \n";
            if (ships < 4) {
                std::cout << "Enter the coordinates of the single-deck ship: - x: \n";
                std::cin >> x;
                std::cout << "Enter the coordinates of the single-deck ship: - y: \n";
                std::cin >> y;
                filed_player_1[y + 2][x + 2] = 'O';
            }
            if (ships < 7) {
                std::cout << "Enter the initial coordinates of the two-deck ship: - x: \n";
                std::cin >> x;
                std::cout << "Enter the initial coordinates of the two-deck ship: - x: \n";
                std::cin >> x_2;
                std::cout << "Enter the final coordinates of the two-deck ship: - y: \n";
                std::cin >> y;
                std::cout << "Enter the final coordinates of the two-deck ship: - x: \n";
                std::cin >> y_2;
                filed_player_1[y + 2][x + 2] = ship(filed_player_1, y + 2, x + 2, y_2 + 2, x_2 + 2);
            }
            if (ships < 9) {
                std::cout << "Enter the initial coordinates of the two-deck ship: - x: \n";
                std::cin >> x;
                std::cout << "Enter the initial coordinates of the two-deck ship: - x: \n";
                std::cin >> x_2;
                std::cout << "Enter the final coordinates of the two-deck ship: - y: \n";
                std::cin >> y;
                std::cout << "Enter the final coordinates of the two-deck ship: - x: \n";
                std::cin >> y_2;
                filed_player_1[y + 2][x + 2] = ship(filed_player_1, y + 2, x + 2, y_2 + 2, x_2 + 2);
            }
            if (ships < 10) {
                std::cout << "Enter the initial coordinates of the two-deck ship: - x: \n";
                std::cin >> x;
                std::cout << "Enter the initial coordinates of the two-deck ship: - x: \n";
                std::cin >> x_2;
                std::cout << "Enter the final coordinates of the two-deck ship: - y: \n";
                std::cin >> y;
                std::cout << "Enter the final coordinates of the two-deck ship: - x: \n";
                std::cin >> y_2;
                filed_player_1[y + 2][x + 2] = ship(filed_player_1, y + 2, x + 2, y_2 + 2, x_2 + 2);
            }
        } while ((x && y && x_2 && y_2 < 0) || (x && y && x_2 && y_2 > 9));

        for (int t = 0; t < 13; t++) {
            for (int l = 0; l < 13; l++) {
                std::cout << filed_player_1[t][l] << " ";
            }
            std::cout << std::endl;
        }

    }

}