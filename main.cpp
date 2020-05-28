#define COUNT_THREADS 1 /// нужен ли он мне???
#define PiDva 6.283185307
#define Pi  3.141592654
#define MAX_OBJECTS 300
#define MAX_SCENE_OBJECTS 300

#include <iostream>
#include <fstream>
#include <math.h>
#include <chrono>
#include <clocale>
#include <conio.h>
#include <windows.h>
#include <windowsx.h>

using namespace std;
using namespace chrono;

#include "vectors.h"
#include "structs.h"
#include "global_header.h"

auto fixStt = steady_clock::now();
auto fixEnd = steady_clock::now();
auto fixRez = duration_cast<milliseconds>(fixEnd - fixStt);
//        fixStt = steady_clock::now();
//        fixEnd = steady_clock::now();
//        fixRez = duration_cast<milliseconds>(fixEnd - fixStt);
//        cout << "Time is = " << fixRez.count() << " ms" << endl;
auto TIMESTART = steady_clock::now();
auto TIMENOW = steady_clock::now();
auto TIMESPEND = duration_cast<milliseconds>(TIMENOW - TIMESTART);

auto TIME_GAME_START = steady_clock::now();
auto TIME_GAME_NOW = steady_clock::now();
auto TIME_GAME_SPEND = duration_cast<milliseconds>(TIME_GAME_NOW - TIME_GAME_START);

XYZ Person_Position = {0,0,0};             /// CHANGE AFTER TESTS
XYZ Person_dEYE = {1,0,0};                  /// !!!!!!!!!!!!!!!!!!
XYZ Person_dEYE_Perp = {0,1,0};
XYZ Person_dEYE_Perp_Verh = {0,0,1};
XYZ tPerson_Position = {-5,0,0};
XYZ tPerson_dEYE = {1,0,0};
XYZ tPerson_dEYE_Perp = {0,1,0};
XYZ tPerson_dEYE_Perp_Verh = {0,0,1};
XYZ Person_Napr = {1,0,0};
XYZ Direction_Sun = {0,0,2};

int PARAM_Jump = 0;
int PARAM_Fall = 0;
double Person_Speed = 3.0;
bool PARAM_Go_Forward = 0;
bool PARAM_Go_Back = 0;
bool PARAM_Go_Left = 0;
bool PARAM_Go_Right = 0;
bool PARAM_EKRAN_SCALE = 0;
float EKRAN_SCALE_X;
float EKRAN_SCALE_Y;

screen_resolution resolution;
screen_resolution EKRAN;
XYZ **GDM_Picture;
screen_resolution block;
XYZ Vzglyad_Center = {0,0,0};

int Obj_N;
int f_exit = 0;
double Eye_to_Monitor = 1.;

Obj_Numeration Obj_Alive;
//Obj_Numeration Obj_OnScene;
Obj_Numeration Obj_On_Scene;

unsigned char *pixels;
unsigned char *pixels1;
unsigned char *pixels2;
unsigned char *pixelsP;
bool *Picture_Complited;
bool Picture_Complited_DrevoType = 0;
int IAI = 0;
int *Thr_Param;
int THREAD_NUMBER = 1;
double sinObz1 = 0.99, sinObz2 = 0.99;
short syncronize_parameter = 1;
short PARAM_Obvod = -1;
int floor_with_or_no = -1;
short PARAM_Light = 1;
int PARAM_Fonarick = -1;
int PARAM_Optimization = -1;
int PARAM_SEE_OPTIMIZATION = -1;
int PARAM_Menu = -1;
int mPARAM_Menu = -1;
int PARAM_Obj_Creating_New = -1;

#include "classes.h"

Obj *All_Obj;
Obj World_Floor;

double PARAM_Scale = -1;

#include "game_options.h"
#include "syst_opt.h"
#include "screen_func.h"
#include "gameplay.h"
#include "prints.h"

#include "menu.h"

DWORD WINAPI THR_Vn_Creator(LPVOID param);
DWORD WINAPI WinMain_GameScreen (LPVOID param);
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);



//struct GameObj_DataDate{    /// должен быть зависим от Obj_Alive
//    int num;
//    double
//};

//fixStt = steady_clock::now();
//fixEnd = steady_clock::now();
//fixRez = duration_cast<milliseconds>(fixEnd - fixStt);
//cout << "Work = " << fixRez.count() << " ms" << endl;

//Obj *All_Obj_G;

///unsigned int *Scene_Obj_Nomera;             /// Из-за этого мне кажется, что возможно будут ошибки/глюки в игре     !!!!!!!
                                            /// Нулевой элемент - количество номеров!!!

                        ///                             ///
                        ///                             ///
                        ///         НАЧАЛО MAIN         ///
                        ///                             ///
                        ///                             ///
