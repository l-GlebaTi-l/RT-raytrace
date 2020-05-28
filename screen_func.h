int Obj_On_Screen(int num);  /// сделать два алгоритма, когда sinObz == sinObz и != (см в тетрадь)
Obj_Numeration Screen_Objects();
DWORD WINAPI Screen_Pixels_All(LPVOID param);
//DWORD WINAPI Screen_Pixels_Drevo(void* param);
int Ray_Tracing_For_Picture(int Obj_Num, XYZ O, XYZ OV);   /// Определение пересечения прямой и треугольника
int Ray_Tracing_For_Deefolt(Obj Floor, XYZ O, XYZ OV);
int Ray_Tracing_For_Picture_Obvod(int Obj_Num, XYZ O, XYZ V);   /// Определение пересечения прямой и треугольника

void InGame_PixelsPloskiy();
DWORD WINAPI PixPl_Drevo(void* param);
void recursy(int j, int i, int dj, int di, Obj_Numeration_rec_Mass msObj); /// j i - начало блока в пикселях, dj di - размер блока, msObj - объекты в блоке

void InGame_PixelsPloskiy_With_Floor();
DWORD WINAPI PixPl_Drevo_With_Floor(void* param);
void recursy_With_Floor(int j, int i, int dj, int di, Obj_Numeration_rec_Mass msObj);

void recursy_light(int j, int i, int dj, int di, Obj_Numeration_rec_Mass msObj);
void recursy_fonarick(int j, int i, int dj, int di, Obj_Numeration_rec_Mass msObj);
void recursy_optimization(int j, int i, int dj, int di, Obj_Numeration_rec_Mass msObj);


int Obj_On_Screen(int num)  /// сделать два алгоритма, когда sinObz == sinObz и != (см в тетрадь)
{
    double sinA, sinS;
    double OSi;
    XYZ OS;
    XYZ TempPos;
    TempPos = All_Obj[num].Position;
    OS = o_vector(Person_Position,TempPos);
    OSi = vector_module(OS);

    OS = vector_ration(OS);
    sinA = vector_SP(OS,Person_dEYE);

    sinS = All_Obj[num].Radius/OSi;

    if((sinA + sinS) > sinObz1){            /// В комментарии код для дерева (ОН ТО И ДЕЛИТ ЭКРАН ПОПОЛАМ, УРАААА!!!!!)
//        double cosEpS;
//        cosEpS = vector_SP(Person_dEYE_Perp,OS);
//        if(cosEpS > 0)                        // благодаря этому, дерево будет практически состоять из квадратов, это хорошооо!
//            return -1;          // На правой части экрана
//        else if(cosEpS < 0)
//            return 1;           // На левой части экрана
//        else
//            return 1;           /// Возможно, нужно задать другой номер (середина как никак)
//        double sinAv
        return 1;
    }
    else
        return 0;
    return -2;              // если программа сломалась
}

Obj_Numeration Screen_Objects()
{
    Obj_Numeration Obj_Yes;
//    Obj_Yes.num = new int [Obj_Alive.n];
//    Obj_Yes.OSi = new double [Obj_Alive.n];
//    Obj_Yes.OS = new XYZ [Obj_Alive.n];
    for(int i = 0; i < Obj_Alive.n; i++){
        if(Obj_On_Screen(Obj_Alive.num[i]) == 1){
            Obj_Yes.num[Obj_Yes.n] = Obj_Alive.num[i];
            Obj_Yes.n++;
        }
    }
    return Obj_Yes;
}

DWORD WINAPI Screen_Pixels_All(LPVOID param)
{
    int thr_num = (int)param;
//    cout << thr_num;
//    GDM_Picture[i][j];
//    Person_Position;
//    Person_dEYE;
//    cout << "Scr_Pix1" << endl;
//    while(Picture_Complited1==1){Sleep(1);}
//    cout << "Scr_Pix1in" << endl;
    int RES1 = 1, RES2 = 0;
/*
    double sinA, cosAii, sinS, cosEpS;
    double OSi;
    XYZ OS;
    XYZ tGD;
    XYZ Z = {0,0,1};
    XYZ tDM;
*/
//    Scene_Obj_Nomera = ;
    if(syncronize_parameter == 1)
        while(Picture_Complited[thr_num] != 0)            /// вертикальная синхронизация!!!!!!!!!!
            Sleep(1);
    RES1 = Obj_On_Scene.n;
    if(RES1 > 0){
        for(int i = Thr_Param[thr_num]; i < Thr_Param[thr_num+1]; i++)
        {
            for(int j = 0; j < resolution.shirina; j++)
            {
                for(int k = 0; k < Obj_On_Scene.n; k++)
                {
//                    if(Shar_i_OV(All_Obj[Obj_Alive.num[k]].Radius, All_Obj[Obj_Alive.num[k]].Position, Person_Position, GDM_Picture[i][j]) == 1)
//                    {
/*
                    tDM = o_vector(Person_Position,GDM_Picture[i][j]);
                    tDM = vector_ration(tDM);
                    OS = o_vector(Person_Position,All_Obj[Obj_On_Scene.num[k]].Position);
                    OSi = vector_module(OS);
                    tGD = vector_perp(tDM,Z);
                    OS = vector_ration(OS);
                    sinA = vector_SP(OS,tDM);

                    sinS = All_Obj[Obj_On_Scene.num[k]].Radius/OSi;


                    if((sinA + sinS) > 1){
*/

                        RES2 = Ray_Tracing_For_Picture(Obj_On_Scene.num[k], Person_Position, GDM_Picture[i][j]);
                        if(RES2 == 1){
                            pixels[i*resolution.shirina*4+j*4] = All_Obj[Obj_On_Scene.num[k]].Color.b;
                            pixels[i*resolution.shirina*4+j*4+1] = All_Obj[Obj_On_Scene.num[k]].Color.g;
                            pixels[i*resolution.shirina*4+j*4+2] = All_Obj[Obj_On_Scene.num[k]].Color.r;
                            pixels[i*resolution.shirina*4+j*4+3] = All_Obj[Obj_On_Scene.num[k]].Color.f;
                            break;
                        }
                        if(PARAM_Obvod == 1){
                            RES2 = Ray_Tracing_For_Picture_Obvod(Obj_On_Scene.num[k], Person_Position, GDM_Picture[i][j]);
                            if(RES2 == 1){
                                pixels[i*resolution.shirina*4+j*4] = 15;
                                pixels[i*resolution.shirina*4+j*4+1] = 15;
                                pixels[i*resolution.shirina*4+j*4+2] = 15;
                                pixels[i*resolution.shirina*4+j*4+3] = 0;
                                break;
                            }
                        }                               /// Функция обвода изображения, можно убрать
/*                    }
                    else RES2 = 0;*/
                }

                if(RES2 == 0){
                    if((GDM_Picture[i][j].z) > 0){
                        pixels[i*resolution.shirina*4+j*4] = 220;
                        pixels[i*resolution.shirina*4+j*4+1] = 50;
                        pixels[i*resolution.shirina*4+j*4+2] = 10;
                        pixels[i*resolution.shirina*4+j*4+3] = 0;
                    }
                    else{
                        pixels[i*resolution.shirina*4+j*4] = 20;
                        pixels[i*resolution.shirina*4+j*4+1] = 5;
                        pixels[i*resolution.shirina*4+j*4+2] = 50;
                        pixels[i*resolution.shirina*4+j*4+3] = 0;
                    }
                }
                if(RES2 == -1)
                    f_exit = 27;
                RES2 = 0;

            }
        }
    }
    if(RES1 == 0){
        for(int i = Thr_Param[thr_num]; i < Thr_Param[thr_num+1]; i++){
            for(int j = 0; j < resolution.shirina; j++){
                    if((GDM_Picture[i][j].z) > 0){
                        pixels[i*resolution.shirina*4+j*4] = 220;
                        pixels[i*resolution.shirina*4+j*4+1] = 50;
                        pixels[i*resolution.shirina*4+j*4+2] = 10;
                        pixels[i*resolution.shirina*4+j*4+3] = 0;
                    }
                else{
                    pixels[i*resolution.shirina*4+j*4] = 20;
                    pixels[i*resolution.shirina*4+j*4+1] = 5;
                    pixels[i*resolution.shirina*4+j*4+2] = 50;
                    pixels[i*resolution.shirina*4+j*4+3] = 0;
                }
            }
        }
    }
    if(RES1 == -1)
        f_exit = 27;
    Picture_Complited[thr_num] = 1;
//    cout << "Exited";
    return 0;
}

int Ray_Tracing_For_Picture(int Obj_Num, XYZ O, XYZ OV)   /// Определение пересечения прямой и треугольника
{
//    Obj* D_Obj = (Obj*) pD_Obj;
    XYZ Peres;
    double D, mu;
    double alphaAB, alphaBC, alphaCA;
    double tL;
    XYZ PA, PB, PC;
//    XYZ VO;
    int i = 0;
    int PERESECH = -1;

    while(PERESECH!=1){
///                     Точка пересечения
//        XYZ OV, VO;
//        OV.x = V.x - O.x;
//        VO.x = -OV.x;
//        OV.y = V.y - O.y;
//        VO.y = -OV.y;
//        OV.z = V.z - O.z;
//        VO.z = -OV.z;

        PA = All_Obj[Obj_Num].B[i].A;
        PB = All_Obj[Obj_Num].B[i].n;
        D = PB.x*PA.x + PB.y*PA.y + PB.z*PA.z;
        D *= -1;
        mu = ( D + PB.x*O.x + PB.y*O.y + PB.z*O.z ) / -( PB.x*OV.x + PB.y*OV.y + PB.z*OV.z );
        Peres.x = O.x + OV.x*mu;
        Peres.y = O.y + OV.y*mu;
        Peres.z = O.z + OV.z*mu;
    //    vector_print(Peres);
    ///                     Проверка пересечения с треугольником

        PA.x = PA.x - Peres.x;
        PA.y = PA.y - Peres.y;
        PA.z = PA.z - Peres.z;

        PB.x = All_Obj[Obj_Num].B[i].B.x - Peres.x;
        PB.y = All_Obj[Obj_Num].B[i].B.y - Peres.y;
        PB.z = All_Obj[Obj_Num].B[i].B.z - Peres.z;

        PC.x = All_Obj[Obj_Num].B[i].C.x - Peres.x;
        PC.y = All_Obj[Obj_Num].B[i].C.y - Peres.y;
        PC.z = All_Obj[Obj_Num].B[i].C.z - Peres.z;

    //    PA = vector_ration(PA);
//        tL = SqrtInv(PA.x*PA.x + PA.y*PA.y + PA.z*PA.z);
//        tL = 1 / tL;
//        tL = Q_rsqrt2E(PA.x*PA.x + PA.y*PA.y + PA.z*PA.z);
        tL = SqrtInvE(PA.x*PA.x + PA.y*PA.y + PA.z*PA.z);
        PA.x = PA.x*tL;
        PA.y = PA.y*tL;
        PA.z = PA.z*tL;
    //    PB = vector_ration(PB);
//        tL = SqrtInv(PB.x*PB.x + PB.y*PB.y + PB.z*PB.z);
//        tL = 1 / tL;
//        tL = Q_rsqrt2E(PB.x*PB.x + PB.y*PB.y + PB.z*PB.z);
        tL = SqrtInvE(PB.x*PB.x + PB.y*PB.y + PB.z*PB.z);
        PB.x = PB.x*tL;
        PB.y = PB.y*tL;
        PB.z = PB.z*tL;
    //    PC = vector_ration(PC);
//        tL = SqrtInv(PC.x*PC.x + PC.y*PC.y + PC.z*PC.z);
//        tL = 1 / tL;
//        tL = Q_rsqrt2E(PC.x*PC.x + PC.y*PC.y + PC.z*PC.z);
        tL = SqrtInvE(PC.x*PC.x + PC.y*PC.y + PC.z*PC.z);
        PC.x = PC.x*tL;
        PC.y = PC.y*tL;
        PC.z = PC.z*tL;
        alphaAB = PA.x*PB.x + PA.y*PB.y + PA.z*PB.z;
        alphaBC = PB.x*PC.x + PB.y*PC.y + PB.z*PC.z;
        alphaCA = PC.x*PA.x + PC.y*PA.y + PC.z*PA.z;

//        alphaAB = acos(alphaAB);
//        alphaBC = acos(alphaBC);
//        alphaCA = acos(alphaCA);
        tL = alphaAB + alphaBC + alphaCA;

        i++;

//        if(tL <= (PiDva + 0.001) && tL >= (PiDva - 0.001)){
//            PERESECH = 1;
//            break;
//        }
        if(tL <= -1){
            PERESECH = 1;
            break;
        }
        if(i == All_Obj[Obj_Num].num_meshs){
            PERESECH = 0;
            break;
        }
    }
    return PERESECH; /// Так можно и так получится? Вопрос!                 !!!!!!!
}

