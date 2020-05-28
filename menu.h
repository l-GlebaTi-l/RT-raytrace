class Menu;

class Button {
private:
public:
    int posi = 0, posj = 0;     //  лева€ верхн€€ точка текстуры на экране
    int li = 0, lj = 0;         //  ширина и высота текстуры
    unsigned char *texture;
    Button(){
        li = resolution.shirina / 10;
        lj = resolution.vysota / 10;
        posi = (resolution.shirina / 2) - (li / 2);
        posj = (resolution.vysota / 4) - (lj / 2);
        texture = new unsigned char[lj*li*4];
        for(int j = 0; j < lj; j++){
            for(int i = 0; i < li*4; i++){
                texture[j*li*4+i] = 100;
            }
        }
    }
    Button(ifstream& file){
        file >> posi >> posj >> li >> lj;
        texture = new unsigned char[lj*li*4];
        for(int j = 0; j < lj; j++){
            for(int i = 0; i < li*4; i++){
                file >> texture[j*li*4+i];
            }
        }
    }
    void Paint(){
        for(int j = 0; j < 0 + lj; j++){
            for(int i = 0; i < 0 + li*4; i++){
                pixelsP[(j+posj)*resolution.shirina*4 + i + (posi*4)] = texture[j*li*4 + i];
            }
        }
    }
    bool is_there(POINT cursor){
        if(cursor.x > posi && cursor.x < (posi + li) && cursor.y > posj && cursor.y < (posj + lj))
            return 1;
        return 0;
    }
};

int But_N = 4;
Button *Buttons;


void Menu_Options(int num)
{
    switch(num){
    case 0:
        PARAM_Menu *= -1;
        break;
    case 1:

        break;
    case 2:

        break;
    case 3:
        f_exit = 27;
        break;
    case 4:

        break;
    case 5:

        break;
    }
}
