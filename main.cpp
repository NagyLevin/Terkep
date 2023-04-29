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
    bool block;

    int szigetek; //szigetek a szinezos megoldassa



};


struct Kep{
private:

int szelesseg,magassag;

string _fajlnev;
int szszam = 0; //szigetek szama
int tszam = 0;

vector<int> utx;
vector<int> uty;

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
        return v[(ex+1) % v.size()][ey].b || v[(ex-1+v.size()) % v.size()][ey].b || v[ex][(ey+1) % v[ex].size()].b || v[ex][(ey-1+v[ex].size()) % v[ex].size()].b ||
         v[(ex+1) % v.size()][(ey+1) % v[ex].size()].b || v[(ex-1+v.size()) % v.size()][(ey-1+v[ex].size()) % v[ex].size()].b || v[(ex-1+v.size()) % v.size()][(ey+1) % v[ex].size()].b || v[(ex+1) % v.size()][(ey-1+v[ex].size())% v[ex].size()].b;
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


}



void xrajz(int ex,int ey){

gout << move_to(ex,ey) << color(255,0,0) << line(5,5) << move_to(ex,ey) << line(-5,-5) << move_to(ex,ey) << line(-5,5) << move_to(ex,ey) << line(5,-5);

}


//rajz
void rajz(){
int voltmagassag = 0;

for(size_t y = 0 ; y< v.size();y++){
    for(size_t x = 0; x < v[y].size();x++){



        if(v[y][x].a <= 0){

            gout << move_to(x,y) << color(0,200,255) << dot;
        }

        if (v[y][x].b){
             gout << move_to(x,y) << color(v[y][x].szigetek*100, v[y][x].szigetek+100, 0) << dot;
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

        //�rnyk�k aszerint, hogy magass�g mennyi k�r�l�tte, ill melyik oldalr�l s�t a nap


    }




}
}
//rajz


//rajzmagassag


//ablak
int AblakSz(){
return szelesseg;
}
int AblakM(){
return magassag;
}
//ablak


void utkereso(int m1x, int m1y, int m2x, int m2y){

        if(v[m1y][m1x].a<= 0 || v[m2y][m2x].a <= 0){

            //cout << "eger koordinatok  " << m1x << ":" << m1y << "     " << m2x <<":" << m2y <<endl;
            cout << "ez egyik pont vizben van " << v[m1y][m1x].a << "  " << v[m2y][m2x].a<<endl;

        }

        else if(v[m1y][m1x].szigetek !=  v[m2y][m2x].szigetek){


            cout << "nincs ut a ket pont kozott" <<endl;

        }


        if(v[m1y][m1x].szigetek ==  v[m2y][m2x].szigetek){




            int szigetid = v[m1y][m1x].szigetek;

            utx.clear();
            uty.clear();

            utx.push_back(m1x);
            uty.push_back(m1y);

            int uthossz = 0;
            int blockolasok = 0;
            int blockszam =0;

            for (size_t i=0; i<v.size(); i++){
                for (size_t j=0; j<v[i].size(); j++){
                    if(v[i][j].block == true){
                        v[i][j].block = false;
                    }

                }
                }



            while(m1y != m2y || m1x != m2x){

             blockolasok = blockolasok +1;
            if (m1x +1 < v[0].size() && m1x < m2x && v[m1y][m1x+1].szigetek == szigetid && v[m1y][m1x+1].block != true ){ //X+1

                m1x =  m1x+1;


                utx.push_back(m1x);
                uty.push_back(m1y);
                v[m1y][m1x].block = true;


            }
            else if(m1y +1< v.size() && m1y < m2y && v[m1y+1][m1x].szigetek == szigetid && v[m1y+1][m1x].block != true){ //Y+1

                m1y = m1y+1;
                utx.push_back(m1x);
                uty.push_back(m1y);
                v[m1y][m1x].block = true;

            }
            else if(m1x -1 > -1 && m1x > m2x && v[m1y][m1x-1].szigetek == szigetid && v[m1y][m1x-1].block != true){ //X-1

                m1x = m1x-1;
                 utx.push_back(m1x);
                uty.push_back(m1y);
                v[m1y][m1x].block = true;

            }
            else if(m1y-1>-1 && m1y > m2y && v[m1y-1][m1x].szigetek == szigetid && v[m1y-1][m1x].block != true){ //Y-1

                m1y = m1y-1;
                 utx.push_back(m1x);
                uty.push_back(m1y);
                v[m1y][m1x].block = true;

            }
            else if(m1x +1<v[0].size() && m1y +1<v.size() && v[m1y+1][m1x+1].szigetek == szigetid && v[m1y+1][m1x+1].block != true){ //XY+1

                m1x = m1x+1;
                m1y = m1y+1;
                utx.push_back(m1x);
                uty.push_back(m1y);
                v[m1y][m1x].block = true;

            }

            else if(m1x -1 > -1 && m1y-1>-1 &&v[m1y-1][m1x-1].szigetek == szigetid && v[m1y-1][m1x-1].block != true){ //XY-1

               m1x = m1x-1;
                m1y = m1y-1;
                utx.push_back(m1x);
                uty.push_back(m1y);
                v[m1y][m1x].block = true;

            }

             else if(m1x +1<v[0].size() && m1y-1>-1 && v[m1y-1][m1x+1].szigetek == szigetid && v[m1y-1][m1x+1].block != true){ //X+1 Y-1

            m1x = m1x+1;
            m1y = m1y-1;
            utx.push_back(m1x);
            uty.push_back(m1y);
            v[m1y][m1x].block = true;

            }
            else if(m1y +1<v.size() && m1x -1 > -1 && v[m1y+1][m1x-1].szigetek == szigetid && v[m1y+1][m1x-1].block != true){ //X-1Y+1

                m1x = m1x-1;
                m1y = m1y+1;
                utx.push_back(m1x);
                uty.push_back(m1y);
                v[m1y][m1x].block = true;

            }

            else{ //ha valahogy beakad

                if(utx.size() > 1 && uty.size() > 1){


                utx.pop_back();
                uty.pop_back();
                cout << utx.size() << " a vektor merete"<<endl;
                cout << m1x << " elotte" << endl;
                m1x = utx[utx.size()-1];
                cout << m1x << " utana" << endl;
                m1y = uty[uty.size()-1];



                }







            }

            cout << blockolasok <<endl;



                //cout << v.size() <<endl; //az y a 300;
                cout << m1x << ":" << m1y <<"         " << m2x << ":" << m2y <<endl;
                gout << move_to(m1x,m1y) << color(255,0,0) << dot << refresh;












            }




        }


}

void Reset(){


    for (int i=0; i<AblakM(); i++){
    for (int j=0; j<AblakSz(); j++){
    szigetkereso(i,j);
    }
    }


}

};




