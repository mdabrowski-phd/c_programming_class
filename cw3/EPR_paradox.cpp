//sprawdzenie iloczynu nieoznaczonosci polozenia i pedu czastki -> zasada nieoznaczosci Heisenberga

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	//wczytujemy plik z danymi o polozeniach
	ifstream plik("position_data.txt");
	if(!plik)
	{
		cerr << "Brak pliku.";
		return 1;
	}
	vector<double> posX, posY;
	double x, y;
	while(plik >> x >> y)
	{
		posX.push_back(x);
		posY.push_back(y);
	}
	plik.close();
	
	//wczytujemy plik z danymi o pedach
	ifstream plik2("momentum_data.txt");
	if(!plik2)
	{
		cerr << "Brak pliku.";
		return 1;
	}
	vector<double> momX, momY;
	while(plik2 >> x >> y)
	{
		momX.push_back(x);
		momY.push_back(y);
	}
	plik2.close();
	
	//obliczenia sredniej
	double mu_pos=0, mu_mom=0;
	for(int i=0; i<posY.size();i++)
		mu_pos+=posY[i]*posX[i];
	mu_pos/=posY.size();
	
	for(int i=0; i<momY.size();i++)
		mu_mom+=momY[i]*momX[i];
	mu_mom/=momY.size();
	
	//obliczenia odchylenia standardowego
	double sigma_pos=0, sigma_mom=0;
	for(int i=0; i<posY.size();i++)
		sigma_pos+=(posY[i]-mu_pos)*(posY[i]-mu_pos);
	sigma_pos=sqrt(sigma_pos/(posY.size()-1));
	for(int i=0; i<momY.size();i++)
		sigma_mom+=(momY[i]-mu_mom)*(momY[i]-mu_mom);
	sigma_mom=sqrt(sigma_mom/(momY.size()-1));
	
	/*iloczyn nieoznaczonosci polozenia i pedu -> nierownosc Heisenberga
	wyniki pomiarow zapisane w plikach s¹ w ukladzie jednostek, gdzie h_bar=1*/
	//cout << sigma_pos << " " << sigma_mom << endl;
	//mu_pos=mu_pos-posX.size()/2;
	//mu_mom=mu_mom-momX.size()/2;
	
	sigma_pos=sigma_pos/posX.size()*double(abs(posX[posX.size()-1]-posX[0]));
	sigma_mom=sigma_mom/momX.size()*double(abs(momX[momX.size()-1]-momX[0]));
	//cout << double(abs(pos[pos.size()-1]-pos[0])) << endl;
	cout << mu_pos << " " << mu_mom << endl;
	//cout << sigma_pos << " " << sigma_mom << endl;
	//cout << sigma_pos*sigma_mom;
	return 0;
	
}
