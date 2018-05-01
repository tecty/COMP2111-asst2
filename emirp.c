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
  mpz_set_ui(r,1);



  // initial the count
  unsigned long long count =0 ;
  while (count < n ) {
    // r ++;
    mpz_add_ui(r,r,1);
    // count = count + ISEMIRP(r)
    count += isEmirp(r);

    // gmp_printf("%Zd ",r );
    // printf("with is Emirp %d\n", isEmirp(r) );
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
  // gmp_printf(" the reverse value of %Zd is %Zd \n",n,r );
  if(mpz_cmp(n,r) !=0  ){
    if (mpz_probab_prime_p(n,50) >0) {
      /* code */
      if(mpz_probab_prime_p(r,50) >0){
        w =1;
      }
      else{
        w =0;
      }
    }
    else{
      w = 0;
    }
  }
  else{
    w= 0;
  }
  return w;
}
