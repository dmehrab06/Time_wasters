#include <cstdio>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int main() {
	int n;

	char name[35];

	scanf("%d\n\n", &n);
	while (n--) {
		int total = 0;
        map<string, int> plants;
		total = 0;
		while (gets(name)) {
			if (strlen(name) == 0)
				break;


				plants[string(name)]++;

			total++;
		}

		map<string, int>::iterator it;
		for (it = plants.begin(); it != plants.end(); it++) {
			printf("%s %.4lf\n", (*it).first.data(),
					(double) (*it).second / (double) total * 100.0);
		}
		if (n > 0){
			printf("\n");

		}
	}

	return 0;
}
