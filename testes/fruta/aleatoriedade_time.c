#include <stdio.h>
#include <sys/random.h>

int main(){
  int loop = 0;
  while(1){
    srand(loop);
    int aleatorio = rand();
    printf("O número é: %d\n", aleatorio);
    
    if(loop < 40){
      loop++;
    }
    else{
      break;
    }
  }
  
  return 0;
}