int Ray_Tracing_For_Picture_Obvod(int Obj_Num, XYZ O, XYZ V)   /// Определение пересечения прямой и треугольника
{
//    Obj* D_Obj = (Obj*) pD_Obj;
    XYZ Peres;
    double D, mu;
    double alphaAB, alphaBC, alphaCA;
    double tL;
    XYZ PA, PB, PC;
    int i = 0;
    int PERESECH = -1;

    while(PERESECH!=1){
///                     Точка пересечения
        XYZ OV, VO;
        OV.x = V.x - O.x;
        VO.x = -OV.x;
        OV.y = V.y - O.y;
        VO.y = -OV.y;
        OV.z = V.z - O.z;
        VO.z = -OV.z;

        PA = All_Obj[Obj_Num].B[i].A;
        PB = All_Obj[Obj_Num].B[i].n;
        D = PB.x*PA.x + PB.y*PA.y + PB.z*PA.z;
        D *= -1;
        mu = ( D + PB.x*O.x + PB.y*O.y + PB.z*O.z ) / ( PB.x*VO.x + PB.y*VO.y + PB.z*VO.z );
        Peres.x = O.x + OV.x*mu;
        Peres.y = O.y + OV.y*mu;
        Peres.z = O.z + OV.z*mu;
    //    vector_print(Peres);
    ///                     Проверка пересечения с треугольником

        PA.x = PA.x - Peres.x;
        PA.y = PA.y - Peres.y;
        PA.z = PA.z - Peres.z;

        PB.x = All_Obj[Obj_Num].B[i].B.x - Peres.x;
        PB.y = All_Obj[Obj_Num].B[i].B.y - Peres.y;
        PB.z = All_Obj[Obj_Num].B[i].B.z - Peres.z;

        PC.x = All_Obj[Obj_Num].B[i].C.x - Peres.x;
        PC.y = All_Obj[Obj_Num].B[i].C.y - Peres.y;
        PC.z = All_Obj[Obj_Num].B[i].C.z - Peres.z;

    //    PA = vector_ration(PA);
        tL = SqrtInv(PA.x*PA.x + PA.y*PA.y + PA.z*PA.z);
        PA.x = PA.x/tL;
        PA.y = PA.y/tL;
        PA.z = PA.z/tL;
    //    PB = vector_ration(PB);
        tL = SqrtInv(PB.x*PB.x + PB.y*PB.y + PB.z*PB.z);
        PB.x = PB.x/tL;
        PB.y = PB.y/tL;
        PB.z = PB.z/tL;
    //    PC = vector_ration(PC);
        tL = SqrtInv(PC.x*PC.x + PC.y*PC.y + PC.z*PC.z);
        PC.x = PC.x/tL;
        PC.y = PC.y/tL;
        PC.z = PC.z/tL;
        alphaAB = PA.x*PB.x + PA.y*PB.y + PA.z*PB.z;
        alphaBC = PB.x*PC.x + PB.y*PC.y + PB.z*PC.z;
        alphaCA = PC.x*PA.x + PC.y*PA.y + PC.z*PA.z;

//        alphaAB = acos(alphaAB);
//        alphaBC = acos(alphaBC);
//        alphaCA = acos(alphaCA);
        tL = alphaAB + alphaBC + alphaCA;

        i++;

//        if(tL <= (PiDva + 0.001) && tL >= (PiDva - 0.001)){
//            PERESECH = 1;
//            break;
//        }
        if(tL <= -0.9 && tL >= -1.1){
            PERESECH = 1;
            break;
        }
        if(i == All_Obj[Obj_Num].num_meshs){
            PERESECH = 0;
            break;
        }
    }
    return PERESECH; /// Так можно и так получится? Вопрос!                 !!!!!!!
}

int Obj_On_Small_Screen(int num, double sinV1, double sinV2, XYZ dV)  /// сделать два алгоритма, когда sinObz == sinObz и != (см в тетрадь)
{
    double sinA, sinS;
    double OSi;
    XYZ OS;
    OS = o_vector(Person_Position,All_Obj[num].Position);
    OSi = vector_module(OS);

    OS = vector_ration(OS);
    sinA = vector_SP(OS,dV);

    sinS = All_Obj[num].Radius/OSi;

    if(((sinA + sinS) > sinV1) && ((sinA - sinS) < sinV2)){            /// В комментарии код для дерева (ОН ТО И ДЕЛИТ ЭКРАН ПОПОЛАМ, УРАААА!!!!!)
//        double cosEpS;
//        cosEpS = vector_SP(Person_dEYE_Perp,OS);
//        if(cosEpS > 0)                        // благодаря этому, дерево будет практически состоять из квадратов, это хорошооо!
//            return -1;          // На правой части экрана
//        else if(cosEpS < 0)
//            return 1;           // На левой части экрана
//        else
//            return 1;           /// Возможно, нужно задать другой номер (середина как никак)
//        double sinAv
        return 1;
    }
    else
        return 0;
    return -2;              // если программа сломалась
}

int Obj_On_Screen_RR(int num, Obj_Numeration_One &tempObjInf)  /// сделать два алгоритма, когда sinObz == sinObz и != (см в тетрадь), RR = Radius Return
{
    double sinA, sinS;
    double OSi;
    XYZ OS;
    XYZ TempPos;
    TempPos = All_Obj[num].Position;
    OS = o_vector(Person_Position,TempPos);
    OSi = vector_module(OS);

    OS = vector_ration(OS);
    sinA = vector_SP(OS,Person_dEYE);

    sinS = All_Obj[num].Radius/OSi;

    if((sinA + sinS) > sinObz1){            /// В комментарии код для дерева (ОН ТО И ДЕЛИТ ЭКРАН ПОПОЛАМ, УРАААА!!!!!)
        tempObjInf.num = num;
        tempObjInf.R = All_Obj[num].Radius;
        tempObjInf.OSi = OSi;
        tempObjInf.OnearS = OSi - tempObjInf.R;
        tempObjInf.sinOSi = sinS;
        tempObjInf.OS = OS;

        double cosEpS;
        cosEpS = vector_SP(Person_dEYE_Perp,OS);
        if(cosEpS > 0)                        // благодаря этому, дерево будет практически состоять из квадратов, это хорошооо!
            return 2;          // На правой части экрана
        else if(cosEpS <= 0)
            return 1;           // На левой части экрана
//        else
//            return 2;           /// Возможно, нужно задать другой номер (середина как никак)
//        double sinAv
    }
    else
        return 0;
    return -1;              // если программа сломалась
}

void Screen_Objects_RR(Obj_Numeration_Mass &Main_Scene_left, Obj_Numeration_Mass &Main_Scene_right)
{
    int storona;
    Obj_Numeration_One temp_Inf;
    for(int i = 0; i < Obj_Alive.n; i++)
        storona = Obj_On_Screen_RR(Obj_Alive.num[i], temp_Inf);
        if(storona == 1){
/*            Main_Scene.num[Obj_Yes.n] = Obj_Alive.num[i];*/      /// проверить, будет ли работать без этого
            Main_Scene_left.Obj[Main_Scene_left.n].num = temp_Inf.num;
            Main_Scene_left.Obj[Main_Scene_left.n].R = temp_Inf.R;
            Main_Scene_left.Obj[Main_Scene_left.n].OSi = temp_Inf.OSi;
            Main_Scene_left.Obj[Main_Scene_left.n].OnearS = temp_Inf.OnearS;
            Main_Scene_left.Obj[Main_Scene_left.n].sinOSi = temp_Inf.sinOSi;
            Main_Scene_left.Obj[Main_Scene_left.n].OS = temp_Inf.OS;
            Main_Scene_left.n++;
        }
        else if(storona == 2){
            Main_Scene_right.Obj[Main_Scene_right.n].num = temp_Inf.num;
            Main_Scene_right.Obj[Main_Scene_right.n].R = temp_Inf.R;
            Main_Scene_right.Obj[Main_Scene_right.n].OSi = temp_Inf.OSi;
            Main_Scene_right.Obj[Main_Scene_right.n].OnearS = temp_Inf.OnearS;
            Main_Scene_right.Obj[Main_Scene_right.n].sinOSi = temp_Inf.sinOSi;
            Main_Scene_right.Obj[Main_Scene_right.n].OS = temp_Inf.OS;
            Main_Scene_right.n++;
        }
}