int main()      //mainnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn
{
    Kep kep("terkep.txt");



    event ev;


    kep.olvas();


    //megkeresi a szigeteket



    int kattintasszam = 0;

    int mark1x,mark1y,mark2x,mark2y;

    gout.open(kep.AblakSz(),kep.AblakM());

     kep.Reset(); //terkep elso beolvasasa

    gin.timer(30);
    while(gin >> ev && ev.keycode != key_escape){

    if(ev.type == ev_timer){
        kep.rajz();
        //kep.rajzM(ev.pos_x,ev.pos_y);


        if(kattintasszam > 0){
            kep.xrajz(mark1x,mark1y);
        }

    }



    //1 feladat ut
    if(ev.type == ev_mouse){

        if(ev.button == btn_left){

            kattintasszam = kattintasszam + 1;

            if(kattintasszam == 1){
            mark1x = ev.pos_x;
            mark1y = ev.pos_y;

            }

            if(kattintasszam == 2){

                mark2x = ev.pos_x;
                mark2y = ev.pos_y;
                kep.utkereso(mark1x,mark1y,mark2x,mark2y);
                kattintasszam = 0;
                mark1x =0;
                mark1y =0;
                mark2x =0;
                mark2y =0;


            }



        }


    }



    gout << refresh;
    gout << move_to(kep.AblakSz(),0) << color(0,0,0) << box(kep.AblakSz(),kep.AblakM()); //torles

    }
    return 0;
}
