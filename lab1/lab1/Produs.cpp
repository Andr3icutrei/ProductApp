#include "Produs.h"
#include <regex>
#include "productType.h"
Produs::Produs()
{

}
/*
* 
 Produs::Produs(uint16_t id,const std::string& productName, float price, uint16_t vat,const std::string& descriptionOrExpDate)
{
	id_m = id;
	productName_m = productName;
	price_m = price;
	vat_m = vat;
	descriptionOrExpDate_m = descriptionOrExpDate;
}

Produs::Produs(uint16_t id, std::string_view productName, float price, uint16_t vat, std::string_view descriptionOrExpDate)
{
	id_m = id;
	productName_m = productName;
	price_m = price;
	vat_m = vat;
	descriptionOrExpDate_m = descriptionOrExpDate;
}
*/

//se mai poate si cu lista de initializare ( cu : dupa )
//daca folosesc metoda din comentariu, ex id_m(id), mai bine folosim id_m{id} (initializare uniforma)
//pentru ca	seamana prea mult cu apelul unei functii

//in principiu se foloseste const & pentru tipurile de date greu de mutat, la tipurile primitive este ok si fara const &

bool Produs::isPerishable() const
{
	std::regex reg{ "\\d{4}-\\d{2}-\\d{2}" };
	return std::regex_search(this->Get_expiration_date(), reg);
}

float Produs::finalPrice() const
{
	return price_m + (float)(vat_m/100.0f) * price_m;
}

std::istream& operator>>(std::istream& is, Produs& p)
{
	std::string expDateOrType;
	is >> p.id_m >> p.productName_m >> p.price_m >> p.vat_m >> expDateOrType;
	std::regex reg  { "\\d{4}-\\d{2}-\\d{2}" };
	if (std::regex_search(expDateOrType, reg))
	{
		p.date_m = expDateOrType;
	}
	else
	{
		if (expDateOrType == "PersonalHygiene")
			p.type_m = productType::PersonalHygiene;
		else if(expDateOrType=="SmallAppliances")
			p.type_m = productType::SmallAppliances;
		else
			p.type_m = productType::Clothing;
	}
	return is;
}

std::ostream& operator<<(std::ostream& os,const Produs& p)
{
	if (p.isPerishable() == false)
		os << p.id_m << " " << p.productName_m << " " << p.price_m << " " << p.vat_m << " "
			<< productTypeToString(p.Get_description());
	else
		os << p.id_m << " " << p.productName_m << " " << p.price_m << " " << p.vat_m << " "
			<<p.date_m;
	return os;
}

bool sortByProductName(const Produs& p1, const Produs& p2)
{
	return p1.productName_m < p2.productName_m;
}

bool sortByPrice(const Produs& p1, const Produs& p2)
{
	return p1.price_m < p2.price_m;
}