/**
у меня есть i и j элемент, GDM, resolution,v/s, Block_Scene,
и из этого нужно сделать древо с пикселизацией...

ni -  горизонтальные направляющие, определяющие ВЕРТИКАЛЬНЫЕ ПЛОСКОСТИ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
nj - вертикальные направляющие, определяющие ГОРИЗОНТАЛЬНЫЕ ПЛОСКОСТИ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

сделать инициальзацию данных массивов вне GDM функции

 n.ni[0] = nil - n_left, n.ni[n.num_i - 1] = nir - n_right, n.nj[0] = njv - n_verhniy, n.nj[n.num_j - 1] = njn - n_nizhniy
 n.ni[n.num_i / 2] = nis = n_srednyaya
**/
void InGame_PixelsPloskiy()
{
    while(Picture_Complited_DrevoType != 0){} /// лучше его поместить непосредственно перед задачей пикселей
//        Sleep(1);
    XYZ nil, nir, njv, njn, nis;
    nil = vector_perp(Person_dEYE_Perp_Verh, GDM_Picture[resolution.vysota / 2][0]);
    nil = vector_ration(nil);
    nir = vector_perp(Person_dEYE_Perp_Verh, GDM_Picture[resolution.vysota / 2][resolution.shirina - 1]);
    nir = vector_ration(nir);
    njv = vector_perp(GDM_Picture[0][resolution.shirina / 2], Person_dEYE_Perp);
    njv = vector_ration(njv);
    njn = vector_perp(GDM_Picture[resolution.vysota - 1][resolution.shirina / 2], Person_dEYE_Perp);
    njn = vector_ration(njn);

    nis = vector_perp(Person_dEYE_Perp_Verh, GDM_Picture[resolution.vysota / 2][resolution.shirina / 2]);
    nis = vector_ration(nis);

    XYZ OS, OSn;
    double sinOSi, OSi;
    Obj_Numeration_Mass M_Sl, M_Sr;    // M_S = Main_Scene
    M_Sl.Obj = new Obj_Numeration_One[Obj_Alive.n];
    M_Sr.Obj = new Obj_Numeration_One[Obj_Alive.n];

    for(int i = 0; i < Obj_Alive.n; i++){
        OS = o_vector(Person_Position, All_Obj[Obj_Alive.num[i]].Position);
        OSn = vector_ration(OS);                                        /// OSn и vector_module вместить сюда, т.к. в них есть
        OSi = vector_module(OS);                                        /// повторяющиеся операции
        sinOSi = (All_Obj[Obj_Alive.num[i]].Radius / OSi);
//        cout << sinOSi;
//        cout << vector_module(nil);
        if((vector_SP(Person_dEYE, OSn) + sinOSi) >= 0){    /// проверка, находится ли объект перед нами или же он сзади нас
            if((vector_SP(nil, OSn) - sinOSi) <= 0){
                if((vector_SP(nir, OSn) + sinOSi) >= 0){
                    if((vector_SP(njv, OSn) - sinOSi) <= 0){
                        if((vector_SP(njn, OSn) + sinOSi) >= 0){  /// объект в "большом" блоке
                            /// проверка по серединной
                            if( (vector_SP(nis, OSn) - sinOSi  ) >= 0){    /// объект только слева
                                M_Sl.Obj[M_Sl.n].num = Obj_Alive.num[i];
                                M_Sl.Obj[M_Sl.n].OS = OS;
                                M_Sl.Obj[M_Sl.n].OSn = OSn;
                                M_Sl.Obj[M_Sl.n].OSi = OSi;
                                M_Sl.Obj[M_Sl.n].R = All_Obj[Obj_Alive.num[i]].Radius;
                                M_Sl.Obj[M_Sl.n].sinOSi = sinOSi;
                                M_Sl.Obj[M_Sl.n].OnearS = M_Sl.Obj[M_Sl.n].sinOSi - M_Sl.Obj[M_Sl.n].R;
                                M_Sl.n++;
                            }
                            else if( (vector_SP(nis, OSn) + sinOSi  ) < 0){    /// объект только справа
                                M_Sr.Obj[M_Sr.n].num = Obj_Alive.num[i];
                                M_Sr.Obj[M_Sr.n].OS = OS;
                                M_Sr.Obj[M_Sr.n].OSn = OSn;
                                M_Sr.Obj[M_Sr.n].OSi = OSi;
                                M_Sr.Obj[M_Sr.n].R = All_Obj[Obj_Alive.num[i]].Radius;
                                M_Sr.Obj[M_Sr.n].sinOSi = sinOSi;
                                M_Sr.Obj[M_Sr.n].OnearS = M_Sr.Obj[M_Sr.n].sinOSi - M_Sr.Obj[M_Sr.n].R;
                                M_Sr.n++;
                            }
                            else{
                                M_Sl.Obj[M_Sl.n].num = Obj_Alive.num[i];
                                M_Sl.Obj[M_Sl.n].OS = OS;
                                M_Sl.Obj[M_Sl.n].OSn = OSn;
                                M_Sl.Obj[M_Sl.n].OSi = OSi;
                                M_Sl.Obj[M_Sl.n].R = All_Obj[Obj_Alive.num[i]].Radius;
                                M_Sl.Obj[M_Sl.n].sinOSi = sinOSi;
                                M_Sl.Obj[M_Sl.n].OnearS = M_Sl.Obj[M_Sl.n].sinOSi - M_Sl.Obj[M_Sl.n].R;
                                M_Sr.Obj[M_Sr.n] = M_Sl.Obj[M_Sl.n];
                                M_Sl.n++;
                                M_Sr.n++;
                            }
                        }
                    }
                }
            }
        }
    }
    /**
    Я определил две стороны с информацией. Теперь необходимо запустить четыре потока на разбиение данных участков.
    **/
//    if(THREAD_NUMBER > 1 && THREAD_NUMBER <= 3){
//        HANDLE thr_pix_pl[2];
//        thr_pix_pl[0] = CreateThread(NULL, 0, PixPl_Drevo, (void*)&M_Sl, 0, 0);
//        thr_pix_pl[1] = CreateThread(NULL, 0, PixPl_Drevo, (void*)&M_Sr, 0, 0);
//        WaitForMultipleObjectsEx(2, thr_pix_pl, TRUE, INFINITE,1);
//    }
    if(THREAD_NUMBER > 3 && THREAD_NUMBER <= 7){
        HANDLE thr_pix_pl[4];
        XYZ nism, njsm; /// n.ni[n.num_i / 4] = nism, n.nj[n.num_j / 2] = njsm
        Obj_Numeration_Mass dmsObj[4];
        for(int imas = 0; imas < 4; imas++){
            dmsObj[imas].Obj = new Obj_Numeration_One[M_Sl.n];
        }
        double SPj, SPi;
                /// лучше разделить рассчеты левой и правой стороны на 2 потока. Ля:(
        nism = vector_perp(Person_dEYE_Perp_Verh, GDM_Picture[resolution.vysota / 2][resolution.shirina / 4]);
        nism = vector_ration(nism);

        njsm = vector_perp(GDM_Picture[resolution.vysota / 2][resolution.shirina / 4], Person_dEYE_Perp);
        njsm = vector_ration(njsm);
        for(int num = 0; num < M_Sl.n; num++){
            SPj = vector_SP(njsm, M_Sl.Obj[num].OSn);

            if( SPj - M_Sl.Obj[num].sinOSi >= 0 ){     /// только сверху
                SPi = vector_SP(nism, M_Sl.Obj[num].OSn);

                if( SPi - M_Sl.Obj[num].sinOSi >= 0 ){ /// только слева
                    dmsObj[0].Obj[dmsObj[0].n] = M_Sl.Obj[num];
                    dmsObj[0].n++;
                }
                else if( SPi + M_Sl.Obj[num].sinOSi < 0 ){  /// только справа
                    dmsObj[1].Obj[dmsObj[1].n] = M_Sl.Obj[num];
                    dmsObj[1].n++;
                }
                else{                                   /// и слева и справа
                    dmsObj[0].Obj[dmsObj[0].n] = M_Sl.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[1].Obj[dmsObj[1].n] = M_Sl.Obj[num];
                    dmsObj[1].n++;
                }
            }
            else if( SPj + M_Sl.Obj[num].sinOSi < 0 ){ /// только снизу
                SPi = vector_SP(nism, M_Sl.Obj[num].OSn);

                if( SPi - M_Sl.Obj[num].sinOSi >= 0 ){ /// только слева
                    dmsObj[2].Obj[dmsObj[2].n] = M_Sl.Obj[num];
                    dmsObj[2].n++;
                }
                else if( SPi + M_Sl.Obj[num].sinOSi < 0 ){  /// только справа
                    dmsObj[3].Obj[dmsObj[3].n] = M_Sl.Obj[num];
                    dmsObj[3].n++;
                }
                else{                                   /// и слева и справа
                    dmsObj[2].Obj[dmsObj[2].n] = M_Sl.Obj[num];
                    dmsObj[2].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = M_Sl.Obj[num];
                    dmsObj[3].n++;
                }
            }
            else{                                       /// и сверху и снизу
                SPi = vector_SP(nism, M_Sl.Obj[num].OSn);

                if( SPi - M_Sl.Obj[num].sinOSi >= 0 ){ /// и сверху и снизу только слева
                    dmsObj[0].Obj[dmsObj[0].n] = M_Sl.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[2].Obj[dmsObj[2].n] = M_Sl.Obj[num];
                    dmsObj[2].n++;
                }
                else if( SPi + M_Sl.Obj[num].sinOSi < 0 ){  /// и сверху и снизу только справа
                    dmsObj[1].Obj[dmsObj[1].n] = M_Sl.Obj[num];
                    dmsObj[1].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = M_Sl.Obj[num];
                    dmsObj[3].n++;
                }
                else{                                   /// везде
                    dmsObj[0].Obj[dmsObj[0].n] = M_Sl.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[1].Obj[dmsObj[1].n] = M_Sl.Obj[num];
                    dmsObj[1].n++;
                    dmsObj[2].Obj[dmsObj[2].n] = M_Sl.Obj[num];
                    dmsObj[2].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = M_Sl.Obj[num];
                    dmsObj[3].n++;
                }
            }
        }

        for(int i = 0; i < 4; i++){
            dmsObj[i].thread_num = i;
            thr_pix_pl[i] = CreateThread(NULL, 0, PixPl_Drevo, (void*)&dmsObj[i], 0, 0);
        }
        WaitForMultipleObjectsEx(4, thr_pix_pl, TRUE, INFINITE,1);

        for(int imas = 0; imas < 4; imas++){
            delete(dmsObj[imas].Obj);
        }
        dmsObj[0].n = 0;
        dmsObj[1].n = 0;
        dmsObj[2].n = 0;
        dmsObj[3].n = 0;
        for(int imas = 0; imas < 4; imas++){
            dmsObj[imas].Obj = new Obj_Numeration_One[M_Sr.n];
        }
        nism = vector_perp(Person_dEYE_Perp_Verh, GDM_Picture[resolution.vysota / 2][resolution.shirina * 3 / 4]);
        nism = vector_ration(nism);

        njsm = vector_perp(GDM_Picture[resolution.vysota / 2][resolution.shirina * 3 / 4], Person_dEYE_Perp);
        njsm = vector_ration(njsm);
        for(int num = 0; num < M_Sr.n; num++){
            SPj = vector_SP(njsm, M_Sr.Obj[num].OSn);

            if( SPj - M_Sr.Obj[num].sinOSi >= 0 ){     /// только сверху
                SPi = vector_SP(nism, M_Sr.Obj[num].OSn);

                if( SPi - M_Sr.Obj[num].sinOSi >= 0 ){ /// только слева
                    dmsObj[0].Obj[dmsObj[0].n] = M_Sr.Obj[num];
                    dmsObj[0].n++;
                }
                else if( SPi + M_Sr.Obj[num].sinOSi < 0 ){  /// только справа
                    dmsObj[1].Obj[dmsObj[1].n] = M_Sr.Obj[num];
                    dmsObj[1].n++;
                }
                else{                                   /// и слева и справа
                    dmsObj[0].Obj[dmsObj[0].n] = M_Sr.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[1].Obj[dmsObj[1].n] = M_Sr.Obj[num];
                    dmsObj[1].n++;
                }
            }
            else if( SPj + M_Sr.Obj[num].sinOSi < 0 ){ /// только снизу
                SPi = vector_SP(nism, M_Sr.Obj[num].OSn);

                if( SPi - M_Sr.Obj[num].sinOSi >= 0 ){ /// только слева
                    dmsObj[2].Obj[dmsObj[2].n] = M_Sr.Obj[num];
                    dmsObj[2].n++;
                }
                else if( SPi + M_Sr.Obj[num].sinOSi < 0 ){  /// только справа
                    dmsObj[3].Obj[dmsObj[3].n] = M_Sr.Obj[num];
                    dmsObj[3].n++;
                }
                else{                                   /// и слева и справа
                    dmsObj[2].Obj[dmsObj[2].n] = M_Sr.Obj[num];
                    dmsObj[2].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = M_Sr.Obj[num];
                    dmsObj[3].n++;
                }
            }
            else{                                       /// и сверху и снизу
                SPi = vector_SP(nism, M_Sr.Obj[num].OSn);

                if( SPi - M_Sr.Obj[num].sinOSi >= 0 ){ /// и сверху и снизу только слева
                    dmsObj[0].Obj[dmsObj[0].n] = M_Sr.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[2].Obj[dmsObj[2].n] = M_Sr.Obj[num];
                    dmsObj[2].n++;
                }
                else if( SPi + M_Sr.Obj[num].sinOSi < 0 ){  /// и сверху и снизу только справа
                    dmsObj[1].Obj[dmsObj[1].n] = M_Sr.Obj[num];
                    dmsObj[1].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = M_Sr.Obj[num];
                    dmsObj[3].n++;
                }
                else{                                   /// везде
                    dmsObj[0].Obj[dmsObj[0].n] = M_Sr.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[1].Obj[dmsObj[1].n] = M_Sr.Obj[num];
                    dmsObj[1].n++;
                    dmsObj[2].Obj[dmsObj[2].n] = M_Sr.Obj[num];
                    dmsObj[2].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = M_Sr.Obj[num];
                    dmsObj[3].n++;
                }
            }
        }

        for(int i = 0; i < 4; i++){
            dmsObj[i].thread_num = i + 4;
            thr_pix_pl[i] = CreateThread(NULL, 0, PixPl_Drevo, (void*)&dmsObj[i], 0, 0);
        }
        WaitForMultipleObjectsEx(4, thr_pix_pl, TRUE, INFINITE,1);
        for(int imas = 0; imas < 4; imas++){
            delete(dmsObj[imas].Obj);
        }
    }
//    else if(THREAD_NUMBER > 7){
//        HANDLE thr_pix_pl[8];
//        for(int i = 0; i < 4; i++){
//            thr_pix_pl[i] = CreateThread(NULL, 0, PixPl_Drevo, (void*)&M_Sl, 0, 0);
//        }
//        for(int i = 4; i < 8; i++){
//            thr_pix_pl[i] = CreateThread(NULL, 0, PixPl_Drevo, (void*)&M_Sr, 0, 0);
//        }
//        WaitForMultipleObjectsEx(8, thr_pix_pl, TRUE, INFINITE,1);
//    }
    else{
        cout << "Прости чувак, но с одним потоком игра не запустится))" << endl;
        f_exit = 27;
    }


/**
            if(){**
                    bool = 1; // указывает, что в данном блоке есть элемент(ы), занимающие весь блок. Такой блок разбивать бессмысленно
                    проверяет, если i == Obj_Alive.n - 1, то делает отбор исходя из OnearS и для данных объектов вызывает
                    Ray_Tracing функцию по каждой точке из блока (однако, можно просто вывести цвет близжайшего меша)
                **
            }      /// проверка на занимание всей области
            **/
    delete(M_Sl.Obj);
    delete(M_Sr.Obj);
    Picture_Complited_DrevoType = 1;
}

DWORD WINAPI PixPl_Drevo(void* param)
{
    Obj_Numeration_Mass* B_B_S = (Obj_Numeration_Mass*)param;   // Big_Block_Scene
    Obj_Numeration_rec_Mass S_B_S;                                 // Small_Block_Scene
    S_B_S.Obj = new Obj_Numeration_One[B_B_S->n];
    S_B_S.n = B_B_S->n;
    int dj, di;

    for(int i = 0; i < S_B_S.n; i++)
        S_B_S.Obj[i] = B_B_S->Obj[i];

    if(B_B_S->thread_num == 0 || B_B_S->thread_num == 1){
        di = B_B_S->thread_num;
        dj = 0;
    }
    if(B_B_S->thread_num == 2 || B_B_S->thread_num == 3){
        di = B_B_S->thread_num - 2;
        dj = 1;
    }
    if(B_B_S->thread_num == 4 || B_B_S->thread_num == 5){
        di = B_B_S->thread_num - 2;
        dj = 0;
    }
    if(B_B_S->thread_num == 6 || B_B_S->thread_num == 7){
        di = B_B_S->thread_num - 4;
        dj = 1;
    }
    di = di * (resolution.shirina / 4);
    dj = dj * (resolution.vysota / 2);
///    if(){}

    /// функция упорядочивания объектов по расстоянию
    Obj_Numeration_One temp;

    for(int sss = 0; sss < S_B_S.n - 1; sss++){
        for(int num = 0; num < S_B_S.n - 1; num++){
            if(S_B_S.Obj[num].OSi > S_B_S.Obj[num+1].OSi){
                temp = S_B_S.Obj[num];
                S_B_S.Obj[num] = S_B_S.Obj[num+1];
                S_B_S.Obj[num+1] = temp;
            }
        }
    }
    /// конец функции

    if(S_B_S.n == 0){
        for(int pj = dj; pj < dj + (resolution.vysota/2); pj++){
            for(int pi = di; pi < di + (resolution.shirina/4); pi++){
                if((GDM_Picture[pj][pi].z) > 0){
                    pixels[pj*resolution.shirina*4+pi*4] = 220;
                    pixels[pj*resolution.shirina*4+pi*4+1] = 50;
                    pixels[pj*resolution.shirina*4+pi*4+2] = 10;
                    pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                }
                else{
                    pixels[pj*resolution.shirina*4+pi*4] = 20;
                    pixels[pj*resolution.shirina*4+pi*4+1] = 5;
                    pixels[pj*resolution.shirina*4+pi*4+2] = 50;
                    pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                }
            }
        }
    }
    else{
        if(PARAM_Optimization == 1)
            recursy_optimization(dj, di, resolution.vysota/2, resolution.shirina/4, S_B_S);
        else if(PARAM_Light == 1)
            recursy_light(dj, di, resolution.vysota/2, resolution.shirina/4, S_B_S);
        else if(PARAM_Fonarick == 1)
            recursy_fonarick(dj, di, resolution.vysota/2, resolution.shirina/4, S_B_S);
        else
            recursy(dj, di, resolution.vysota/2, resolution.shirina/4, S_B_S);
    }

    delete(S_B_S.Obj);
    return 0;
}

                    /// i - значение ширины, j - значение высоты!!!!!!!!!!!!!!!!!!!!!!!!!!!
