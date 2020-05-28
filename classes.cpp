#include "classes.h"

class mesh {
private:

public:
    XYZ A, B, C;
    XYZ ab, ac, n;
    mesh(){
        A.x = A.y = A.z = B.x = B.y = B.z = C.x = C.y = C.z = 0;
    }
    void mesher(std::ifstream& file){
//        std::ifstream file("vectors.txt");
        A = vf(A, file);
        B = vf(B, file);
        C = vf(C, file);
//        file.close();
        ab = o_vector(A, B);
        ac = o_vector(A, C);
        n = vector_normal(ab, ac);
        n = vector_sim(n);
    }
};

class vizor {
public:
    XYZ O;
    XYZ V;
    XYZ ov;
    XYZ V1 = V;
    XYZ O1 = O;
    XYZ E0;
    vizor (){
        std::ifstream file("vizor.txt");
        O = vf(O, file);
        V = vf(V, file);
        file.close();
        V1 = V;
        O1 = O;
    }
//    rotation (){
//
//    }
};

class Obj {
private:
public:
    bool live;
    char Name[100];
    double Radius;
    XYZ Position;
    double health = 100;
    RGBF Color;
    int num_meshs = 0;
    mesh *B = new mesh[num_meshs];
    Obj(){}
    void Objj(std::ifstream& file){
        file >> num_meshs;
        mesh *C = new mesh[num_meshs];
        mesh A;
        for (int k = 0; k < num_meshs; k++){
            A.mesher(file);
            C[k] = A;
        }
        B = C;
        if(!file.eof())
            file >> Radius;
        else {
            std::cout << "ÐÀÄÈÓÑ ÍÅ ÏÐÈÑÓÒÑÒÂÓÅÒ Â ÔÀÉËÅ!!!" << std::endl;
            Radius = 10;
        }
        if(!file.eof()){
            file >> Position.x;
            file >> Position.y;
            file >> Position.z;
        }
        else {
            std::cout << "ÍÅ ÏÐÈÑÓÒÑÒÂÓÞÒ ÊÎÎÐÄÈÍÀÒÛ ÖÅÍÒÐÀ ÎÁÚÅÊÒÀ!!!" << std::endl;
            Position.x = 0;
            Position.y = 0;
            Position.z = 0;
        }
        if(!file.eof()){
            file >> Color.r;
            file >> Color.g;
            file >> Color.b;
            file >> Color.f;
        }
        else {
            std::cout << "ÍÅ ÏÐÈÑÓÒÑÒÂÓÞÒ ÄÀÍÍÛÅ Î ÖÂÅÒÅ ÎÁÚÅÊÒÀ!!!" << std::endl;
            Color.r = 30;
            Color.g = 100;
            Color.b = 30;
            Color.f = 0;
        }
//        std::cout << "Is error is here?" << B[0].A.x << std::endl;
//        delete[]C;
//        std::cout << "Here????????" << B[0].A.x << std::endl;
    }
    void Objj_create(){
        Radius = 3;
        Position.x = Person_Position.x + Person_dEYE.x*10;
        Position.y = Person_Position.y + Person_dEYE.y*10;
        Position.z = Person_Position.z + Person_dEYE.z*10;
        Color.r = 100;
        Color.g = 100;
        Color.b = 100;
        Color.f = 0;
        num_meshs = 1;
        mesh *C = new mesh[num_meshs];
        C[0].A.x = Position.x + Person_dEYE_Perp.x*5;
        C[0].A.y = Position.y + Person_dEYE_Perp.y*5;
        C[0].A.z = Position.z + Person_dEYE_Perp.z*5;

        C[0].B.x = Position.x - Person_dEYE_Perp.x*5;
        C[0].B.y = Position.y - Person_dEYE_Perp.y*5;
        C[0].B.z = Position.z - Person_dEYE_Perp.z*5;

        C[0].C.x = Position.x;
        C[0].C.y = Position.y;
        C[0].C.z = Position.z + 2;

        C[0].ab = o_vector(C[0].A, C[0].B);
        C[0].ac = o_vector(C[0].A, C[0].C);
        C[0].n = vector_normal(C[0].ab, C[0].ac);
//        C[0].n = vector_sim(C[0].n);
        B = new mesh[num_meshs];
        B[0] = C[0];
        live = 1;
    }
    void Obj_d_Teleport(XYZ dS){
        Position.x += dS.x;
        Position.y += dS.y;
        Position.z += dS.z;
        for(int i = 0; i < num_meshs; i++){
            B[i].A.x += dS.x;
            B[i].A.y += dS.y;
            B[i].A.z += dS.z;
            B[i].B.x += dS.x;
            B[i].B.y += dS.y;
            B[i].B.z += dS.z;
            B[i].C.x += dS.x;
            B[i].C.y += dS.y;
            B[i].C.z += dS.z;
        }
    }
    void Obj_Hit(double damage, int i){
        health -= damage;
        std::cout << "Çäîðîâüå îáúåêòà " << Name << " = " << health << std::endl;
        if(health < 0){
            int kill = Game_Obj_Kill(i);
            if(kill == 0)
                std::cout << "All objects killed!" << std::endl;
            if((kill != 1)&&(kill != 0))
                std::cout << "Kill Error" << std::endl;
            else
                std::cout << "Killed ¹ " << Obj_Alive.num[i] << "!" << std::endl;
            break;
        }
    }
};



