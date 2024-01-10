#include <stdio.h>
#include <ctype.h>
#include "str_vrb.h"

#ifndef PROJEODEV_REZERVASYON_YAPMA_H
#define PROJEODEV_REZERVASYON_YAPMA_H

void rezYap () {

    int secim;
    char onay;

    biletal:
    ucuslariYaz();

    printf("\nAlmak istediginiz ucus numarasini seciniz:\n");
    scanf("%d", &secim);
    for (int j = 0; j < 10; j++) {
        if (secim == 500+j) {
            onaylama:
            printf("\n%d TL ucretli %s'den %s'ye ucus bileti almak icin onayliyor musunuz? (e,h):", ucuslar[j].ucret, ucuslar[j].nereden, ucuslar[j].nereye);
            fflush(stdin);// Ek bir güvenlik önlemi, platforma bağlı olarak çalışmayabilir
            onay = getchar();
            onay = toupper(onay);
            if (ucuslar[j].bosYer > 0) {
                switch (onay) {
                    case 'E':
                        if (users[0].walletAmount >= ucuslar[j].ucret){
                            printf("\n%d.%d.%d tarihinde %d numarali ucus biletini almis oldunuz. Bizi tercih ettiginiz icin tesekkur ederiz.\n\n",
                                   ucuslar[j].tarih.gun, ucuslar[j].tarih.ay, ucuslar[j].tarih.yil, ucuslar[j].ucusId);
                            ucuslar[j].bosYer--;
                            rez[j] = ucuslar[j].ucusId;
                            users[0].walletAmount -= ucuslar[j].ucret;
                            printf("Kalan bakiyeniz = %d\n\n", users[0].walletAmount);

                            FILE *dosya = fopen("kullanici_islemleri.txt","a");
                            if (dosya == NULL) {
                                printf("Dosya acilamadi.\n");
                            }
                            fprintf(dosya, "%d ID numarali %s %s tarafindan %d no'lu ucus alindi.\n\n", users[0].userId, users[0].name, users[0].surname, ucuslar[j].ucusId);
                            fclose(dosya);

                        } else
                            printf("\nBakiyeniz yetersizdir.\nBaska hesabinizi deneyiniz.\n");
                        break;
                    case 'H':
                        goto biletal;
                        break;
                    default:
                        printf("Gecersiz secim yaptiniz. Tekrar deneyiniz.");
                        goto onaylama;
                }
            } else {
                printf("Maalesef istediginiz ucusta yer yok. Lutfen baska bir ucus tercih ediniz");
                goto biletal;
            }
        }
    }
}


#endif //PROJEODEV_REZERVASYON_YAPMA_H