void recursy(int j, int i, int dj, int di, Obj_Numeration_rec_Mass msObj)   //  msObj = mini scene Objects
{
    if(msObj.n == 0){   /// рисовать дефолт
        for(int pj = j; pj < j + dj; pj++){
            for(int pi = i; pi < i + di; pi++){
                if((GDM_Picture[pj][pi].z) > 0){
                    pixels[pj*resolution.shirina*4+pi*4] = 220;
                    pixels[pj*resolution.shirina*4+pi*4+1] = 50;
                    pixels[pj*resolution.shirina*4+pi*4+2] = 10;
                    pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                }
                else{
                    pixels[pj*resolution.shirina*4+pi*4] = 20;
                    pixels[pj*resolution.shirina*4+pi*4+1] = 5;
                    pixels[pj*resolution.shirina*4+pi*4+2] = 50;
                    pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                }
            }
        }
    }
    else if(di <= block.shirina || dj <= block.vysota){          /// вызов для каждого квадрата, Ray_Tracing_For_Picture()
        int RES = 0;

        for(int pj = j; pj < j + dj; pj++){
            for(int pi = i; pi < i + di; pi++){ /// сперва лучше вызвать упорядочивание по расстоянию до объекта
                for(int num = 0; num < msObj.n; num++){
                    RES = Ray_Tracing_For_Picture(msObj.Obj[num].num, Person_Position, GDM_Picture[pj][pi]);
                    if(RES == 1){   /// рисую цвет объекта
                        pixels[pj*resolution.shirina*4+pi*4] = All_Obj[msObj.Obj[num].num].Color.b;
                        pixels[pj*resolution.shirina*4+pi*4+1] = All_Obj[msObj.Obj[num].num].Color.g;
                        pixels[pj*resolution.shirina*4+pi*4+2] = All_Obj[msObj.Obj[num].num].Color.r;
                        pixels[pj*resolution.shirina*4+pi*4+3] = All_Obj[msObj.Obj[num].num].Color.f;
                        break;
                    }
                }
                if(RES == 0){
                    if((GDM_Picture[pj][pi].z) > 0){
                        pixels[pj*resolution.shirina*4+pi*4] = 220;
                        pixels[pj*resolution.shirina*4+pi*4+1] = 50;
                        pixels[pj*resolution.shirina*4+pi*4+2] = 10;
                        pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                    }
                    else{
                        pixels[pj*resolution.shirina*4+pi*4] = 20;
                        pixels[pj*resolution.shirina*4+pi*4+1] = 5;
                        pixels[pj*resolution.shirina*4+pi*4+2] = 50;
                        pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                    }
                }
                if(RES == -1)
                    f_exit = 27;
                RES = 0;
            }
        }
    }
    else{
        XYZ nj, ni;
        ni = vector_perp(Person_dEYE_Perp_Verh, GDM_Picture[j + (dj / 2)][i + (di / 2)]);
        ni = vector_ration(ni);

        nj = vector_perp(GDM_Picture[j + (dj / 2)][i + (di / 2)], Person_dEYE_Perp);
        nj = vector_ration(nj);

        Obj_Numeration_rec_Mass dmsObj[4];   /// 0 - левый верхний, 1 - правый верхний, 2 - левый нижний, 3 - правый нижний
        for(int imas = 0; imas < 4; imas++){
            dmsObj[imas].Obj = new Obj_Numeration_One[msObj.n];
        }
        double SPj, SPi;
        for(int num = 0; num < msObj.n; num++){
            SPj = vector_SP(nj, msObj.Obj[num].OSn);

            if( SPj - msObj.Obj[num].sinOSi >= 0 ){     /// только сверху
                SPi = vector_SP(ni, msObj.Obj[num].OSn);

                if( SPi - msObj.Obj[num].sinOSi >= 0 ){ /// только слева
                    dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                    dmsObj[0].n++;
                }
                else if( SPi + msObj.Obj[num].sinOSi < 0 ){  /// только справа
                    dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                    dmsObj[1].n++;
                }
                else{                                   /// и слева и справа
                    dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                    dmsObj[1].n++;
                }
            }
            else if( SPj + msObj.Obj[num].sinOSi < 0 ){ /// только снизу
                SPi = vector_SP(ni, msObj.Obj[num].OSn);

                if( SPi - msObj.Obj[num].sinOSi >= 0 ){ /// только слева
                    dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                    dmsObj[2].n++;
                }
                else if( SPi + msObj.Obj[num].sinOSi < 0 ){  /// только справа
                    dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                    dmsObj[3].n++;
                }
                else{                                   /// и слева и справа
                    dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                    dmsObj[2].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                    dmsObj[3].n++;
                }
            }
            else{                                       /// и сверху и снизу
                SPi = vector_SP(ni, msObj.Obj[num].OSn);

                if( SPi - msObj.Obj[num].sinOSi >= 0 ){ /// и сверху и снизу только слева
                    dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                    dmsObj[2].n++;
                }
                else if( SPi + msObj.Obj[num].sinOSi < 0 ){  /// и сверху и снизу только справа
                    dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                    dmsObj[1].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                    dmsObj[3].n++;
                }
                else{                                   /// везде
                    dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                    dmsObj[1].n++;
                    dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                    dmsObj[2].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                    dmsObj[3].n++;
                }
            }
        }
        for(int k = 0; k < 4; k++){
    //        else{
                if(k == 0)
                    recursy(j, i, (dj+1)/2, (di+1)/2, dmsObj[0]);
                else if(k == 1)
                    recursy(j, i+(di/2), (dj+1)/2, (di+1)/2, dmsObj[1]);
                else if(k == 2)
                    recursy(j+(dj/2), i, (dj+1)/2, (di+1)/2, dmsObj[2]);
                else if(k == 3)
                    recursy(j+(dj/2), i+(di/2), (dj+1)/2, (di+1)/2, dmsObj[3]);
    //        }
        }
        for(int imas = 0; imas < 4; imas++){
            delete(dmsObj[imas].Obj);
        }
        /// if( (vector_SP(n.nj[n.num_j/2], OSn) - sinOSi  ) >= 0)
    }
}


int Ray_Tracing_For_Deefolt(Obj Floor, XYZ O, XYZ OV)   /// Определение пересечения прямой и треугольника
{
//    Obj* D_Obj = (Obj*) pD_Obj;
    XYZ Peres;
    double D, mu;
    double alphaAB, alphaBC, alphaCA;
    double tL;
    XYZ PA, PB, PC;
    XYZ VO;
    XYZ OP;
    int i = 0;
    int PERESECH = -1;

    while(PERESECH!=1){
///                     Точка пересечения
//        XYZ OV, VO;
//        OV.x = V.x - O.x;
        VO.x = -OV.x;
//        OV.y = V.y - O.y;
        VO.y = -OV.y;
//        OV.z = V.z - O.z;
        VO.z = -OV.z;

        PA = Floor.B[i].A;
        PB = Floor.B[i].n;
        D = PB.x*PA.x + PB.y*PA.y + PB.z*PA.z;
        D *= -1;
        mu = ( D + PB.x*O.x + PB.y*O.y + PB.z*O.z ) / ( PB.x*VO.x + PB.y*VO.y + PB.z*VO.z );
        Peres.x = O.x + OV.x*mu;
        Peres.y = O.y + OV.y*mu;
        Peres.z = O.z + OV.z*mu;
    //    vector_print(Peres);
    ///                     Проверка пересечения с треугольником

        PA.x = PA.x - Peres.x;
        PA.y = PA.y - Peres.y;
        PA.z = PA.z - Peres.z;

        PB.x = Floor.B[i].B.x - Peres.x;
        PB.y = Floor.B[i].B.y - Peres.y;
        PB.z = Floor.B[i].B.z - Peres.z;

        PC.x = Floor.B[i].C.x - Peres.x;
        PC.y = Floor.B[i].C.y - Peres.y;
        PC.z = Floor.B[i].C.z - Peres.z;

    //    PA = vector_ration(PA);
        tL = SqrtInv(PA.x*PA.x + PA.y*PA.y + PA.z*PA.z);
        PA.x = PA.x/tL;
        PA.y = PA.y/tL;
        PA.z = PA.z/tL;
    //    PB = vector_ration(PB);
        tL = SqrtInv(PB.x*PB.x + PB.y*PB.y + PB.z*PB.z);
        PB.x = PB.x/tL;
        PB.y = PB.y/tL;
        PB.z = PB.z/tL;
    //    PC = vector_ration(PC);
        tL = SqrtInv(PC.x*PC.x + PC.y*PC.y + PC.z*PC.z);
        PC.x = PC.x/tL;
        PC.y = PC.y/tL;
        PC.z = PC.z/tL;
        alphaAB = PA.x*PB.x + PA.y*PB.y + PA.z*PB.z;
        alphaBC = PB.x*PC.x + PB.y*PC.y + PB.z*PC.z;
        alphaCA = PC.x*PA.x + PC.y*PA.y + PC.z*PA.z;

//        alphaAB = acos(alphaAB);
//        alphaBC = acos(alphaBC);
//        alphaCA = acos(alphaCA);
        tL = alphaAB + alphaBC + alphaCA;

        i++;

//        if(tL <= (PiDva + 0.001) && tL >= (PiDva - 0.001)){
//            PERESECH = 1;
//            break;
//        }

        if(tL <= -1){
            OP = o_vector(O, Peres);
            if(vector_SP(Person_dEYE, OP) > 0){
                PERESECH = 1;
                break;
            }
        }
        if(i == Floor.num_meshs){
            PERESECH = 0;
            break;
        }
    }
    return PERESECH; /// Так можно и так получится? Вопрос!                 !!!!!!!
}


