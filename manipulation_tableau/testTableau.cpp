#include "manipulation_tableau.h"
#include <assert.h>
int main(){
  assert(tabIsNul({0,0,0}) == true);
  assert(tabIsNul({0,0,0, 0, 0, 0}) == true);
  assert(tabIsNul({0,0,0, 0,0,0,0}) == true);
  assert(tabIsNul({0,1,0}) == false);
  assert(tabIsNul({0,2,65}) == false);
  assert(tabIsNul({0,0,1}) == false);
  assert(tabIsNul({0,2,65}) == false);
  assert(tabIsNul({1,0,0}) == false);
  assert(tabIsNul({0,2,65}) == false);
  assert(tabIsNul({3,2,45}) == false);





}
