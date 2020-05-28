void Otladchik();
void obj_print(Obj A_Obj);
void CLR_CNS(HANDLE hOut);



void Otladchik()
{
    cout << "�������� � ������: " << Obj_N << " ����� ��������: " << Obj_Alive.n;
//    cout << " ������:" << endl;
//    for(int i = 0; i < Obj_Alive.n; i++)
//        cout << Obj_Alive.num[i] << " ";
    cout << endl << "�������� �� �����: " << Obj_On_Scene.n;
    if(syncronize_parameter == -1)
        cout << "������������ ������������� ���������" << endl;
    else cout << "������������ ������������� ��������" << endl;
    XYZ proeczia_Person_dEYE;
    double alpha;
    proeczia_Person_dEYE = Person_dEYE;
    proeczia_Person_dEYE.z = 0;
    alpha = vector_ygol(proeczia_Person_dEYE,Person_dEYE);
    cout << "����������� ������ = " << Eye_to_Monitor << endl;
    cout << "���� ������� ������ (� ��������) = " << ((acos(alpha)/Pi)*180) << endl;
    cout << "����� � ������ ����: ";
    TIMENOW = steady_clock::now();
    TIMESPEND = duration_cast<milliseconds>(TIMENOW - TIMESTART);
    cout << TIMESPEND.count() << endl;
    cout << "������� FPS: " << ((IAI*1000)/(TIMESPEND.count())) << endl;
    cout << "���������� ���������: " << Person_Position.x << " " << Person_Position.y << " " << Person_Position.z << endl;
    cout << "����������� ���������: " << Person_Napr.x << " " << Person_Napr.y << " " << Person_Napr.z << endl;

    cout << endl;
}

void obj_print(Obj A_Obj)
{
    for (int i = 0; i < A_Obj.num_meshs; i++){
        cout << "Mesh " << i+1 << " is:" << endl;
        vector_print(A_Obj.B[i].A);
        vector_print(A_Obj.B[i].B);
        vector_print(A_Obj.B[i].C);
        cout << endl;
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
            cout << "\t\t\t\t";
    }
    SetConsoleCursorPosition(hOut,
                            CLEAN_CONSOLE);
}





