#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include "Produs.h"
#include "productType.h"
#include <algorithm>
#include <vector>

int main()
{
	/*
	char a[10]{ "elev" };
	std::string b{ "student" };
	char c[10] = { 'e','l','e','v' };
	std::string d{ b };
	
	std::string_view{ d };
	*/
	//initializare uniforma: se folosesc {} pentru initializarea variabilelor
	std::vector<Produs> vProducts;
	for(std::ifstream fin{"product.prodb"};!fin.eof();/*empty*/)
	{
		Produs p;
		fin >> p;
		vProducts.emplace_back(p);	//este mai ineficient cu push_back pentru ca se creeaza o copie cu obiectul
	}

	for (Produs& product : vProducts) //pentru acest for se folosesc metodele begin si end
	{
		if (product.isPerishable()==false)
			std::cout << product<<" : "<<product.finalPrice() << '\n';
	}
	//RANGED-BASED FOR
	/*
	std::cout << "sort by price :\n ";
	std::sort(vProducts.begin(), vProducts.end(), sortByPrice);
	
	for (Produs& product : vProducts)
	{
		std::cout << product << '\n';
	}

	std::cout << "sort by product Name :\n ";
	std::sort(vProducts.begin(), vProducts.end(), sortByProductName);
	for (auto product : vProducts)
	{
		std::cout << product << '\n';
	}
	*/
	return 0;
}