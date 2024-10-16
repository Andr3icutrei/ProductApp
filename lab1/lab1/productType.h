#pragma once
#include <cstdint>

enum class productType: uint8_t { PersonalHygiene, SmallAppliances,Clothing};//implicit, tipul setat e int

inline std::string productTypeToString(productType prodType)//am declarat functia inline pentru a nu avea probleme
//cand se s-ar defini mai multe functii de acest tip cand este inclus headerul in alte fisiere
{
	switch (prodType)
	{
		case productType::PersonalHygiene:
			return "PersonalHygiene";
		case productType::SmallAppliances:
			return "SmallAppliances";
		case productType::Clothing:
			return "Clothing";
		default:
			return "";
	}
}
//enum class Culoare{rosu,verde,albastru};
//rosu == personalHygiene dadea true cu enum simplu, iar cu enum class nu se returneaza false, ci se da eroare la compilare
