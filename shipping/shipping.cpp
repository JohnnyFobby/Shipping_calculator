#include <iostream>
#include <iomanip>

int main()
{
	int length{}, width{}, height{};
	double base_cost{ 2.50 };

	const int tier1_threshold{ 100 }; //volume
	const int tier2_threshold{ 500 }; // volume

	int max_dimension_length{ 10 }; //inches
	double tier1_surcharge{ 0.10 }; //10% extra
	double tier2_surcharge{ 0.25 }; //25% extra

	//all dimensions must be 10 inches or less

	int package_volume{};

	std::cout << "Welcome to the package cost calculator!" << std::endl;
	std::cout << "Enter length, width, and height of hte package separated by spaces: ";
	std::cin >> length >> width >> height;

	if (length > max_dimension_length || width > max_dimension_length || height > max_dimension_length)
	{
		std::cout << "Package rejected! Dimensions exceeded." << std::endl;
	}
	else
	{
		double package_cost{};
		package_volume = length * width * height;

		package_cost = base_cost;

		if (package_volume > tier2_threshold)
		{
			package_cost += package_cost * tier2_surcharge;
			std::cout << "Adding tier 2 surcharge" << std::endl;
		}
		else if (package_volume > tier1_threshold)
		{
			package_cost += package_cost * tier1_surcharge;
			std::cout << "Adding tier 1 surcharge" << std::endl;
		}
		std::cout << std::fixed << std::setprecision(2); //prints dollars nicely :D
		std::cout << "The volume of your package is: " << package_volume << std::endl;
		std::cout << "Your package will cost: $" << package_cost << " to ship" << std::endl;

	}


}