int main()
{
    auto Game_Start = steady_clock::now();
    setlocale(LC_CTYPE, "rus");

    Resolution();
    pixels1 = new unsigned char[resolution.shirina*resolution.vysota*4];
    pixels2 = new unsigned char[resolution.shirina*resolution.vysota*4];
    pixels = &pixels1[0];

//    ifstream file("vectors.txt");
//    mesh A;
//    A.mesher(file);
//    file.close();
    ::Obj_N = 0;

    char Adress_Objects[] = {"Game_Objects/Objects_adress.txt"};

    vizor Player;
    cout << "Желаете ли создать новые объекты в папку игры?" << endl << "1 -> Да" << endl;
    int answer = 1;// = getch();
//	char choice = getch();
//    cin >> answer;
    if(answer == 49){
        ofstream Obj_adr_end(Adress_Objects, ios_base::app);
        Obj_Create_New(Obj_adr_end);
        Obj_adr_end.close();
    }
    else{cout << "Окей, идем дальше" << endl;}

//    ofstream out("page.txt");
//    for (int i = 0; i < 24; i++){
//        Cursor_dt = dCursor(Cursor_dt);
////        screen_view(A, Player, out);
//        cout << Cursor_dt.x << " " << Cursor_dt.y << endl;
//        Sleep(50);
//    }
//    out.close();

    ifstream Obj_adr(Adress_Objects);
//    Obj *All_Obj;
    All_Obj = Obj_Maker(All_Obj, Obj_adr);

    ifstream Floor_file("Game_Objects/floor.txt");
    World_Floor.Objj(Floor_file);
    for(int i = 0; i < World_Floor.num_meshs; i++){
        if(World_Floor.B[i].n.z < 0){
            World_Floor.B[i].n = vector_sim(World_Floor.B[i].n);
        }
    }
//    for(int j = 0; j < Obj_N; j++){
//        cout << "Object " << j+1 << " parameters" << endl;
//        obj_print(All_Obj[j]);
//        cout << endl;
//    }
//    cout << "Do you want to make Radius for some objects?" << endl;
    cout << "Найти и записать радиусы для некоторых объектов?" << endl;
//    cin >> answer;
//    answer = getch();
    if(answer == 49)
        Obj_Radius_Maker(All_Obj);
    else cout << "Нет так нет..." << endl << endl;
    auto Game_End = steady_clock::now();
    auto elapsed_ms = duration_cast<milliseconds>(Game_End - Game_Start);
    cout << "Time spend: " << elapsed_ms.count() << " ms" << endl;

    cout << "Сделать проверку радиусов? (0 - да)" << endl;
//    cin >> answer;
    while(answer == 0){
        while ((answer < 1) || (answer > Obj_N)){
            cout << "Введите номер объекта от 1 до " << Obj_N << endl;
            cin >> answer;
        }
        cout << All_Obj[answer - 1].Name << endl;
        cout << "Радиус = " << All_Obj[answer - 1].Radius << endl << "Следующий?";
        cin >> answer;
    }
    cout << "КОЛИЧЕСТВО ОБЪЕКТОВ ПЕРЕД СТАРТОМ: " << Obj_N << endl;
    Obj_Alive.n = Obj_N;
    for(int i = 0; i < Obj_Alive.n; i++){
        Obj_Alive.num[i] = i;
    }
    for(int i = Obj_Alive.n; i < Obj_Alive.n+50; i++){
        Obj_Alive.num[i] = -1;
    }
//    Sleep(5000);
//    HINSTANCE hInstance;
//    HINSTANCE nPrevInstance;
//    LPSTR lpCmdLine;
//    int CmdShow;
//    WinMain(hInstance, nPrevInstance, lpCmdLine, CmdShow);
//    Player_eye();
    Picture_Complited = new bool [THREAD_NUMBER];
    for(int i = 0; i < THREAD_NUMBER; i++)
        Picture_Complited[i] = 0;

    Buttons = new Button[But_N];
//    Buttons[0].Button();
    for(int i = 1; i < But_N; i++){
//        Buttons[i].Button();
        Buttons[i].posj = Buttons[i - 1].posj + Buttons[i - 1].lj + 10;
    }

    HANDLE Thread;
    Thread = CreateThread(NULL, 0, THR_Vn_Creator, NULL, 0, 0);
//    WaitForMultipleObjects(COUNT_THREADS, Thread, TRUE, INFINITE);
    WaitForSingleObject(Thread,INFINITE);
//    Sleep(10000);
//    WinMain_GameScreen();
    cout << "Количество всех кадров = " << IAI << endl;
    cout << "Game Ends here. Thanks for testing!" << endl << "Say GoodBye!" << endl << "- ";
    Sleep(1000);
//    cout << "Количество кадров: " << IAI << endl;
//    cin >> IAI;
    getchar();
    return 0;
}

                        ///                            ///
                        ///                            ///
                        ///         КОНЕЦ MAIN         ///
                        ///                            ///
                        ///                            ///



///                             CLEAN EYE PROGRAMM

//                  Ради сонхронизации можно создать доп элемент в структуре
//                  изображения с типом bool, и переменять её на 1, если изображение
//                  уже было задействовано, и 0 - если это новое изображение. То же
//                  самое можно сделать для отрисовки и пр. (но оптимизированно ли это?)




