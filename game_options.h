void Resolution_out();
void Obj_Create_New(ofstream& Obj_adr_end);
void Obj_Radius_Maker(Obj *All_Obj);
Obj* Obj_Maker(Obj *All_Obj, ifstream& Obj_adr);
double Radius_finder(Obj *Some);
void Resolution();



void Resolution_out()
{
    cout << resolution.shirina << " " << resolution.vysota;
}

void Obj_Create_New(ofstream& Obj_adr_end)
{
    short answer = 0, ans_1, ans_2, ans_3;
    cout << "������� ��� ������ �������: ";
    char tName[100] = {"Game_Objects/"}, Name[100], NameSuffics[] = {".txt"}, TempName[100];
    int N_meshes = 0;
    cin >> TempName;
    strcat(tName,TempName);
    strcat(tName,NameSuffics);
    OemToChar(tName,Name);
    ofstream obj_new(Name);
//    obj_new << endl;

    cout << "������� ������ ��� �����: ";
    TempMesh *mesh_now;
    mesh_now = new TempMesh;
    XYZ A[3];
    for(int i = 0; i < 3; i++){
        cin >> A[i].x >> A[i].y >> A[i].z;
        mesh_now->tMesh[i] = A[i];
    }
    TempMesh *first;
    first = new TempMesh;
    first->next = mesh_now;
    N_meshes++;
    cout << "��� ������ ������?/n1)�������� ����� � ����������� ����/n2)������� ����� ���/3)��������� ������ � ������" << endl;
    while(answer!=3){
        cin >> answer;
        if(answer == 1){
            cout << "����� ����� �������?" << endl;
            for(int i = 0; i < 3; i++){
                cout << i + 1 << ") ";
                vector_print(A[i]);
            }
            cin >> ans_1 >> ans_2;
            while((ans_1 != 1 && ans_1 != 2 && ans_1 != 3) || (ans_2 != 1 && ans_2 !=2 && ans_2 != 3) || (ans_1 == ans_2)){
                cout << "������������ �����, 1, 2 ��� 3!\n������ ��� ���" << endl;
                cin >> ans_1 >> ans_2;
            }
            cout << endl;

            cout << "������� ���������� ����� �����: ";
            if(ans_1 != 1 && ans_2 != 1)
                ans_3 = 0;
            if(ans_1 != 2 && ans_2 != 2)
                ans_3 = 1;
            if(ans_1 != 3 && ans_2 != 3)
                ans_3 = 2;
            cin >> A[ans_3].x >> A[ans_3].y >> A[ans_3].z;
            TempMesh *TempA = new TempMesh;
            for(int i = 0; i < 3; i++)
                TempA->tMesh[i] = A[i];
            mesh_now->next = TempA;
            mesh_now = mesh_now->next;
            N_meshes++;
            cout << "������. ��� ������?" << endl;
            continue;
        }
        if(answer == 2){
            cout << "������� ���������� ���� ����� �����:" << endl;
            for(int i = 0; i < 3; i++)
                cin >> A[i].x >> A[i].y >> A[i].z;
            TempMesh *TempA = new TempMesh;
            for(int i = 0; i < 3; i++)
                TempA->tMesh[i] = A[i];
            mesh_now->next = TempA;
            mesh_now = mesh_now->next;
            N_meshes++;
            cout << "������. ��� ������?" << endl;
            continue;
        }
        if(answer == 3){
            mesh_now = first->next;
            obj_new << N_meshes;
            for(int i = 0; i < N_meshes; i++){
                for(int j = 0; j < 3; j++)
                    obj_new << endl << mesh_now->tMesh[j].x << " " << mesh_now->tMesh[j].y << " " << mesh_now->tMesh[j].z;
                mesh_now = mesh_now->next;
            }
            obj_new.close();

            ifstream obj_new_read(Name);
            Obj New;
            New.Objj(obj_new_read);
            double L;
            L = Radius_finder(&New);
            cout << "L of new object is: " << L << endl;
            obj_new_read.close();
            ofstream obj_new(Name, ios_base::app);
            obj_new << endl << L;
            obj_new << endl << New.Position.x << " " << New.Position.y << " " << New.Position.z;
            cout << "������� ����� ������� � ������� RGBF �� 0 �� 255" << endl;
            RGBF color_new;
            cin >> color_new.r >> color_new.g >> color_new.b >> color_new.f;
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
            obj_new << endl << color_new.r << " " << color_new.g << " " << color_new.b << " " << color_new.f;
            Obj_adr_end << endl << Name;
            obj_new.close();
            break;
        }
        if(answer!=1&&answer!=2&&answer!=3){
            cout << "����� ���������, �����..." << endl;
            continue;
        }
    }
    cout << endl << "�������!" << endl << endl;
}

