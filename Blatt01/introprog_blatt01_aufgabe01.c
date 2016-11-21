/* === INTROPROG ABGABE ===
 * Blatt 1, Aufgabe 1
 * Tutorium: t21
 * Gruppe: g11
 * Gruppenmitglieder:
 *  - Sören Junghans
 *  - Alexander Oberländer
 * ========================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input_blatt01.h"

int MAX_LAENGE = 1000;
int i,j,key = 0;

void insertion_sort(int array[], int len) {
    for (j = 1; j < len; j++) {
      key = array[j];
      i = j - 1;
      while (i >= 0 && array[i] > key) {
        array[i + 1] = array[i];
        i--;
      }
      array[i + 1] = key;
    }
}

int main(int argc, char *argv[]) {

    if (argc < 2){
        printf("Aufruf: %s <Dateiname>\n", argv[0]);
        printf("Beispiel: %s zahlen.txt\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];

    int array[MAX_LAENGE];
    int len = read_array_from_file(array, MAX_LAENGE, filename);

    printf("Unsortiertes Array:");
    print_array(array, len);

    insertion_sort(array, len);

    printf("Sortiertes Array:");
    print_array(array, len);

    return 0;
}
