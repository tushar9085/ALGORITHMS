import math

### Dictionary of Word Counts

def dictionaryCreate(filename):
    doc = open(filename).read()
    words_of_doc = doc.split()
    dictionary = dict()

    for word in words_of_doc:
        dictionary[word] = dictionary.get(word, 0) + 1

    return dictionary

###Sorting Dictionaries

def sortDictionary(dictionary):
    sorted_dictionary = sorted(dictionary.items())
    return sorted_dictionary


### DotProduct

def dotProduct(dic1, dic2):
    total = 0
    match = 0
    for key1, value1 in dic1:
        for key2, value2 in dic2:
            if key1 == key2:
                match += 1
                total += value1 * value2
    print('Matches Found', match)
    return total


### Vector Value

def valueOfDictionary(dictionary):
    sum = 0
    for key, value in dictionary:
        sum += value * value
    return sum


dict_unsorted1 = dictionaryCreate('mbox.txt')
dict2_unsorted2 = dictionaryCreate('doc2.txt')

dict1 = sortDictionary(dict_unsorted1)
dict2 = sortDictionary(dict2_unsorted2)

dot_product = dotProduct(dict1, dict2)
val1 = valueOfDictionary(dict1)
val2 = valueOfDictionary(dict2)
denominator = math.sqrt(val1 * val2)

angle = math.degrees(math.acos(dot_product / denominator))


print('The Distance is %0.6f'%angle, 'in Degree')

