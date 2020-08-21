import random

suits = ('Hearts', 'Diamonds', 'Spades', 'Clubs')
ranks = ('Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine', 'Ten', 'Jack', 'Queen', 'King', 'Ace')
values = {'Two':2, 'Three':3, 'Four':4, 'Five':5, 'Six':6, 'Seven':7, 'Eight':8, 'Nine':9, 'Ten':10, 'Jack':10,
         'Queen':10, 'King':10, 'Ace':11}

playing = True

class Card:
    
    def __init__(self,suit,rank):
        self.suit = suit
        self.rank = rank
    
    def __str__(self):
        return f"{self.rank} of {self.suit}"


class Deck:
    
    def __init__(self):
        self.deck = []  # start with an empty list
        for suit in suits:
            for rank in ranks:
                (self.deck).append(Card(suit, rank))
    
    def __str__(self):
        deck_comp = ""
        for card in self.deck:
            deck_comp += "\n" + str(card) 
        return deck_comp

    def shuffle(self):
        random.shuffle(self.deck)
        
    def deal(self):
        single_card = self.deck.pop()
        return single_card

class Hand:

    def __init__(self):
        self.cards = []  # start with an empty list as we did in the Deck class
        self.value = 0   # start with zero value
        self.aces = 0    # add an attribute to keep track of aces
    
    def add_card(self,card):
        self.cards.append(card)
        self.value += values[card.rank]
        
        if card.rank == "Ace":
            self.aces += 1
    
    def adjust_for_ace(self):
        while self.value > 21 and self.aces:
            self.value -= 10
            self.aces -= 1
class Chips:
    
    def __init__(self):
        self.total = 100  # This can be set to a default value or supplied by a user input
        self.bet = 0
        
    def win_bet(self):
        self.total += self.bet
    
    def lose_bet(self):
        self.total -= self.bet
        
def take_bet(Chips):

    while True:
        try:
            Chips.bet = int(input("Please enter your bet: "))
        except:
            print("That is not an integer!")
        else:
            if Chips.bet > Chips.total:
                    print(f"Sorry you do not have enough chips to bet {Chips.bet} chips! You have {Chips.total} chips!")
            else:
                break
                
def hit(deck,hand):
    hand.add_card(deck.deal())
    hand.adjust_for_ace()
    
def hit_or_stand(deck,hand):
    global playing
    
    while True:
        x = input("Hit or Stand? Enter H or S")
        
        if x[0].upper() == 'H':
            hit(deck, hand)
            show_some(player,dealer)
            break
            
        elif x[0].upper() == 'S':
            print("Player Stands, Dealer's Turn")
            playing = False
            break
            
        else:
            print("Not a valid input. Please enter H or S")
            continue
            
def player_busts(player,dealer,chips):
    print("\n")
    print("Player BUSTS!")
    chips.lose_bet()

def player_wins(player,dealer,chips):
    print("\n")
    print("Player WINS!")
    chips.win_bet()

def dealer_busts(player,dealer,chips):
    print("\n")
    print("Player WINS! Dealer BUSTS!")
    chips.win_bet()
    
def dealer_wins(player,dealer,chips):
    print("\n")
    print("Player BUSTS! Dealer WINS")
    chips.lose_bet()
    
def push(player,dealer):
    print("\n")
    print("It's a tie!")
    
def show_some(player,dealer):
    print("\n")
    print("Player's Hand:")  
    for card in player.cards:
        print(card)
    
    print("\n")
    print("Dealer's Hand:")
    print("*Hidden Card*")
    print(dealer.cards[1])
    print("\n")
    
def show_all(player,dealer):
    print("\n")
    print("Player's Hand:")    
    for card in player.cards:
        print(card)
    
    print("\n")
    print("Dealer's Hand:")
    for card in dealer.cards:
        print(card)
    
    
while True:
    print("Welcome to my BlackJack game!")
   
    import random

    suits = ('Hearts', 'Diamonds', 'Spades', 'Clubs')
    ranks = ('Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine', 'Ten', 'Jack', 'Queen', 'King', 'Ace')
    values = {'Two':2, 'Three':3, 'Four':4, 'Five':5, 'Six':6, 'Seven':7, 'Eight':8, 'Nine':9, 'Ten':10, 'Jack':10,
                 'Queen':10, 'King':10, 'Ace':11}

    playing = True
    game_deck = Deck()
    game_deck.shuffle()
    
    player = Hand()
    hit(game_deck,player)
    hit(game_deck,player)
    
    dealer = Hand()
    hit(game_deck,dealer)
    hit(game_deck,dealer)

    player_chips = Chips()
    take_bet(player_chips)
    
    show_some(player,dealer)
    
    while playing:  
        
        hit_or_stand(game_deck,player)
        
        if player.value > 21:
            player_busts(player,dealer,player_chips)
            break
        
    if player.value <= 21:
        while dealer.value <= 17:
            hit(game_deck,dealer)
            
        show_all(player,dealer)
    
    
        if dealer.value > 21:
             dealer_busts(player,dealer,player_chips)
                
        elif dealer.value > player.value:
            dealer_wins(player,dealer,player_chips)

        elif dealer.value < player.value:
            player_wins(player,dealer,player_chips)

        else:
            push(player_hand,dealer_hand)   
    
    
    print(f"Your total chips are now: {player_chips.total}")
    
    print("\n")
    choice = input("Would you like to play again? Type Y or N:")
    
    if choice[0].upper() == "Y":
        playing = True
        print("Great! Let's play BlackJack!")
        
    else:
        playing = False
        print("Thanks for Playing!")
        break
    