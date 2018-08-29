#ifndef Carnet_Puntos_h
#define Carnet_Puntos_h

#include <iostream>
#include <map>
#include <list>
#include <stdexcept>

class DriverLicense {
	std::map<std::string, int> drivers;
	std::map<int, std::list<std::string>> driversByPoints;

public:

	DriverLicense() {
		for (int i = 0; i < 16; ++i) {
			driversByPoints.insert({ i,{} });
		}
	}

	void registerNewDriver(const std::string driver) {
		auto itToDrivers = drivers.find(driver);

		if (itToDrivers != drivers.end())
			throw new std::domain_error("The driver already exists");

		drivers.insert({ driver,15 });
		
		auto itToDriverByPoints = driversByPoints.find(15);
		itToDriverByPoints->second.push_back(driver);
	}

	void removePoints(const std::string driver, const int p) {
		auto itToDrivers = drivers.find(driver);

		if (itToDrivers == drivers.end())
			throw new std::domain_error("Driver not existant");
		
		
		auto itToDriverByPoints = driversByPoints.find(itToDrivers->second);
		auto itToDriverOnList = itToDriverByPoints->second.begin();
		while (*itToDriverOnList != driver) {
			++itToDriverOnList;
		}
		itToDriverByPoints->second.erase(itToDriverOnList);

		if (itToDrivers->second - p < 0)
			itToDrivers->second = 0;
		else
			itToDrivers->second -= p;

		itToDriverByPoints = driversByPoints.find(itToDrivers->second);
		itToDriverByPoints->second.push_back(driver);
	}

	const int findDriver(const std::string driver) const {
		auto itToDrivers = drivers.find(driver);

		if (itToDrivers == drivers.end())
			throw new std::domain_error("Driver not existant");

		return itToDrivers->second;
	}

	const int countDriversByPoints(const int points) const {
		if (points < 0 || points > 15)
			throw new std::domain_error("Points must be between 0 and 15");
		auto itToDriversByPoints = driversByPoints.find(points);

		return itToDriversByPoints->second.size();
	}
};
#endif
