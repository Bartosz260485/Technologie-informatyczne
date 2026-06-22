import pygame
import random
import sys

#Dane i funkcje

WARTOSCI_KART = {
    '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, '10': 10,
    'Walet': 10, 'Dama': 10, 'Król': 10, 'As': 11
}

KOLORY = ['Pik', 'Kier', 'Trefl', 'Karo']
FIGURY = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'Walet', 'Dama', 'Król', 'As']

#Tlumaczenie
TLUMACZENIE_KOLOR = {
    'Pik': 'spades',
    'Kier': 'hearts',
    'Trefl': 'clubs',
    'Karo': 'diamonds'
}

TLUMACZENIE_FIGURA = {
    '2': '2', '3': '3', '4': '4', '5': '5', '6': '6', '7': '7', '8': '8', '9': '9', '10': '10',
    'Walet': 'jack',
    'Dama': 'queen',
    'Król': 'king',
    'As': 'ace'
}


def stworz_i_potasuj_talie():
    talia = []
    for kolor in KOLORY:
        for figura in FIGURY:
            karta = f"{figura} {kolor}"
            talia.append(karta)
    random.shuffle(talia)
    return talia


def oblicz_punkty(reka):
    punkty = 0
    liczba_asow = 0
    for karta in reka:
        figura = karta.split()[0]
        punkty += WARTOSCI_KART[figura]
        if figura == 'As':
            liczba_asow += 1

    while punkty > 21 and liczba_asow > 0:
        punkty -= 10
        liczba_asow -= 1
    return punkty


#pygame

pygame.init()
SZEROKOSC = 800
WYSOKOSC = 600
okno = pygame.display.set_mode((SZEROKOSC, WYSOKOSC))
pygame.display.set_caption("Blackjack")

ZIELONY_STOL = (34, 139, 34)
BIALY = (255, 255, 255)
CZARNY = (0, 0, 0)
CZERWONY = (200, 0, 0)

#wczytanie kart
karty = {}
rewers_img = pygame.image.load("PNG-cards-1.3/rewers.png").convert_alpha()
rewers_img = pygame.transform.scale(rewers_img, (100, 140))

for kolor in KOLORY:
    for figura in FIGURY:
        nazwa_karty_w_grze = f"{figura} {kolor}"
        nazwa_pliku = f"{TLUMACZENIE_FIGURA[figura]}_of_{TLUMACZENIE_KOLOR[kolor]}.png"
        sciezka = f"PNG-cards-1.3/{nazwa_pliku}"

        try:
            obraz = pygame.image.load(sciezka).convert_alpha()
            obraz = pygame.transform.scale(obraz, (100, 140))
            karty[nazwa_karty_w_grze] = obraz
        except FileNotFoundError:
            print(f"BŁĄD: Nie znaleziono pliku karty: {sciezka}")

czcionka_duza = pygame.font.SysFont("Arial", 40, bold=True)
czcionka_mala = pygame.font.SysFont("Arial", 20)

zegar = pygame.time.Clock()

talia = []
reka_gracza = []
reka_krupiera = []
tura_gracza = True
koniec_gry = False
komunikat_koncowy = ""


def nowa_gra():
    global talia, reka_gracza, reka_krupiera, tura_gracza, koniec_gry, komunikat_koncowy
    talia = stworz_i_potasuj_talie()
    reka_gracza = [talia.pop(), talia.pop()]
    reka_krupiera = [talia.pop(), talia.pop()]
    tura_gracza = True
    koniec_gry = False
    komunikat_koncowy = ""

    if oblicz_punkty(reka_gracza) == 21:
        komunikat_koncowy = "Blackjack! Wygrywasz!"
        tura_gracza = False
        koniec_gry = True

nowa_gra()


def rysuj_karte(karta_tekst, x, y, ukryta=False):
    if ukryta:
        okno.blit(rewers_img, (x, y))
    else:
        obraz_do_narysowania = karty.get(karta_tekst)

        if obraz_do_narysowania:
            okno.blit(obraz_do_narysowania, (x, y))
        else:
            pygame.draw.rect(okno, CZERWONY, (x, y, 100, 140))


#Gra

dziala = True
while dziala:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            dziala = False

        if event.type == pygame.KEYDOWN:
            if tura_gracza and not koniec_gry:
                if event.key == pygame.K_t:
                    reka_gracza.append(talia.pop())
                    if oblicz_punkty(reka_gracza) > 21:
                        komunikat_koncowy = "Przekroczyłeś 21! Przegrywasz."
                        tura_gracza = False
                        koniec_gry = True

                elif event.key == pygame.K_n:
                    tura_gracza = False

            elif koniec_gry:
                if event.key == pygame.K_SPACE:
                    nowa_gra()

#runda krupiera
    if not tura_gracza and not koniec_gry:
        while oblicz_punkty(reka_krupiera) < 17:
            reka_krupiera.append(talia.pop())

        punkty_gracza = oblicz_punkty(reka_gracza)
        punkty_krupiera = oblicz_punkty(reka_krupiera)

        if punkty_krupiera > 21:
            komunikat_koncowy = "Krupier przekroczył 21! Wygrywasz!"
        elif punkty_gracza > punkty_krupiera:
            komunikat_koncowy = "Masz więcej punktów! Wygrywasz!"
        elif punkty_krupiera > punkty_gracza:
            komunikat_koncowy = "Krupier ma więcej punktów. Przegrywasz."
        else:
            komunikat_koncowy = "Remis!"

        koniec_gry = True

    okno.fill(ZIELONY_STOL)
    napis_krupier = czcionka_mala.render(
        f"Karty Krupiera (Punkty: {'?' if tura_gracza else oblicz_punkty(reka_krupiera)}):", True, BIALY)
    okno.blit(napis_krupier, (50, 50))

    for i, karta in enumerate(reka_krupiera):
        czy_ukryta = (i == 1 and tura_gracza)
        rysuj_karte(karta, 50 + i * 120, 90, czy_ukryta)

    napis_gracz = czcionka_mala.render(f"Twoje karty (Punkty: {oblicz_punkty(reka_gracza)}):", True, BIALY)
    okno.blit(napis_gracz, (50, 300))

    for i, karta in enumerate(reka_gracza):
        rysuj_karte(karta, 50 + i * 120, 340)
    if tura_gracza:
        instrukcja = czcionka_duza.render("Wciśnij 'T' (Dobierz) lub 'N' (Zatrzymaj)", True, BIALY)
        okno.blit(instrukcja, (50, 520))
    elif koniec_gry:
        pygame.draw.rect(okno, CZERWONY, (0, 250, SZEROKOSC, 100))
        wynik = czcionka_duza.render(komunikat_koncowy, True, BIALY)
        okno.blit(wynik, (50, 275))

        reset_info = czcionka_mala.render("Wciśnij SPACJĘ aby zagrać ponownie", True, BIALY)
        okno.blit(reset_info, (50, 520))

    pygame.display.flip()
    zegar.tick(60)

pygame.quit()
sys.exit()