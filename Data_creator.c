char *** creatData(){
    char*** res=malloc(sizeof(char**)*34);
    for(int x=0;x<34;x++){
        res[x]=malloc(sizeof(char*)*4);
        for(int y=0;y<4;y++){
            res[x][y]=malloc(sizeof(char)*30);
        }
    }
    char data[34][4][50]={{"1","Epee en bois","Arme","10 durabilité","1 maximum","1 degat"},
                          {"2","Pioche en bois","Outil","10 durabilité","1 maximum"},
                          {"3","Serpe en bois","Outil","10 durabilité"},
                          {"4","Hache en bois","Outil","10 durabilité"},
                          {"5","Sapin","Ressource de craft","0 durabilite","20 maximum"},
                          {"6","Pierre","Ressource de craft","20 maximum"},
                          {"7","Herbe","Ressource de craft","20 maximum"},
                          {"8","Épée en pierre","Arme","2 dégât / 10 durabilité"},
                          {"9","Lance en pierre","Arme","3 dégât / 8 durabilité"},
                          {"10","Marteau en pierre","Arme","4 dégât / 5 durabilité"},
                          {"11","Plastron en pierre","Armure","10% résistance aux dégâts"},
                          {"12","Pioche en pierre","Outil","10 durabilité"},
                          {"13","Serpe en pierre","Outil","10 durabilité"},
                          {"14","Hache en pierre","Outil","10 durabilité"},
                          {"15","Potion de vie I","Soin","1 durabilite","1 maximum","30 soin"},
                          {"16","Hêtre","Ressource de craft","20 maximum"},
                          {"17","Fer","Ressource de craft","20 maximum"},
                          {"18","Lavande","Ressource de craft","20 maximum"},
                          {"19","Épée en fer","Arme","5 dégâts / 10 durabilité"},
                          {"20","Lance en fer","Arme","7 dégâts / 8 durabilité"},
                          {"21","Marteau en fer","Arme","10 dégât / 5 durabilité"},
                          {"22","Plastron en fer","Armure","20% résistance aux dégâts"},
                          {"23","Pioche en fer","Outil","10 durabilité"},
                          {"24","Serpe en fer","Outil","10 durabilité"},
                          {"25","Hache en fer","Outil","10 durabilité"},
                          {"26","Potion de vie II","Soin","Restaure 80 HP"},
                          {"27","Chene","Ressource de craft","20 maximum"},
                          {"28","Diamant","Ressource de craft","20 maximum"},
                          {"29","Chanvre","Ressource de craft","20 maximum"},
                          {"30","Épée en diamant","Arme","10 dégâts / 10 durabilité"},
                          {"31","Lance en diamant","Arme","15 dégâts / 8 durabilité"},
                          {"32","Marteau en diamant","Arme","20 dégâts / 5 durabilité"},
                          {"33","Plastron en diamant","Armure","40% résistance aux dégâts"},
                          {"34","Potion de vie III","Soin","Restaure 200 HP"}
    };
    for(int x=0;x<34;x++){
        for(int y=0;y<4;y++) {
            res[x][y]=data[x][y];
        }
    }
    return res;
}
char *** maps(){
    char map[15][3][50]={{"-3","Portail entre zones || & |||","6"},
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
    return map;
}

