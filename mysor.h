
DWORD WINAPI Screen_Pixels1(LPVOID param)
{
//    GDM_Picture[i][j];
//    Person_Position;
//    Person_dEYE;
//    std::cout << "Scr_Pix1" << std::endl;
//    while(Picture_Complited1==1){Sleep(1);}
//    std::cout << "Scr_Pix1in" << std::endl;
    int RES1 = 1, RES2 = 0;
//    RES1 = Scene_Obj();
//    Scene_Obj_Nomera = ;
    if(RES1 == 1){
        for(int i = 0; i < (resolution.vysota/4); i++)
        {
            for(int j = 0; j < resolution.shirina; j++)
            {
                for(int k = 0; k < Obj_Alive.n; k++)
                {
//                    if(Shar_i_OV(All_Obj[Obj_Alive.num[k]].Radius, All_Obj[Obj_Alive.num[k]].Position, Person_Position, GDM_Picture[i][j]) == 1)
//                    {
                        RES2 = Ray_Trastd::cing_For_Picture(Obj_Alive.num[k], Person_Position, GDM_Picture[i][j]);
                        if(RES2 == 1){
                            pixels[i*resolution.shirina*4+j*4] = All_Obj[Obj_Alive.num[k]].Color.b;
                            pixels[i*resolution.shirina*4+j*4+1] = All_Obj[Obj_Alive.num[k]].Color.g;
                            pixels[i*resolution.shirina*4+j*4+2] = All_Obj[Obj_Alive.num[k]].Color.r;
                            pixels[i*resolution.shirina*4+j*4+3] = All_Obj[Obj_Alive.num[k]].Color.f;
                            break;
                        }
//                    }
                }

                if(RES2 == 0){
                    if((GDM_Picture[i][j].z - Person_Position.z) > 0){
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

            }
        }
    }
    if(RES1 == 0){
        for(int i = 0; i < (resolution.vysota/4); i++){
            for(int j = 0; j < resolution.shirina; j++){
                    if((GDM_Picture[i][j].z - Person_Position.z) > 0){
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
    Picture_Complited[0] = 1;
    return 0;
}

DWORD WINAPI Screen_Pixels2(LPVOID param)
{
//    GDM_Picture[i][j];
//    Person_Position;
//    Person_dEYE;
//    std::cout << "Scr_Pix2" << std::endl;
//    while(Picture_Complited2==1){Sleep(1);}
//    std::cout << "Scr_Pix2in" << std::endl;
    int RES1 = 1, RES2 = 0;
//    RES1 = Scene_Obj();
//    Scene_Obj_Nomera = ;
    if(RES1 == 1){
        for(int i = (resolution.vysota/4); i < (resolution.vysota/2); i++)
        {
            for(int j = 0; j < resolution.shirina; j++)
            {
                for(int k = 0; k < Obj_Alive.n; k++)
                {
//                    if(Shar_i_OV(All_Obj[Obj_Alive.num[k]].Radius, All_Obj[Obj_Alive.num[k]].Position, Person_Position, GDM_Picture[i][j]) == 1)
//                    {
                        RES2 = Ray_Trastd::cing_For_Picture(Obj_Alive.num[k], Person_Position, GDM_Picture[i][j]);
                        if(RES2 == 1){
                            pixels[i*resolution.shirina*4+j*4] = All_Obj[Obj_Alive.num[k]].Color.b;
                            pixels[i*resolution.shirina*4+j*4+1] = All_Obj[Obj_Alive.num[k]].Color.g;
                            pixels[i*resolution.shirina*4+j*4+2] = All_Obj[Obj_Alive.num[k]].Color.r;
                            pixels[i*resolution.shirina*4+j*4+3] = All_Obj[Obj_Alive.num[k]].Color.f;
                            break;
                        }
//                    }
                }

                if(RES2 == 0){
                    if((GDM_Picture[i][j].z - Person_Position.z) > 0){
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

            }
        }
    }
    if(RES1 == 0){
        for(int i = (resolution.vysota/4); i < (resolution.vysota/2); i++){
            for(int j = 0; j < resolution.shirina; j++){
                    if((GDM_Picture[i][j].z - Person_Position.z) > 0)
                    if((GDM_Picture[i][j].z - Person_Position.z) > 0){
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
    Picture_Complited[1] = 1;
    return 0;
}

DWORD WINAPI Screen_Pixels3(LPVOID param)
{
//    GDM_Picture[i][j];
//    Person_Position;
//    Person_dEYE;
//    std::cout << "Scr_Pix1" << std::endl;
//    while(Picture_Complited1==1){Sleep(1);}
//    std::cout << "Scr_Pix1in" << std::endl;
    int RES1 = 1, RES2 = 0;
//    RES1 = Scene_Obj();
//    Scene_Obj_Nomera = ;
    if(RES1 == 1){
        for(int i = (resolution.vysota/2); i < ((resolution.vysota/4)*3); i++)
        {
            for(int j = 0; j < resolution.shirina; j++)
            {
                for(int k = 0; k < Obj_Alive.n; k++)
                {
//                    if(Shar_i_OV(All_Obj[Obj_Alive.num[k]].Radius, All_Obj[Obj_Alive.num[k]].Position, Person_Position, GDM_Picture[i][j]) == 1)
//                    {
                        RES2 = Ray_Trastd::cing_For_Picture(Obj_Alive.num[k], Person_Position, GDM_Picture[i][j]);
                        if(RES2 == 1){
                            pixels[i*resolution.shirina*4+j*4] = All_Obj[Obj_Alive.num[k]].Color.b;
                            pixels[i*resolution.shirina*4+j*4+1] = All_Obj[Obj_Alive.num[k]].Color.g;
                            pixels[i*resolution.shirina*4+j*4+2] = All_Obj[Obj_Alive.num[k]].Color.r;
                            pixels[i*resolution.shirina*4+j*4+3] = All_Obj[Obj_Alive.num[k]].Color.f;
                            break;
                        }
//                    }
                }

                if(RES2 == 0){
                    if((GDM_Picture[i][j].z - Person_Position.z) > 0){
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

            }
        }
    }
    if(RES1 == 0){
        for(int i = (resolution.vysota/2); i < ((resolution.vysota/4)*3); i++){
            for(int j = 0; j < resolution.shirina; j++){
                    if((GDM_Picture[i][j].z - Person_Position.z) > 0){
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
    Picture_Complited[2] = 1;
    return 0;
}

DWORD WINAPI Screen_Pixels4(LPVOID param)
{
//    GDM_Picture[i][j];
//    Person_Position;
//    Person_dEYE;
//    std::cout << "Scr_Pix1" << std::endl;
//    while(Picture_Complited1==1){Sleep(1);}
//    std::cout << "Scr_Pix1in" << std::endl;
    int RES1 = 1, RES2 = 0;
//    RES1 = Scene_Obj();
//    Scene_Obj_Nomera = ;
    if(RES1 == 1){
        for(int i = ((resolution.vysota/4)*3); i < resolution.vysota; i++)
        {
            for(int j = 0; j < resolution.shirina; j++)
            {
                for(int k = 0; k < Obj_Alive.n; k++)
                {
//                    if(Shar_i_OV(All_Obj[Obj_Alive.num[k]].Radius, All_Obj[Obj_Alive.num[k]].Position, Person_Position, GDM_Picture[i][j]) == 1)
//                    {
                        RES2 = Ray_Trastd::cing_For_Picture(Obj_Alive.num[k], Person_Position, GDM_Picture[i][j]);
                        if(RES2 == 1){
                            pixels[i*resolution.shirina*4+j*4] = All_Obj[Obj_Alive.num[k]].Color.b;
                            pixels[i*resolution.shirina*4+j*4+1] = All_Obj[Obj_Alive.num[k]].Color.g;
                            pixels[i*resolution.shirina*4+j*4+2] = All_Obj[Obj_Alive.num[k]].Color.r;
                            pixels[i*resolution.shirina*4+j*4+3] = All_Obj[Obj_Alive.num[k]].Color.f;
                            break;
                        }
//                    }
                }

                if(RES2 == 0){
                    if((GDM_Picture[i][j].z - Person_Position.z) > 0){
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

            }
        }
    }
    if(RES1 == 0){
        for(int i = ((resolution.vysota/4)*3); i < resolution.vysota; i++){
            for(int j = 0; j < resolution.shirina; j++){
                    if((GDM_Picture[i][j].z - Person_Position.z) > 0){
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
    Picture_Complited[3] = 1;
    return 0;
}

XYZ get_pixel(mesh M, vizor P)
{
    XYZ AV, OS, OV, PIXEL;
    double pv, ov, vs, alpha, k;
    AV = o_vector(M.A, P.V);
    pv = vector_SP(M.n, AV);
    OV = o_vector(P.O, P.V);
    ov = vector_module(OV);
    alpha = vector_SP(M.n, OV) / ov;
    vs = -pv / alpha;
    OS = OV;
    k = vs / ov;
    OV = vector_YnC(OV, k);
    OS = vector_sum(OS, OV);
    PIXEL = vector_return_tochky(OS, P.O);

    return PIXEL;
}

void screen_view(mesh A, vizor Player, std::ofstream& out) // œ≈–≈œ»—¿“‹, ƒ¿ÕÕ¿ﬂ - ƒÀﬂ ≈ƒ»Õ»◊ÕŒ√Œ —À”◊¿ﬂ!!!!!
{
    XYZ PIXEL;
    auto begin = steady_clock::now();
    double dVy, dSh; // Õ≈ «¿¡€“‹ - œŒ ¿ ¡≈—œŒÀ≈«Õ€, œ–»¬ﬂ«¿“‹

    for(int i = 0; i < resolution.vysota; i++){
//        out << "Line " << i << " is ";
        Player.V.y -= 3;
        for(int j = 0; j < resolution.shirina; j++){
            Player.V.y += 0.002;
            PIXEL = get_pixel(A, Player);
//            out << PIXEL.x << " " << PIXEL.y << " " << PIXEL.z << " ";
        }
//        out << std::endl;
        Player.V.y = Player.V1.y;
        Player.V.z -= 0.002;
    }
    Player.V.z = Player.V1.z;
    auto end = steady_clock::now();
    auto elapsed_ms = duration_cast<milliseconds>(end - begin);
    std::cout << "Time spend: " << elapsed_ms.count() << " ms" << std::endl;
}

void Player_eye(VOID)
{
    HANDLE threads[COUNT_THREADS];
//    threads[0] = CreateThread(NULL, 0, THR_exit_catch, NULL, 0, 0);
    threads[0] = CreateThread(NULL, 0, THR_Vn_Creator, NULL, 0, 0);
//    threads[2] = CreateThread(NULL, 0, Mesh_Finder, NULL, 0, 0);
    WaitForMultipleObjects(COUNT_THREADS, threads, TRUE, INFINITE);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE nPrevInstance, LPSTR lpCmdLine, int CmdShow)
{
    char str[] = "Fuck\nReally shit";
    MessageBox(NULL, str, "My Window", MB_ICONSTOP);
}

DWORD WINAPI THR_exit_catch(LPVOID param)
{
    unsigned char temp;
    while(f_exit != 27){
//        std::cin >> ::f_exit;
        temp = getch();
        f_exit = temp;
        if(f_exit == 224 && ((f_exit = getch()) == 72)){  /// w
            Person_Position.x++;
        }
        else if(f_exit == 75)
            Person_Position.y++;
        else if(f_exit == 77)
            Person_Position.y--;
        else if(f_exit == 80)
            Person_Position.x--;
//        if(f_exit == 224 && (getch() == 72)){  /// w
//            Person_Position.x++;
//        }
//        if(f_exit == 97 || f_exit == 65){   /// a
//            Person_Position.y++;
//        }
//        if(f_exit == 115 || f_exit == 83){  /// s
//            Person_Position.x--;
//        }
//        if(f_exit == 100 || f_exit == 68){  /// d
//            Person_Position.y--;
//        }
    }
    ExitThread(0);
}

int Scene_Obj() /// double L_Eye_Obj
{
    /// Vzglyad_Center
    int kolvo = 0;
    int Scene_Obj_i[Obj_N];         /// ‚˚ÌÂÒÚË ‚ „ÎÓ·‡Î Ë Á‡‰‡Ú¸ ‚ main'e
    for(int i = 0; i < Obj_N; i++){
//        if((Shar_i_OV(All_Obj[i].Radius, All_Obj[i].Position, Person_Position, Person_dEYE)) == 1){ /// Õ≈ “¿ ‘”Õ ÷»ﬂ !!!!!!!
        if((Shar_v_Ecrane(All_Obj[i].Radius, All_Obj[i].Position)) == 1){
            Scene_Obj_i[kolvo] = i;
            kolvo++;
        }
    }
    Obj_OnScene.n = kolvo;
    for(int ii = 0; ii < kolvo; ii++)
        Scene_Obj_Nomera[ii+1] = Scene_Obj_i[ii];
        Obj_OnScene.num[ii] =
    if(kolvo == 0)
        return 0;
    if(kolvo > 0)
        return 1;
    return -1;
}

DWORD WINAPI Screen_Pixels(LPVOID param)
{
//    GDM_Picture[i][j];
//    Person_Position;
//    Person_dEYE;
    while(Picture_Complited!=0){Sleep(1);}
    int RES1 = 1, RES2 = 0;
//    RES1 = Scene_Obj();
    Scene_Obj_Nomera = new unsigned int[3+1];
    Scene_Obj_Nomera[0] = 3;
    for(int ii = 0; ii < 3; ii++)
        Scene_Obj_Nomera[ii+1] = ii;
//    Scene_Obj_Nomera = ;
    if(RES1 == 1){
        for(int i = 0; i < resolution.vysota; i++)
        {
            for(int j = 0; j < resolution.shirina; j++)
            {
                for(int k = 0; k < Obj_Alive.n; k++)
                {
//                    if(Shar_i_OV(All_Obj[Obj_Alive.num[k]].Radius, All_Obj[Obj_Alive.num[k]].Position, Person_Position, GDM_Picture[i][j]) == 1)
//                    {
                        RES2 = Ray_Trastd::cing_For_Picture(Obj_Alive.num[k], Person_Position, GDM_Picture[i][j]);
                        if(RES2 == 1){
                            pixels[i*resolution.shirina*4+j*4] = All_Obj[Obj_Alive.num[k]].Color.b;
                            pixels[i*resolution.shirina*4+j*4+1] = All_Obj[Obj_Alive.num[k]].Color.g;
                            pixels[i*resolution.shirina*4+j*4+2] = All_Obj[Obj_Alive.num[k]].Color.r;
                            pixels[i*resolution.shirina*4+j*4+3] = All_Obj[Obj_Alive.num[k]].Color.f;
                            break;
                        }
//                    }
                }

                if(RES2 == 0){
                    pixels[i*resolution.shirina*4+j*4] = 220;
                    pixels[i*resolution.shirina*4+j*4+1] = 50;
                    pixels[i*resolution.shirina*4+j*4+2] = 10;
                    pixels[i*resolution.shirina*4+j*4+3] = 0;
                }
                if(RES2 == -1)
                    f_exit = 27;

            }
        }
    }
    if(RES1 == 0){
        for(int i = 0; i < resolution.vysota; i++){
            for(int j = 0; j < resolution.shirina; j++){
                pixels[i*resolution.shirina*4+j*4] = 220;
                pixels[i*resolution.shirina*4+j*4+1] = 50;
                pixels[i*resolution.shirina*4+j*4+2] = 10;
                pixels[i*resolution.shirina*4+j*4+3] = 0;
            }
        }
    }
    if(RES1 == -1)
        f_exit = 27;
    Picture_Complited = 1;
    return 0;
}

int Shar_v_Ecrane(float R, XYZ S)
{
    XYZ OV, OS, O = Person_Position, V = Person_dEYE;
    float lOS;
    OV.x = V.x - O.x;
    OV.y = V.y - O.y;
    OV.z = V.z - O.z;
    OS.x = S.x - O.x;
    OS.y = S.y - O.y;
    OS.z = S.z - O.z;
    lOS = vector_module(OS);
    float sinB, cosA;
    sinB = R/lOS;
    OS.x /= lOS;
    OS.y /= lOS;
    OS.z /= lOS;

    lOS = SqrtInvE(OV.x*OV.x + OV.y*OV.y + OV.z*OV.z);
    OV.x = OV.x*lOS;
    OV.y = OV.y*lOS;
    OV.z = OV.z*lOS;

    cosA = OV.x*OS.x + OV.y*OS.y + OV.z*OS.z;
    if((cosA + sinB) > resolution.Person_EYE_Alpha){
//        std::cout << "NEW V EKRANE" << std::endl;
        return 1;
    }
    else if ((cosA + sinB) <= resolution.Person_EYE_Alpha){
//        std::cout << "NEW NE V EKRANE" << std::endl;
        return 0;
    }
    else {
//        std::cout << "NEW some shit happened..." << std::endl;
        return -2;
    }
    return -1;
}

DWORD WINAPI Screen_Pixels_With_Tree(LPVOID param)
{
    int thr_num = (int)param;
//    std::cout << thr_num;
//    GDM_Picture[i][j];
//    Person_Position;
//    Person_dEYE;
//    std::cout << "Scr_Pix1" << std::endl;
//    while(Picture_Complited1==1){Sleep(1);}
//    std::cout << "Scr_Pix1in" << std::endl;
    int RES1 = 1, RES2 = 0;
//    RES1 = Scene_Obj();
//    Scene_Obj_Nomera = ;
    if(RES1 == 1){
        for(int i = Thr_Param[thr_num]; i < Thr_Param[thr_num+1]; i++)
        {
            for(int j = 0; j < resolution.shirina; j++)
            {
                for(int k = 0; k < Obj_Alive.n; k++)
                {
//                    if(Shar_i_OV(All_Obj[Obj_Alive.num[k]].Radius, All_Obj[Obj_Alive.num[k]].Position, Person_Position, GDM_Picture[i][j]) == 1)
//                    {
                        RES2 = Ray_Trastd::cing_For_Picture(Obj_Alive.num[k], Person_Position, GDM_Picture[i][j]);
                        if(RES2 == 1){
                            pixels[i*resolution.shirina*4+j*4] = All_Obj[Obj_Alive.num[k]].Color.b;
                            pixels[i*resolution.shirina*4+j*4+1] = All_Obj[Obj_Alive.num[k]].Color.g;
                            pixels[i*resolution.shirina*4+j*4+2] = All_Obj[Obj_Alive.num[k]].Color.r;
                            pixels[i*resolution.shirina*4+j*4+3] = All_Obj[Obj_Alive.num[k]].Color.f;
                            break;
                        }
//                    }
                }

                if(RES2 == 0){
                    if((GDM_Picture[i][j].z - Person_Position.z) > 0){
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

            }
        }
    }
    if(RES1 == 0){
        for(int i = Thr_Param[thr_num]; i < Thr_Param[thr_num+1]; i++){
            for(int j = 0; j < resolution.shirina; j++){
                    if((GDM_Picture[i][j].z - Person_Position.z) > 0){
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
//    std::cout << "Exited";
    return 0;
}

int Shar_i_OV_STARYI(double R, XYZ S, XYZ O, XYZ V) /// R - ‡‰ËÛÒ, S - ˆÂÌÚ ÓÍÛÊÌÓÒÚË, O - ÔÓÁËˆËˇ ÒÏÓÚˇ˘Â„Ó, V - ‚ÁÓ ÒÏÓÚˇ˘Â„Ó
{
//    double cosAlpha, l, lOS;
//
//    V.x = V.x - O.x;
//    V.y = V.y - O.y;
//    V.z = V.z - O.z;
//    S.x = S.x - O.x;
//    S.y = S.y - O.y;
//    S.z = S.z - O.z;
//    lOS = SqrtInv(S.x*S.x + S.y*S.y + S.z*S.z);
//    l = SqrtInvE(V.x*V.x + V.y*V.y + V.z*V.z);
//    V.x = V.x*l;
//    V.y = V.y*l;
//    V.z = V.z*l;
////                  0 1 2 1 1 2 6 0 0 2
//    l = SqrtInvE(S.x*S.x + S.y*S.y + S.z*S.z);
//    S.x = S.x*l;
//    S.y = S.y*l;
//    S.z = S.z*l;
//    cosAlpha = V.x*S.x + V.y*S.y + V.z*S.z;
//    cosAlpha = SqrtInv(1 - (cosAlpha*cosAlpha));
//    l = cosAlpha * lOS;
//
//    if(l <= R){
////        std::cout << "YES!" << std::endl;
//        return 1;
//    }
//    else {
////        std::cout << "NO!" << std::endl;
//        return 0;
//    }
//    return -1;
}
int Shar_i_OV(double R, XYZ S, XYZ O, XYZ V)            /// 180 - 195 ms
{
    float lOS, sinA;
    V.x = V.x - O.x;
    V.y = V.y - O.y;
    V.z = V.z - O.z;
    S.x = S.x - O.x;
    S.y = S.y - O.y;
    S.z = S.z - O.z;
    lOS = SqrtInv(S.x*S.x + S.y*S.y + S.z*S.z);
    sinA = R/lOS;
    S.x /= lOS;
    S.y /= lOS;
    S.z /= lOS;

    lOS = SqrtInvE(V.x*V.x + V.y*V.y + V.z*V.z);
    V.x = V.x*lOS;
    V.y = V.y*lOS;
    V.z = V.z*lOS;

    lOS = V.x*S.x + V.y*S.y + V.z*S.z;
    lOS = lOS * lOS;
    sinA = sinA * sinA;
    lOS = lOS + sinA;
    if(lOS >= 1){
//        std::cout << "NEW Na okr" << std::endl;
        return 1;
    }
    else if (lOS < 1){
//        std::cout << "NEW No" << std::endl;
        return 0;
    }
    else {
//        std::cout << "NEW Yes!" << std::endl;
        return -2;
    }
    return -1;
}

LRESULT CALLBACK WindowProcedure_FULL_VERSION_WITH_2_BUFS (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
         case WM_CREATE:
         {
              SetTimer (hwnd, 1, 1, NULL);
         }
         break;

        case WM_TIMER:
            {
            if(BUF == 1){
                {
                    if (OpenClipboard (hwnd))
                    {
                        Cursor_dt = dCursor(Cursor_dt);
                        if(Cursor_dt.x > 0)
                            dR += Cursor_dt.x;
                        else
                            dB += -Cursor_dt.x;
                        if(Cursor_dt.y > 0)
                            dG += Cursor_dt.y;
                        else{
                            dG += Cursor_dt.y;
                            dB += Cursor_dt.y;
                            dR += Cursor_dt.y;
                        }
                        if(dR < 0)
                            dR = 0;
                        if(dB < 0)
                            dB = 0;
                        if(dG < 0)
                            dG = 0;
                        if(dR > 255)
                            dR = 255;
                        if(dB > 255)
                            dB = 255;
                        if(dG > 255)
                            dG = 255;

                        for (int i=0; i<768; i ++){
                                for (int j = 0; j < 1344*4; j++){
                                    for (int k = 0; k < 4; k++){
                                        pixels[(i*1344*4)+j]=0+dB;
                                        pixels[(i*1344*4)+j+1]=0+dG;
                                        pixels[(i*1344*4)+j+2]=0+dR;
                                        pixels[(i*1344*4)+j+3]=0+dWhat_is_it;
                                        j += 4;
                                    }
                                    j--;
                                }
                        }



                        fff++;
                        if(fff == 8)
                            fff = 0;
                        bmih.biSize     = sizeof(BITMAPINFOHEADER);
                        bmih.biWidth    = 1344;
                        bmih.biHeight   = -768;
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

                        hdc = ::GetDC(NULL);

                        hImg = CreateDIBitmap(hdc, &bmih, CBM_INIT, pixels, &dbmi, DIB_RGB_COLORS);
                        if (hImg == NULL) {
                            std::cout << "Could not load the desired image image" << std::endl;
                            return 0;
                        }

                        ::ReleaseDC(NULL, hdc);
                       if (hImg)
                            InvalidateRect(hwnd, NULL, TRUE);
                        SetClipboardData(CF_BITMAP, hImg);
                    }
                }
    //         break;
    //
    //         case WM_PAINT:
                {
                    hdc = BeginPaint (hwnd, &ps);
                    hMemDC = CreateCompatibleDC(hdc);

                    SelectBitmap(hMemDC, hImg);
                    GetObject (hImg, sizeof (BITMAP), &bm);
                    BitBlt (hdc, 0, 0, bm.bmWidth, bm.bmHeight, hMemDC, 0, 0, SRCCOPY);
                    DeleteDC (hMemDC);
                    EndPaint (hwnd, &ps);
                }
//            delete [] pixels;
            }
            if(BUF == -1){
                {
                    if (OpenClipboard (hwnd))
                    {
                        Cursor_dt = dCursor(Cursor_dt);
                        if(Cursor_dt.x > 0)
                            dR += Cursor_dt.x;
                        else
                            dB += -Cursor_dt.x;
                        if(Cursor_dt.y > 0)
                            dG += Cursor_dt.y;
                        else{
                            dG += Cursor_dt.y;
                            dB += Cursor_dt.y;
                            dR += Cursor_dt.y;
                        }
                        if(dR < 0)
                            dR = 0;
                        if(dB < 0)
                            dB = 0;
                        if(dG < 0)
                            dG = 0;
                        if(dR > 255)
                            dR = 255;
                        if(dB > 255)
                            dB = 255;
                        if(dG > 255)
                            dG = 255;
                            for (int i=0; i<768; i ++){
                                    for (int j = 0; j < 1344*4; j++){
                                        for (int k = 0; k < 4; k++){
                                            pixels2[(i*1344*4)+j]=0+dB;
                                            pixels2[(i*1344*4)+j+1]=0+dG;
                                            pixels2[(i*1344*4)+j+2]=0+dR;
                                            pixels2[(i*1344*4)+j+3]=0+dWhat_is_it;
                                            j += 4;
                                        }
                                        j--;
                                    }
                        }
                        fff++;
                        if(fff == 8)
                            fff = 0;
                        bmih2.biSize     = sizeof(BITMAPINFOHEADER);
                        bmih2.biWidth    = 1344;
                        bmih2.biHeight   = -768;
                        bmih2.biPlanes   = 1;
                        bmih2.biBitCount = 32;
                        bmih2.biCompression  = BI_RGB;
                        bmih2.biSizeImage    = 0;
                        bmih2.biXPelsPerMeter    =   10;
                        bmih2.biYPelsPerMeter    =   10;
                        bmih2.biClrUsed    =0;
                        bmih2.biClrImportant =0;

                        ZeroMemory(&dbmi2, sizeof(dbmi2));
                        dbmi2.bmiHeader = bmih2;
                        dbmi2.bmiColors->rgbBlue = 0;
                        dbmi2.bmiColors->rgbGreen = 0;
                        dbmi2.bmiColors->rgbRed = 0;
                        dbmi2.bmiColors->rgbReserved = 0;

                        hdc = ::GetDC(NULL);

                        hImg2 = CreateDIBitmap(hdc, &bmih2, CBM_INIT, pixels2, &dbmi2, DIB_RGB_COLORS);
                        if (hImg2 == NULL) {
                            std::cout << "Could not load the desired image image" << std::endl;
                            return 0;
                        }
                        ::ReleaseDC(NULL, hdc);
                       if (hImg2)
                            InvalidateRect(hwnd, NULL, TRUE);
                        SetClipboardData(CF_BITMAP, hImg2);
                  }
             }
    //         break;
    //
    //         case WM_PAINT:
             {
                  hdc = BeginPaint (hwnd, &ps2);
                  hMemDC2 = CreateCompatibleDC(hdc);

                  SelectBitmap(hMemDC2, hImg2);
                  GetObject (hImg2, sizeof (BITMAP), &bm2);
                  BitBlt (hdc, 0, 0, bm2.bmWidth, bm2.bmHeight, hMemDC2, 0, 0, SRCCOPY);
                  DeleteDC (hMemDC2);
                  EndPaint (hwnd, &ps2);
             }
//            delete [] pixels2;

            }
            BUF *= -1;
            }
            break;

         case WM_DESTROY:
         {
                CloseClipboard();
                DeleteObject(hImg);
                DeleteObject(hImg2);
              KillTimer (hwnd, 1);
              PostQuitMessage (0);
         }
         break;
    }
    return DefWindowProc (hwnd, msg, wParam, lParam);
}





