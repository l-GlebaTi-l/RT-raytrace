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
    int num = 0;                    /// ���������� ����� ������� � �������
    XYZ OS = {0,0,0};                     /// ������ �� ��������� �� �������
    XYZ OSn = {0,0,0};                    /// ����������������� ������ �� ��������� �� �������
    double OSi = 0;                 /// ����� �� ��������� �� �������
    double R = 0;                   /// ������ �������
    double sinOSi = 0;              /// ����� ���� �� ������ ������� �� ��� ����
    double OnearS = 0;              /// ����� �� ��������� �� ������� ������� �������
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
struct Obj_Numeration_Block{    /// ������?!?!?!
    int i = 0;                  /// ����� �� ������ �����
    int j = 0;                  /// ����� �� ������ �����
    int num;                    /// ���������� ����� ������� � �������
    double R;                   /// ������ �������
    double OSi;                 /// ����� �� ��������� �� �������
    double OnearS;              /// ����� �� ��������� �� ������� ������� �������
    double sinOSi;              /// ����� ���� �� ������ ������� �� ��� ����
    XYZ OS;                     /// ����������������� ������ �� ��������� �� �������
};
typedef struct TempMesh{
    XYZ tMesh[3];
    struct TempMesh *next;
} TempMesh;
struct InGame_ObjInf{
    int num;
    int n;
};



