#pragma once 

#include<iostream>
#include <cassert>
#include <cstdio>
#include <typeinfo>
#include <vector>
#include <cmath>

using namespace std;


typedef int entero;

template <size_t N, size_t B,class T = char>
	class Number_t{
		public:
		    
		    T    v[N];
	
		public:
		 
			Number_t(entero e = 0);
			char to_char(int digtconv);
			void set_v(int pos,T dato);
			T get_v(int pos)const;
			int to_decimal(void)const;
			Number_t<N,B,T> to_this_base(int n)const;

			ostream& write(ostream& os)const;
			Number_t<N,B,T> operator +  (const Number_t<N,B,T>& n)const;
			Number_t<N,B,T> operator =  (const Number_t<N,B,T>& n)const;
			Number_t<N,B,T> operator -  (const Number_t<N,B,T>& n)const;
			Number_t<N,B,T> operator *  (const Number_t<N,B,T>& n)const;
			Number_t<N,B,T> operator /  (const Number_t<N,B,T>& n)const;
			bool operator <  (const Number_t<N,B,T>& n)const;
			bool operator ==  (const Number_t<N,B,T>& n)const;
	
		private:
		
			void to_base(int);
			
	};
	
//~###############################################################################//
//                            MÉTODOS PÚBLICOS                                    //
//~###############################################################################//
        template <size_t N, size_t B,class T>
        Number_t<N,B,T>::Number_t(entero e){ 
			for (int i = 0; i < N; i++){
				v[i] = 0;
			}
			to_base(e);
			//cout << "Number" << "<" << N << "," << B << "," << ">" << "(" << e << ")." << endl;
			
			
		}
		
        
        template <size_t N, size_t B,class T>
		void Number_t<N,B,T>::set_v(int pos,T dato){
			assert((pos <= N) &&  ((pos >= 0)));
				v[pos] = dato;
		}
	
	
		template <size_t N, size_t B,class T>
		T Number_t<N,B,T>::get_v(int pos)const {
			
			assert((pos < N) && ((pos >= 0)));
				return v[pos];
		}
        
	
		template <size_t N, size_t B,class T>
		char Number_t<N,B,T>::to_char(int digtconv)
		{
		    char Mychars[]={'0','1','2','3','4','5','7','8','9','A','B','C','D','E','F','G','H','I','J'};
		    if(digtconv >=9 )
		    {
		        digtconv=Mychars[digtconv-1];
		        return digtconv;
		    }
		    else
		    {
		        digtconv=Mychars[digtconv];
		        return digtconv;
		    }
		}
		
		template <size_t N, size_t B,class T>
		int Number_t<N,B,T>::to_decimal()const
		{
			int decimal = 0;
			for (int i  = N - 1; i >= 0; i --){
				decimal += get_v(i)*pow(B,i);
			}
			
			return decimal;
		}
		
		template <size_t N, size_t B,class T>
		Number_t<N,B,T> Number_t<N,B,T>::to_this_base(int  n)const
		{
			Number_t<N,B,T> n1(n);
			return n1;
		}
		
		
		template <size_t N, size_t B,class T>
		ostream& Number_t<N,B,T>::write(ostream& os)const
		{
			char Mychars[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
			for (int i = N - 1; i >= 0; i--){
				
			//	if ( v[i] >= 9 ){
					os << Mychars[v[i]];
		//		}else {
		//			os << Mychars[v[i]];
		//		}
				
			}
		}
		
		
		template <size_t N, size_t B,class T>
		Number_t<N,B,T> Number_t<N,B,T>::operator +  (const Number_t<N,B,T>& n)const
		{
			int op1 = 0;
			int op2 = 0;
			op1 = to_decimal();
			op2 = n.to_decimal();
			int res = op1 + op2;
			Number_t<N,B,T> resultado(res);
			resultado.write(cout);
			return resultado;
			
		} 
	
		
		template <size_t N, size_t B,class T>
		Number_t<N,B,T> Number_t<N,B,T>::operator -  (const Number_t<N,B,T>& n)const
		{
			int op1 = 0;
			int op2 = 0;
			op1 = to_decimal();
			op2 = n.to_decimal();
			int res = op1 - op2;
			Number_t<N,B,T> resultado(res);
			return resultado;
			
		}
		
		
		template <size_t N, size_t B,class T>
		Number_t<N,B,T> Number_t<N,B,T>::operator *  (const Number_t<N,B,T>& n)const
		{
			int op1 = 0;
			int op2 = 0;
			op1 = to_decimal();
			op2 = n.to_decimal();
			int res = op1 * op2;
			Number_t<N,B,T> resultado(res);
			return resultado;
			
		}
		
		
		template <size_t N, size_t B,class T>
		Number_t<N,B,T> Number_t<N,B,T>::operator /  (const Number_t<N,B,T>& n)const
		{
			int op1 = 0;
			int op2 = 0;
			op1 = to_decimal();
			op2 = n.to_decimal();
			int res = op1 / op2;
			Number_t<N,B,T> resultado(res);
			return resultado;
			
		}
		
		
		template <size_t N, size_t B,class T>
		bool Number_t<N,B,T>::operator <  (const Number_t<N,B,T>& n)const
		{
			int op1 = 0;
			int op2 = 0;
			op1 = to_decimal();
			op2 = n.to_decimal();
			if(op1 < op2)
				return true;
			else
				return false;
		}
		
		
		template <size_t N, size_t B,class T>
		bool Number_t<N,B,T>::operator ==  (const Number_t<N,B,T>& n)const
		{
			int op1 = 0;
			int op2 = 0;
			op1 = to_decimal();
			op2 = n.to_decimal();
			if (op1 == op2)
				return true;
			else 
				return false;
			
		}
		
		
		template <size_t N, size_t B,class T>
		Number_t<N,B,T> Number_t<N,B,T>::operator =  (const Number_t<N,B,T>& n)const
		{
			
			return Number_t<N,B,T>(n.to_decimal());
			
		}
		
//~###############################################################################//
//                            MÉTODOS PRIVADOS                                    //
//~##############################################################################//
        template <size_t N, size_t B,class T>
        void Number_t<N,B,T>::to_base(int e){
        	int cociente,residuo,cont;
			int i = 0;
			do{
			        cociente = e/B;
			        residuo = e%B;
			        set_v(i,residuo);
			        e = cociente;
			        i++;
			}while (cociente>0);
		} 
		
		
		