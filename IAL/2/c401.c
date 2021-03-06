
/* c401.c: **********************************************************}
{* Téma: Rekurzivní implementace operací nad BVS
**                                         Vytvořil: Petr Přikryl, listopad 1994
**                                         Úpravy: Andrea Němcová, prosinec 1995
**                                                      Petr Přikryl, duben 1996
**                                                   Petr Přikryl, listopad 1997
**                                  Převod do jazyka C: Martin Tuček, říjen 2005
**                                         Úpravy: Bohuslav Křena, listopad 2009
**                                         Úpravy: Karel Masařík, říjen 2013
**                                         Úpravy: Radek Hranický, říjen 2014
**                                         Úpravy: Radek Hranický, listopad 2015
**                                         Úpravy: Radek Hranický, říjen 2016
**
** Implementujte rekurzivním způsobem operace nad binárním vyhledávacím
** stromem (BVS; v angličtině BST - Binary Search Tree).
**
** Klíčem uzlu stromu je jeden znak (obecně jím může být cokoliv, podle
** čeho se vyhledává). Užitečným (vyhledávaným) obsahem je zde integer.
** Uzly s menším klíčem leží vlevo, uzly s větším klíčem leží ve stromu
** vpravo. Využijte dynamického přidělování paměti.
** Rekurzivním způsobem implementujte následující funkce:
**
**   BSTInit ...... inicializace vyhledávacího stromu
**   BSTSearch .... vyhledávání hodnoty uzlu zadaného klíčem
**   BSTInsert .... vkládání nové hodnoty
**   BSTDelete .... zrušení uzlu se zadaným klíčem
**   BSTDispose ... zrušení celého stromu
**
** ADT BVS je reprezentován kořenovým ukazatelem stromu (typ tBSTNodePtr).
** Uzel stromu (struktura typu tBSTNode) obsahuje klíč (typu char), podle
** kterého se ve stromu vyhledává, vlastní obsah uzlu (pro jednoduchost
** typu int) a ukazatel na levý a pravý podstrom (LPtr a RPtr). Přesnou definici typů
** naleznete v souboru c401.h.
**
** Pozor! Je třeba správně rozlišovat, kdy použít dereferenční operátor *
** (typicky při modifikaci) a kdy budeme pracovat pouze se samotným ukazatelem
** (např. při vyhledávání). V tomto příkladu vám napoví prototypy funkcí.
** Pokud pracujeme s ukazatelem na ukazatel, použijeme dereferenci.
**/

/*
 * VUT FIT 2BIA
 * *****************************
 * 1. Domaca uloha z IAL
 * Implementoval: Jan Jakub Kubik (xkubik32@stud.fit.vutbr.cz)
 * Vypracovane: 21.10.2017
 * ***************************
*/

#include "c401.h"
int solved;

void BSTInit (tBSTNodePtr *RootPtr) {
/*   -------
** Funkce provede počáteční inicializaci stromu před jeho prvním použitím.
**
** Ověřit, zda byl již strom předaný přes RootPtr inicializován, nelze,
** protože před první inicializací má ukazatel nedefinovanou (tedy libovolnou)
** hodnotu. Programátor využívající ADT BVS tedy musí zajistit, aby inicializace
** byla volána pouze jednou, a to před vlastní prací s BVS. Provedení
** inicializace nad neprázdným stromem by totiž mohlo vést ke ztrátě přístupu
** k dynamicky alokované paměti (tzv. "memory leak").
**
** Všimněte si, že se v hlavičce objevuje typ ukazatel na ukazatel.
** Proto je třeba při přiřazení přes RootPtr použít dereferenční operátor *.
** Ten bude použit i ve funkcích BSTDelete, BSTInsert a BSTDispose.
**/
	(*RootPtr) = NULL;

	 //solved = FALSE;		  /* V případě řešení smažte tento řádek! */

}

int BSTSearch (tBSTNodePtr RootPtr, char K, int *Content)	{
/*  ---------
** Funkce vyhledá uzel v BVS s klíčem K.
**
** Pokud je takový nalezen, vrací funkce hodnotu TRUE a v proměnné Content se
** vrací obsah příslušného uzlu.´Pokud příslušný uzel není nalezen, vrací funkce
** hodnotu FALSE a obsah proměnné Content není definován (nic do ní proto
** nepřiřazujte).
**
** Při vyhledávání v binárním stromu bychom typicky použili cyklus ukončený
** testem dosažení listu nebo nalezení uzlu s klíčem K. V tomto případě ale
** problém řešte rekurzivním volání této funkce, přičemž nedeklarujte žádnou
** pomocnou funkci.
**/

	// check if tree isnt empty
	if ( RootPtr == NULL )  {							
		return FALSE;
	}

	// root ptr is found itm
	else if ( RootPtr->Key == K ) {						

			*Content = RootPtr->BSTNodeCont;
			return TRUE;
	}
	
	// recursive call of left children
	else if ( K < RootPtr->Key ) {
			return BSTSearch( RootPtr->LPtr, K, Content );		
	}
	
	// recursive call of right children
	else return BSTSearch( RootPtr->RPtr, K, Content );		

	 //solved = FALSE;		  /* V případě řešení smažte tento řádek! */
}


