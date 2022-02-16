

# Reads InputFile and prints out a list of each item and quantity sold.
def itemsPurchased():
    with open('InputFile.txt', 'r') as reader:
        groceryList = reader.read().split() # Reads file as a string and splits by whitespace / newline.
        noDupes = set(groceryList) # Creates a Set that removes duplicate items included in the original list

        for item in noDupes:
            print(groceryList.count(item), "\t", item)


# Takes the string of a given item and returns the quantity sold for that given item.
def quantityPurchased(t_input):
    with open('InputFile.txt', 'r') as reader:
        groceryList = reader.read().split()

        i = 0
        for item in groceryList:
            if item.lower() == t_input.lower():
                i+=1

        return i;


# Reads InputFile and writes the each individual item and its amount sold to the file 'frequency.dat'. 'frequency.dat' is created if it does not already exist.
def histogram():
    with open('InputFile.txt', 'r') as reader:
        groceryList = reader.read().split()  # Reads file as a string and splits by whitespace / newline.
        noDupes = set(groceryList)  # Creates a Set that removes duplicate items included in the original list

        with open('frequency.dat', 'w') as writer:
            for item in noDupes:
                writer.write(item)
                writer.write(" ")
                writer.write(str(quantityPurchased(item)))
                writer.write("\n")

    