void InGame_PixelsPloskiy_With_Floor()
{
//    while(Picture_Complited_DrevoType != 0) /// лучше его поместить непосредственно перед задачей пикселей
//        Sleep(1);
    XYZ nil, nir, njv, njn, nis;
    nil = vector_perp(Person_dEYE_Perp_Verh, GDM_Picture[resolution.vysota / 2][0]);
    nil = vector_ration(nil);
    nir = vector_perp(Person_dEYE_Perp_Verh, GDM_Picture[resolution.vysota / 2][resolution.shirina - 1]);
    nir = vector_ration(nir);
    njv = vector_perp(GDM_Picture[0][resolution.shirina / 2], Person_dEYE_Perp);
    njv = vector_ration(njv);
    njn = vector_perp(GDM_Picture[resolution.vysota - 1][resolution.shirina / 2], Person_dEYE_Perp);
    njn = vector_ration(njn);

    nis = vector_perp(Person_dEYE_Perp_Verh, GDM_Picture[resolution.vysota / 2][resolution.shirina / 2]);
    nis = vector_ration(nis);

    XYZ OS, OSn;
    double sinOSi, OSi;
    Obj_Numeration_Mass M_Sl, M_Sr;    // M_S = Main_Scene

    for(int i = 0; i < Obj_Alive.n; i++){
        OS = o_vector(Person_Position, All_Obj[Obj_Alive.num[i]].Position);
        OSn = vector_ration(OS);                                        /// OSn и vector_module вместить сюда, т.к. в них есть
        OSi = vector_module(OS);                                        /// повторяющиеся операции
        sinOSi = (All_Obj[Obj_Alive.num[i]].Radius / OSi);
//        cout << sinOSi;
//        cout << vector_module(nil);
        if((vector_SP(Person_dEYE, OSn) + sinOSi) >= 0){    /// проверка, находится ли объект перед нами или же он сзади нас
            if((vector_SP(nil, OSn) - sinOSi) <= 0){
                if((vector_SP(nir, OSn) + sinOSi) >= 0){
                    if((vector_SP(njv, OSn) - sinOSi) <= 0){
                        if((vector_SP(njn, OSn) + sinOSi) >= 0){  /// объект в "большом" блоке
                            /// проверка по серединной
                            if( (vector_SP(nis, OSn) - sinOSi  ) >= 0){    /// объект только слева
                                M_Sl.Obj[M_Sl.n].num = Obj_Alive.num[i];
                                M_Sl.Obj[M_Sl.n].OS = OS;
                                M_Sl.Obj[M_Sl.n].OSn = OSn;
                                M_Sl.Obj[M_Sl.n].OSi = OSi;
                                M_Sl.Obj[M_Sl.n].R = All_Obj[Obj_Alive.num[i]].Radius;
                                M_Sl.Obj[M_Sl.n].sinOSi = sinOSi;
                                M_Sl.Obj[M_Sl.n].OnearS = M_Sl.Obj[M_Sl.n].sinOSi - M_Sl.Obj[M_Sl.n].R;
                                M_Sl.n++;
                            }
                            else if( (vector_SP(nis, OSn) + sinOSi  ) < 0){    /// объект только справа
                                M_Sr.Obj[M_Sr.n].num = Obj_Alive.num[i];
                                M_Sr.Obj[M_Sr.n].OS = OS;
                                M_Sr.Obj[M_Sr.n].OSn = OSn;
                                M_Sr.Obj[M_Sr.n].OSi = OSi;
                                M_Sr.Obj[M_Sr.n].R = All_Obj[Obj_Alive.num[i]].Radius;
                                M_Sr.Obj[M_Sr.n].sinOSi = sinOSi;
                                M_Sr.Obj[M_Sr.n].OnearS = M_Sr.Obj[M_Sr.n].sinOSi - M_Sr.Obj[M_Sr.n].R;
                                M_Sr.n++;
                            }
                            else{
                                M_Sl.Obj[M_Sl.n].num = Obj_Alive.num[i];
                                M_Sl.Obj[M_Sl.n].OS = OS;
                                M_Sl.Obj[M_Sl.n].OSn = OSn;
                                M_Sl.Obj[M_Sl.n].OSi = OSi;
                                M_Sl.Obj[M_Sl.n].R = All_Obj[Obj_Alive.num[i]].Radius;
                                M_Sl.Obj[M_Sl.n].sinOSi = sinOSi;
                                M_Sl.Obj[M_Sl.n].OnearS = M_Sl.Obj[M_Sl.n].sinOSi - M_Sl.Obj[M_Sl.n].R;
                                M_Sr.Obj[M_Sr.n] = M_Sl.Obj[M_Sl.n];
                                M_Sl.n++;
                                M_Sr.n++;
                            }
                        }
                    }
                }
            }
        }
    }
    /**
    Я определил две стороны с информацией. Теперь необходимо запустить четыре потока на разбиение данных участков.
    **/
//    if(THREAD_NUMBER > 1 && THREAD_NUMBER <= 3){
//        HANDLE thr_pix_pl[2];
//        thr_pix_pl[0] = CreateThread(NULL, 0, PixPl_Drevo, (void*)&M_Sl, 0, 0);
//        thr_pix_pl[1] = CreateThread(NULL, 0, PixPl_Drevo, (void*)&M_Sr, 0, 0);
//        WaitForMultipleObjectsEx(2, thr_pix_pl, TRUE, INFINITE,1);
//    }
    if(THREAD_NUMBER > 3 && THREAD_NUMBER <= 7){
        HANDLE thr_pix_pl[4];
        XYZ nism, njsm; /// n.ni[n.num_i / 4] = nism, n.nj[n.num_j / 2] = njsm
        Obj_Numeration_Mass dmsObj[4];
        double SPj, SPi;
                /// лучше разделить рассчеты левой и правой стороны на 2 потока. Ля:(
        nism = vector_perp(Person_dEYE_Perp_Verh, GDM_Picture[resolution.vysota / 2][resolution.shirina / 4]);
        nism = vector_ration(nism);

        njsm = vector_perp(GDM_Picture[resolution.vysota / 2][resolution.shirina / 4], Person_dEYE_Perp);
        njsm = vector_ration(njsm);
        for(int num = 0; num < M_Sl.n; num++){
            SPj = vector_SP(njsm, M_Sl.Obj[num].OSn);

            if( SPj - M_Sl.Obj[num].sinOSi >= 0 ){     /// только сверху
                SPi = vector_SP(nism, M_Sl.Obj[num].OSn);

                if( SPi - M_Sl.Obj[num].sinOSi >= 0 ){ /// только слева
                    dmsObj[0].Obj[dmsObj[0].n] = M_Sl.Obj[num];
                    dmsObj[0].n++;
                }
                else if( SPi + M_Sl.Obj[num].sinOSi < 0 ){  /// только справа
                    dmsObj[1].Obj[dmsObj[1].n] = M_Sl.Obj[num];
                    dmsObj[1].n++;
                }
                else{                                   /// и слева и справа
                    dmsObj[0].Obj[dmsObj[0].n] = M_Sl.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[1].Obj[dmsObj[1].n] = M_Sl.Obj[num];
                    dmsObj[1].n++;
                }
            }
            else if( SPj + M_Sl.Obj[num].sinOSi < 0 ){ /// только снизу
                SPi = vector_SP(nism, M_Sl.Obj[num].OSn);

                if( SPi - M_Sl.Obj[num].sinOSi >= 0 ){ /// только слева
                    dmsObj[2].Obj[dmsObj[2].n] = M_Sl.Obj[num];
                    dmsObj[2].n++;
                }
                else if( SPi + M_Sl.Obj[num].sinOSi < 0 ){  /// только справа
                    dmsObj[3].Obj[dmsObj[3].n] = M_Sl.Obj[num];
                    dmsObj[3].n++;
                }
                else{                                   /// и слева и справа
                    dmsObj[2].Obj[dmsObj[2].n] = M_Sl.Obj[num];
                    dmsObj[2].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = M_Sl.Obj[num];
                    dmsObj[3].n++;
                }
            }
            else{                                       /// и сверху и снизу
                SPi = vector_SP(nism, M_Sl.Obj[num].OSn);

                if( SPi - M_Sl.Obj[num].sinOSi >= 0 ){ /// и сверху и снизу только слева
                    dmsObj[0].Obj[dmsObj[0].n] = M_Sl.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[2].Obj[dmsObj[2].n] = M_Sl.Obj[num];
                    dmsObj[2].n++;
                }
                else if( SPi + M_Sl.Obj[num].sinOSi < 0 ){  /// и сверху и снизу только справа
                    dmsObj[1].Obj[dmsObj[1].n] = M_Sl.Obj[num];
                    dmsObj[1].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = M_Sl.Obj[num];
                    dmsObj[3].n++;
                }
                else{                                   /// везде
                    dmsObj[0].Obj[dmsObj[0].n] = M_Sl.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[1].Obj[dmsObj[1].n] = M_Sl.Obj[num];
                    dmsObj[1].n++;
                    dmsObj[2].Obj[dmsObj[2].n] = M_Sl.Obj[num];
                    dmsObj[2].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = M_Sl.Obj[num];
                    dmsObj[3].n++;
                }
            }
        }

        for(int i = 0; i < 4; i++){
            dmsObj[i].thread_num = i;
            thr_pix_pl[i] = CreateThread(NULL, 0, PixPl_Drevo_With_Floor, (void*)&dmsObj[i], 0, 0);
        }
        WaitForMultipleObjectsEx(4, thr_pix_pl, TRUE, INFINITE,1);

        nism = vector_perp(Person_dEYE_Perp_Verh, GDM_Picture[resolution.vysota / 2][resolution.shirina * 3 / 4]);
        nism = vector_ration(nism);

        njsm = vector_perp(GDM_Picture[resolution.vysota / 2][resolution.shirina * 3 / 4], Person_dEYE_Perp);
        njsm = vector_ration(njsm);
        for(int num = 0; num < M_Sr.n; num++){
            SPj = vector_SP(njsm, M_Sr.Obj[num].OSn);

            if( SPj - M_Sr.Obj[num].sinOSi >= 0 ){     /// только сверху
                SPi = vector_SP(nism, M_Sr.Obj[num].OSn);

                if( SPi - M_Sr.Obj[num].sinOSi >= 0 ){ /// только слева
                    dmsObj[0].Obj[dmsObj[0].n] = M_Sr.Obj[num];
                    dmsObj[0].n++;
                }
                else if( SPi + M_Sr.Obj[num].sinOSi < 0 ){  /// только справа
                    dmsObj[1].Obj[dmsObj[1].n] = M_Sr.Obj[num];
                    dmsObj[1].n++;
                }
                else{                                   /// и слева и справа
                    dmsObj[0].Obj[dmsObj[0].n] = M_Sr.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[1].Obj[dmsObj[1].n] = M_Sr.Obj[num];
                    dmsObj[1].n++;
                }
            }
            else if( SPj + M_Sr.Obj[num].sinOSi < 0 ){ /// только снизу
                SPi = vector_SP(nism, M_Sr.Obj[num].OSn);

                if( SPi - M_Sr.Obj[num].sinOSi >= 0 ){ /// только слева
                    dmsObj[2].Obj[dmsObj[2].n] = M_Sr.Obj[num];
                    dmsObj[2].n++;
                }
                else if( SPi + M_Sr.Obj[num].sinOSi < 0 ){  /// только справа
                    dmsObj[3].Obj[dmsObj[3].n] = M_Sr.Obj[num];
                    dmsObj[3].n++;
                }
                else{                                   /// и слева и справа
                    dmsObj[2].Obj[dmsObj[2].n] = M_Sr.Obj[num];
                    dmsObj[2].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = M_Sr.Obj[num];
                    dmsObj[3].n++;
                }
            }
            else{                                       /// и сверху и снизу
                SPi = vector_SP(nism, M_Sr.Obj[num].OSn);

                if( SPi - M_Sr.Obj[num].sinOSi >= 0 ){ /// и сверху и снизу только слева
                    dmsObj[0].Obj[dmsObj[0].n] = M_Sr.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[2].Obj[dmsObj[2].n] = M_Sr.Obj[num];
                    dmsObj[2].n++;
                }
                else if( SPi + M_Sr.Obj[num].sinOSi < 0 ){  /// и сверху и снизу только справа
                    dmsObj[1].Obj[dmsObj[1].n] = M_Sr.Obj[num];
                    dmsObj[1].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = M_Sr.Obj[num];
                    dmsObj[3].n++;
                }
                else{                                   /// везде
                    dmsObj[0].Obj[dmsObj[0].n] = M_Sr.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[1].Obj[dmsObj[1].n] = M_Sr.Obj[num];
                    dmsObj[1].n++;
                    dmsObj[2].Obj[dmsObj[2].n] = M_Sr.Obj[num];
                    dmsObj[2].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = M_Sr.Obj[num];
                    dmsObj[3].n++;
                }
            }
        }

        for(int i = 0; i < 4; i++){
            dmsObj[i].thread_num = i + 4;
            thr_pix_pl[i] = CreateThread(NULL, 0, PixPl_Drevo_With_Floor, (void*)&dmsObj[i], 0, 0);
        }
        WaitForMultipleObjectsEx(4, thr_pix_pl, TRUE, INFINITE,1);
    }
//    else if(THREAD_NUMBER > 7){
//        HANDLE thr_pix_pl[8];
//        for(int i = 0; i < 4; i++){
//            thr_pix_pl[i] = CreateThread(NULL, 0, PixPl_Drevo, (void*)&M_Sl, 0, 0);
//        }
//        for(int i = 4; i < 8; i++){
//            thr_pix_pl[i] = CreateThread(NULL, 0, PixPl_Drevo, (void*)&M_Sr, 0, 0);
//        }
//        WaitForMultipleObjectsEx(8, thr_pix_pl, TRUE, INFINITE,1);
//    }
    else{
        cout << "Прости чувак, но с одним потоком игра не запустится))" << endl;
        f_exit = 27;
    }


/**
            if(){**
                    bool = 1; // указывает, что в данном блоке есть элемент(ы), занимающие весь блок. Такой блок разбивать бессмысленно
                    проверяет, если i == Obj_Alive.n - 1, то делает отбор исходя из OnearS и для данных объектов вызывает
                    Ray_Tracing функцию по каждой точке из блока (однако, можно просто вывести цвет близжайшего меша)
                **
            }      /// проверка на занимание всей области
            **/
    Picture_Complited_DrevoType = 1;
}