void BSTInsert (tBSTNodePtr* RootPtr, char K, int Content)	{
/*   ---------
** Vloží do stromu RootPtr hodnotu Content s klíčem K.
**
** Pokud již uzel se zadaným klíčem ve stromu existuje, bude obsah uzlu
** s klíčem K nahrazen novou hodnotou. Pokud bude do stromu vložen nový
** uzel, bude vložen vždy jako list stromu.
**
** Funkci implementujte rekurzivně. Nedeklarujte žádnou pomocnou funkci.
**
** Rekurzivní implementace je méně efektivní, protože se při každém
** rekurzivním zanoření ukládá na zásobník obsah uzlu (zde integer).
** Nerekurzivní varianta by v tomto případě byla efektivnější jak z hlediska
** rychlosti, tak z hlediska paměťových nároků. Zde jde ale o školní
** příklad, na kterém si chceme ukázat eleganci rekurzivního zápisu.
**/

	// root is empty
	if ( (*RootPtr) == NULL ) {										

		// create new item
		tBSTNodePtr newItm = malloc(sizeof(struct tBSTNode));		

		if ( newItm == NULL ) {
			exit(99);
		}
		
		newItm->BSTNodeCont = Content;
		newItm->Key = K;
		newItm->LPtr = NULL;
		newItm->RPtr = NULL;

		(*RootPtr) = newItm;
	}

	else if ( (*RootPtr)->Key == K ) {
		(*RootPtr)->BSTNodeCont = Content;
	}

	else if ( K < (*RootPtr)->Key ) {
		BSTInsert ( &((*RootPtr)->LPtr), K, Content );		
	}

	else {
		BSTInsert ( &((*RootPtr)->RPtr), K, Content );
	}


	 //solved = FALSE;		  /* V případě řešení smažte tento řádek! */

}

void ReplaceByRightmost (tBSTNodePtr PtrReplaced, tBSTNodePtr *RootPtr) {
/*   ------------------
** Pomocná funkce pro vyhledání, přesun a uvolnění nejpravějšího uzlu.
**
** Ukazatel PtrReplaced ukazuje na uzel, do kterého bude přesunuta hodnota
** nejpravějšího uzlu v podstromu, který je určen ukazatelem RootPtr.
** Předpokládá se, že hodnota ukazatele RootPtr nebude NULL (zajistěte to
** testováním před volání této funkce). Tuto funkci implementujte rekurzivně.
**
** Tato pomocná funkce bude použita dále. Než ji začnete implementovat,
** přečtěte si komentář k funkci BSTDelete().
**/
	tBSTNodePtr rem = (*RootPtr);

	while ( rem->RPtr != NULL ) {

		rem = rem->RPtr;
	}

	PtrReplaced->Key = rem->Key;
	PtrReplaced->BSTNodeCont = rem->BSTNodeCont;

	BSTDelete(&(*RootPtr), rem->Key);

	 //solved = FALSE;		  /* V případě řešení smažte tento řádek! */

}

void BSTDelete (tBSTNodePtr *RootPtr, char K) 		{
/*   ---------
** Zruší uzel stromu, který obsahuje klíč K.
**
** Pokud uzel se zadaným klíčem neexistuje, nedělá funkce nic.
** Pokud má rušený uzel jen jeden podstrom, pak jej zdědí otec rušeného uzlu.
** Pokud má rušený uzel oba podstromy, pak je rušený uzel nahrazen nejpravějším
** uzlem levého podstromu. Pozor! Nejpravější uzel nemusí být listem.
**
** Tuto funkci implementujte rekurzivně s využitím dříve deklarované
** pomocné funkce ReplaceByRightmost.
**/
	if ( *RootPtr != NULL ) {												// check if tree isnt empty

		if ( K < (*RootPtr)->Key ) { 	
													
			BSTDelete(&(*RootPtr)->LPtr, K);								// check left subtree

		}	
		else if ( K > (*RootPtr)->Key	 ) {	

			BSTDelete(&(*RootPtr)->RPtr, K);								// chcek right subtree

		}	

		else {																// found item
			
			if ( (*RootPtr)->LPtr == NULL && (*RootPtr)->RPtr == NULL ) { 	// no childre

				free(*RootPtr);

				(*RootPtr) = NULL;
			} 

			else if ( (*RootPtr)->LPtr == NULL ) { 							// one child (right)
				
				tBSTNodePtr del = (*RootPtr);
				(*RootPtr) = (*RootPtr)->RPtr;

				free(del);

			} 
			else if ( (*RootPtr)->RPtr == NULL ) {							// one child (left)
				
				tBSTNodePtr del = (*RootPtr);
				(*RootPtr) = (*RootPtr)->LPtr;

				free(del);

			} 

			else {															// item has two children
				ReplaceByRightmost ((*RootPtr), &(*RootPtr)->LPtr);
			}
		}	
	}	




	 //solved = FALSE;		  /* V případě řešení smažte tento řádek! */

}

void BSTDispose (tBSTNodePtr *RootPtr) {
/*   ----------
** Zruší celý binární vyhledávací strom a korektně uvolní paměť.
**
** Po zrušení se bude BVS nacházet ve stejném stavu, jako se nacházel po
** inicializaci. Tuto funkci implementujte rekurzivně bez deklarování pomocné
** funkce.
**/
	while ( *RootPtr != NULL ) {

		BSTDispose( &((*RootPtr)->LPtr) );
		BSTDispose( &((*RootPtr)->RPtr) );

		free( *RootPtr );
		
		*RootPtr = NULL;					 
	}

	 //solved = FALSE;		  /* V případě řešení smažte tento řádek! */

}

/* konec c401.c */
