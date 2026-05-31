/* Check in disjoint or joint of two intervals
Ex: [1,5] and [5,10] are disjoint
[1,3] and [2,6] are joint
*/
#include <stdio.h>

int interval(void){
    printf("First interval:\n");
    int begin1, end1;
    scanf("%d %d", &begin1, &end1);
    printf("Second interval:\n");
    int begin2, end2;
    scanf("%d %d", &begin2, &end2);

    if (end1<begin2 || end2<begin1){
        printf("Disjoint");
    }
    // else if (end1==begin2 || end2==begin1){
    //     printf("Disjoint");
    // }
    else {
        printf("Joint");
    }
    return 0;
}