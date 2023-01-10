#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

void add (mpz_t x_P,mpz_t y_P,mpz_t x_Q,mpz_t y_Q,mpz_t p, mpz_t a){
	mpz_t lambda,x_R,y_R;
	mpz_t mu;
	
	mpz_init(lambda);
	mpz_init(mu);
	mpz_init(x_R);
	mpz_init(y_R);
	
	//calcul de lambda
	if ( (mpz_cmp(x_P,x_Q)==0) && (mpz_cmp(y_P,y_Q)==0)){		//calcul si P=Q
		mpz_mul(lambda,x_P,x_P);
		mpz_mul_si(lambda,lambda,3);
		mpz_add(lambda,lambda,a);
		
		mpz_mul_si(mu,y_P,2);
		mpz_invert(mu,mu,p);
		
		mpz_mul(lambda,lambda,mu);
		
		mpz_mod(lambda,lambda, p);
	}
	else{ 														//calcul si P!=Q
		mpz_sub(lambda,x_P,x_Q);
		mpz_sub(mu,y_P,y_Q);
	
		mpz_invert(lambda,lambda,p);
		mpz_mul(lambda, lambda,mu);
	
		mpz_mod(lambda,lambda, p);
	}
	
	
	// calcul de x_R
	
	
	mpz_mul(x_R,lambda,lambda);
	mpz_sub(x_R,x_R, x_P);
	mpz_sub(x_R,x_R, x_Q);
	
	mpz_mod(x_R,x_R, p);
	
	
	// calcul de y_R
	
	mpz_sub(y_R,x_P,x_R);
	mpz_mul(y_R,y_R,lambda);
	mpz_sub(y_R,y_R,y_P);
	
	mpz_mod(y_R,y_R, p);		
	
	mpz_set(x_Q,x_R);
	mpz_set(y_Q,y_R);
	
	mpz_clear(lambda);
	mpz_clear(mu);
	
	mpz_clear(x_R);
	mpz_clear(y_R);
	

}	



void double_and_add(mpz_t n, mpz_t x_P, mpz_t y_P, mpz_t x_R, mpz_t y_R, mpz_t p,mpz_t a){
	mpz_t j;
	mpz_t x_puiss, y_puiss;
	
	mpz_init_set(x_puiss,x_P);
	mpz_init_set( y_puiss,y_P);
	
	mpz_init_set(j,n);
	unsigned long int test=mpz_cdiv_r_ui( j,j,2);
	mpz_set(j,n);
	while (test==0){
		printf("here");
		test=mpz_cdiv_r_ui(j,j,2);
		add(x_puiss,y_puiss,x_puiss,y_puiss,p,a);
		
	}
	mpz_set(x_R,x_puiss);
	mpz_set(y_R,y_puiss); 
	
	while(mpz_cmp_si(j,0)!=0){
		printf("test  : %d \n",test);
		if (test ==1){
			
			add(x_R,y_R,x_puiss,y_puiss,p,a);
		}
		add(x_puiss,y_puiss,x_puiss,y_puiss,p,a);
		test=mpz_cdiv_r_ui(j,j,2);
	}

	mpz_clear(j);
	mpz_clear(x_puiss);
	mpz_clear (y_puiss);
}




int main(int argc, char** argv){
	mpz_t x_P,x_Q,x_R,y_P,y_Q,y_R,p,a,b,n;
	
	mpz_init(x_P);
	mpz_init(x_Q);
	mpz_init(x_R);
	mpz_init(y_P);
	mpz_init(y_Q);
	mpz_init(y_R);

	
	mpz_init_set_str(p,"7",10);
	mpz_init_set_str(a,"6",10);
	mpz_init_set_str(b,"1",10);
	mpz_init_set_str(n,"2",10);
	
	mpz_set_str(x_P,"1",10);
	mpz_set_str(y_P,"1",10);
	mpz_set_str(x_Q,"1",10);
	mpz_set_str(y_Q,"1",10);
	
	add(x_P,y_P,x_P,y_P,p,a);

	
	//double_and_add(n,x_P,y_P,x_R,y_R,p,a);

	gmp_printf("%Zd\n ",x_Q);
	gmp_printf("%Zd\n ", y_Q);
	
	mpz_clear (x_P);
	mpz_clear (x_Q);
	mpz_clear (x_R);
	mpz_clear (y_P);
	mpz_clear (y_Q);
	mpz_clear (y_R);
	mpz_clear (p);
	mpz_clear (a);
	mpz_clear (b);
	
	
}