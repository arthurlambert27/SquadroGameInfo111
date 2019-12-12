#include "mouvement.h"
#include <assert.h>
#include <tuple>
int main(){
  int test1 = ptnDeMouvement(1,1,{0,0,0,0,0,0,0,0,0,0});
  int test2 = ptnDeMouvement(3,2,{0,0,0,0,0,0,0,0,0,0});
  int test3 = ptnDeMouvement(1,1,{0,0,0,0,0,0,0,1,0,0});
  int test4 = ptnDeMouvement(1,1,{0,0,0,0,0,0,0,0,0,1});
  assert( test1 == 1);
  assert( test2 == 2);
  assert( test3 == 2);
  assert( test4 == 1);





}
