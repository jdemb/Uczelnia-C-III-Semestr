package pkg;
import java.util.Scanner;
class Pokoj{
	public int numer_pietra;
	public int numer_pokoju;
	public boolean wolny;
	public String nazwisko;
	public Pokoj(int numer_pietra, int numer_pokoju, boolean wolny, String nazwisko){
		this.numer_pietra = numer_pietra;
		this.numer_pokoju = numer_pokoju;
		this.wolny = wolny;
		this.nazwisko = nazwisko;
	}
	public boolean czyWolny(){
		if(wolny) return true;
		else return false;
	}
	public void zajmijPokoj()
	{
		if(wolny)
		{
			Scanner odczyt = new Scanner(System.in);
			System.out.println("Podaj nazwisko klienta");
			String naz = odczyt.nextLine();
			this.nazwisko = naz;
			this.wolny = false;
			System.out.println("Pokoj zostal zajety");
		}
		else
			System.out.println("Pokoj jest juz zajety");
	}
	public void zwolnijPokoj()
	{
		System.out.println("Pokoj numer: " + numer_pokoju + " zostaje zwolniony");
		this.wolny = true;
		this.nazwisko = "";
	}
}
class Pietro{
	public int numer_pietra;
	public int liczba_pokoi;
	public Pietro(int numer_pietra, int liczba_pokoi){
		this.numer_pietra = numer_pietra;
		this.liczba_pokoi = liczba_pokoi;
	}
}
class Hotel{
	public int liczba_pieter;
	public Hotel(int liczba_pieter){
		this.liczba_pieter = liczba_pieter;
	}
	Pietro[] pietro = new Pietro[4+1];
	Pokoj[][] pokoj = new Pokoj[4+1][5+1];
	public void przypiszPokoje()
	{
		for(int i=1; i<=4; i++)
		{
			pietro[i] = new Pietro(i, 5);
			for(int j=1; j<=5; j++)
				pokoj[i][j] = new Pokoj(i,j,true,"");
		}
	}
	public boolean czyPokojWolny(int i, int j){
		return pokoj[i][j].czyWolny();
	}
	public void zajmijPokoj(int i, int j){
	    pokoj[i][j].zajmijPokoj();
	}
	public void zwolnijPokoj(int i, int j){
		pokoj[i][j].zwolnijPokoj();
	}
	public int czyJakisWolny(int numer_pietra){
		for(int i=1; i<=5; i++)
		{
			if(pokoj[numer_pietra][i].czyWolny())
				return i;
		}
		return 0;
	}
	public boolean czyKpokoi(int k){ //czy mozna wynajac k sasiednich pokoi
		int ile = 0;
		for(int i=1; i<=4; i++)
		{
			for(int j=1; j<=5; j++)
			{
				if(pokoj[i][j].czyWolny())
					ile++;
				if(!pokoj[i][j].czyWolny())
					ile=0;
				if(ile==k)
					return true;
			}
			ile = 0;
		}
		return false;
	}
	public void pokojePoNazwisku(String nazwisko){
		boolean znalazl = false;
		int[] tab = new int[20+1];
		int z = 0;
		for(int i=1; i<=4; i++)
		{
			for(int j=1; j<=5; j++)
			{
				if(pokoj[i][j].nazwisko.equals(nazwisko))
				{
					System.out.println("Pokoj: " + j + "Na pietrze: " + i);
					tab[z] = i;
					z++;
					tab[z] = j;
					z++;
					znalazl = true;
				}
			}
		}
		if(!znalazl)
			System.out.println("Nie znaleziono zadnych pokoi");
		else
		{
			System.out.println("Czy zwolnic znalezione pokoje? \n TAK (wprowadz '1') NIE (wprowadz '0') ");
			Scanner odczyt = new Scanner(System.in);
			int bool = odczyt.nextInt();
			if(bool==1)
			{
				for(int i=0; i<z; i+=2)
				{
					pokoj[tab[i]][tab[i+1]].zwolnijPokoj();
				}
				System.out.println("Pokoje zostaly zwolnione");
			}
		}
	}
}

public class Program {
	public static void main(String[] args) {
	    Hotel hotel = new Hotel(4);
		hotel.przypiszPokoje();
		while(true)
		{
			System.out.println("Witaj w programie SuperHotel, wybierz co chcesz zrobic");
			System.out.println("//////////////////////////////////////////////////////");
			System.out.println("1. Zajmij pokoj");
			System.out.println("2. Zwolnij pokoj");
			System.out.println("3. Sprawdz czy dany pokoj jest wolny");
			System.out.println("4. Sprawdz czy mozna wynajac k sasiednich pokoi");
			System.out.println("5. Wyszukaj wynajete pokoje po nazwisku klienta");
			System.out.println("6. Sprawdz czy na danym pietrze znajduje sie wolny pokoj");
			Scanner odczyt = new Scanner(System.in);
			int wejscie = odczyt.nextInt();
			int wejscie2,wejscie3;
			String wejscie4;
			switch (wejscie) {
            case 1:  System.out.println("Podaj numer pokoju");
					 wejscie2 = odczyt.nextInt();
					 System.out.println("Podaj numer pietra");
					 wejscie3 = odczyt.nextInt();
					 hotel.zajmijPokoj(wejscie3,wejscie2);
					 break;
            case 2:  System.out.println("Podaj numer pokoju");
					 wejscie2 = odczyt.nextInt();
					 System.out.println("Podaj numer pietra");
					 wejscie3 = odczyt.nextInt();
					 hotel.zwolnijPokoj(wejscie3,wejscie2);
                     break;
            case 3:  System.out.println("Podaj numer pokoju");
					 wejscie2 = odczyt.nextInt();
					 System.out.println("Podaj numer pietra");
					 wejscie3 = odczyt.nextInt();
					 if(hotel.czyPokojWolny(wejscie3,wejscie2))
					 System.out.println("Jest wolny");
					 else
					 System.out.println("Nie jest wolny");
                     break;
            case 4:  System.out.println("Podaj liczbe pokoi");
					 wejscie2 = odczyt.nextInt();
					 if(hotel.czyKpokoi(wejscie2))
					 System.out.println("Mozna");
					 else
					 System.out.println("Nie mozna");
                     break;
            case 5:  System.out.println("Podaj nazwisko klienta");
					 wejscie4 = odczyt.next();
					 hotel.pokojePoNazwisku(wejscie4);
                     break;
			case 6:  System.out.println("Podaj pietro");
					 wejscie2 = odczyt.nextInt();
					 int a=hotel.czyJakisWolny(wejscie2);
					 if(a==0)
					 System.out.println("Nie ma wolnego");
					 else
					 System.out.println("Jest wolny pokoj: " + a);
                     break;
            default: System.out.println("Niepoprawne wejscie");
                     break;
        }
		}
	}
}
