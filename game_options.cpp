#include "game_options.h"

void Resolution_out()
{
    std::cout << resolution.shirina << " " << resolution.vysota;
}

void Obj_Create_New(std::ofstream& Obj_adr_end)
{
    short answer = 0, ans_1, ans_2, ans_3;
    std::cout << "������� ��� ������ �������: ";
    char tName[100] = {"Game_Objects/"}, Name[100], NameSuffics[] = {".txt"}, TempName[100];
    int N_meshes = 0;
    std::cin >> TempName;
    strcat(tName,TempName);
    strcat(tName,NameSuffics);
    OemToChar(tName,Name);
    std::ofstream obj_new(Name);
//    obj_new << std::endl;

    std::cout << "������� ������ ��� �����: ";
    TempMesh *mesh_now;
    mesh_now = new TempMesh;
    XYZ A[3];
    for(int i = 0; i < 3; i++){
        std::cin >> A[i].x >> A[i].y >> A[i].z;
        mesh_now->tMesh[i] = A[i];
    }
    TempMesh *first;
    first = new TempMesh;
    first->next = mesh_now;
    N_meshes++;
    std::cout << "��� ������ ������?/n1)�������� ����� � ����������� ����/n2)������� ����� ���/3)��������� ������ � ������" << std::endl;
    while(answer!=3){
        std::cin >> answer;
        if(answer == 1){
            std::cout << "����� ����� �������?" << std::endl;
            for(int i = 0; i < 3; i++){
                std::cout << i + 1 << ") ";
                vector_print(A[i]);
            }
            std::cin >> ans_1 >> ans_2;
            while((ans_1 != 1 && ans_1 != 2 && ans_1 != 3) || (ans_2 != 1 && ans_2 !=2 && ans_2 != 3) || (ans_1 == ans_2)){
                std::cout << "������������ �����, 1, 2 ��� 3!\n������ ��� ���" << std::endl;
                std::cin >> ans_1 >> ans_2;
            }
            std::cout << std::endl;

            std::cout << "������� ���������� ����� �����: ";
            if(ans_1 != 1 && ans_2 != 1)
                ans_3 = 0;
            if(ans_1 != 2 && ans_2 != 2)
                ans_3 = 1;
            if(ans_1 != 3 && ans_2 != 3)
                ans_3 = 2;
            std::cin >> A[ans_3].x >> A[ans_3].y >> A[ans_3].z;
            TempMesh *TempA = new TempMesh;
            for(int i = 0; i < 3; i++)
                TempA->tMesh[i] = A[i];
            mesh_now->next = TempA;
            mesh_now = mesh_now->next;
            N_meshes++;
            std::cout << "������. ��� ������?" << std::endl;
            continue;
        }
        if(answer == 2){
            std::cout << "������� ���������� ���� ����� �����:" << std::endl;
            for(int i = 0; i < 3; i++)
                std::cin >> A[i].x >> A[i].y >> A[i].z;
            TempMesh *TempA = new TempMesh;
            for(int i = 0; i < 3; i++)
                TempA->tMesh[i] = A[i];
            mesh_now->next = TempA;
            mesh_now = mesh_now->next;
            N_meshes++;
            std::cout << "������. ��� ������?" << std::endl;
            continue;
        }
        if(answer == 3){
            mesh_now = first->next;
            obj_new << N_meshes;
            for(int i = 0; i < N_meshes; i++){
                for(int j = 0; j < 3; j++)
                    obj_new << std::endl << mesh_now->tMesh[j].x << " " << mesh_now->tMesh[j].y << " " << mesh_now->tMesh[j].z;
                mesh_now = mesh_now->next;
            }
            obj_new.close();

            std::ifstream obj_new_read(Name);
            Obj New;
            New.Objj(obj_new_read);
            double L;
            L = Radius_finder(&New);
            std::cout << "L of new object is: " << L << std::endl;
            obj_new_read.close();
            std::ofstream obj_new(Name, ios_base::app);
            obj_new << std::endl << L;
            obj_new << std::endl << New.Position.x << " " << New.Position.y << " " << New.Position.z;
            std::cout << "������� ����� ������� � ������� RGBF �� 0 �� 255" << std::endl;
            RGBF color_new;
            std::cin >> color_new.r >> color_new.g >> color_new.b >> color_new.f;
            if(color_new.r > 255)
                color_new.r = 255;
            if(color_new.r < 0)
                color_new.r = 0;
            if(color_new.g > 255)
                color_new.g = 255;
            if(color_new.g < 0)
                color_new.g = 0;
            if(color_new.b > 255)
                color_new.b = 255;
            if(color_new.b < 0)
                color_new.b = 0;
            if(color_new.f > 255)
                color_new.f = 255;
            if(color_new.f < 0)
                color_new.f = 0;
            obj_new << std::endl << color_new.r << " " << color_new.g << " " << color_new.b << " " << color_new.f;
            Obj_adr_end << std::endl << Name;
            obj_new.close();
            break;
        }
        if(answer!=1&&answer!=2&&answer!=3){
            std::cout << "����� ���������, �����..." << std::endl;
            continue;
        }
    }
    std::cout << std::endl << "�������!" << std::endl << std::endl;
}

