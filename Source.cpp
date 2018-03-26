#include <iostream>
#include <math.h>
#include <string >
using namespace std;
int main() {

	string yekan[10] = { "yek", "do", "seh", "chahar", "pang", "shesh", "haft","hasht","noh" }, khas[9] = { "yazdah","davazdah","sizdah","chahardah","panzdah","shanzdah","hefdah","hejdah","nozdah" },
		dahgan[9] = { "dah","bist","sii","chehel","pangah","shast","haftad","hashtad","navad" }, sadgan[9] = { "sad","divest","sisad","charsad","pansad","sheshsad","haftsad","hashtsad","nohsad" }, hezarga[4] = { "hezar","miliyon","miliyard","triliyon" };
	char ans = 'y';
	while (ans == 'y') {
		int i, conter, d, b, k = 12, j, c = 0, count = 0;
		char number[13];
		string num[13];
		int adad[13];
		int sum = 0;
		cout << "enter the number :" << endl;
		cin >> number;
		for (i = 0; i < 13; i++) if (number[i] == NULL) break;
		for (int j = 0; j < i; j++) adad[j] = number[j] - 48;
		for (int j = 0; j < i; j++) sum += adad[j];
		if (sum == 0) cout << "sefr";
		else {
			conter = i - 1;
			d = conter;
			do {
				if (adad[d] == 0 && adad[d - 1] == 0) {
					num[k] = "sefr";
					num[k - 1] = "sefr";
					k -= 2;
					d -= 2;
				}
				else if (adad[d - 1] == 0 && adad[d] != 0) {
					b = 1;
					while (b < 10) {
						if (adad[d] == b) {
							num[k] = yekan[b - 1];
							k--;
							break;
						}
						b++;
					}
					num[k] = "sefr";
					k--;
					d -= 2;
				}
				else {
					j = (adad[d - 1] * 10) + adad[d];
					if (adad[d] != 0 && adad[d - 1] == 1) {
						b = 1;
						while (b < 10) {
							if (adad[d] == b) {
								num[k] = khas[b - 1];
								k--;
								break;
							}
							b++;
						}
						num[k] = "sefr";
						k--;
					}
					if (adad[d] != 0 && adad[d - 1] != 1) {
						b = 1;
						while (b < 10) {
							if (adad[d] == b) {
								num[k] = yekan[b - 1];
								k--;
								break;
							}
							b++;
						}
					}
					if (j == 10 || j >= 20) {
						if (adad[d] == 0) {
							num[k] = "sefr";
							k--;
						}
						b = 1;
						while (b < 10) {
							if (adad[d - 1] == b) {
								num[k] = dahgan[b - 1];
								k--;
								break;
							}
							b++;
						}
					}
					d -= 2;
				}
				if (adad[d] == 0) {
					num[k] = "sefr";
					k--;
					d--;
				}
				else {
					b = 1;
					while (b < 10) {
						if (adad[d] == b) {
							num[k] = sadgan[b - 1];
							d--;
							k--;
							break;
						}
						b++;
					}
				}
			} while (d >= 0);
			string test1;
			c = 0;
			count = 0;
			i = 12;
			for (int j = 12; j >= 0; j--)if (num[j] == test1) num[j] = "a";
			while (i >= 0) {
				if (num[i] != "sefr" && num[i - 1] != "sefr" && num[i - 2] != "sefr" && num[i] != "a" && num[i - 1] != "a" && num[i - 2] != "a") {
					if (c >= 3) {
						cout << " va " << hezarga[count] << num[i] << " va " << num[i - 1] << " va " << num[i - 2];
						count++;
					}
					else {
						cout << num[i] << " va " << num[i - 1] << " va " << num[i - 2];
					}
				}
				else if (num[i] == "sefr" && num[i - 1] != "sefr" && num[i - 2] != "sefr" && num[i - 1] != "a"&& num[i - 2] != "a") {
					if (c >= 3) {
						cout << " va " << hezarga[count] << num[i - 1] << " va " << num[i - 2];
						count++;
					}
					else {
						cout << num[i - 1] << " va " << num[i - 2];
					}
				}
				else if (num[i] == "sefr" && num[i - 1] == "sefr" && num[i - 2] != "sefr"  && num[i - 2] != "a") {
					if (c >= 3) {
						cout << " va " << hezarga[count] << num[i - 2];
						count++;
					}
					else {
						cout << num[i - 2];
					}
				}
				else if (num[i] != "sefr" && num[i - 1] == "sefr" && num[i - 2] != "sefr" && num[i] != "a" && num[i - 2] != "a") {
					if (c >= 3) {
						cout << " va " << hezarga[count] << num[i] << " va " << num[i - 2];
						count++;
					}
					else {
						cout << num[i] << " va " << num[i - 2];
					}
				}
				else if (num[i] == "sefr" && num[i - 1] != "sefr" && num[i - 2] == "sefr" && num[i - 1] != "a") {
					if (c >= 3) {
						cout << " va " << hezarga[count] << num[i - 1];
						count++;
					}
					else {
						cout << num[i - 1];
					}
				}
				else if (num[i] != "sefr" && num[i - 1] == "sefr" && num[i - 2] == "sefr" && num[i] != "a") {
					if (c >= 3) {
						cout << " va " << hezarga[count] << num[i];
						count++;
					}
					else {
						cout << num[i];
					}
				}
				else if (num[i] == "sefr" && num[i - 1] == "sefr" && num[i - 2] == "sefr") {
					if (c >= 3)  count++;
				}
				else if (num[i] != "sefr" && num[i] != "a" && num[i - 1] == "a" && num[i - 2] == "a") {
					if (c >= 3) {
						cout << " va " << hezarga[count] << num[i];
					}
					else cout << num[i];
				}
				else if (num[i] != "sefr" && num[i] != "a" && num[i - 1] != "sefr" && num[i - 1] != "a" && num[i - 2] == "a") {
					if (c >= 3) {
						cout << " va " << hezarga[count] << num[i] << " va " << num[i - 1];
					}
					else cout << num[i] << " va " << num[i - 1];
				}
				else if (num[i] != "sefr" && num[i - 1] != "sefr" && num[i] != "a" && num[i - 1] != "a" && num[i - 2] == "sefr") {
					if (c >= 3) {
						cout << " va " << hezarga[count] << num[i] << " va " << num[i - 1];
						count++;
					}
					else {
						cout << num[i] << " va " << num[i - 1];
					}
				}
				else if (num[i] != "sefr" && num[i] != "a" && num[i - 1] != "sefr" && num[i - 1] != "a" && num[i - 2] == "sefr") {
					if (c >= 3) {
						cout << " va " << hezarga[count] << num[i] << " va " << num[i - 1];
						count++;
					}
					else cout << num[i] << " va " << num[i - 1];
				}
				else if (num[i] == "sefr" && num[i - 1] != "sefr" && num[i - 1] != "a" && num[i - 2] == "a") {
					if (c >= 3) {
						cout << " va " << hezarga[count] << num[i - 1];
					}
					else cout << num[i - 1];
				}
				else if (num[i] != "sefr" && num[i] != "a"&& num[i - 1] == "sefr" && num[i - 2] == "a") {
					cout << num[i];
				}
				i -= 3;
				c += 3;
			}

		}
		cout << "\n do you wnat to continue(y/n)?" << endl;
		cin >> ans;
	}
	cin.get();
	cin.get();
}