#include "gameplay.h"

int Game_Obj_Kill(int Number)            /// Number - глобальный номер элемента (номер при начале игры)
{
    std::cout << "Номер поражаемого объекта = " << Number << std::endl;
    if(Obj_Alive.n == 1){
        Obj_Alive.num[0] = -1;
        Obj_Alive.n = 0;
        std::cout << "Последний объект" << std::endl;
        return 0;                       /// Здесь можно выводить MessageBox об уничтожении всех объектов
    }
    else if(Obj_Alive.n > 1){
        Obj_Alive.num[Number] = Obj_Alive.num[Obj_Alive.n - 1];
        Obj_Alive.num[Obj_Alive.n - 1] = -1;
        Obj_Alive.n--;
        std::cout << "Нескольно объектов" << std::endl;
        return 1;
    }
    else if(Obj_Alive.n < 1){
        std::cout << "Ошибка, <1" << std::endl;
        return -1;
    }
    std::cout << "Ошибка -3" << std::endl;
    return -3;
}

void Game_Obj_Add()                /// Проверить верность в игре через логи
{
    Obj New;
    New.Objj_create();
    All_Obj[Obj_N] = New;
    Obj_Alive.num[Obj_Alive.n] = Obj_N;
    Obj_Alive.n++;
    Obj_N++;
}




