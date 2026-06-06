tablica = [0, 0, 0, 0, 0]


def dodaj(tablice):
    i = 0
    while i < 5:
        tablice[i] = int(input("Podaj liczba: "))
        i = i + 1


def sum(tablice):
    i = 0
    suma = 0
    while i < 5:
        suma = suma + tablice[i]
        i = i + 1
    print(suma)
    return suma  # Dodano zwracanie wartości, by średnia (opcja 6) zadziałała!


def sort(tablice):
    n = len(tablice)
    for i in range(n):
        for j in range(i + 1, n):
            # Uzupełniony warunek i zamiana elementów (sortowanie)
            if tablice[j] < tablice[i]:
                temp = tablice[j]
                tablice[j] = tablice[i]
                tablice[i] = temp


while True:
    print("=====TABLICE====")
    print("1.Uzupełnij tablice")
    print("2.Wypisz tablice")
    print("3.Suma tablica")
    print("4.Najwieksza")
    print("5.Najmniejsza")
    print("6.Srednia")
    print("7.Mediana")

    choice = int(input("Wybierz co chcesz zrobic:"))

    if choice == 1:
        dodaj(tablica)
    if choice == 2:
        print(tablica)
    if choice == 3:
        sum(tablica)
    if choice == 4:
        print(max(tablica))
    if choice == 5:
        print(min(tablica))
    if choice == 6:
        avr = sum(tablica) / len(tablica)
        print(avr)
    if choice == 7:
        sort(tablica)
        # Mediana to środkowy element w 5-elementowej posortowanej tablicji (indeks 2)
        print(tablica[2])

    if choice == 0:
        print("wyłączanie...")
        break