DWORD WINAPI THR_Vn_Creator(LPVOID param)
{
    POINT DCursor;
//    COORD FPS_Where;
//    FPS_Where.X = 50;
//    FPS_Where.Y = 3;
//    COORD Look_Where;
//    Look_Where.X = 1;
//    Look_Where.Y = 1;
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    auto Game_Start = steady_clock::now();
    auto Game_End = steady_clock::now();
    auto elapsed_ms = duration_cast<milliseconds>(Game_End - Game_Start);

    double Alpha = 0, Beta = 0, temp_proeczia, dDCursorX = 0, dDCursorY = 0;
    XYZ E0, Ez{0,0,1}, eVys, eShi, dEVys, dEShi, V;
    XYZ** DM_Picture;
    DM_Picture = new XYZ*[resolution.vysota];
    for (int i = 0; i < resolution.vysota; i++)
        DM_Picture[i] = new XYZ[resolution.shirina];

    double dShi, dVys;
    dShi = 1.0 / resolution.vysota;
    dVys = 1.0 / resolution.vysota;
    double iii = 0.;
    int fps = 0.;
    double sec = 0.;
    double fps_sec = 0.0;
    int tR, tV;
    SetCursorPos(resolution.shirina/2,resolution.vysota/2);         /// Сюда лучше прибавлять единицу перед стартом     !!!!!!!
    CLR_CNS(hOut);
    CreateThread(NULL, 0, WinMain_GameScreen, NULL, 0, 0);
//    HANDLE threads[THREAD_NUMBER];
//    Sleep(7789);
    Game_Start = steady_clock::now();
    TIMESTART = steady_clock::now();
    CreateThread(NULL, 0, Player_Physics, NULL, 0, 0);
    while(f_exit != 27){
        DCursor = dCursor(DCursor);
        dDCursorX = DCursor.x;
        dDCursorX /= resolution.shirina;
        dDCursorY = DCursor.y;
        dDCursorY /= resolution.vysota;
//        if(dDCursorX == 0 && dDCursorY == 0 && IAI > 5)
//            goto GOTO_NO_dDCursor;              /// GOTO THERE START <----------------------
        Beta += dDCursorY;
        if(Beta > (Pi/2) - 0.1)             /// ограничение по вертикальному обзору (обязательно >0)
            Beta = (Pi/2) - 0.1;
        if(Beta < -(Pi/2) + 0.1)
            Beta = -(Pi/2) + 0.1;
        Alpha += dDCursorX;
        E0.z = Eye_to_Monitor*sin(Beta);
        temp_proeczia = Eye_to_Monitor*cos(Beta);
        E0.y = temp_proeczia*sin(Alpha);
        E0.x = temp_proeczia*cos(Alpha);

        Person_Napr.x = cos(Alpha);
        Person_Napr.y = sin(Alpha);

        eShi = vector_perp(Ez,E0);
        eShi = vector_ration(eShi);

        tPerson_dEYE_Perp = eShi;

        eShi = vector_YnC(eShi,-1);
        eVys = vector_perp(E0,eShi);
        eVys = vector_ration(eVys);

        tPerson_dEYE_Perp_Verh = vector_YnC(eVys,-1);

        dEShi = vector_YnC(eShi,dShi);
        dEVys = vector_YnC(eVys,dVys);
        tR = resolution.shirina/2;
        tV = resolution.vysota/2;
        V.x = E0.x - dEShi.x*(tR) - dEVys.x*(tV);
        V.y = E0.y - dEShi.y*(tR) - dEVys.y*(tV);
        V.z = E0.z - dEShi.z*(tR) - dEVys.z*(tV);
//        Vzglyad_Center = E0;
        /// создать поток и передать ему параметр V.x V.y V.z центра экрана,
        /// он из All_Obj будет выбирать те, что попадают на сцену путём измерения     _ O O _
        /// угла между объектом и глаза, и создавать массив ссылок на эти объекты.     \__|__/
        /// В функцию Ray_Trasing и будет передаваться данный массив, чтобы снизить
        /// в ней нагрузку и объем вычислений. Гениально! Да! ДА! ДА! (ахах спатьки хочу).
        for(int i = 0; i < resolution.vysota; i++){           // i < 768
            for(int j = 0; j < resolution.shirina; j++){      // j < 1365
                DM_Picture[i][j] = V;
                V.x += dEShi.x;
                V.y += dEShi.y;
                V.z += dEShi.z;
            }
            DM_Picture[i][resolution.shirina - 1] = V;
            V.x -= dEShi.x*resolution.shirina;
            V.y -= dEShi.y*resolution.shirina;
            V.z -= dEShi.z*resolution.shirina;
            V.x += dEVys.x;
            V.y += dEVys.y;
            V.z += dEVys.z;
        }
//GOTO_NO_dDCursor:                               /// GOTO THERE END <------------------------
//        cout << "Near wait" << endl;
//        WaitForMultipleObjects(4, threads, TRUE, INFINITE);
//        sinObzXYZ.x = DM_Picture[resolution.vysota-1][resolution.shirina-1].x;
//        sinObzXYZ.y = DM_Picture[resolution.vysota-1][resolution.shirina-1].y;
//        sinObzXYZ.z = DM_Picture[resolution.vysota-1][resolution.shirina-1].z;
//        tsinObz1 = vector_SP(vector_ration(vector_ration(sinObzXYZ)),E0);
///        WaitForMultipleObjectsEx(THREAD_NUMBER, threads, TRUE, INFINITE,1);

//        sinObz1 = tsinObz1;
//        sinObz2 = tsinObz1;
//        Sleep(1000);
//        cout << "After wait" << endl;
        ::GDM_Picture = DM_Picture;
//        cout << "Full:" << endl;
        Person_dEYE = E0;
        Person_dEYE_Perp = tPerson_dEYE_Perp;
        Person_dEYE_Perp_Verh = tPerson_dEYE_Perp_Verh;
        Person_Position = tPerson_Position;
        Direction_Sun = Person_Position;

//        vector_print(Person_dEYE);
//        vector_print(Person_dEYE_Perp);
//        vector_print(Person_dEYE_Perp_Verh);
//        vector_print(Person_Position);
//        cout << "end" << endl;
//        Obj_On_Scene = Screen_Objects();          ///   Обязательный элемент для работы!!!!!!!!!!!!!!!
//        fixStt = steady_clock::now();
//        fixEnd = steady_clock::now();
//        fixRez = duration_cast<milliseconds>(fixEnd - fixStt);
//        cout << "Work = " << fixRez.count() << " ms" << endl;


//        CLR_CNS(hOut);
//        SetConsoleCursorPosition(hOut,
//                                Look_Where);
//        if(IAI!=0)
//            cout << "Objects on scene: " << Scene_Obj_Nomera[0] << endl;
//            cout << "Длина E0 = " << vector_module(E0) << endl;
//            cout << "Длина Person_dEYE = " << vector_module(Person_dEYE) << endl;
//            vector_print(Person_dEYE);
//            cout << "Длина Person_dEYE_Perp = " << vector_module(Person_dEYE_Perp) << endl;
//            vector_print(Person_dEYE_Perp);
//            cout << "Позиция игрока: ";
//            vector_print(Person_Position);
//            cout << "Взгляд игрока: ";
//            vector_print(DM_Picture[resolution.vysota/2][resolution.shirina/2]);
//        cout << "Alpha = " << Alpha << ", Beta = " << Beta << endl;
//        cout << "Person_dEYE: ";
//        vector_print(Person_dEYE);
//        cout << "Person_Position: ";
//        vector_print(Person_Position);
//        cout << endl << "\t\t\t0DM X:" << DM_Picture[0][0].x;
//        cout << "\t0DM Y: " << DM_Picture[0][0].y;
//        cout << "\t0DM Z: " << DM_Picture[0][0].z << "\t\t\t" << endl;
//        cout << endl << "\t\t\t0DM X:" << DM_Picture[0][resolution.shirina-1].x;
//        cout << "\tEDM Y: " << DM_Picture[0][resolution.shirina-1].y;
//        cout << "\t DM Z: " << DM_Picture[0][resolution.shirina-1].z << "\t\t\t" << endl;
//        cout << endl << "\t\t\tSDM X:" << DM_Picture[resolution.vysota/2][resolution.shirina/2].x;
//        cout << "\tSDM Y: " << DM_Picture[resolution.vysota/2][resolution.shirina/2].y;
//        cout << "\t DM Z: " << DM_Picture[resolution.vysota/2][resolution.shirina/2].z << "\t\t\t" << endl;
//        cout << endl << "\t\t\tEDM X:" << DM_Picture[resolution.vysota-1][0].x;
//        cout << "\t0DM Y: " << DM_Picture[resolution.vysota-1][0].y;
//        cout << "\t DM Z: " << DM_Picture[resolution.vysota-1][0].z << "\t\t\t" << endl;
//        cout << endl << "\t\t\tEDM X:" << DM_Picture[resolution.vysota-1][resolution.shirina-1].x;
//        cout << "\tEDM Y: " << DM_Picture[resolution.vysota-1][resolution.shirina-1].y;
//        cout << "\t DM Z: " << DM_Picture[resolution.vysota-1][resolution.shirina-1].z << "\t\t\t" << endl;

        TIME_GAME_NOW = steady_clock::now();
        TIME_GAME_SPEND = duration_cast<milliseconds>(TIME_GAME_NOW - TIME_GAME_START);
        TIME_GAME_START = TIME_GAME_NOW;



        Game_End = steady_clock::now();
        elapsed_ms = duration_cast<milliseconds>(Game_End - Game_Start);
        sec += elapsed_ms.count();
        fps_sec += elapsed_ms.count();
        iii++;
        fps++;
        Game_Start = steady_clock::now();
//        if(fps == 15){
//            SetConsoleCursorPosition(hOut,
//                                    FPS_Where);
//            cout << "fps: " << (fps/(fps_sec/1000)) << "    " << endl;
//            fps_sec = 0;
//            fps = 0;
//        }
//        SetConsoleCursorPosition(hOut,
//                                Look_Where);
//        Person_Position = {0, 6, -2};
//        Person_dEYE = {2, 2, 0};

///        for(int i = 0; i < THREAD_NUMBER; i++)
///            threads[i] = CreateThread(NULL, 0, Screen_Pixels_All, (LPVOID)i, 0, 0);
//        fixStt = steady_clock::now();
        if(floor_with_or_no == -1)
            InGame_PixelsPloskiy();
        else
            InGame_PixelsPloskiy_With_Floor();

//        fixEnd = steady_clock::now();
//        fixRez = duration_cast<milliseconds>(fixEnd - fixStt);
//        cout << "Time is = " << fixRez.count() << " ms" << endl;

//        cout << "Thr created" << endl;

    }
//    CLR_CNS(hOut);
    cout << "Srednee fps: " << ((iii*1000)/(sec)) << endl;
    cout << "Vremya: " << sec << endl;
    cout << "Srednee vremya: " << sec / iii << endl;
    getchar();
    ExitThread(0);
}



