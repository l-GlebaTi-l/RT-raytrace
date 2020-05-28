#include "prints.h"

void Otladchik()
{
    std::cout << "�������� � ������: " << Obj_N << " ����� ��������: " << Obj_Alive.n;
//    std::cout << " ������:" << std::endl;
//    for(int i = 0; i < Obj_Alive.n; i++)
//        std::cout << Obj_Alive.num[i] << " ";
    std::cout << std::endl << "�������� �� �����: " << Obj_On_Scene.n;
    if(syncronize_parameter == -1)
        std::cout << "������������ ������������� ���������" << std::endl;
    else std::cout << "������������ ������������� ��������" << std::endl;
    XYZ proeczia_Person_dEYE;
    double alpha;
    proeczia_Person_dEYE = Person_dEYE;
    proeczia_Person_dEYE.z = 0;
    alpha = vector_ygol(proeczia_Person_dEYE,Person_dEYE);
    std::cout << "����������� ������ = " << Eye_to_Monitor << std::endl;
    std::cout << "���� ������� ������ (� ��������) = " << ((acos(alpha)/Pi)*180) << std::endl;
    std::cout << "����� � ������ ����: ";
    TIMENOW = steady_clock::now();
    TIMESPEND = duration_cast<milliseconds>(TIMENOW - TIMESTART);
    std::cout << TIMESPEND.count() << std::endl;
    std::cout << "������� FPS: " << ((IAI*1000)/(TIMESPEND.count())) << std::endl;
}

void obj_print(Obj A_Obj)
{
    for (int i = 0; i < A_Obj.num_meshs; i++){
        std::cout << "Mesh " << i+1 << " is:" << std::endl;
        vector_print(A_Obj.B[i].A);
        vector_print(A_Obj.B[i].B);
        vector_print(A_Obj.B[i].C);
        std::cout << std::endl;
    }
}

void CLR_CNS(HANDLE hOut)
{
    COORD CLEAN_CONSOLE = {0, 0};
//    CLEAN_CONSOLE.X = 0;
//    CLEAN_CONSOLE.Y = 0;
    SetConsoleCursorPosition(hOut,
                            CLEAN_CONSOLE);
    for(int i = 0; i < 60; i++){
        for(int j = 0; j < 10; j++)
            std::cout << "\t\t\t\t";
    }
    SetConsoleCursorPosition(hOut,
                            CLEAN_CONSOLE);
}