void Obj_Radius_Maker(Obj *All_Obj)
{
//    for(int i = 0; i < Obj_N; i++)
//        std::cout << "Object " << i + 1 << " live is " << All_Obj[i].live << std::endl;
    int k = -1;
    char t[100];
    short choose = 1;
    while(choose==1){
        std::cout << "�������� ������ ��� ������� �������" << std::endl;
        std::cin >> k;
        while(k < 1 || k > Obj_N){
            std::cout << "������ ������ �� ����������, �������� ������" << std::endl;
            std::cin >> k;
        }
        if(All_Obj[k - 1].live == 0){
            std::cout << "� ���� �������� ��������, �������� ������" << std::endl;
            std::cin >> k;
            while(k < 1 || k > Obj_N){
                std::cout << "������ ������ �� ����������, �������� ������" << std::endl;
                std::cin >> k;
            }
            if(All_Obj[k - 1].live == 0){
                std::cout << "� ���� ���� ��������... ��� ��� (��� -1 ��� ������)" << std::endl;
                std::cin >> k;
                if(k == -1){
                    std::cout << "������� �������!" << std::endl;
                    break;
                }
                while(k < 1 || k > Obj_N){
                    std::cout << "������ ������ �� ����������, �������� ������" << std::endl;
                    std::cin >> k;
                    if(k == -1){
                        std::cout << "������� �������!" << std::endl;
                        break;
                    }
                }
                while(All_Obj[k - 1].live == 0){
                    std::cout << "D'oh! � � ����..." << std::endl;
                    std::cin >> k;
                    if(k == -1){
                        std::cout << "������� �������!" << std::endl;
                        break;
                    }
                    while(k < 1 || k > Obj_N){
                        std::cout << "������ ������ �� ����������, �������� ������" << std::endl;
                        std::cin >> k;
                        if(k == -1){
                            std::cout << "������� �������!" << std::endl;
                            break;
                        }
                    }
                }
            }
        }
        if(k == -1)
            break;
        double L;
        L = Radius_finder(&All_Obj[k-1]);
//        std::cout << "Radius is " << L << std::endl;
        for(int i = 0; i < 100; i++){
            t[i] = All_Obj[k-1].Name[i];
        }
        std::ifstream check(t);
        int counter = -1;
        double temp, temp_prev1, temp_prev2, temp_prev3;
        while(!check.eof()){
            if(counter > 2) temp_prev3 = temp_prev2;
            if(counter > 1) temp_prev2 = temp_prev1;
            if(counter > 0) temp_prev1 = temp;
            check >> temp;
            if(counter == -1) temp_prev3 = temp;
            counter++;
        }
        std::cout << "Counter = " << counter << std::endl;
        if(counter%9 == 0){
            std::ofstream write(t, ios_base::app);
            std::cout << "�� �������� �� ������, �� �������. ��������..." << std::endl;
            write << std::endl << L;
            All_Obj[k-1].Radius = L;
            write << std::endl << All_Obj[k-1].Position.x << " " << All_Obj[k-1].Position.y << " " << All_Obj[k-1].Position.z;
            write.close();
            std::cout << "�������. ��� ��� ������?" << std::endl;
//            std::cout << "Saved. Do next?" << std::endl;
            std::cin >> choose;
        }
        else {
            if((counter-1)%9 == 0){
                int tt, ll;
                tt = temp*10000;
                ll = L*10000;
                if(ll == tt){
                    std::cout << "��� ����� ������, ������� ���. �����..." << std::endl << "������� ��������� ������?" << std::endl;;
                    std::ofstream write(t, ios_base::app);
                    write << std::endl << All_Obj[k-1].Position.x << " " << All_Obj[k-1].Position.y << " " << All_Obj[k-1].Position.z;
                }
                else std::cout << "((or) some shit in the end of the file:)" << std::endl << "������� ����� ������� ������?" << std::endl;
//                std::cout << "Already have Radius (or some shit in the end of the file:)" << std::endl << "Choose else object?" << std::endl;
            }
            else if ((counter-4)%9 == 0) {
                int tt, ll;
                tt = temp_prev3*10000;
                ll = L*10000;
                if(ll != tt){
                    std::cout << "������������ ������ ������� � �������, �� ��� ������� ������ �� �����." << std::endl;
                }
                else if((All_Obj[k-1].Position.x == temp_prev2) && (All_Obj[k-1].Position.y == temp_prev1) && (All_Obj[k-1].Position.z == temp)){
                    std::cout << "��� ������� ������ �������" << std::endl;
                }
                else std::cout << "������� � ����� �� ����� ����������������" << std::endl;
            }
            else std::cout << "������ ������..." << std::endl << "������� ������?" << std::endl;
            std::cin >> choose;
        }
    }
}