///                             END OF CLEAN EYE PROGRAMM

DWORD WINAPI WinMain_GameScreen (LPVOID param)
{
    HINSTANCE hInst;
    hInst = NULL;
    char Class [] = "HackClipboard_Class";          // HackClipboard_Class - название программы, которая и дала мне
                                                    // вывод изображения, только там он был с обычного буфера обмена...)
    WNDCLASS wc      = {0};
    ZeroMemory (&wc, sizeof (wc) );

    wc.style         = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc   = WindowProcedure;
    wc.hInstance     = hInst;
    wc.hIcon         = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor (NULL, IDC_ARROW);
//    wc.hbrBackground = CreateSolidBrush (RGB (150, 150, 150));
    wc.hbrBackground = NULL;
    wc.lpszClassName = Class;
    wc.lpszMenuName  = NULL;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;

    if (!RegisterClass (&wc))
    {
//         MessageBox (NULL, "Window Registration Failed!", "Error!", MB_OK | MB_ICONERROR);
         return 0;
    }

    HWND hwnd;
    if(PARAM_EKRAN_SCALE == 1)
        hwnd = CreateWindow (Class, "HackClipboard", /*WS_OVERLAPPEDWINDOW*/ WS_POPUP, CW_USEDEFAULT, CW_USEDEFAULT, EKRAN.shirina, EKRAN.vysota, NULL, NULL, hInst, NULL);
    else
        hwnd = CreateWindow (Class, "HackClipboard", /*WS_OVERLAPPEDWINDOW*/ WS_POPUP, CW_USEDEFAULT, CW_USEDEFAULT, resolution.shirina, resolution.vysota, NULL, NULL, hInst, NULL);
    if (!hwnd)
    {
//         MessageBox (NULL, "Window Creation Failed!", "Error!", MB_OK | MB_ICONERROR);
         return 0;
    }

    ShowWindow (hwnd, SW_SHOW);
    InvalidateRect(hwnd, 0, 0);         /// 3-ье значение было NULL
    UpdateWindow (hwnd);

    MSG msg;
    bool NoEr;
//    while (f_exit != 27)
//    {
//        PeekMessageA (&msg, NULL, 0, 0, PM_REMOVE);
//        DispatchMessage (&msg);
//        TranslateMessage (&msg);
//    }
//    PlaySound(NULL, NULL, 0);
    while ( (NoEr = GetMessageA (&msg, NULL, 0, 0)) != 0 )
    {
        DispatchMessage (&msg);
        TranslateMessage (&msg);
        if(f_exit == 27){
            PlaySound(NULL, NULL, 0);
            return (int) msg.wParam;
        }
    }
    UnregisterClass (Class, hInst);
    return (int) msg.wParam;
}

