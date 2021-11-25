#include "Data_creator.h"
char *** creatData(){
    char*** res=malloc(sizeof(char**)*34);
    for(int x=0;x<34;x++){
        res[x]=malloc(sizeof(char*)*6);
        for(int y=0;y<6;y++){
            res[x][y]=malloc(sizeof(char)*30);
        }
    }
    char data[34][6][50]={{"1","Epee en bois","Arme","10 durabilite","1 maximum","1 degat"},
                          {"2","Pioche en bois","Outil","10 durabilite","1 maximum","0 degat"},
                          {"3","Serpe en bois","Outil","10 durabilite","1 maximum","0 degat"},
                          {"4","Hache en bois","Outil","10 durabilite","1 maximum","0 degat"},
                          {"5","Sapin","Ressource de craft","0 durabilite","20 maximum","0 degat"},
                          {"6","Pierre","Ressource de craft","0 durabilite","20 maximum","0 degat"},
                          {"7","Herbe","Ressource de craft","0 durabilite","20 maximum","0 degat"},
                          {"8","Epee en pierre","Arme","10 durabilite","1 maximum","2 degat"},
                          {"9","Lance en pierre","Arme","8 durabilite","1 maximum","3 degat"},
                          {"10","Marteau en pierre","Arme","5 durabilite","1 maximum","4 degat"},
                          {"11","Plastron en pierre","Armure","1 durabilite","1 maximum","10% résistance aux dégâts"},
                          {"12","Pioche en pierre","Outil","10 durabilite","1 maximum","0 degat"},
                          {"13","Serpe en pierre","Outil","10 durabilite","1 maximum","0 degat"},
                          {"14","Hache en pierre","Outil","10 durabilite","1 maximum","0 degat"},
                          {"15","Potion de vie I","Soin","1 durabilite","1 maximum","30 HP"},
                          {"16","Hetre","Ressource de craft","0 durabilite","20 maximum","0 degat"},
                          {"17","Fer","Ressource de craft","0 durabilite","20 maximum","0 degat"},
                          {"18","Lavande","Ressource de craft","0 durabilite","20 maximum","0 degat"},
                          {"19","Epee en fer","Arme","10 durabilité","1 maximum","5 degat"},
                          {"20","Lance en fer","Arme","8 durabilité","1 maximum","7 degat"},
                          {"21","Marteau en fer","Arme","5 durabilité","1 maximum","10 degat"},
                          {"22","Plastron en fer","Armure","1 durabilite","1 maximum","20% résistance aux dégâts"},
                          {"23","Pioche en fer","Outil","10 durabilité","1 maximum","0 degat"},
                          {"24","Serpe en fer","Outil","10 durabilité","1 maximum","0 degat"},
                          {"25","Hache en fer","Outil","10 durabilité","1 maximum","0 degat"},
                          {"26","Potion de vie II","Soin","1 durabilite","1 maximum","80 HP"},
                          {"27","Chene","Ressource de craft","0 durabilite","20 maximum","0 degat"},
                          {"28","Diamant","Ressource de craft","0 durabilite","20 maximum","0 degat"},
                          {"29","Chanvre","Ressource de craft","0 durabilite","20 maximum","0 degat"},
                          {"30","Epee en diamant","Arme","10 durabilité","1 maximum","10 degat"},
                          {"31","Lance en diamant","Arme","8 durabilité","1 maximum","15 degat"},
                          {"32","Marteau en diamant","Arme","5 durabilité","1 maximum","20 degat"},
                          {"33","Plastron en diamant","Armure","1 durabilite","1 maximum","40% résistance aux dégâts"},
                          {"34","Potion de vie III","Soin","1 durabilite","1 maximum","200 HP"}
    };
    for(int x=0;x<34;x++){
        for(int y=0;y<6;y++) {
            res[x][y]=data[x][y];
        }
    }
    return res;
}
char *** maps(){
    char*** res=malloc(sizeof(char**)*15);
    for(int x=0;x<15;x++){
        res[x]=malloc(sizeof(char*)*3);
        for(int y=0;y<3;y++){
            res[x][y]=malloc(sizeof(char)*30);
        }
    }
    char map[15][3][30]={{"-3","Portail entre zones || & |||","6"},
                         {"-2","Portail entre zones | & ||","5"},
                         {"-1","Case infranchissable","4"},
                         {"0","Zone libre pour se déplacer","4"},
                         {"1","Joueur","4"},
                         {"2","PNJ","4"},
                         {"3","Plante zone I","1"},
                         {"4","Rocher zone I","1"},
                         {"5","Bois zone I","1"},
                         {"6","Plante zone II","2"},
                         {"7","Rocher zone II","2"},
                         {"8","Bois zone II","2"},
                         {"9","Plante zone III","3"},
                         {"10","Rocher zone III","3"},
                         {"11","Bois zone III","3"},
    };
    for(int x=0;x<15;x++){
        for(int y=0;y<3;y++) {
            res[x][y]=map[x][y];
        }
    }
    return res;
}