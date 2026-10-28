/*
     * APL121 - Bie daalt No1 - first working version
 * Сэдэв: Цагийн хөлстэй ажилтны долоо хоногийн цалингийн тооцоо
 *
 * Миний тогтоосон дүрэм:
 *  - Цагийн хөлс 1000-200000 төгрөг
 *  - Суутгал 0-50 хувь
 *  - Нэг өдөр 0-16 цаг
 *  - 7 хоногт 40 цаг хүртэл энгийн цаг, түүнээс дээших цагийг 1.5 дахин бодно
 */
#include <stdio.h>

int main(void)
{
    double tsagiinHuls;      /* 1 цагийн хөлс */
    double suutgaliinHuvi;   /* суутгалын хувь */
    double tsag;             /* нэг өдрийн ажилласан цаг */
    double niitTsag = 0;     /* 7 хоногийн нийт цаг */
    double engiinTsag;       /* энгийн цаг */
    double iluuTsag;         /* илүү цаг */
    double niitTsaling;      /* нийт цалин */
    double suutgal;          /* суутгалын мөнгө */
    double garDeer;          /* гарт олгох дүн */
    double hamgiinTsag = 0;  /* хамгийн их цаг */
    int hamgiinOdor = 1;     /* хамгийн их цагтай өдөр */
    int odor;                /* давталтын тоолуур */

    /* Дэд алгоритм (Flowgorithm-д ShowRules): дүрмийг харуулах */
    printf("=== ДОЛОО ХОНОГИЙН ЦАЛИНГИЙН ТООЦОО ===\n");
    printf("Дүрэм: 40 цагаас дээших цагийг 1.5 дахин бодно.\n");
    printf("Нэг өдөр 0-16 цаг, суутгал 0-50 хувь байна.\n\n");

    /* Оролт 1: цагийн хөлс (буруу бол дахин асууна) */
    do {
        printf("Цагийн хөлс (1000-200000): ");
        scanf("%lf", &tsagiinHuls);
        if (tsagiinHuls < 1000 || tsagiinHuls > 200000) {
            printf("Алдаа! 1000-200000 хооронд оруулна уу.\n");
        }
    } while (tsagiinHuls < 1000 || tsagiinHuls > 200000);

    /* Оролт 2: суутгалын хувь */
    do {
        printf("Суутгалын хувь (0-50): ");
        scanf("%lf", &suutgaliinHuvi);
        if (suutgaliinHuvi < 0 || suutgaliinHuvi > 50) {
            printf("Алдаа! 0-50 хооронд оруулна уу.\n");
        }
    } while (suutgaliinHuvi < 0 || suutgaliinHuvi > 50);

    /* Хүснэгтийн толгой */
    printf("\n%-6s %-10s %6s %12s\n", "Odor", "Turul", "Tsag", "Hulsh");
    printf("------------------------------------\n");

    /* Давталт: 7 өдрийн цаг авч, мөр бүрийг хүснэгтэд хэвлэнэ */
    for (odor = 1; odor <= 7; odor++) {
        /* Оролт 3: өдрийн цаг */
        do {
            printf("%d-р өдрийн цаг (0-16): ", odor);
            scanf("%lf", &tsag);
            if (tsag < 0 || tsag > 16) {
                printf("Алдаа! 0-16 хооронд оруулна уу.\n");
            }
        } while (tsag < 0 || tsag > 16);

        niitTsag = niitTsag + tsag;

        /* Хайлт: хамгийн олон цагтай өдөр */
        if (tsag > hamgiinTsag) {
            hamgiinTsag = tsag;
            hamgiinOdor = odor;
        }

        /* else-if шат: өдрийн төрлийг ангилна */
        if (tsag == 0) {
            printf("%-6d %-10s %6.2f %12.2f\n", odor, "Amralt", tsag, tsag * tsagiinHuls);
        } else if (tsag > 0 && tsag <= 8) {
            printf("%-6d %-10s %6.2f %12.2f\n", odor, "Engiin", tsag, tsag * tsagiinHuls);
        } else {
            printf("%-6d %-10s %6.2f %12.2f\n", odor, "Urt", tsag, tsag * tsagiinHuls);
        }
    }

    /* Энгийн ба илүү цаг */
    if (niitTsag > 40) {
        engiinTsag = 40;
        iluuTsag = niitTsag - 40;
    } else {
        engiinTsag = niitTsag;
        iluuTsag = 0;
    }

    /* Арифметик */
    niitTsaling = engiinTsag * tsagiinHuls + iluuTsag * tsagiinHuls * 1.5;
    suutgal = niitTsaling * suutgaliinHuvi / 100;
    garDeer = niitTsaling - suutgal;

    /* Үр дүн */
    printf("\n=========== ДҮН ===========\n");
    printf("Нийт цаг       : %10.2f\n", niitTsag);
    printf("Энгийн цаг     : %10.2f\n", engiinTsag);
    printf("Илүү цаг       : %10.2f\n", iluuTsag);
    printf("Нийт цалин     : %10.2f төгрөг\n", niitTsaling);
    printf("Суутгал        : %10.2f төгрөг\n", suutgal);
    printf("Гарт олгох дүн : %10.2f төгрөг\n", garDeer);
    printf("Хамгийн олон цагтай өдөр: %d-р өдөр (%.2f цаг)\n", hamgiinOdor, hamgiinTsag);

    return 0;
}
