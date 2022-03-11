Cerinta:
https://ocw.cs.pub.ro/courses/poo-is/tema1?&#restrictii

Siniuc Robert_Valentin 321AA

1.
	Pe langa clasa Player , am definit si clasa Team , ce contine numarul de Playeri dintr-o echipa , Numele echipei , si un pointer catre Playerii echipei.
	
	In functia read citesc mai intai nr de echipe iar apoi folosindu ma de acesta citesc toate echipele folosind operatorul >> , imediat dupa citirea unui element din fisier il adaug la lista.
	
	Pentru scrierea in fisier , folosesc operatorul << supradefinit la clasa Team , ce parcurge pe rand fiecare element la listei si il scrie sub formatul specificat in fisier; 
		

2.
	In functia losers , imi citesc din fisier numarul de echipe .
	
	Prin functia Delete_Min caut echipa cu cel mai mic punctaj  si o sterg din lista , dupa apelarea acesteiea scad 1 din nr de echipe , aceasta operatie se repete pana cand n devine putere a lui 2 (Priumul intalnit este totodata si cel mai mare n posibil)
	
	Functia Delete_Min , parcurge cu 2 pointeri lista si retine cea mai slaba echipa , la final aceasta este cautata inb lista iar elementul dinaintea lui, in lista, va avea ca next acum nextul echipei slabe (sarind astfel peste ea , si eliminand o din lista)
 
	La final se refoloseste functia de write pentru a scrie in fisier a echipelor ramase.	
3.
	Am implementat:
			 clasa Meciuri ==> Aceasta contine 2 echipe (acestea sunt luate in ordine din lista) , si un pointer catre urmatorul meci;

			 clasa Coada ==> Aceasta contine doi pointeri catre primul meci si ultimul meci	.

	Functia Lupte face mai multe lucruri:
			Parcurge cu doi pointeri lista de echipe si introduce in meciuri  , totodata creeaza si lista de meciuri
			Creeaza coada folosind lista de meciuri
			Pana cand ramane doar o echipa <==> Ia fiecare meci si folosind functia membra de executare a echipei mai slabe , afla care este echipa castigatoare si o returneaza, aceasta fiind adaugata la lista de wineri , lafel si pentru loser.
			Dupa ce aflu castigatorii repet functia de lupta cu lista win ;
			Cadn termin ii afisez;
			

4.	Am implementat clasa Bst ce contine echipa si pointer catre o frunza din dreapta si din stanga.
	
	Cand ajung in runda in care raman cu 8 echipe , creez cu acestea un BST , mergand din frunza in frunza si asezand termenii in locuri goala , la stanga daca au punctajul mai mic si la dreapta daca au punctajul mai mare , iar daca au punctajul egal ,inafara de radacina voi pune la stanga (pt ordice buna) , iar in rest la stanga.

	Pentru afisare parcurg invers partea dreapta a BST-ului iar apoi partea stanga.
