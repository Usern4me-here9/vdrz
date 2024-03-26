IspisiPut(int cvor_iz_kojeg_smo_dosli[],int polazni_cvor,int destinacija){
	
	if(polazni_cvor != destinacija){
		IspisiPut(cvor_iz_kojeg_smo_dosli, polazni_cvor, cvor_iz_kojeg_smo_dosli[destinacija])
	}
	cout << destinacija << "	";
}

void dijkstra(int matrica_susednosti[max][max],int broj_cvorova, int pocetni_cvor)
{
	int udaljenost[MAX], cvor_iz_kojeg_smo_dosli[], posecen[MAX] = {0}, minimalna_distanca, cvor_minimuma;
	posecen[pocetni_cvor] = 1;
	
	for(int i = 0; i < n; i++){
		udaljenost[i] = matrica_susednosti[pocetni_cvor][i];
		cvor_iz_kojeg_smo_dosli[i] = pocetni_cvor;
	}
	
	for(int k = 0; k < n-1; k++){
		minimalna_distanca = INF;
		
		for(int i = 0; i < n; i++){
			if(udaljenost[i] < minimalna_distanca && posecen[i] == 0){
				minimalna_distanca = udaljenost[i];
				cvor_minimuma = i;
			}
		}
		
		if(udaljenost[cvor_minimuma] == INF)
			break;
			
		posecen[cvor_minimuma] = 1;
		
		for(int i = 0; i < n; i++){
			if(posecen[i] == 0){
				if(minimalna_distanca + matrica_susednosti[cvor_minimuma][i] < udaljenost[i]){
					udaljenost[i] = minimalna_distanca + matrica_susednosti[cvor_minimuma][i];
					cvor_iz_kojeg_smo_dosli[i] = cvor_minimuma;
				}
			{
		}
	}
	
	cout << "Grad	Udaljenost	Mozemo doci	Mozemo se vratiti	Putanja" << endl;
	
	for(int i = 0; i < MAX; i++){
	
		if(udaljenost[i] != INF){
			cout << "	" << i << "	" << udaljenost[i] << "	";
			
			if(udaljenost[i] <= (kolicina_goriva / potrosnja_automobila) * 100)
				cout << "	DA	";
			else
				cout << "	NE	";
				
			if(udaljenost[i]*2 <= (kolicina_goriva / potrosnja_automobila) * 100)
				cout << "	DA	";
			else
				cout << "	NE	";
				
			IspisiPut(cvor_iz_kojeg_smo_dosli, 0 ,i);
			
			cout << "	";
		}
		else{
			cout << "Put ne postoji";
		}
		cout << endl;
	}
}