Obj* Obj_Maker(Obj *All_Obj, std::ifstream& Obj_adr)
{
    if(!Obj_adr.is_open()){
        std::cout << "*******�� ���� ����� ������ �������� ����*******" << std::endl;
//        std::cout << "Can't find Game Objects adresses" << std::endl;
        Sleep(5000);
    }

    char s[100], t[100];
    std::cout << "������� ���������� ��������..." << std::endl;
    while(!Obj_adr.eof()){
        Obj_adr >> s;
        ::Obj_N++;
    }
    std::cout << "����� ��������..." << std::endl;
    Obj_adr.seekg(0,ios_base::beg);
    All_Obj = new Obj[Obj_N+10];
    int k = 0;

    while(!Obj_adr.eof()){
        Obj_adr >> s;
        OemToChar(s,t);
        std::ifstream obj_1(t);
        if (!obj_1.is_open()){
            std::cout << "������ � ������ " << s << "." << std::endl;
            All_Obj[k].live = 0;
            k++;
            continue;
        } else {std::cout << "���� " << s << " ������" << std::endl;}
        All_Obj[k].Objj(obj_1);
        for(int i = 0; i < 100; i++){
            All_Obj[k].Name[i] = t[i];
        }
        All_Obj[k].live = 1;
        k++;
    }
    return All_Obj;
}

