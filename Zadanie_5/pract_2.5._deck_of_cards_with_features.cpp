#include <iostream>
#include <vector>
#include <ctime>
15
using namespace std;
void convert (int mast,int karta)
{
 switch ( (int)mast ) {
 case 1:
 cout<<"Черви";
 break;
 case 2:
 cout<<"Буби";
 break;
 case 3:
 cout<<"Крести";
 break;
 case 0:
 cout<<"Пики";
 break;
 }
 cout<<" ";
 switch ( (int)karta ) {
 case 1:
 cout<<"6";
 break;
 case 2:
 cout<<"7";
 break;
 case 3:
16
 cout<<"8";
 break;
 case 4:
 cout<<"9";
 break;
 case 5:
 cout<<"10";
 break;
 case 6:
 cout<<"Валет";
 break;
 case 7:
 cout<<"Дама";
 break;
 case 8:
 cout<<"Король";
 break;
 case 0:
 cout<<"туз";
 break;
 }
 cout<<endl;
}
int main()
{
 bool er =0;
 int c = 0,i=0;
17
 vector<int> mast(36,11);
 vector<int> karta(36,13);
 vector <string> Itog(36);
 while (i<36) {
 er = 0;
 c++;
 srand((unsigned int)time(NULL)+(c*71)/3);
 int cvet = rand() % 4;
 int nominal = rand() % 9;
 for (int j=0; j<36; j++) {
 if ((mast.at(j) == cvet) && (karta.at(j) == nominal)) {
 er = 1;
 break;
 }
 }
 if(er) {
 continue;
 }
 mast.at(i) = cvet;
 karta.at(i) = nominal;
 i++;
 }
 /*for(int i =0; i<36; i++) {
 cout<<mast.at(i)<<" ";
 cout<<karta.at(i)<<endl;
 }*/
18
 cout<<"Заполнение\перемешивание"<<endl;
 for(int i=0; i<36; i++) {
 int mast1=mast.at(i);
 int karta1=karta.at(i);
 convert(mast1,karta1);
 }
 cout<<"\vНахождением одинаковых"<<endl;
 for(int i=1; i<36; i++) {
 if (mast.at(i-1)==mast.at(i)) {
 int mast1=mast.at(i);
 int karta1=karta.at(i);
 int karta2=karta.at(i-1);
 convert(mast1,karta1);
 convert(mast1,karta2);
 }
 }
 cout<<"\vНахождением одинаковых"<<endl;
 for(int i=1; i<36; i++) {
 if (karta.at(i-1)==karta.at(i)) {
 int mast1=mast.at(i);
 int karta1=karta.at(i);
 int mast2=mast.at(i-1);
 convert(mast1,karta1);
 convert(mast2,karta1);
 }
 }
 cout<<"\vНахождением дамы"<<endl;
19
 for(int i=1; i<36; i++) {
 if ((karta.at(i)==7)&&(mast.at(i)==0)) {
 int mast1=mast.at(i);
 int karta1=karta.at(i);
 convert(mast1,karta1);
 }
 }

 cout<<"\vНахождением тузов"<<endl;
 for(int i=1; i<36; i++) {
 if ((karta.at(i)==0)) {
 int mast1=mast.at(i);
 int karta1=karta.at(i);
 convert(mast1,karta1);
 }
 }
 return 0;
}
