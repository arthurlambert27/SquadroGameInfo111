#include "deplacement.h"
#include <assert.h>
#include <tuple>
int main(){
  std::tuple<std::vector<std::vector<int>>, std::vector<int>, int, int> plateau1;
  std::tuple<std::vector<std::vector<int>>, std::vector<int>, int, int> plateau2;
  plateau1 = std::make_tuple(  {{9,0,0,0,0,0,9},
    {0,0,0,1,0,0,0},
    {1,0,0,0,0,0,0},
    {1,0,0,0,0,0,0},
    {1,0,0,0,0,0,0},
    {1,0,0,0,0,0,0},
    {9,2,2,2,2,2,9}}, {0,0,0,0,0,0,0,0,0,0},5, 5);
  assert(true);
  assert(deplace({{9,0,0,0,0,0,0,9},{1,0,0,0,0,0,0},{1,0,0,0,0,0,0},{1,0,0,0,0,0,0},{1,0,0,0,0,0,0},{1,0,0,0,0,0,0},{9,2,2,2,2,2,9}},{0,0,0,0,0,0,0,0,0,0},1,1)
   == plateau1


  );





}
