if __name__ == '__main__':
    while True:
        word = input("Enter a word (nothing ends program: ")
        if word == "":
            print("closing program")
            break
        print("word:",word)
        print("lower:", word.lower())
        print("upper:", word.upper())
        print("length of word:", len(word))
        print("-------------------")

