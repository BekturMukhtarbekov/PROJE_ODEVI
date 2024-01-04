#include <stdio.h>
#include "str_vrb.h"

#ifndef PROJEODEV_REZERVASYON_GORME_H
#define PROJEODEV_REZERVASYON_GORME_H

void rezGor () {
    printf("\nYapilan  rezervasyonlar:\n");
    printf("Ucus numarasi\tTarih\n");
    printf("_________\n");

    for (int i = 0; i < 10; ++i) {
        if (rez[i] != 0) {
            printf("%d\t\t%d.%d.%d\n\n", rez[i], ucuslar[i].tarih.gun, ucuslar[i].tarih.ay, ucuslar[i].tarih.yil);
        }
    }
}

#endif //PROJEODEV_REZERVASYON_GORME_H
