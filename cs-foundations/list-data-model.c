
void main(){
    
}

typedef struct CELL *LIST;
struct CELL{
    int elemet;
    LIST next;
}

BOOLEAN lookup(index x , LIST L){
    if(L == NULL){
        return FALSE;
    }else if(x == L->element){
        return TRUE;
    }else{
        return lookup(x,L->next);
    }
}