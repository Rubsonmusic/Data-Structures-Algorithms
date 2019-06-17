/*
 * Polynomial.cpp

 *
 *  Created on: Apr 6, 2017
 *      Author: mchaudhry
 */
#include "Polynomial.h"

Polynomial::Polynomial():deg(0){
	coef=new Fraction[1];
}

Polynomial::Polynomial(const Polynomial& p):coef(0),deg(0){
	*this=p;
}

const Polynomial& Polynomial::operator =(const Polynomial& poly){
	if(&poly!=this){
		if(coef!=0)
			delete [] coef;
		deg= poly.deg;
		coef = new Fraction[deg+1];
		for(int i=0;i<deg+1;i++){
			coef[i]=poly.coef[i];
		}
	}
	return (*this);
}

Polynomial::~Polynomial(){
	if(coef!=0){
		delete [] coef;
	}
}

Polynomial& Polynomial::reduce(){
	if(coef[deg]==Fraction() && deg!=0){
		deg=deg-1;
		Fraction * temp= new Fraction[deg+1];
		for(int i=0;i<deg+1; i++){
			temp[i]=coef[i];
		}
		delete coef;
		coef=temp;
		return reduce();
	}
	else{
		return *this;
	}
}

void Polynomial::addCoef(const Fraction &f, int deg){
	reduce();
	if(deg>this->deg){
		Fraction * temp= new Fraction[deg+1];
		for(int i=0;i<deg+1; i++){
			temp[i]=coef[i];
		}
		temp[deg]=f;
		delete coef;
		coef=temp;
	}
	else{
		coef[deg] = coef[deg]+f;
	}
	reduce();
}

Polynomial Polynomial::operator +(const Polynomial & poly) const{
	Polynomial temp; int iter;
	if(poly.deg>this->deg){
		temp=poly; iter=this->deg;
		for(int i=0; i<iter+1; i++){
				temp.addCoef(this->coef[i], i);
			}
	}
	else{
		temp=*this; iter=poly.deg;
		for(int i=0; i<iter+1; i++){
				temp.addCoef(poly.coef[i], i);
		}
	}
	return temp;
}

Polynomial Polynomial::operator *(const Polynomial& poly) const{
	Polynomial temp;
	//temp.addCoef(Fraction(),this->deg+poly.deg);
	for(int i=0; i<this->deg+1; i++){
		for(int j=0; j<poly.deg+1; j++){
			Fraction f=this->coef[i]*poly.coef[j];
			temp.addCoef(f, i+j);
		}
	}
	return temp;
}

Polynomial Polynomial::operator-(const Polynomial & poly) const{
	Polynomial temp;
	Fraction f(-1,1);
	temp.addCoef(f,0);
	return *this + temp*poly;
}

const Polynomial& Polynomial::operator+=(const Polynomial& poly){
	*this= *this + poly;
	return *this;
}

const Polynomial& Polynomial::operator-=(const Polynomial& poly){
	*this= *this - poly;
	return *this;
}

ostream& operator<<(ostream& os, const Polynomial& poly){
	os<<poly.coef[poly.deg]<<"x"<<poly.deg;
	for(int i=poly.deg-1; i>+0; i--)
		os<<"+"<<poly.coef[i]<<"x"<<i;
	return os;
}
