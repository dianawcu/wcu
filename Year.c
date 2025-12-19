#include <stdio.h>


int leapYear(int year) {
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}


int daysInMonth(int month, int year) {
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (month == 2 && leapYear(year))
        return 29;

    return days[month - 1];
}


int gunHesabla(int d1, int m1, int y1, int d2, int m2, int y2) {
    int totalDays = 0;

    while (d1 != d2 || m1 != m2 || y1 != y2) {
        totalDays++;
        d1++;

        if (d1 > daysInMonth(m1, y1)) {
            d1 = 1;
            m1++;

            if (m1 > 12) {
                m1 = 1;
                y1++;
            }
        }
    }

    return totalDays;
}

int main() {
    int d1, m1, y1;
    int d2, m2, y2;
    int result;

    printf("Birinci tarixi daxil edin (gun ay il): ");
    scanf("%d %d %d", &d1, &m1, &y1);

    printf("Ikinci tarixi daxil edin (gun ay il): ");
    scanf("%d %d %d", &d2, &m2, &y2);

    result = gunHesabla(d1, m1, y1, d2, m2, y2);

    printf("Tarixler arasindaki gun sayi: %d\n", result);

    return 0;
}
