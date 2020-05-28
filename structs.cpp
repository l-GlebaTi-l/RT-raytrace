#include "structs.h"

struct XYZ {
    double x;
    double y;
    double z;
};
struct Kvadro_Derevo{
    int i_l;
    int i_p;
    int j_l;
    int j_p;
    int n = 0;
    int *obj;
};
struct screen_resolution{
    int shirina;
    int vysota;
    double Person_EYE_Alpha;
};
struct RGBF{
    unsigned short b = 0;
    unsigned short g = 0;
    unsigned short r = 0;
    unsigned short f = 0;
};
struct Two_Param{
    int i;
    int j;
};
struct Obj_Numeration{
    int n = 0;
    int num[MAX_OBJECTS];
    double OSi[MAX_OBJECTS];
    XYZ OS[MAX_OBJECTS];
};
struct Obj_Numeration_One{
    int num = 0;                    /// порядковый номер объекта в глобале
    XYZ OS = {0,0,0};                     /// вектор от персонажа до объекта
    XYZ OSn = {0,0,0};                    /// нормализированный вектор от персонажа до объекта
    double OSi = 0;                 /// длина от персонажа до объекта
    double R = 0;                   /// радиус объекта
    double sinOSi = 0;              /// синус угла от центра объекта до его краёв
    double OnearS = 0;              /// длина от персонажа до ближней границы объекта
};
struct Obj_Numeration_Mass{
    int n = 0;
    int thread_num = 0;
    int storona = 0;
    Obj_Numeration_One Obj[MAX_SCENE_OBJECTS];
};
struct Obj_Numeration_sMass{
    int n = 0;
    int i = 0;
    int j = 0;
    Obj_Numeration_One Obj[MAX_SCENE_OBJECTS];
};
struct Obj_Numeration_rec_Mass{     //  rec = recurse
    int n = 0;
    Obj_Numeration_One Obj[MAX_SCENE_OBJECTS];
};
struct Obj_Numeration_Block{    /// КРИВОЙ?!?!?!
    int i = 0;                  /// номер по высоте блока
    int j = 0;                  /// номер по ширине блока
    int num;                    /// порядковый номер объекта в глобале
    double R;                   /// радиус объекта
    double OSi;                 /// длина от персонажа до объекта
    double OnearS;              /// длина от персонажа до ближней границы объекта
    double sinOSi;              /// синус угла от центра объекта до его краёв
    XYZ OS;                     /// нормализированный вектор от персонажа до объекта
};
typedef struct TempMesh{
    XYZ tMesh[3];
    struct TempMesh *next;
} TempMesh;
struct InGame_ObjInf{
    int num;
    int n;
};



