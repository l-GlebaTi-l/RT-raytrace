#include "gameplay.h"

int Game_Obj_Kill(int Number)            /// Number - ���������� ����� �������� (����� ��� ������ ����)
{
    std::cout << "����� ����������� ������� = " << Number << std::endl;
    if(Obj_Alive.n == 1){
        Obj_Alive.num[0] = -1;
        Obj_Alive.n = 0;
        std::cout << "��������� ������" << std::endl;
        return 0;                       /// ����� ����� �������� MessageBox �� ����������� ���� ��������
    }
    else if(Obj_Alive.n > 1){
        Obj_Alive.num[Number] = Obj_Alive.num[Obj_Alive.n - 1];
        Obj_Alive.num[Obj_Alive.n - 1] = -1;
        Obj_Alive.n--;
        std::cout << "��������� ��������" << std::endl;
        return 1;
    }
    else if(Obj_Alive.n < 1){
        std::cout << "������, <1" << std::endl;
        return -1;
    }
    std::cout << "������ -3" << std::endl;
    return -3;
}

void Game_Obj_Add()                /// ��������� �������� � ���� ����� ����
{
    Obj New;
    New.Objj_create();
    All_Obj[Obj_N] = New;
    Obj_Alive.num[Obj_Alive.n] = Obj_N;
    Obj_Alive.n++;
    Obj_N++;
}