double Radius_finder(Obj *Some)         // ����������� ���������� (������ ����)
{
    double L = 0, tL;
    XYZ centr;
    XYZ temp_tochechka;
    XYZ tochka[(*Some).num_meshs*3];
    for(int i = 0, j = 0; i < (*Some).num_meshs; i++){ // �� ����� ������������� ��������� �� ���������� �����
        tochka[j] = (*Some).B[i].A;                    // �� ����� �����������, �� ��������� ����������.
        tochka[j+1] = (*Some).B[i].B;
        tochka[j+2] = (*Some).B[i].C;
        j += 3;
    }
    int max1, max2;
    std::cout << std::endl << "�����:" << std::endl << std::endl;
    for(int i = 0; i < (*Some).num_meshs*3; i++){
        vector_print(tochka[i]);
    }
    std::cout << std::endl << "�����:" << std::endl << std::endl;
    for(int i = 0; i < (*Some).num_meshs*3; i++){
        for(int j = i+1; j < (*Some).num_meshs*3; j++){
            if(tochka[i].x == tochka[j].x){
                if(tochka[i].y == tochka[j].y){
                    if(tochka[i].z == tochka[j].z){
                        continue;
                    }
                    tL = tochka[i].z - tochka[j].z;
                    if(tL < 0)
                        tL = -tL;
                    if(tL > L){
                        max1 = i;
                        max2 = j;
                        L = tL;
                    }
//                    std::cout << "����� ����� " << i+1 << " " << j+1 << "\t";
                    std::cout << "tL: " << tL << " L: " << L << std::endl;
                    continue;
                }
            }
            temp_tochechka = o_vector(tochka[i], tochka[j]);
            tL = vector_module(temp_tochechka);
            if(tL > L){
                max1 = i;
                max2 = j;
                L = tL;
            }
//            std::cout << "����� ����� " << i+1 << " " << j+1 << "\t";
            std::cout << "tL: " << tL << " L: " << L << std::endl;
        }
    }
//    std::cout << "������ �����: " << max1+1 << " " << max2+1 << std::endl;
//    std::cout << "��� �����:";
//    vector_print(tochka[max1]);
//    vector_print(tochka[max2]);
    std::cout << "�����:" << std::endl;
    centr = vector_sum(tochka[max1], tochka[max2]);
//    vector_print(centr);
    centr = vector_YnC(centr,0.5);
    vector_print(centr);
//    All_Obj[nomer_obj].Position = centr;
    (*Some).Position = centr;
    vector_print((*Some).Position);
//    std::cout << std::endl << "�������!" << std::endl;
//    vector_print(centr);
//    vector_print((*Some).Position);
//    vector_print(All_Obj[nomer_obj].Position);
//    std::cout << "�� ������ ���� ��� �����..." << std::endl << std::endl;
//    std::cout << "�������: " << L << std::endl;
    L /= 2;
    std::cout << "������: " << L << std::endl;
    return L;
}

void Resolution()
{
    HWND hwnd;
    char Title[1024];
    int iWidth = GetSystemMetrics(SM_CXSCREEN);  // ������ ������ �� �����������
    int iHeight = GetSystemMetrics(SM_CYSCREEN); // ������ ������ �� ���������
    int Y = iHeight/4, X = iWidth/4;
    GetConsoleTitle(Title, 1024); // ������ ��� ����
    // ��� GetModuleFileName(NULL,Title, sizeof(Title));
    hwnd = FindWindow(NULL, Title);
    MoveWindow(hwnd, X, Y, iWidth/2, iHeight/2, true);

    std::cout << "������� ���� ���������� ������ (������ * ������) ��� �������� �� ������������:" << std::endl;
    std::cout << "1) ���� ���������� (" << iWidth << "x" << iHeight << ")\n2) 800x400\n3) 1024x512\n4) 1366x768\n-) ������������ ����������" << std::endl;
    int choise = getch();
//    std::cout << "Choise is: " << choise << std::endl;
//    Sleep(2000);
//	std::cout << flush;
//    int choise;
//    std::cin >> choise;
    switch(choise){
    case 49:
        resolution.shirina = iWidth;
        resolution.vysota = iHeight;
        break;
    case 50:
        resolution.shirina = 800;
        resolution.vysota = 400;
        break;
    case 51:
        resolution.shirina = 1024;
        resolution.vysota = 512;
        break;
    case 52:
        resolution.shirina = 1366;
        resolution.vysota = 768;
        break;
//    case 53:
//        resolution.shirina = 600;
//        resolution.vysota = 600;
//        break;
    default:
//        resolution.shirina = choise;
        std::cin >> resolution.shirina >> resolution.vysota;
        break;
    }
    std::cout << "������� ���������� ���� ���������� (��� ��������� ������������������): ";
    std::cin >> THREAD_NUMBER;
    Thr_Param = new int[THREAD_NUMBER+1];
    for(int i = 0; i <= THREAD_NUMBER+1; i++){
        Thr_Param[i] = (resolution.vysota/THREAD_NUMBER)*i;
    }
    std::cout << "������� ����� ����� ������ � ������� ������/������ (16�16, ��������)\n - ������ �������� ����� ��� ���������������" << std::endl;
    std::cin >> block.shirina >> block.vysota;
    Drevo_Blocks = new Obj_Numeration_Block*[(resolution.vysota/block.vysota)];
    for(int i = 0; i < resolution.vysota/block.vysota; i++)
        Drevo_Blocks[i] = new Obj_Numeration_Block[(resolution.shirina/block.shirina)];
}



