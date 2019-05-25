#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

struct Card{
	int face;
	char type;
	struct Card *next;
};
typedef struct Card card;

card * createDeck(){
	card *head;
	card *currCard;
	card *newCard;
	char types[] = {'H', 'S', 'C', 'D'};
	char type;
	int face;
	int i, j;
	for(i=0; i<13; i++){
		face = i+1;
		for(j=0; j<4; j++){
			type = types[j];
			newCard = malloc(sizeof(card));

			newCard->face = face;
			newCard->type = type;
			newCard->next = NULL;

			if(i==0 && j==0){
				head = newCard;
				currCard = head;
			}else{
				currCard->next = newCard;
				currCard = currCard->next;
			}
		}
	}
	return head;
}

void printDeck(card *head){
	card *currCard;
	currCard = head;
	int i=0;
	while(1){
		if(currCard->next == NULL){
			printf("Card %d : %d of %c", i, currCard->face, currCard->type);
			break;
		}else {
			printf("Card %d : %d of %c\n", i, currCard->face, currCard->type);
			currCard = currCard->next;
		}
		i++;
	}
}

void swapCards(card *card1, card *card2){
	int tmpFace;
	char tmpType;

	tmpFace = card1->face;
	card1->face = card2->face;
	card2->face = tmpFace;

	tmpType = card1->type;
	card1->type = card2->type;
	card2->type = tmpType;
}

card * getCard(card *head, int index){
	card *currCard; 
	int i;

	currCard = head;
	for(i=0; i<index; i++){
		if(i>=52) break;
		currCard = currCard->next;
	}
	return currCard;
}

void shuffleDeck(card *head){
	card *currCard;
	currCard = head;
	srand(time(NULL));
	int i;
	int index;
	for(i=0; i<52; i++){
		index = rand() % 52;
		swapCards(currCard, getCard(head, index));
		currCard = currCard->next;
	}
}
