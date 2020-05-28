POINT dCursor(POINT Cursor_dt);
int Obj_On_Line(int num);  /// сделать два алгоритма, когда sinObz == sinObz и != (см в тетрадь)
double Ray_Tracing_For_RealTime(int Obj_Num, XYZ O, XYZ OV);   /// Определение пересечения прямой и треугольника
double Ray_Tracing_For_Floor(Obj Floor, XYZ O, XYZ Vzglyad);
double Ray_Tracing_For_Obj_Creating(int Obj_Num, XYZ O, XYZ OV, XYZ &Peres);


POINT dCursor(POINT Cursor_dt)
{
    if(PARAM_Menu == -1){
        if(mPARAM_Menu == 1){
            mPARAM_Menu *= -1;
            if(PARAM_EKRAN_SCALE == 1)
                SetCursorPos(EKRAN.shirina/2,EKRAN.vysota/2);
            else
                SetCursorPos(resolution.shirina/2,resolution.vysota/2);
        }
        GetCursorPos(&Cursor_dt);
        if(PARAM_EKRAN_SCALE == 1){
            SetCursorPos(EKRAN.shirina/2,EKRAN.vysota/2);
            Cursor_dt.x = EKRAN.shirina/2 - Cursor_dt.x;
            Cursor_dt.y = EKRAN.vysota/2 - Cursor_dt.y;
        }
        else{
            SetCursorPos(resolution.shirina/2,resolution.vysota/2);
            Cursor_dt.x = resolution.shirina/2 - Cursor_dt.x;
            Cursor_dt.y = resolution.vysota/2 - Cursor_dt.y;
        }
    }
    else{
        mPARAM_Menu = 1;
        Cursor_dt.x = 0;
        Cursor_dt.y = 0;
    }
    return Cursor_dt;
}

int Obj_On_Line(int num)  /// сделать два алгоритма, когда sinObz == sinObz и != (см в тетрадь)
{
    double sinA, sinS;
    double OSi;
    XYZ O = Person_Position;
    XYZ OS;

    OS = o_vector(O,All_Obj[num].Position);
    OSi = vector_module(OS);

    OS = vector_ration(OS);
    sinA = vector_SP(OS,Person_dEYE);

    sinS = All_Obj[num].Radius/OSi;


    if((sinA + sinS) > 1){            /// В комментарии код для дерева
//        double cosEpS;
//        cosEpS = vector_SP(Person_dEYE_Perp,OS);
//        if(cosEpS > 0)
//            return -1;          // На правой части экрана
//        else if(cosEpS < 0)
//            return 1;           // На левой части экрана
//        else
//            return 1;           /// Возможно, нужно задать другой номер (середина как никак)
        return 1;
    }
    else
        return 0;
    return -2;              // если программа сломалась
}

double Ray_Tracing_For_RealTime(int Obj_Num, XYZ O, XYZ OV)     /// Определение пересечения прямой и треугольника
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
    double L = -1;
    XYZ OS;

    while(PERESECH!=1){
///                     Точка пересечения
//        XYZ OV, VO;
//        Person_dEYE.x = V.x - O.x;
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
            OS = o_vector(O, Peres);
            L = vector_module(OS);
            PERESECH = 1;
            break;
        }
        if(i == All_Obj[Obj_Num].num_meshs){
            PERESECH = 0;
            break;
        }
    }
    return L; /// Так можно и так получится? Вопрос!                 !!!!!!!
}


double Ray_Tracing_For_Floor(Obj Floor, XYZ O, XYZ Vzglyad)     /// Определение угла между полом и направлением движения
{
    XYZ Peres;
    double D, mu;
    double alphaAB, alphaBC, alphaCA;
    double tL;
    XYZ PA, PB, PC;
    XYZ VO;
    int i = 0;
    int PERESECH = -1;
//    double L = -1;
    XYZ OS;
    XYZ OV = {0,0,-1};
    double cosPerFloor;

    while(PERESECH!=1){
///                     Точка пересечения
//        XYZ OV, VO;
//        Person_dEYE.x = V.x - O.x;
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


//        if(tL <= (PiDva + 0.001) && tL >= (PiDva - 0.001)){
//            PERESECH = 1;
//            break;
//        }
        if(tL <= -1){
            XYZ Noga;
            Noga = O;
            Noga.z -= 1.;
            OS = o_vector(Noga, Peres);
//            L = vector_module(OS);

            cosPerFloor = vector_SP(Floor.B[i].n, Person_Napr);
            PERESECH = 1;
            break;
        }

        i++;

        if(i == Floor.num_meshs){
            cosPerFloor = -2;
            PERESECH = 0;
            break;
        }
    }
    return cosPerFloor; /// Так можно и так получится? Вопрос!                 !!!!!!!
}


