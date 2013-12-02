/*
Harjoitus 17
Tekij‰: Hanna Lukkarinen
Pvm: 26.11.2013

Kuvaus: Muokkaa edellist‰ ohjelmaa siten, ett‰ edell‰ m‰‰ritelty‰ tietuetyyppi‰
k‰ytet‰‰n my‰s kahden muun "koululaisen" tietojen tallentamiseen.
N‰iden kahden muun koululaisen tiedot alustetaan ao. muuttujien
m‰‰rittelyn yhteydess‰. Ainoastaan yhden koululaisen tiedot kysyt‰‰n
k‰ytt‰j‰lt‰ edellisen teht‰v‰n tapaan.

Tulosta kolmen koululaisen tiedot koulumatkan mukaisessa
suuruusj‰rjestyksess‰ (pienimm‰st‰ suurimpaan) n‰yt‰lle.

*/

#include <iostream>
using namespace std;

struct HENKILOTIEDOT
{
	char etunimi[15];
	char sukunimi[20];
	float koulumatka;
	char osoite[30];
	char postinumero[20];
	int kengannumero;
};

void main()
{
	HENKILOTIEDOT henk[5] = {
				{"Aku", "Ankka", 5.5, "Esimerkkitie 2", "40123 JKL", 40},
				{"Mikko", "Meik‰l‰inen", 1.2, "Katukuja 13 A2", "12345 JKL", 38}
				};

	cout<<"Anna etunimesi: ";
	cin>>ws>>henk[2].etunimi;
	cout<<"Anna sukunimesi: ";
	cin>>ws>>henk[2].sukunimi;
	cout<<"Anna koulumatkasi pituus kilometrein‰: ";
	cin>>ws>>henk[2].koulumatka;
	cout<<"Anna osoitteesi: ";
	cin>>ws;
	cin.get(henk[2].osoite, 30);
	cout<<"Anna postinumerosi ja postitoimipaikkasi: ";
	cin>>ws;
	cin.get(henk[2].postinumero, 20);
	cout<<"Anna keng‰nnumerosi: ";
	cin>>ws>>henk[2].kengannumero;

	while(henk[0].koulumatka > henk[1].koulumatka || henk[1].koulumatka > henk[2].koulumatka)
	{
		if (henk[0].koulumatka > henk[1].koulumatka)
		{
			henk[3] = henk[0];
			henk[0] = henk[1];
			henk[1] = henk[3];
		}
		if (henk[1].koulumatka > henk[2].koulumatka)
		{
			henk[3] = henk[1];
			henk[1] = henk[2];
			henk[2] = henk[3];
		}
	}

	for(int i = 0; i < 3; i++)
	{
	cout<<"\nNimi: "<<henk[i].etunimi<<' '<<henk[i].sukunimi<<endl;
	cout<<"Osoite: "<<henk[i].osoite<<endl;
	cout<<"Postinumero ja -toimipaikka: "<<henk[i].postinumero<<endl;
	cout<<"Koulumatkan pituus: "<<henk[i].koulumatka<<" km\n";
	cout<<"Keng‰nnumero: "<<henk[i].kengannumero<<endl;
	}
}