void Obj_Radius_Maker(Obj *All_Obj)
{
//    for(int i = 0; i < Obj_N; i++)
//        cout << "Object " << i + 1 << " live is " << All_Obj[i].live << endl;
    int k = -1;
    char t[100];
    short choose = 1;
    while(choose==1){
        cout << "�������� ������ ��� ������� �������" << endl;
        cin >> k;
        while(k < 1 || k > Obj_N){
            cout << "������ ������ �� ����������, �������� ������" << endl;
            cin >> k;
        }
        if(All_Obj[k - 1].live == 0){
            cout << "� ���� �������� ��������, �������� ������" << endl;
            cin >> k;
            while(k < 1 || k > Obj_N){
                cout << "������ ������ �� ����������, �������� ������" << endl;
                cin >> k;
            }
            if(All_Obj[k - 1].live == 0){
                cout << "� ���� ���� ��������... ��� ��� (��� -1 ��� ������)" << endl;
                cin >> k;
                if(k == -1){
                    cout << "������� �������!" << endl;
                    break;
                }
                while(k < 1 || k > Obj_N){
                    cout << "������ ������ �� ����������, �������� ������" << endl;
                    cin >> k;
                    if(k == -1){
                        cout << "������� �������!" << endl;
                        break;
                    }
                }
                while(All_Obj[k - 1].live == 0){
                    cout << "D'oh! � � ����..." << endl;
                    cin >> k;
                    if(k == -1){
                        cout << "������� �������!" << endl;
                        break;
                    }
                    while(k < 1 || k > Obj_N){
                        cout << "������ ������ �� ����������, �������� ������" << endl;
                        cin >> k;
                        if(k == -1){
                            cout << "������� �������!" << endl;
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
//        cout << "Radius is " << L << endl;
        for(int i = 0; i < 100; i++){
            t[i] = All_Obj[k-1].Name[i];
        }
        ifstream check(t);
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
        cout << "Counter = " << counter << endl;
        if(counter%9 == 0){
            ofstream write(t, ios_base::app);
            cout << "�� �������� �� ������, �� �������. ��������..." << endl;
            write << endl << L;
            All_Obj[k-1].Radius = L;
            write << endl << All_Obj[k-1].Position.x << " " << All_Obj[k-1].Position.y << " " << All_Obj[k-1].Position.z;
            write.close();
            cout << "�������. ��� ��� ������?" << endl;
//            cout << "Saved. Do next?" << endl;
            cin >> choose;
        }
        else {
            if((counter-1)%9 == 0){
                int tt, ll;
                tt = temp*10000;
                ll = L*10000;
                if(ll == tt){
                    cout << "��� ����� ������, ������� ���. �����..." << endl << "������� ��������� ������?" << endl;;
                    ofstream write(t, ios_base::app);
                    write << endl << All_Obj[k-1].Position.x << " " << All_Obj[k-1].Position.y << " " << All_Obj[k-1].Position.z;
                }
                else cout << "((or) some shit in the end of the file:)" << endl << "������� ����� ������� ������?" << endl;
//                cout << "Already have Radius (or some shit in the end of the file:)" << endl << "Choose else object?" << endl;
            }
            else if ((counter-4)%9 == 0) {
                int tt, ll;
                tt = temp_prev3*10000;
                ll = L*10000;
                if(ll != tt){
                    cout << "������������ ������ ������� � �������, �� ��� ������� ������ �� �����." << endl;
                }
                else if((All_Obj[k-1].Position.x == temp_prev2) && (All_Obj[k-1].Position.y == temp_prev1) && (All_Obj[k-1].Position.z == temp)){
                    cout << "��� ������� ������ �������" << endl;
                }
                else cout << "������� � ����� �� ����� ����������������" << endl;
            }
            else cout << "������ ������..." << endl << "������� ������?" << endl;
            cin >> choose;
        }
    }
}

Obj* Obj_Maker(Obj *All_Obj, ifstream& Obj_adr)
{
    if(!Obj_adr.is_open()){
        cout << "*******�� ���� ����� ������ �������� ����*******" << endl;
//        cout << "Can't find Game Objects adresses" << endl;
        Sleep(5000);
    }

    char s[100], t[100];
    cout << "������� ���������� ��������..." << endl;
    while(!Obj_adr.eof()){
        Obj_adr >> s;
        ::Obj_N++;
    }
    cout << "����� ��������..." << endl;
    Obj_adr.seekg(0,ios_base::beg);
    All_Obj = new Obj[MAX_OBJECTS];
    int k = 0;

    while(!Obj_adr.eof()){
        Obj_adr >> s;
        OemToChar(s,t);
        ifstream obj_1(t);
        if (!obj_1.is_open()){
            cout << "������ � ������ " << s << "." << endl;
            All_Obj[k].live = 0;
            k++;
            continue;
        } else {cout << "���� " << s << " ������" << endl;}
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
    cout << endl << "�����:" << endl << endl;
    for(int i = 0; i < (*Some).num_meshs*3; i++){
        vector_print(tochka[i]);
    }
    cout << endl << "�����:" << endl << endl;
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
//                    cout << "����� ����� " << i+1 << " " << j+1 << "\t";
                    cout << "tL: " << tL << " L: " << L << endl;
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
//            cout << "����� ����� " << i+1 << " " << j+1 << "\t";
            cout << "tL: " << tL << " L: " << L << endl;
        }
    }
//    cout << "������ �����: " << max1+1 << " " << max2+1 << endl;
//    cout << "��� �����:";
//    vector_print(tochka[max1]);
//    vector_print(tochka[max2]);
    cout << "�����:" << endl;
    centr = vector_sum(tochka[max1], tochka[max2]);
//    vector_print(centr);
    centr = vector_YnC(centr,0.5);
    vector_print(centr);
//    All_Obj[nomer_obj].Position = centr;
    (*Some).Position = centr;
    vector_print((*Some).Position);
//    cout << endl << "�������!" << endl;
//    vector_print(centr);
//    vector_print((*Some).Position);
//    vector_print(All_Obj[nomer_obj].Position);
//    cout << "�� ������ ���� ��� �����..." << endl << endl;
//    cout << "�������: " << L << endl;
    L /= 2;
    cout << "������: " << L << endl;
    return L;
}

void Resolution()
{
    HWND hwnd;
    char Title[1024];
    int iWidth = GetSystemMetrics(SM_CXSCREEN);  // ������ ������ �� �����������
    int iHeight = GetSystemMetrics(SM_CYSCREEN); // ������ ������ �� ���������
    EKRAN.shirina = iWidth;
    EKRAN.vysota = iHeight;
    cout << "������� ���������� �������� (������ * ������) ��� �������� �� ������������:" << endl;
    cout << "1) ���������� ������ (" << iWidth << "x" << iHeight << ")\n2) 800x400\n3) 1024x512\n4) 1366x768\n-) ������������ ����������" << endl;
    int choise = getch();
//    cout << "Choise is: " << choise << endl;
//    Sleep(2000);
//	cout << flush;
//    int choise;
//    cin >> choise;
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
        cin >> resolution.shirina >> resolution.vysota;
        break;
    }
    cout << "�������� ���� �� ���� ����� (��������, � ������� ��������)?" << endl;
    if(getch() == 49)
        PARAM_EKRAN_SCALE = 1;
    else
        PARAM_EKRAN_SCALE = 0;
    EKRAN_SCALE_X = ((float)EKRAN.shirina/(float)resolution.shirina);
    EKRAN_SCALE_Y = ((float)EKRAN.vysota/(float)resolution.vysota);
    int Y = 0, X = 0;
    if(choise != 52 && choise != 49){
        Y = 0;
        X = resolution.shirina;
    }
    else{
        Y = resolution.vysota/4;
        X = resolution.shirina/3;
    }
    GetConsoleTitle(Title, 1024); // ������ ��� ����
    // ��� GetModuleFileName(NULL,Title, sizeof(Title));
    hwnd = FindWindow(NULL, Title);
    if(choise != 52 && choise != 49)
        MoveWindow(hwnd, X, Y, iWidth - resolution.shirina, iHeight, true);
    else
        MoveWindow(hwnd, X, Y, resolution.shirina/3, iHeight/2, true);

    cout << "������� ���������� ���� ���������� (��� ��������� ������������������, � �������, 4): ";
//    cin >> THREAD_NUMBER;
    THREAD_NUMBER = 4;
    Thr_Param = new int[THREAD_NUMBER+1];
    for(int i = 0; i <= THREAD_NUMBER+1; i++){
        Thr_Param[i] = (resolution.vysota/THREAD_NUMBER)*i;
    }
    cout << "������� ����� ����� ������ � ������� ������/������ (��������, 16�16)\n - ������ �������� ����� ��� ���������������" << endl;
//    cin >> block.shirina >> block.vysota;
    block.shirina = 8;
    block.vysota = 8;
}



