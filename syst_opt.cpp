#include "syst_opt.h"

POINT dCursor(POINT Cursor_dt)
{
    GetCursorPos(&Cursor_dt);
    SetCursorPos(resolution.shirina/2,resolution.vysota/2);
    Cursor_dt.x = resolution.shirina/2 - Cursor_dt.x;
    Cursor_dt.y = resolution.vysota/2 - Cursor_dt.y;
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

int Ray_Tracing_For_RealTime(int Obj_Num)   /// Определение пересечения прямой и треугольника
{
//    Obj* D_Obj = (Obj*) pD_Obj;
    XYZ Peres;
    int i = 0;
    int PERESECH = -1;

    while(PERESECH!=1){
///                     Точка пересечения
        XYZ VO;
        VO.x = -Person_dEYE.x;
        VO.y = -Person_dEYE.y;
        VO.z = -Person_dEYE.z;
        double D, mu;
        D = All_Obj[Obj_Num].B[i].n.x*All_Obj[Obj_Num].B[i].A.x + All_Obj[Obj_Num].B[i].n.y*All_Obj[Obj_Num].B[i].A.y + All_Obj[Obj_Num].B[i].n.z*All_Obj[Obj_Num].B[i].A.z;
        D *= -1;
        mu = ( D + All_Obj[Obj_Num].B[i].n.x*Person_Position.x + All_Obj[Obj_Num].B[i].n.y*Person_Position.y + All_Obj[Obj_Num].B[i].n.z*Person_Position.z ) / ( All_Obj[Obj_Num].B[i].n.x*VO.x + All_Obj[Obj_Num].B[i].n.y*VO.y + All_Obj[Obj_Num].B[i].n.z*VO.z );
        Peres.x = Person_Position.x + Person_dEYE.x*mu;
        Peres.y = Person_Position.y + Person_dEYE.y*mu;
        Peres.z = Person_Position.z + Person_dEYE.z*mu;
    //    vector_print(Peres);
    ///                     Проверка пересечения с треугольником

        XYZ PA, PB, PC;
        double alphaAB, alphaBC, alphaCA;
        double tL;
        PA.x = All_Obj[Obj_Num].B[i].A.x - Peres.x;
        PA.y = All_Obj[Obj_Num].B[i].A.y - Peres.y;
        PA.z = All_Obj[Obj_Num].B[i].A.z - Peres.z;

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

        alphaAB = acos(alphaAB);
        alphaBC = acos(alphaBC);
        alphaCA = acos(alphaCA);
        tL = alphaAB + alphaBC + alphaCA;

        i++;

        if(tL <= (PiDva + 0.001) && tL >= (PiDva - 0.001)){
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

