#include <iostream>

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
    bool good = true, player_2 = false, got = true;

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
        do {
            good = true, got = true;
            if (player_2) {
                std::cout << "Player number two, your turn:. Enter the firing coordinates:\n";
            } else {
                std::cout << "Player number one, your turn. Enter the firing coordinates:\n";
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
                } else {
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
            if (field_fire_p1[y + 2][x + 2] || field_fire_p2[y + 2][x + 2] == 'X') {
                std::cout << "You've already shot there!\n";
                good = false;
            }
        }while ((x < 0 || y < 0 || x > 9 || y > 9) && !good);

    if (player_2) {
        field_fire_p2[y + 2][x + 2] = 'X';
    }else {
        field_fire_p1[y + 2][x + 2] = 'X';
    }
    if (player_2) {
        if (filed_player_1[y + 2][x + 2] == 'O') {
            filed_player_1[y + 2][x + 2] = 'X';
            std::cout << "Got!!!\n";
            if (filed_player_1[y + 1][x + 1] != 'O' &&  filed_player_1[y + 1][x + 2] != 'O' &&  filed_player_1[y + 1][x + 3] != 'O' &&
                    filed_player_1[y + 2][x + 1] != 'O' &&  filed_player_1[y + 2][x + 3] != 'O' && filed_player_1[y + 3][x + 1] != 'O' &&
                    filed_player_1[y + 3][x + 2] != 'O' && filed_player_1[y + 3][x + 3] != 'O') {
                std::cout << "Killed!!!\n";
            }
        }else {
            filed_player_1[y + 2][x + 2] = 'X';
            std::cout << "Miss!\n";
            got = false;
        }
    }
    else if (filed_player_2[y + 2][x + 2] == 'O') {
            filed_player_2[y + 2][x + 2] = 'X';
            std::cout << "Got!!!\n";
            if (filed_player_2[y + 1][x + 1] != 'O' &&  filed_player_2[y + 1][x + 2] != 'O' &&  filed_player_2[y + 1][x + 3] != 'O' &&
                filed_player_2[y + 2][x + 1] != 'O' &&  filed_player_2[y + 2][x + 3] != 'O' && filed_player_2[y + 3][x + 1] != 'O' &&
                filed_player_2[y + 3][x + 2] != 'O' && filed_player_2[y + 3][x + 3] != 'O') {
                std::cout << "Killed!!!\n";
            }
        }else {
            filed_player_2[y + 2][x + 2] = 'X';
            std::cout << "Miss!\n";
            got = false;
        }
       int count = 0;
        for (int vic = 0; vic < 13; vic ++) {
            for (int tory = 0; tory < 13; tory++) {
                if (player_2) {
                    if (filed_player_1[tory][vic] == 'O') {
                        count++;
                    }
                }else {
                    if (filed_player_2[tory][vic] == 'O') {
                        count++;
                    }
                }
            }
        }
        if (player_2 && count == 0) {
            std::cout << "Player two WIN!!!";
            return 0;
        }else if (count == 0) {
            std::cout << "Player one WIN!!!";
            return 0;
        }

    if (player_2 && !got) {
        player_2 = false;
    }else if (!got) {
        player_2 = true;
    }
    }
}