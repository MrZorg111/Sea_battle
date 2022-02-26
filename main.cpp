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


int main() {
    char filed_player_1[13][13];
    char filed_player_2[13][13];
    for (int i = 0; i < 13; i++) {
        for (int l = 0; l < 13; l++) {
            filed_player_1[i][l] = field(i, l);
            filed_player_2[i][l] = field(i, l);
        }
    }
    int x, tempo_x, y, tempo_y, ships = 0, deck = 2;
    bool good = true, player_2 = false;

    for (int i = 0; i < 11; i++) {
        if (i == 10) {
            player_2 = true;
            i = 0;
            ships = 0;
            deck = 2;
        }
        do {
            good = true;
            if (player_2) {
                std::cout << "Player number two, arrange your ships: \n";
            }
            else {
                std::cout << "Player number one, arrange your ships: \n";
            }
            std::cout << "Enter the coordinates of the first-deck ship: - x: \n";
            std::cin >> x;
            std::cout << "Enter the coordinates of the first-deck ship: - y: \n";
            std::cin >> y;
            if (player_2) {
                if (filed_player_2[y + 2][x + 2] == 'O') {
                    std::cout << "The ship intersects the coordinates of another ship, please rearrange it!\n";
                    good = false;
                }
            }else {
                if (filed_player_1[y + 2][x + 2] == 'O') {
                    std::cout << "The ship intersects the coordinates of another ship, please rearrange it!\n";
                    good = false;
                }
            }
            if (ships > 3 && ships < 10) {

                tempo_x = x, tempo_y = y;
                std::cout << "Enter the final coordinates of the " << deck << "-deck ship: - x: \n";
                std::cin >> x;
                std::cout << "Enter the final coordinates of the " << deck << "-deck ship: - y: \n";
                std::cin >> y;
                if ((x - tempo_x != deck - 1) && (y - tempo_y != deck - 1)) {
                    std::cout << "The size of the ship is set incorrectly!\n";
                    good = false;
                }
            }
            if (y == tempo_y) {
                for (int w = tempo_x; w <= x; w++) {
                    if (player_2) {
                        if (filed_player_2[y + 2][w + 2] == 'O') {
                            std::cout << "The ship intersects the coordinates of another ship, please rearrange it!\n";
                            good = false;
                        }
                    }else {
                        if (filed_player_1[y + 2][w + 2] == 'O') {
                            std::cout << "The ship intersects the coordinates of another ship, please rearrange it!\n";
                            good = false;
                        }
                    }
                }
            }
            else if (x == tempo_x) {
                for (int e = tempo_y; e <= y; e++) {
                    if (player_2) {
                        if (filed_player_2[e + 2][x + 2] == 'O') {
                            std::cout << "The ship intersects the coordinates of another ship, please rearrange it!\n";
                            good = false;
                        }
                    }else {
                        if (filed_player_1[e + 2][x + 2] == 'O') {
                            std::cout << "The ship intersects the coordinates of another ship, please rearrange it!\n";
                            good = false;
                        }
                    }
                }
            }
            }while ((x || y || tempo_x || tempo_y < 0) && (x || y || tempo_x || tempo_y > 9) && !good);
            if (ships < 4) {
                if (player_2) {
                    filed_player_2[y + 2][x + 2] = 'O';
                    }else {
                    filed_player_1[y + 2][x + 2] = 'O';
                }
            }
            else if (y == tempo_y) {
                for (int u = tempo_x; u <= x; u++) {
                    if (player_2) {
                        filed_player_2[y + 2][u + 2] = 'O';
                    }else {
                        filed_player_1[y + 2][u + 2] = 'O';
                    }
                }
            }
            else if (x == tempo_x) {
                for (int l = tempo_y; l <= y; l++) {
                    if (player_2) {
                        filed_player_2[l + 2][x + 2] = 'O';
                        }else {
                        filed_player_1[l + 2][x + 2] = 'O';
                    }
                }
             }
            std::cout << ships << " \n";
            for (int t = 0; t < 13; t++) {
                for (int l = 0; l < 13; l++) {
                    if (player_2) {
                        std::cout << filed_player_2[t][l] << " ";
                    }else {
                        std::cout << filed_player_1[t][l] << " ";
                    }
                }
                std::cout << std::endl;
            }
            if (player_2 && deck == 4) {
                break;
            }
            ships++;
            if (ships == 7 || ships == 9) {
            deck += 1;
            }

    }
    std::cout << "\t\t\tStart Game!\n";
    char field_fire_p1[13][13];
    char field_fire_p2[13][13];
    for (int i = 0; i < 13; i++) {
        for (int l = 0; l < 13; l++) {
            field_fire_p1[i][l] = field(i, l);
            field_fire_p2[i][l] = field(i, l);
        }
    }
    player_2 = false;
    for (int g = 0; ; g++) {
        if (player_2){
            std::cout << "Player number two, you start first. Enter the firing coordinates:\n";
        }else {
            std::cout << "Player number one, you start first. Enter the firing coordinates:\n";
        }
        for (int f = 0; f < 13; f++) {
            if (player_2) {
                for (int a = 0; a < 13; a++) {
                    std::cout << filed_player_2[f][a] << " ";
                }
                std::cout << "\t\t\t";
                for (int a_2 = 0; a_2 < 13; a_2++) {
                    std::cout << field_fire_p2[f][a_2] << " ";
                }
            }
            else {
                for (int a = 0; a < 13; a++) {
                    std::cout << filed_player_1[f][a] << " ";
                }
                std::cout << "\t\t\t";
                for (int a_2 = 0; a_2 < 13; a_2++) {
                    std::cout << field_fire_p1[f][a_2] << " ";
                }
            }
            std::cout << std::endl;
        }
    std::cout << "Enter the x coordinate:\n";
    std::cin >> x;
    std::cout << "Enter the y coordinate:\n";
    std::cin >> y;

    if (player_2) {
        field_fire_p2[y + 2][x + 2] = 'X';
    }else {
        field_fire_p1[y + 2][x + 2] = 'X';
    }





    }
}