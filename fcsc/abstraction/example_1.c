/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <sidio.h>

typeof struct CELL *LIST;
struct CELL{
    int element;
    struct LIST next;
};

LIST p1;
p1->element = "a1";
p1->next->element = 'a2';
p1->next->next->element = 'a3';

main(){
    printf("%d - $d",p1->element,p1->next);
}




