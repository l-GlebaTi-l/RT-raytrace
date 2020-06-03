int Game_Obj_Kill(int Number);            /// Number - глобальный номер элемента (номер при начале игры)
void Game_Obj_Add();                /// Проверить верность в игре через логи
void Game_Obj_Add(XYZ A, XYZ B, XYZ C, RGBF newColor);
DWORD WINAPI Player_Jump(LPVOID param);



int Game_Obj_Kill(int Number)            /// Number - глобальный номер элемента (номер при начале игры)
{
    cout << "Номер поражаемого объекта = " << Number << endl;
    if(Obj_Alive.n == 1){
        Obj_Alive.num[0] = -1;
        Obj_Alive.n = 0;
        cout << "Последний объект" << endl;
        return 0;                       /// Здесь можно выводить MessageBox об уничтожении всех объектов
    }
    else if(Obj_Alive.n > 1){
        Obj_Alive.num[Number] = Obj_Alive.num[Obj_Alive.n - 1];
        Obj_Alive.num[Obj_Alive.n - 1] = -1;
        Obj_Alive.n--;
        cout << "Нескольно объектов" << endl;
        return 1;
    }
    else if(Obj_Alive.n < 1){
        cout << "Ошибка, <1" << endl;
        return -1;
    }
    cout << "Ошибка -3" << endl;
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

void Game_Obj_Add(XYZ A, XYZ B, XYZ C, RGBF newColor)                /// Проверить верность в игре через логи
{
    Obj New;
    New.Objj_create(A, B, C, newColor);
    New.Radius = Radius_finder(&New);
    New.Radius *=  1.732;
    All_Obj[Obj_N] = New;
    Obj_Alive.num[Obj_Alive.n] = Obj_N;
    Obj_Alive.n++;
    Obj_N++;
}

DWORD WINAPI Player_Jump(LPVOID param)
{
    double jump = 0.05;
    XYZ Noga;
    Noga = Person_Position;
    Noga.z -= 1;
    while(jump > 0){
        tPerson_Position.z += jump;
        jump -= 0.002;
        Sleep(30);
    }
    Noga = Person_Position;
    Noga.z -= 1;
//    cout << "Теперь вниз" << endl;
//    while(result = Ray_Tracing_For_Jump(World_Floor, Noga, OZ) > 0){
//        cout << "Высота до пола: " << result << endl;
//        tPerson_Position.z -= jump;
//        jump += 0.002;
//        Sleep(30);
//        Noga = Person_Position;
//        Noga.z -= 1;
//        cout << "DOWN";
//    }
//    tPerson_Position.z -= jump;
    PARAM_Jump = 0;
    return 0;
}

void Player_Physics_Fall();

DWORD WINAPI Player_Physics(LPVOID param)
{
    XYZ OZ = {0,0,-1};
    XYZ Noga;
    Noga = tPerson_Position;
    Noga.z -= 1;
    while(f_exit != 27){
        Noga = tPerson_Position;
        Noga.z -= 1;
        while((tPerson_Position.z > Ray_Tracing_For_Stand(World_Floor, Noga, OZ) + 1.01) || (tPerson_Position.z < Ray_Tracing_For_Stand(World_Floor, Noga, OZ) + 0.99)){
            PARAM_Fall = 1;
            Noga = tPerson_Position;
            Noga.z -= 1;
            Player_Physics_Fall();
        }
        PARAM_Fall = 0;
        Sleep(10);
    }
    return 0;
}

void Player_Physics_Fall()
{
    XYZ OZ = {0,0,-1};
    XYZ Noga;
    Noga = tPerson_Position;
    Noga.z -= 1;
    double dfall = 0.001;
    while(Ray_Tracing_For_Go(World_Floor, Noga, OZ) != 0){
        tPerson_Position.z -= dfall;
        Noga = tPerson_Position;
        Noga.z -= 1;
        dfall += 0.002;
        Sleep(30);
    }
    tPerson_Position.z = Ray_Tracing_For_Stand(World_Floor, Noga, OZ) + 1;
}

DWORD WINAPI Player_Go(LPVOID param)
{
    XYZ OZ = {0,0,-1};
    XYZ Noga;
    Noga = tPerson_Position;
    Noga.z -= 1;
    tPerson_Position.x += (Person_Napr.x/3);
    tPerson_Position.y += (Person_Napr.y/3);
    Noga = tPerson_Position;
    Noga.z -= 1;
    double dfall = 0.001;
    auto time_was = steady_clock::now();
    auto time_now = steady_clock::now();
    auto time_spend = duration_cast<milliseconds>(time_now - time_was);
    int tIAI = IAI;
    while(Ray_Tracing_For_Go(World_Floor, Noga, OZ) != 0){
        if(IAI > tIAI){
            time_now = steady_clock::now();
            time_spend = duration_cast<milliseconds>(time_now - time_was);
            tPerson_Position.z -= (dfall)*(time_spend.count())/1000;
            Noga = tPerson_Position;
            Noga.z -= 1;
            dfall += 0.002;
            time_was = time_now;
            tIAI = IAI;
        }
        else{
            Sleep(1);
        }
    }
    tPerson_Position.z = Ray_Tracing_For_Stand(World_Floor, Noga, OZ) + 1;
    return 0;
}

DWORD WINAPI Player_Went_Forward(LPVOID param)
{
    auto time_was = steady_clock::now();
    auto time_now = steady_clock::now();
    auto time_spend = duration_cast<milliseconds>(time_now - time_was);
    int tIAI = IAI;
    while(PARAM_Go_Forward == 1){
        if(IAI > tIAI){
            time_now = steady_clock::now();
            time_spend = duration_cast<milliseconds>(time_now - time_was);
            tPerson_Position.x += (Person_Speed) * (Person_Napr.x)*(time_spend.count())/1000;
            tPerson_Position.y += (Person_Speed) * (Person_Napr.y)*(time_spend.count())/1000;
            time_was = time_now;
            tIAI = IAI;
        }
        else{
            Sleep(1);
        }
    }
    return 0;
}

DWORD WINAPI Player_Went_Back(LPVOID param)
{
    auto time_was = steady_clock::now();
    auto time_now = steady_clock::now();
    auto time_spend = duration_cast<milliseconds>(time_now - time_was);
    int tIAI = IAI;
    while(PARAM_Go_Back == 1){
        if(IAI > tIAI){
            time_now = steady_clock::now();
            time_spend = duration_cast<milliseconds>(time_now - time_was);
            tPerson_Position.x -= (Person_Speed) * (Person_Napr.x)*(time_spend.count())/1000;
            tPerson_Position.y -= (Person_Speed) * (Person_Napr.y)*(time_spend.count())/1000;
            time_was = time_now;
            tIAI = IAI;
        }
        else{
            Sleep(1);
        }
    }
    return 0;
}

DWORD WINAPI Player_Went_Left(LPVOID param)
{
    auto time_was = steady_clock::now();
    auto time_now = steady_clock::now();
    auto time_spend = duration_cast<milliseconds>(time_now - time_was);
    int tIAI = IAI;
    while(PARAM_Go_Left == 1){
        if(IAI > tIAI){
            time_now = steady_clock::now();
            time_spend = duration_cast<milliseconds>(time_now - time_was);
            tPerson_Position.x -= (Person_Speed) * (Person_Napr.y)*(time_spend.count())/1000;
            tPerson_Position.y += (Person_Speed) * (Person_Napr.x)*(time_spend.count())/1000;
            time_was = time_now;
            tIAI = IAI;
        }
        else{
            Sleep(1);
        }
    }
    return 0;
}

DWORD WINAPI Player_Went_Right(LPVOID param)
{
    auto time_was = steady_clock::now();
    auto time_now = steady_clock::now();
    auto time_spend = duration_cast<milliseconds>(time_now - time_was);
    int tIAI = IAI;
    while(PARAM_Go_Right == 1){
        if(IAI > tIAI){
            time_now = steady_clock::now();
            time_spend = duration_cast<milliseconds>(time_now - time_was);
            tPerson_Position.x += (Person_Speed) * (Person_Napr.y)*(time_spend.count())/1000;
            tPerson_Position.y -= (Person_Speed) * (Person_Napr.x)*(time_spend.count())/1000;
            time_was = time_now;
            tIAI = IAI;
        }
        else{
            Sleep(1);
        }
    }
    return 0;
}
