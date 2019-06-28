#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void find_family(vector<string>& spisok, unsigned size)
{
 string stroka1,stroka2;
 string family1, family2;
 int probel1, probel2;
 unsigned int i = 0, j = 0;
 for(i = 0; i < size; i++) {
 stroka1=spisok.at(i);
 for(unsigned int k = 0; k < stroka1.size(); k++) {
 if(stroka1.at(k)==' ') {
 probel1 = k;
 break;
 }
 }
 family1 = stroka1.substr(0,probel1);
 for(j = i + 1; j < size; j++) {
 stroka2=spisok.at(j);
 for(unsigned int k = 0; k < stroka2.size(); k++) {
 if(stroka2.at(k)==' ') {
 probel2 = k;
 break;
 }
 }
 family2 = stroka2.substr(0,probel2);
 if (family1 == family2) {
 cout << stroka1 << endl<< stroka2 << endl;
 }
 }
 }
}


int Fprobel(string stroka, int pos)
{
 int probel;
 for(unsigned int k = pos; k < stroka.size(); k++) {
 if(stroka.at(k)==' ') {
 probel = k;
 break;
 }
 }
 return probel;
}

void find_name(vector<string> spisok, unsigned size)
{
 string stroka1,stroka2;
 string name1, name2;
 unsigned int i,j,k=0;
 string rare_name [size];
 int probel1, probel2;
 for(i = 0; i < size; i++) {
 stroka1 = spisok.at(i);
 if(!stroka1.empty()){
 probel1 = Fprobel(stroka1,0);
 probel2 = Fprobel(stroka1,probel1);
 name1 = stroka1.substr(probel1,probel2);
 for(j = i + 1; j < size; j++) {
 stroka2 = spisok.at(j);
 if(!stroka2.empty()){
 probel1 = Fprobel(stroka2,0);
 probel2 = Fprobel(stroka2,probel1);
 
 name2 = stroka2.substr(probel1,probel2);
 if (name1 == name2){
 k++;
 spisok.at(j).erase(0,stroka2.size());

 }
 }
 }
 rare_name [k] = rare_name[k] + ' ' + name1;
 k=0;
 }
 }
 for(unsigned int c = 0; c < size; c++) {
 string finalname = rare_name[c];
 if(!finalname.empty())
 cout << finalname <<" с частотой - " << c+1 << endl;
 }
}

void sort (vector <string>& array, int size)
{
 bool k=1;
 while (k) {
 k = 0;
 for (int i = 1; i < size; i++) {
 if (array[i] < array[i - 1]) {
 string t = array[i];
 array[i] = array[i-1];
 array[i-1] = t;
 k=1;

 }
 }
 }
}

int main()
{
 ifstream fail("/root/2_prakt/group");
 unsigned i = 0;
 vector<string> result;
 string stroka;
 while (getline(fail, stroka)) {
 if (stroka != "\n" || stroka != " " || stroka != "\t")
 result.push_back(stroka);
 }

 cout << "Список:" << endl;
 for (i = 0; i < result.size(); i++)
 cout << result.at(i) << endl;
 cout << endl;
 sort(result, result.size());
 cout << "Отсортированнй список:" << endl;
 for (i = 0; i < result.size(); i++)
 cout << result[i] << endl;
 cout << endl;
 cout << "Однофамильцы:" << endl;
 find_family(result, result.size());
 cout << endl;
 cout << "Частота имен:" << endl;
 find_name(result, result.size());
 fail.close();
 return 0;
}