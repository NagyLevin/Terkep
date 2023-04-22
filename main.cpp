#include "graphics.hpp"
#include "math.h"
#include "fstream"
#include <iostream>




using namespace genv;
using namespace std;



struct Ertek{



public:
    int a; //ertekek
    bool b; // igaz hamis




};


struct Kep{
private:

int szelesseg,magassag;
vector<vector<Ertek>> v;
string _fajlnev;


public:

Kep(string fajlnev):_fajlnev(fajlnev){


}


void olvas(){
ifstream befajl(_fajlnev);

befajl >> szelesseg;

cout << szelesseg << endl;

befajl >> magassag;

v = vector<vector<Ertek>> (magassag,vector<Ertek>(szelesseg));

for(int i = 0 ; i< magassag;i++){
    for(int j = 0; j < szelesseg;j++){

        befajl >> v[i][j].a;
         //cout << v[i][j].a <<endl;

    }


}






befajl.close();

cout << "terkep sikeresen beolvasva" << endl;

}


//rajz
void rajz(){
int voltmagassag = 0;

for(int y = 0 ; y< v.size();y++){
    for(int x = 0; x < v[y].size();x++){



        if(v[y][x].a < 0){

            gout << move_to(x,y) << color(0,200,255) << dot;
        }


        if(v[y][x].a > 0){

            int pillmagassag = v[y][x].a;

            if(pillmagassag < voltmagassag){


                    gout << move_to(x,y) << color(200,100-100+pillmagassag,0) << dot;





            }
            if(pillmagassag > voltmagassag){


                    gout << move_to(x,y) << color(200,100+100+pillmagassag,0) << dot;


            }

         voltmagassag = pillmagassag;

        }

        //árnykék aszerint, hogy magasság mennyi körülötte, ill melyik oldalról süt a nap


    }




}
}
//rajz


//rajzmagassag
void rajzM(int ex, int ey){


for(int y = 0 ; y< v.size();y++){
for(int x = 0; x < v[y].size();x++){

//v [magassag][szelesseg]
gout << move_to(AblakSz()+x,v[ey][x].a + AblakM()/2) << color(0,200,255) << dot;
}
}
}
//rajzmagassag


//ablak
int AblakSz(){
return szelesseg;
}
int AblakM(){
return magassag;
}
//ablak

};




int main()
{
    Kep kep("terkep.txt");


    event ev;


    kep.olvas();

    gout.open(kep.AblakSz(),kep.AblakM());

    while(gin >> ev && ev.keycode != key_escape){


    kep.rajz();
    //kep.rajzM(ev.pos_x,ev.pos_y);











    gout << refresh;
    gout << move_to(kep.AblakSz(),0) << color(0,0,0) << box(kep.AblakSz(),kep.AblakM()); //torles

    }
    return 0;
}
