#include <gmp.h>
#include "reverse.h"

// int isEmirp(mpz_t n);
void emirp( unsigned long long n );
int isEmirp(mpz_t n);
int main(int argc, char const *argv[]) {
  unsigned long long n;

  if (scanf("%llu",&n) == 1){
    // call the procedure to find nth emirp
    emirp(n);
  }

  return 0;
}


void emirp( unsigned long long n ) {
  // initial the r
  mpz_t r;
  mpz_init(r);
  // r = 1
  mpz_set_ui(r,1);

  // count = 0
  unsigned long long count =0 ;
  while (count != n || isEmirp(r)!= 1) {
    // r = r+1;
    mpz_add_ui(r,r,1);
    // count = count + ISEMIRP(r)
    count += isEmirp(r);
  }
  gmp_printf("%Zd\n",r );

}
//
int isEmirp(mpz_t n){
  // var w ,r
  int w ;
  mpz_t r;
  // r = reversen(n)
  mpz_init(r);
  reversen(n,r);


  if(mpz_cmp(n,r) !=0  ){
    // {n != r}
    if (mpz_probab_prime_p(n,50) >0) {
      // {n \in Prime}
      if(mpz_probab_prime_p(r,50) >0){
        // {r \in Prime}

        // {n != r && n \in Prime && r \in Prime} \Implies {w = 1}
        w =1;
      }
      else{
        // {r \notin Prime}
        w =0;
      }
    }
    else{
      // {n \notin Prime}
      w = 0;
    }
  }
  else{
    // {n = r}
    w= 0;
  }
  return w;
}