DWORD WINAPI PixPl_Drevo_With_Floor(void* param)
{
    Obj_Numeration_Mass* B_B_S = (Obj_Numeration_Mass*)param;   // Big_Block_Scene
    Obj_Numeration_rec_Mass S_B_S;                                 // Small_Block_Scene
    S_B_S.n = B_B_S->n;
    int dj, di;

    for(int i = 0; i < S_B_S.n; i++)
        S_B_S.Obj[i] = B_B_S->Obj[i];

    if(B_B_S->thread_num == 0 || B_B_S->thread_num == 1){
        di = B_B_S->thread_num;
        dj = 0;
    }
    if(B_B_S->thread_num == 2 || B_B_S->thread_num == 3){
        di = B_B_S->thread_num - 2;
        dj = 1;
    }
    if(B_B_S->thread_num == 4 || B_B_S->thread_num == 5){
        di = B_B_S->thread_num - 2;
        dj = 0;
    }
    if(B_B_S->thread_num == 6 || B_B_S->thread_num == 7){
        di = B_B_S->thread_num - 4;
        dj = 1;
    }
    di = di * (resolution.shirina / 4);
    dj = dj * (resolution.vysota / 2);
///    if(){}

    /// функция упорядочивания объектов по расстоянию
    Obj_Numeration_One temp;

    for(int sss = 0; sss < S_B_S.n - 1; sss++){
        for(int num = 0; num < S_B_S.n - 1; num++){
            if(S_B_S.Obj[num].OSi > S_B_S.Obj[num+1].OSi){
                temp = S_B_S.Obj[num];
                S_B_S.Obj[num] = S_B_S.Obj[num+1];
                S_B_S.Obj[num+1] = temp;
            }
        }
    }
    /// конец функции

    if(S_B_S.n == 0){
        for(int pj = dj; pj < dj + (resolution.vysota/2); pj++){
            for(int pi = di; pi < di + (resolution.shirina/4); pi++){
                if(Ray_Tracing_For_Deefolt(World_Floor, Person_Position, GDM_Picture[pj][pi]) == 1){
                    pixels[pj*resolution.shirina*4+pi*4] = World_Floor.Color.b;
                    pixels[pj*resolution.shirina*4+pi*4+1] = World_Floor.Color.g;
                    pixels[pj*resolution.shirina*4+pi*4+2] = World_Floor.Color.r;
                    pixels[pj*resolution.shirina*4+pi*4+3] = World_Floor.Color.f;
                }
                else{
                    if((GDM_Picture[pj][pi].z) > 0){
                        pixels[pj*resolution.shirina*4+pi*4] = 220;
                        pixels[pj*resolution.shirina*4+pi*4+1] = 50;
                        pixels[pj*resolution.shirina*4+pi*4+2] = 10;
                        pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                    }
                    else{
                        pixels[pj*resolution.shirina*4+pi*4] = 20;
                        pixels[pj*resolution.shirina*4+pi*4+1] = 5;
                        pixels[pj*resolution.shirina*4+pi*4+2] = 50;
                        pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                    }
                }
            }
        }
    }
    else
        recursy_With_Floor(dj, di, resolution.vysota/2, resolution.shirina/4, S_B_S);

    return 0;
}

                    /// i - значение ширины, j - значение высоты!!!!!!!!!!!!!!!!!!!!!!!!!!!
void recursy_With_Floor(int j, int i, int dj, int di, Obj_Numeration_rec_Mass msObj)   //  msObj = mini scene Objects
{
    if(msObj.n == 0){   /// рисовать дефолт
        for(int pj = j; pj < j + dj; pj++){
            for(int pi = i; pi < i + di; pi++){
                if(Ray_Tracing_For_Deefolt(World_Floor, Person_Position, GDM_Picture[pj][pi]) == 1){
                    pixels[pj*resolution.shirina*4+pi*4] = World_Floor.Color.b;
                    pixels[pj*resolution.shirina*4+pi*4+1] = World_Floor.Color.g;
                    pixels[pj*resolution.shirina*4+pi*4+2] = World_Floor.Color.r;
                    pixels[pj*resolution.shirina*4+pi*4+3] = World_Floor.Color.f;
                }
                else{
                    if((GDM_Picture[pj][pi].z) > 0){
                        pixels[pj*resolution.shirina*4+pi*4] = 220;
                        pixels[pj*resolution.shirina*4+pi*4+1] = 50;
                        pixels[pj*resolution.shirina*4+pi*4+2] = 10;
                        pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                    }
                    else{
                        pixels[pj*resolution.shirina*4+pi*4] = 20;
                        pixels[pj*resolution.shirina*4+pi*4+1] = 5;
                        pixels[pj*resolution.shirina*4+pi*4+2] = 50;
                        pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                    }
                }
            }
        }
    }
    else if(di <= block.shirina || dj <= block.vysota){          /// вызов для каждого квадрата, Ray_Tracing_For_Picture()
        int RES = 0;

        for(int pj = j; pj < j + dj; pj++){
            for(int pi = i; pi < i + di; pi++){ /// сперва лучше вызвать упорядочивание по расстоянию до объекта
                for(int num = 0; num < msObj.n; num++){
                    RES = Ray_Tracing_For_Picture(msObj.Obj[num].num, Person_Position, GDM_Picture[pj][pi]);
                    if(RES == 1){   /// рисую цвет объекта
                        pixels[pj*resolution.shirina*4+pi*4] = All_Obj[msObj.Obj[num].num].Color.b;
                        pixels[pj*resolution.shirina*4+pi*4+1] = All_Obj[msObj.Obj[num].num].Color.g;
                        pixels[pj*resolution.shirina*4+pi*4+2] = All_Obj[msObj.Obj[num].num].Color.r;
                        pixels[pj*resolution.shirina*4+pi*4+3] = All_Obj[msObj.Obj[num].num].Color.f;
                        break;
                    }
                }
                if(RES == 0){
                    if(Ray_Tracing_For_Deefolt(World_Floor, Person_Position, GDM_Picture[pj][pi]) == 1){
                        pixels[pj*resolution.shirina*4+pi*4] = World_Floor.Color.b;
                        pixels[pj*resolution.shirina*4+pi*4+1] = World_Floor.Color.g;
                        pixels[pj*resolution.shirina*4+pi*4+2] = World_Floor.Color.r;
                        pixels[pj*resolution.shirina*4+pi*4+3] = World_Floor.Color.f;
                    }
                    else{
                        if((GDM_Picture[pj][pi].z) > 0){
                            pixels[pj*resolution.shirina*4+pi*4] = 220;
                            pixels[pj*resolution.shirina*4+pi*4+1] = 50;
                            pixels[pj*resolution.shirina*4+pi*4+2] = 10;
                            pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                        }
                        else{
                            pixels[pj*resolution.shirina*4+pi*4] = 20;
                            pixels[pj*resolution.shirina*4+pi*4+1] = 5;
                            pixels[pj*resolution.shirina*4+pi*4+2] = 50;
                            pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                        }
                    }
                }
                if(RES == -1)
                    f_exit = 27;
                RES = 0;
            }
        }
    }
    else{
        XYZ nj, ni;
        ni = vector_perp(Person_dEYE_Perp_Verh, GDM_Picture[j + (dj / 2)][i + (di / 2)]);
        ni = vector_ration(ni);

        nj = vector_perp(GDM_Picture[j + (dj / 2)][i + (di / 2)], Person_dEYE_Perp);
        nj = vector_ration(nj);

        Obj_Numeration_rec_Mass dmsObj[4];   /// 0 - левый верхний, 1 - правый верхний, 2 - левый нижний, 3 - правый нижний
        double SPj, SPi;
        for(int num = 0; num < msObj.n; num++){
            SPj = vector_SP(nj, msObj.Obj[num].OSn);

            if( SPj - msObj.Obj[num].sinOSi >= 0 ){     /// только сверху
                SPi = vector_SP(ni, msObj.Obj[num].OSn);

                if( SPi - msObj.Obj[num].sinOSi >= 0 ){ /// только слева
                    dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                    dmsObj[0].n++;
                }
                else if( SPi + msObj.Obj[num].sinOSi < 0 ){  /// только справа
                    dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                    dmsObj[1].n++;
                }
                else{                                   /// и слева и справа
                    dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                    dmsObj[1].n++;
                }
            }
            else if( SPj + msObj.Obj[num].sinOSi < 0 ){ /// только снизу
                SPi = vector_SP(ni, msObj.Obj[num].OSn);

                if( SPi - msObj.Obj[num].sinOSi >= 0 ){ /// только слева
                    dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                    dmsObj[2].n++;
                }
                else if( SPi + msObj.Obj[num].sinOSi < 0 ){  /// только справа
                    dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                    dmsObj[3].n++;
                }
                else{                                   /// и слева и справа
                    dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                    dmsObj[2].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                    dmsObj[3].n++;
                }
            }
            else{                                       /// и сверху и снизу
                SPi = vector_SP(ni, msObj.Obj[num].OSn);

                if( SPi - msObj.Obj[num].sinOSi >= 0 ){ /// и сверху и снизу только слева
                    dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                    dmsObj[2].n++;
                }
                else if( SPi + msObj.Obj[num].sinOSi < 0 ){  /// и сверху и снизу только справа
                    dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                    dmsObj[1].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                    dmsObj[3].n++;
                }
                else{                                   /// везде
                    dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                    dmsObj[1].n++;
                    dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                    dmsObj[2].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                    dmsObj[3].n++;
                }
            }
        }
        for(int k = 0; k < 4; k++){
    //        else{
                if(k == 0)
                    recursy_With_Floor(j, i, dj/2, di/2, dmsObj[0]);
                else if(k == 1)
                    recursy_With_Floor(j, i+(di/2), dj/2, di/2, dmsObj[1]);
                else if(k == 2)
                    recursy_With_Floor(j+(dj/2), i, dj/2, di/2, dmsObj[2]);
                else if(k == 3)
                    recursy_With_Floor(j+(dj/2), i+(di/2), dj/2, di/2, dmsObj[3]);
    //        }
        }
        /// if( (vector_SP(n.nj[n.num_j/2], OSn) - sinOSi  ) >= 0)
    }
}


double Ray_Tracing_For_Picture_Light(int Obj_Num, XYZ O, XYZ OV)   /// Определение пересечения прямой и треугольника
{
//    Obj* D_Obj = (Obj*) pD_Obj;
    XYZ Peres;
    double D, mu;
    double alphaAB, alphaBC, alphaCA;
    double tL;
    XYZ PA, PB, PC;
    XYZ VO;
    int i = 0;
    int PERESECH = -1;

    while(PERESECH!=1){
///                     Точка пересечения
//        XYZ OV, VO;
//        OV.x = V.x - O.x;
        VO.x = -OV.x;
//        OV.y = V.y - O.y;
        VO.y = -OV.y;
//        OV.z = V.z - O.z;
        VO.z = -OV.z;

        PA = All_Obj[Obj_Num].B[i].A;
        PB = All_Obj[Obj_Num].B[i].n;
        D = PB.x*PA.x + PB.y*PA.y + PB.z*PA.z;
        D *= -1;
        mu = ( D + PB.x*O.x + PB.y*O.y + PB.z*O.z ) / ( PB.x*VO.x + PB.y*VO.y + PB.z*VO.z );
        Peres.x = O.x + OV.x*mu;
        Peres.y = O.y + OV.y*mu;
        Peres.z = O.z + OV.z*mu;
    //    vector_print(Peres);
    ///                     Проверка пересечения с треугольником

        PA.x = PA.x - Peres.x;
        PA.y = PA.y - Peres.y;
        PA.z = PA.z - Peres.z;

        PB.x = All_Obj[Obj_Num].B[i].B.x - Peres.x;
        PB.y = All_Obj[Obj_Num].B[i].B.y - Peres.y;
        PB.z = All_Obj[Obj_Num].B[i].B.z - Peres.z;

        PC.x = All_Obj[Obj_Num].B[i].C.x - Peres.x;
        PC.y = All_Obj[Obj_Num].B[i].C.y - Peres.y;
        PC.z = All_Obj[Obj_Num].B[i].C.z - Peres.z;

    //    PA = vector_ration(PA);
        tL = SqrtInvE(PA.x*PA.x + PA.y*PA.y + PA.z*PA.z);
        PA.x = PA.x*tL;
        PA.y = PA.y*tL;
        PA.z = PA.z*tL;
    //    PB = vector_ration(PB);
        tL = SqrtInvE(PB.x*PB.x + PB.y*PB.y + PB.z*PB.z);
        PB.x = PB.x*tL;
        PB.y = PB.y*tL;
        PB.z = PB.z*tL;
    //    PC = vector_ration(PC);
        tL = SqrtInvE(PC.x*PC.x + PC.y*PC.y + PC.z*PC.z);
        PC.x = PC.x*tL;
        PC.y = PC.y*tL;
        PC.z = PC.z*tL;
        alphaAB = PA.x*PB.x + PA.y*PB.y + PA.z*PB.z;
        alphaBC = PB.x*PC.x + PB.y*PC.y + PB.z*PC.z;
        alphaCA = PC.x*PA.x + PC.y*PA.y + PC.z*PA.z;

//        alphaAB = acos(alphaAB);
//        alphaBC = acos(alphaBC);
//        alphaCA = acos(alphaCA);
        tL = alphaAB + alphaBC + alphaCA;


//        if(tL <= (PiDva + 0.001) && tL >= (PiDva - 0.001)){
//            PERESECH = 1;
//            break;
//        }
        if(tL <= PARAM_Scale){
            XYZ Light;
            Light = o_vector(Direction_Sun, Peres);
            Light = vector_ration(Light);
            double cosLight;
            cosLight = vector_SP(Light, All_Obj[Obj_Num].B[i].n);
//            cosLight *= cosLight;
//            cosLight = 1 - cosLight;
//            cosLight = SqrtInv(cosLight);
            if(cosLight < 0)
                cosLight *= -1;
            return cosLight;
        }
        i++;
        if(i == All_Obj[Obj_Num].num_meshs){
            return -2;
        }
    }
    return -3; /// Так можно и так получится? Вопрос!                 !!!!!!!
}

                    /// i - значение ширины, j - значение высоты!!!!!!!!!!!!!!!!!!!!!!!!!!!
