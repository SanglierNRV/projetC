#include <stdio.h>	
#include <stdlib.h>
#include <gmp.h>



// argc est automatiquement la taille de la ligne de caractères et argv est ce tableau de caractères
// atoi transforme un caractere en int




void add(mpz_t x0, mpz_t y0, mpz_t x1, mpz_t y1,mpz_t p){ // on stock le resultat dans x1,y1
	
mpz_t l, lbis,x2,y2;
mpz_init(lbis);
mpz_init(l);
mpz_init(x2);
mpz_init(y2);

mpz_sub(l,x0,x1);
mpz_invert(l,l,p);
mpz_sub(lbis,y0,y1);
mpz_mul(l,l,lbis);
mpz_mod(l,l,p);

mpz_mul(x2,l,l);
mpz_sub(x2,x2,x0);
mpz_sub(x2,x2,x1);
mpz_mod(x2,x2,p);

mpz_sub(y2,x0,x2);
mpz_mul(y2,l,y2);
mpz_sub(y2,y2,y0);
mpz_mod(y2,y2,p);

mpz_set(x1,x2);
mpz_set(y1,y2);

mpz_clear(x2);
mpz_clear(y2);
mpz_clear(l);
mpz_clear(lbis);

}



void doubl(mpz_t x0, mpz_t y0,mpz_t p, mpz_t A){

mpz_t l, lbis,x2,y2;
mpz_init(l);
mpz_init(lbis);
mpz_init(x2);
mpz_init(y2);

mpz_mul_si(lbis,y0,2);
mpz_invert(lbis,lbis,p);


mpz_mul(l,x0,x0);
mpz_mul_si(l,l,3);
mpz_add(l,l,A);
mpz_mul(l,lbis,l);
mpz_mod(l,l,p);

gmp_printf("%Zd \n" ,l);

mpz_mul(x2,l,l);
mpz_mul_si(lbis,x0,2);
mpz_sub(x2,x2,lbis);
mpz_mod(x2,x2,p);

mpz_sub(y2,x0,x2);
mpz_mul(y2,l,y2);
mpz_sub(y2,y2,y0);
mpz_mod(y2,y2,p);

mpz_set(x0,x2);
mpz_set(y0,y2);

mpz_clear(x2);
mpz_clear(y2);
mpz_clear(lbis);
mpz_clear(l);
}

void DnA(mpz_t x0, mpz_t y0,mpz_t p, mpz_t A, mpz_t n){


}



void main(){


//mpz_set_str(p,"F1FD178C0B3AD58F10126DE8CE42435B3961ADBCABC8CA6DE8FCF353D86E9C03",16);
//mpz_set_str(A,"F1FD178C0B3AD58F10126DE8CE42435B3961ADBCABC8CA6DE8FCF353D86E9C00",16);
//mpz_set_str(B,"EE353FCA5428A9300D4ABA754A44C00FDFEC0C9AE4B1A1803075ED967B7BB73F",16);
//mpz_set_str(x0,"B6B3D4C356C139EB31183D4749D423958C27D2DCAF98B70164C97A2DD98F5CFF",16);
//mpz_set_str(y0,"6142E0F7C8B204911F9271F0F3ECEF8C2701C307E8E4C9E183115A1554062CFB",16);
//mpz_set_str(n,argv[1],10);
//mpz_clears(p,q,A,B,x0,y0,n);

mpz_t p,x0,x1,y0,y1,x2,y2,A;
mpz_init(p);
mpz_init(x0);
mpz_init(x1);
mpz_init(y0);
mpz_init(y1);
mpz_init(x2);
mpz_init(y2);
mpz_init(A);

mpz_set_str(p,"7",10);
mpz_set_str(x0,"1",10);
mpz_set_str(x1,"1",10);
mpz_set_str(y0,"1",10);
mpz_set_str(y1,"1",10);
mpz_set_str(A,"6",10);

//add(x0,y0,x1,y1,p,x2,y2);
doubl(x0,y0,p,x2,y2,A);

gmp_printf("  %Zd \t %Zd \n",x2,y2);

mpz_clear(p);
mpz_clear(x0);
mpz_clear(x1);
mpz_clear(x2);
mpz_clear(y0);
mpz_clear(y1);
mpz_clear(y2);
mpz_clear(A);


}

