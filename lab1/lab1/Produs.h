#pragma once
#include <string>
#include <cstdint>
#include <string_view>
#include <iostream>
#include "productType.h"

class Produs
{
private: 
	uint16_t id_m;//int pe 16 biti fara semn 
	std::string productName_m;
	float price_m;
	uint16_t vat_m;
	productType type_m;
	std::string date_m;
public:
	Produs();
	//Produs(uint16_t id,const std::string& productName,float price,uint16_t vat,productType type);
	//Produs(uint16_t id, const char* productName, float price, uint16_t vat, const char* descriptionOrExpDate);
	//Produs(uint16_t id, std::string_view productName, float price, uint16_t vat, std::string_view descriptionOrExpDate);

	Produs& operator=(const Produs& product)=default;//la tipul returnat se pune si & pentru ca daca avem p1=p2=p3 sa functioneze bine
	Produs(const Produs& p)=default;
	~Produs()=default;
	//compilatorul genereaza aceste metode default si mai merge pt operator==
	// nu functioneaza default pentru alocari dinamice facut de mana, adica nu cu std::vector

	friend std::istream& operator>>(std::istream& is, Produs& p);
	bool isPerishable() const;
	float finalPrice() const;
	friend std::ostream& operator<<(std::ostream& os,const Produs& p);
	friend bool sortByProductName(const Produs& p1,const Produs& p2);
	friend bool sortByPrice(const Produs& p1, const Produs& p2);

	uint16_t Get_id() const { return id_m; }//constul de dupa functie se specifica faptul ca nu se fac fac modificari in functie
	std::string Get_name() const { return productName_m; }
	float Get_price() const { return price_m; }
	uint16_t Get_vat() const { return vat_m; }
	std::string Get_expiration_date() const { return date_m; }
	productType Get_description() const { return type_m; }
	//pentru a nu face doi constructori, unul pentru char* si unul pentru string, am folosit string_view, care este un numitor comun intre 
	//cele 2. folosinta lui este pentru a transmite parametri cu ajutorul lui, nu pentru algoritmi.
};