void recursy_light(int j, int i, int dj, int di, Obj_Numeration_rec_Mass msObj)   //  msObj = mini scene Objects
{
    if(msObj.n == 0){   /// рисовать дефолт
        for(int pj = j; pj < j + dj; pj++){
            for(int pi = i; pi < i + di; pi++){
                if((GDM_Picture[pj][pi].z) > 0){
                    pixels[pj*resolution.shirina*4+pi*4] = 220;
                    pixels[pj*resolution.shirina*4+pi*4+1] = 50;
                    pixels[pj*resolution.shirina*4+pi*4+2] = 10;
                    pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                }
                else{
                    pixels[pj*resolution.shirina*4+pi*4] = 20;
                    pixels[pj*resolution.shirina*4+pi*4+1] = 5;
                    pixels[pj*resolution.shirina*4+pi*4+2] = 50;
                    pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                }
            }
        }
    }
    else if(di <= block.shirina || dj <= block.vysota){          /// вызов для каждого квадрата, Ray_Tracing_For_Picture()
        double RES = -2;
        for(int pj = j; pj < j + dj; pj++){
            for(int pi = i; pi < i + di; pi++){ /// сперва лучше вызвать упорядочивание по расстоянию до объекта
                for(int num = 0; num < msObj.n; num++){
                    RES = Ray_Tracing_For_Picture_Light(msObj.Obj[num].num, Person_Position, GDM_Picture[pj][pi]);
                    if(RES > -2){   /// рисую цвет объекта
                        pixels[pj*resolution.shirina*4+pi*4] = All_Obj[msObj.Obj[num].num].Color.b*RES;
                        pixels[pj*resolution.shirina*4+pi*4+1] = All_Obj[msObj.Obj[num].num].Color.g*RES;
                        pixels[pj*resolution.shirina*4+pi*4+2] = All_Obj[msObj.Obj[num].num].Color.r*RES;
                        pixels[pj*resolution.shirina*4+pi*4+3] = All_Obj[msObj.Obj[num].num].Color.f*RES;
                        break;
                    }
                }
                if(RES == -2){
                    if((GDM_Picture[pj][pi].z) > 0){
                        pixels[pj*resolution.shirina*4+pi*4] = 220;
                        pixels[pj*resolution.shirina*4+pi*4+1] = 50;
                        pixels[pj*resolution.shirina*4+pi*4+2] = 10;
                        pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                    }
                    else{
                        pixels[pj*resolution.shirina*4+pi*4] = 20;
                        pixels[pj*resolution.shirina*4+pi*4+1] = 5;
                        pixels[pj*resolution.shirina*4+pi*4+2] = 50;
                        pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                    }
                }
                if(RES == -3)
                    f_exit = 27;
                RES = 0;
            }
        }
    }
    else{
        XYZ nj, ni;
        ni = vector_perp(Person_dEYE_Perp_Verh, GDM_Picture[j + (dj / 2)][i + (di / 2)]);
        ni = vector_ration(ni);

        nj = vector_perp(GDM_Picture[j + (dj / 2)][i + (di / 2)], Person_dEYE_Perp);
        nj = vector_ration(nj);

        Obj_Numeration_rec_Mass dmsObj[4];   /// 0 - левый верхний, 1 - правый верхний, 2 - левый нижний, 3 - правый нижний
        for(int imas = 0; imas < 4; imas++){
            dmsObj[imas].Obj = new Obj_Numeration_One[msObj.n];
        }
        double SPj, SPi;
        for(int num = 0; num < msObj.n; num++){
            SPj = vector_SP(nj, msObj.Obj[num].OSn);

            if( SPj - msObj.Obj[num].sinOSi >= 0 ){     /// только сверху
                SPi = vector_SP(ni, msObj.Obj[num].OSn);

                if( SPi - msObj.Obj[num].sinOSi >= 0 ){ /// только слева
                    dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                    dmsObj[0].n++;
                }
                else if( SPi + msObj.Obj[num].sinOSi < 0 ){  /// только справа
                    dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                    dmsObj[1].n++;
                }
                else{                                   /// и слева и справа
                    dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                    dmsObj[1].n++;
                }
            }
            else if( SPj + msObj.Obj[num].sinOSi < 0 ){ /// только снизу
                SPi = vector_SP(ni, msObj.Obj[num].OSn);

                if( SPi - msObj.Obj[num].sinOSi >= 0 ){ /// только слева
                    dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                    dmsObj[2].n++;
                }
                else if( SPi + msObj.Obj[num].sinOSi < 0 ){  /// только справа
                    dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                    dmsObj[3].n++;
                }
                else{                                   /// и слева и справа
                    dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                    dmsObj[2].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                    dmsObj[3].n++;
                }
            }
            else{                                       /// и сверху и снизу
                SPi = vector_SP(ni, msObj.Obj[num].OSn);

                if( SPi - msObj.Obj[num].sinOSi >= 0 ){ /// и сверху и снизу только слева
                    dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                    dmsObj[2].n++;
                }
                else if( SPi + msObj.Obj[num].sinOSi < 0 ){  /// и сверху и снизу только справа
                    dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                    dmsObj[1].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                    dmsObj[3].n++;
                }
                else{                                   /// везде
                    dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                    dmsObj[1].n++;
                    dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                    dmsObj[2].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                    dmsObj[3].n++;
                }
            }
        }
        for(int k = 0; k < 4; k++){
    //        else{
                if(k == 0)
                    recursy_light(j, i, (dj+1)/2, (di+1)/2, dmsObj[0]);
                else if(k == 1)
                    recursy_light(j, i+(di/2), (dj+1)/2, (di+1)/2, dmsObj[1]);
                else if(k == 2)
                    recursy_light(j+(dj/2), i, (dj+1)/2, (di+1)/2, dmsObj[2]);
                else if(k == 3)
                    recursy_light(j+(dj/2), i+(di/2), (dj+1)/2, (di+1)/2, dmsObj[3]);
    //        }
        }
        /// if( (vector_SP(n.nj[n.num_j/2], OSn) - sinOSi  ) >= 0)
    }
}

                    /// i - значение ширины, j - значение высоты!!!!!!!!!!!!!!!!!!!!!!!!!!!
void recursy_fonarick(int j, int i, int dj, int di, Obj_Numeration_rec_Mass msObj)   //  msObj = mini scene Objects
{
    if(msObj.n == 0){   /// рисовать дефолт
        for(int pj = j; pj < j + dj; pj++){
            for(int pi = i; pi < i + di; pi++){
                if((GDM_Picture[pj][pi].z) > 0){
                    pixels[pj*resolution.shirina*4+pi*4] = 220;
                    pixels[pj*resolution.shirina*4+pi*4+1] = 50;
                    pixels[pj*resolution.shirina*4+pi*4+2] = 10;
                    pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                }
                else{
                    pixels[pj*resolution.shirina*4+pi*4] = 20;
                    pixels[pj*resolution.shirina*4+pi*4+1] = 5;
                    pixels[pj*resolution.shirina*4+pi*4+2] = 50;
                    pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                }
            }
        }
    }
    else if(di <= block.shirina || dj <= block.vysota){          /// вызов для каждого квадрата, Ray_Tracing_For_Picture()
        int RES = 0;
        int fonarick = 0;
        int colorrr = 0;
        for(int pj = j; pj < j + dj; pj++){
            for(int pi = i; pi < i + di; pi++){ /// сперва лучше вызвать упорядочивание по расстоянию до объекта
                for(int num = 0; num < msObj.n; num++){
                    RES = Ray_Tracing_For_Picture(msObj.Obj[num].num, Person_Position, GDM_Picture[pj][pi]);
                    if(RES == 1){   /// рисую цвет объекта
                        if(pi > (resolution.shirina/2 - 30) && pi < (resolution.shirina/2 + 30) && pj > (resolution.vysota/2 - 30) && pj < (resolution.vysota/2 +30)){
                            fonarick = (resolution.shirina/2 - pi + resolution.vysota/2 - pj);
                            if(fonarick < 0)
                                fonarick *= -1;
                            fonarick = 60 - fonarick;
                            fonarick *= 2;
                        }
                        else
                            fonarick = 0;
                        colorrr = All_Obj[msObj.Obj[num].num].Color.b + fonarick;
                        if(colorrr > 255)
                            colorrr = 255;
                        pixels[pj*resolution.shirina*4+pi*4] = colorrr;

                        colorrr = All_Obj[msObj.Obj[num].num].Color.g + fonarick;
                        if(colorrr > 255)
                            colorrr = 255;
                        pixels[pj*resolution.shirina*4+pi*4+1] = colorrr;

                        colorrr = All_Obj[msObj.Obj[num].num].Color.r + fonarick;
                        if(colorrr > 255)
                            colorrr = 255;
                        pixels[pj*resolution.shirina*4+pi*4+2] = colorrr;

                        colorrr = All_Obj[msObj.Obj[num].num].Color.f + fonarick;
                        if(colorrr > 255)
                            colorrr = 255;
                        pixels[pj*resolution.shirina*4+pi*4+3] = colorrr;
                        break;
                    }
                }
                if(RES == 0){
                    if((GDM_Picture[pj][pi].z) > 0){
                        pixels[pj*resolution.shirina*4+pi*4] = 220;
                        pixels[pj*resolution.shirina*4+pi*4+1] = 50;
                        pixels[pj*resolution.shirina*4+pi*4+2] = 10;
                        pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                    }
                    else{
                        pixels[pj*resolution.shirina*4+pi*4] = 20;
                        pixels[pj*resolution.shirina*4+pi*4+1] = 5;
                        pixels[pj*resolution.shirina*4+pi*4+2] = 50;
                        pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                    }
                }
                if(RES == -1)
                    f_exit = 27;
                RES = 0;
            }
        }
    }
    else{
        XYZ nj, ni;
        ni = vector_perp(Person_dEYE_Perp_Verh, GDM_Picture[j + (dj / 2)][i + (di / 2)]);
        ni = vector_ration(ni);

        nj = vector_perp(GDM_Picture[j + (dj / 2)][i + (di / 2)], Person_dEYE_Perp);
        nj = vector_ration(nj);

        Obj_Numeration_rec_Mass dmsObj[4];   /// 0 - левый верхний, 1 - правый верхний, 2 - левый нижний, 3 - правый нижний
        for(int imas = 0; imas < 4; imas++){
            dmsObj[imas].Obj = new Obj_Numeration_One[msObj.n];
        }
        double SPj, SPi;
        for(int num = 0; num < msObj.n; num++){
            SPj = vector_SP(nj, msObj.Obj[num].OSn);

            if( SPj - msObj.Obj[num].sinOSi >= 0 ){     /// только сверху
                SPi = vector_SP(ni, msObj.Obj[num].OSn);

                if( SPi - msObj.Obj[num].sinOSi >= 0 ){ /// только слева
                    dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                    dmsObj[0].n++;
                }
                else if( SPi + msObj.Obj[num].sinOSi < 0 ){  /// только справа
                    dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                    dmsObj[1].n++;
                }
                else{                                   /// и слева и справа
                    dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                    dmsObj[1].n++;
                }
            }
            else if( SPj + msObj.Obj[num].sinOSi < 0 ){ /// только снизу
                SPi = vector_SP(ni, msObj.Obj[num].OSn);

                if( SPi - msObj.Obj[num].sinOSi >= 0 ){ /// только слева
                    dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                    dmsObj[2].n++;
                }
                else if( SPi + msObj.Obj[num].sinOSi < 0 ){  /// только справа
                    dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                    dmsObj[3].n++;
                }
                else{                                   /// и слева и справа
                    dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                    dmsObj[2].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                    dmsObj[3].n++;
                }
            }
            else{                                       /// и сверху и снизу
                SPi = vector_SP(ni, msObj.Obj[num].OSn);

                if( SPi - msObj.Obj[num].sinOSi >= 0 ){ /// и сверху и снизу только слева
                    dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                    dmsObj[2].n++;
                }
                else if( SPi + msObj.Obj[num].sinOSi < 0 ){  /// и сверху и снизу только справа
                    dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                    dmsObj[1].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                    dmsObj[3].n++;
                }
                else{                                   /// везде
                    dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                    dmsObj[0].n++;
                    dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                    dmsObj[1].n++;
                    dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                    dmsObj[2].n++;
                    dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                    dmsObj[3].n++;
                }
            }
        }
        for(int k = 0; k < 4; k++){
    //        else{
                if(k == 0)
                    recursy_fonarick(j, i, dj/2, di/2, dmsObj[0]);
                else if(k == 1)
                    recursy_fonarick(j, i+(di/2), dj/2, di/2, dmsObj[1]);
                else if(k == 2)
                    recursy_fonarick(j+(dj/2), i, dj/2, di/2, dmsObj[2]);
                else if(k == 3)
                    recursy_fonarick(j+(dj/2), i+(di/2), dj/2, di/2, dmsObj[3]);
    //        }
        }
        /// if( (vector_SP(n.nj[n.num_j/2], OSn) - sinOSi  ) >= 0)
    }
}

