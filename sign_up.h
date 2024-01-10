#include <stdio.h>
#include "str_vrb.h"

#ifndef PROJEODEV_SIGN_UP_H
#define PROJEODEV_SIGN_UP_H

#define MAX_USERS 50

void signup(){

    if (userCount >= MAX_USERS) {
        printf("Daha fazla kullanici eklenemiyor. Sistem dolu.\n");
        return;
    }

    Kullanici newUser;

    newUser.userId = nextUserId;

    printf("_______________UYE OL________________\n\n");
    printf("Adiniz:");
    scanf("%s", newUser.name);

    printf("Soyadiniz:");
    scanf("%s", newUser.surname);

    printf("Hesabinizdaki bakiye:");
    scanf("%d", &newUser.walletAmount);

    printf("Sifre olusturunuz:");
    scanf("%s", newUser.password);

    users[userCount++] = newUser;
    printf("Kullanici basariyla kaydedildi.\n");
    printf("Kullanici ID'niz: %d\n" , nextUserId);
    printf("_____________________________________\n");

    // Verileri, turleriyle (Kullanici Id, Ad, Soyad vs.) beraber goruntuleyebilmek icin acilan bir dosya
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }
    fprintf(file, "Kullanici ID:\t%d\nAd:\t\t\t\t%s\nSoyad:\t\t\t%s\nBakiye:\t\t\t%d\nSifre:\t\t\t%s\n\n",
            nextUserId, newUser.name, newUser.surname, newUser.walletAmount, newUser.password);
    nextUserId++;
    fclose(file);

    FILE *dosya = fopen("kullanici_islemleri.txt","a");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
    }
    fprintf(dosya, "%s %s kullanicisi %d ID numarasi ile uye oldu.\n\n", users[0].name, users[0].surname, users[0].userId);
    fclose(dosya);

}

#endif //PROJEODEV_SIGN_UP_H
