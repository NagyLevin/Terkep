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
    bool bt; // igaz hamis


    int szigetek; //szigetek a szinezos megoldassa
    int tengerszemek; //tengerszemek a szinezos megoldassa



};


struct Kep{
private:

int szelesseg,magassag;

string _fajlnev;
int szszam = 0; //szigetek szama
int tszam = 0;


public:

vector<vector<Ertek>> v;


Kep(string fajlnev):_fajlnev(fajlnev){


}


void olvas(){
ifstream befajl(_fajlnev);

befajl >> szelesseg;



befajl >> magassag;

cout << szelesseg  << "  "  << magassag << endl;

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

bool sziget(int ex, int ey)
    {
        return v[(ex+1) % v.size()][ey].b || v[(ex-1+v.size()) % v.size()][ey].b || v[ex][(ey+1) % v[ex].size()].b || v[ex][(ey-1+v[ex].size()) % v[ex].size()].b;
    }
bool tszem(int ex, int ey)
    {
        return v[(ex+1) % v.size()][ey].bt || v[(ex-1+v.size()) % v.size()][ey].bt || v[ex][(ey+1) % v[ex].size()].bt || v[ex][(ey-1+v[ex].size()) % v[ex].size()].bt;
    }

    void szigetkereso(int ex, int ey)
    {
        bool valtozott;

        //szigetkereses

        if (v[ex][ey].a >= 0 && v[ex][ey].b == false ){
            v[ex][ey].b = true;
            do
            {
                valtozott = false;

                for (size_t i=0; i<v.size(); i++)
                {
                    for (size_t j=0; j<v[i].size(); j++)
                    {
                        if (v[i][j].a >= 0 and
                            sziget(i, j) and
                            !v[i][j].b)
                        {
                            v[i][j].b = true;
                            valtozott = true;
                        }
                    }
                }
                for (size_t i=0; i<v.size(); i++)
                {
                    for (int j=v[i].size()-1; j>=0; j--)
                    {
                        if (v[i][j].a >= 0 and
                            sziget(i, j) and
                            !v[i][j].b)
                        {
                            v[i][j].b = true;
                            valtozott = true;
                        }
                    }
                }
                for (int i=v.size()-1; i>=0; i--)
                {
                    for (size_t j=0; j<v[i].size(); j++)
                    {
                        if (v[i][j].a >= 0 and
                            sziget(i, j) and
                            !v[i][j].b)
                        {
                            v[i][j].b = true;
                            valtozott = true;
                        }
                    }
                }
                for (int i=v.size()-1; i>=0; i--)
                {
                    for (int j=v[i].size()-1; j>=0; j--)
                    {
                        if (v[i][j].a >= 0 and
                            sziget(i, j) and
                            !v[i][j].b)
                        {
                            v[i][j].b = true;
                            valtozott = true;
                        }
                    }
                }

            }
            while (valtozott);


                /*
            for (size_t i=0; i<sz.size(); i++){
                    for (size_t j=0; j<sz[i].size(); j++){
                        cout << szines[i][j] << "    ";
                    }
                    }
                */

            //itt mar beszinezi jol
                szszam = szszam + 1;
               // cout << szszam <<endl;
               for (size_t i=0; i<v.size(); i++){
                    for (size_t j=0; j<v[i].size(); j++){
                        v[i][j].szigetek = v[i][j].szigetek + v[i][j].b;

                        //memoriaszemet van meg a vektorokban, 0 val kellene kezdeni oket
                        if(v[i][j].szigetek > 146){
                            //cout << v[i][j].szigetek <<"  ";
                            cout << szszam <<"  " << v[i][j].b*szszam <<endl;
                        }
                        //memoriaszemet van meg a vektorokban, 0 val kellene kezdeni oket

                        //cout << v[i][j].szigetek <<"  ";


                    }
                }


        /*
        for (size_t i=0; i<sz.size(); i++){
                    for (size_t j=0; j<sz[i].size(); j++){
                        cout << szines[i][j] <<" ";
                    }
        }
        cout << "egylefutas" <<endl;
            */
        }

        //szigetkereses

        if (v[ex][ey].a <= 0 && v[ex][ey].bt == false ){
            v[ex][ey].bt = true;
            do
            {
                valtozott = false;

                for (size_t i=0; i<v.size(); i++)
                {
                    for (size_t j=0; j<v[i].size(); j++)
                    {
                        if (v[i][j].a <= 0 and
                            tszem(i, j) and
                            !v[i][j].bt)
                        {
                            v[i][j].bt = true;
                            valtozott = true;
                        }
                    }
                }
                for (size_t i=0; i<v.size(); i++)
                {
                    for (int j=v[i].size()-1; j>=0; j--)
                    {
                        if (v[i][j].a <= 0 and
                            tszem(i, j) and
                            !v[i][j].bt)
                        {
                            v[i][j].bt = true;
                            valtozott = true;
                        }
                    }
                }
                for (int i=v.size()-1; i>=0; i--)
                {
                    for (size_t j=0; j<v[i].size(); j++)
                    {
                        if (v[i][j].a <= 0 and
                            tszem(i, j) and
                            !v[i][j].bt)
                        {
                            v[i][j].bt = true;
                            valtozott = true;
                        }
                    }
                }
                for (int i=v.size()-1; i>=0; i--)
                {
                    for (int j=v[i].size()-1; j>=0; j--)
                    {
                        if (v[i][j].a <= 0 and
                            tszem(i, j) and
                            !v[i][j].bt)
                        {
                            v[i][j].bt = true;
                            valtozott = true;
                        }
                    }
                }

            }
            while (valtozott);


                /*
            for (size_t i=0; i<sz.size(); i++){
                    for (size_t j=0; j<sz[i].size(); j++){
                        cout << szines[i][j] << "    ";
                    }
                    }
                */

            //itt mar beszinezi jol
                tszam = tszam + 1;
                //cout << tszam <<endl;
               for (size_t i=0; i<v.size(); i++){
                    for (size_t j=0; j<v[i].size(); j++){
                        v[i][j].tengerszemek = v[i][j].tengerszemek + v[i][j].bt;


                        //cout << v[i][j].szigetek <<"  ";


                    }
                }


        /*
        for (size_t i=0; i<sz.size(); i++){
                    for (size_t j=0; j<sz[i].size(); j++){
                        cout << szines[i][j] <<" ";
                    }
        }
        cout << "egylefutas" <<endl;
            */
        }
        //cout << "tefutott" <<endl;




}






//rajz
void rajz(){
int voltmagassag = 0;

for(int y = 0 ; y< v.size();y++){
    for(int x = 0; x < v[y].size();x++){



        if (v[y][x].bt){
             gout << move_to(x,y) << color(v[y][x].tengerszemek*100, v[y][x].tengerszemek+100, v[y][x].tengerszemek-100) << dot;


        }

        else if(v[y][x].a <= 0){

            gout << move_to(x,y) << color(0,200,255) << dot;
        }

        if (v[y][x].b){
             gout << move_to(x,y) << color(v[y][x].szigetek*100, v[y][x].szigetek+100, v[y][x].szigetek-100) << dot;
             //cout << v[y][x].szigetek <<endl;

        }

        else if(v[y][x].a > 0){

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


for(size_t y = 0 ; y< v.size();y++){
for(size_t x = 0; x < v[y].size();x++){

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


    //megkeresi a szigeteket

    for (int i=0; i<kep.AblakM(); i++){
    for (int j=0; j<kep.AblakSz(); j++){
    kep.szigetkereso(i,j);
    }
    }
//    cout << "tefutott" <<endl;


    //cout << kep.szszam <<endl;
    /*
    for (int i=0; i<kep.AblakM(); i++){
    for (int j=0; j<kep.AblakSz(); j++){
    cout << kep.v[i][j].szigetek << "   ";
    }
    }
    */

    gout.open(kep.AblakSz(),kep.AblakM());
    gin.timer(30);
    while(gin >> ev && ev.keycode != key_escape){

    if(ev.type == ev_timer){
        kep.rajz();
        //kep.rajzM(ev.pos_x,ev.pos_y);

    }












    gout << refresh;
    gout << move_to(kep.AblakSz(),0) << color(0,0,0) << box(kep.AblakSz(),kep.AblakM()); //torles

    }
    return 0;
}