void recursy_optimization(int j, int i, int dj, int di, Obj_Numeration_rec_Mass msObj)   //  msObj = mini scene Objects
{
    if(msObj.n == 0){   /// рисовать дефолт
        for(int pj = j; pj < j + dj; pj++){
            for(int pi = i; pi < i + di; pi++){
                if((GDM_Picture[pj][pi].z) > 0){
                    pixels[pj*resolution.shirina*4+pi*4] = 220;
                    pixels[pj*resolution.shirina*4+pi*4+1] = 50;
                    pixels[pj*resolution.shirina*4+pi*4+2] = 10;
                    pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                }
                else{
                    pixels[pj*resolution.shirina*4+pi*4] = 20;
                    pixels[pj*resolution.shirina*4+pi*4+1] = 5;
                    pixels[pj*resolution.shirina*4+pi*4+2] = 50;
                    pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                }
            }
        }
        if(PARAM_SEE_OPTIMIZATION == 1){
            pixels[j*resolution.shirina*4+i*4] = 0;
            pixels[j*resolution.shirina*4+i*4+1] = 0;
            pixels[j*resolution.shirina*4+i*4+2] = 0;
            pixels[j*resolution.shirina*4+i*4+3] = 0;
        }
    }
    else if(di <= block.shirina || dj <= block.vysota){          /// вызов для каждого квадрата, Ray_Tracing_For_Picture()
        int RES = 0;

        for(int tj = 0; tj < 2; tj++)
            for(int ti = 0; ti < 2; ti++){
                RES += Ray_Tracing_For_Picture(msObj.Obj[0].num, Person_Position, GDM_Picture[j + (dj-1)*tj][i + (di-1)*ti]);
            }

        if(RES == 4){
//            cout << "P";
            /// закрашивать всё одним объектом
            for(int pj = j; pj < j + dj; pj++){
                for(int pi = i; pi < i + di; pi++){
                    pixels[pj*resolution.shirina*4+pi*4] = All_Obj[msObj.Obj[0].num].Color.b;
                    pixels[pj*resolution.shirina*4+pi*4+1] = All_Obj[msObj.Obj[0].num].Color.g;
                    pixels[pj*resolution.shirina*4+pi*4+2] = All_Obj[msObj.Obj[0].num].Color.r;
                    pixels[pj*resolution.shirina*4+pi*4+3] = All_Obj[msObj.Obj[0].num].Color.f;
                }
            }
            if(PARAM_SEE_OPTIMIZATION == 1){
                pixels[j*resolution.shirina*4+i*4] = 150;
                pixels[j*resolution.shirina*4+i*4+1] = 150;
                pixels[j*resolution.shirina*4+i*4+2] = 150;
                pixels[j*resolution.shirina*4+i*4+3] = 0;
            }
        }
        else if(RES == 0 && dj <= block.vysota && msObj.n == 1){
            for(int pj = j; pj < j + dj; pj++){
                for(int pi = i; pi < i + di; pi++){
                    if((GDM_Picture[pj][pi].z) > 0){
                        pixels[pj*resolution.shirina*4+pi*4] = 220;
                        pixels[pj*resolution.shirina*4+pi*4+1] = 50;
                        pixels[pj*resolution.shirina*4+pi*4+2] = 10;
                        pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                    }
                    else{
                        pixels[pj*resolution.shirina*4+pi*4] = 20;
                        pixels[pj*resolution.shirina*4+pi*4+1] = 5;
                        pixels[pj*resolution.shirina*4+pi*4+2] = 50;
                        pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                    }
                }
            }
            if(PARAM_SEE_OPTIMIZATION == 1){
                pixels[j*resolution.shirina*4+i*4] = 50;
                pixels[j*resolution.shirina*4+i*4+1] = 50;
                pixels[j*resolution.shirina*4+i*4+2] = 50;
                pixels[j*resolution.shirina*4+i*4+3] = 0;
            }
        }
        else{
            RES = 0;
            for(int pj = j; pj < j + dj; pj++){
                for(int pi = i; pi < i + di; pi++){ /// сперва лучше вызвать упорядочивание по расстоянию до объекта
                    for(int num = 0; num < msObj.n; num++){
                        RES = Ray_Tracing_For_Picture(msObj.Obj[num].num, Person_Position, GDM_Picture[pj][pi]);
                        if(RES == 1){   /// рисую цвет объекта
                            pixels[pj*resolution.shirina*4+pi*4] = All_Obj[msObj.Obj[num].num].Color.b;
                            pixels[pj*resolution.shirina*4+pi*4+1] = All_Obj[msObj.Obj[num].num].Color.g;
                            pixels[pj*resolution.shirina*4+pi*4+2] = All_Obj[msObj.Obj[num].num].Color.r;
                            pixels[pj*resolution.shirina*4+pi*4+3] = All_Obj[msObj.Obj[num].num].Color.f;
                            break;
                        }
                    }
                    if(RES == 0){
                        if((GDM_Picture[pj][pi].z) > 0){
                            pixels[pj*resolution.shirina*4+pi*4] = 220;
                            pixels[pj*resolution.shirina*4+pi*4+1] = 50;
                            pixels[pj*resolution.shirina*4+pi*4+2] = 10;
                            pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                        }
                        else{
                            pixels[pj*resolution.shirina*4+pi*4] = 20;
                            pixels[pj*resolution.shirina*4+pi*4+1] = 5;
                            pixels[pj*resolution.shirina*4+pi*4+2] = 50;
                            pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                        }
                    }
                    if(RES == -1)
                        f_exit = 27;
                    RES = 0;
                }
            }
            if(PARAM_SEE_OPTIMIZATION == 1){
                pixels[j*resolution.shirina*4+i*4] = 255;
                pixels[j*resolution.shirina*4+i*4+1] = 255;
                pixels[j*resolution.shirina*4+i*4+2] = 255;
                pixels[j*resolution.shirina*4+i*4+3] = 0;
            }
        }
    }
    else{
        int RES = 0;
        if(msObj.n == 1 || ((msObj.Obj[0].OSi + msObj.Obj[0].R) < msObj.Obj[1].OnearS) ){
            for(int tj = 0; tj < 2; tj++)
                for(int ti = 0; ti < 2; ti++){
                    RES += Ray_Tracing_For_Picture(msObj.Obj[0].num, Person_Position, GDM_Picture[j + (dj-1)*tj][i + (di-1)*ti]);
                }
//            cout << "R=" << RES;
            if(RES == 4){
//                cout << "O";
                /// закрашивать всё одним объектом
                for(int pj = j; pj < j + dj; pj++){
                    for(int pi = i; pi < i + di; pi++){
                        pixels[pj*resolution.shirina*4+pi*4] = All_Obj[msObj.Obj[0].num].Color.b;
                        pixels[pj*resolution.shirina*4+pi*4+1] = All_Obj[msObj.Obj[0].num].Color.g;
                        pixels[pj*resolution.shirina*4+pi*4+2] = All_Obj[msObj.Obj[0].num].Color.r;
                        pixels[pj*resolution.shirina*4+pi*4+3] = All_Obj[msObj.Obj[0].num].Color.f;
                    }
                }
                if(PARAM_SEE_OPTIMIZATION == 1){
                    pixels[j*resolution.shirina*4+i*4] = 50;
                    pixels[j*resolution.shirina*4+i*4+1] = 50;
                    pixels[j*resolution.shirina*4+i*4+2] = 50;
                    pixels[j*resolution.shirina*4+i*4+3] = 0;
                }
                RES = 1;
            }
            else if(RES == 0 && dj <= block.vysota && msObj.n == 1){
                for(int pj = j; pj < j + dj; pj++){
                    for(int pi = i; pi < i + di; pi++){
                        if((GDM_Picture[pj][pi].z) > 0){
                            pixels[pj*resolution.shirina*4+pi*4] = 220;
                            pixels[pj*resolution.shirina*4+pi*4+1] = 50;
                            pixels[pj*resolution.shirina*4+pi*4+2] = 10;
                            pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                        }
                        else{
                            pixels[pj*resolution.shirina*4+pi*4] = 20;
                            pixels[pj*resolution.shirina*4+pi*4+1] = 5;
                            pixels[pj*resolution.shirina*4+pi*4+2] = 50;
                            pixels[pj*resolution.shirina*4+pi*4+3] = 0;
                        }
                    }
                }
                if(PARAM_SEE_OPTIMIZATION == 1){
                    pixels[j*resolution.shirina*4+i*4] = 50;
                    pixels[j*resolution.shirina*4+i*4+1] = 50;
                    pixels[j*resolution.shirina*4+i*4+2] = 50;
                    pixels[j*resolution.shirina*4+i*4+3] = 0;
                }
                RES = 1;
            }
            else RES = 0;
        }

        if(RES == 0){
            XYZ nj, ni;
            ni = vector_perp(Person_dEYE_Perp_Verh, GDM_Picture[j + (dj / 2)][i + (di / 2)]);
            ni = vector_ration(ni);

            nj = vector_perp(GDM_Picture[j + (dj / 2)][i + (di / 2)], Person_dEYE_Perp);
            nj = vector_ration(nj);

            Obj_Numeration_rec_Mass dmsObj[4];   /// 0 - левый верхний, 1 - правый верхний, 2 - левый нижний, 3 - правый нижний
            for(int imas = 0; imas < 4; imas++){
                dmsObj[imas].Obj = new Obj_Numeration_One[msObj.n];
            }
            double SPj, SPi;
            for(int num = 0; num < msObj.n; num++){
                SPj = vector_SP(nj, msObj.Obj[num].OSn);

                if( SPj - msObj.Obj[num].sinOSi >= 0 ){     /// только сверху
                    SPi = vector_SP(ni, msObj.Obj[num].OSn);

                    if( SPi - msObj.Obj[num].sinOSi >= 0 ){ /// только слева
                        dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                        dmsObj[0].n++;
                    }
                    else if( SPi + msObj.Obj[num].sinOSi < 0 ){  /// только справа
                        dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                        dmsObj[1].n++;
                    }
                    else{                                   /// и слева и справа
                        dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                        dmsObj[0].n++;
                        dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                        dmsObj[1].n++;
                    }
                }
                else if( SPj + msObj.Obj[num].sinOSi < 0 ){ /// только снизу
                    SPi = vector_SP(ni, msObj.Obj[num].OSn);

                    if( SPi - msObj.Obj[num].sinOSi >= 0 ){ /// только слева
                        dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                        dmsObj[2].n++;
                    }
                    else if( SPi + msObj.Obj[num].sinOSi < 0 ){  /// только справа
                        dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                        dmsObj[3].n++;
                    }
                    else{                                   /// и слева и справа
                        dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                        dmsObj[2].n++;
                        dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                        dmsObj[3].n++;
                    }
                }
                else{                                       /// и сверху и снизу
                    SPi = vector_SP(ni, msObj.Obj[num].OSn);

                    if( SPi - msObj.Obj[num].sinOSi >= 0 ){ /// и сверху и снизу только слева
                        dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                        dmsObj[0].n++;
                        dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                        dmsObj[2].n++;
                    }
                    else if( SPi + msObj.Obj[num].sinOSi < 0 ){  /// и сверху и снизу только справа
                        dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                        dmsObj[1].n++;
                        dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                        dmsObj[3].n++;
                    }
                    else{                                   /// везде
                        dmsObj[0].Obj[dmsObj[0].n] = msObj.Obj[num];
                        dmsObj[0].n++;
                        dmsObj[1].Obj[dmsObj[1].n] = msObj.Obj[num];
                        dmsObj[1].n++;
                        dmsObj[2].Obj[dmsObj[2].n] = msObj.Obj[num];
                        dmsObj[2].n++;
                        dmsObj[3].Obj[dmsObj[3].n] = msObj.Obj[num];
                        dmsObj[3].n++;
                    }
                }
            }
            for(int k = 0; k < 4; k++){
        //        else{
                    if(k == 0)
                        recursy_optimization(j, i, dj/2, di/2, dmsObj[0]);
                    else if(k == 1)
                        recursy_optimization(j, i+(di/2), dj/2, di/2, dmsObj[1]);
                    else if(k == 2)
                        recursy_optimization(j+(dj/2), i, dj/2, di/2, dmsObj[2]);
                    else if(k == 3)
                        recursy_optimization(j+(dj/2), i+(di/2), dj/2, di/2, dmsObj[3]);
        //        }
            }
        }
        /// if( (vector_SP(n.nj[n.num_j/2], OSn) - sinOSi  ) >= 0)
    }
}