int fff = 0;
int dB = 100, dG = 100, dR = 100, dWhat_is_it = 0; /// не обязательные в будущем
int BUF = 1;
POINT Cursor_dt;
HBITMAP hImg;
BITMAPINFO dbmi;
BITMAPINFOHEADER bmih;
HDC hdc;
HDC hMemDC;
PAINTSTRUCT ps;
BITMAP bm;
WORD nSize;
TCHAR szBuf[80];

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static double wheelDelta = 0;
    if(PARAM_Menu == -1){
        switch (msg)
        {
            case WM_CREATE:
            {
                SetTimer (hwnd, 1, 1, NULL);
//                PlaySound(TEXT("veterok.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
            }
            break;

            case WM_KEYDOWN:
                {
                    if( wParam == ( VkKeyScan('W') & 0xFF )){
                        if(PARAM_Go_Forward == 0){
                            PARAM_Go_Forward = 1;
                            CreateThread(NULL, 0, Player_Went_Forward, NULL, 0, 0);
                        }
                    }
                    if( wParam == ( VkKeyScan('S') & 0xFF )){
                        if(PARAM_Go_Back == 0){
                            PARAM_Go_Back = 1;
                            CreateThread(NULL, 0, Player_Went_Back, NULL, 0, 0);
                        }
                    }
                    if( wParam == ( VkKeyScan('A') & 0xFF )){
                        if(PARAM_Go_Left == 0){
                            PARAM_Go_Left = 1;
                            CreateThread(NULL, 0, Player_Went_Left, NULL, 0, 0);
                        }
                    }
                    if( wParam == ( VkKeyScan('D') & 0xFF )){
                        if(PARAM_Go_Right == 0){
                            PARAM_Go_Right = 1;
                            CreateThread(NULL, 0, Player_Went_Right, NULL, 0, 0);
                        }
                    }
                }
                break;
            case WM_KEYUP:
                {
                    if( wParam == ( VkKeyScan('W') & 0xFF )){
                        if(PARAM_Go_Forward == 1){
                            PARAM_Go_Forward = 0;
                        }
                    }
                    if( wParam == ( VkKeyScan('S') & 0xFF )){
                        if(PARAM_Go_Back == 1){
                            PARAM_Go_Back = 0;
                        }
                    }
                    if( wParam == ( VkKeyScan('A') & 0xFF )){
                        if(PARAM_Go_Left == 1){
                            PARAM_Go_Left = 0;
                        }
                    }
                    if( wParam == ( VkKeyScan('D') & 0xFF )){
                        if(PARAM_Go_Right == 1){
                            PARAM_Go_Right = 0;
                        }
                    }
                }
                break;
            case WM_CHAR:
                switch (wParam)
                {
                    /*
                    case 119:                       /// cout << "PRESSED W" << endl;
                        tPerson_Position.x += (Person_Napr.x/3);
                        tPerson_Position.y += (Person_Napr.y/3);
                        break;
                    case 97:                        /// cout << "PRESSED A" << endl;
                        tPerson_Position.x -= (Person_Napr.y/3);
                        tPerson_Position.y += (Person_Napr.x/3);
                        break;
                    case 115:                       /// cout << "PRESSED S" << endl;
                        tPerson_Position.x -= (Person_Napr.x/3);
                        tPerson_Position.y -= (Person_Napr.y/3);
                        break;
                    case 100:                       /// cout << "PRESSED D" << endl;
                        tPerson_Position.x += (Person_Napr.y/3);
                        tPerson_Position.y -= (Person_Napr.x/3);
                        break;
                        */
                    case 32:    /// Пробел
                        if(PARAM_Jump == 0){
                            PARAM_Jump = 1;
                            CreateThread(NULL, 0, Player_Jump, NULL, 0, 0);
                        }
                        break;
                    case 107:   /// k
                        tPerson_Position.z += 0.3;
                        break;
                    case 99:    /// c
                        tPerson_Position.z -= 0.3;
                        break;
                    case 112:   /// p
                        Sleep(5000);
                        break;
                    case 103:   /// g
                        {
                        cout << "Количество живых объектов: " << Obj_Alive.n << ", Номера ";
                        for(int i = 0; i < Obj_Alive.n + 5; i++)
                            cout << Obj_Alive.num[i] << " ";
                        cout << endl;
                        cout << "Количество объектов в памяти" << Obj_N << endl;
                        }
                        break;
                    case 42:    /// *
                        {
                            syncronize_parameter *= -1;
                        }
                        break;
                    case 116:   /// t
                        {
                            cout << "there TELEPORT" << endl;
                        for(int i = 0; i < Obj_Alive.n; i++)
                            if(Ray_Tracing_For_RealTime(Obj_Alive.num[i], Person_Position, Person_dEYE) > 0){
                                All_Obj[Obj_Alive.num[i]].Obj_d_Teleport(vector_YnC(Person_dEYE, -1));
                                cout << "Object № " << i << " went some:)" << endl;
                                break;
                            }
                        }
                        break;
                    case 43:    /// +
                        {
                            Eye_to_Monitor += 0.035;
                        }
                        break;
                    case 45:    /// -
                        {
                            Eye_to_Monitor -= 0.035;
                            if(Eye_to_Monitor < 0.1)
                                Eye_to_Monitor = 0.1;
                        }
                        break;
                    case 111:   /// o
                        {
                            Otladchik();
                        }
                        break;
                    case 33:    /// SHIFT + 1
                        {
                            PARAM_Obvod *= -1;
                        }
                        break;
                    case 64:    /// SHIFT + 2
                        {
                            floor_with_or_no *= -1;
                        }
                        break;
                    case 35:    /// SHIFT + 3
                        {
                            PARAM_Light *= -1;
                        }
                        break;
                    case 36:    /// SHIFT + 4
                        {
                            PARAM_Optimization *= -1;
                        }
                        break;
                    case 37:    /// SHIFT + 5
                        {
                            PARAM_SEE_OPTIMIZATION *= -1;
                        }
                    case 108:    /// l
                        {
                            PARAM_Fonarick *= -1;
                        }
                        break;
                    case 101:   /// e
                        {
                            PARAM_Obj_Creating_New *= -1;
                        }
                        break;
                    case 13:    /// Enter
                        PARAM_Menu *= -1;
                        break;
                    case 109:   /// m
                        {
                            int iWidth = GetSystemMetrics(SM_CXSCREEN);  // ширина экрана по горизонтали
                            int iHeight = GetSystemMetrics(SM_CYSCREEN); // высота экрана по вертикали
                            int Y, X;
                            X = (iWidth - resolution.shirina) / 2;
                            Y = (iHeight - resolution.vysota) / 2;
                            hwnd = GetActiveWindow();
                            MoveWindow(hwnd, X, Y, resolution.shirina, resolution.vysota, true);
                        }
                        break;
                    case 91:
                        {
                            Person_Speed -= 0.1;
                        }
                        break;
                    case 93:
                        {
                            Person_Speed += 0.1;
                        }
                        break;
                    case 27:    /// Esc
                        f_exit = 27;
                        break;
                }
                break;
            case WM_MOUSEWHEEL:
                {
                    wheelDelta += GET_WHEEL_DELTA_WPARAM(wParam);
                    for(; wheelDelta > WHEEL_DELTA; wheelDelta -= WHEEL_DELTA){
                        PARAM_Scale -= 0.01;
                    }
                    for(; wheelDelta < 0; wheelDelta += WHEEL_DELTA){
                        PARAM_Scale += 0.01;
                    }
                }
                break;
            case WM_LBUTTONDOWN:
                {
                    cout << "ЛКМ" << endl;
                    mciSendString("play crash.wav", NULL, 0, 0);
                    double L = 0;
                    for(int i = 0; i < Obj_Alive.n; i++){
                        L = Ray_Tracing_For_RealTime(Obj_Alive.num[i], Person_Position, Person_dEYE);
                        if(L > 0){
                            cout << "Расстояние до объекта = " << L << endl;
                            All_Obj[Obj_Alive.num[i]].Obj_Hit(100/L, i);
                            break;
                        }
                    }
                    if(L <= 0)
                        cout << "Промах! Или....." << endl;
                }
                break;
            case WM_RBUTTONDOWN:
                {
                    if(PARAM_Obj_Creating_New == -1){
                        cout << "ПКМ" << endl;
                        mciSendString("play boom.wav", NULL, 0, 0);
                        {
                            Game_Obj_Add();
                            cout << "Added!" << endl;
                        }
                    }
                    else{
                        static int ti = 0;
                        XYZ tA;
                        static XYZ A[3];
                        A[ti] = vector_sum(Person_Position, Person_dEYE);
                        for(int i = 0; i < Obj_Alive.n; i++)
                            if(Ray_Tracing_For_Obj_Creating(Obj_Alive.num[i], Person_Position, Person_dEYE, tA) > 0){
                                A[ti] = tA;
                                break;
                            }
                        ti++;
                        if(ti == 3){
                            RGBF newColor;
                            newColor.r = 100;
                            newColor.g = 0;
                            newColor.b = 100;
                            newColor.f = 0;
                            Game_Obj_Add(A[0], A[1], A[2], newColor);
                            ti = 0;
                        }
                    }
                }
                break;
            case WM_TIMER:
            {
                fff++;
                if(fff == 8)
                    fff = 0;
                bmih.biSize     = sizeof(BITMAPINFOHEADER);
                bmih.biWidth    = resolution.shirina;
                bmih.biHeight   = -resolution.vysota;
                bmih.biPlanes   = 1;
                bmih.biBitCount = 32;
                bmih.biCompression  = BI_RGB;
                bmih.biSizeImage    = 0;
                bmih.biXPelsPerMeter    =   10;
                bmih.biYPelsPerMeter    =   10;
                bmih.biClrUsed    =0;
                bmih.biClrImportant =0;

                ZeroMemory(&dbmi, sizeof(dbmi));
                dbmi.bmiHeader = bmih;
                dbmi.bmiColors->rgbBlue = 0;
                dbmi.bmiColors->rgbGreen = 0;
                dbmi.bmiColors->rgbRed = 0;
                dbmi.bmiColors->rgbReserved = 0;

                while(Picture_Complited_DrevoType != 1){}
//                    Sleep(1);
                pixelsP = pixels;
                if(BUF == 1)
                    pixels = &pixels2[0];
                if(BUF == -1)
                    pixels = &pixels1[0];
                Picture_Complited_DrevoType = 0;
                BUF *= -1;
                /**
                while(Picture_Menu_Complited != 1){
                    if(PARAM_Menu == 1)
                        Sleep(1)
                    else
                        break;
                }
                **/
                hdc = ::GetDC(NULL);
                hImg = CreateDIBitmap(hdc, &bmih, CBM_INIT, pixelsP, &dbmi, DIB_RGB_COLORS);
                if (hImg == NULL) {
                    cout << "Could not load the desired image image" << endl;
                    return 0;
                }
                IAI++;

                ::ReleaseDC(NULL, hdc);

                if (hImg)
                    InvalidateRect(hwnd, NULL, TRUE);

                hdc = BeginPaint (hwnd, &ps);
                hMemDC = CreateCompatibleDC(hdc);

                SelectBitmap(hMemDC, hImg);
                GetObject (hImg, sizeof (BITMAP), &bm);
                if(PARAM_EKRAN_SCALE == 1)
                    StretchBlt (hdc, 0, 0, EKRAN.shirina, EKRAN.vysota, hMemDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
                else
                    BitBlt (hdc, 0, 0, bm.bmWidth, bm.bmHeight, hMemDC, 0, 0, SRCCOPY);



                nSize = wsprintf(szBuf, TEXT("%d"), (1000 / TIME_GAME_SPEND.count()));
                TextOut(hdc, 10, 10, szBuf, nSize);



                DeleteDC (hMemDC);
                EndPaint (hwnd, &ps);
                DeleteObject(hImg);
            }
            break;

            case WM_DESTROY:
            {
                CloseClipboard();
                DeleteObject(hImg);
                mciSendString("stop veterok.wav", NULL, 0, 0);
                PlaySound(NULL, NULL, 0);
                f_exit = 27;
                KillTimer (hwnd, 1);
                PostQuitMessage (0);
            }
            break;
        }
    }
    else{
        switch (msg)
        {
            case WM_CREATE:
            {
                SetTimer (hwnd, 1, 1, NULL);
            }
            break;


            case WM_CHAR:
                switch (wParam)
                {
                    case 119:                       /// cout << "PRESSED W" << endl;
                        break;
                    case 97:                        /// cout << "PRESSED A" << endl;
                        break;
                    case 115:                       /// cout << "PRESSED S" << endl;
                        break;
                    case 100:                       /// cout << "PRESSED D" << endl;
                        break;
                    case 32:    /// Пробел
                        break;
                    case 107:   /// k
                        break;
                    case 99:    /// c
                        {
                            for(int i = 0; i < But_N; i++){
                                cout << "Button param: " << Buttons[i].posj << endl;
                            }
                        }
                        break;
                    case 112:   /// p
                        break;
                    case 103:   /// g
                        break;
                    case 42:    /// *
                        {
                            syncronize_parameter *= -1;
                        }
                        break;
                    case 116:   /// t
                        break;
                    case 43:    /// +
                        {
                            Eye_to_Monitor += 0.035;
                        }
                        break;
                    case 45:    /// -
                        {
                            Eye_to_Monitor -= 0.035;
                            if(Eye_to_Monitor < 0.1)
                                Eye_to_Monitor = 0.1;
                        }
                        break;
                    case 111:   /// O
                        {
                            Otladchik();
                        }
                        break;
                    case 33:    /// SHIFT + 1
                        break;
                    case 64:    /// SHIFT + 2
                        {
                            floor_with_or_no *= -1;
                        }
                        break;
                    case 35:    /// SHIFT + 3
                        {
                            PARAM_Light *= -1;
                        }
                        break;
                    case 108:    /// SHIFT + 4
                        {
                            PARAM_Fonarick *= -1;
                        }
                        break;
                    case 13:    /// Enter
                        PARAM_Menu *= -1;
                        break;
                    case 27:    /// Esc
                        f_exit = 27;
                        break;
                }
                break;
            case WM_LBUTTONDOWN:
                {
                    POINT Menu_Cursor;
                    GetCursorPos(&Menu_Cursor);
                    for(int i = 0; i < But_N; i++)
                        if(Buttons[i].is_there(Menu_Cursor) == 1){
                            Menu_Options(i);
                        }
                }
                break;
            case WM_RBUTTONDOWN:
                break;
            case WM_TIMER:
            {
                fff++;
                if(fff == 8)
                    fff = 0;
                bmih.biSize     = sizeof(BITMAPINFOHEADER);
                bmih.biWidth    = resolution.shirina;
                bmih.biHeight   = -resolution.vysota;
                bmih.biPlanes   = 1;
                bmih.biBitCount = 32;
                bmih.biCompression  = BI_RGB;
                bmih.biSizeImage    = 0;
                bmih.biXPelsPerMeter    =   10;
                bmih.biYPelsPerMeter    =   10;
                bmih.biClrUsed    =0;
                bmih.biClrImportant =0;

                ZeroMemory(&dbmi, sizeof(dbmi));
                dbmi.bmiHeader = bmih;
                dbmi.bmiColors->rgbBlue = 0;
                dbmi.bmiColors->rgbGreen = 0;
                dbmi.bmiColors->rgbRed = 0;
                dbmi.bmiColors->rgbReserved = 0;

                while(Picture_Complited_DrevoType != 1){}
//                    Sleep(1);
                pixelsP = pixels;
                if(BUF == 1)
                    pixels = &pixels2[0];
                if(BUF == -1)
                    pixels = &pixels1[0];
                Picture_Complited_DrevoType = 0;
                BUF *= -1;
                for(int i = 0; i < But_N; i++)
                    Buttons[i].Paint();
                /**
                while(Picture_Menu_Complited != 1){
                    if(PARAM_Menu == 1)
                        Sleep(1)
                    else
                        break;
                }
                **/
                hdc = ::GetDC(NULL);
                hImg = CreateDIBitmap(hdc, &bmih, CBM_INIT, pixelsP, &dbmi, DIB_RGB_COLORS);
                if (hImg == NULL) {
                    cout << "Could not load the desired image image" << endl;
                    return 0;
                }
                IAI++;

                ::ReleaseDC(NULL, hdc);

                if (hImg)
                    InvalidateRect(hwnd, NULL, TRUE);

                hdc = BeginPaint (hwnd, &ps);
                hMemDC = CreateCompatibleDC(hdc);

                SelectBitmap(hMemDC, hImg);
                GetObject (hImg, sizeof (BITMAP), &bm);
                if(PARAM_EKRAN_SCALE == 1)
                    StretchBlt (hdc, 0, 0, EKRAN.shirina, EKRAN.vysota, hMemDC, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
                else
                    BitBlt (hdc, 0, 0, bm.bmWidth, bm.bmHeight, hMemDC, 0, 0, SRCCOPY);
                DeleteDC (hMemDC);
                EndPaint (hwnd, &ps);
                DeleteObject(hImg);
            }
            break;

            case WM_DESTROY:
            {
                CloseClipboard();
                DeleteObject(hImg);
                mciSendString("stop veterok.wav", NULL, 0, 0);
                PlaySound(NULL, NULL, 0);
                f_exit = 27;
                KillTimer (hwnd, 1);
                PostQuitMessage (0);
            }
            break;
        }
    }
    return DefWindowProc (hwnd, msg, wParam, lParam);
}




