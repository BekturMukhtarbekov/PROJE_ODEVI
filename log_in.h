#include <stdio.h>
#include <string.h>
#include "str_vrb.h"

#ifndef PROJEODEV_LOG_IN_H
#define PROJEODEV_LOG_IN_H

// Uygulamaya girmek icin bir fonksiyon
int login() {
    int userId;
    char password[50];
    int i;

    printf("\n_______________GIRIS YAP_______________\n\n");
    printf("Kullanici ID'nizi giriniz:");
    scanf("%d", &userId);

    printf("Sifrenizi giriniz:");
    scanf("%s", password);

    for (i = 0; i < userCount; i++) {
        if (users[i].userId == userId && strcmp(users[i].password, password) == 0) {
            printf("Giris basariyla yapildi\n");
            printf("Hos geldiniz, %s %s!\n\n", users[i].name, users[i].surname);
            return 1;
        }
    }
    return 0;
}

#endif //PROJEODEV_LOG_IN_H
