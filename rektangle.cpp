/* Challenge #276 [Easy] Rektangles
   Generate a rektangle of a given width and length
   i.e., for inputs "REKT", 2, and 2:
	R E K T K E R
	E     K     E
	K     E     K
	T K E R E K T
	K     E     K
	E     K     E
	R E K T K E R
*/
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

void ins(std::vector<std::vector<char> > *a, int x, int y, string s, bool hor, bool reverse){
	for(int k = 1; k<s.length(); k++){
		if(hor)
			(*a)[y][x+k] = ((reverse) ? s[s.length()-1-k] : s[k]);
		else
			(*a)[y+k][x] = ((reverse) ? s[s.length()-1-k] : s[k]);
	}
}

int main(int argc, char *argv[]) {
	std::string s = argv[1];
	int w = (atoi(argv[2])*s.length()) - (atoi(argv[2])) + 1;
	int l = (atoi(argv[3])*s.length()) - (atoi(argv[3])) + 1;
	std::vector<std::vector<char> > *a = new std::vector<std::vector<char> >(l, std::vector<char> (w,' '));

	(*a)[0][0] = s[0];
	for(int i=0; i<l; i+=s.length()-1){
		for(int j=0; j<w; j+=s.length()-1){
			if(i<l-1)
				ins(a,j,i,s,false,(((i+j)/(s.length()-1))%2==1));
			if(j<w-1)
				ins(a,j,i,s,true,(((i+j)/(s.length()-1))%2==1));
		}
	}
	for(int i=0; i<l;i++){
		std:vector<char> v = (*a)[i];
		std::copy(v.begin(), v.end(), std::ostream_iterator<char>(std::cout," "));
		cout<<endl;
	}

	return 0;
} 