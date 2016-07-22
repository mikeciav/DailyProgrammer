/* Challenge #276 [Intermediate] Key Function
   Write a key function that executes a function for a subarray of items that each share a key (i.e. group by in SQL)
   Functions:
   1 - Histogram
   2 - Grouped sum of field
   3 - Nub
*/
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <string>
#include <numeric>

std::map<std::string, int> key(std::vector<std::string> keys, 
						std::map<std::string, std::vector<int> > values, 
						std::map<std::string, int>(*func)(std::vector<std::string>, std::map<std::string, std::vector<int> >)){
	return (*func)(keys, values);
}

std::map<std::string, int> histogram(std::vector<std::string> ind, std::map<std::string, std::vector<int> > val){
	std::map<std::string, int> m;
	for(int i=0; i<ind.size(); i++){
		m.insert(std::pair<std::string,int>(ind[i], val.at(ind[i]).size()));
	}
	return m;
}

std::map<std::string, int> groupSum(std::vector<std::string> ind, std::map<std::string, std::vector<int> > val){
	std::map<std::string, int> m;
	for(int i=0; i<ind.size(); i++){
		m.insert(std::pair<std::string,int>(ind[i], std::accumulate(val.at(ind[i]).begin(), val.at(ind[i]).end(), 0)));
	}
	return m;
}

std::map<std::string, int> nub(std::vector<std::string> ind, std::map<std::string, std::vector<int> > val){
	std::map<std::string, int> m;
	for(int i=0; i<ind.size(); i++){
		m.insert(std::pair<std::string,int>(ind[i], val.at(ind[i])[0]));
	}
	return m;
}

int main(int argc, char *argv[]) {
	std::vector<std::string> ind;
	std::map<std::string, std::vector<int> > map;
	for (int i=1; i<argc; i+=2){
		std::string key(argv[i]);
		int val = atoi(argv[i+1]);
		if (std::find(ind.begin(), ind.end(), argv[i]) == ind.end() ){
			ind.push_back(key);
			std::vector<int> vec;
			map.insert(std::pair<std::string, std::vector<int> >(key,vec));
		}
		map.at(key).push_back(val);
	}

	std::map<std::string,int> hists = key(ind, map, histogram);
	std::map<std::string,int> sums = key(ind, map, groupSum);
	std::map<std::string,int> nubs = key(ind, map, nub);

	std::cout << "\nHISTOGRAMS:" << std::endl;
	for (int i=0; i<ind.size(); i++)
	{
		std::cout << ind[i] << " - " << hists.at(ind[i]) << std::endl;
	}
	std::cout << "\nSUMS:" << std::endl;
	for (int i=0; i<ind.size(); i++)
	{
		std::cout << ind[i] << " - " << sums.at(ind[i]) << std::endl;
	}
	std::cout << "\nNUBS:" << std::endl;
	for (int i=0; i<ind.size(); i++)
	{
		std::cout << ind[i] << " - " << nubs.at(ind[i]) << std::endl;
	}

	return 0;
}