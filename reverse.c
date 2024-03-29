/* $Revision: 1.2 $ */
#include "reverse.h"

void reversen(mpz_t n, mpz_t r) {
  int i,l;
  l = gmp_sprintf(_reversen_inbuf,"%Zd", n);
  for(i = 0; i < l; i++)
    _reversen_outbuf[l-i-1] = _reversen_inbuf[i];
  _reversen_outbuf[l]='\0';
  mpz_set_str (r, _reversen_outbuf, 10);
}