double Ray_Tracing_For_Jump(Obj Floor, XYZ O, XYZ OV)       /// Расстояние до нижней точки ландшафта
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
    double L = -1;
    XYZ OP;

    while(PERESECH!=1){
///                     Точка пересечения
//        XYZ OV, VO;
//        Person_dEYE.x = V.x - O.x;
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
            L = vector_module(OP);
            cout << "L = " << L << endl;
            if(vector_SP(OP, Floor.B[i].n) > 0){
                L = -L;
            }
            cout << "Ln = " << L << endl;
            PERESECH = 1;
            break;
        }
        if(i == Floor.num_meshs){
            PERESECH = 0;
            break;
        }
    }
    return L; /// Так можно и так получится? Вопрос!                 !!!!!!!
}


bool Ray_Tracing_For_Go(Obj Floor, XYZ O, XYZ Vzglyad)      /// Определяет, находится ли объект над или под ландшафтом
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
//    double L = -1;
    XYZ OV = {0,0,-1};

    while(PERESECH!=1){
///                     Точка пересечения
//        XYZ OV, VO;
//        Person_dEYE.x = V.x - O.x;
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


//        if(tL <= (PiDva + 0.001) && tL >= (PiDva - 0.001)){
//            PERESECH = 1;
//            break;
//        }
        if(tL <= -1){
            Peres.x -= O.x;
            Peres.y -= O.y;
            Peres.z -= O.z;
            if(Peres.z < 0)
                return 1;
            else return 0;
        }

        i++;

        if(i == Floor.num_meshs){
            return 0;
        }
    }
    return 0; /// Так можно и так получится? Вопрос!                 !!!!!!!
}


double Ray_Tracing_For_Stand(Obj Floor, XYZ O, XYZ Vzglyad)     /// Возвращает точку ландшафта под точкой O
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
    XYZ OV = {0,0,-1};

    while(PERESECH!=1){
///                     Точка пересечения
//        XYZ OV, VO;
//        Person_dEYE.x = V.x - O.x;
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


//        if(tL <= (PiDva + 0.001) && tL >= (PiDva - 0.001)){
//            PERESECH = 1;
//            break;
//        }
        if(tL <= -1){
            return Peres.z;
        }

        i++;

        if(i == Floor.num_meshs){
            return O.z;
        }
    }
    return O.z; /// Так можно и так получится? Вопрос!                 !!!!!!!
}


double Ray_Tracing_For_Obj_Creating(int Obj_Num, XYZ O, XYZ OV, XYZ &Peres)     /// Возврат точки пересечения прямой и треугольника
{
//    Obj* D_Obj = (Obj*) pD_Obj;
    double D, mu;
    double alphaAB, alphaBC, alphaCA;
    double tL;
    XYZ PA, PB, PC;
    XYZ VO;
    int i = 0;
    int PERESECH = -1;
    double L = -1;
    XYZ OS;

    while(PERESECH!=1){
///                     Точка пересечения
//        XYZ OV, VO;
//        Person_dEYE.x = V.x - O.x;
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
            OS = o_vector(O, Peres);
            L = vector_module(OS);
            if(vector_SP(OS,OV) < 0){
                L *= -1;
                if(i == All_Obj[Obj_Num].num_meshs){
                    PERESECH = 0;
                    break;
                }
                continue;
            }
            PERESECH = 1;
            break;
        }
        if(i == All_Obj[Obj_Num].num_meshs){
            PERESECH = 0;
            break;
        }
    }
    return L; /// Так можно и так получится? Вопрос!                 !!!!!!!
}


