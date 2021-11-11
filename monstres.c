#include <stdio.h>

typedef struct Monstre{
    int id;
    int HP;
    int temps_reaparition;
    int position_x;
    int position_y;
    int zone;
}Monstre;

int momo(int argc, const char * argv[]){
    Monstre monstre[26];

    Monstre m1;
    m1.id = 12;
    m1.HP = 10;
    m1.temps_reaparition = 0;
    monstre[0]=m1;

    Monstre m2;
    m2.id = 15;
    m2.HP = 10;
    m2.temps_reaparition = 0;
    monstre[1]=m2;

    Monstre m3;
    m3.id = 18;
    m3.HP = 10;
    m3.temps_reaparition = 0;
    monstre[2]=m3;

    Monstre m4;
    m4.id = 20;
    m4.HP = 10;
    m4.temps_reaparition = 0;
    monstre[3]=m4;

    Monstre m5;
    m5.id = 20;
    m5.HP = 10;
    m5.temps_reaparition = 0;
    monstre[4]=m5;

    Monstre m6;
    m6.id = 21;
    m6.HP = 10;
    m6.temps_reaparition = 0;
    monstre[5]=m6;

    Monstre m7;
    m7.id = 23;
    m7.HP = 10;
    m7.temps_reaparition = 0;
    monstre[6]=m7;

    Monstre m8;
    m8.id = 25;
    m8.HP = 10;
    m8.temps_reaparition = 0;
    monstre[7]=m8;

    Monstre m9;
    m9.id = 26;
    m9.HP = 10;
    m9.temps_reaparition = 0;
    monstre[8]=m9;

    Monstre m10;
    m10.id = 28;
    m10.HP = 10;
    m10.temps_reaparition = 0;
    monstre[9]=m10;

    Monstre m11;
    m11.id = 30;
    m11.HP = 20;
    m11.temps_reaparition = 0;
    monstre[10]=m11;

    Monstre m12;
    m12.id = 32;
    m12.HP = 20;
    m12.temps_reaparition = 0;
    monstre[11]=m12;

    Monstre m13;
    m13.id = 35;
    m13.HP = 20;
    m13.temps_reaparition = 0;
    monstre[12]=m13;

    Monstre m14;
    m14.id = 40;
    m14.HP = 20;
    m14.temps_reaparition = 0;
    monstre[13]=m14;

    Monstre m15;
    m15.id = 44;
    m15.HP = 20;
    m15.temps_reaparition = 0;
    monstre[14]=m15;

    Monstre m16;
    m16.id = 47;
    m16.HP = 20;
    m16.temps_reaparition = 0;
    monstre[15]=m16;

    Monstre m17;
    m17.id = 49;
    m17.HP = 20;
    m17.temps_reaparition = 0;
    monstre[16]=m17;

    Monstre m18;
    m18.id = 52;
    m18.HP = 20;
    m18.temps_reaparition = 0;
    monstre[17]=m18;

    Monstre m19;
    m19.id = 55;
    m19.HP = 20;
    m19.temps_reaparition = 0;
    monstre[18]=m19;

    Monstre m20;
    m20.id = 58;
    m20.HP = 20;
    m20.temps_reaparition = 0;
    monstre[19]=m20;

    Monstre m21;
    m21.id = 63;
    m21.HP = 30;
    m21.temps_reaparition = 0;
    monstre[20]=m21;

    Monstre m22;
    m22.id = 66;
    m22.HP = 30;
    m22.temps_reaparition = 0;
    monstre[21]=m22;

    Monstre m23;
    m23.id = 70;
    m23.HP = 30;
    m23.temps_reaparition = 0;
    monstre[22]=m23;

    Monstre m24;
    m24.id = 73;
    m24.HP = 30;
    m24.temps_reaparition = 0;
    monstre[23]=m24;

    Monstre m25;
    m25.id = 75;
    m25.HP = 30;
    m25.temps_reaparition = 0;
    monstre[24]=m25;

    Monstre boss;
    boss.id = 99;
    boss.HP = 50;
    boss.temps_reaparition = 0;
    monstre[25]=boss;

}
